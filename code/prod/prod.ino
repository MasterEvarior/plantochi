#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include "Adafruit_SHT31.h"

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

/*
  Variables to adjust
*/

#define SHT_ADDR 0x44
#define LS_PIN 5
#define MOISTURE_PIN A5
#define LDR_PIN A4

#define M_THRESHOLD_LOW 400
#define M_THRESHOLD_HIGH 600
#define T_THRESHOLD_LOW 15
#define T_THRESHOLD_HIGH 30
#define L_THRESHOLD_LOW 200
#define L_THRESHOLD_HIGH 600


/*
  Keep this as is
*/

enum Sensor {
  LIGHT,
  SOIL_MOISTURE,
  AIR_TEMPERATURE,
  AIR_MOISTURE
};

enum class Eyes {
  NORMAL,
  SQUINT,
  BIG
};

enum class Mouth {
  HAPPY,
  SAD,
  OPEN
};

enum class Symbol {
  NONE,
  HEAT,
  COLD,
};

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);
Adafruit_SHT31 sht31 = Adafruit_SHT31();
unsigned long toneStartTime = 0;
bool isBeeping = false;
int messageState = 0;

void setup(void) {
  Serial.begin(115200);

  sht31.begin(SHT_ADDR);
  u8g2.begin();

  displayClear();
  displayText("Initializing...");
  displayShow();
  delay(1000);
}

void loop(void) {
  int badStates = 0;
  bool isThirsty = 0;

  Symbol symbol = Symbol::NONE;
  Eyes eyes = Eyes::NORMAL;
  Mouth mouth = Mouth::HAPPY;

  float light = readSensor(LIGHT);
  if(light > L_THRESHOLD_HIGH){
    eyes = Eyes::SQUINT;
    badStates++;
  } else if (light < L_THRESHOLD_LOW){
    eyes = Eyes::BIG;
    badStates++;
  } else {
    eyes = Eyes::NORMAL;
  }

  float airTemp = readSensor(AIR_TEMPERATURE);
  if(airTemp > T_THRESHOLD_HIGH){
    badStates++;
    symbol = Symbol::HEAT;
  } else if (airTemp < T_THRESHOLD_LOW){
    badStates++;
    symbol = Symbol::COLD;
  } else {
    symbol = Symbol::NONE;
  }

  // The value of the moisture sensor decreases
  // as the moisture increases
  float soilMoisture = readSensor(SOIL_MOISTURE);
  if(soilMoisture > M_THRESHOLD_HIGH){
    badStates++;
    isThirsty = 1;
    mouth = Mouth::OPEN;
  } else if (soilMoisture < M_THRESHOLD_LOW){
    badStates++;
    mouth = Mouth::SAD;
  } else {
    mouth = Mouth::HAPPY;
  }

  displayClear();
  displaySmiley(symbol, eyes, mouth);
  String text = getText(badStates);
  displayText(text.c_str());
  displayShow();

  if((isThirsty || badStates > 1) && !isBeeping){
    startBeep();
  } else {
    stopBeep();
  }

  updateBeep();

  // Cooldown
  delay(1500);
}

String getText(int amount){
  if(amount == 0){
    return "";
  }

  if(messageState == 0){
    messageState = 1;
    return "Bad plant parent!";
  } else if(messageState == 1 && amount != 1){
    messageState = 0;
    String suffix = " things are wrong!";
    return amount + suffix;
  } else if(messageState == 1 && amount == 1){
    messageState = 0;
    String suffix = " thing is wrong!";
    return amount + suffix;
  } 

  return "";
}

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

#define M_THRESHOLD_LOW 0
#define M_THRESHOLD_HIGH 0
#define T_THRESHOLD_LOW 0
#define T_THRESHOLD_HIGH 0
#define L_THRESHOLD_LOW 0
#define L_THRESHOLD_HIGH 0

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

/*
  Keep this as is
*/
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);
Adafruit_SHT31 sht31 = Adafruit_SHT31();
unsigned long toneStartTime = 0;
bool isBeeping = false;

void setup(void) {
  Serial.begin(115200);

  sht31.begin(SHT_ADDR);
  u8g2.begin();

  displayClear();
  displayText("Initializing...");
  displayShow();
  delay(1000);

  displayClear();
  displayText("All ready to go!");
  displayShow();
  delay(1000);
  
  displayClear();
}

void loop(void) {
  displayClear();
  displaySmiley(Symbol::HEAT, Eyes::NORMAL, Mouth::HAPPY);
  displayShow();

   /*
  int moisture = readSensor(SOIL_MOISTURE);
  int light = readSensor(LIGHT);
  float t = readSensor(AIR_TEMPERATURE);
  float h = readSensor(AIR_MOISTURE);
  */
}

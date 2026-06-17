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

#define LS_PIN 5
#define MOISTURE_PIN A5
#define LDR_PIN A4


U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);
Adafruit_SHT31 sht31 = Adafruit_SHT31();



void setup(void) {
  Serial.begin(115200);

  sht31.begin(0x44);
  u8g2.begin();
}

void loop(void) {
  
  u8g2.clearBuffer();					// clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr);	// choose a suitable font
  u8g2.drawStr(0,10,"Hello World!");	// write something to the internal memory
  u8g2.sendBuffer();					// transfer internal memory to the display
  delay(1000);  

  int sensorValue = analogRead(MOISTURE_PIN);
  Serial.print("Moist: ");
  Serial.println(sensorValue);
  delay(1000);        // delay in between reads for stability

  int light = analogRead(LDR_PIN);
  Serial.print("LDR: ");
  Serial.println(light);
  delay(1000);


  float t = sht31.readTemperature();
  float h = sht31.readHumidity();

  if (! isnan(t)) {  // check if 'is not a number'
    Serial.print("Temp *C = "); Serial.print(t); Serial.print("\t\t");
  } else { 
    Serial.println(t);
    Serial.println("Failed to read temperature");
  }
  
  if (! isnan(h)) {  // check if 'is not a number'
    Serial.print("Hum. % = "); Serial.println(h);
  } else { 
    Serial.println(h);
    Serial.println("Failed to read humidity");
  }

  delay(1000);

  drawSmiley();

  delay(1000);

  tone(LS_PIN, 1000);
  delay(1000);
  noTone(LS_PIN);
}

void drawSmiley() {
  u8g2.clearBuffer();
  
  // 1. Draw the face outline (x, y, radius)
  u8g2.drawCircle(64, 32, 25);
  
  // 2. Draw the eyes (x, y, radius)
  u8g2.drawDisc(54, 25, 3); // Left eye
  u8g2.drawDisc(74, 25, 3); // Right eye
  
  // 3. Draw the mouth (x, y, radius, start_angle, end_angle)
  // This draws an arc for a smile
  u8g2.drawArc(64, 32, 15, 0, 180, 360); 
  
  u8g2.sendBuffer();
}
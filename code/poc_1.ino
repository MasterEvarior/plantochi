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

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);    //Low spped I2C
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

  int sensorValue = analogRead(A5);
  Serial.print("Moist: ");
  Serial.println(sensorValue);
  delay(1000);        // delay in between reads for stability

  int light = analogRead(A4);
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

  u8g2.clearBuffer();
  u8g2.drawStr(0,10,"Coool World!");	// write something to the internal memory
  u8g2.sendBuffer();					// transfer internal memory to the display

  delay(1000);

  tone(5, 1000);
  delay(1000);
  noTone(5);
}
float readSensor(Sensor type) {
    float value = 0;

    switch(type) {
        case LIGHT:
            value = (float) analogRead(LDR_PIN);
            logSensor("Light", value);
            break;
        case SOIL_MOISTURE:
            value = (float) analogRead(MOISTURE_PIN);
            logSensor("Soil Moisture", value);
            break;
        case AIR_TEMPERATURE:
            value = sht31.readTemperature();
            logSensor("Air Temperature", value);
            break;
        case AIR_MOISTURE:
            value = sht31.readHumidity();
            logSensor("Air Humidity", value);
            break;
    }
    
    return value;
}

void logSensor(String label, float value) {
  Serial.print(label);
  Serial.print(": ");
  Serial.println(value);
}
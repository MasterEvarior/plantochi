/**
  Place this in an if somehwere
*/
void startBeep() {
  int freq = random(300, 9000);

  tone(LS_PIN, freq);
  toneStartTime = millis();
  isBeeping = true;
}
void stopBeep() {
  noTone(LS_PIN);
  isBeeping = false;
}

/**
  Call this at the end of the main loop somehwere
*/
void updateBeep() {
  if (isBeeping && (millis() - toneStartTime >= 1000)) {
    noTone(LS_PIN);
    isBeeping = false;
    toneStartTime = 0;
  }
}
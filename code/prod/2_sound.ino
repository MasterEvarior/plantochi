/**
  Place this in an if somehwere
*/
void startBeep() {
  tone(LS_PIN, 1000);
  toneStartTime = millis();
  isBeeping = true;
}

/**
  Call this at the end of the main loop somehwere
*/
void updateBeep() {
  if (isBeeping && (millis() - toneStartTime >= 1000)) {
    noTone(LS_PIN);
    isBeeping = false;
  }
}

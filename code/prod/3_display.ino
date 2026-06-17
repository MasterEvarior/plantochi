void displayText(const char *s) {
    u8g2.clearBuffer();
    u8g2.drawStr(0,15, s);
    u8g2.sendBuffer();
}

void displaySmiley(Forehead forehead, Eyes eyes, Mouth mouth){

  
}
void displayClear() {
    u8g2.clearBuffer();
}

void displayShow() {
    u8g2.sendBuffer();
}

void displayText(const char *s) {
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.drawStr(0, 10, s);
}

void displaySmiley(Symbol right, Eyes eyes, Mouth mouth) {
    const int CX = 64;
    const int CY = 40;

    u8g2.drawCircle(CX, CY, 22);

    switch (right) {
        case Symbol::HEAT:
            u8g2.setFont(u8g2_font_unifont_t_symbols);
            u8g2.drawGlyph(CX + 35, CY, 0x2615);
            break;
        case Symbol::COLD:
            u8g2.setFont(u8g2_font_unifont_t_symbols);
            u8g2.drawGlyph(CX + 35, CY, 0x2603);
            break;
        case Symbol::NONE:
            break;
        default:
            break;
    }

    switch (eyes) {
        case Eyes::SQUINT:
            u8g2.drawLine(CX - 14, CY - 8, CX - 8, CY - 8);
            u8g2.drawLine(CX + 8, CY - 8, CX + 14, CY - 8);
            break;
        case Eyes::BIG:
            u8g2.drawCircle(CX - 11, CY - 8, 5);
            u8g2.drawCircle(CX + 11, CY - 8, 5);
            u8g2.drawDisc(CX - 11, CY - 8, 2);
            u8g2.drawDisc(CX + 11, CY - 8, 2);
            break;
        default:
            u8g2.drawDisc(CX - 11, CY - 8, 3);
            u8g2.drawDisc(CX + 11, CY - 8, 3);
            break;
    }

    switch (mouth) {
        case Mouth::HAPPY:
            u8g2.drawCircle(CX, CY, 10, U8G2_DRAW_LOWER_LEFT | U8G2_DRAW_LOWER_RIGHT);
            break;
        case Mouth::SAD:
            u8g2.drawCircle(CX, CY + 10, 10, U8G2_DRAW_UPPER_LEFT | U8G2_DRAW_UPPER_RIGHT);
            break;
        case Mouth::OPEN:
            u8g2.drawDisc(CX, CY + 8, 7);
            break;
    }
}
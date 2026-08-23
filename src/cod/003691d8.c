/* cygnus-2.96 matched TU. */

/* compiler: cygnus-2.96 ; extra keys: none */
__attribute__((section(".text.MPV_CheckDelim")))
int MPV_CheckDelim(unsigned char *b) {
    int c;
    int r;

    c = b[0];
    c <<= 8;
    c |= b[1];
    c <<= 8;
    c |= b[2];
    c <<= 8;
    c |= b[3];
    if (c == 0x100) {
        r = 4;
    } else if (c == 0x101) {
        r = 3;
    } else if ((unsigned int)(c - 0x102) < 0xAE) {
        r = 1;
    } else if (c == 0x1B2) {
        r = 0x20;
    } else if (c == 0x1B3) {
        r = 0x40;
    } else if (c == 0x1B5) {
        r = 0x10;
    } else if (c == 0x1B7) {
        r = 0x80;
    } else if ((c ^ 0x1B8) == 0) {
        r = 8;
    } else {
        r = 0;
    }
    return r;
}

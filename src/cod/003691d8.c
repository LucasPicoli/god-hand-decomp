/* cygnus-2.96 matched TU. */
#include "godhand/MpvHandle.h"

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
        r = MPV_DLM_PSC;
    } else if (c == 0x101) {
        r = MPV_DLM_SLICE;
    } else if ((unsigned int)(c - 0x102) < 0xAE) {
        r = MPV_DLM_SLICE_NEXT;
    } else if (c == 0x1B2) {
        r = MPV_DLM_UDSC;
    } else if (c == 0x1B3) {
        r = MPV_DLM_SHC;
    } else if (c == 0x1B5) {
        r = MPV_DLM_ESC;
    } else if (c == 0x1B7) {
        r = MPV_DLM_SEC;
    } else if ((c ^ 0x1B8) == 0) {
        r = MPV_DLM_GSC;
    } else {
        r = 0;
    }
    return r;
}

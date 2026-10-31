#include "godhand/ehFrameObj.h"

/* Byte-identical to RE4 PS2 (SLUS-21134) 0x00178590 — LEB128 varint decode.
 * Compiled with the SN toolchain (sn-2.95.3-136). Reads a base-128 varint from
 * p into *val and returns the pointer past the last byte consumed. */

__attribute__((section(".text.func_00321938")))
unsigned char *func_00321938(unsigned char *p, int *val) {
    int sh = 0, r;
    unsigned char b;
    b = *p;
    p++;
    r = b & 0x7F;
    while (b & 0x80) {
        b = *p;
        p++;
        sh += 7;
        r = r | ((b & 0x7F) << sh);
    }
    *val = r;
    return p;
}

/* ee-2.9-991111 matched TU. */

#include "godhand/vu0.h"

__attribute__((section(".text.func_003950F8")))
int func_003950F8(void) {
    unsigned int flags;
    unsigned int vi29;

    do {
        unsigned int t;
        t = *(volatile unsigned int *)0x10009000;
        flags = 0;
        if (t & 0x100) {
            flags = 1;
        }
        if (*(volatile unsigned int *)0x1000A000 & 0x100) {
            flags |= 2;
        }
        if (*(volatile unsigned int *)0x10003C00 & 3) {
            flags |= 4;
        }
        VU0_CFC2_NI(vi29, 29);
        if (vi29 & 0x100) {
            flags |= 8;
        }
        if (*(volatile unsigned int *)0x10003020 & 0xC00) {
            flags |= 0x10;
        }
    } while (flags != 0);

    return 0;
}

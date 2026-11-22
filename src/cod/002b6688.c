#include "godhand/globals.h"
__attribute__((section(".text.func_002B6688")))
int func_002B6688(int id)
{
    unsigned int i;

    if (id == 0x264) {
        return 4;
    }
    if ((unsigned int)(id - 0x300) < 0x200) {
        return 0;
    }
    for (i = 0; D_0044B360[i] != 0xFFFF; i++) {
        if (id == D_0044B360[i]) {
            return 0;
        }
    }
    for (i = 0; D_0044B378[i] != 0xFFFF; i++) {
        if (id == D_0044B378[i]) {
            return 3;
        }
    }
    for (i = 0; D_0044B410[i] != 0xFFFF; i++) {
        if (id == D_0044B410[i]) {
            return 2;
        }
    }
    if ((unsigned int)(id - 0x200) < 0x100) {
        return 3;
    }
    return 0;
}

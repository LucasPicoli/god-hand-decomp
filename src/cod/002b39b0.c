/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"

__attribute__((section(".text.func_002B39B0")))
int func_002B39B0(unsigned char *obj)
{
    int mode;

    switch (*(unsigned short *)(*(unsigned char **)(obj + 0x8C) + 2)) {
    case 0:
    default:
        mode = 0;
        break;
    case 1:
        mode = 1;
        break;
    case 2:
        mode = 6;
        break;
    case 3:
        mode = 2;
        break;
    case 4:
        mode = 3;
        break;
    case 6:
        mode = *(int *)(obj + 0x20);
        break;
    }
    cSnd_SeCallGlobal(obj, mode, *(short *)(*(unsigned char **)(obj + 0x8C) + 4), *(void **)(obj + 0x18));
    return 0;
}

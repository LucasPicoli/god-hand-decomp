/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"

extern int GetSeqSEBase(void *a0);
extern int irand(void);

/* sn-2.95.3-136 matched TU. */






#define SE(obj, k) cSnd_SeCall_2CBA48(&D_005FEE00, 1, \
                                      (short)(GetSeqSEBase(obj) + (k)), \
                                      (obj), 0, 0, 0, 0)

__attribute__((section(".text.func_002744E0")))
void func_002744E0(void *a0)
{
    char *p = (char *)a0;

    switch (*(int *)(p + 0x564)) {
    default:
    case 0x202:
        if ((irand() & 1) != 0) {
            SE(a0, 0xA);
        } else {
            SE(a0, 0xB);
        }
        break;
    case 0x20b:
        switch ((unsigned int)irand() & 3) {
        default:
        case 0:
            SE(a0, 0xA);
            break;
        case 1:
            SE(a0, 0xB);
            break;
        case 2:
            SE(a0, 0xE);
            break;
        case 3:
            SE(a0, 0xF);
            break;
        }
        break;
    case 0x209:
        if ((*(unsigned short *)(p + 0x3AC) & 2) != 0) {
            switch (irand() & 1) {
            default:
            case 0:
                SE(a0, 0xA);
                break;
            case 1:
                SE(a0, 0xF);
                break;
            }
        } else if ((irand() & 1) != 0) {
            SE(a0, 0xF);
        } else {
            switch (irand() & 1) {
            default:
            case 0:
                SE(a0, 0xB);
                break;
            case 1:
                SE(a0, 0xE);
                break;
            }
        }
        break;
    case 0x21f:
        switch ((unsigned int)irand() % 6) {
        default:
        case 0:
            SE(a0, 0xA);
            break;
        case 1:
            SE(a0, 0xB);
            break;
        case 2:
            SE(a0, 0xE);
            break;
        case 3:
            SE(a0, 0xF);
            break;
        case 4:
            SE(a0, 0x10);
            break;
        case 5:
            SE(a0, 0x11);
            break;
        }
        break;
    case 0x213:
    case 0x217:
    case 0x250:
    case 0x251:
    case 0x252:
    case 0x260:
        switch ((unsigned int)irand() % 5) {
        default:
        case 0:
            SE(a0, 0xA);
            break;
        case 1:
            SE(a0, 0xB);
            break;
        case 2:
            SE(a0, 0xE);
            break;
        case 3:
            SE(a0, 0xF);
            break;
        case 4:
            SE(a0, 0x10);
            break;
        }
        break;
    case 0x214:
    case 0x215:
        switch ((unsigned int)irand() % 5) {
        default:
        case 0:
            SE(a0, 0xA);
            break;
        case 1:
            SE(a0, 0xB);
            break;
        case 2:
            SE(a0, 0xE);
            break;
        case 3:
            SE(a0, 0xF);
            break;
        case 4:
            SE(a0, 0x10);
            break;
        case 5:
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)0x1A, a0, 0, 0, 0, 0);
            break;
        }
        break;
    case 0x264:
        if ((irand() & 1) != 0) {
            SE(a0, 0xA);
        } else {
            SE(a0, 0xB);
        }
        break;
    case 0x265:
        switch ((unsigned int)irand() & 3) {
        default:
        case 0:
            SE(a0, 0xA);
            break;
        case 1:
            SE(a0, 0xB);
            break;
        case 2:
            SE(a0, 0xE);
            break;
        case 3:
            SE(a0, 0xF);
            break;
        }
        break;
    case 0x26a:
        switch ((unsigned int)irand() % 3) {
        default:
        case 0:
            SE(a0, 0xA);
            break;
        case 1:
            SE(a0, 0xB);
            break;
        case 2:
            SE(a0, 0xE);
            break;
        }
        break;
    case 0x270:
        switch ((unsigned int)irand() % 3) {
        default:
        case 0:
            SE(a0, 0xA);
            break;
        case 1:
            SE(a0, 0xB);
            break;
        case 2:
            SE(a0, 0xE);
            break;
        }
        break;
    case 0x271:
        switch ((unsigned int)irand() % 3) {
        default:
        case 0:
            SE(a0, 0xA);
            break;
        case 1:
            SE(a0, 0xB);
            break;
        case 2:
            SE(a0, 0xE);
            break;
        }
        break;
    case 0x272:
        switch ((unsigned int)irand() % 3) {
        default:
        case 0:
            SE(a0, 0xA);
            break;
        case 1:
            SE(a0, 0xB);
            break;
        case 2:
            SE(a0, 0xE);
            break;
        }
        break;
    case 0x273:
        switch ((unsigned int)irand() % 3) {
        default:
        case 0:
            SE(a0, 0xA);
            break;
        case 1:
            SE(a0, 0xB);
            break;
        case 2:
            SE(a0, 0xE);
            break;
        }
        break;
    case 0x274:
        switch (irand() & 1) {
        default:
        case 0:
            SE(a0, 0xA);
            break;
        case 1:
            SE(a0, 0xB);
            break;
        }
        break;
    case 0x256:
    case 0x27e:
        if ((*(unsigned short *)(p + 0x3AC) & 2) != 0) {
            SE(a0, 0xB);
        } else {
            switch ((unsigned int)irand() % 5) {
            default:
            case 0:
                SE(a0, 0xB);
                break;
            case 1:
                SE(a0, 0xE);
                break;
            case 2:
                SE(a0, 0xF);
                break;
            case 3:
                SE(a0, 0x10);
                break;
            case 4:
                SE(a0, 0x11);
                break;
            }
        }
        break;
    }
}

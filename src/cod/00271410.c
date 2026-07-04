/* sn-2.95.3-136 matched TU. */

extern void EmClothInit(int, char *, char *, char *);

#include "godhand/vu0.h"




__attribute__((section(".text.func_00271410")))
void func_00271410(char *obj)
{
    char *buf;
    char *p;
    int i;

    switch (*(int *)(obj + 0x564)) {
    case 0x214:
    case 0x215:
    case 0x21C:
    case 0x223:
    case 0x243:
    case 0x244:
    case 0x250:
    case 0x251:
    case 0x252:
    case 0x256:
    case 0x270:
    case 0x271:
    case 0x272:
    case 0x273:
    case 0x274:
        buf = func_0030F578(0x1B80);
        p = buf;
        i = 0x2B;
        do {
            VU0_SQC2_VF0(p, 0x0);
            VU0_SQC2_VF0(p, 0x10);
            VU0_SQC2_VF0(p, 0x30);
            VU0_SQC2_VF0(p, 0x40);
            VU0_SQC2_VF0(p, 0x50);
            VU0_SQC2_VF0(p, 0x80);
            p += 0xA0;
        } while (--i != -1);
        *(char **)(obj + 0x1860) = buf;
        if (buf != 0) {
            EmClothInit(*(int *)(obj + 0x564), obj, buf, obj + 0x17E0);
        }
        break;
    }
}

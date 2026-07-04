/* sn-2.95.3-136 matched TU. */

extern void EmClothInit(int, char *, char *, char *);

#include "godhand/vu0.h"




__attribute__((section(".text.func_0028CDD0")))
void func_0028CDD0(char *arg)
{
    switch (*(int *)(arg + 0x564)) {
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
    {
        char *p;
        char *q;
        int i;

        p = func_0030F578(0x1B80);
        q = p;
        for (i = 0x2B; i != -1; i--) {
            VU0_SQC2_VF0(q, 0x0);
            VU0_SQC2_VF0(q, 0x10);
            VU0_SQC2_VF0(q, 0x30);
            VU0_SQC2_VF0(q, 0x40);
            VU0_SQC2_VF0(q, 0x50);
            VU0_SQC2_VF0(q, 0x80);
            q += 0xA0;
        }
        *(char **)(arg + 0x1630) = p;
        if (p != 0) {
            EmClothInit(*(int *)(arg + 0x564), arg, p, arg + 0x15B0);
        }
        break;
    }
    }
}

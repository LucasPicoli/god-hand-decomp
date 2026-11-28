/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/cOmBase.h"

extern int irand(void);
extern void cDamageUnit_SetDamageCollFlashActive(void *a0, int a1, short a2);

/* sn-2.95.3-136 matched TU. */






#define PART(K, IDX)                                        \
    b = s0->partNum;                                        \
    spill[0] = b;                                           \
    lim = (K);                                              \
    if (lim < b)                                            \
        obj = (int)s0->children[IDX];                       \
    else                                                    \
        obj = 0;

__attribute__((section(".text.func_001ACB78")))
void func_001ACB78(void *a0)
{
    cOmBase *s0 = a0;
    int obj;
    int b, lim;
    int spill[2];
    int r;
    int n;
    int p;

    switch (s0->step) {
    case 0:
        *(float *)((char *)s0 + 0x794) = 0.0f;
        r = irand();
        s0->step = 1;
        *(short *)((char *)s0 + 0x61E) = (r & 0xF) + 0xF;
        *(char *)((char *)s0 + 0x620) = 0;
        s0->stepArg = 0;
        /* fall through */
    case 1:
        n = *(unsigned short *)((char *)s0 + 0x61E) - 1;
        *(short *)((char *)s0 + 0x61E) = n;
        if ((short)n > 0)
            break;
        *(short *)((char *)s0 + 0x61E) = 8;
        s0->step = 2;
        *(char *)((char *)s0 + 0x620) = *(unsigned char *)((char *)s0 + 0x620) + 1;
        s0->stepArg = 0;
        break;
    case 2:
        *(float *)((char *)s0 + 0x794) = *(float *)((char *)s0 + 0x794) + 0.0872664601f;
        PART(1, 1)
        if (obj != 0) {
            PART(1, 1)
            *(float *)(obj + 0x104) = -*(float *)((char *)s0 + 0x794);
        }
        PART(2, 2)
        if (obj != 0) {
            PART(2, 2)
            *(float *)(obj + 0x104) = *(float *)((char *)s0 + 0x794);
        }
        s0->stepArg = 0;
        s0->step = 3;
        break;
    case 3:
        *(float *)((char *)s0 + 0x794) = *(float *)((char *)s0 + 0x794) - 0.0872664601f;
        PART(1, 1)
        if (obj != 0) {
            PART(1, 1)
            *(float *)(obj + 0x104) = -*(float *)((char *)s0 + 0x794);
        }
        PART(2, 2)
        if (obj != 0) {
            PART(2, 2)
            *(float *)(obj + 0x104) = *(float *)((char *)s0 + 0x794);
        }
        n = *(unsigned short *)((char *)s0 + 0x61E) - 1;
        *(short *)((char *)s0 + 0x61E) = n;
        if ((short)n > 0) {
            s0->stepArg = 0;
            s0->step = 2;
            break;
        }
        s0->stepArg = 0;
        s0->step = 4;
        break;
    case 4:
        *(float *)((char *)s0 + 0x794) = *(float *)((char *)s0 + 0x794) + 0.34906584f;
        PART(1, 1)
        if (obj != 0) {
            PART(1, 1)
            *(float *)(obj + 0x104) = -*(float *)((char *)s0 + 0x794);
        }
        PART(2, 2)
        if (obj != 0) {
            PART(2, 2)
            *(float *)(obj + 0x104) = *(float *)((char *)s0 + 0x794);
        }
        if (1.57079637f <= *(float *)((char *)s0 + 0x794)) {
            p = *(int *)((char *)s0 + 0x628);
            if (p != 0) {
                cDamageUnit_SetDamageCollFlashActive((void *)p, 1, 2);
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x111, a0, 0, 0, 0, 0);
            }
            s0->stepArg = 0;
            s0->step = 5;
            break;
        }
        break;
    case 5:
        *(float *)((char *)s0 + 0x794) = *(float *)((char *)s0 + 0x794) - 0.0872664601f;
        PART(1, 1)
        if (obj != 0) {
            PART(1, 1)
            *(float *)(obj + 0x104) = -*(float *)((char *)s0 + 0x794);
        }
        PART(2, 2)
        if (obj != 0) {
            PART(2, 2)
            *(float *)(obj + 0x104) = *(float *)((char *)s0 + 0x794);
        }
        if (*(float *)((char *)s0 + 0x794) <= 0.0f) {
            PART(1, 1)
            if (obj != 0) {
                PART(1, 1)
                *(int *)(obj + 0x104) = 0;
            }
            PART(2, 2)
            if (obj != 0) {
                PART(2, 2)
                *(int *)(obj + 0x104) = 0;
            }
            if ((irand() & 1) != 0) {
                s0->stepArg = 0;
                s0->step = 6;
                break;
            }
            if (*(char *)((char *)s0 + 0x620) >= 2) {
                s0->stepArg = 0;
                s0->step = 6;
                break;
            }
            *(short *)((char *)s0 + 0x61E) = 4;
            s0->step = 1;
            *(float *)((char *)s0 + 0x794) = 0.0f;
            s0->stepArg = 0;
            break;
        }
        break;
    case 6:
        s0->phase = 0;
        s0->step = 0;
        s0->stepArg = 0;
        *(int *)((char *)s0 + 0x618) = 0;
        break;
    }
}

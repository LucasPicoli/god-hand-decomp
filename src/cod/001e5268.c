/* sn-2.95.3-136 matched TU. */

extern void func_001E8E48(void *a, void *b);
extern int cSnd_SeCall(void *a0, int a1, short a2, int a3, int a4, int a5);
extern unsigned char D_005FEE00[];

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"





static inline unsigned char tick(int *p)
{
    if (*p != 0) {
        *p = *p - 1;
        return 0;
    }
    return 1;
}

__attribute__((section(".text.func_001E5268")))
void func_001E5268(char *a0)
{
    unsigned char buf[16] __attribute__((aligned(16)));
    char *s0 = a0;
    char *s1;

    switch (*(int *)(s0 + 8)) {
    case 0:
        {
            char *p = s0 + 0x310;
            *(int *)(p + 0xC) = 0;
            *(int *)(p + 8) = 0;
            *(int *)(p + 4) = 2;
        }
        *(int *)(s0 + 8) = *(int *)(s0 + 8) + 1;
        /* fall through */
    case 1:
        {
            long b364 = *(unsigned int *)(s0 + 0x364);
            if ((b364 & 1) == 0) return;
        }
        VU0_SQC2_VF0(buf, 0);
        s1 = s0 + 0x58;
        func_001E8E48(s1, buf);
        *(int *)(s0 + 0x3EC) = cSnd_SeCall(&D_005FEE00, 2, 1, (int)buf, 0, 0);
        {
            long b118 = *(unsigned int *)(s0 + 0x118);
            if ((b118 & 1) == 0) goto skip118;
        }
        *(int *)(s1 + 8) = 0;
        *(int *)(s1 + 4) = 2;
        *(int *)(s1 + 0xC) = 0;
    skip118:
        *(int *)(s0 + 0x10) = 5;
        *(int *)(s0 + 8) = *(int *)(s0 + 8) + 1;
        return;
    case 2:
        if (tick((int *)(s0 + 0x10)) == 0) return;
        {
            char *p = s0 + 0x140;
            long b200 = *(unsigned int *)(s0 + 0x200);
            if ((b200 & 1) == 0) goto skip200;
            *(int *)(p + 8) = 0;
            *(int *)(p + 4) = 2;
            *(int *)(p + 0xC) = 0;
        }
    skip200:
        *(int *)(s0 + 0x10) = 5;
        *(int *)(s0 + 8) = *(int *)(s0 + 8) + 1;
        return;
    case 3:
        if (tick((int *)(s0 + 0x10)) == 0) return;
        {
            char *p = s0 + 0x228;
            long b2E8 = *(unsigned int *)(s0 + 0x2E8);
            if ((b2E8 & 1) == 0) goto skip2E8;
            *(int *)(p + 8) = 0;
            *(int *)(p + 4) = 2;
            *(int *)(p + 0xC) = 0;
        }
    skip2E8:
        *(int *)(s0 + 8) = *(int *)(s0 + 8) + 1;
        return;
    case 4:
        {
            long c118 = *(unsigned int *)(s0 + 0x118);
            if (((c118 >> 1) & 1) == 0) return;
        }
        {
            long c200 = *(unsigned int *)(s0 + 0x200);
            if (((c200 >> 1) & 1) == 0) return;
        }
        {
            long c2E8 = *(unsigned int *)(s0 + 0x2E8);
            if (((c2E8 >> 1) & 1) == 0) return;
        }
        *(int *)(s0 + 8) = 0;
        *(int *)(s0 + 4) = 2;
        *(int *)(s0 + 0xC) = 0;
        return;
    }
}

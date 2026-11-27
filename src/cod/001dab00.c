/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"

extern int Casino_randRange(void *self, int lo, int hi);
extern void func_001DBE18(void *a0, void *a1);
extern void func_001D6EC8(void *a0, int a1);
extern void func_001D6DD0(void *a0, int a1);
extern void SetField_56_1DEBE8(void *a0, int a1);
extern float D_00568160[];
extern float D_005681C0[];

static __inline__ unsigned char TickDown(int *p) {
    if (*p == 0) {
        return 1;
    }
    *p = *p - 1;
    return 0;
}

/* Casino table step machine (state byte at 0x3025): arm a 30-tick wait, then pick a
 * random slot (row 0..3, column from the 0x604 width) or the next one, flash it and
 * play its sound. Each arm does its own x * 13 after its second random call: in the
 * shared block combine fuses the multiply and the add into madd, which retail has not. */
__attribute__((section(".text.Casino_stepSlotPick")))
void Casino_stepSlotPick(char *s0) {
    unsigned char ok;

    switch (*(unsigned char *)(s0 + 0x3025)) {
    case 0:
        *(int *)(s0 + 0x3028) = 30;
        *(unsigned char *)(s0 + 0x3025) = *(unsigned char *)(s0 + 0x3025) + 1;
        break;
    case 1:
        ok = TickDown((int *)(s0 + 0x3028));
        if (ok) {
            char *g1;
            char *ob;
            char *vt;
            void (*fp)();
            long t = *(unsigned int *)(s0 + 0x3020);
            if (((t >> 4) & 1) == 1) {
                int x;
                int y;
                int m;
                char *p;
                unsigned short w = *(unsigned short *)(**(int **)(s0 + 0x3004) + 0x604);
                if (*(unsigned char *)(s0 + 0x3044) != 0) {
                    x = Casino_randRange(s0, 0, 3);
                    y = Casino_randRange(s0, 1, w - 1);
                    x = x & 0xFFFF;
                    m = 0xD;
                    x = x * m;
                } else {
                    x = Casino_randRange(s0, 0, 3);
                    y = Casino_randRange(s0, w + 1, 0xC);
                    x = x & 0xFFFF;
                    m = 0xD;
                    x = x * m;
                }
                do { x = x + y; } while (0);
                p = s0 + (((x & 0xFFFF) << 3) + 0x2E64);
                *(char **)(s0 + 0x3008) = p;
                *(int *)(p + 4) &= ~1;
            } else {
                func_001DBE18(s0, s0 + 0x3008);
            }
            func_001D6EC8(*(char **)(s0 + 0x3008), 0);
            g1 = *(char **)*(char **)(s0 + 0x3008);
            *(int *)(g1 + 0x250) = *(int *)(g1 + 0x250) | 2;
            ob = *(char **)*(char **)(s0 + 0x3008);
            vt = *(char **)(ob + 0x214);
            fp = *(void (**)())(vt + 0x74);
            fp(ob + *(short *)(vt + 0x70), D_00568160);
            *(unsigned char *)(s0 + 0x3025) = *(unsigned char *)(s0 + 0x3025) + 1;
        }
        break;
    case 2:
        {
        char *g2 = *(char **)*(char **)(s0 + 0x3008);
        *(int *)(g2 + 0x250) = *(int *)(g2 + 0x250) & 0xFFFFFFFDU;
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, *(cObj **)*(char **)(s0 + 0x3008), 0, 0, 0, 0);
        *(int *)(s0 + 0x302C) = 10;
        *(unsigned char *)(s0 + 0x3025) = *(unsigned char *)(s0 + 0x3025) + 1;
        }
        break;
    case 3:
        {
        float t = (10.0f - (float)*(int *)(s0 + 0x302C)) / 10.0f;
        float r0;
        float r1;
        char *d1;
        int n;
        r0 = t * (D_005681C0[4] - D_00568160[0]) + D_00568160[0];
        r1 = t * (D_005681C0[5] - D_00568160[1]) + D_00568160[1];
        d1 = *(char **)(*(char **)*(char **)(s0 + 0x3008) + 0xF0);
        *(float *)d1 = r0;
        {
        char *d2 = *(char **)(*(char **)*(char **)(s0 + 0x3008) + 0xF0);
        *(float *)(d2 + 4) = r1;
        }
        n = *(int *)(s0 + 0x302C);
        if (n == 0) {
            *(int *)(s0 + 0x3028) = 30;
            *(unsigned char *)(s0 + 0x3025) = *(unsigned char *)(s0 + 0x3025) + 1;
        } else {
            *(int *)(s0 + 0x302C) = n - 1;
        }
        }
        break;
    case 4:
        ok = TickDown((int *)(s0 + 0x3028));
        if (ok) {
            func_001D6DD0(*(char **)(s0 + 0x3008), 1);
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 1, *(cObj **)*(char **)(s0 + 0x3008), 0, 0, 0, 0);
            *(unsigned char *)(s0 + 0x3025) = *(unsigned char *)(s0 + 0x3025) + 1;
        }
        break;
    case 5:
        {
        long f = *(unsigned int *)(*(char **)(s0 + 0x3008) + 4);
        if (((f >> 3) & 1) == 1) {
            SetField_56_1DEBE8(s0, 6);
            *(unsigned char *)(s0 + 0x3025) = 0;
            *(unsigned char *)(s0 + 0x3024) = 16;
        }
        }
        break;
    }
}

/* sn-2.95.3-136 matched TU. */
#include "godhand/Slot2.h"

/* Slot2 two-step pause screen: wait two updates, then return to the title
 * state. */
__attribute__((section(".text.Slot2_PayoutNone")))
void Slot2_PayoutNone(Slot2 *self) {
    switch (self->phase) {
    case 0:
        self->phase = 1;
        break;
    case 1:
        self->phase = 2;
        break;
    case 2:
        self->state = 0;
        self->step = 0;
        self->phase = 0;
        break;
    }
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_001E8DF0")))
void func_001E8DF0(char *a0, void *src, int *tbl, int n) {
    int *d;
    n &= 0xFFFF;
    if (src == 0) return;
    if (tbl == 0) return;
    if ((unsigned int)n >= 0x16) return;
    *(short *)(a0 + 0xB4) = n;
    *(void **)a0 = src;
    n = 0;
    while (n < *(unsigned short *)(a0 + 0xB4)) {
        *(int *)(a0 + 0x54 + n * 4) = tbl[n];
        n++;
    }
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.cDamageUnit_SetDamageCollActive_1FD610")))
void cDamageUnit_SetDamageCollActive_1FD610(char *a0, int id, int on) {
    char *p;
    char *q;
    p = *(char **)(a0 + 0x3C);
    while (p != 0) {
        if (*(short *)(p + 0x2C) == id) {
            q = *(char **)(p + 0x28);
            if (on == 1) *(unsigned int *)q |= 2;
            else *(unsigned int *)q &= 0xFFFFFFFDU;
            return;
        }
        p = *(char **)(p + 0x24);
    }
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_002A58D8")))
void func_002A58D8(char *a0, unsigned int v) {
    char *p;
    int s;
    if (v == 0xFFFFFFFFU) {
        p = a0 + 0x28000;
        s = *(int *)(p + 0x2060);
        switch (s) {
        default:
            *(int *)(p + 0x2064) = 1;
            break;
        case 4:
        case 6:
            *(int *)(p + 0x2064) = 2;
            break;
        }
    } else {
        *(int *)(a0 + 0x28000 + 0x2064) = v;
    }
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_002A73F0")))
int func_002A73F0(char *a0) {
    int *q;
    q = (int *)(a0 + 0x520);
    *(int *)(a0 + 0x520) = 0;
    q[1] = 0;
    q[2] = 0;
    *(short *)(a0 + 0x570) = -1;
    *(int *)(a0 + 0x574) = 2;
    *(float *)(a0 + 0x5A8) = 1.0f;
    *(float *)(a0 + 0x3A8) = 1.0f;
    *(int *)(a0 + 0x5A0) = 0;
    *(short *)(a0 + 0x548) = 0;
    *(short *)(a0 + 0x54A) = 0;
    *(int *)(a0 + 0x54C) = 0;
    *(int *)(a0 + 0x254) |= 0x8000000;
    return 1;
}

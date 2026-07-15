/* sn-2.95.3-136 matched TU. */

extern void func_001DF858(void *a0);
extern void Obj0000_Init_Fields_00_04_1D6DB0(void *a0);

/* sn-2.95.3-136 matched TU. One call-loop → --call-loop-pad. */




__attribute__((section(".text.Poker__ctor")))
void *Poker__ctor(void *a0) {
    char *this = (char *)a0;
    char *p;
    short *p3;
    int i;
    int j;

    func_001DF858(this);

    p = this + 0x2E64;
    /* `i != -1`: retail closes with `bne $s2,$s3` where $s3 = -1. */
    for (i = 0x33; i != -1; i--) {
        Obj0000_Init_Fields_00_04_1D6DB0(p);
        p += 8;
    }

    Obj0000_Init_Fields_00_04_1D6DB0(this + 0x3018);

    p3 = (short *)(this + 0x3052);

    *(int *)(this + 0x3020) = 0;
    *(int *)(this + 0x3048) = 9;
    *(char *)(this + 0x3024) = 0;
    *(char *)(this + 0x3025) = 0;
    *(int *)(this + 0x304C) = 0;
    *(int *)(this + 0x3034) = 0;
    *(int *)(this + 0x3038) = 0;

    for (j = 4; j >= 0; j--) {
        ((int *)(this + 0x3004))[j] = 0;
    }
    for (j = 4; j >= 0; j--) {
        p3[j] = 0x34;
    }

    *(char *)(this + 0x3050) = 0;
    return this;
}

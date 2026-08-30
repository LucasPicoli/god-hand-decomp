/* sn-2.95.3-136 matched TU. */

extern void Obj0000_Set_Fields_68_6C_From_D_007474A0_1615D0();
extern void cIDManager_setIDData();
extern void cIDBase_initialize();
extern void cIDBase_restartAnim();
extern int cIDBase_setPackedMessData();
extern int cIDBase_getIDWork(void *self, int idx);
extern int IsSet_Field_A4_1FBFD0(void *a0, int a1);
extern void func_00162B18();
extern void func_00162C98();
extern void func_001630E8();
extern void cCockPlBar_initData();
extern int D_0041F430;
extern int *D_003C2384;
extern char D_00569B70[];
extern int D_00747A24;
extern char *D_003BD6E8;

/* sn-2.95.3-136 matched TU. */




















__attribute__((section(".text.func_001627D8")))
void func_001627D8(void *a0) {
    char *s1 = (char *)a0;
    int *p;
    int i;
    unsigned long t;

    Obj0000_Set_Fields_68_6C_From_D_007474A0_1615D0(s1);
    *(short *)(s1 + 0x134) = 0;
    *(short *)(s1 + 0x136) = 0;
    if (func_00161500(s1, &D_0041F430) != 0) {
        cIDManager_setIDData(*D_003C2384, 7, *(int *)(s1 + 0x50));
        cIDBase_initialize(s1, 7, 0);
        cIDBase_restartAnim(s1);
        cIDBase_setPackedMessData(s1, 7, 1);
        *(int *)(s1 + 0x60) = 3;
    }
    p = (int *)(s1 + 0x80);
    for (i = 0; i < 0x1C; i++) {
        p[i] = cIDBase_getIDWork(s1, i);
    }
    for (i = 1; i < 9; i++) {
        int k = i + 8;
        int m = k * 4;
        int *r = (int *)((int)p + m);
        int q = *r;
        *(int *)(q + 0x2C) |= 0x8000000;
        if (IsSet_Field_A4_1FBFD0(D_00569B70, (unsigned short)i) == 0) {
            continue;
        }
        switch (i) {
        case 1:
            *(int *)(*(int *)(s1 + 0x84) + 0x2C) &= 0xF7FFFFFF;
            *(int *)(*(int *)(s1 + 0xA4) + 0x2C) &= 0xF7FFFFFF;
            break;
        case 2:
            *(int *)(*(int *)(s1 + 0x88) + 0x2C) &= 0xF7FFFFFF;
            *(int *)(*(int *)(s1 + 0xA8) + 0x2C) &= 0xF7FFFFFF;
            break;
        case 3:
            *(int *)(*(int *)(s1 + 0x8C) + 0x2C) &= 0xF7FFFFFF;
            *(int *)(*(int *)(s1 + 0xAC) + 0x2C) &= 0xF7FFFFFF;
            break;
        case 4:
            *(int *)(*(int *)(s1 + 0x90) + 0x2C) &= 0xF7FFFFFF;
            *(int *)(*(int *)(s1 + 0xB0) + 0x2C) &= 0xF7FFFFFF;
            break;
        case 5:
            *(int *)(*(int *)(s1 + 0x94) + 0x2C) &= 0xF7FFFFFF;
            *(int *)(*(int *)(s1 + 0xB4) + 0x2C) &= 0xF7FFFFFF;
            *(int *)(*(int *)(s1 + 0x98) + 0x2C) &= 0xF7FFFFFF;
            break;
        case 6:
            *(int *)(*(int *)(s1 + 0x9C) + 0x2C) &= 0xF7FFFFFF;
            *(int *)(*(int *)(s1 + 0xB8) + 0x2C) &= 0xF7FFFFFF;
            break;
        case 7:
            *(int *)(*(int *)(s1 + 0xA0) + 0x2C) &= 0xF7FFFFFF;
            *(int *)(*(int *)(s1 + 0xBC) + 0x2C) &= 0xF7FFFFFF;
            break;
        case 8:
            *(int *)(*(int *)(s1 + 0xC0) + 0x2C) &= 0xF7FFFFFF;
            break;
        }
    }
    switch (*(unsigned char *)(s1 + 0x64)) {
    case 0:
        *(short *)(s1 + 0x130) = 0;
        func_00162B18(s1);
        break;
    case 1:
        *(short *)(s1 + 0x130) = 0;
        func_00162C98(s1);
        break;
    case 2:
        t = D_00747A24;
        if (((t >> 6) & 1) == 1) {
            *(short *)(s1 + 0x130) = 1;
            cCockPlBar_initData(D_003BD6E8 + 0x460);
        } else {
            *(short *)(s1 + 0x130) = 0;
        }
        func_001630E8(s1);
        break;
    case 3:
        t = D_00747A24;
        if (((t >> 6) & 1) == 1) {
            *(short *)(s1 + 0x130) = 1;
            cCockPlBar_initData(D_003BD6E8 + 0x460);
        } else {
            *(short *)(s1 + 0x130) = 0;
        }
        func_001630E8(s1);
        break;
    }
}

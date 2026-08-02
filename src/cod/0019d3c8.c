/* sn-2.95.3-136 matched TU. */

extern char D_00425D48[];
extern int ResetActorState_1BBF00();
extern int cOmBase_checkDamage();
extern int ClearAndResetFields_1FE278();
extern char D_00426D50[];
extern char D_00574380[];
extern int ResetField214FreeField180_1C2820();
extern char D_00426E78[];
extern int SetField214PtrThenInit_1B6F38();
extern int cDamageManage_ReleaseDamageGive();
extern int cDamageUnit_SetDamageCollActive();
extern char D_00427060[];
extern char D_00427400[];

/* clone */



__attribute__((section(".text.func_0019D3C8")))
int func_0019D3C8(void *a0) {
    *(char**)((char*)a0+0x214) = D_00425D48;
    return ResetActorState_1BBF00(a0);
}

/* clone */


__attribute__((section(".text.func_0019F4B0")))
void func_0019F4B0(void *a0) {
    int v1;
    v1 = cOmBase_checkDamage(a0, *(int *)((char*)a0 + 0x650));
    if (v1 == 1) {
        if (*(short *)((char*)a0 + 0x54A) <= 0) {
            int v3 = *(int *)((char*)a0 + 0x5B0);
            *(char *)((char*)a0 + 0x2F4) = 2;
            *(char *)((char*)a0 + 0x2F5) = 0;
            *(char *)((char*)a0 + 0x2F6) = 0;
            *(char *)((char*)a0 + 0x2F7) = 0;
            *(int *)((char*)a0 + 0x5B0) = v3 | 1;
        } else {
            *(char *)((char*)a0 + 0x2F4) = (char)v1;
            *(char *)((char*)a0 + 0x2F5) = 0;
            *(char *)((char*)a0 + 0x2F6) = 0;
            *(char *)((char*)a0 + 0x2F7) = 0;
        }
    }
}

/* clone */





__attribute__((section(".text.func_001A0B78")))
void func_001A0B78(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00426D50;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

/* clone */






__attribute__((section(".text.func_001A0DF0")))
void func_001A0DF0(void *a0, void *a1) {
    int *p;
    int i;
    int v;
    *(int *)((char *)a0 + 0x214) = (int)&D_00426E78;
    p = (int *)((char *)a0 + 0x600);
    for (i = 1; i >= 0; i--) {
        v = *p;
        if (v != 0) {
            ClearAndResetFields_1FE278(&D_00574380, (void *)v);
            *p = 0;
        }
        p++;
    }
    v = *(int *)((char *)a0 + 0x608);
    if (v != 0) {
        cDamageManage_ReleaseDamageGive(&D_00574380);
        *(int *)((char *)a0 + 0x608) = 0;
    }
    SetField214PtrThenInit_1B6F38(a0, a1);
}

/* clone */


__attribute__((section(".text.func_001A1690")))
void func_001A1690(void *a0) {
    short *s2 = (short *)((char *)a0 + 0xD98);
    int *s1 = (int *)((char *)a0 + 0x600);
    int s3 = 0;
    do {
        int r = cOmBase_checkDamage(a0, *s1);
        if (r == 1) {
            int *obj = (int *)*s1;
            int v1 = (int)*(unsigned short *)s2 - *(int *)((char *)obj + 0x4C);
            *s2 = (short)v1;
            if ((short)v1 < 0) {
                *(int *)((char *)a0 + 0x5B0) |= 1;
                *(char *)((char *)a0 + 0xD9C) = (char)s3;
                *(char *)((char *)a0 + 0x2F4) = 2;
                *(char *)((char *)a0 + 0x2F5) = 0;
                *(char *)((char *)a0 + 0x2F6) = 0;
                *(char *)((char *)a0 + 0x2F7) = 0;
            } else {
                *(char *)((char *)a0 + 0x2F4) = (char)r;
                *(char *)((char *)a0 + 0x2F5) = 0;
                *(char *)((char *)a0 + 0x2F6) = 0;
                *(char *)((char *)a0 + 0x2F7) = 0;
            }
        }
        s3++;
        s2++;
        s1++;
    } while (s3 < 2);
}

/* clone */


__attribute__((section(".text.func_001A2350")))
void func_001A2350(void *a0, int a1) {
    int *ebase = (int *)((char *)a0 + 0x600);
    int *base;
    if (ebase[a1] != 0) cDamageUnit_SetDamageCollActive(ebase[a1], 0);
    base = (int *)((char *)a0 + 0xD90);
    base[(unsigned int)a1 >> 5] |= (unsigned int)0x80000000 >> (a1 & 0x1F);
}

/* clone */


__attribute__((section(".text.func_001A2D50")))
void func_001A2D50(void *a0) {
    short *s2 = (short *)((char *)a0 + 0xD9A);
    int *s1 = (int *)((char *)a0 + 0x600);
    int s3 = 0;
    do {
        int r = cOmBase_checkDamage(a0, *s1);
        if (r == 1) {
            int *obj = (int *)*s1;
            int v1 = (int)*(unsigned short *)s2 - *(int *)((char *)obj + 0x4C);
            *s2 = (short)v1;
            if ((short)v1 < 0) {
                *(int *)((char *)a0 + 0x5B0) |= 1;
                *(char *)((char *)a0 + 0xD9E) = (char)s3;
                *(char *)((char *)a0 + 0x2F4) = 2;
                *(char *)((char *)a0 + 0x2F5) = 0;
                *(char *)((char *)a0 + 0x2F6) = 0;
                *(char *)((char *)a0 + 0x2F7) = 0;
            } else {
                *(char *)((char *)a0 + 0x2F4) = (char)r;
                *(char *)((char *)a0 + 0x2F5) = 0;
                *(char *)((char *)a0 + 0x2F6) = 0;
                *(char *)((char *)a0 + 0x2F7) = 0;
            }
        }
        s3++;
        s2++;
        s1++;
    } while (s3 < 2);
}

/* clone */


__attribute__((section(".text.func_001A37F0")))
void func_001A37F0(void *a0, int a1) {
    int *ebase = (int *)((char *)a0 + 0x600);
    int *base;
    if (ebase[a1] != 0) cDamageUnit_SetDamageCollActive(ebase[a1], 0);
    base = (int *)((char *)a0 + 0xD90);
    base[(unsigned int)a1 >> 5] |= (unsigned int)0x80000000 >> (a1 & 0x1F);
}

/* clone */





__attribute__((section(".text.func_001A3B20")))
void func_001A3B20(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00427060;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

/* clone */





__attribute__((section(".text.func_001A6038")))
void func_001A6038(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00427400;
    v1 = *(int *)((char *)a0 + 0x608);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x608) = 0;
    }
    SetField214PtrThenInit_1B6F38(a0, a1);
}

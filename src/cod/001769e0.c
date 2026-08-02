/* sn-2.95.3-136 matched TU. */

extern int cDamageUnit_SetDamageCollActive();
extern int ClearAndResetFields_1FE278();
extern char D_004212E8[];
extern char D_00574380[];
extern int SetField214PtrThenInit_1B6F38();
extern int cDamageManage_ReleaseDamageGive();
extern int cOmBase_checkDamage();
extern char D_004213C0[];
extern int ResetField214FreeField180_1C2820();
extern char D_004214A8[];
extern char D_00421590[];
extern char D_00421658[];
extern char D_00421740[];
extern char D_00421848[];

/* clone */


__attribute__((section(".text.func_001769E0")))
void func_001769E0(void *a0, int a1) {
    int *ebase = (int *)((char *)a0 + 0x600);
    int *base;
    if (ebase[a1] != 0) cDamageUnit_SetDamageCollActive(ebase[a1], 0);
    base = (int *)((char *)a0 + 0xD30);
    base[(unsigned int)a1 >> 5] |= (unsigned int)0x80000000 >> (a1 & 0x1F);
}

/* clone */






__attribute__((section(".text.func_00176CB8")))
void func_00176CB8(void *a0, void *a1) {
    int *p;
    int i;
    int v;
    *(int *)((char *)a0 + 0x214) = (int)&D_004212E8;
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


__attribute__((section(".text.func_00177488")))
void func_00177488(void *a0) {
    short *s2 = (short *)((char *)a0 + 0xD38);
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
                *(char *)((char *)a0 + 0xD3C) = (char)s3;
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


__attribute__((section(".text.func_00178068")))
void func_00178068(void *a0, int a1) {
    int *ebase = (int *)((char *)a0 + 0x600);
    int *base;
    if (ebase[a1] != 0) cDamageUnit_SetDamageCollActive(ebase[a1], 0);
    base = (int *)((char *)a0 + 0xD30);
    base[(unsigned int)a1 >> 5] |= (unsigned int)0x80000000 >> (a1 & 0x1F);
}

/* clone */



__attribute__((section(".text.func_00178340")))
int func_00178340(void *a0) {
    *(char**)((char*)a0+0x214) = D_004213C0;
    return ResetField214FreeField180_1C2820(a0);
}

/* clone */



__attribute__((section(".text.func_001785F0")))
int func_001785F0(void *a0) {
    *(char**)((char*)a0+0x214) = D_004214A8;
    return ResetField214FreeField180_1C2820(a0);
}

/* clone */



__attribute__((section(".text.func_00178848")))
int func_00178848(void *a0) {
    *(char**)((char*)a0+0x214) = D_00421590;
    return SetField214PtrThenInit_1B6F38(a0);
}

/* clone */



__attribute__((section(".text.func_00178AF8")))
int func_00178AF8(void *a0) {
    *(char**)((char*)a0+0x214) = D_00421658;
    return ResetField214FreeField180_1C2820(a0);
}

/* clone */





__attribute__((section(".text.func_00178DB8")))
void func_00178DB8(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00421740;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

/* clone */





__attribute__((section(".text.func_00179050")))
void func_00179050(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00421848;
    v1 = *(int *)((char *)a0 + 0x650);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x650) = 0;
    }
    func_001C7DE0(a0, a1);
}

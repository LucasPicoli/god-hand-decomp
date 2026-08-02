/* sn-2.95.3-136 matched TU. */

extern int ClearAndResetFields_1FE278();
extern char D_00423148[];
extern char D_00574380[];
extern int ResetField214FreeField180_1C2820();
extern char D_00423230[];
extern int cOmBase_checkDamage();
extern char D_00423400[];
extern char D_004234E8[];
extern char D_00423608[];
extern int SetField214PtrThenInit_1B6F38();
extern int cDamageManage_ReleaseDamageGive();
extern char D_00423700[];
extern char D_004237E8[];

/* clone */





__attribute__((section(".text.func_001877D8")))
void func_001877D8(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00423148;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

/* clone */



__attribute__((section(".text.func_00187A50")))
int func_00187A50(void *a0) {
    *(char**)((char*)a0+0x214) = D_00423230;
    return ResetField214FreeField180_1C2820(a0);
}

/* clone */


__attribute__((section(".text.func_00188118")))
void func_00188118(void *a0) {
    int v1;
    v1 = cOmBase_checkDamage(a0, *(int *)((char*)a0 + 0x604));
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





__attribute__((section(".text.func_00188AF0")))
void func_00188AF0(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00423400;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

/* clone */





__attribute__((section(".text.func_00188D80")))
void func_00188D80(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_004234E8;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

/* clone */






__attribute__((section(".text.func_00189008")))
void func_00189008(void *a0, void *a1) {
    int *p;
    int i;
    int v;
    *(int *)((char *)a0 + 0x214) = (int)&D_00423608;
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


__attribute__((section(".text.func_001896E0")))
void func_001896E0(void *a0) {
    short *s2 = (short *)((char *)a0 + 0xCD2);
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
                *(char *)((char *)a0 + 0xCD6) = (char)s3;
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





__attribute__((section(".text.func_0018A620")))
void func_0018A620(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00423700;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    SetField214PtrThenInit_1B6F38(a0, a1);
}

/* clone */


__attribute__((section(".text.func_0018A988")))
void func_0018A988(void *a0) {
    int v1;
    v1 = cOmBase_checkDamage(a0, *(int *)((char*)a0 + 0x600));
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





__attribute__((section(".text.func_0018B318")))
void func_0018B318(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_004237E8;
    v1 = *(int *)((char *)a0 + 0x650);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x650) = 0;
    }
    func_001C7DE0(a0, a1);
}

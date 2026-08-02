/* sn-2.95.3-136 matched TU. */

extern char D_00420D68[];
extern int InitField214WithPtr429420_1BD650();
extern int cDamageUnit_SetDamageCollActive();
extern int ClearAndResetFields_1FE278();
extern char D_00420FE0[];
extern char D_00574380[];
extern int cOmBase_checkDamage();
extern int ClearStateAndFlag_1C7E08();
extern char D_005CAE50[];
extern char D_004210D0[];
extern char D_004211D8[];
extern int SetField214PtrThenInit_1B6F38();
extern int cDamageManage_ReleaseDamageGive();

/* clone */



__attribute__((section(".text.func_00171B48")))
int func_00171B48(void *a0) {
    *(char**)((char*)a0+0x214) = D_00420D68;
    return InitField214WithPtr429420_1BD650(a0);
}

/* clone */


__attribute__((section(".text.func_00173638")))
void func_00173638(void *a0, int a1) {
    int *ebase = (int *)((char *)a0 + 0x600);
    int *base;
    if (ebase[a1] != 0) cDamageUnit_SetDamageCollActive(ebase[a1], 0);
    base = (int *)((char *)a0 + 0xD90);
    base[(unsigned int)a1 >> 5] |= (unsigned int)0x80000000 >> (a1 & 0x1F);
}

/* clone */





__attribute__((section(".text.func_00173A78")))
void func_00173A78(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00420FE0;
    v1 = *(int *)((char *)a0 + 0x650);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x650) = 0;
    }
    func_001C7DE0(a0, a1);
}

/* clone */


__attribute__((section(".text.func_00173DE8")))
void func_00173DE8(void *a0) {
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





__attribute__((section(".text.func_00174650")))
void func_00174650(void *a0) {
    int v0;
    v0 = (*(int*)((char*)a0 + 0x5B0) & -9) | 4;
    *(int*)((char*)a0 + 0x5B0) = v0;
    if (*(int*)((char*)a0 + 0x650) != 0) {
        cDamageUnit_SetDamageCollActive(*(int*)((char*)a0 + 0x650), 0);
    }
    func_001331B8((int)&D_005CAE50, *(double*)((char*)a0 + 0x540), 0);
    ClearStateAndFlag_1C7E08(a0);
}

/* clone */





__attribute__((section(".text.func_00174830")))
void func_00174830(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_004210D0;
    v1 = *(int *)((char *)a0 + 0x650);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x650) = 0;
    }
    func_001C7DE0(a0, a1);
}

/* clone */


__attribute__((section(".text.func_00174BB0")))
void func_00174BB0(void *a0) {
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





__attribute__((section(".text.func_00175450")))
void func_00175450(void *a0) {
    int v0;
    v0 = (*(int*)((char*)a0 + 0x5B0) & -9) | 4;
    *(int*)((char*)a0 + 0x5B0) = v0;
    if (*(int*)((char*)a0 + 0x650) != 0) {
        cDamageUnit_SetDamageCollActive(*(int*)((char*)a0 + 0x650), 0);
    }
    func_001331B8((int)&D_005CAE50, *(double*)((char*)a0 + 0x540), 0);
    ClearStateAndFlag_1C7E08(a0);
}

/* clone */






__attribute__((section(".text.func_00175630")))
void func_00175630(void *a0, void *a1) {
    int *p;
    int i;
    int v;
    *(int *)((char *)a0 + 0x214) = (int)&D_004211D8;
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


__attribute__((section(".text.func_00175E00")))
void func_00175E00(void *a0) {
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

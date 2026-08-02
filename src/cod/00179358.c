/* sn-2.95.3-136 matched TU. */

extern int cOmBase_checkDamage();
extern int ClearStateAndFlag_1C7E08();
extern char D_005CAE50[];
extern int cDamageUnit_SetDamageCollActive();
extern int ClearAndResetFields_1FE278();
extern char D_00421938[];
extern char D_00574380[];
extern char D_00421A08[];
extern int SetField214PtrThenInit_1B6F38();
extern char D_00421C80[];
extern int InitField214WithPtr429420_1BD650();
extern char D_00421D68[];

/* clone */


__attribute__((section(".text.func_00179358")))
void func_00179358(void *a0) {
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





__attribute__((section(".text.func_00179C00")))
void func_00179C00(void *a0) {
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





__attribute__((section(".text.func_00179DE0")))
void func_00179DE0(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00421938;
    v1 = *(int *)((char *)a0 + 0x650);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x650) = 0;
    }
    func_001C7DE0(a0, a1);
}

/* clone */


__attribute__((section(".text.func_0017A108")))
void func_0017A108(void *a0) {
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





__attribute__((section(".text.func_0017A980")))
void func_0017A980(void *a0) {
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





__attribute__((section(".text.func_0017AC30")))
void func_0017AC30(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00421A08;
    v1 = *(int *)((char *)a0 + 0x60C);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x60C) = 0;
    }
    SetField214PtrThenInit_1B6F38(a0, a1);
}

/* clone */



__attribute__((section(".text.func_0017C4E0")))
int func_0017C4E0(void *a0) {
    *(char**)((char*)a0+0x214) = D_00421C80;
    return InitField214WithPtr429420_1BD650(a0);
}

/* clone */





__attribute__((section(".text.func_0017C6A8")))
void func_0017C6A8(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00421D68;
    v1 = *(int *)((char *)a0 + 0x650);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x650) = 0;
    }
    func_001C7DE0(a0, a1);
}

/* clone */


__attribute__((section(".text.func_0017CA18")))
void func_0017CA18(void *a0) {
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





__attribute__((section(".text.func_0017D280")))
void func_0017D280(void *a0) {
    int v0;
    v0 = (*(int*)((char*)a0 + 0x5B0) & -9) | 4;
    *(int*)((char*)a0 + 0x5B0) = v0;
    if (*(int*)((char*)a0 + 0x650) != 0) {
        cDamageUnit_SetDamageCollActive(*(int*)((char*)a0 + 0x650), 0);
    }
    func_001331B8((int)&D_005CAE50, *(double*)((char*)a0 + 0x540), 0);
    ClearStateAndFlag_1C7E08(a0);
}

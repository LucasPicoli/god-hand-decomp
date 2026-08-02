/* sn-2.95.3-136 matched TU. */

extern int ClearAndResetFields_1FE278();
extern char D_00422858[];
extern char D_00574380[];
extern int cOmBase_checkDamage();
extern int ClearStateAndFlag_1C7E08();
extern char D_005CAE50[];
extern int cDamageUnit_SetDamageCollActive();
extern char D_00422928[];
extern int ResetField214FreeField180_1C2820();
extern char D_00422B48[];
extern char D_00422C18[];
extern char D_00422F90[];
extern int ResetActorState_1BBF00();
extern char D_00423078[];

/* clone */





__attribute__((section(".text.func_001818C0")))
void func_001818C0(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00422858;
    v1 = *(int *)((char *)a0 + 0x650);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x650) = 0;
    }
    func_001C7DE0(a0, a1);
}

/* clone */


__attribute__((section(".text.func_00181C20")))
void func_00181C20(void *a0) {
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





__attribute__((section(".text.func_00182488")))
void func_00182488(void *a0) {
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



__attribute__((section(".text.func_00182668")))
int func_00182668(void *a0) {
    *(char**)((char*)a0+0x214) = D_00422928;
    return ResetField214FreeField180_1C2820(a0);
}

/* clone */





__attribute__((section(".text.func_00183380")))
void func_00183380(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00422B48;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    func_001BFB00(a0, a1);
}

/* clone */



__attribute__((section(".text.func_00183628")))
int func_00183628(void *a0) {
    *(char**)((char*)a0+0x214) = D_00422C18;
    return ResetField214FreeField180_1C2820(a0);
}

/* clone */



__attribute__((section(".text.func_001867C0")))
int func_001867C0(void *a0) {
    *(char**)((char*)a0+0x214) = D_00422F90;
    return ResetActorState_1BBF00(a0);
}

/* clone */





__attribute__((section(".text.func_00186A20")))
void func_00186A20(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00423078;
    v1 = *(int *)((char *)a0 + 0x650);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x650) = 0;
    }
    func_001C7DE0(a0, a1);
}

/* clone */


__attribute__((section(".text.func_00186D90")))
void func_00186D90(void *a0) {
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





__attribute__((section(".text.func_001875F8")))
void func_001875F8(void *a0) {
    int v0;
    v0 = (*(int*)((char*)a0 + 0x5B0) & -9) | 4;
    *(int*)((char*)a0 + 0x5B0) = v0;
    if (*(int*)((char*)a0 + 0x650) != 0) {
        cDamageUnit_SetDamageCollActive(*(int*)((char*)a0 + 0x650), 0);
    }
    func_001331B8((int)&D_005CAE50, *(double*)((char*)a0 + 0x540), 0);
    ClearStateAndFlag_1C7E08(a0);
}

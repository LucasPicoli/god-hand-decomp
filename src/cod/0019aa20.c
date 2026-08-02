/* sn-2.95.3-136 matched TU. */

extern int ClearAndResetFields_1FE278();
extern char D_00425630[];
extern char D_00574380[];
extern int ResetField214FreeField180_1C2820();
extern char D_00425718[];
extern char D_00425820[];
extern int SetField214PtrThenInit_1B6F38();
extern int cOmBase_checkDamage();
extern char D_004258F0[];
extern char D_004259D8[];
extern char D_00425AC0[];
extern char D_00425B90[];
extern int ResetActorState_1BBF00();
extern char D_00425C78[];

/* clone */





__attribute__((section(".text.func_0019AA20")))
void func_0019AA20(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00425630;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

/* clone */





__attribute__((section(".text.func_0019ACA0")))
void func_0019ACA0(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00425718;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

/* clone */





__attribute__((section(".text.func_0019AF20")))
void func_0019AF20(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00425820;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    SetField214PtrThenInit_1B6F38(a0, a1);
}

/* clone */


__attribute__((section(".text.func_0019B458")))
void func_0019B458(void *a0) {
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





__attribute__((section(".text.func_0019BC40")))
void func_0019BC40(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_004258F0;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

/* clone */





__attribute__((section(".text.func_0019BEB0")))
void func_0019BEB0(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_004259D8;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

/* clone */





__attribute__((section(".text.func_0019C150")))
void func_0019C150(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00425AC0;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    func_001BFB00(a0, a1);
}

/* clone */



__attribute__((section(".text.func_0019C3A8")))
int func_0019C3A8(void *a0) {
    *(char**)((char*)a0+0x214) = D_00425B90;
    return ResetActorState_1BBF00(a0);
}

/* clone */





__attribute__((section(".text.func_0019C610")))
void func_0019C610(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00425C78;
    v1 = *(int *)((char *)a0 + 0x650);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x650) = 0;
    }
    func_001C7DE0(a0, a1);
}

/* clone */


__attribute__((section(".text.func_0019C980")))
void func_0019C980(void *a0) {
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

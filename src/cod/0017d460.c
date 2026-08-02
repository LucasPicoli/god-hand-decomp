/* sn-2.95.3-136 matched TU. */

extern char D_00421E38[];
extern int ResetActorState_1BBF00();
extern char D_00421FE8[];
extern int SetField214PtrThenInit_1B6F38();
extern char D_004220B0[];
extern char D_00422178[];
extern int InitField214WithPtr429420_1BD650();
extern char D_00422308[];
extern char D_004223D0[];
extern char D_00422498[];
extern char D_00422560[];
extern int ClearAndResetFields_1FE278();
extern char D_004226A8[];
extern char D_00574380[];
extern char D_00422770[];

/* clone */



__attribute__((section(".text.func_0017D460")))
int func_0017D460(void *a0) {
    *(char**)((char*)a0+0x214) = D_00421E38;
    return ResetActorState_1BBF00(a0);
}

/* clone */



__attribute__((section(".text.func_0017E1C0")))
int func_0017E1C0(void *a0) {
    *(char**)((char*)a0+0x214) = D_00421FE8;
    return SetField214PtrThenInit_1B6F38(a0);
}

/* clone */



__attribute__((section(".text.func_0017E8B0")))
int func_0017E8B0(void *a0) {
    *(char**)((char*)a0+0x214) = D_004220B0;
    return ResetActorState_1BBF00(a0);
}

/* clone */



__attribute__((section(".text.func_0017EAD0")))
int func_0017EAD0(void *a0) {
    *(char**)((char*)a0+0x214) = D_00422178;
    return InitField214WithPtr429420_1BD650(a0);
}

/* clone */



__attribute__((section(".text.func_0017EE78")))
int func_0017EE78(void *a0) {
    *(char**)((char*)a0+0x214) = D_00422308;
    return SetField214PtrThenInit_1B6F38(a0);
}

/* clone */



__attribute__((section(".text.func_0017F2F8")))
int func_0017F2F8(void *a0) {
    *(char**)((char*)a0+0x214) = D_004223D0;
    return ResetActorState_1BBF00(a0);
}

/* clone */



__attribute__((section(".text.func_0017F5A8")))
int func_0017F5A8(void *a0) {
    *(char**)((char*)a0+0x214) = D_00422498;
    return SetField214PtrThenInit_1B6F38(a0);
}

/* clone */



__attribute__((section(".text.func_0017FC30")))
int func_0017FC30(void *a0) {
    *(char**)((char*)a0+0x214) = D_00422560;
    return SetField214PtrThenInit_1B6F38(a0);
}

/* clone */





__attribute__((section(".text.func_001809B0")))
void func_001809B0(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_004226A8;
    v1 = *(int *)((char *)a0 + 0x60C);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x60C) = 0;
    }
    SetField214PtrThenInit_1B6F38(a0, a1);
}

/* clone */



__attribute__((section(".text.func_001816C0")))
int func_001816C0(void *a0) {
    *(char**)((char*)a0+0x214) = D_00422770;
    return ResetActorState_1BBF00(a0);
}

/* sn-2.95.3-136 matched TU. */

extern char D_004274D0[];
extern int SetField214PtrThenInit_1B6F38();
extern char D_004275C8[];
extern char D_00427690[];
extern int ResetActorState_1BBF00();
extern char D_004277B8[];
extern char D_005CAE50[];
extern char D_00427880[];
extern char D_00427B20[];
extern char D_00427F48[];
extern char D_00428228[];
extern int InitField214WithPtr429420_1BD650();
extern char D_004284A0[];
extern int ResetField214FreeField180_1C2820();
extern char D_00428588[];

/* clone */



__attribute__((section(".text.func_001A6DA0")))
int func_001A6DA0(void *a0) {
    *(char**)((char*)a0+0x214) = D_004274D0;
    return SetField214PtrThenInit_1B6F38(a0);
}

/* clone */



__attribute__((section(".text.func_001A77F8")))
int func_001A77F8(void *a0) {
    *(char**)((char*)a0+0x214) = D_004275C8;
    return SetField214PtrThenInit_1B6F38(a0);
}

/* clone */



__attribute__((section(".text.func_001A81D8")))
int func_001A81D8(void *a0) {
    *(char**)((char*)a0+0x214) = D_00427690;
    return ResetActorState_1BBF00(a0);
}

/* clone */





__attribute__((section(".text.func_001A8380")))
void func_001A8380(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_004277B8;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        func_0012EC58(&D_005CAE50, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    SetField214PtrThenInit_1B6F38(a0, a1);
}

/* clone */



__attribute__((section(".text.func_001A8730")))
int func_001A8730(void *a0) {
    *(char**)((char*)a0+0x214) = D_00427880;
    return SetField214PtrThenInit_1B6F38(a0);
}

/* clone */



__attribute__((section(".text.func_001A96C0")))
int func_001A96C0(void *a0) {
    *(char**)((char*)a0+0x214) = D_00427B20;
    return SetField214PtrThenInit_1B6F38(a0);
}

/* clone */



__attribute__((section(".text.func_001ADBC0")))
int func_001ADBC0(void *a0) {
    *(char**)((char*)a0+0x214) = D_00427F48;
    return SetField214PtrThenInit_1B6F38(a0);
}

/* clone */



__attribute__((section(".text.func_001B0BA8")))
int func_001B0BA8(void *a0) {
    *(char**)((char*)a0+0x214) = D_00428228;
    return InitField214WithPtr429420_1BD650(a0);
}

/* clone */



__attribute__((section(".text.func_001B22A8")))
int func_001B22A8(void *a0) {
    *(char**)((char*)a0+0x214) = D_004284A0;
    return ResetField214FreeField180_1C2820(a0);
}

/* clone */



__attribute__((section(".text.func_001B2520")))
int func_001B2520(void *a0) {
    *(char**)((char*)a0+0x214) = D_00428588;
    return SetField214PtrThenInit_1B6F38(a0);
}

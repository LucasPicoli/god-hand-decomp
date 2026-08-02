/* sn-2.95.3-136 matched TU. */

extern char D_00428650[];
extern int SetField214PtrThenInit_1B6F38();
extern int ClearField5B4IfFlagUnset_1B76B0();
extern char D_00429190[];
extern char D_005CAE50[];
extern char D_00429620[];
extern char D_004296F0[];
extern char D_004297D8[];
extern char D_00429B88[];
extern char D_00574380[];
extern int cDamageManage_ReleaseDamageGive();
extern int cOmBase_checkDamage();
extern char D_00429EC8[];

/* clone */



__attribute__((section(".text.func_001B37A8")))
int func_001B37A8(void *a0) {
    *(char**)((char*)a0+0x214) = D_00428650;
    return SetField214PtrThenInit_1B6F38(a0);
}

/* clone */



__attribute__((section(".text.func_001B7168")))
void func_001B7168(void *a0) {
    if (ClearField5B4IfFlagUnset_1B76B0(a0))
        func_001B76D8(a0);
}

/* clone */



__attribute__((section(".text.func_001BBB00")))
int func_001BBB00(void *a0) {
    *(char**)((char*)a0+0x214) = D_00429190;
    return SetField214PtrThenInit_1B6F38(a0);
}

/* clone */



__attribute__((section(".text.func_001BDBB8")))
void func_001BDBB8(void *a0) {
    void *a1 = *(void **)((char *)a0 + 0x77C);
    if (!a1)
        return;
    func_0012EC58(&D_005CAE50, a1);
    *(int *)((char *)a0 + 0x77C) = 0;
}

/* clone */



__attribute__((section(".text.func_001BE8F0")))
int func_001BE8F0(void *a0) {
    *(char**)((char*)a0+0x214) = D_00429620;
    return SetField214PtrThenInit_1B6F38(a0);
}

/* clone */



__attribute__((section(".text.func_001BF4B8")))
int func_001BF4B8(void *a0) {
    *(char**)((char*)a0+0x214) = D_004296F0;
    return SetField214PtrThenInit_1B6F38(a0);
}

/* clone */



__attribute__((section(".text.func_001BFB00")))
int func_001BFB00(void *a0) {
    *(char**)((char*)a0+0x214) = D_004297D8;
    return SetField214PtrThenInit_1B6F38(a0);
}

/* clone */





__attribute__((section(".text.func_001C00C8")))
void func_001C00C8(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00429B88;
    v1 = *(int *)((char *)a0 + 0x680);
    if (v1 != 0) {
        cDamageManage_ReleaseDamageGive(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x680) = 0;
    }
    SetField214PtrThenInit_1B6F38(a0, a1);
}

/* clone */


__attribute__((section(".text.func_001C2B08")))
void func_001C2B08(void *a0) {
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



__attribute__((section(".text.func_001C8FC8")))
int func_001C8FC8(void *a0) {
    *(char**)((char*)a0+0x214) = D_00429EC8;
    return SetField214PtrThenInit_1B6F38(a0);
}

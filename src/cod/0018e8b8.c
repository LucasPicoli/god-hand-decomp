/* sn-2.95.3-136 matched TU. */

extern int ClearStateAndFlag_1C7E08();
extern char D_005CAE50[];
extern int cDamageUnit_SetDamageCollActive();
extern int ClearAndResetFields_1FE278();
extern char D_00423B88[];
extern char D_00574380[];
extern int ResetField214FreeField180_1C2820();
extern char D_00423C70[];
extern char D_00423D40[];
extern int ResetActorState_1BBF00();
extern char D_00424128[];
extern char D_004241F0[];
extern char D_00425290[];
extern char D_00425378[];
extern char D_00425460[];
extern char D_00425548[];

/* clone */





__attribute__((section(".text.func_0018E8B8")))
void func_0018E8B8(void *a0) {
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





__attribute__((section(".text.func_0018EA98")))
void func_0018EA98(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00423B88;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

/* clone */





__attribute__((section(".text.func_0018ECD0")))
void func_0018ECD0(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00423C70;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    func_001BFB00(a0, a1);
}

/* clone */



__attribute__((section(".text.func_0018EF30")))
int func_0018EF30(void *a0) {
    *(char**)((char*)a0+0x214) = D_00423D40;
    return ResetActorState_1BBF00(a0);
}

/* clone */



__attribute__((section(".text.func_00191DC0")))
int func_00191DC0(void *a0) {
    *(char**)((char*)a0+0x214) = D_00424128;
    return ResetActorState_1BBF00(a0);
}

/* clone */



__attribute__((section(".text.func_00192028")))
int func_00192028(void *a0) {
    *(char**)((char*)a0+0x214) = D_004241F0;
    return ResetActorState_1BBF00(a0);
}

/* clone */





__attribute__((section(".text.func_0019A058")))
void func_0019A058(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00425290;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

/* clone */





__attribute__((section(".text.func_0019A2C8")))
void func_0019A2C8(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00425378;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

/* clone */





__attribute__((section(".text.func_0019A530")))
void func_0019A530(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00425460;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

/* clone */





__attribute__((section(".text.func_0019A7A8")))
void func_0019A7A8(void *a0, void *a1) {
    int v1;
    *(int **)((char *)a0 + 0x214) = &D_00425548;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

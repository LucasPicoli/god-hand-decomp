/* sn-2.95.3-136 matched TU. */

extern void LookupSlotPopulateFieldsAndDispatch_1F7858(void *, int, int, int, void *, void *, int);
extern char D_00568288;
extern void func_001E9F18(void);
extern int D_00466470[];
extern int D_00747A34;
extern char D_00423338[];
extern char D_00574380[];
extern void ClearAndResetFields_1FE278(void *a, void *b);
extern void cDamageManage_ReleaseDamageGive(void *a, void *b);
extern void SetField214PtrThenInit_1B6F38(void *a, void *b);
extern char D_00423E48[];
extern void func_001C7DE0(void *a, void *b);
extern char D_00427148[];
extern void ResetField214FreeField180_1C2820(void *a, void *b);
extern char D_00427230[];
extern char D_004272F8[];
extern char D_00427E60[];

/* clone */




__attribute__((section(".text.DogRace_SetActBtn")))
void DogRace_SetActBtn(void *a0) {
    LookupSlotPopulateFieldsAndDispatch_1F7858(&D_00568288, 4, 0x18, 0, (void *)&func_001E9F18, a0, 0);
}

/* clone */




__attribute__((section(".text.func_001500C0")))
int func_001500C0(void) {
    if (D_00747A34 & 0x20000) {
        return 0;
    }
    return func_00150538(D_00466470);
}

__attribute__((section(".text.func_00187D10")))
void func_00187D10(void *a0, void *a1) {
    int v1;
    int v2;
    *(int **)((char *)a0 + 0x214) = (int *)&D_00423338;
    v1 = *(int *)((char *)a0 + 0x604);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x604) = 0;
    }
    v2 = *(int *)((char *)a0 + 0x608);
    if (v2 != 0) {
        cDamageManage_ReleaseDamageGive(&D_00574380, (void *)v2);
        *(int *)((char *)a0 + 0x608) = 0;
    }
    SetField214PtrThenInit_1B6F38(a0, a1);
}

__attribute__((section(".text.func_0018F1A0")))
void func_0018F1A0(void *a0, void *a1) {
    int v1;
    int v2;
    *(int **)((char *)a0 + 0x214) = (int *)&D_00423E48;
    v1 = *(int *)((char *)a0 + 0x654);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x654) = 0;
    }
    v2 = *(int *)((char *)a0 + 0x658);
    if (v2 != 0) {
        cDamageManage_ReleaseDamageGive(&D_00574380, (void *)v2);
        *(int *)((char *)a0 + 0x658) = 0;
    }
    func_001C7DE0(a0, a1);
}

__attribute__((section(".text.func_001A3D98")))
void func_001A3D98(void *a0, void *a1) {
    int v1;
    int v2;
    *(int **)((char *)a0 + 0x214) = (int *)&D_00427148;
    v1 = *(int *)((char *)a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x600) = 0;
    }
    v2 = *(int *)((char *)a0 + 0x604);
    if (v2 != 0) {
        cDamageManage_ReleaseDamageGive(&D_00574380, (void *)v2);
        *(int *)((char *)a0 + 0x604) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

__attribute__((section(".text.func_001A43B8")))
void func_001A43B8(void *a0, void *a1) {
    int v1;
    int v2;
    *(int **)((char *)a0 + 0x214) = (int *)&D_00427230;
    v1 = *(int *)((char *)a0 + 0x764);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x764) = 0;
    }
    v2 = *(int *)((char *)a0 + 0x768);
    if (v2 != 0) {
        cDamageManage_ReleaseDamageGive(&D_00574380, (void *)v2);
        *(int *)((char *)a0 + 0x768) = 0;
    }
    SetField214PtrThenInit_1B6F38(a0, a1);
}

__attribute__((section(".text.func_001A5190")))
void func_001A5190(void *a0, void *a1) {
    int v1;
    int v2;
    *(int **)((char *)a0 + 0x214) = (int *)&D_004272F8;
    v1 = *(int *)((char *)a0 + 0x624);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x624) = 0;
    }
    v2 = *(int *)((char *)a0 + 0x620);
    if (v2 != 0) {
        cDamageManage_ReleaseDamageGive(&D_00574380, (void *)v2);
        *(int *)((char *)a0 + 0x620) = 0;
    }
    SetField214PtrThenInit_1B6F38(a0, a1);
}

__attribute__((section(".text.func_001ABE08")))
void func_001ABE08(void *a0, void *a1) {
    int v1;
    int v2;
    *(int **)((char *)a0 + 0x214) = (int *)&D_00427E60;
    v1 = *(int *)((char *)a0 + 0x624);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
        *(int *)((char *)a0 + 0x624) = 0;
    }
    v2 = *(int *)((char *)a0 + 0x628);
    if (v2 != 0) {
        cDamageManage_ReleaseDamageGive(&D_00574380, (void *)v2);
        *(int *)((char *)a0 + 0x628) = 0;
    }
    SetField214PtrThenInit_1B6F38(a0, a1);
}

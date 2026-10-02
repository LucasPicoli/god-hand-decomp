/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern int D_0041B598;
extern int D_0041B590;
extern int D_00462FC0;
extern void cCollisionSolidManage_ReleaseUnit(void *, void *);
extern void func_002A73C8(void *, void *);
extern int D_007854C8;
extern int D_0041B638;
extern int D_007854D8;
extern void func_002A9300(void);
extern void SetField_0_4_8_31EEA8(void *, void *, void *);
extern int D_007854E8;
extern int D_0041B710;
extern int D_007854F8;
extern void func_0014FD20(void);
extern float D_003BC7C0;
extern void func_002A8578(void *, void *, void *, int, int, int, float);
extern void cObjBase_addNullSpeed_Rotation(void *, float);
extern void cObjBase_addNullSpeed(void *, float);

__attribute__((section(".text.IsStateByteIdle_10B5F0")))
int IsStateByteIdle_10B5F0(unsigned char *a0) {
    int c;
    if (a0[0x2F4] != 0)
        return 0;
    c = a0[0x2F5];
    if (c != 0 && c != 0xA)
        return 0;
    return 1;
}

__attribute__((section(".text.cPlBase")))
void *cPlBase(void *a0) {
    void *r;
    cGameObj(a0);
    *(int **)((char*)a0 + 0x214) = &D_0041B598;
    r = a0;
    *(int **)((char*)a0 + 0x4AC) = &D_0041B590;
    return r;
}

__attribute__((section(".text.InitObjectVtableAndRegister_1002C0")))
void InitObjectVtableAndRegister_1002C0(void *a0, void *a1) {
    *(int **)((char*)a0 + 0x214) = &D_0041B598;
    cCollisionSolidManage_ReleaseUnit(&D_00462FC0, a0);
    func_002A73C8(a0, a1);
}

__attribute__((section(".text.GetOrInitSingleton_100328")))
void *GetOrInitSingleton_100328(void) {
    if (D_007854C8 == 0) {
        func_002A9300();
        SetField_0_4_8_31EEA8(&D_007854C8, &D_0041B638, &D_007854D8);
    }
    return &D_007854C8;
}

__attribute__((section(".text.GetOrInitSingletonAlt_101E48")))
void *GetOrInitSingletonAlt_101E48(void) {
    if (D_007854E8 == 0) {
        func_0014FD20();
        SetField_0_4_8_31EEA8(&D_007854E8, &D_0041B710, &D_007854F8);
    }
    return &D_007854E8;
}

__attribute__((section(".text.UpdateAttackMoveState_102BD8")))
void UpdateAttackMoveState_102BD8(void *a0) {
    void *r = Getplayer();
    switch (*(unsigned char *)((char *)a0 + 0x2F6)) {
    case 0: {
        void *p = *(void **)((char *)a0 + 0x304);
        void *q = (void *)(*(int *)((char *)p + 0x24) + (int)p);
        func_002A8578(a0, q, q, 5, 0, 0, 0.0f);
        *(unsigned char *)((char *)a0 + 0x2F6) = *(unsigned char *)((char *)a0 + 0x2F6) + 1;
    }
    case 1:
        *(float *)((char *)r + 0x15F0) = D_003BC7C0;
        if (moveMotion(a0) != 0) {
            *(unsigned char *)((char *)a0 + 0x2F4) = 0;
            *(unsigned char *)((char *)a0 + 0x2F5) = 0;
            *(unsigned char *)((char *)a0 + 0x2F6) = 0;
            *(unsigned char *)((char *)a0 + 0x2F7) = 0;
        }
        cObjBase_addNullSpeed_Rotation(a0, 1.0f);
        cObjBase_addNullSpeed(a0, 1.0f);
        break;
    default:
        break;
    }
}

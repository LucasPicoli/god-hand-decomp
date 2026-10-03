/* sn-2.95.3-136 matched TU. */

extern int cSceAtManager_SetDisableById(int a0, int a1);
extern void cScenario_taskExec(void *a0, void *a1, void *a2, int a3);
extern char D_005FEA60[];
extern char *D_003C2F84;
extern void func_001E9F68(void);
extern int D_00785BD8;
extern int D_00423F00;
extern int D_007858B8;
extern void func_001C8F30(void);
extern void SetField_0_4_8_31EEA8(void *a0, void *a1, void *a2);
extern int D_00785F88;
extern int D_004274B0;
extern int D_00785878;
extern void GetOrInitGlobal785878_1B8058(void);
extern int D_007860B8;
extern int D_00428828;
extern void Obj0000_Set_D_007474A0_Fields_5D8_5E0(int a0);
extern void cIDBase_release(int a0);
extern void func_00161590(int a0);
extern char **D_003C2384;

/* Disable the scenario object tied to this machine's slot id, then queue its step task. */






__attribute__((section(".text.ActBtnHandler_Variant2")))
void ActBtnHandler_Variant2(char *self) {
    cSceAtManager_SetDisableById((int)D_005FEA60, *(unsigned short *)(self + 0x1B0));
    cScenario_taskExec(D_003C2F84, (void *)&func_001E9F68, self, -1);
}

/* Return the shared singleton at D_00785BD8, building it on first use. */






__attribute__((section(".text.GetSingletonA")))
void *GetSingletonA(void) {
    void *p = &D_00785BD8;
    if (D_00785BD8 == 0) {
        func_001C8F30();
        SetField_0_4_8_31EEA8(p, &D_00423F00, &D_007858B8);
    }
    return p;
}

/* Return the shared singleton at D_00785F88, building it on first use. */






__attribute__((section(".text.GetSingletonB")))
void *GetSingletonB(void) {
    void *p = &D_00785F88;
    if (D_00785F88 == 0) {
        GetOrInitGlobal785878_1B8058();
        SetField_0_4_8_31EEA8(p, &D_004274B0, &D_00785878);
    }
    return p;
}

/* Return the shared singleton at D_007860B8, building it on first use. */






__attribute__((section(".text.GetSingletonC")))
void *GetSingletonC(void) {
    void *p = &D_007860B8;
    if (D_007860B8 == 0) {
        GetOrInitGlobal785878_1B8058();
        SetField_0_4_8_31EEA8(p, &D_00428828, &D_00785878);
    }
    return p;
}

/* Reset an object: run the base reset, release both id slots, clear two counters on the shared record. */





__attribute__((section(".text.ResetObjAndReleaseIdsA")))
void ResetObjAndReleaseIdsA(int a0) {
    char *p;
    Obj0000_Set_D_007474A0_Fields_5D8_5E0(a0);
    cIDBase_release(a0 + 0xE0);
    cIDBase_release(a0);
    p = *D_003C2384;
    *(int *)(p + 0x44) = 0;
    *(int *)(p + 0x40) = 0;
    func_00161590(a0);
}

/* Reset an object: run the base reset, release both id slots, clear two counters on the shared record. */





__attribute__((section(".text.ResetObjAndReleaseIdsB")))
void ResetObjAndReleaseIdsB(int a0) {
    char *p;
    Obj0000_Set_D_007474A0_Fields_5D8_5E0(a0);
    cIDBase_release(a0 + 0xC0);
    cIDBase_release(a0);
    p = *D_003C2384;
    *(int *)(p + 0x44) = 0;
    *(int *)(p + 0x40) = 0;
    func_00161590(a0);
}

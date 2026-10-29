extern void SetField_0_4_8_31EEA8(void *a, void *b, void *c);
extern void func_0031EEC8(void *a, void *b);

/* cCollisionScrollSolid__tf — 2-arg variant (no pre-init call). */
extern int D_00460D00, D_0041D5D0;
__attribute__((section(".text.cCollisionScrollSolid__tf")))
int *cCollisionScrollSolid__tf(void) {
    if (D_00460D00 == 0) {
        func_0031EEC8(&D_00460D00, &D_0041D5D0);
    }
    return &D_00460D00;
}

/* GetSingleton785868_171AB8 — pre-init GetOrInitGlobal785878_1B8058() + 3-arg registration. */
extern int D_00785868, D_00420D50, D_00785878;
extern void GetOrInitGlobal785878_1B8058(void);
__attribute__((section(".text.GetSingleton785868_171AB8")))
int *GetSingleton785868_171AB8(void) {
    if (D_00785868 == 0) {
        GetOrInitGlobal785878_1B8058();
        SetField_0_4_8_31EEA8(&D_00785868, &D_00420D50, &D_00785878);
    }
    return &D_00785868;
}

/* cOmWeapon__tf — same shape as GetSingleton785868_171AB8 (shared init + arg2). */
extern int D_00786178, D_0042AB48;
__attribute__((section(".text.cOmWeapon__tf")))
int *cOmWeapon__tf(void) {
    if (D_00786178 == 0) {
        GetOrInitGlobal785878_1B8058();
        SetField_0_4_8_31EEA8(&D_00786178, &D_0042AB48, &D_00785878);
    }
    return &D_00786178;
}

/* GetSingleton7861C8_276790 — pre-init func_0028FDD0() + 3-arg registration. */
extern int D_007861C8, D_00447AB8, D_007861D8;
extern void func_0028FDD0(void);
__attribute__((section(".text.GetSingleton7861C8_276790")))
int *GetSingleton7861C8_276790(void) {
    if (D_007861C8 == 0) {
        func_0028FDD0();
        SetField_0_4_8_31EEA8(&D_007861C8, &D_00447AB8, &D_007861D8);
    }
    return &D_007861C8;
}

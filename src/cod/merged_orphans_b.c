extern int D_00421C68;
extern int D_00422B30;
extern int D_00427218;
extern int D_00427580;
extern int D_00427B08;
extern int D_00428638;
extern int D_00448298;
extern int D_0044E398;
extern int D_0044F030;
extern int D_0044F398;
extern int D_0044F6C0;
extern int D_0044F868;
extern int D_0044FBA8;
extern int D_0044FDB8;
extern int D_00450CA8;
extern int D_00460D58;
extern int D_007854F8;
extern int D_00785798;
extern int D_00785878;
extern int D_00785978;
extern int D_00785A98;
extern int D_00785F58;
extern int D_00785F98;
extern int D_00785FE8;
extern int D_00786098;
extern int D_007861D8;
extern int D_00786248;
extern int D_007863C8;
extern int D_007863E8;
extern int D_007863F8;
extern int D_007864C8;
extern int D_00786508;
extern int D_00786268;
extern int D_00448688;
extern int D_00786558;
extern int D_00786578;
extern int D_00786598;
extern int D_007865A8;
extern int D_00786618;

extern void cObjBase__tf(void);
extern void GetOrInitGlobal785878_1B8058(void);
extern void GetOrInitGlobal785798_1C3BE8(void);
extern void func_0028FDD0(void);
extern void GetOrInit_460D58_2B6528(void);
extern void func_002EFA60(void);
extern void GetOrInitGlobal7863C8_300148(void);
extern void SetField_0_4_8_31EEA8(void *a, void *b, void *c);

__attribute__((section(".text.GetSingleton785978_17C450")))
int *GetSingleton785978_17C450(void) {
    if (D_00785978 == 0) {
        GetOrInitGlobal785878_1B8058();
        SetField_0_4_8_31EEA8(&D_00785978, &D_00421C68, &D_00785878);
    }
    return &D_00785978;
}

__attribute__((section(".text.GetSingleton785A98_1832F0")))
int *GetSingleton785A98_1832F0(void) {
    if (D_00785A98 == 0) {
        GetOrInitGlobal785878_1B8058();
        SetField_0_4_8_31EEA8(&D_00785A98, &D_00422B30, &D_00785878);
    }
    return &D_00785A98;
}

__attribute__((section(".text.GetSingleton785F58_1A4298")))
int *GetSingleton785F58_1A4298(void) {
    if (D_00785F58 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_00785F58, &D_00427218, &D_00785798);
    }
    return &D_00785F58;
}

__attribute__((section(".text.GetSingleton785F98_1A7738")))
int *GetSingleton785F98_1A7738(void) {
    if (D_00785F98 == 0) {
        GetOrInitGlobal785878_1B8058();
        SetField_0_4_8_31EEA8(&D_00785F98, &D_00427580, &D_00785878);
    }
    return &D_00785F98;
}

__attribute__((section(".text.GetSingleton785FE8_1A9638")))
int *GetSingleton785FE8_1A9638(void) {
    if (D_00785FE8 == 0) {
        GetOrInitGlobal785878_1B8058();
        SetField_0_4_8_31EEA8(&D_00785FE8, &D_00427B08, &D_00785878);
    }
    return &D_00785FE8;
}

__attribute__((section(".text.GetSingleton786098_1B3680")))
int *GetSingleton786098_1B3680(void) {
    if (D_00786098 == 0) {
        GetOrInitGlobal785878_1B8058();
        SetField_0_4_8_31EEA8(&D_00786098, &D_00428638, &D_00785878);
    }
    return &D_00786098;
}

__attribute__((section(".text.GetSingleton786248_27DD38")))
int *GetSingleton786248_27DD38(void) {
    if (D_00786248 == 0) {
        func_0028FDD0();
        SetField_0_4_8_31EEA8(&D_00786248, &D_00448298, &D_007861D8);
    }
    return &D_00786248;
}

__attribute__((section(".text.GetSingleton7863E8_2E6318")))
int *GetSingleton7863E8_2E6318(void) {
    if (D_007863E8 == 0) {
        func_002EFA60();
        SetField_0_4_8_31EEA8(&D_007863E8, &D_0044E398, &D_007863F8);
    }
    return &D_007863E8;
}

__attribute__((section(".text.GetSingleton7864C8_2F3DC0")))
int *GetSingleton7864C8_2F3DC0(void) {
    if (D_007864C8 == 0) {
        GetOrInitGlobal7863C8_300148();
        SetField_0_4_8_31EEA8(&D_007864C8, &D_0044F030, &D_007863C8);
    }
    return &D_007864C8;
}

__attribute__((section(".text.GetSingleton786508_2F5358")))
int *GetSingleton786508_2F5358(void) {
    if (D_00786508 == 0) {
        GetOrInitGlobal7863C8_300148();
        SetField_0_4_8_31EEA8(&D_00786508, &D_0044F398, &D_007863C8);
    }
    return &D_00786508;
}

__attribute__((section(".text.GetSingleton786558_2F7090")))
int *GetSingleton786558_2F7090(void) {
    if (D_00786558 == 0) {
        GetOrInitGlobal7863C8_300148();
        SetField_0_4_8_31EEA8(&D_00786558, &D_0044F6C0, &D_007863C8);
    }
    return &D_00786558;
}

__attribute__((section(".text.GetSingleton786578_2F9CE0")))
int *GetSingleton786578_2F9CE0(void) {
    if (D_00786578 == 0) {
        func_002EFA60();
        SetField_0_4_8_31EEA8(&D_00786578, &D_0044F868, &D_007863F8);
    }
    return &D_00786578;
}

__attribute__((section(".text.GetSingleton786598_3000F8")))
int *GetSingleton786598_3000F8(void) {
    if (D_00786598 == 0) {
        GetOrInit_460D58_2B6528();
        SetField_0_4_8_31EEA8(&D_00786598, &D_0044FBA8, &D_00460D58);
    }
    return &D_00786598;
}

__attribute__((section(".text.GetSingletonD007865A8_304E38")))
int *GetSingletonD007865A8_304E38(void) {
    if (D_007865A8 == 0) {
        GetOrInit_460D58_2B6528();
        SetField_0_4_8_31EEA8(&D_007865A8, &D_0044FDB8, &D_00460D58);
    }
    return &D_007865A8;
}

/* moved from src/cod/002810.c (cygnus catch-all): this is an sq-prologue
 * singleton getter and needs the SN pin. */
__attribute__((section(".text.GetClassDescB_2815E8")))
int *GetClassDescB_2815E8(void) {
    if (D_00786268 == 0) {
        func_0028FDD0();
        SetField_0_4_8_31EEA8(&D_00786268, &D_00448688, &D_007861D8);
    }
    return &D_00786268;
}

__attribute__((section(".text.GetSingletonD00786618_318788")))
int *GetSingletonD00786618_318788(void) {
    if (D_00786618 == 0) {
        cObjBase__tf();
        SetField_0_4_8_31EEA8(&D_00786618, &D_00450CA8, &D_007854F8);
    }
    return &D_00786618;
}

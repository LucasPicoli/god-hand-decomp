/* sn-2.95.3-136 matched TU. */

extern int D_00786198;
extern int D_00786188;
extern void *GetOrInit_460D40_1F7C88(void);
extern void SetField_0_4_8_31EEA8(void *a, void *b, void *c);
extern int D_0042C300;
extern int D_00460D40;
extern int D_0042C308;
extern int D_00786458;
extern int D_007863F8;
extern void *GetOrInitGlobal7863C8_300148(void);
extern int D_0044E9F8;
extern int D_007863C8;
extern int D_0044EA08;
extern int D_007865C8;
extern int D_007865A8;
extern void *GetOrInit_460D58_2B6528(void);
extern int D_0044FDB8;
extern int D_00460D58;
extern int D_0044FDD8;
extern int D_007865D8;
extern int D_0044FDE8;

__attribute__((section(".text.func_003A9260")))
int func_003A9260(char *s1, char *s2) {
    while (*s1) {
        int c1 = func_003AD0F8(*s1);
        int c2 = func_003AD0F8(*s2);
        if (c1 != c2) break;
        s1++;
        s2++;
    }
    return func_003AD0F8((unsigned char)*s1) - func_003AD0F8((unsigned char)*s2);
}

__attribute__((section(".text.func_001F7BD8")))
void *func_001F7BD8(void) {
    if (D_00786198 == 0) {
        if (D_00786188 == 0) {
            GetOrInit_460D40_1F7C88();
            SetField_0_4_8_31EEA8(&D_00786188, &D_0042C300, &D_00460D40);
        }
        SetField_0_4_8_31EEA8(&D_00786198, &D_0042C308, &D_00786188);
    }
    return &D_00786198;
}

__attribute__((section(".text.func_002EFAB8")))
void *func_002EFAB8(void) {
    if (D_00786458 == 0) {
        if (D_007863F8 == 0) {
            GetOrInitGlobal7863C8_300148();
            SetField_0_4_8_31EEA8(&D_007863F8, &D_0044E9F8, &D_007863C8);
        }
        SetField_0_4_8_31EEA8(&D_00786458, &D_0044EA08, &D_007863F8);
    }
    return &D_00786458;
}

__attribute__((section(".text.func_00305148")))
void *func_00305148(void) {
    if (D_007865C8 == 0) {
        if (D_007865A8 == 0) {
            GetOrInit_460D58_2B6528();
            SetField_0_4_8_31EEA8(&D_007865A8, &D_0044FDB8, &D_00460D58);
        }
        SetField_0_4_8_31EEA8(&D_007865C8, &D_0044FDD8, &D_007865A8);
    }
    return &D_007865C8;
}

__attribute__((section(".text.func_00305200")))
void *func_00305200(void) {
    if (D_007865D8 == 0) {
        if (D_007865A8 == 0) {
            GetOrInit_460D58_2B6528();
            SetField_0_4_8_31EEA8(&D_007865A8, &D_0044FDB8, &D_00460D58);
        }
        SetField_0_4_8_31EEA8(&D_007865D8, &D_0044FDE8, &D_007865A8);
    }
    return &D_007865D8;
}

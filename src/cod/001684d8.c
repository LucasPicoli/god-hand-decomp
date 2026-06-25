/* sn-2.95.3-136 matched TU. */

extern int D_00785758;
extern int D_0041FCA0;
extern int D_00460D38;
extern int D_00785768;
extern int D_0041FE38;
extern int D_00785778;
extern int D_0041FF70;
extern int D_00785788;
extern int D_00420140;
extern int D_00785798;
extern int D_007857A8;
extern int D_00420228;
extern int D_00785888;
extern int D_00420E18;
extern int D_00785858;

void GetOrInit_00460D38_161628(void);
void SetField_0_4_8_31EEA8(int *, int *, int *);

__attribute__((section(".text.func_001684D8")))
int *func_001684D8(void) {
    int *s0 = &D_00785758;
    if (!*s0) {
        GetOrInit_00460D38_161628();
        SetField_0_4_8_31EEA8(s0, &D_0041FCA0, &D_00460D38);
    }
    return s0;
}

void GetOrInit_00460D38_161628(void);
void SetField_0_4_8_31EEA8(int *, int *, int *);

__attribute__((section(".text.func_0016C1E8")))
int *func_0016C1E8(void) {
    int *s0 = &D_00785768;
    if (!*s0) {
        GetOrInit_00460D38_161628();
        SetField_0_4_8_31EEA8(s0, &D_0041FE38, &D_00460D38);
    }
    return s0;
}

void GetOrInit_00460D38_161628(void);
void SetField_0_4_8_31EEA8(int *, int *, int *);

__attribute__((section(".text.func_0016F350")))
int *func_0016F350(void) {
    int *s0 = &D_00785778;
    if (!*s0) {
        GetOrInit_00460D38_161628();
        SetField_0_4_8_31EEA8(s0, &D_0041FF70, &D_00460D38);
    }
    return s0;
}

void GetOrInitGlobal785798_1C3BE8(void);
void SetField_0_4_8_31EEA8(int *, int *, int *);

__attribute__((section(".text.func_0016F648")))
int *func_0016F648(void) {
    int *s0 = &D_00785788;
    if (!*s0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(s0, &D_00420140, &D_00785798);
    }
    return s0;
}

void GetOrInitGlobal785798_1C3BE8(void);
void SetField_0_4_8_31EEA8(int *, int *, int *);

__attribute__((section(".text.func_0016F938")))
int *func_0016F938(void) {
    int *s0 = &D_007857A8;
    if (!*s0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(s0, &D_00420228, &D_00785798);
    }
    return s0;
}

void GetPilotClassDesc_1BDE00(void);
void SetField_0_4_8_31EEA8(int *, int *, int *);

__attribute__((section(".text.func_00171C40")))
int *func_00171C40(void) {
    int *s0 = &D_00785888;
    if (!*s0) {
        GetPilotClassDesc_1BDE00();
        SetField_0_4_8_31EEA8(s0, &D_00420E18, &D_00785858);
    }
    return s0;
}

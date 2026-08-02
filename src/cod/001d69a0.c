/* sn-2.95.3-136 matched TU. */

extern void SetFlagOnEntries7C_1D51B8(void *a, int b, void *c);
extern char D_00447B90[];
extern char D_00447B98[];
extern void Obj0000_Set_Field_424_1595E8(void *a, int b);
extern void *SearchData(void *a, void *b, int c);
extern int cModel_setupModel(void *a, void *b, void *c, int d, int e);
extern char D_00447D38[];
extern char D_00447D40[];
extern char D_00447E58[];
extern char D_00447E60[];
extern char D_00448180[];
extern char D_00448188[];
extern char D_004482C8[];
extern char D_004482D0[];
extern char D_00448588[];
extern char D_00448590[];

__attribute__((section(".text.func_001D69A0")))
void func_001D69A0(void *a0, void *a1) {
    SetFlagOnEntries7C_1D51B8(a0, 0x1C, a1);
    SetFlagOnEntries7C_1D51B8(a0, 0x1D, a1);
}

__attribute__((section(".text.func_001D69E8")))
void func_001D69E8(void *a0, void *a1) {
    SetFlagOnEntries7C_1D51B8(a0, 0x1A, a1);
    SetFlagOnEntries7C_1D51B8(a0, 0x1B, a1);
}

__attribute__((section(".text.func_001D6BE0")))
void func_001D6BE0(void *a0, void *a1) {
    SetFlagOnEntries7C_1D51B8(a0, 0x29, a1);
    SetFlagOnEntries7C_1D51B8(a0, 0x2A, a1);
}

__attribute__((section(".text.func_001D6C28")))
void func_001D6C28(void *a0, void *a1) {
    SetFlagOnEntries7C_1D51B8(a0, 0x2B, a1);
    SetFlagOnEntries7C_1D51B8(a0, 0x2C, a1);
}

__attribute__((section(".text.func_001D6C90")))
void func_001D6C90(void *a0, void *a1) {
    SetFlagOnEntries7C_1D51B8(a0, 0x25, a1);
    SetFlagOnEntries7C_1D51B8(a0, 0x26, a1);
}

__attribute__((section(".text.func_001D6CD8")))
void func_001D6CD8(void *a0, void *a1) {
    SetFlagOnEntries7C_1D51B8(a0, 0x27, a1);
    SetFlagOnEntries7C_1D51B8(a0, 0x28, a1);
}

__attribute__((section(".text.func_00277F80")))
int func_00277F80(char *a0) {
    void *m1;
    void *m2;
    Obj0000_Set_Field_424_1595E8(a0, 0);
    m1 = SearchData(*(void **)(a0 + 0x304), &D_00447B90, 0);
    m2 = SearchData(*(void **)(a0 + 0x304), &D_00447B98, 0);
    if (m2 != 0) {
        return cModel_setupModel(a0, m1, m2, 0, 0);
    }
    return 0;
}

__attribute__((section(".text.func_00279938")))
int func_00279938(char *a0) {
    void *m1;
    void *m2;
    Obj0000_Set_Field_424_1595E8(a0, 0);
    m1 = SearchData(*(void **)(a0 + 0x304), &D_00447D38, 0);
    m2 = SearchData(*(void **)(a0 + 0x304), &D_00447D40, 0);
    if (m2 != 0) {
        return cModel_setupModel(a0, m1, m2, 0, 0);
    }
    return 0;
}

__attribute__((section(".text.func_00279F68")))
int func_00279F68(char *a0) {
    void *m1;
    void *m2;
    Obj0000_Set_Field_424_1595E8(a0, 0);
    m1 = SearchData(*(void **)(a0 + 0x304), &D_00447E58, 0);
    m2 = SearchData(*(void **)(a0 + 0x304), &D_00447E60, 0);
    if (m2 != 0) {
        return cModel_setupModel(a0, m1, m2, 0, 0);
    }
    return 0;
}

__attribute__((section(".text.func_0027D150")))
int func_0027D150(char *a0) {
    void *m1;
    void *m2;
    Obj0000_Set_Field_424_1595E8(a0, 0);
    m1 = SearchData(*(void **)(a0 + 0x304), &D_00448180, 0);
    m2 = SearchData(*(void **)(a0 + 0x304), &D_00448188, 0);
    if (m2 != 0) {
        return cModel_setupModel(a0, m1, m2, 0, 0);
    }
    return 0;
}

__attribute__((section(".text.func_0027E638")))
int func_0027E638(char *a0) {
    void *m1;
    void *m2;
    Obj0000_Set_Field_424_1595E8(a0, 0);
    m1 = SearchData(*(void **)(a0 + 0x304), &D_004482C8, 0);
    m2 = SearchData(*(void **)(a0 + 0x304), &D_004482D0, 0);
    if (m2 != 0) {
        return cModel_setupModel(a0, m1, m2, 0, 0);
    }
    return 0;
}

__attribute__((section(".text.func_00280B60")))
int func_00280B60(char *a0) {
    void *m1;
    void *m2;
    Obj0000_Set_Field_424_1595E8(a0, 0);
    m1 = SearchData(*(void **)(a0 + 0x304), &D_00448588, 0);
    m2 = SearchData(*(void **)(a0 + 0x304), &D_00448590, 0);
    if (m2 != 0) {
        return cModel_setupModel(a0, m1, m2, 0, 0);
    }
    return 0;
}

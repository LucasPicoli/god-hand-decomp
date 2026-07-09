/* cygnus-2.96 matched TU. */

extern void func_0034E268(void *a0);
extern void UpdateObj0000Fields_34F6C0(void *a0);
extern void func_00346968(void *a0, int *a1, int *a2);
extern void func_00347A40(void *a0);
extern void func_00358FF8(int *a0);
extern int Obj34D8_SetGlobalEE0B8_IfField48(int *a0);
extern int GetArrayElemA0C_35A1C8(int *a0, int a1);

/* MATCH via cygnus-2.96 +drop-freorder. */




__attribute__((section(".text.func_0034E1F0")))
int func_0034E1F0(char *a0) {
    int r;
    if (func_0034F418(a0) == 1)
        return 0;
    func_0034E268(a0);
    r = func_0034E2C8(a0);
    if (*(int *)(a0 + 0x48) == 2)
        UpdateObj0000Fields_34F6C0(a0);
    return r;
}

/* MATCH via cygnus-2.96 +drop-freorder. */


__attribute__((section(".text.func_00348158")))
void func_00348158(char *a0) {
    int local0, local1;
    func_00346968(a0, &local0, &local1);
    if (local0 / local1 < *(int *)(a0 + 0x2FC) / 1000)
        return;
    if (*(int *)(a0 + 0x2E8) != 2)
        return;
    func_00347A40(a0);
    *(int *)(a0 + 0x2E8) = 3;
}

/* MATCH via cygnus-2.96 +drop-freorder. */






__attribute__((section(".text.func_00357ED8")))
int func_00357ED8(int *a0)
{
    if (func_00357F58(a0) != 0 ||
        func_00357FC8(a0) != 0 ||
        func_00358090(a0) != 0 ||
        func_003580E8(a0) != 0 ||
        a0[0x18] != 0) {
        return func_003581E0(a0);
    }
    return 0;
}

/* MATCH via cygnus-2.96 +drop-freorder. */



__attribute__((section(".text.func_003581E0")))
int func_003581E0(int *a0)
{
    int v0 = func_00358A48(a0);
    if (v0 != 0) return v0;
    a0[0x13] = 6;
    func_00358FF8(a0);
    return 0;
}

/* MATCH via cygnus-2.96 +drop-freorder. */






__attribute__((section(".text.func_003588B0")))
int func_003588B0(int *a0)
{
    int r;
    if (Obj34D8_SetGlobalEE0B8_IfField48(a0) != 0)
        return func_0034DD70(0, 0xFF000132);
    if (GetArrayElemA0C_35A1C8(a0, 0x2F) == 1)
        r = func_00357140(a0);
    else
        r = func_00358930(a0);
    a0[0x11] = 1;
    return r;
}

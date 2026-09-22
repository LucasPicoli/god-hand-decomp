/* sn-2.95.3-136 matched TU. */

extern int SearchData(int a0, void *a1, int a2);
extern void cModel_setTextureExchange(void *a0, int a1, int a2, int a3);
extern int D_00428A18;
extern void func_003A52F0(void *a0, int a1, int a2);
extern void func_002CD740(void *);
extern void func_002B43B0(void *);
extern void func_002B45E8(void *);
extern char *D_003C23A4;
extern int cDamageManage_ReleaseDamageGive(void *a, void *b);
extern void Tramp_00312708_1B79B0(void *a0);
extern int D_00574380;
extern void func_003870E0(int);

/* cOmBase_setTexChange — sn-2.95.3-136 */



__attribute__((section(".text.cOmBase_setTexChange")))
void cOmBase_setTexChange(char *a0, int a1) {
    *(int *)(a0 + 0x254) |= 0x10000000;
    cModel_setTextureExchange(a0, *(int *)(a0 + 0x284),
        SearchData(*(int *)(a0 + 0x304), &D_00428A18, 0), a1);
}

/* func_002CD668 — sn-2.95.3-136 */


__attribute__((section(".text.func_002CD668")))
void func_002CD668(char *a0, int a1, int a2) {
    *(char **)(a0 + 0x380) = a0;
    func_003A52F0(a0, 0, 0x380);
    *(int *)(a0 + 0x384) = a2;
    func_002CD740(a0);
    *(char **)(a0 + 0x38C) = a0;
    *(int *)(a0 + 0x388) = 0;
    *(int *)(*(char **)(a0 + 0x380) + 0x10) = a1;
}

/* func_002B3B70 — sn-2.95.3-136 */





__attribute__((section(".text.func_002B3B70")))
int func_002B3B70(char *a0) {
    if (func_002AEF90(D_003C23A4) == 0 ||
        func_002B45F8(a0, *(int *)(a0 + 0x8C), 0x8000) == 0)
        func_002B43B0(a0);
    func_002B45E8(a0);
    *(char *)(a0 + 0xC) = 6;
    *(char *)(a0 + 0xD) = 0;
    *(char *)(a0 + 0xE) = 0;
    *(char *)(a0 + 0xF) = 0;
    return 2;
}

/* func_001C8DD8 — sn-2.95.3-136 */
struct VtEnt { short delta; short index; void *pfn; };



__attribute__((section(".text.func_001C8DD8")))
void func_001C8DD8(char *a0) {
    struct VtEnt *vt;
    if (*(int *)(a0 + 0x600) != 0) {
        if (cDamageManage_ReleaseDamageGive(&D_00574380, *(void **)(a0 + 0x600)) != 0) {
            *(int *)(a0 + 0x600) = 0;
            *(int *)(a0 + 0x604) = -1;
        }
    }
    if (*(unsigned char *)(a0 + 0x640) != 0) {
        Tramp_00312708_1B79B0(a0);
        return;
    }
    vt = *(struct VtEnt **)(a0 + 0x214);
    ((void (*)(void *))vt[20].pfn)(a0 + vt[20].delta);
}

/* func_0037A5F0 — sn-2.95.3-136 */



__attribute__((section(".text.func_0037A5F0")))
void func_0037A5F0(char *a0) {
    char *p = a0 + 0xCC;
    int r;
    if (func_00387430(0) != 0) return;
    if (*(int *)(p + 0x40) == 2 && *(signed char *)(p + 0x7) == 0x2F) return;
    r = func_00386FA0(0, p);
    *(int *)(a0 + 0xC) = r;
    if (r == 0) return;
    func_003870E0(0);
}

/* sn-2.95.3-136 matched TU. */

extern void func_00143A90(void *);
extern char *D_003BD6E8;
extern void UnlinkAndCoalesceNode_2A9680(void *a0, void *a1);
extern void __builtin_delete(void *a0);
extern void func_00375050(void *, int);
extern void func_002CE3E8(void *);
extern void func_002B22E0(void *, int);
extern int cCoreSave_getCostumeNo(void *a0);
extern int D_00569B70;

/* func_001DBCF8 — sn-2.95.3-136 */


__attribute__((section(".text.func_001DBCF8")))
void func_001DBCF8(char *a0) {
    if (*(unsigned char *)(a0 + 0x3025) != 0) return;
    func_00143A90(D_003BD6E8 + 0x1AE0);
    *(int *)(a0 + 0x3020) |= 1;
    *(unsigned char *)(a0 + 0x3025) = *(unsigned char *)(a0 + 0x3025) + 1;
}

/* func_003128B0 — sn-2.95.3-136 */


__attribute__((section(".text.func_003128B0")))
void func_003128B0(char *a0) {
    char *n = *(char **)a0;
    if (n != 0) {
        char *q = *(char **)(n + 0x4);
        if (q != 0) UnlinkAndCoalesceNode_2A9680(*(void **)(q - 0x20), q);
        __builtin_delete(n);
    }
    *(int *)a0 = 0;
}

/* func_002CE430 — sn-2.95.3-136 */



__attribute__((section(".text.func_002CE430")))
void func_002CE430(char *a0) {
    if (func_002CDA38(a0) == 0) return;
    if ((*(int *)(a0 + 0xC) & 1) != 0)
        func_00375050(*(void **)(a0 + 0x14), 0);
    else
        func_002CE3E8(a0);
}

/* cModel_setMeshDisplay — sn-2.95.3-136 */

__attribute__((section(".text.cModel_setMeshDisplay")))
int cModel_setMeshDisplay(void *a0, int a1, int flag) {
    char *m = func_0014B730(a0, a1);
    if (m == 0) return 0;
    if (flag != 0) *(int *)(m + 0x380) &= 0xFFFFFFFE;
    else *(int *)(m + 0x380) |= 1;
    return 1;
}

/* func_002B2A88 — sn-2.95.3-136 */


__attribute__((section(".text.func_002B2A88")))
void func_002B2A88(char *a0) {
    char *t;
    func_002B22E0(a0, func_002B4690(a0, *(int *)(a0 + 0x8C) + 2));
    *(char *)(a0 + 0x3C) = 0;
    t = *(char **)(a0 + 0x18);
    if (t != 0 && *(unsigned short *)(t + 0x2FE) == 0x102)
        *(char *)(a0 + 0xA4) = 1;
}

/* func_00298088 — sn-2.95.3-136 */


__attribute__((section(".text.func_00298088")))
void func_00298088(char *a0) {
    unsigned short k;
    int c;
    if (a0 == 0) return;
    k = *(unsigned short *)(a0 + 0x2FE);
    c = cCoreSave_getCostumeNo(&D_00569B70);
    if (k == 0x667 && c != 0)
        *(int *)(a0 + 0x250) |= 2;
}

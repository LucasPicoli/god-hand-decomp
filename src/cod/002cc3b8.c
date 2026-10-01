/* sn-2.95.3-136 matched TU. */

extern void cSeData_Init(void *a0);
extern void cBgmData_Init(void *a0);
extern void cSndSeVoice_Ctor(void *a0);
extern void cSndBgmNode_Ctor(void *a0);
extern char D_005FEE00[];
extern char D_005FEFF0[];
extern char D_005FFCF0[];
extern char D_005FFD80[];
extern char D_00601180[];

/* sn-2.95.3-136 matched TU. */













__attribute__((section(".text.cSnd_StaticInit")))
void cSnd_StaticInit(void *a0, int a1) {
    char *p;
    char *q;
    int i;
    int j;

    if (a1 != 0xFFFF) return;
    if (a0 == 0) return;

    func_002C9C88(D_005FEE00);

    p = D_005FEFF0;
    /* `i != -1` (retail materialises -1 and closes with `bne`), not `i >= 0`:
       the idiom picks the branch instruction. */
    for (i = 0x33; i != -1; i--) {
        cSeData_Init(p);
        p += 0x40;
    }

    q = D_005FFCF0;
    for (j = 1; j != -1; j--) {
        cBgmData_Init(q);
        q += 0x44;
    }

    q = D_005FFD80;
    for (j = 0x3F; j != -1; j--) {
        cSndSeVoice_Ctor(q);
        q += 0x50;
    }

    q = D_00601180;
    for (j = 0xF; j != -1; j--) {
        cSndBgmNode_Ctor(q);
        q += 0xDC;
    }
}

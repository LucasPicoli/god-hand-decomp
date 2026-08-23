/* sn-2.95.3-136 matched TU. */

extern unsigned char D_0044BAB0[];
extern void ForwardFieldNeg20_002A9680_30F5A0(void *a);
extern unsigned char D_0044D3C0[];
extern int cIDBase_initialize();
extern int D_00747A80;
extern int cGameObj_isClip();
extern int cIDBase_getIDWork(void *a, int b);
extern int D_00785548;
extern int D_00460D10;
extern int D_0041D830;
extern int D_0041D848;
extern void func_0031EEC8(void *a, void *b);
extern void SetField_0_4_8_31EEA8(void *a, void *b, void *c);

/* LANE K3, wave 18 -- DEAD-HEAD boundary class.
 * declared symbol : func_002BAE68
 * TRUE ENTRY      : 0x002BAE68
 * head bytes      : 8 (dead words in front of the true entry)
 * compiler        : sn-2.95.3-136
 * extra keys      : none
 * symbol_addrs    : func_002BAE68 = 0x002BAE68; // type:func
 *
 * Byte-exact over the TRUE span only.  score_candidate compares the
 * DECLARED span and reports a clean length miss of 2 words.
 * Land it after the boundary moves.
 */



__attribute__((section(".text.func_002BAE68")))
void func_002BAE68(void *a0, int a1) {
    *(unsigned char **)((char *)a0 + 0x18) = D_0044BAB0;
    if (a1 & 1) {
        ForwardFieldNeg20_002A9680_30F5A0(a0);
    }
}

/* LANE K3, wave 18 -- DEAD-HEAD boundary class.
 * declared symbol : func_002D9F30
 * TRUE ENTRY      : 0x002D9F30
 * head bytes      : 8 (dead words in front of the true entry)
 * compiler        : sn-2.95.3-136
 * extra keys      : none
 * symbol_addrs    : func_002D9F30 = 0x002D9F30; // type:func
 *
 * Byte-exact over the TRUE span only.  score_candidate compares the
 * DECLARED span and reports a clean length miss of 2 words.
 * Land it after the boundary moves.
 */



__attribute__((section(".text.func_002D9F30")))
void func_002D9F30(void *a0, int a1) {
    *(unsigned char **)((char *)a0 + 0x0) = D_0044D3C0;
    if (a1 & 1) {
        ForwardFieldNeg20_002A9680_30F5A0(a0);
    }
}

/* LANE K3, wave 18 -- DEAD-HEAD boundary class.
 * declared symbol : func_0013F118
 * TRUE ENTRY      : 0x0013F118
 * head bytes      : 8 (dead words in front of the true entry)
 * compiler        : sn-2.95.3-136
 * extra keys      : none
 * symbol_addrs    : func_0013F118 = 0x0013F118; // type:func
 *
 * Byte-exact over the TRUE span only.  score_candidate compares the
 * DECLARED span and reports a clean length miss of 2 words.
 * Land it after the boundary moves.
 */


__attribute__((section(".text.func_0013F118")))
void func_0013F118(void *a0) {
    cIDBase_initialize(a0, 1, 0x11);
    *(int *)((char *)a0 + 0x9C) = 0xFFFF;
}

/* LANE K3, wave 18 -- DEAD-HEAD boundary class.
 * declared symbol : func_00143558
 * TRUE ENTRY      : 0x00143558
 * head bytes      : 8 (dead words in front of the true entry)
 * compiler        : sn-2.95.3-136
 * extra keys      : none
 * symbol_addrs    : func_00143558 = 0x00143558; // type:func
 *
 * Byte-exact over the TRUE span only.  score_candidate compares the
 * DECLARED span and reports a clean length miss of 2 words.
 * Land it after the boundary moves.
 */


__attribute__((section(".text.func_00143558")))
void func_00143558(void *a0) {
    cIDBase_initialize(a0, 1, 0x13);
    cIDBase_initialize((char *)a0 + 0xB0, 1, 0x18);
}

/* LANE K3, wave 18 -- DEAD-HEAD boundary class.
 * declared symbol : func_001B80C0
 * TRUE ENTRY      : 0x001B80C0
 * head bytes      : 16 (dead words in front of the true entry)
 * compiler        : sn-2.95.3-136
 * extra keys      : none
 * symbol_addrs    : func_001B80C0 = 0x001B80C0; // type:func
 *
 * Byte-exact over the TRUE span only.  score_candidate compares the
 * DECLARED span and reports a clean length miss of 4 words.
 * Land it after the boundary moves.
 */



__attribute__((section(".text.func_001B80C0")))
int func_001B80C0(void *a0) {
    if (D_00747A80 & 0x20000000) {
        return 1;
    }
    return cGameObj_isClip(a0) != 0;
}

/* LANE K3, wave 18 -- DEAD-HEAD boundary class.
 * declared symbol : func_0013D048
 * TRUE ENTRY      : 0x0013D048
 * head bytes      : 24 (dead words in front of the true entry)
 * compiler        : sn-2.95.3-136
 * extra keys      : none
 * symbol_addrs    : func_0013D048 = 0x0013D048; // type:func
 *
 * Byte-exact over the TRUE span only.  score_candidate compares the
 * DECLARED span and reports a clean length miss of 6 words.
 * Land it after the boundary moves.
 */


__attribute__((section(".text.func_0013D048")))
void func_0013D048(void *a0) {
    cIDBase_initialize(a0, 1, 6);
    cIDBase_initialize((char *)a0 + 0x140, 1, 7);
    cIDBase_initialize((char *)a0 + 0x190, 1, 8);
    cIDBase_initialize((char *)a0 + 0xA0, 1, 0x1B);
    cIDBase_initialize((char *)a0 + 0xF0, 1, 0x1C);
}

/* LANE K3, wave 18 -- DEAD-HEAD boundary class.
 * declared symbol : func_0013C220
 * TRUE ENTRY      : 0x0013C220
 * head bytes      : 8 (dead words in front of the true entry)
 * compiler        : sn-2.95.3-136
 * extra keys      : none
 * symbol_addrs    : func_0013C220 = 0x0013C220; // type:func
 *
 * Byte-exact over the TRUE span only.  score_candidate compares the
 * DECLARED span and reports a clean length miss of 2 words.
 * Land it after the boundary moves.
 */



__attribute__((section(".text.func_0013C220")))
void func_0013C220(void *a0) {
    int *tbl;
    unsigned short i;
    tbl = (int *)((char *)a0 + 0x98);
    *(int *)((char *)a0 + 0x90) = 0;
    cIDBase_initialize(a0, 1, 0xA);
    i = 0;
    do {
        *(int *)((char *)tbl + (i << 2)) = cIDBase_getIDWork(a0, i);
        i = i + 1;
    } while (i < 4);
}

/* LANE K3, wave 18 -- DEAD-HEAD boundary class.
 * declared symbol : func_001342B8
 * TRUE ENTRY      : 0x001342B8
 * head bytes      : 8 (dead words in front of the true entry)
 * compiler        : sn-2.95.3-136
 * extra keys      : none
 * symbol_addrs    : func_001342B8 = 0x001342B8; // type:func
 *
 * Byte-exact over the TRUE span only.  score_candidate compares the
 * DECLARED span and reports a clean length miss of 2 words.
 * Land it after the boundary moves.
 */







__attribute__((section(".text.func_001342B8")))
int *func_001342B8(void) {
    if (D_00785548 == 0) {
        if (D_00460D10 == 0) {
            func_0031EEC8(&D_00460D10, &D_0041D830);
        }
        SetField_0_4_8_31EEA8(&D_00785548, &D_0041D848, &D_00460D10);
    }
    return &D_00785548;
}

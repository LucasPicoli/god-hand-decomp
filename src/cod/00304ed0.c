/* sn-2.95.3-136 matched TU. */

extern int D_007865B8;
extern int D_007865A8;
extern int D_0044FDB8;
extern int D_0044FDC8;
extern int D_00460D58;
extern void GetOrInit_460D58_2B6528(void);
extern void SetField_0_4_8_31EEA8(void *a, void *b, void *c);

/* LANE K3, wave 18 -- DEAD-HEAD boundary class.
 * declared symbol : func_00304ED0
 * TRUE ENTRY      : 0x00304ED0
 * head bytes      : 72 (dead words in front of the true entry)
 * compiler        : sn-2.95.3-136
 * extra keys      : none
 * symbol_addrs    : func_00304ED0 = 0x00304ED0; // type:func
 *
 * Byte-exact over the TRUE span only.  score_candidate compares the
 * DECLARED span and reports a clean length miss of 18 words.
 * Land it after the boundary moves.
 */








__attribute__((section(".text.func_00304ED0")))
int *func_00304ED0(void) {
    if (D_007865B8 == 0) {
        if (D_007865A8 == 0) {
            GetOrInit_460D58_2B6528();
            SetField_0_4_8_31EEA8(&D_007865A8, &D_0044FDB8, &D_00460D58);
        }
        SetField_0_4_8_31EEA8(&D_007865B8, &D_0044FDC8, &D_007865A8);
    }
    return &D_007865B8;
}

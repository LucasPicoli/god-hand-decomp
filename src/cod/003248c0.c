/* cygnus-2.96 matched TU. */

extern void func_0033F130(void *a);
extern void func_0032EBD8(void);
extern void func_00330268(void);

/* LANE K3, wave 18 -- DEAD-HEAD boundary class.
 * declared symbol : Forward33F130_3248C0
 * TRUE ENTRY      : 0x003248C0
 * head bytes      : 16 (dead words in front of the true entry)
 * compiler        : cygnus-2.96
 * extra keys      : none
 * symbol_addrs    : Forward33F130_3248C0 = 0x003248C0; // type:func
 *
 * Byte-exact over the TRUE span only.  score_candidate compares the
 * DECLARED span and reports a clean length miss of 4 words.
 * Land it after the boundary moves.
 */


__attribute__((section(".text.Forward33F130_3248C0")))
void Forward33F130_3248C0(void *a0, void *a1) {
    func_0033F130(a1);
}

/* LANE K3, wave 18 -- DEAD-HEAD boundary class.
 * declared symbol : func_0032D170
 * TRUE ENTRY      : 0x0032D170
 * head bytes      : 8 (dead words in front of the true entry)
 * compiler        : cygnus-2.96
 * extra keys      : none
 * symbol_addrs    : func_0032D170 = 0x0032D170; // type:func
 *
 * Byte-exact over the TRUE span only.  score_candidate compares the
 * DECLARED span and reports a clean length miss of 2 words.
 * Land it after the boundary moves.
 */



__attribute__((section(".text.func_0032D170")))
int func_0032D170(void) {
    func_0032EBD8();
    func_00330268();
    return 0;
}

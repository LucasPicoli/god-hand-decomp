/* sn-2.95.3-136 matched TU. */

extern void ClearFields_1614D0(void *a);
extern void func_00307140(int a, int b);

/* LANE K3, wave 18 -- DEAD-HEAD boundary class.
 * declared symbol : func_00161688
 * TRUE ENTRY      : 0x00161688
 * head bytes      : 32 (dead words in front of the true entry)
 * compiler        : sn-2.95.3-136
 * extra keys      : none
 * symbol_addrs    : func_00161688 = 0x00161688; // type:func
 *
 * Byte-exact over the TRUE span only.  score_candidate compares the
 * DECLARED span and reports a clean length miss of 8 words.
 * Land it after the boundary moves.
 */


__attribute__((section(".text.func_00161688")))
void func_00161688(void *a0) {
    ClearFields_1614D0(a0);
}

/* LANE K3, wave 18 -- DEAD-HEAD boundary class.
 * declared symbol : Forward307140_3071E8
 * TRUE ENTRY      : 0x003071E8
 * head bytes      : 8 (dead words in front of the true entry)
 * compiler        : sn-2.95.3-136
 * extra keys      : none
 * symbol_addrs    : Forward307140_3071E8 = 0x003071E8; // type:func
 *
 * Byte-exact over the TRUE span only.  score_candidate compares the
 * DECLARED span and reports a clean length miss of 2 words.
 * Land it after the boundary moves.
 */


__attribute__((section(".text.Forward307140_3071E8")))
void Forward307140_3071E8(void) {
    func_00307140(1, 0xFFFF);
}

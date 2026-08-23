/* sn-2.95.3-136 matched TU. */

extern void terminate(void) __attribute__((noreturn));

/* LANE K3, wave 18 -- DEAD-HEAD boundary class.
 * declared symbol : terminate
 * TRUE ENTRY      : 0x003211F8
 * head bytes      : 24 (dead words in front of the true entry)
 * compiler        : sn-2.95.3-136
 * extra keys      : none
 * symbol_addrs    : func_003211F8 = 0x003211F8; // type:func
 *
 * Byte-exact over the TRUE span only.  score_candidate compares the
 * DECLARED span and reports a clean length miss of 6 words.
 * Land it after the boundary moves.
 */


__attribute__((section(".text.func_003211F8")))
void func_003211F8(void) {
    terminate();
}

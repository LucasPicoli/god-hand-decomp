/* ee-2.9-991111 matched TU. */

/* LANE K3, wave 18 -- DEAD-HEAD boundary class.
 * declared symbol : func_003B6470
 * TRUE ENTRY      : 0x003B6470
 * head bytes      : 8 (dead words in front of the true entry)
 * compiler        : ee-2.9-991111
 * extra keys      : none
 * symbol_addrs    : func_003B6470 = 0x003B6470; // type:func
 *
 * Byte-exact over the TRUE span only.  score_candidate compares the
 * DECLARED span and reports a clean length miss of 2 words.
 * Land it after the boundary moves.
 */
__attribute__((section(".text.func_003B6470")))
int func_003B6470(int *a0, int *a1, unsigned int a2) {
    unsigned int n;
    unsigned int i;
    n = a2 >> 2;
    if (n != 0) {
        i = 0;
        do {
            *a0 = *a1;
            a1++;
            i++;
            a0++;
        } while (i < n);
    }
    return 0;
}

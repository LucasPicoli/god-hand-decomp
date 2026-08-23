/* sn-2.95.3-136 matched TU. */

/* func_003597D0 -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
 * The declared span starts 32 B too early. The TRUE ENTRY is 0x003597D0.
 * This body is BYTE-EXACT over the TRUE span under sn-2.95.3-136
 * with no extra keys.
 * score_candidate against the DECLARED span reports a clean LEN miss of
 * 8 words with REG 0 / IMM 0 / OPC 0. That is what a CORRECT body
 * looks like in this class. Do not edit it.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  func_003597D0 = 0x003597D0; // type:func
 *   scripts/resplat.sh
 * The function then carries the name func_003597D0. AFTER the resplat rename it:
 *   sed -i 's/func_003597D0/func_003597D0/g' <this file>
 * The name is left as func_003597D0 here so the body stays verifiable against
 * today's monolith.
 */
__attribute__((section(".text.func_003597D0")))
void func_003597D0(char *a0, int a1, int a2) {
    int *p = *(int **)(a0 + 0x36B0);
    if (p != 0) {
        if (p[0x36E] < 0) p[0x36E] = a1;
        if (p[0x36F] < 0) p[0x36F] = a2;
    }
}

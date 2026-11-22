/* sn-2.95.3-136 matched TU. */

/* SFSEE_FixAvPlay -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
 * The declared span starts 32 B too early. The TRUE ENTRY is 0x003597D0.
 * This body is BYTE-EXACT over the TRUE span under sn-2.95.3-136
 * with no extra keys.
 * score_candidate against the DECLARED span reports a clean LEN miss of
 * 8 words with REG 0 / IMM 0 / OPC 0. That is what a CORRECT body
 * looks like in this class. Do not edit it.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  SFSEE_FixAvPlay = 0x003597D0; // type:func
 *   scripts/resplat.sh
 * The function then carries the name SFSEE_FixAvPlay. AFTER the resplat rename it:
 *   sed -i 's/SFSEE_FixAvPlay/SFSEE_FixAvPlay/g' <this file>
 * The name is left as SFSEE_FixAvPlay here so the body stays verifiable against
 * today's monolith.
 */
__attribute__((section(".text.SFSEE_FixAvPlay")))
void SFSEE_FixAvPlay(char *a0, int a1, int a2) {
    int *p = *(int **)(a0 + 0x36B0);
    if (p != 0) {
        if (p[0x36E] < 0) p[0x36E] = a1;
        if (p[0x36F] < 0) p[0x36F] = a2;
    }
}

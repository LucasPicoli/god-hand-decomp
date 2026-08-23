/* sn-2.95.3-136 matched TU. */

extern char D_0044D1C8[];
extern void ForwardFieldNeg20_002A9680_30F5A0(void *a0);

/* func_002D5CA8 -- DEAD-HEAD BOUNDARY DEFECT.
 * The declared span starts 48 B too early; the TRUE entry is 0x002D5CA8.
 * This body is BYTE-EXACT over 0x002D5CA8..end under sn-2.95.3-136.
 * score_candidate against the DECLARED span reports a LEN miss of 12 words.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  func_002D5CA8 = 0x002D5CA8; // type:func
 *   scripts/resplat.sh
 * The function then carries the name func_002D5CA8. AFTER the resplat, rename it:
 *   sed -i 's/func_002D5CA8/func_002D5CA8/g' <this file>
 * The name is left as func_002D5CA8 here so the body stays verifiable against
 * today's monolith.
 */



__attribute__((section(".text.func_002D5CA8")))
void func_002D5CA8(void *a0, int a1) {
    *(char **)((char *)a0 + 0x30) = D_0044D1C8;
    if (a1 & 1) {
        ForwardFieldNeg20_002A9680_30F5A0(a0);
    }
}

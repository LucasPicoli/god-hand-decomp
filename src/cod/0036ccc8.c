/* sn-2.95.3-136 matched TU. */

extern void (*D_003F1FFC)(void);

/* func_0036CCC8 -- DEAD-HEAD BOUNDARY DEFECT.
 * The declared span starts 16 B too early; the TRUE entry is 0x0036CCC8.
 * This body is BYTE-EXACT over 0x0036CCC8..end under sn-2.95.3-136.
 * score_candidate against the DECLARED span reports a LEN miss of 4 words.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  func_0036CCC8 = 0x0036CCC8; // type:func
 *   scripts/resplat.sh
 * The function then carries the name func_0036CCC8. AFTER the resplat, rename it:
 *   sed -i 's/func_0036CCC8/func_0036CCC8/g' <this file>
 * The name is left as func_0036CCC8 here so the body stays verifiable against
 * today's monolith.
 */


__attribute__((section(".text.func_0036CCC8")))
void func_0036CCC8(void) {
    if (D_003F1FFC != 0) {
        D_003F1FFC();
    }
}

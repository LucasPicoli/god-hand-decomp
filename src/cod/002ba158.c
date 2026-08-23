/* sn-2.95.3-136 matched TU. */

extern void func_002B8990(int a1);

/* func_002BA158 -- DEAD-HEAD BOUNDARY DEFECT.
 * The declared span starts 24 B too early; the TRUE entry is 0x002BA158.
 * This body is BYTE-EXACT over 0x002BA158..end under sn-2.95.3-136.
 * score_candidate against the DECLARED span reports a LEN miss of 6 words.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  func_002BA158 = 0x002BA158; // type:func
 *   scripts/resplat.sh
 * The function then carries the name func_002BA158. AFTER the resplat, rename it:
 *   sed -i 's/func_002BA158/func_002BA158/g' <this file>
 * The name is left as func_002BA158 here so the body stays verifiable against
 * today's monolith.
 */


__attribute__((section(".text.func_002BA158")))
int func_002BA158(int a0, int a1) {
    func_002B8990(a1);
    return 1;
}

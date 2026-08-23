/* cygnus-2.96 matched TU. */

/* func_00348CB8 -- DEAD-HEAD BOUNDARY DEFECT.
 * The declared span starts 8 B too early; the TRUE entry is 0x00348CB8.
 * This body is BYTE-EXACT over 0x00348CB8..end under cygnus-2.96 + c_flags_drop -freorder-blocks.
 * score_candidate against the DECLARED span reports a LEN miss of 2 words.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  func_00348CB8 = 0x00348CB8; // type:func
 *   scripts/resplat.sh
 * The function then carries the name func_00348CB8. AFTER the resplat, rename it:
 *   sed -i 's/func_00348CB8/func_00348CB8/g' <this file>
 * The name is left as func_00348CB8 here so the body stays verifiable against
 * today's monolith.
 */


__attribute__((section(".text.func_00348CB8")))
int func_00348CB8(int *a0) {
    if (a0[0x18] == 1) {
        return func_00348CE0();
    }
    return 1;
}

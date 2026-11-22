/* cygnus-2.96 matched TU. */

/* MWSFSVR_CheckForceSvrBdr -- DEAD-HEAD BOUNDARY DEFECT.
 * The declared span starts 8 B too early; the TRUE entry is 0x00348CB8.
 * This body is BYTE-EXACT over 0x00348CB8..end under cygnus-2.96 + c_flags_drop -freorder-blocks.
 * score_candidate against the DECLARED span reports a LEN miss of 2 words.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  MWSFSVR_CheckForceSvrBdr = 0x00348CB8; // type:func
 *   scripts/resplat.sh
 * The function then carries the name MWSFSVR_CheckForceSvrBdr. AFTER the resplat, rename it:
 *   sed -i 's/MWSFSVR_CheckForceSvrBdr/MWSFSVR_CheckForceSvrBdr/g' <this file>
 * The name is left as MWSFSVR_CheckForceSvrBdr here so the body stays verifiable against
 * today's monolith.
 */


__attribute__((section(".text.MWSFSVR_CheckForceSvrBdr")))
int MWSFSVR_CheckForceSvrBdr(int *a0) {
    if (a0[0x18] == 1) {
        return mwsfsvr_ExecForceSvrBdr();
    }
    return 1;
}

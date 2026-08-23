/* cygnus-2.96 matched TU. */

/* Forward33F130_3292C0 -- DEAD-HEAD BOUNDARY DEFECT.
 * The declared span starts 16 B too early; the TRUE entry is 0x003292C0.
 * This body is BYTE-EXACT over 0x003292C0..end under cygnus-2.96.
 * score_candidate against the DECLARED span reports a LEN miss of 4 words.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  Forward33F130_3292C0 = 0x003292C0; // type:func
 *   scripts/resplat.sh
 * The function then carries the name Forward33F130_3292C0. AFTER the resplat, rename it:
 *   sed -i 's/Forward33F130_3292C0/Forward33F130_3292C0/g' <this file>
 * The name is left as Forward33F130_3292C0 here so the body stays verifiable against
 * today's monolith.
 */


__attribute__((section(".text.Forward33F130_3292C0")))
int Forward33F130_3292C0(int a0, int a1) { return func_0033F130(a1); }

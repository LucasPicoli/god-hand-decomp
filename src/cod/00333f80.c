/* cygnus-2.96 matched TU. */

/* Forward331CE0_333F80 -- DEAD-HEAD BOUNDARY DEFECT.
 * The declared span starts 8 B too early; the TRUE entry is 0x00333F80.
 * This body is BYTE-EXACT over 0x00333F80..end under cygnus-2.96.
 * score_candidate against the DECLARED span reports a LEN miss of 2 words.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  Forward331CE0_333F80 = 0x00333F80; // type:func
 *   scripts/resplat.sh
 * The function then carries the name Forward331CE0_333F80. AFTER the resplat, rename it:
 *   sed -i 's/Forward331CE0_333F80/Forward331CE0_333F80/g' <this file>
 * The name is left as Forward331CE0_333F80 here so the body stays verifiable against
 * today's monolith.
 */


__attribute__((section(".text.Forward331CE0_333F80")))
int Forward331CE0_333F80(void) { return func_00331CE0(); }

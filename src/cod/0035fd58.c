/* cygnus-2.96 matched TU. */

/* Forward36CC80_35FD58 -- DEAD-HEAD BOUNDARY DEFECT.
 * The declared span starts 8 B too early; the TRUE entry is 0x0035FD58.
 * This body is BYTE-EXACT over 0x0035FD58..end under cygnus-2.96.
 * score_candidate against the DECLARED span reports a LEN miss of 2 words.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  Forward36CC80_35FD58 = 0x0035FD58; // type:func
 *   scripts/resplat.sh
 * The function then carries the name Forward36CC80_35FD58. AFTER the resplat, rename it:
 *   sed -i 's/Forward36CC80_35FD58/Forward36CC80_35FD58/g' <this file>
 * The name is left as Forward36CC80_35FD58 here so the body stays verifiable against
 * today's monolith.
 */


__attribute__((section(".text.Forward36CC80_35FD58")))
int Forward36CC80_35FD58(int *a0) { return func_0036CC80(a0[0xC]); }

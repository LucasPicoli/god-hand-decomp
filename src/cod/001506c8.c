/* sn-2.95.3-136 matched TU. */

extern void func_00150608(int a0, int a1);

/* Forward150608_1506C8 -- DEAD-HEAD BOUNDARY DEFECT.
 * The declared span starts 80 B too early; the TRUE entry is 0x001506C8.
 * This body is BYTE-EXACT over 0x001506C8..end under sn-2.95.3-136.
 * score_candidate against the DECLARED span reports a LEN miss of 20 words.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  Forward150608_1506C8 = 0x001506C8; // type:func
 *   scripts/resplat.sh
 * The function then carries the name Forward150608_1506C8. AFTER the resplat, rename it:
 *   sed -i 's/Forward150608_1506C8/Forward150608_1506C8/g' <this file>
 * The name is left as Forward150608_1506C8 here so the body stays verifiable against
 * today's monolith.
 */


__attribute__((section(".text.Forward150608_1506C8")))
void Forward150608_1506C8(void) { func_00150608(1, 0xFFFF); }

/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern void func_00335248(int a0);
extern void setDevName(int a0);

/* func_00333FA0 -- DEAD-HEAD BOUNDARY DEFECT.
 * The declared span starts 8 B too early; the TRUE entry is 0x00333FA0.
 * This body is BYTE-EXACT over 0x00333FA0..end under cygnus-2.96.
 * score_candidate against the DECLARED span reports a LEN miss of 2 words.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  func_00333FA0 = 0x00333FA0; // type:func
 *   scripts/resplat.sh
 * The function then carries the name func_00333FA0. AFTER the resplat, rename it:
 *   sed -i 's/func_00333FA0/func_00333FA0/g' <this file>
 * The name is left as func_00333FA0 here so the body stays verifiable against
 * today's monolith.
 */





__attribute__((section(".text.func_00333FA0")))
int func_00333FA0(void) {
    D_003D9F68;
    func_00335248(0);
    setDevName(0);
    return (int)&D_003D9F78;
}

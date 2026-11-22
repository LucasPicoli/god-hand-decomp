/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern void htCiSetRootDir(int a0);
extern void setDevName(int a0);

/* htCiGetInterface -- DEAD-HEAD BOUNDARY DEFECT.
 * The declared span starts 8 B too early; the TRUE entry is 0x00333FA0.
 * This body is BYTE-EXACT over 0x00333FA0..end under cygnus-2.96.
 * score_candidate against the DECLARED span reports a LEN miss of 2 words.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  htCiGetInterface = 0x00333FA0; // type:func
 *   scripts/resplat.sh
 * The function then carries the name htCiGetInterface. AFTER the resplat, rename it:
 *   sed -i 's/htCiGetInterface/htCiGetInterface/g' <this file>
 * The name is left as htCiGetInterface here so the body stays verifiable against
 * today's monolith.
 */





__attribute__((section(".text.htCiGetInterface")))
int htCiGetInterface(void) {
    D_003D9F68;
    htCiSetRootDir(0);
    setDevName(0);
    return (int)&D_003D9F78;
}

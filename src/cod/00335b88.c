/* cygnus-2.96 matched TU. */

extern void func_00335CD8(void);
extern void LSC_SetFlowLimit(int a0, int a1);

/* func_00335B88 -- DEAD-HEAD BOUNDARY DEFECT.
 * The declared span starts 24 B too early; the TRUE entry is 0x00335B88.
 * This body is BYTE-EXACT over 0x00335B88..end under cygnus-2.96.
 * score_candidate against the DECLARED span reports a LEN miss of 6 words.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  func_00335B88 = 0x00335B88; // type:func
 *   scripts/resplat.sh
 * The function then carries the name func_00335B88. AFTER the resplat, rename it:
 *   sed -i 's/func_00335B88/func_00335B88/g' <this file>
 * The name is left as func_00335B88 here so the body stays verifiable against
 * today's monolith.
 */




__attribute__((section(".text.func_00335B88")))
int func_00335B88(int a0, int a1) {
    func_00335CD8();
    LSC_SetFlowLimit(a0, a1);
    return func_00335CE0();
}

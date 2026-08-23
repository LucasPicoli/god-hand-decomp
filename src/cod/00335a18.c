/* cygnus-2.96 matched TU. */

extern void func_00335CD8(void);
extern void func_00335A40(void);

/* func_00335A18 -- DEAD-HEAD BOUNDARY DEFECT.
 * The declared span starts 16 B too early; the TRUE entry is 0x00335A18.
 * This body is BYTE-EXACT over 0x00335A18..end under cygnus-2.96.
 * score_candidate against the DECLARED span reports a LEN miss of 4 words.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  func_00335A18 = 0x00335A18; // type:func
 *   scripts/resplat.sh
 * The function then carries the name func_00335A18. AFTER the resplat, rename it:
 *   sed -i 's/func_00335A18/func_00335A18/g' <this file>
 * The name is left as func_00335A18 here so the body stays verifiable against
 * today's monolith.
 */




__attribute__((section(".text.func_00335A18")))
int func_00335A18(void) {
    func_00335CD8();
    func_00335A40();
    return func_00335CE0();
}

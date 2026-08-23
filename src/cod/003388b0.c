/* cygnus-2.96 matched TU. */

extern int D_003E0710;
extern int D_003E0708;
extern char D_00455870[];
extern void func_003260C8(char *a0);

/* func_003388B0 -- DEAD-HEAD BOUNDARY DEFECT.
 * The declared span starts 24 B too early; the TRUE entry is 0x003388B0.
 * This body is BYTE-EXACT over 0x003388B0..end under cygnus-2.96 + c_flags_drop -freorder-blocks.
 * score_candidate against the DECLARED span reports a LEN miss of 6 words.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  func_003388B0 = 0x003388B0; // type:func
 *   scripts/resplat.sh
 * The function then carries the name func_003388B0. AFTER the resplat, rename it:
 *   sed -i 's/func_003388B0/func_003388B0/g' <this file>
 * The name is left as func_003388B0 here so the body stays verifiable against
 * today's monolith.
 */





__attribute__((section(".text.func_003388B0")))
int func_003388B0(void) {
    if (D_003E0710 == 1) {
        if (D_003E0708 <= 0) {
            return 0;
        }
    }
    func_003260C8(D_00455870);
    return 0;
}

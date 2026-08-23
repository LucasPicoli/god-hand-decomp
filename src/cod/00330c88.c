/* cygnus-2.96 matched TU. */

extern int D_00755E80;

/* func_00330C88 -- DEAD-HEAD BOUNDARY DEFECT.
 * The declared span starts 8 B too early; the TRUE entry is 0x00330C88.
 * This body is BYTE-EXACT over 0x00330C88..end under cygnus-2.96.
 * score_candidate against the DECLARED span reports a LEN miss of 2 words.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  func_00330C88 = 0x00330C88; // type:func
 *   scripts/resplat.sh
 * The function then carries the name func_00330C88. AFTER the resplat, rename it:
 *   sed -i 's/func_00330C88/func_00330C88/g' <this file>
 * The name is left as func_00330C88 here so the body stays verifiable against
 * today's monolith.
 */


__attribute__((section(".text.func_00330C88")))
void func_00330C88(void) {
    int *p;
    int i;
    void (**q)(void);
    p = &D_00755E80;
    i = 0x1F;
    do {
        q = (void (**)(void))*p;
        p += 4;
        if (q != 0) {
            if (*q != 0) {
                (*q)();
            }
        }
        i--;
    } while (i >= 0);
}

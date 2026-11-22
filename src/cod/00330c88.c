/* cygnus-2.96 matched TU. */

extern int D_00755E80;

/* cvFsExecServer -- DEAD-HEAD BOUNDARY DEFECT.
 * The declared span starts 8 B too early; the TRUE entry is 0x00330C88.
 * This body is BYTE-EXACT over 0x00330C88..end under cygnus-2.96.
 * score_candidate against the DECLARED span reports a LEN miss of 2 words.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  cvFsExecServer = 0x00330C88; // type:func
 *   scripts/resplat.sh
 * The function then carries the name cvFsExecServer. AFTER the resplat, rename it:
 *   sed -i 's/cvFsExecServer/cvFsExecServer/g' <this file>
 * The name is left as cvFsExecServer here so the body stays verifiable against
 * today's monolith.
 */


__attribute__((section(".text.cvFsExecServer")))
void cvFsExecServer(void) {
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

/* cygnus-2.96 matched TU. */

extern int *GetD003EEA90_360D18(void);
extern void func_0035FE20(int a0, int a1, int a2);

/* func_00360CF0 -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
 * The declared span starts 32 B too early. The TRUE ENTRY is 0x00360CF0.
 * This body is BYTE-EXACT over the TRUE span under cygnus-2.96
 * with no extra keys.
 * score_candidate against the DECLARED span reports a clean LEN miss of
 * 8 words with REG 0 / IMM 0 / OPC 0. That is what a CORRECT body
 * looks like in this class. Do not edit it.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  func_00360CF0 = 0x00360CF0; // type:func
 *   scripts/resplat.sh
 * The function then carries the name func_00360CF0. AFTER the resplat rename it:
 *   sed -i 's/func_00360CF0/func_00360CF0/g' <this file>
 * The name is left as func_00360CF0 here so the body stays verifiable against
 * today's monolith.
 */



__attribute__((section(".text.func_00360CF0")))
int func_00360CF0(void) {
    *GetD003EEA90_360D18() = 0;
    return func_00360D28(0x80);
}

/* func_0033D2D0 -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
 * The declared span starts 8 B too early. The TRUE ENTRY is 0x0033D2D0.
 * This body is BYTE-EXACT over the TRUE span under cygnus-2.96
 * with no extra keys.
 * score_candidate against the DECLARED span reports a clean LEN miss of
 * 2 words with REG 0 / IMM 0 / OPC 0. That is what a CORRECT body
 * looks like in this class. Do not edit it.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  func_0033D2D0 = 0x0033D2D0; // type:func
 *   scripts/resplat.sh
 * The function then carries the name func_0033D2D0. AFTER the resplat rename it:
 *   sed -i 's/func_0033D2D0/func_0033D2D0/g' <this file>
 * The name is left as func_0033D2D0 here so the body stays verifiable against
 * today's monolith.
 */



__attribute__((section(".text.func_0033D2D0")))
int func_0033D2D0(int *a0, int a1) {
    int *p = (int *)((char *)a0 + 0x48);
    int s0 = a0[2];
    func_0033FA70(s0, p[0], a1, p[5] + (p[8] << 1), 0);
    return func_0033FB00(s0);
}

/* func_0035FD98 -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
 * The declared span starts 24 B too early. The TRUE ENTRY is 0x0035FD98.
 * This body is BYTE-EXACT over the TRUE span under cygnus-2.96
 * with no extra keys.
 * score_candidate against the DECLARED span reports a clean LEN miss of
 * 6 words with REG 0 / IMM 0 / OPC 0. That is what a CORRECT body
 * looks like in this class. Do not edit it.
 * MERGE CASE. The declared span also ends EARLY: the real function runs to
 * 0x0035FE1C, so it continues into the next declaration `func_0035FDA8`.
 * The orchestrator must ALSO REMOVE `func_0035FDA8` from config/symbol_addrs.txt,
 * or the two halves stay split and this body cannot land.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  func_0035FD98 = 0x0035FD98; // type:func
 *   scripts/resplat.sh
 * The function then carries the name func_0035FD98. AFTER the resplat rename it:
 *   sed -i 's/func_0035FD98/func_0035FD98/g' <this file>
 * The name is left as func_0035FD98 here so the body stays verifiable against
 * today's monolith.
 */


__attribute__((section(".text.func_0035FD98")))
void func_0035FD98(int a0, int a1, int a2) {
    int u = (a2 / 2) * 2;
    int v = (a1 / 2) * 2;
    func_0035FE20(a0 + 0x4, u, v);
    func_0035FE20(a0 + 0x14, u >> 1, v >> 1);
    func_0035FE20(a0 + 0x24, u >> 1, v >> 1);
}

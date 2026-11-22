/* cygnus-2.96 matched TU. */

extern int *GetD003EEA90_360D18(void);
extern void func_0035FE20(int a0, int a1, int a2);

/* CFTPS2_InitMaxAlpha -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
 * The declared span starts 32 B too early. The TRUE ENTRY is 0x00360CF0.
 * This body is BYTE-EXACT over the TRUE span under cygnus-2.96
 * with no extra keys.
 * score_candidate against the DECLARED span reports a clean LEN miss of
 * 8 words with REG 0 / IMM 0 / OPC 0. That is what a CORRECT body
 * looks like in this class. Do not edit it.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  CFTPS2_InitMaxAlpha = 0x00360CF0; // type:func
 *   scripts/resplat.sh
 * The function then carries the name CFTPS2_InitMaxAlpha. AFTER the resplat rename it:
 *   sed -i 's/CFTPS2_InitMaxAlpha/CFTPS2_InitMaxAlpha/g' <this file>
 * The name is left as CFTPS2_InitMaxAlpha here so the body stays verifiable against
 * today's monolith.
 */



__attribute__((section(".text.CFTPS2_InitMaxAlpha")))
int CFTPS2_InitMaxAlpha(void) {
    *GetD003EEA90_360D18() = 0;
    return func_00360D28(0x80);
}

/* ADXB_EvokeExpandMono -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
 * The declared span starts 8 B too early. The TRUE ENTRY is 0x0033D2D0.
 * This body is BYTE-EXACT over the TRUE span under cygnus-2.96
 * with no extra keys.
 * score_candidate against the DECLARED span reports a clean LEN miss of
 * 2 words with REG 0 / IMM 0 / OPC 0. That is what a CORRECT body
 * looks like in this class. Do not edit it.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  ADXB_EvokeExpandMono = 0x0033D2D0; // type:func
 *   scripts/resplat.sh
 * The function then carries the name ADXB_EvokeExpandMono. AFTER the resplat rename it:
 *   sed -i 's/ADXB_EvokeExpandMono/ADXB_EvokeExpandMono/g' <this file>
 * The name is left as ADXB_EvokeExpandMono here so the body stays verifiable against
 * today's monolith.
 */



__attribute__((section(".text.ADXB_EvokeExpandMono")))
int ADXB_EvokeExpandMono(int *a0, int a1) {
    int *p = (int *)((char *)a0 + 0x48);
    int s0 = a0[2];
    func_0033FA70(s0, p[0], a1, p[5] + (p[8] << 1), 0);
    return ADXPD_Start(s0);
}

/* SFX_ShiftYccPtrByPix -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
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
 *   config/symbol_addrs.txt  +  SFX_ShiftYccPtrByPix = 0x0035FD98; // type:func
 *   scripts/resplat.sh
 * The function then carries the name SFX_ShiftYccPtrByPix. AFTER the resplat rename it:
 *   sed -i 's/SFX_ShiftYccPtrByPix/SFX_ShiftYccPtrByPix/g' <this file>
 * The name is left as SFX_ShiftYccPtrByPix here so the body stays verifiable against
 * today's monolith.
 */


__attribute__((section(".text.SFX_ShiftYccPtrByPix")))
void SFX_ShiftYccPtrByPix(int a0, int a1, int a2) {
    int u = (a2 / 2) * 2;
    int v = (a1 / 2) * 2;
    func_0035FE20(a0 + 0x4, u, v);
    func_0035FE20(a0 + 0x14, u >> 1, v >> 1);
    func_0035FE20(a0 + 0x24, u >> 1, v >> 1);
}

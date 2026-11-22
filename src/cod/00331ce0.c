/* cygnus-2.96 matched TU. */
#include "godhand/criStm.h"
#include "godhand/globals.h"

extern volatile int D_003D8454;
extern void func_003B1F28(char *a0);
extern volatile int D_00766C9C;
extern int D_00766C90;
extern int *Obj35D0_GetStringPtr_D00459BF0(void);
extern void initLibWork(int a0, int a1);
extern void Obj35D0_SetFields_a1_Clear4_a2_D718(int *a0, int a1, int a2);
extern int *Obj0000_Get_D_0045A1B0_360790(void);
extern void Tramp_sceSifFreeSysMemory_3B5A50(int a0);
extern void DTX_Destroy(int a0);
extern void ps2rna_finish_psj(void);
extern void PS2RNA_FinishIopSnd(void);
extern void DTX_Finish(void);
extern void SJX_Finish(void);
extern void func_0033B010(void);

/* SRD_SetLockHost -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
 * The declared span starts 8 B too early. The TRUE ENTRY is 0x00331CE0.
 * This body is BYTE-EXACT over the TRUE span under cygnus-2.96
 * with c_flags_drop: ["-freorder-blocks"].
 * score_candidate against the DECLARED span reports a clean LEN miss of
 * 2 words with REG 0 / IMM 0 / OPC 0. That is what a CORRECT body
 * looks like in this class. Do not edit it.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  SRD_SetLockHost = 0x00331CE0; // type:func
 *   scripts/resplat.sh
 * The function then carries the name SRD_SetLockHost. AFTER the resplat rename it:
 *   sed -i 's/SRD_SetLockHost/SRD_SetLockHost/g' <this file>
 * The name is left as SRD_SetLockHost here so the body stays verifiable against
 * today's monolith.
 */





__attribute__((section(".text.SRD_SetLockHost")))
void SRD_SetLockHost(int a0) {
    D_003D8454 = (char)a0;
    D_003D8484 = D_003D8454;
    if (a0 == 1) {
        func_003B1F28(D_004540B8);
    }
}

/* SFH_Init -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
 * The declared span starts 8 B too early. The TRUE ENTRY is 0x0035D538.
 * This body is BYTE-EXACT over the TRUE span under cygnus-2.96
 * with c_flags_drop: ["-freorder-blocks"].
 * score_candidate against the DECLARED span reports a clean LEN miss of
 * 2 words with REG 0 / IMM 0 / OPC 0. That is what a CORRECT body
 * looks like in this class. Do not edit it.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  SFH_Init = 0x0035D538; // type:func
 *   scripts/resplat.sh
 * The function then carries the name SFH_Init. AFTER the resplat rename it:
 *   sed -i 's/SFH_Init/SFH_Init/g' <this file>
 * The name is left as SFH_Init here so the body stays verifiable against
 * today's monolith.
 */







__attribute__((section(".text.SFH_Init")))
void SFH_Init(int a0, int a1) {
    int t = D_00766C9C;
    if (t <= 0) {
        D_00766C9C = t + 1;
        D_00766C88 = Obj35D0_GetStringPtr_D00459BF0();
        initLibWork(a0, a1);
        Obj35D0_SetFields_a1_Clear4_a2_D718(&D_00766C90, a0, a1);
    }
}

/* SUD_Init -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
 * The declared span starts 16 B too early. The TRUE ENTRY is 0x00360740.
 * This body is BYTE-EXACT over the TRUE span under cygnus-2.96
 * with c_flags_drop: ["-freorder-blocks"].
 * score_candidate against the DECLARED span reports a clean LEN miss of
 * 4 words with REG 0 / IMM 0 / OPC 0. That is what a CORRECT body
 * looks like in this class. Do not edit it.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  SUD_Init = 0x00360740; // type:func
 *   scripts/resplat.sh
 * The function then carries the name SUD_Init. AFTER the resplat rename it:
 *   sed -i 's/SUD_Init/SUD_Init/g' <this file>
 * The name is left as SUD_Init here so the body stays verifiable against
 * today's monolith.
 */




__attribute__((section(".text.SUD_Init")))
void SUD_Init(void) {
    if (D_003EEA6C <= 0) {
        D_00766CA4 = Obj0000_Get_D_0045A1B0_360790();
        D_003EEA6C = D_003EEA6C + 1;
    }
}

/* PS2RNA_Finish -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
 * The declared span starts 24 B too early. The TRUE ENTRY is 0x00337D20.
 * This body is BYTE-EXACT over the TRUE span under cygnus-2.96
 * with c_flags_drop: ["-freorder-blocks"].
 * score_candidate against the DECLARED span reports a clean LEN miss of
 * 6 words with REG 0 / IMM 0 / OPC 0. That is what a CORRECT body
 * looks like in this class. Do not edit it.
 * MERGE CASE. The declared span also ends EARLY: the real function runs to
 * 0x00337DDC, so it continues into the next declaration `func_00337D24`.
 * The orchestrator must ALSO REMOVE `func_00337D24` from config/symbol_addrs.txt,
 * or the two halves stay split and this body cannot land.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  PS2RNA_Finish = 0x00337D20; // type:func
 *   scripts/resplat.sh
 * The function then carries the name PS2RNA_Finish. AFTER the resplat rename it:
 *   sed -i 's/PS2RNA_Finish/PS2RNA_Finish/g' <this file>
 * The name is left as PS2RNA_Finish here so the body stays verifiable against
 * today's monolith.
 */














__attribute__((section(".text.PS2RNA_Finish")))
void PS2RNA_Finish(void) {
    int n;
    if (D_003E0710 == 1) {
        if (D_003E0708 <= 0) {
            return;
        }
    }
    n = D_003E0754 - 1;
    D_003E0754 = n;
    if (n == 0) {
        Tramp_sceSifFreeSysMemory_3B5A50(D_003E0724);
        D_003E0724 = 0;
        DTX_Destroy(D_003E31A8);
        D_003E31A8 = 0;
        Tramp_sceSifFreeSysMemory_3B5A50(D_003E075C);
        D_003E075C = 0;
        ps2rna_finish_psj();
        PS2RNA_FinishIopSnd();
        DTX_Finish();
        SJX_Finish();
        func_0033B010();
    }
}

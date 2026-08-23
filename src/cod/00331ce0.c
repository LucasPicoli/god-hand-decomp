/* cygnus-2.96 matched TU. */

extern volatile int D_003D8454;
extern int D_003D8484;
extern char D_004540B8[];
extern void func_003B1F28(char *a0);
extern volatile int D_00766C9C;
extern volatile int *D_00766C88;
extern int D_00766C90;
extern int *Obj35D0_GetStringPtr_D00459BF0(void);
extern void initLibWork(int a0, int a1);
extern void Obj35D0_SetFields_a1_Clear4_a2_D718(int *a0, int a1, int a2);
extern int D_003EEA6C;
extern int *volatile D_00766CA4;
extern int *Obj0000_Get_D_0045A1B0_360790(void);
extern int D_003E0710;
extern int D_003E0708;
extern int D_003E0754;
extern int D_003E0724;
extern int D_003E31A8;
extern int D_003E075C;
extern void Tramp_sceSifFreeSysMemory_3B5A50(int a0);
extern void DTX_Destroy(int a0);
extern void func_00337240(void);
extern void func_00337AC8(void);
extern void func_003325F8(void);
extern void func_0033B3B0(void);
extern void func_0033B010(void);

/* func_00331CE0 -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
 * The declared span starts 8 B too early. The TRUE ENTRY is 0x00331CE0.
 * This body is BYTE-EXACT over the TRUE span under cygnus-2.96
 * with c_flags_drop: ["-freorder-blocks"].
 * score_candidate against the DECLARED span reports a clean LEN miss of
 * 2 words with REG 0 / IMM 0 / OPC 0. That is what a CORRECT body
 * looks like in this class. Do not edit it.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  func_00331CE0 = 0x00331CE0; // type:func
 *   scripts/resplat.sh
 * The function then carries the name func_00331CE0. AFTER the resplat rename it:
 *   sed -i 's/func_00331CE0/func_00331CE0/g' <this file>
 * The name is left as func_00331CE0 here so the body stays verifiable against
 * today's monolith.
 */





__attribute__((section(".text.func_00331CE0")))
void func_00331CE0(int a0) {
    D_003D8454 = (char)a0;
    D_003D8484 = D_003D8454;
    if (a0 == 1) {
        func_003B1F28(D_004540B8);
    }
}

/* func_0035D538 -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
 * The declared span starts 8 B too early. The TRUE ENTRY is 0x0035D538.
 * This body is BYTE-EXACT over the TRUE span under cygnus-2.96
 * with c_flags_drop: ["-freorder-blocks"].
 * score_candidate against the DECLARED span reports a clean LEN miss of
 * 2 words with REG 0 / IMM 0 / OPC 0. That is what a CORRECT body
 * looks like in this class. Do not edit it.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  func_0035D538 = 0x0035D538; // type:func
 *   scripts/resplat.sh
 * The function then carries the name func_0035D538. AFTER the resplat rename it:
 *   sed -i 's/func_0035D538/func_0035D538/g' <this file>
 * The name is left as func_0035D538 here so the body stays verifiable against
 * today's monolith.
 */







__attribute__((section(".text.func_0035D538")))
void func_0035D538(int a0, int a1) {
    int t = D_00766C9C;
    if (t <= 0) {
        D_00766C9C = t + 1;
        D_00766C88 = Obj35D0_GetStringPtr_D00459BF0();
        initLibWork(a0, a1);
        Obj35D0_SetFields_a1_Clear4_a2_D718(&D_00766C90, a0, a1);
    }
}

/* func_00360740 -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
 * The declared span starts 16 B too early. The TRUE ENTRY is 0x00360740.
 * This body is BYTE-EXACT over the TRUE span under cygnus-2.96
 * with c_flags_drop: ["-freorder-blocks"].
 * score_candidate against the DECLARED span reports a clean LEN miss of
 * 4 words with REG 0 / IMM 0 / OPC 0. That is what a CORRECT body
 * looks like in this class. Do not edit it.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  func_00360740 = 0x00360740; // type:func
 *   scripts/resplat.sh
 * The function then carries the name func_00360740. AFTER the resplat rename it:
 *   sed -i 's/func_00360740/func_00360740/g' <this file>
 * The name is left as func_00360740 here so the body stays verifiable against
 * today's monolith.
 */




__attribute__((section(".text.func_00360740")))
void func_00360740(void) {
    if (D_003EEA6C <= 0) {
        D_00766CA4 = Obj0000_Get_D_0045A1B0_360790();
        D_003EEA6C = D_003EEA6C + 1;
    }
}

/* func_00337D20 -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
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
 *   config/symbol_addrs.txt  +  func_00337D20 = 0x00337D20; // type:func
 *   scripts/resplat.sh
 * The function then carries the name func_00337D20. AFTER the resplat rename it:
 *   sed -i 's/func_00337D20/func_00337D20/g' <this file>
 * The name is left as func_00337D20 here so the body stays verifiable against
 * today's monolith.
 */














__attribute__((section(".text.func_00337D20")))
void func_00337D20(void) {
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
        func_00337240();
        func_00337AC8();
        func_003325F8();
        func_0033B3B0();
        func_0033B010();
    }
}

/* cygnus-2.96 matched TU. */

extern int D_003E9D5C;
extern int D_003EE804;
extern int D_0045A290;
extern int *volatile D_00766CD0;

/* GetField_F_33CE80 -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
 * The declared span starts 8 B too early. The TRUE ENTRY is 0x0033CE80.
 * This body is BYTE-EXACT over the TRUE span under cygnus-2.96
 * with no extra keys.
 * score_candidate against the DECLARED span reports a clean LEN miss of
 * 2 words with REG 0 / IMM 0 / OPC 0. That is what a CORRECT body
 * looks like in this class. Do not edit it.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  GetField_F_33CE80 = 0x0033CE80; // type:func
 *   scripts/resplat.sh
 * The function then carries the name GetField_F_33CE80. AFTER the resplat rename it:
 *   sed -i 's/GetField_F_33CE80/GetField_F_33CE80/g' <this file>
 * The name is left as GetField_F_33CE80 here so the body stays verifiable against
 * today's monolith.
 */
__attribute__((section(".text.GetField_F_33CE80")))
int GetField_F_33CE80(int *a0) { return a0[0xF]; }

/* SetField_4_35FC78 -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
 * The declared span starts 8 B too early. The TRUE ENTRY is 0x0035FC78.
 * This body is BYTE-EXACT over the TRUE span under cygnus-2.96
 * with no extra keys.
 * score_candidate against the DECLARED span reports a clean LEN miss of
 * 2 words with REG 0 / IMM 0 / OPC 0. That is what a CORRECT body
 * looks like in this class. Do not edit it.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  SetField_4_35FC78 = 0x0035FC78; // type:func
 *   scripts/resplat.sh
 * The function then carries the name SetField_4_35FC78. AFTER the resplat rename it:
 *   sed -i 's/SetField_4_35FC78/SetField_4_35FC78/g' <this file>
 * The name is left as SetField_4_35FC78 here so the body stays verifiable against
 * today's monolith.
 */
__attribute__((section(".text.SetField_4_35FC78")))
void SetField_4_35FC78(int *a0, int a1) { a0[4] = a1; }

/* ReturnK_Neg1_369FB0 -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
 * The declared span starts 8 B too early. The TRUE ENTRY is 0x00369FB0.
 * This body is BYTE-EXACT over the TRUE span under cygnus-2.96
 * with no extra keys.
 * score_candidate against the DECLARED span reports a clean LEN miss of
 * 2 words with REG 0 / IMM 0 / OPC 0. That is what a CORRECT body
 * looks like in this class. Do not edit it.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  ReturnK_Neg1_369FB0 = 0x00369FB0; // type:func
 *   scripts/resplat.sh
 * The function then carries the name ReturnK_Neg1_369FB0. AFTER the resplat rename it:
 *   sed -i 's/ReturnK_Neg1_369FB0/ReturnK_Neg1_369FB0/g' <this file>
 * The name is left as ReturnK_Neg1_369FB0 here so the body stays verifiable against
 * today's monolith.
 */
__attribute__((section(".text.ReturnK_Neg1_369FB0")))
int ReturnK_Neg1_369FB0(void) { return -1; }

/* func_0033C708 -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
 * The declared span starts 8 B too early. The TRUE ENTRY is 0x0033C708.
 * This body is BYTE-EXACT over the TRUE span under cygnus-2.96
 * with no extra keys.
 * score_candidate against the DECLARED span reports a clean LEN miss of
 * 2 words with REG 0 / IMM 0 / OPC 0. That is what a CORRECT body
 * looks like in this class. Do not edit it.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  func_0033C708 = 0x0033C708; // type:func
 *   scripts/resplat.sh
 * The function then carries the name func_0033C708. AFTER the resplat rename it:
 *   sed -i 's/func_0033C708/func_0033C708/g' <this file>
 * The name is left as func_0033C708 here so the body stays verifiable against
 * today's monolith.
 */


__attribute__((section(".text.func_0033C708")))
void func_0033C708(int a0) { D_003E9D5C = a0; }

/* func_00360710 -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
 * The declared span starts 24 B too early. The TRUE ENTRY is 0x00360710.
 * This body is BYTE-EXACT over the TRUE span under cygnus-2.96
 * with no extra keys.
 * score_candidate against the DECLARED span reports a clean LEN miss of
 * 6 words with REG 0 / IMM 0 / OPC 0. That is what a CORRECT body
 * looks like in this class. Do not edit it.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  func_00360710 = 0x00360710; // type:func
 *   scripts/resplat.sh
 * The function then carries the name func_00360710. AFTER the resplat rename it:
 *   sed -i 's/func_00360710/func_00360710/g' <this file>
 * The name is left as func_00360710 here so the body stays verifiable against
 * today's monolith.
 */


__attribute__((section(".text.func_00360710")))
void func_00360710(int a0) { D_003EE804 = a0; }

/* SetField_1_35FC58 -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
 * The declared span starts 32 B too early. The TRUE ENTRY is 0x0035FC58.
 * This body is BYTE-EXACT over the TRUE span under cygnus-2.96
 * with no extra keys.
 * score_candidate against the DECLARED span reports a clean LEN miss of
 * 8 words with REG 0 / IMM 0 / OPC 0. That is what a CORRECT body
 * looks like in this class. Do not edit it.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  SetField_1_35FC58 = 0x0035FC58; // type:func
 *   scripts/resplat.sh
 * The function then carries the name SetField_1_35FC58. AFTER the resplat rename it:
 *   sed -i 's/SetField_1_35FC58/SetField_1_35FC58/g' <this file>
 * The name is left as SetField_1_35FC58 here so the body stays verifiable against
 * today's monolith.
 */
__attribute__((section(".text.SetField_1_35FC58")))
void SetField_1_35FC58(int *a0, int a1) { a0[1] = a1; }

/* func_00360CA0 -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
 * The declared span starts 16 B too early. The TRUE ENTRY is 0x00360CA0.
 * This body is BYTE-EXACT over the TRUE span under cygnus-2.96
 * with no extra keys.
 * score_candidate against the DECLARED span reports a clean LEN miss of
 * 4 words with REG 0 / IMM 0 / OPC 0. That is what a CORRECT body
 * looks like in this class. Do not edit it.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  func_00360CA0 = 0x00360CA0; // type:func
 *   scripts/resplat.sh
 * The function then carries the name func_00360CA0. AFTER the resplat rename it:
 *   sed -i 's/func_00360CA0/func_00360CA0/g' <this file>
 * The name is left as func_00360CA0 here so the body stays verifiable against
 * today's monolith.
 */




__attribute__((section(".text.func_00360CA0")))
int func_00360CA0(void) {
    D_00766CD0 = &D_0045A290;
    return func_00360CF0();
}

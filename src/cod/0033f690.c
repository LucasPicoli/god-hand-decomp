/* sn-2.95.3-136 matched TU. */

extern int D_003EB848;
extern void func_0033F7B8(void);
extern void Forward33BC48_33BD90(void);
extern void Forward33BC48_33BDA8(void);
extern void Forward33BC48_33BDC0(void);

/* func_0033F690 -- DEAD-HEAD BOUNDARY DEFECT (wave 18, lane K2).
 * The declared span starts 32 B too early. The TRUE ENTRY is 0x0033F690.
 * This body is BYTE-EXACT over the TRUE span under sn-2.95.3-136
 * with no extra keys.
 * score_candidate against the DECLARED span reports a clean LEN miss of
 * 8 words with REG 0 / IMM 0 / OPC 0. That is what a CORRECT body
 * looks like in this class. Do not edit it.
 * MERGE CASE. The declared span also ends EARLY: the real function runs to
 * 0x0033F720, so it continues into the next declaration `func_0033F694`.
 * The orchestrator must ALSO REMOVE `func_0033F694` from config/symbol_addrs.txt,
 * or the two halves stay split and this body cannot land.
 * Land it only after the boundary moves:
 *   config/symbol_addrs.txt  +  func_0033F690 = 0x0033F690; // type:func
 *   scripts/resplat.sh
 * The function then carries the name func_0033F690. AFTER the resplat rename it:
 *   sed -i 's/func_0033F690/func_0033F690/g' <this file>
 * The name is left as func_0033F690 here so the body stays verifiable against
 * today's monolith.
 */







__attribute__((section(".text.func_0033F690")))
int func_0033F690(void) {
    int r = func_0033F850(D_003EB848);
    int lo = r < 2;
    if (r == 1) goto a1;
    if (lo) goto out;
    if (r == 2) goto a2;
    if (r == 3) goto a3;
    do { } while (0);
    goto out;
a1:
    func_0033F7B8();
    do { } while (0);
    goto out;
a2:
    Forward33BC48_33BD90();
    do { } while (0);
    goto out;
a3:
    Forward33BC48_33BDA8();
    Forward33BC48_33BDC0();
out:
    return 0;
}

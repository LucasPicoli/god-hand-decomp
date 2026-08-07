/* sn-2.95.3-136 matched TU. */

extern int D_007474A0;
extern int D_00747AC0;
extern int D_003C3C40;
extern int D_00747B00;

/* sn-2.95.3-136 — byte_match: true (120 B)
 *
 * Two levers here.
 *
 * 1. dst/src must be bound to locals IMMEDIATELY BEFORE the lqc2 run, not at
 *    the top of the guarded block.  Binding them at the top hoists all four
 *    %hi/%lo chains above the leading sqc2 (20.0% exact-aligned); binding them
 *    in their own inner block puts exactly two address chains in flight, which
 *    is what retail schedules (lui dst, lui src, addiu dst, addiu src).
 *
 * 2. The three zero stores must be a CHAINED assignment.  Four separate
 *    `p[i] = 0.0f;` statements each take gcc's SFmode `sw $zero` path; the
 *    chain creates one shared SFmode pseudo, which is materialised once with
 *    `mtc1 $zero,$f0` and reused by three `swc1` -- retail's exact form.
 *    The emitted store order (0, 0xC, 0x8, 0x4) then falls out on its own.
 */

#include "godhand/vu0.h"






__attribute__((section(".text.func_003079C8")))
void func_003079C8(int a0, int a1) {
    if (a1 == 0xFFFF && a0 != 0) {
        VU0_SQC2_VF0(&D_007474A0, 0x5C0);
        {
            void *dst = &D_00747AC0;
            void *src = &D_003C3C40;
            VU0_LQC2(4, src, 0x0);
            VU0_LQC2(5, src, 0x10);
            VU0_LQC2(6, src, 0x20);
            VU0_LQC2(7, src, 0x30);
            VU0_SQC2(4, dst, 0x0);
            VU0_SQC2(5, dst, 0x10);
            VU0_SQC2(6, dst, 0x20);
            VU0_SQC2(7, dst, 0x30);
        }
        {
            float *p = (float *)&D_00747B00;
            p[0] = p[1] = p[2] = 0.0f;
            p[3] = 1.0f;
        }
    }
}

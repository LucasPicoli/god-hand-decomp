/* cygnus-2.96 matched TU. */

extern int D_00586AF0;
extern int D_004A6D80;
extern int D_003BD8D0;

/* cygnus-2.96 --drop-freorder-blocks — byte_match: true (36 B) */

#include "godhand/vu0.h"



__attribute__((section(".text.func_00298000")))
void func_00298000(int a0, int a1) {
    if (a1 == 0xFFFF && a0 != 0) {
        VU0_SQC2_VF0(&D_00586AF0, 0x20);
    }
}

/* cygnus-2.96 --drop-freorder-blocks — byte_match: true (72 B)
 *
 * Both base addresses MUST be bound to locals before the lqc2 run: with the
 * symbols spelled inline in the macro operands gcc materialises each %hi/%lo
 * pair at first use, so the dst pair sinks below the four loads (77.8%,
 * struct-distance 5).  Binding them first makes both address chains ready at
 * block entry and the scheduler interleaves them exactly as retail does
 * (lui dst, lui src, addiu dst, addiu src).
 */

#include "godhand/vu0.h"




__attribute__((section(".text.func_001574F0")))
void func_001574F0(int a0, int a1) {
    if (a1 == 0xFFFF && a0 != 0) {
        void *dst = &D_004A6D80;
        void *src = &D_003BD8D0;
        VU0_LQC2(4, src, 0x0);
        VU0_LQC2(5, src, 0x10);
        VU0_LQC2(6, src, 0x20);
        VU0_LQC2(7, src, 0x30);
        VU0_SQC2(4, dst, 0x0);
        VU0_SQC2(5, dst, 0x10);
        VU0_SQC2(6, dst, 0x20);
        VU0_SQC2(7, dst, 0x30);
    }
}

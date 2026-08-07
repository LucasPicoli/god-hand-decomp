/* cygnus-2.96 matched TU. */

extern int D_0041ECA0;

/* cygnus-2.96 (no flags) — byte_match: true (196 B)
 *
 * Levers:
 *  - `return-the-parameter-forces-entry-copy`: the pointer return type + the
 *    leading `char *p = (char *)a0;` copy is what emits retail's redundant
 *    entry `daddu $v0,$a0,$zero` (insn 1).  Without it, 192 B / 28.6%.
 *  - Each 1.0f vec4 is written as element 0 through `p` FIRST, then the other
 *    three through a pointer local introduced afterwards.  Introducing the
 *    pointer before the element-0 store lets CSE rewrite `*(float*)(p+0x110)`
 *    into `q[0]`, which emits `swc1 $f0,0($v1)` where retail has
 *    `swc1 $f0,0x110($v0)` — the last 2 wrong words at 95.9%.
 *  - Chain order `q[3] = q[2] = q[1]` reproduces retail's emitted store order
 *    0x110, 0x11C, 0x114, 0x118.
 *  - The identity-matrix idiom (vmove/vmr32 x3 then sqc2 at 0x30/0x20/0x10/0x0,
 *    descending) is copied verbatim from the matched src/cod/001503b8.c.
 */

#include "godhand/vu0.h"



__attribute__((section(".text.func_0014FF80")))
void *func_0014FF80(void *a0) {
    char *p = (char *)a0;
    *(void **)(p + 0x214) = &D_0041ECA0;
    VU0_SQC2_VF0(p, 0xC0);
    *(void **)(p + 0xD0) = p + 0x30;
    VU0_SQC2_VF0(p, 0xE0);
    *(void **)(p + 0xF0) = p + 0xB0;
    VU0_SQC2_VF0(p, 0x100);
    *(float *)(p + 0x110) = 1.0f;
    {
        float *q = (float *)(p + 0x110);
        q[3] = q[2] = q[1] = 1.0f;
    }
    *(float *)(p + 0x120) = 1.0f;
    {
        float *q = (float *)(p + 0x120);
        q[3] = q[2] = q[1] = 1.0f;
    }
    VU0_SQC2_VF0(p, 0x130);
    *(char *)(p + 0x140) = 0;
    *(int *)(p + 0x144) = 0;
    *(int *)(p + 0x148) = 0;
    *(int *)(p + 0x14C) = 0;
    *(int *)(p + 0x158) = 0;
    VU0_SQC2_VF0(p, 0x1A0);
    VU0_VMOVE_XYZW(4, 0);
    VU0_VMR32_XYZW(5, 4);
    VU0_VMR32_XYZW(6, 5);
    VU0_VMR32_XYZW(7, 6);
    VU0_SQC2(4, p, 0x30);
    VU0_SQC2(5, p, 0x20);
    VU0_SQC2(6, p, 0x10);
    VU0_SQC2(7, p, 0x0);
    {
        char *b = p + 0x80;
        VU0_VMOVE_XYZW(4, 0);
        VU0_VMR32_XYZW(5, 4);
        VU0_VMR32_XYZW(6, 5);
        VU0_VMR32_XYZW(7, 6);
        VU0_SQC2(4, b, 0x30);
        VU0_SQC2(5, b, 0x20);
        VU0_SQC2(6, b, 0x10);
        VU0_SQC2(7, b, 0x0);
    }
    return p;
}

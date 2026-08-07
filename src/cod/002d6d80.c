/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 — byte_match: true (440 B)
 *
 * Levers:
 *  - `return-the-parameter-forces-entry-copy`: pointer return + `return p;`
 *    emits retail's entry `daddu $a1,$a0,$zero` and its tail
 *    `jr $ra; daddu $v0,$a1,$zero`.  $a0 and $v0 are both needed as scratch
 *    (loop sentinel and running base), so the parameter has to live elsewhere.
 *  - Loop exit test: the six counting loops must be spelled `i != -1`, which
 *    emits `li $a0,-1` + `bne $v1,$a0`.  Spelling them `i < N` ascending or
 *    `i >= 0` descending both give `bgez` and cost the `li $a0,-1` (insn
 *    delta -8, 74.5%).  The FINAL loop is the exception: it really is
 *    `i >= 0` / `bgez`, and it walks its pointer DOWN.
 *  - `store-run-rotates-by-one`: the three `sw $zero` at 0x16284 / 0x16120 /
 *    0x16130 are written in that source order and emit as 0x16130, 0x16284,
 *    0x16120 -- last source store first.  Direct confirmation of the card.
 *  - The in-loop `nop` pairs are the ee-as R5900 short-loop errata pad and
 *    appear on their own; no --call-loop-pad needed (these loops have no call).
 */

#include "godhand/vu0.h"

__attribute__((section(".text.func_002D6D80")))
void *func_002D6D80(void *a0) {
    char *p = (char *)a0;
    int i;

    VU0_SQC2_VF0(p, 0x30);
    VU0_SQC2_VF0(p, 0x40);
    VU0_SQC2_VF0(p, 0x50);
    {
        char *e = p + 0x80;
        for (i = 255; i != -1; i--) {
            VU0_SQC2_VF0(e, 0x10);
            VU0_SQC2_VF0(e, 0x20);
            VU0_SQC2_VF0(e, 0x30);
            e += 0x70;
        }
    }

    VU0_SQC2_VF0(p, 0x7480);
    VU0_SQC2_VF0(p, 0x7490);
    VU0_SQC2_VF0(p, 0x74A0);
    {
        char *e = p + 0x74D0;
        for (i = 255; i != -1; i--) {
            VU0_SQC2_VF0(e, 0x10);
            VU0_SQC2_VF0(e, 0x20);
            VU0_SQC2_VF0(e, 0x30);
            e += 0x70;
        }
    }

    {
        char *b = p + 0xE8A0;
        VU0_SQC2_VF0(b, 0x30);
        VU0_SQC2_VF0(b, 0x40);
        VU0_SQC2_VF0(b, 0x50);
        {
            char *e = b + 0x80;
            for (i = 255; i != -1; i--) {
                VU0_SQC2_VF0(e, 0x10);
                VU0_SQC2_VF0(e, 0x20);
                VU0_SQC2_VF0(e, 0x30);
                e += 0x70;
            }
        }
    }

    {
        char *e = p + 0x15D00;
        for (i = 7; i != -1; i--) {
            VU0_SQC2_VF0(e, 0x0);
            VU0_SQC2_VF0(e, 0x10);
            VU0_SQC2_VF0(e, 0x20);
            e += 0x80;
        }
    }
    {
        char *e = p + 0x161A0;
        for (i = 2; i != -1; i--) {
            VU0_SQC2_VF0(e, 0x0);
            e += 0x10;
        }
    }
    {
        char *e = p + 0x161D0;
        for (i = 2; i != -1; i--) {
            VU0_SQC2_VF0(e, 0x0);
            e += 0x10;
        }
    }
    VU0_SQC2_VF0(p + 0x16200, 0x0);
    VU0_SQC2_VF0(p + 0x16210, 0x0);
    VU0_SQC2_VF0(p + 0x16220, 0x0);
    VU0_SQC2_VF0(p + 0x16230, 0x0);

    *(int *)(p + 0x16284) = 0;
    *(int *)(p + 0x16120) = 0;
    *(int *)(p + 0x16130) = 0;
    {
        int *w = (int *)(p + 0x1611C);
        for (i = 7; i >= 0; i--) {
            *w = 0;
            w--;
        }
    }
    return p;
}

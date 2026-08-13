/* SN ProDG ee-gcc 2.95.3 matched TU. */
/* src/cod/002a86.c — InitRenderStruct_2A8608: 6-arg actor-spawn / move setup wrapper.
 *
 * Builds a 0x7C-byte stack descriptor (3x sqc2 $vf0 zero-quads at 0x10/0x20/
 * 0x60, floats initialised to 1.0, sentinel bytes, scratch ints cleared),
 * writes t0 -> *(a0+0x574) and a3 -> *(u16*)(a0+0x570), then dispatches to
 * SetEffect(a1, a2, src, &desc, a3, a0) on the t1!=0 / t1==0 branch.
 * Hot: 180 call sites via func_0021A538's siblings.
 *
 * Byte-exact under sn-2.95.3-136.  Three edits closed the residual the old
 * header called a permutation:
 *   1. b4F is `unsigned char`.  `signed char` folds 0xFF to -1, so gcc emits
 *      one `li -1` for both 0x4C and 0x4F where retail has `li -1` AND
 *      `li 255`.  Worth 42 of 67 words.
 *   2. The 0x30..0x3C float run stores through a bound `float *q`, which
 *      hoists retail's `addiu $v0,$sp,0x30` above the group's first store.
 *      Naming the four members emits no base at all.  Worth 44 of 67 words.
 *   3. The branch tests `t1 == 0` first.  gcc emits the negated source
 *      condition and lays the "then" arm out as the fall-through, so retail's
 *      `bnez` means the source tested `== 0`.  Worth 12 words.
 * Two real bugs were fixed during the earlier recovery and still hold: a3 is
 * `int` (retail does no sign-extend), and the sqc2 $vf0 zero-quad idiom is
 * correct (objdump mislabels the identical bytes as `sdc2 $0`). */
#include "godhand/vu0.h"

extern int SetEffect();

typedef struct {
    float f00;      /* 0x00 */
    float f04;      /* 0x04 */
    float f08;      /* 0x08 */
    float f0C;      /* 0x0C */
    char  q10[0x10];/* 0x10 sqc2 */
    char  q20[0x10];/* 0x20 sqc2 */
    float f30;      /* 0x30 */
    float f34;      /* 0x34 */
    float f38;      /* 0x38 */
    float f3C;      /* 0x3C */
    float f40;      /* 0x40 */
    int   i44;      /* 0x44 */
    int   i48;      /* 0x48 */
    signed char b4C;/* 0x4C */
    signed char b4D;/* 0x4D */
    signed char b4E;/* 0x4E */
    unsigned char b4F;/* 0x4F */
    int   i50;      /* 0x50 */
    char  pad54[0xC];/* 0x54 */
    char  q60[0x10];/* 0x60 sqc2 */
    short h70;      /* 0x70 */
    short h72;      /* 0x72 */
    signed char b74;/* 0x74 */
    char  pad75[3]; /* 0x75 */
    int   i78;      /* 0x78 */
} S;

__attribute__((section(".text.InitRenderStruct_2A8608")))
void InitRenderStruct_2A8608(void *a0, int a1, void *a2, int a3, int t0, void *t1) {
    S s;
    s.f00 = 1.0f;
    s.f04 = 1.0f;
    s.f08 = 1.0f;
    s.f0C = 1.0f;
    VU0_SQC2_VF0(&s, 0x10);
    VU0_SQC2_VF0(&s, 0x20);
    {
        float *q = &s.f30;
        q[0] = 1.0f;
        q[1] = 1.0f;
        q[2] = 1.0f;
        q[3] = 1.0f;
    }
    s.f40 = 1.0f;
    s.b4C = -1;
    s.b4F = 0xFF;
    s.i44 = 0;
    s.i48 = 0;
    s.b4D = 0;
    s.b4E = 0;
    s.i50 = 0;
    VU0_SQC2_VF0(&s, 0x60);
    *(int *)((char *)a0 + 0x574) = t0;
    s.h70 = 0;
    s.h72 = 0;
    s.b74 = 0;
    s.i78 = 0;
    *(unsigned short *)((char *)a0 + 0x570) = a3;
    if (t1 == 0) {
        if (a0 != 0) {
            if (*(unsigned short *)((char *)a0 + 0x434) & 2) {
                s.i48 |= 0x80;
                s.f40 = *(float *)((char *)a0 + 0x114);
            }
        }
        SetEffect(a1, a2, a0, &s, a3, a0);
    } else {
        if (a0 != 0) {
            s.f40 = *(float *)((char *)a0 + 0x114);
        }
        SetEffect(a1, a2, t1, &s, a3, a0);
    }
}

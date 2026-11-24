/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"
#include "godhand/cGameObj.h"
#include "godhand/cObjBase.h"

/* Start effect a2 of kind a1 with the default parameters, and record a3 and t0
 * in a0 as its effect number and kill mode. With no t1 the effect sits on a0,
 * looping and at a0's scale when a0's motionFlags has bit 1; otherwise it sits
 * on t1 at a0's scale. Either way it follows a0. */
/* Three spellings are load-bearing under sn-2.95.3-136:
 *   1. unk4F is `unsigned char`: a signed byte folds 0xFF to -1, and gcc then
 *      emits one `li -1` for both 0x4C and 0x4F where retail has two.
 *   2. The scale run stores through the bound `float *q`, which hoists
 *      retail's `addiu $v0,$sp,0x30` above the first store.
 *   3. The branch tests `t1 == 0` first, so its arm is retail's fall-through. */
__attribute__((section(".text.InitRenderStruct_2A8608")))
void InitRenderStruct_2A8608(cGameObj *a0, int a1, int a2, int a3, int t0, void *t1) {
    cEffectParam s;
    s.color.x = 1.0f;
    s.color.y = 1.0f;
    s.color.z = 1.0f;
    s.color.w = 1.0f;
    VU0_SQC2_VF0(&s, 0x10);
    VU0_SQC2_VF0(&s, 0x20);
    {
        float *q = &s.scale.x;
        q[0] = 1.0f;
        q[1] = 1.0f;
        q[2] = 1.0f;
        q[3] = 1.0f;
    }
    s.size = 1.0f;
    s.unk4C = -1;
    s.unk4F = 0xFF;
    s.unk44 = 0;
    s.flags = 0;
    s.unk4D = 0;
    s.unk4E = 0;
    s.unk50 = 0;
    VU0_SQC2_VF0(&s, 0x60);
    a0->effArg = t0;
    s.unk70 = 0;
    s.unk72 = 0;
    s.unk74 = 0;
    s.unk78 = 0;
    a0->effNo = a3;
    if (t1 == 0) {
        if (a0 != 0) {
            if (a0->motionFlags & 2) {
                s.flags |= EFFECT_PARAM_LOOP;
                s.size = a0->scale.y;
            }
        }
        SetEffect(a1, a2, (cObj *)a0, &s, a3, (cObj *)a0);
    } else {
        if (a0 != 0) {
            s.size = a0->scale.y;
        }
        SetEffect(a1, a2, t1, &s, a3, (cObj *)a0);
    }
}

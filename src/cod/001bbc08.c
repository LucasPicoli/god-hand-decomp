/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/vu0.h"
#include "godhand/cGameObj.h"


extern float fRand1_1(void);
extern void cObjBase_MoveByNullSpeed(void *a0, float f12, float f13);

__attribute__((section(".text.func_001BBC08")))
void func_001BBC08(cGameObj *s0)
{
    switch (s0->step) {
    case 0:
        s0->unk568 = 0xE;
        s0->step = s0->step + 1;
        /* fallthrough */
    case 1:
        (*(float **)((char *)s0 + 0xF0))[1] = (*(float **)((char *)s0 + 0xF0))[1] - 0.100000001f;
        if (s0->unk568 != 0) {
            s0->unk568 = *(unsigned short *)((char *)s0 + 0x568) - 1;
        } else {
            s0->step = s0->step + 1;
        }
        break;
    case 2:
        s0->unk568 = 0x1E;
        s0->unk56A = 0xF;
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x110, (cObj *)s0, 0, 0, 0, 0);
        s0->nullSpeed.x = fRand1_1() * 0.200000003f;
        s0->nullSpeed.y = 0.100000001f;
        s0->nullSpeed.z = -0.100000001f;
        s0->step = s0->step + 1;
        /* fallthrough */
    case 3:
        cObjBase_MoveByNullSpeed(s0, s0->rot.y, 1.0f);
        {
        float k = 0.0199999996f;
        s0->rot.x = s0->rot.x + -0.17453292f;
        VU0_LQC2(4, s0, 0x330);
        VU0_LOAD_SCALAR(5, k);
        VU0_VSUBX_XYZ(4, 4, 5);
        VU0_SQC2(4, s0, 0x330);
        }
        if (s0->unk568 < 0xF) {
            s0->tint.w = s0->tint.w - 0.100000001f;
            s0->objFlags |= 0x10;
            if (s0->tint.w <= 0.150000006f) {
                s0->tint.w = 0.0f;
                s0->objFlags |= 2;
                *(unsigned int *)((char *)s0 + 0x250) &= 0xFFFFFFEF;
            }
        }
        if (s0->unk56A != 0) {
            s0->unk56A = *(unsigned short *)((char *)s0 + 0x56A) - 1;
            if (s0->unk56A == 0) {
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x32, (cObj *)s0, 0, 0, 0, 0);
            }
        }
        if (s0->unk568 != 0) {
            s0->unk568 = *(unsigned short *)((char *)s0 + 0x568) - 1;
        } else {
            s0->step = 0;
            s0->mode = 1;
        }
        break;
    }
}

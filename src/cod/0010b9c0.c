/* sn-2.95.3-136 matched TU. */

extern float SetMotionStep(void *a0, float f12);
#include "godhand/cCollisionSolid.h"
#include "godhand/cSnd.h"
#include "godhand/effectPos.h"
#include "godhand/motion.h"
extern int moveMotion(void *a0);
extern float fRand1_1(void);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);
extern unsigned int irand(void);
extern void func_0012C348(void *a0, int a1);

#include "godhand/vu0.h"
#include "godhand/cGameObj.h"














__attribute__((section(".text.func_0010B9C0")))
void func_0010B9C0(void *a0)
{
    cVec fr;
    cGameObj *s0 = a0;

    s0->hitFlash = 5.0f;
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s0, 0);
    *(int *)((char *)s0 + 0x15F4) |= 0x2000;
    s0->speedRate = 1.0f;
    SetMotionStep(s0, 1.0f);
    switch (s0->step) {
    case 0: {
        int p = *(int *)((char *)s0 + 0x304);

        func_002A8578(s0, *(int *)(p + 0x28) + p, *(int *)(p + 0x2C) + p,
                      5, 0.0f, 0, 0);
        s0->step = s0->step + 1;
    }
    /* fallthrough */
    case 1:
        moveMotion(s0);
        break;
    case 2: {
        int f1, f2;

        switch (s0->stepArg) {
        case 1:
            {
                int p = *(int *)((char *)s0 + 0x304);

                f1 = *(int *)(p + 0x94C) + p;
                f2 = *(int *)(p + 0x950) + p;
            }
            break;
        case 2:
            {
                int p = *(int *)((char *)s0 + 0x304);

                f1 = *(int *)(p + 0x94C) + p;
                f2 = *(int *)(p + 0x950) + p;
            }
            break;
        case 3:
            {
                int p = *(int *)((char *)s0 + 0x304);

                f1 = *(int *)(p + 0x94C) + p;
                f2 = *(int *)(p + 0x950) + p;
            }
            break;
        default:
        case 0:
            {
                int p = *(int *)((char *)s0 + 0x304);

                f1 = *(int *)(p + 0x94C) + p;
                f2 = *(int *)(p + 0x950) + p;
            }
            break;
        }
        func_002A8578(s0, f1, f2, 3, 0.0f, 0, 0);
        s0->unk568 = 1;
        s0->step = s0->step + 1;
    }
    /* fallthrough */
    case 3:
        if (moveMotion(s0) != 0)
            s0->step = 0;
        if ((s0->seqFlags & 3) &&
            s0->unk568 != 0) {
            float k;

            VU0_SQC2_VF0(&fr, 0);
            k = 0.1f;
            fr.x = fRand1_1() * k + -0.2f;
            fr.y = fRand1_1() * k + 1.5f;
            fr.z = fRand1_1() * k + 0.5f;
            sceVu0ApplyMatrix(&fr, (char *)s0 + 0x80, &fr);
            s0->unk568 = 0;
            SetEffectPos(0, 0x40, 0, &fr, 1.0f, -1);
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x111, a0, 0, 0, 0, 0);
        }
        break;
    case 4: {
        int f1, f2;

        switch (irand() % 3) {
        default:
        case 0:
            {
                int p = *(int *)((char *)s0 + 0x304);

                f1 = *(int *)(p + 0x140) + p;
                f2 = *(int *)(p + 0x144) + p;
            }
            break;
        case 1:
            {
                int p = *(int *)((char *)s0 + 0x304);

                f1 = *(int *)(p + 0x4DC) + p;
                f2 = *(int *)(p + 0x4E0) + p;
            }
            break;
        case 2:
            {
                int p = *(int *)((char *)s0 + 0x304);

                f1 = *(int *)(p + 0x4E4) + p;
                f2 = *(int *)(p + 0x4E8) + p;
            }
            break;
        }
        func_002A8578(s0, f1, f2, 1, 0.0f, 0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xCE, a0, 0, 0, 0, 0);
        func_0012C348(s0, 0);
        s0->step = s0->step + 1;
    }
    /* fallthrough */
    case 5:
        if (moveMotion(s0) != 0)
            s0->step = 0;
        break;
    default:
        break;
    }
}

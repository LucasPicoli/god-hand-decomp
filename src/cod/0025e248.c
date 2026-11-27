/* sn-2.95.3-136 matched TU. */

extern void SetMotionStep(void *a0, float f12);
#include "godhand/cCollisionSolid.h"
#include "godhand/effectPos.h"
#include "godhand/motion.h"
extern void func_00281560(int a0, int a1);
extern void func_00283438(int a0, int a1);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern float fRand1_1(void);
extern float fRand0_1(void);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);

#include "godhand/vu0.h"
#include "godhand/cGameObj.h"
#include "godhand/cEm00.h"
#include "godhand/player.h"



















__attribute__((section(".text.func_0025E248")))
void func_0025E248(void *a0)
{
    cEm00 *s0 = a0;
    cGameObj *s1;
    cVec buf __attribute__((aligned(16)));
    float v;

    s1 = Getplayer();
    v = s1->speedRate;
    s0->speedRate = v;
    SetMotionStep(s0, v);
    s0->hitFlash = 3.0f;
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s0, 0);
    switch (s0->step) {
    case 0: {
        int w = EM_RES(s0);
        func_002A8578(s0, *(int *)(w + 0x3E4C) + w, *(int *)(w + 0x3E50) + w,
                      0, 0.0f, 0, 0);
        if (s0->sub0 != 0)
            func_00281560(s0->sub0, 0);
        if (s0->sub1 != 0)
            func_00283438(s0->sub1, 0);
        if (s0->sub2 != 0)
            func_00283438(s0->sub2, 0);
        s0->unk56A = 0;
        s0->step = s0->step + 1;
        goto phase1;
    }
    case 2: {
        int w = EM_RES(s0);
        func_002A8578(s0, *(int *)(w + 0x3E54) + w, *(int *)(w + 0x3E58) + w,
                      0, 0.0f, 0, 0);
        if (s0->sub0 != 0)
            func_00281560(s0->sub0, 1);
        if (s0->sub1 != 0)
            func_00283438(s0->sub1, 1);
        if (s0->sub2 != 0)
            func_00283438(s0->sub2, 1);
        s0->step = s0->step + 1;
    }
    /* fallthrough */
    case 1:
    case 3:
    phase1:
        moveMotion(s0);
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        s0->step = s1->step;
        break;
    case 4: {
        int w = EM_RES(s0);
        func_002A8578(s0, *(int *)(w + 0x3E5C) + w, *(int *)(w + 0x3E60) + w,
                      0, 0.0f, 0, 0);
        if (s0->sub0 != 0)
            func_00281560(s0->sub0, 2);
        if (s0->sub1 != 0)
            func_00283438(s0->sub1, 2);
        if (s0->sub2 != 0)
            func_00283438(s0->sub2, 2);
        s0->step = s0->step + 1;
    }
    /* fallthrough */
    case 5:
        if (moveMotion(s0))
            func_002705D8(s0);
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    default:
        break;
    }

    if (s0->seqFlags & 3) {
        if (s0->seqFlags & 1) {
            VU0_SQC2_VF0(&buf, 0);
            buf.x = fRand1_1() * 0.1f;
            buf.y = fRand1_1() * 0.1f + 1.5f;
            buf.z = fRand0_1() * 0.1f + 0.7f;
            sceVu0ApplyMatrix(&buf, s1->mtx, &buf);
            SetEffectPos(0, 0x4F, 0, &buf, 1.0f, -1);
        }
        if (s0->unk56A != 0) {
            if (s0->seqFlags & 1) {
                CEM00_VCALL(s0, hit, 0x14, s1, 0, 0);
                if (s0->hp <= 0)
                    s0->hp = 1;
                cHeatSys_AddHeatGage(&D_005CB000, 0, 0.5f);
            }
            if (s0->seqFlags & 2) {
                CEM00_VCALL(s0, hit, 0xC8, s1, 0, 0);
                cHeatSys_AddHeatGage(&D_005CB000, 0, 0.5f);
            }
        }
        s0->unk56A = 0;
    } else {
        s0->unk56A = 1;
    }
}

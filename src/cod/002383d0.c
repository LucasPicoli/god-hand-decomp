/* sn-2.95.3-136 matched TU. */

/* func_002383D0, 996 B, sn-2.95.3-136. Wave 2026-08-31 V2 h2 + a block-local base pointer per if/else arm (pa1..pa4) so local-alloc takes the base first. */
#include "godhand/cCollisionSolid.h"
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cGameObj.h"

extern int D_007474A8;

extern int Getplayer();
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern float SetMotionStep(void *a0, float f);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f12);
extern void cObjBase_addNullSpeed(void *a0, float f12);

__attribute__((section(".text.func_002383D0")))
void func_002383D0(cEm00 *self)
{
    cEm00 *s0 = self;
    cGameObj *s3;
    char *s1;
    char *s2;

    s3 = (char *)Getplayer();
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s0, 0);
    switch (s0->step) {
    case 0:
    {
        int t8;
        char *pp;
        int n;

        *(char *)((char *)s0 + 0x1864) = 0;
        t8 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        if (s0->stepArg != 0) {
            char *pa1 = s0->pack;
            s2 = (char *)(*(int *)(pa1 + 0x2B24) + (int)pa1);
            s1 = (char *)(*(int *)(pa1 + 0x2B28) + (int)pa1);
        } else {
            char *pa2 = s0->pack;
            s2 = (char *)(*(int *)(pa2 + 0x2B40) + (int)pa2);
            s1 = (char *)(*(int *)(pa2 + 0x2B44) + (int)pa2);
        }
        func_002A8578(s0, (int)s2, (int)s1, 0, 0.0f, t8, 0);
        StoreMotionParamsBoth_2609A8(self, 4, 0, 0x3D, -1, 0);
        s0->unk56A = 0;
        *(short *)((char *)s0 + 0x56C) = 0;
        s0->unk568 = 0x3C;
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1: default: n = 0xF; break;
        case 2: n = 0x14; break;
        case 3: case 4: n = 0x19; break;
        case 5: n = 0x1E; break;
        }
        if ((s0->emFlags2 & 0x4000000) != 0) {
            n = n + 5;
        }
        if (n >= 0x24) {
            n = 0x23;
        }
        s0->timerA = 0xF;
        *(short *)((char *)s0 + 0x56E) = n;
        (s0->step)++;
    }
        /* fallthrough */
    case 1:
        if (s0->timerA != 0) {
            char *p;
            char *q;

            s0->timerA = s0->timerA - 1;
            p = *(char **)((char *)s0 + 0xF0);
             
            q = (char *)s3 + 0x550;
            VU0_VADD_XYZ_IP(p, 0x0, q);
        }
        s0->hitFlash = 5.0f;
        if ((s0->emFlags2 & 0x4000000) != 0) {
            SetMotionStep(s0, s0->speedRate * 3.0f);
        } else {
            SetMotionStep(s0,
                s0->speedRate + s0->speedRate);
        }
        moveMotion(s0);
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        {
            int t = *(unsigned short *)((char *)s0 + 0x568) - 1;

            s0->unk568 = t;
            if ((short)t <= 0) {
                *(char *)((char *)s0 + 0x2F6) = 2;
                *(char *)((char *)s3 + 0x2F6) = 4;
                if (s0->unk56A >= *(short *)((char *)s0 + 0x56E)) {
                    *(short *)((char *)s3 + 0x56C) = 1;
                } else {
                    *(short *)((char *)s0 + 0x56C) = 1;
                }
            } else {
                if (s3->hp > 0) {
                    if ((D_007474A8 & 0xF0) != 0) {
                        int m = *(unsigned short *)((char *)s0 + 0x56A) + 1;

                        s0->unk56A = m;
                        if ((short)m == 5) {
                            *(char *)((char *)s3 + 0x2F6) = 2;
                            s0->unk568 = 0x3C;
                        }
                    }
                }
            }
        }
        break;
    case 2:
    {
        int t8;
        char *pp;

        if (s0->stepArg != 0) {
            char *pa3 = s0->pack;
            s2 = (char *)(*(int *)(pa3 + 0x2B2C) + (int)pa3);
            s1 = (char *)(*(int *)(pa3 + 0x2B30) + (int)pa3);
        } else {
            char *pa4 = s0->pack;
            s2 = (char *)(*(int *)(pa4 + 0x2B48) + (int)pa4);
            s1 = (char *)(*(int *)(pa4 + 0x2B4C) + (int)pa4);
        }
        t8 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        func_002A8578(s0, (int)s2, (int)s1, 0, 0.0f, t8, 0);
        StoreMotionParamsBoth_2609A8(self, 0x3C, 0, 0x41, -1, 0);
        s0->timerA = 0xF;
        s0->hitFlash = 2.0f;
        (s0->step)++;
    }
        /* fallthrough */
    case 3:
        if (s0->timerA != 0) {
            char *p;
            char *q;

            q = (char *)s3 + 0x550;
            s0->timerA = s0->timerA - 1;
            p = *(char **)((char *)s0 + 0xF0);
            VU0_VADD_XYZ_IP(p, 0x0, q);
        }
        if (*(short *)((char *)s0 + 0x56C) != 0) {
            s0->hitFlash = 5.0f;
        }
        if (moveMotion(s0) != 0) {
            *(char *)((char *)s0 + 0x2F4) = 0;
            *(char *)((char *)s0 + 0x2F5) = 0x6C;
            *(char *)((char *)s0 + 0x2F6) = 0;
            *(char *)((char *)s0 + 0x2F7) = 0;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    default:
        break;
    }
    func_00260B30(self);
}

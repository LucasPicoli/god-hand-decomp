#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern unsigned char D_00462FC0[];
extern unsigned char D_005FEE00[];
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern float fRand0_1(void);
extern void cGameObj_SetTgtTurn(void *a0, void *a1, float a2);
extern void SetEffectPos(int a0, int a1, int a2, void *a3, int a4, float a5);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002705D8(void *a0);
extern void func_00260B30(void *a0);

/* sn-2.95.3-136 matched TU. */

















/* Phase machine on the step byte, 6 case labels. Calls cCollisionSolidManage_SetActive,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, func_002A8578, moveMotion, cObjBase_addNullSpeed_Rotation,
 * cObjBase_addNullSpeed and 7 more. */
__attribute__((section(".text.func_002448E0"))) void func_002448E0(cEm00 *self)
{
    cCollisionSolidManage_SetActive(&D_00462FC0, self, 0);
    switch (self->step) {
        case 0: {
            int gb;
            char *v1;

            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            v1 = (char *)self->resource;
            func_002A8578(self, EM_RES_REC((int)v1, 0xD70), EM_RES_REC((int)v1, 0xD74), 0.0f, 3, gb,
                          0);
            self->step += 1;
        }
            /* fallthrough */
        case 1:
            self->hitFlash = 2.0f;
            *(unsigned short *)((char *)self + 0x434) =
                *(unsigned short *)((char *)self + 0x434) | 8;
            if (moveMotion(self) != 0) {
                self->step += 1;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 2:
            self->timer = fRand0_1() * 45.0f + 90.0f;
            *(int *)((char *)self + 0x4A8) = *(int *)((char *)self + 0x4A8) | 0x80000000;
            *(float *)((char *)self + 0x608) = 3.0f;
            self->step += 1;
            *(int *)((char *)self + 0x604) = 0;
            /* fallthrough */
        case 3:
            *(char *)((char *)self + 0x617) = 1;
            *(char *)((char *)self + 0x623) = 1;
            self->hitFlash = 2.0f;
            *(char *)((char *)self + 0x531) = -1;
            cGameObj_SetTgtTurn(self, &self->unk16A0, self->speedRate * 0.09817477f);
            *(unsigned short *)((char *)self + 0x434) =
                *(unsigned short *)((char *)self + 0x434) | 8;
            moveMotion(self);
            if (self->playerDist > 1.0f) {
                *(int *)((char *)self + 0x330) = 0;
                *(int *)((char *)self + 0x334) = 0;
                self->stepVec.z = self->speedRate * 0.1f;
            } else {
                *(int *)((char *)self + 0x330) = 0;
                *(int *)((char *)self + 0x334) = 0;
                *(int *)((char *)self + 0x338) = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            self->timer = self->timer - self->speedRate;
            if (self->timer <= 0.0f) {
                self->step = 4;
                break;
            }
            self->timer2 = self->timer2 - self->speedRate;
            if (self->timer2 <= 0.0f) {
                SetEffectPos(0x58, 0x9C, 0, (void *)self->pos, -1, 1.0f);
                self->timer2 = 6.0f;
            }
            if (*(int *)((char *)self + 0x474) != 1 && *(int *)((char *)self + 0x474) != 9) {
                self->step = 4;
            }
            *(float *)((char *)self + 0x608) = *(float *)((char *)self + 0x608) - self->speedRate;
            if (*(float *)((char *)self + 0x608) <= 0.0f) {
                *(float *)((char *)self + 0x608) = 15.0f;
                cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xFB, self, 0, 0, 0, 0);
            }
            break;
        case 4: {
            int gb;
            int s2v, s1v;

            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            if ((self->emNo ^ 0x20F) != 0) {
                char *w = (char *)self->resource;
                s2v = EM_RES_REC((int)w, 0xDA8);
                s1v = EM_RES_REC((int)w, 0xDAC);
                StoreMotionParamsBoth_2609A8(self, 0x14, 0x23, 0x37, -1, 0);
            } else {
                char *w = (char *)self->resource;
                s2v = EM_RES_REC((int)w, 0xD78);
                s1v = EM_RES_REC((int)w, 0xD7C);
            }
            func_002A8578(self, s2v, s1v, 0.0f, 3, gb, 0);
            *(float *)((char *)self + 0x1744) = 300.0f;
            *(char *)((char *)self + 0x531) = 3;
            *(int *)((char *)self + 0x4A8) = *(int *)((char *)self + 0x4A8) & 0x7FFFFFFF;
            self->hitFlash = 5.0f;
            self->step += 1;
            *(char *)((char *)self + 0x623) = 0;
        }
            /* fallthrough */
        case 5:
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            func_00260B30(self);
            break;
    }
}

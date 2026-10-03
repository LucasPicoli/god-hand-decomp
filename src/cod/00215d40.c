/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"

extern unsigned int irand(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void cGameObj_SetTgtTurn(void *a0, int a1, float f12);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern void func_002705D8(void *a0);
extern void func_00262AA8(void *a0);

/* Phase machine on the step byte, 6 case labels. Calls irand, Obj0000_Get_Byte_17C3_NZ_2_276468,
 * func_002A8578, cGameObj_SetTgtTurn, moveMotion, cObjBase_addNullSpeed_Rotation and 5 more. */
__attribute__((section(".text.func_00215D40"))) void func_00215D40(cEm00 *self)
{
    self->emFlags |= 0x400;
    switch (self->step) {
        case 0: {
            int w;
            int r;
            *(int *)((char *)self + 0x17D0) = irand() % 5;
            r = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
            w = self->resource;
            func_002A8578(self, EM_RES_REC(w, 0x1934), EM_RES_REC(w, 0x1938), 0.0f, 0xA, r & 0xFFFF,
                          0);
            self->step++;
        }
        /* fallthrough */
        case 1:
            cGameObj_SetTgtTurn(self, (int)(&self->unk16A0), self->speedRate * 0.09817477f);
            if (moveMotion(self))
                self->step++;
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 2: {
            int w;
            int r = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
            w = self->resource;
            func_002A8578(self, EM_RES_REC(w, 0x193C), EM_RES_REC(w, 0x1940), 0.0f, 0xA, r & 0xFFFF,
                          0);
            self->stepArg = irand() & 1;
            self->step++;
        }
        /* fallthrough */
        case 3: {
            float d;
            cGameObj_SetTgtTurn(self, (int)(&self->unk16A0), self->speedRate * 0.19634954f);
            moveMotion(self);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5)
                self->stepVec.z = self->speedRate * 0.6f;
            else
                self->stepVec.z = self->speedRate * 0.3f;
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            d = Turn_dest((void *)self->pos, ((char *)self + 0x1690), self->rot.y, 3.14159274f);
            if (d < 0.0f)
                d = -d;
            if (self->stepArg) {
                if (self->playerDist < 25.0f)
                    func_002705D8(self);
            }
            if (1.5707964f < d || self->playerDist < 6.25f)
                func_002705D8(self);
            break;
        }
        case 4: {
            int w;
            int r = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
            w = self->resource;
            func_002A8578(self, EM_RES_REC(w, 0x1944), EM_RES_REC(w, 0x1948), 0.0f, 0xA, r & 0xFFFF,
                          0);
            self->step++;
        }
        /* fallthrough */
        case 5:
            if (moveMotion(self))
                func_002705D8(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        default:
            break;
    }
    func_00262AA8(self);
}

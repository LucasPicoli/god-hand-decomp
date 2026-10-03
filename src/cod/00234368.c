/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"

extern unsigned int irand(void);
extern void CheckSlotsShort2FEAndSetByte1864_262A10(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f12, int a3, int t0, int t1);
extern void Obj1D00_SetState_7_2(int a0);
extern void Obj1D00_SetState_7_A_a1(int a0, int a1);
extern void Obj1D00_SetState_7_6(int a0);
extern void Obj1D00_SetState_7_4(int a0);
extern void Obj1D00_SetState_7_8(int a0);
extern void Obj1D00_SetState_7_18(int a0);
extern void Obj1D00_ClearState_7(int a0);
extern int Getplayer(void);
extern void cGameObj_SetTgtTurn(void *a0, int a1, float f12);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_0026BEF0(void *a0, int a1, int a2);
extern void func_002705D8(void *a0);
extern void func_002744E0(void *a0);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern char D_005FEE00[];

/* Phase machine on the step byte, 14 case labels. Calls irand,
 * CheckSlotsShort2FEAndSetByte1864_262A10, Obj0000_Get_Byte_17C3_NZ_2_276468, func_002A8578,
 * Obj1D00_SetState_7_2, cGameObj_SetTgtTurn and 15 more. */
__attribute__((section(".text.func_00234368"))) void func_00234368(cEm00 *self)
{
    self->unk186A = 2;
    self->emFlags2 |= 0x400;
    if (self->step == 0 && (irand() & 3) == 0)
        self->step = 8;
    CheckSlotsShort2FEAndSetByte1864_262A10(self);
    switch (self->step) {
        case 0: {
            int t;
            int w;
            int p;
            self->unk1864 = 0;
            t = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            w = self->resource;
            func_002A8578(self, EM_RES_REC(w, 0x2F24), EM_RES_REC(w, 0x2F28), 0.0f, 0xA, t, 0);
            p = *(int *)((char *)self + 0x708);
            if (p != 0)
                Obj1D00_SetState_7_2(p);
            self->timerB = 1;
            self->step++;
        }
        /* fallthrough */
        case 1:
            cGameObj_SetTgtTurn(self, *(int *)(Getplayer() + 0xF0), self->speedRate * 0.09817477f);
            if (moveMotion(self))
                self->step++;
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        default:
            break;
        case 2: {
            int t;
            int lo;
            int hi;
            int r;
            self->unk1864 = 0;
            t = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            r = irand() & 1;
            self->stepArg = r;
            switch ((unsigned char)r) {
                default:
                case 0: {
                    int w = self->resource;
                    int p = *(int *)((char *)self + 0x708);
                    lo = EM_RES_REC(w, 0x2F4C);
                    hi = EM_RES_REC(w, 0x2F50);
                    if (p != 0)
                        Obj1D00_SetState_7_6(p);
                    break;
                }
                case 1: {
                    int w = self->resource;
                    lo = EM_RES_REC(w, 0x2F54);
                    hi = EM_RES_REC(w, 0x2F58);
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        int p = *(int *)((char *)self + 0x708);
                        int w2 = self->resource;
                        hi = EM_RES_REC(w2, 0x2F5C);
                        if (p != 0)
                            Obj1D00_SetState_7_A_a1(p, 1);
                    } else {
                        int p = *(int *)((char *)self + 0x708);
                        if (p != 0)
                            Obj1D00_SetState_7_A_a1(p, 0);
                    }
                    break;
                }
            }
            func_002A8578(self, lo, hi, 0.0f, 3, t, 0);
            self->step++;
        }
        /* fallthrough */
        case 3: {
            unsigned short fl;
            cGameObj_SetTgtTurn(self, *(int *)(Getplayer() + 0xF0), self->speedRate * 0.09817477f);
            if (moveMotion(self)) {
                if (36.0f < self->playerDist)
                    self->step = 6;
                else
                    self->step = 4;
                if (cCoreSave_getGameLevel(&D_00569B70) >= 2 && (irand() & 1))
                    self->step = 2;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            fl = self->moveFlags;
            if ((fl & 3) == 0)
                goto set5F4;
            if (self->timerB != 0) {
                self->timerB = 0;
                switch (self->stepArg) {
                    default:
                    case 0:
                        if ((fl & 2) != 0)
                            goto call13;
                        goto call0D;
                    case 1:
                        goto call13;
                }
            }
            break;
        }
        case 4: {
            int t;
            int w;
            int p;
            self->unk1864 = 0;
            t = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            w = self->resource;
            func_002A8578(self, EM_RES_REC(w, 0x2F2C), EM_RES_REC(w, 0x2F30), 0.0f, 3, t, 0);
            p = *(int *)((char *)self + 0x708);
            if (p != 0)
                Obj1D00_SetState_7_4(p);
            self->step++;
        }
        /* fallthrough */
        case 5:
            cGameObj_SetTgtTurn(self, *(int *)(Getplayer() + 0xF0), self->speedRate * 0.09817477f);
            if (moveMotion(self)) {
                int p;
                cObjBase_addNullSpeed_Rotation(self, 1.0f);
                cObjBase_addNullSpeed(self, 1.0f);
                func_002705D8(self);
                p = *(int *)((char *)self + 0x708);
                if (p != 0)
                    Obj1D00_ClearState_7(p);
            } else {
                cObjBase_addNullSpeed_Rotation(self, 1.0f);
                cObjBase_addNullSpeed(self, 1.0f);
            }
            break;
        case 6: {
            int t;
            int w;
            int p;
            self->unk1864 = 0;
            t = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            w = self->resource;
            func_002A8578(self, EM_RES_REC(w, 0x2F9C), EM_RES_REC(w, 0x2FA0), 0.0f, 3, t, 0);
            p = *(int *)((char *)self + 0x708);
            if (p != 0)
                Obj1D00_SetState_7_8(p);
            self->timerA = 1;
            self->step++;
        }
        /* fallthrough */
        case 7:
            cGameObj_SetTgtTurn(self, *(int *)(Getplayer() + 0xF0), self->speedRate * 0.09817477f);
            if (moveMotion(self))
                self->step = 4;
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if ((self->moveFlags & 3) && self->timerA != 0) {
                self->timerA = 0;
                func_002744E0(self);
            }
            break;
        case 8: {
            int t;
            int w;
            int p;
            self->unk1864 = 0;
            t = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            w = self->resource;
            func_002A8578(self, EM_RES_REC(w, 0x2F40), EM_RES_REC(w, 0x2F44), 0.0f, 0xA, t, 0);
            p = *(int *)((char *)self + 0x708);
            if (p != 0)
                Obj1D00_SetState_7_18(p);
            self->timerB = 1;
            self->step++;
        }
        /* fallthrough */
        case 9:
            cGameObj_SetTgtTurn(self, *(int *)(Getplayer() + 0xF0), self->speedRate * 0.09817477f);
            if (moveMotion(self)) {
                self->mode = 0;
                self->phase = 0x6C;
                self->step = 0;
                self->stepArg = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if ((self->moveFlags & 3) == 0)
                goto set5F4;
            if (self->timerB != 0) {
                self->timerB = 0;
                cSnd_SeCall_2CBA48(D_005FEE00, 1, 0x25, self, 0, 0, 0, 0);
                if (self->moveFlags & 2) {
                call13:
                    func_0026BEF0(self, 0x13, 0);
                    func_0026BEF0(self, 0x13, 1);
                    func_0026BEF0(self, 0x13, 2);
                    func_0026BEF0(self, 0x13, 3);
                    func_0026BEF0(self, 0x13, 4);
                } else {
                call0D:
                    func_0026BEF0(self, 0xD, 0);
                }
            }
            break;
    }
    return;
set5F4:
    self->timerB = 1;
}

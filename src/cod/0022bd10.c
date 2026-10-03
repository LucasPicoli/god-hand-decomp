/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"

extern unsigned char D_005FEE00[];
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern unsigned int irand(void);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void *Getplayer(void);
extern void cGameObj_SetTgtTurn(void *a0, void *a1, float a2);
extern int moveMotion(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void func_0026BBD0(void *a0, int a1);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);

/* sn-2.95.3-136 matched TU. */

















struct Bf { signed char v : 8; };

/* Phase machine on the step byte, 11 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468, irand,
 * cCoreSave_getGameLevel, func_002A8578, Getplayer, cGameObj_SetTgtTurn and 7 more. */
__attribute__((section(".text.func_0022BD10"))) void func_0022BD10(cEm00 *self)
{
    self->unk186A = 2;
    self->emFlags = self->emFlags | 0x400;
    self->emFlags2 = self->emFlags2 | 0x400;
    switch (self->step) {
        case 0: {
            int gb;
            char *v1;
            cCoreSave *s4;
            int s2v, s1v;
            int t;
            int one;
            int raw;
            unsigned char b;

            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            self->stepArg = irand() & 1;
            v1 = (char *)self->resource;
            s4 = &D_00569B70;
            s2v = EM_RES_REC((int)v1, 0x2330);
            s1v = EM_RES_REC((int)v1, 0x2334);
            if (cCoreSave_getGameLevel(s4) == 5) {
                char *w = (char *)self->resource;
                s1v = EM_RES_REC((int)w, 0x2338);
            }
            func_002A8578(self, s2v, s1v, 0.0f, 3, gb, 0);
            one = 1;
            self->timerC = 0;
            self->timer2 = 35.0f;
            self->timerA = one;
            self->unk568 = one;
            switch (cCoreSave_getGameLevel(s4)) {
                case 1:
                default:
                    if ((irand() & 1) != 0) {
                        self->unk568 = 2;
                    }
                    break;
                case 2:
                    self->unk568 = 2;
                    if ((irand() & 1) != 0) {
                        self->unk568 = 3;
                    }
                    break;
                case 3:
                case 4:
                    self->unk568 = 2;
                    if ((irand() & 1) != 0) {
                        self->unk568 = 4;
                    }
                    break;
                case 5:
                    self->unk568 = 4;
                    break;
            }
            if ((char)*(unsigned char *)((char *)self + 0x1869) < self->unk568) {
                self->unk568 = (char)*(unsigned char *)((char *)self + 0x1869);
            }
            self->step += 1;
        }
            /* fallthrough */
        case 1: {
            char *p;

            self->emFlags = self->emFlags | 0x800000;
            p = (char *)Getplayer();
            cGameObj_SetTgtTurn(self, *(void **)(p + 0xF0), self->speedRate * 0.19634955f);
            if (moveMotion(self) != 0) {
                self->step = 2;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        }
        case 2: {
            int gb;
            char *v1;
            int s2v, s1v;
            int r;

            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            self->stepArg = irand() & 1;
            v1 = (char *)self->resource;
            s2v = EM_RES_REC((int)v1, 0x233C);
            s1v = EM_RES_REC((int)v1, 0x2340);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                char *w = (char *)self->resource;
                s1v = EM_RES_REC((int)w, 0x2344);
            }
            func_002A8578(self, s2v, s1v, 0.0f, 3, gb, 0);
            self->timerC = 0;
            self->timerA = 1;
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0x23, self, 0, 0, 0, 0);
            self->unk568 = self->unk568 - 1;
            if (*(char *)((char *)self + 0x1869) > 0) {
                r = func_0026AA30(self, 0x36A);
                if (r != 0) {
                    func_0026BBD0(self, r);
                }
            }
            self->step += 1;
        }
            /* fallthrough */
        case 3: {
            char *p;

            p = (char *)Getplayer();
            cGameObj_SetTgtTurn(self, *(void **)(p + 0xF0), self->speedRate * 0.19634955f);
            if (moveMotion(self) != 0) {
                if (self->unk568 > 0) {
                    self->step = 2;
                } else {
                    self->step = 4;
                }
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        }
        case 4: {
            int gb;
            char *v1;
            int s2v, s1v;

            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            self->stepArg = irand() & 1;
            v1 = (char *)self->resource;
            s2v = EM_RES_REC((int)v1, 0x2348);
            s1v = EM_RES_REC((int)v1, 0x234C);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                char *w = (char *)self->resource;
                s1v = EM_RES_REC((int)w, 0x2350);
            }
            func_002A8578(self, s2v, s1v, 0.0f, 3, gb, 0);
            self->step += 1;
        }
            /* fallthrough */
        case 5: {
            char *p;

            p = (char *)Getplayer();
            cGameObj_SetTgtTurn(self, *(void **)(p + 0xF0), self->speedRate * 0.19634955f);
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        }
    }
    if (self->moveFlags & 3) {
        self->timerC = 1;
    }
    if (self->timerC != 0) {
        self->emFlags2 = self->emFlags2 & 0xFFFFFBFF;
    }
}

/* sn-2.95.3-136 matched TU. */

/* cEm00_stepGetUp: an enemy that goes down and gets up; steps 0 and 2 start a
 * get-up motion, step 1 and 3 wait for it to end. */
#include "godhand/cEm00.h"

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void *Getplayer(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_00281470(int a0, unsigned char a1);
extern void func_00283378(int a0, unsigned char a1);


extern void func_002705D8(void *a0);

__attribute__((section(".text.cEm00_stepGetUp")))
void cEm00_stepGetUp(cEm00 *self)
{
    void *player;
    int motion;

    player = Getplayer();
    switch (self->step) {
    case 0: {
        int res;
        int p1;
        int p2;

        motion = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        res = self->resource;
        p1 = EM_RES_REC(res, 0x3E34);
        p2 = EM_RES_REC(res, 0x3E38);
        self->emFlags = self->emFlags & 0xFEFFFFFF;
        *(int *)&self->unk16F4 = 0;
        func_002A8578(self, p1, p2, self->unk16F4, 2, motion, 0);
        if (self->sub0 != 0) {
            func_00281470(self->sub0, 0);
        }
        if (self->sub1 != 0) {
            func_00283378(self->sub1, 0);
        }
        if (self->sub2 != 0) {
            func_00283378(self->sub2, 0);
        }
        self->unk568 = 1;
        self->unk5B4 = self->unk5B4 + 0x32;
        func_0026F120(self);
        self->step = self->step + 1;
    }
    case 1:
        self->hitFlash = 3.0f;
        if (self->unk17CC > 0.0f) {
            self->unk17CC = 150.0f;
        }
        if (moveMotion(self) != 0) {
            self->mode = 1;
            self->phase = 0xF;
            self->step = 4;
            self->stepArg = 0;
            if (self->vital < 2) {
                self->vital = 0;
            }
        }
        if ((self->moveFlags & 0x10) != 0 && self->vital >= 2 && func_0026F1D8(self) == 0) {
            self->step = self->step + 1;
        }
        break;
    case 2: {
        int res;
        int p1;
        int p2;

        motion = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        res = self->resource;
        p1 = EM_RES_REC(res, 0x3E3C);
        p2 = EM_RES_REC(res, 0x3E40);
        *(int *)&self->unk16F4 = 0;
        func_002A8578(self, p1, p2, self->unk16F4, 2, motion, 0);
        if (self->sub0 != 0) {
            func_00281470(self->sub0, 1);
        }
        if (self->sub1 != 0) {
            func_00283378(self->sub1, 1);
        }
        if (self->sub2 != 0) {
            func_00283378(self->sub2, 1);
        }
        self->unk568 = 1;
        func_0026F120(self);
        self->step = self->step + 1;
    }
    case 3:
        self->hitFlash = 3.0f;
        if (moveMotion(self) != 0) {
            func_002705D8(self);
        }
        break;
    }
    if ((self->moveFlags & 1) != 0 && self->unk568 != 0) {
        self->unk568 = 0;
        CEM00_VCALL(self, hit, 0xC8, player, 0, 0);
        if (self->vital <= 0) {
            self->vital = 1;
        }
    }
}

/* sn-2.95.3-136 matched TU. */

/* cEm00_stepPatrolAttackDrop: a patrolling enemy. It walks to the player (steps 0 to 5),
 * then picks one of three attack motions (steps 6 and 7), and on the drop
 * steps (8 to 13) it spawns its drop item once and winds down. */
#include "godhand/cEm00.h"
#include "godhand/vu0.h"

extern void func_002A8578(void *a0, int a1, int a2, float f12, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int func_00291010(void *a0, void *a1, void *a2, int a3, int t0, float f12, float f13, float f14);
extern int IsEntryActive_1C2490(int a0);
extern void func_0028FB08(void *a0);
extern void cModel_calcNullPart(void *a0);
extern void Add_nullspeed(void *a0);
extern void *Getplayer(void);
extern void cGameObj_SetTgtTurn(void *a0, void *a1, float f);
extern int irand(void);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern int cEmManage_CreateItem(void *a0, int a1, int a2, int a3);
extern void func_001C2280(void *a0, void *a1, int a2, void *a3, void *a4);
extern unsigned char D_005864F0[];
extern unsigned char D_005FEE00[];
extern int D_007476B0;

__attribute__((section(".text.cEm00_stepPatrolAttackDrop")))
void cEm00_stepPatrolAttackDrop(cEm00 *self)
{
    unsigned char fr[0x20] __attribute__((aligned(16)));
    int next;
    int item;
    cEm00 *player;

    if (self->step == 0 && (self->gotoFlags & 0x40) == 0 && self->playerDist < 100.0f) {
        float *q = (float *)self->pos;

        VU0_LQC2(4, q, 0);
        VU0_SQC2(4, fr, 0);
        if (func_00291010(D_005864F0, fr, 0, 1, 0, self->rot.y, 10.0f, 3.14159274f) == 0) {
            if ((self->gotoFlags & 4) == 0) {
                self->step = 8;
            } else {
                self->step = 6;
            }
        }
    }
    if (self->unk15C4 != 0 && IsEntryActive_1C2490(self->unk15C4) != 0) {
        self->unk15C4 = 0;
        func_0028FB08(self);
    }
    switch (self->step) {
    case 0: {
        int b = self->resource;

        func_002A8578(self, EM_RES_REC(b, 0x48), EM_RES_REC(b, 0x4C), 0.0f, 0xA, 0, 0);
        self->step = self->step + 1;
    }
    case 1:
        if (moveMotion(self) != 0) {
            self->step = self->step + 1;
        }
        cModel_calcNullPart(self);
        Add_nullspeed(self);
        break;
    case 2: {
        int b = self->resource;

        func_002A8578(self, EM_RES_REC(b, 0x28), EM_RES_REC(b, 0x2C), 0.0f, 0xA, 0, 0);
        self->step = self->step + 1;
    }
    case 3:
        self->gotoFlags = self->gotoFlags | 1;
        if (0.0f < self->animRate) {
            moveMotion(self);
            cModel_calcNullPart(self);
            Add_nullspeed(self);
        }
        if ((self->gotoFlags & 0x40) != 0) {
            return;
        }
        if ((D_007476B0 & 7) != (self->unk2FC & 7)) {
            return;
        }
        if (!(self->playerDist < 100.0f)) {
            return;
        }
        {
            float *q = (float *)self->pos;

            VU0_LQC2(4, q, 0);
            VU0_SQC2(4, fr, 0);
        }
        if (func_00291010(D_005864F0, fr, 0, 1, 0, self->rot.y, 10.0f, 3.14159274f) == 0) {
            self->step = self->step + 1;
        }
        break;
    case 4: {
        int b = self->resource;

        func_002A8578(self, EM_RES_REC(b, 0x30), EM_RES_REC(b, 0x34), 0.0f, 0xA, 0, 0);
        self->step = self->step + 1;
    }
    case 5:
        if ((self->moveFlags & 2) == 0) {
            player = Getplayer();
            cGameObj_SetTgtTurn(self, player->pos, self->speedRate * 0.049087386f);
        }
        if (moveMotion(self) != 0) {
            if ((self->gotoFlags & 4) == 0) {
                self->step = 8;
            } else {
                self->step = 6;
            }
        }
        cModel_calcNullPart(self);
        Add_nullspeed(self);
        break;
    case 6: {
        int rec;

        if (self->emNo == 0x2A7 || self->emNo == 0x2AB) {
            int b = self->resource;

            rec = *(int *)(b + 0xE0) + b;
        } else {
            switch ((unsigned int)irand() % 3) {
            case 1: {
                int b = self->resource;

                rec = *(int *)(b + 0xE8) + b;
                break;
            }
            case 0: {
                int b = self->resource;

                rec = *(int *)(b + 0xE0) + b;
                break;
            }
            case 2: {
                int b = self->resource;

                rec = *(int *)(b + 0xF0) + b;
                break;
            }
            default: {
                int b = self->resource;

                rec = *(int *)(b + 0xE0) + b;
                break;
            }
            }
        }
        cSnd_SeCall_2CBA48(D_005FEE00, 1, 0x5D, self, 0, 0, 0, 0);
        func_002A8578(self, rec, rec, 0.0f, 0xA, 0, 0);
        self->step = self->step + 1;
    }
    case 7:
        self->gotoFlags = self->gotoFlags | 1;
        player = Getplayer();
        cGameObj_SetTgtTurn(self, player->pos, self->speedRate * 0.049087386f);
        if (400.0f < self->playerDist) {
            return;
        }
        moveMotion(self);
        cModel_calcNullPart(self);
        Add_nullspeed(self);
        break;
    case 8: {
        int b = self->resource;

        func_002A8578(self, EM_RES_REC(b, 0xF8), EM_RES_REC(b, 0xFC), 0.0f, 0xA, 0, 0);
        self->step = self->step + 1;
    }
    case 9:
        player = Getplayer();
        cGameObj_SetTgtTurn(self, player->pos, self->speedRate * 0.049087386f);
        if (moveMotion(self) != 0) {
            self->step = self->step + 1;
        }
        cModel_calcNullPart(self);
        Add_nullspeed(self);
        if ((self->moveFlags & 1) == 0) {
            return;
        }
        if (self->unk15C4 != 0) {
            return;
        }
        item = cEmManage_CreateItem(D_005864F0, (int)self->pos, self->dropItem, 0);
        self->unk15C4 = item;
        if (item != 0) {
            VU0_SQC2_VF0(fr, 0x0);
            VU0_SQC2_VF0(fr, 0x10);
            *(int *)(fr + 0x0) = 0;
            *(int *)(fr + 0x4) = 0;
            *(int *)(fr + 0x8) = 0;
            *(int *)(fr + 0x10) = 0;
            *(int *)(fr + 0x14) = 0;
            *(int *)(fr + 0x18) = 0;
            func_001C2280((void *)item, self, 10, fr, fr + 0x10);
        }
        self->gotoFlags = self->gotoFlags | 4;
        func_0028FB08(self);
        return;
    case 10: {
        int b = self->resource;

        func_002A8578(self, EM_RES_REC(b, 0x100), EM_RES_REC(b, 0x104), 0.0f, 0xA, 0, 0);
        self->step = self->step + 1;
    }
    case 11:
        player = Getplayer();
        cGameObj_SetTgtTurn(self, player->pos, self->speedRate * 0.049087386f);
        moveMotion(self);
        cModel_calcNullPart(self);
        Add_nullspeed(self);
        if (self->unk15C4 != 0) {
            return;
        }
        self->step = self->step + 1;
        break;
    case 12: {
        int b = self->resource;

        func_002A8578(self, EM_RES_REC(b, 0x108), EM_RES_REC(b, 0x10C), 0.0f, 0xA, 0, 0);
        self->step = self->step + 1;
    }
    case 13:
        player = Getplayer();
        cGameObj_SetTgtTurn(self, player->pos, self->speedRate * 0.049087386f);
        if (moveMotion(self) != 0) {
            self->step = 6;
        }
        cModel_calcNullPart(self);
        Add_nullspeed(self);
        break;
    }
}

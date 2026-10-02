/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136, extern_jtbl D_0042BE40 */
#include "godhand/ColiseumBattle.h"

extern unsigned char D_00747470[];
extern int D_00747A84;
extern unsigned char D_00586AA5;
extern char D_005CAE50[];
extern int *D_003BD6E8;
extern ColiseumVtEnt D_003BE570[];
extern ColiseumVtEnt D_003BE710[];
extern int Getplayer(void);
extern void cCockPlBar_initData(void *bar);
extern void cCollisionScroll_SetLayerCollEnable(void *scroll, int layer, int on);
extern void displayScrollLayer(int layer, int on);
extern void classFADE_start(void *p, int b, int c, int d, unsigned int e, unsigned int f, int g);
extern void classFADE_kill(void *p);
extern void func_001EFFF8(ColiseumBattle *self);
extern void func_001F03E8(ColiseumBattle *self);
extern void func_001F0498(ColiseumBattle *self, float v0, int id, float *vec);
extern void func_001F2CF0(void *ui);
extern void func_001F2B28(void *ui, int n, int on);
extern void func_001F28F0(void *ui);
extern void func_001F2990(void *ui);
extern void NoOp_1F0490(ColiseumBattle *self);

extern void ColiseumBattle_UpdateCountdown(ColiseumBattle *self, int on);
extern void ColiseumBattle_PlCtrlOff(ColiseumBattle *self, int off);

/* Per-frame update of the result scene: runs the seven-step sequence that
 * sets the ring up, fades in, waits for the fight, then hands control back. */

__attribute__((section(".text.ColiseumBattle_Update")))
void ColiseumBattle_Update(ColiseumBattle *self)
{
    char *layers;
    char *player;
    int done;
    int alive;
    int hp;
    unsigned long bits;
    float vec[4];

    switch (self->state) {
    case 0:
        cCockPlBar_initData(D_003BD6E8 + 0x118);
        self->unkB90 = 0;
        layers = D_005CAE50;
        cCollisionScroll_SetLayerCollEnable(layers, 1, 0);
        cCollisionScroll_SetLayerCollEnable(layers, 2, 0);
        cCollisionScroll_SetLayerCollEnable(layers, 3, 0);
        cCollisionScroll_SetLayerCollEnable(layers, 4, 0);
        displayScrollLayer(4, 0);
        cCollisionScroll_SetLayerCollEnable(layers, 5, 0);
        cCollisionScroll_SetLayerCollEnable(layers, 6, 0);
        D_003BE570[self->ring.ringNo].pfn((char *)self + D_003BE570[self->ring.ringNo].delta);
        switch (self->ring.ringNo) {
        case 0x16:
            vec[0] = 0;
            vec[1] = 0;
            vec[2] = 0;
            vec[3] = 1.0f;
            func_001F0498(self, vec[0], 0x37B, vec);
            break;
        case 0x12:
        case 0x2B:
            cCollisionScroll_SetLayerCollEnable(D_005CAE50, 4, 1);
            displayScrollLayer(4, 1);
            break;
        }
        {
            long t = self->flags;

            if (((t >> 3) % 2L) != 0L) {
                func_001EFFF8(self);
            }
        }
        classFADE_start(D_00747470, 0, 0xA, 0, 0xFF000000u, 0, 0xF);
        self->state = self->state + 1;
        break;
    case 1:
        if (((D_00747470[0x1C] >> 2) & 1) != 0) {
            classFADE_kill(D_00747470);
            self->timer = 0x1E;
            self->state = self->state + 1;
        }
        break;
    case 2:
        if (self->timer != 0) {
            done = 0;
            self->timer = self->timer - 1;
        } else {
            done = 1;
        }
        if ((done & 0xFF) != 0) {
            func_001F2CF0(self->ui);
            self->timer = 0x3C;
            self->state = self->state + 1;
        }
        break;
    case 3:
        if (self->timer != 0) {
            done = 0;
            self->timer = self->timer - 1;
        } else {
            done = 1;
        }
        if ((done & 0xFF) != 0) {
            ColiseumBattle_PlCtrlOff(self, 0);
            self->state = self->state + 1;
        }
        break;
    case 4:
        alive = ColiseumBattle_CountLiveEnemies(self);
        /* int-pointee store: keeps this ahead of the D_00747A84 load, as retail orders them */
        *(int *)&self->unkB88 = self->enemyNum - alive;
        bits = D_00747A84;
        if (((bits >> 6) % 2UL) != 0UL) {
            func_001F2B28(self->ui, self->ring.unk0A - self->unkB88, 0);
        } else {
            func_001F2B28(self->ui, self->ring.unk0A - self->unkB88, 1);
        }
        D_003BE710[self->ring.ringNo].pfn((char *)self + D_003BE710[self->ring.ringNo].delta);
        player = (char *)Getplayer();
        hp = 0;
        if (player != 0) {
            hp = *(short *)(player + 0x54A);
        }
        if (hp == 0) {
            break;
        }
        if (self->ring.timeLimit != 0) {
            if (self->countdown != 0.0f) {
                if (self->unkB88 >= self->ring.unk0A) {
                    ColiseumBattle_PlCtrlOff(self, 1);
                    self->timer = 0x3C;
                    self->state = self->state + 1;
                } else {
                    ColiseumBattle_UpdateCountdown(self, 1);
                }
            } else {
                ColiseumBattle_PlCtrlOff(self, 1);
                D_00586AA5 = 1;
                *(float *)(player + 0x54C) = 1800.0f;
                self->state = self->state + 2;
            }
        } else if (self->unkB88 >= self->ring.unk0A) {
            ColiseumBattle_PlCtrlOff(self, 1);
            *(float *)(player + 0x54C) = 1800.0f;
            self->timer = 0x3C;
            self->state = self->state + 1;
        }
        break;
    case 5:
        if (self->timer != 0) {
            done = 0;
            self->timer = self->timer - 1;
        } else {
            done = 1;
        }
        if ((done & 0xFF) != 0) {
            self->mode = 1;
            self->flags = self->flags | COLISEUM_FLAG_CTRL_OFF;
            self->state = 0;
            self->unk0C = 0;
        }
        break;
    case 6:
        self->mode = 3;
        self->flags = self->flags | COLISEUM_FLAG_CTRL_OFF;
        self->state = 0;
        self->unk0C = 0;
        break;
    }
    {
        long t = self->flags;

        if (((t >> 3) % 2L) != 0L) {
            func_001F03E8(self);
        }
    }
    NoOp_1F0490(self);
    func_001F28F0(self->ui);
    func_001F2990(self->ui);
}

/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/ColiseumBattle.h"
#include "godhand/vu0.h"


extern int cSnd_SeCall(void *a0, int a1, short a2, int a3, int a4, int a5);
extern int cSnd_SeCall_2CB8A0(void *a0, int a1, int a2, int a3, int t0, int t1, int t2);
extern void func_001F30B8(char *a0, int a1);
extern void func_001F33F8(char *a0, int a1, int a2);
extern void func_001F3488(char *a0, int a1);

extern void cCoreSave_SetFightingRingClearFlag(char *a0, int a1, int a2);
extern int cCoreSave_getClearNum(char *a0);
extern void cCoreSave_setGold(char *a0, int a1);
extern int cCoreSave_getGold(char *a0);
extern void cCoreSave_addGold(char *a0, int a1, int a2);
extern void classFADE_start(void *p, int b, int c, int d, int e, unsigned int f, int g);
extern void cScenario_beginRoomJump_2C4548(char *p, int a1, float f, void *buf, int a3, unsigned int t0, int t1);
extern void NoOp_1F0490(char *a0);
extern void func_001F28F0(char *a0);
extern void func_001F2990(char *a0);
extern char D_00569B70[];
extern char D_005FEE00[];
extern char D_00747470[];
extern int D_005CAFF0;
extern int D_00747A24[];
extern long D_00747640;
extern unsigned char D_0074748C;
extern char *D_003C2F84;

/* Result sequence after a fight: marks the ring cleared, pays the prize
* out thousand by thousand, then fades to the next room. */
__attribute__((section(".text.ColiseumBattle_StepResult")))
void ColiseumBattle_StepResult(ColiseumBattle *self)
{
    char buf[16];
    int done;
    int all;
    int i;

    switch (self->state) {
    case 0:
        cSnd_SeCall(D_005FEE00, 0, 0x35, D_005CAFF0 + 0x210, 0, 0);
        func_001F30B8(self->ui, 1);
        self->timer = 0x3C;
        self->state = self->state + 1;
        break;
    case 1:
        if (self->timer != 0) {
            done = 0;
            self->timer = self->timer - 1;
        } else {
            done = 1;
        }
        if ((done & 0xFF) == 0) {
            break;
        }
        if (func_001FC4D0(D_00569B70, self->ring.ringNo) == 0) {
            cCoreSave_SetFightingRingClearFlag(D_00569B70, self->ring.ringNo, 1);
            if ((((cCoreSave *)D_00569B70)->data->flags & 0x800000) == 0) {
                all = 1;
                i = 1;
                for (; i < 0x33; i++) {
                    if (func_001FC4D0(D_00569B70, i) == 0) {
                        all = 0;
                        break;
                    }
                }
                if (all != 0) {
                    ((cCoreSave *)D_00569B70)->data->flags = ((cCoreSave *)D_00569B70)->data->flags | 0x800000;
                }
            } else {
                if (func_001FC4D0(D_00569B70, 0x33) != 0) {
                    if ((((cCoreSave *)D_00569B70)->data->flags & 0x400000) == 0) {
                        self->flags = self->flags | 0x10;
                    }
                    ((cCoreSave *)D_00569B70)->data->flags = ((cCoreSave *)D_00569B70)->data->flags | 0x400000;
                    D_00747A24[1] = D_00747A24[1] | 0x400000;
                }
            }
            cCoreSave_addGold(D_00569B70, self->ring.prize, 0);
        }
        self->timer = 0x3C;
        self->state = self->state + 1;
        break;
    case 2:
        if (self->timer != 0) {
            done = 0;
            self->timer = self->timer - 1;
        } else {
            done = 1;
        }
        if ((done & 0xFF) == 0) {
            break;
        }
        all = 0;
        if (cCoreSave_getClearNum(D_00569B70) == 0) {
            if ((((cCoreSave *)D_00569B70)->data->flags & 0x20000) == 0) {
                i = 1;
                all = 1;
                for (; i < 0x29; i++) {
                    if (func_001FC4D0(D_00569B70, i) == 0) {
                        all = 0;
                        break;
                    }
                }
            }
        }
        if (all != 0) {
            self->prizeLeft = 0xC350;
            ((cCoreSave *)D_00569B70)->data->flags = ((cCoreSave *)D_00569B70)->data->flags | 0x20000;
            func_001F30B8(self->ui, 0);
            self->timer = 0x1E;
            self->state = self->state + 1;
        } else {
            self->timer = 0x1E;
            self->state = 6;
        }
        break;
    case 3:
        if (self->timer != 0) {
            done = 0;
            self->timer = self->timer - 1;
        } else {
            done = 1;
        }
        if ((done & 0xFF) == 0) {
            break;
        }
        func_001F33F8(self->ui, 1, self->prizeLeft);
        self->timer = 0x1E;
        self->state = self->state + 1;
        break;
    case 4:
        if (self->timer != 0) {
            done = 0;
            self->timer = self->timer - 1;
        } else {
            done = 1;
        }
        if ((done & 0xFF) == 0) {
            break;
        }
        self->prizeSteps = self->prizeLeft / 0x3E8;
        self->state = self->state + 1;
        break;
    case 5:
        if (self->prizeSteps == 0 || (D_00747640 & 0xF00000000L) != 0) {
            cCoreSave_setGold(D_00569B70, cCoreSave_getGold(D_00569B70) + self->prizeSteps * 0x3E8);
            self->timer = 0x1E;
            self->state = self->state + 1;
            self->prizeSteps = 0;
        } else {
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x165, -1, -1, 0, 0);
            cCoreSave_setGold(D_00569B70, cCoreSave_getGold(D_00569B70) + 0x3E8);
            self->prizeSteps = self->prizeSteps - 1;
        }
        func_001F33F8(self->ui, 1, self->prizeSteps * 0x3E8);
        break;
    case 6:
        if (self->timer != 0) {
            done = 0;
            self->timer = self->timer - 1;
        } else {
            done = 1;
        }
        if ((done & 0xFF) == 0) {
            break;
        }
        func_001F33F8(self->ui, 0, 0);
        { long t = self->flags;
        if (((t >> 4) % 2L) != 0L) {
            func_001F30B8(self->ui, 0);
            self->timer = 0x1E;
            self->state = self->state + 1;
        } else {
            self->timer = 0x1E;
            self->state = 9;
        } }
        break;
    case 7:
        if (self->timer != 0) {
            done = 0;
            self->timer = self->timer - 1;
        } else {
            done = 1;
        }
        if ((done & 0xFF) == 0) {
            break;
        }
        func_001F3488(self->ui, 2);
        self->timer = 0x5A;
        self->state = self->state + 1;
        break;
    case 8:
        if (self->timer != 0) {
            done = 0;
            self->timer = self->timer - 1;
        } else {
            done = 1;
        }
        if ((done & 0xFF) == 0) {
            break;
        }
        func_001F3488(self->ui, 0);
        self->timer = 0x1E;
        self->state = self->state + 1;
        break;
    case 9:
        if (self->timer != 0) {
            done = 0;
            self->timer = self->timer - 1;
        } else {
            done = 1;
        }
        if ((done & 0xFF) == 0) {
            break;
        }
        func_001F33F8(self->ui, 0, 0);
        classFADE_start(D_00747470, 0, 0xA, 0, 0, 0xFF000000u, 0xF);
        self->state = self->state + 1;
        break;
    case 10:
        if (((D_0074748C >> 2) & 1) != 0) {
            char *p = D_003C2F84;
            int h = *(unsigned short *)(p + 0x16);
            VU0_LQC2(4, p, 0x0);
            VU0_SQC2(4, buf, 0x0);
            cScenario_beginRoomJump_2C4548(p, h, *(float *)(p + 0x10), buf, 0, 0x80000000u, 1);
        }
        break;
    }
    NoOp_1F0490(self);
    func_001F28F0(self->ui);
    func_001F2990(self->ui);
}

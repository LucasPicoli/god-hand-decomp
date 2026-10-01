/* sn-2.95.3-136 matched TU. */

#include "godhand/Slot2.h"
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"

extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);
extern void func_001E6ED8(Slot2 *a0, int a1, int a2);
extern void func_001E6B70(Slot2 *a0, int a1, int a2);
extern void func_001E8E48(void *a0, void *a1);
extern void cSnd_BgmEventStart(void *a0, int a1, int a2, int a3);
extern int cSnd_SeCall(void *a0, int a1, short a2, int a3, int a4, int a5);
extern void cSnd_SeStop(void *a0, int a1);
extern char D_005FEE00[];
extern long D_00747650;
extern void func_001E6C80(Slot2 *a0, int a1, int a2);

/* Slot2 payout stage, first line prize: pay out coin by coin until a button
 * is pressed or the coins run out. */
















__attribute__((section(".text.Slot2_payoutLine1")))
void Slot2_payoutLine1(Slot2 *self) {
    unsigned char buf[16] __attribute__((aligned(16)));
    int done;

    switch (self->phase) {
    case 0:
        SetEffect(1, 1, 0, 0, -1, 0xFFFFFFFFU);
        func_001E6ED8(self, 1, 1);
        func_001E6B70(self, 1, 1);
        self->timer = 0x3C;
        self->phase = self->phase + 1;
        break;
    case 1:
        if (self->timer != 0) {
            self->timer = self->timer - 1;
            done = 0;
        } else {
            done = 1;
        }
        if ((done & 0xFF) == 0) break;
        cSnd_BgmEventStart(D_005FEE00, 0x32, 0, 0);
        self->coinUnit = 100;
        self->coinNum = self->unk36C[0] / 100;
        VU0_SQC2_VF0(buf, 0);
        func_001E8E48(&self->reel[0], buf);
        self->seId[1] = cSnd_SeCall(D_005FEE00, 2, 2, (int)buf, 0, 0);
        self->phase = self->phase + 1;
        break;
    case 2:
        if (self->coinNum == 0 || cCoreSave_isGoldFull(&D_00569B70) != 0 || (D_00747650 & 0xF00000000L) != 0) {
            cSnd_SeStop(D_005FEE00, self->seId[1]);
            cCoreSave_addGold(&D_00569B70, self->coinUnit * self->coinNum, 0);
            func_001E6ED8(self, 0, 0);
            func_001E6B70(self, 0, 0);
            self->phase = self->phase + 1;
            break;
        }
        cCoreSave_addGold(&D_00569B70, self->coinUnit, 0);
        self->coinNum = self->coinNum - 1;
        break;
    case 3:
        self->state = 0;
        self->step = 0;
        self->phase = 0;
        break;
    }
}

/* Slot2 payout stage, second line prize: pay out coin by coin until a button
 * is pressed or the coins run out. */
















__attribute__((section(".text.Slot2_payoutLine2")))
void Slot2_payoutLine2(Slot2 *self) {
    unsigned char buf[16] __attribute__((aligned(16)));
    int done;

    switch (self->phase) {
    case 0:
        SetEffect(1, 2, 0, 0, -1, 0xFFFFFFFFU);
        func_001E6ED8(self, 1, 1);
        func_001E6C80(self, 1, 1);
        self->timer = 0x3C;
        self->phase = self->phase + 1;
        break;
    case 1:
        if (self->timer != 0) {
            self->timer = self->timer - 1;
            done = 0;
        } else {
            done = 1;
        }
        if ((done & 0xFF) == 0) break;
        cSnd_BgmEventStart(D_005FEE00, 0x33, 0, 0);
        self->coinUnit = 100;
        self->coinNum = self->unk36C[1] / 100;
        VU0_SQC2_VF0(buf, 0);
        func_001E8E48(&self->reel[0], buf);
        self->seId[1] = cSnd_SeCall(D_005FEE00, 2, 2, (int)buf, 0, 0);
        self->phase = self->phase + 1;
        break;
    case 2:
        if (self->coinNum == 0 || cCoreSave_isGoldFull(&D_00569B70) != 0 || (D_00747650 & 0xF00000000L) != 0) {
            cSnd_SeStop(D_005FEE00, self->seId[1]);
            cCoreSave_addGold(&D_00569B70, self->coinUnit * self->coinNum, 0);
            func_001E6ED8(self, 0, 0);
            func_001E6C80(self, 0, 0);
            self->phase = self->phase + 1;
            break;
        }
        cCoreSave_addGold(&D_00569B70, self->coinUnit, 0);
        self->coinNum = self->coinNum - 1;
        break;
    case 3:
        self->state = 0;
        self->step = 0;
        self->phase = 0;
        break;
    }
}

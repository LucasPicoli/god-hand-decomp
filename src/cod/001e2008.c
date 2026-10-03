/* sn-2.95.3-136 matched TU. */

#include "godhand/Slot1.h"
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"

extern void func_001E4200(Slot1 *a0, int a1, int a2, int a3);
extern void func_001E3D78(Slot1 *a0, int a1, int a2);
extern void func_001E8E48(void *a0, void *a1);
extern int cSnd_SeCall(void *a0, int a1, short a2, int a3, int a4, int a5);
extern void cSnd_SeStop(void *a0, int a1);
extern char D_005FEE00[];
extern long D_00747650;
extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);
extern void func_001E3928(Slot1 *a0, int a1, int a2);
extern void cSnd_BgmEventStart(void *a0, int a1, int a2, int a3);
extern void func_001E3A98(Slot1 *a0, int a1, int a2);
extern void func_001E7470(int a0, int a1, int a2);

/* Slot1 payout stage, prize line 3: pay out coin by coin until a button is pressed or the coins run out. */












__attribute__((section(".text.Slot1_payoutLine4")))
void Slot1_payoutLine4(Slot1 *self) {
    unsigned char buf[16] __attribute__((aligned(16)));
    int done;

    switch (self->phase) {
    case 0:
        self->payMode = SLOT1_PAYMODE_ON;
        func_001E4200(self, self->slotId, 1, 1);
        func_001E3D78(self, 1, 1);
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
        self->coinUnit = 10;
        self->coinNum = self->prize[3] / 10;
        VU0_SQC2_VF0(buf, 0);
        func_001E8E48(&self->reel[0], buf);
        self->seId = cSnd_SeCall(D_005FEE00, 2, 2, (int)buf, 0, 0);
        self->phase = self->phase + 1;
        break;
    case 2:
        if (self->coinNum == 0 || cCoreSave_isGoldFull(&D_00569B70) != 0 || (D_00747650 & 0xF00000000L) != 0) {
            cSnd_SeStop(D_005FEE00, self->seId);
            cCoreSave_addGold(&D_00569B70, self->coinUnit * self->coinNum, 0);
            func_001E4200(self, self->slotId, 0, 0);
            func_001E3D78(self, 0, 0);
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

/* Slot1 payout stage, prize line 4: pay out coin by coin until a button is pressed or the coins run out. */












__attribute__((section(".text.Slot1_payoutLine5")))
void Slot1_payoutLine5(Slot1 *self) {
    unsigned char buf[16] __attribute__((aligned(16)));
    int done;

    switch (self->phase) {
    case 0:
        self->payMode = SLOT1_PAYMODE_ON;
        func_001E4200(self, self->slotId, 1, 1);
        func_001E3D78(self, 1, 1);
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
        self->coinUnit = 10;
        self->coinNum = self->prize[4] / 10;
        VU0_SQC2_VF0(buf, 0);
        func_001E8E48(&self->reel[0], buf);
        self->seId = cSnd_SeCall(D_005FEE00, 2, 2, (int)buf, 0, 0);
        self->phase = self->phase + 1;
        break;
    case 2:
        if (self->coinNum == 0 || cCoreSave_isGoldFull(&D_00569B70) != 0 || (D_00747650 & 0xF00000000L) != 0) {
            cSnd_SeStop(D_005FEE00, self->seId);
            cCoreSave_addGold(&D_00569B70, self->coinUnit * self->coinNum, 0);
            func_001E4200(self, self->slotId, 0, 0);
            func_001E3D78(self, 0, 0);
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

/* Slot1 payout stage, prize line 5: pay out coin by coin until a button is pressed or the coins run out. */












__attribute__((section(".text.Slot1_payoutLine6")))
void Slot1_payoutLine6(Slot1 *self) {
    unsigned char buf[16] __attribute__((aligned(16)));
    int done;

    switch (self->phase) {
    case 0:
        self->payMode = SLOT1_PAYMODE_ON;
        func_001E4200(self, self->slotId, 1, 1);
        func_001E3D78(self, 1, 1);
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
        self->coinUnit = 10;
        self->coinNum = self->prize[5] / 10;
        VU0_SQC2_VF0(buf, 0);
        func_001E8E48(&self->reel[0], buf);
        self->seId = cSnd_SeCall(D_005FEE00, 2, 2, (int)buf, 0, 0);
        self->phase = self->phase + 1;
        break;
    case 2:
        if (self->coinNum == 0 || cCoreSave_isGoldFull(&D_00569B70) != 0 || (D_00747650 & 0xF00000000L) != 0) {
            cSnd_SeStop(D_005FEE00, self->seId);
            cCoreSave_addGold(&D_00569B70, self->coinUnit * self->coinNum, 0);
            func_001E4200(self, self->slotId, 0, 0);
            func_001E3D78(self, 0, 0);
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

/* Slot1 payout stage, prize line 0: pay out coin by coin until a button is pressed or the coins run out. */














__attribute__((section(".text.Slot1_payoutLine1")))
void Slot1_payoutLine1(Slot1 *self) {
    unsigned char buf[16] __attribute__((aligned(16)));
    int done;

    switch (self->phase) {
    case 0:
        self->payMode = SLOT1_PAYMODE_ON;
        SetEffect(1, 1, 0, 0, -1, 0xFFFFFFFFU);
        func_001E4200(self, self->slotId, 1, 1);
        func_001E3928(self, 1, 1);
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
        self->coinNum = self->prize[0] / 100;
        VU0_SQC2_VF0(buf, 0);
        func_001E8E48(&self->reel[0], buf);
        self->seId = cSnd_SeCall(D_005FEE00, 2, 2, (int)buf, 0, 0);
        self->phase = self->phase + 1;
        break;
    case 2:
        if (self->coinNum == 0 || cCoreSave_isGoldFull(&D_00569B70) != 0 || (D_00747650 & 0xF00000000L) != 0) {
            cSnd_SeStop(D_005FEE00, self->seId);
            cCoreSave_addGold(&D_00569B70, self->coinUnit * self->coinNum, 0);
            func_001E4200(self, self->slotId, 0, 0);
            func_001E3928(self, 0, 0);
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

/* Slot1 payout stage, prize line 1: pay out coin by coin until a button is pressed or the coins run out. */














__attribute__((section(".text.Slot1_payoutLine2")))
void Slot1_payoutLine2(Slot1 *self) {
    unsigned char buf[16] __attribute__((aligned(16)));
    int done;

    switch (self->phase) {
    case 0:
        self->payMode = SLOT1_PAYMODE_ON;
        SetEffect(1, 2, 0, 0, -1, 0xFFFFFFFFU);
        func_001E4200(self, self->slotId, 1, 1);
        func_001E3A98(self, 1, 1);
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
        self->coinNum = self->prize[1] / 100;
        VU0_SQC2_VF0(buf, 0);
        func_001E8E48(&self->reel[0], buf);
        self->seId = cSnd_SeCall(D_005FEE00, 2, 2, (int)buf, 0, 0);
        self->phase = self->phase + 1;
        break;
    case 2:
        if (self->coinNum == 0 || cCoreSave_isGoldFull(&D_00569B70) != 0 || (D_00747650 & 0xF00000000L) != 0) {
            cSnd_SeStop(D_005FEE00, self->seId);
            cCoreSave_addGold(&D_00569B70, self->coinUnit * self->coinNum, 0);
            func_001E4200(self, self->slotId, 0, 0);
            func_001E3A98(self, 0, 0);
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

/* Set the display flag of custom-ID works 2 to 8 on one UI object. */


__attribute__((section(".text.SetUiIdWorkDispRange")))
void SetUiIdWorkDispRange(int a0, int a1) {
    func_001E7470(a0, 2, a1);
    func_001E7470(a0, 3, a1);
    func_001E7470(a0, 4, a1);
    func_001E7470(a0, 5, a1);
    func_001E7470(a0, 6, a1);
    func_001E7470(a0, 7, a1);
    func_001E7470(a0, 8, a1);
}

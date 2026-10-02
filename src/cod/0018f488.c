/* sn-2.95.3-136 matched TU. */

#include "godhand/Slot1.h"
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"

extern int IsEntryActive_1C2490(int a0);
extern void SetField_630_1C2370(int a0);
extern void ColiseumBattle_DefeatAllEnemies(void *a0);
extern int ColiseumBattle_CountLiveEnemies(void *a0);
extern void cEmSetParam_setEm(void *a0, int a1);
extern void cEmWrap_StartAction(void *a0);
extern char D_00586AB0[];
extern int ClearField5B4IfFlagUnset_1B76B0(int a0);
extern void func_001C7E30(void *a0);
extern void func_002A87E8(void *a0, int a1);
extern void func_001B76D8(void *a0);
extern unsigned short D_003F2060[];
extern void func_0032A9F0(int a0, int a1);
extern void func_001E4200(Slot1 *a0, int a1, int a2, int a3);
extern void func_001E3D78(Slot1 *a0, int a1, int a2);
extern void func_001E8E48(void *a0, void *a1);
extern int cSnd_SeCall(void *a0, int a1, short a2, int a3, int a4, int a5);
extern void cSnd_SeStop(void *a0, int a1);
extern char D_005FEE00[];
extern long D_00747650;

/* Phase-machine tick: drop the pending entry at +0x15B0 (stop it if still running), then run the handler of the 0..1 state byte. */



struct Entry_func_0028A8D0 { short f0; short f2; short f4; short f6; };
typedef struct { char b[0x10]; } Blob10;
extern Blob10 D_00448E00;

__attribute__((section(".text.func_0028A8D0")))
void func_0028A8D0(char *s0)
{
    struct Entry_func_0028A8D0 tbl[2];
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;

    *(Blob10 *)tbl = D_00448E00;
    if (*(int *)(s0 + 0x15B0) != 0) {
        if (IsEntryActive_1C2490(*(int *)(s0 + 0x15B0)) != 0) {
            *(int *)(s0 + 0x15B0) = 0;
        } else {
            SetField_630_1C2370(*(int *)(s0 + 0x15B0));
        }
        *(int *)(s0 + 0x15B0) = 0;
    }
    if (*(unsigned char *)(s0 + 0x2F5) >= 2)
        *(unsigned char *)(s0 + 0x2F5) = 0;
    i8 = *(unsigned char *)(s0 + 0x2F5) * 8;
    e = (char *)tbl + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)tbl + i8 + 4);
    }
    f0 = tbl[*(unsigned char *)(s0 + 0x2F5)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
}

/* Coliseum wave director, second variant: clear the field, then spawn the next group when the timer (750 frames) runs out or no enemy is left. */








__attribute__((section(".text.func_001F1B20")))
void func_001F1B20(void *a0) {
    char *s0 = (char *)a0;
    char buf[0x10];
    int st;

    st = *(int *)(s0 + 0xB94);
    switch (st) {
    case 0:
        ColiseumBattle_DefeatAllEnemies(s0);
        *(int *)(s0 + 0xBA0) = 0;
        *(int *)(s0 + 0xB94) = *(int *)(s0 + 0xB94) + 1;
        break;
    case 1:
        if (*(int *)(s0 + 0xBA0) < 0x2EE && ColiseumBattle_CountLiveEnemies(s0) != 0) goto bail;
        buf[0] = st;
        cEmSetParam_setEm(D_00586AB0, 1);
        cEmWrap_StartAction(buf);
        *(int *)(s0 + 0xBA0) = 0;
        *(int *)(s0 + 0xB8C) = *(int *)(s0 + 0xB8C) + 1;
        *(int *)(s0 + 0xB94) = *(int *)(s0 + 0xB94) + 1;
        break;
    case 2:
        if (*(int *)(s0 + 0xBA0) < 0x2EE && ColiseumBattle_CountLiveEnemies(s0) != 0) goto bail;
        buf[0] = st;
        cEmSetParam_setEm(D_00586AB0, 2);
        cEmWrap_StartAction(buf);
        *(int *)(s0 + 0xB8C) = *(int *)(s0 + 0xB8C) + 1;
        *(int *)(s0 + 0xB94) = *(int *)(s0 + 0xB94) + 1;
        break;
    }
    return;
bail:
    *(int *)(s0 + 0xBA0) = *(int *)(s0 + 0xBA0) + 1;
}

/* Phase-machine tick: when flag bit 2 is clear run the state handler, skip the sync step if bit 1 is set, then the shared post-update; else run the alternate update. */





extern struct Table_173 D_00423E10;

struct Entry_173 { short f0; unsigned short type; unsigned short f4; short f6; };
struct Table_173 { struct Entry_173 e[4]; };

__attribute__((section(".text.func_0018F488")))
void func_0018F488(void *a0)
{
    char *s0 = (char *)a0;
    struct Table_173 buf;
    char *e;
    int i8;
    int f0;
    long flags; int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    flags = *(unsigned int *)(s0 + 0x5B0);
    if (((flags >> 2) & 1) == 0) {
        buf = D_00423E10;
        i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
        e = (char *)&buf + i8;
        type = (short)*(unsigned short *)(e + 2);
        if (type >= 0) {
            int base = *(int *)(s0 + (short)*(unsigned short *)(e + 4));
            entry = *(long *)(base + type * 8 - 8);
            fp = (int (*)(int))(int)(entry >> 32);
        } else {
            fp = *(int (**)(int))((char *)&buf + i8 + 4);
        }
        f0 = buf.e[*(unsigned char *)(s0 + 0x2F4)].f0;
        if (type >= 0)
            arg = (short)entry + f0;
        else
            arg = f0;
        fp((int)(s0 + arg));
        flags = *(unsigned int *)(s0 + 0x5B0);
        if (((flags >> 1) & 1) == 0)
            func_002A87E8(s0, 0);
        func_001B76D8(s0);
    } else {
        func_001C7E30(s0);
    }
}

/* Nudge two scroll positions of the selected row by a step (10 when bit 1 of the pad flags is set): stick/dpad moves the first, up/down the second via the table; then update the linked sound. */




__attribute__((section(".text.func_00381150")))
void func_00381150(char *a0, char *a1)
{
    char *p;
    char *q;
    short step;
    int f;

    p = a0 + (*(unsigned char *)(a0 + 5) * 0x48 + 0x48);
    q = p + 0x10;
    step = 1;
    if ((*(int *)(a1 + 0x2C) & 2) != 0) {
        step = 10;
    }
    f = *(int *)(a1 + 0x38);
    if (f < 0) {
        if (*(short *)(p + 4) >= step - 0x3C0) {
            *(short *)(p + 4) = *(short *)(p + 4) - step;
        } else {
            *(short *)(p + 4) = -0x3C0;
        }
        goto call1;
    }
    if ((f & 0x40000000) != 0) {
        if (*(short *)(p + 4) <= -step) {
            *(short *)(p + 4) = step + *(short *)(p + 4);
        } else {
            *(short *)(p + 4) = 0;
        }
call1:
        *(short *)(p + 6) = func_003807E0(a0, *(short *)(p + 4));
    } else if ((f & 0x8000) != 0) {
        if (*(short *)(p + 6) >= step) {
            *(short *)(p + 6) = *(short *)(p + 6) - step;
        } else {
            *(short *)(p + 6) = 0;
        }
        *(short *)(p + 4) = D_003F2060[*(short *)(p + 6)];
    } else {
        if ((f & 0x2000) == 0) {
            return;
        }
        if (*(short *)(p + 6) <= 0x7F - step) {
            *(short *)(p + 6) = step + *(short *)(p + 6);
        } else {
            *(short *)(p + 6) = 0x7F;
        }
        *(short *)(p + 4) = D_003F2060[*(short *)(p + 6)];
    }
    if (*(int *)(q + 0x30) != 0) {
        func_0032A9F0(*(int *)(q + 0x30), *(short *)(p + 4));
    }
}

/* Slot1 payout stage, prize line 2: pay out coin by coin until a button is pressed or the coins run out. */












__attribute__((section(".text.func_001E26D8")))
void func_001E26D8(Slot1 *self) {
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
        self->coinNum = self->prize[2] / 10;
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

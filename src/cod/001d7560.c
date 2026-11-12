/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136, as=sn: the poker table's bet step, 100 gold per press between the save and the bet. */
#include "godhand/cCoreSave.h"
#include "godhand/Poker.h"

extern void func_001DD770(void *a0, int a1);
extern void func_001DD840(void *a0, int a1);
extern void func_001DD910(void *a0, int a1);
extern void func_001DD5A0(void *a0, int a1);
extern void SetBlendField1D4_1DDB10(void *a0, int a1);
extern void NoOp_1DCE60(void *a0);
extern void CustomIDWork_SetNumber_1DD218(char *a0, int a1);
extern void SetCustomIDNumberIndexed_1DD648(char *a0, int a1, int a2);
extern int cSnd_SeCall_2CB8A0(void *a0, int a1, int a2, int a3, int t0, int t1, int t2);
extern int D_007474A0;
extern int D_00747A2C;
extern unsigned char D_005FEE00[];

#define POKER_BET_STEP      0x64        /* gold moved per press */
#define POKER_F_HELP        0x2         /* flags: the help panel is open */
#define POKER_F_BET_CHANGED 0x8         /* flags: cleared when the bet reaches betMax */
#define POKER_STATE_DEAL    3
#define POKER_STATE_QUIT    4
#define POKER_STATE_BACK    2
#define PAD_HELP_TOGGLE     0x80000000000L   /* pad word at D_00747A2C - 0x3EC */
#define PAD_QUIT            0xCC0000C000000L /* pad words at GameWork + 0x1B0 */
#define PAD_BACK            0x3300003000000L
#define PAD_BET_UP          0x10000000       /* pad word at GameWork + 0x1A0 */
#define PAD_BET_DOWN        0x20000000
#define SE_CANCEL           0x15F
#define SE_BET_UP           0x15E
#define SE_BET_DOWN         0x161

/* One frame of the bet step: the help toggle, quit and back keys, and the bet up and down
 * keys, then the payout of each hand for the current bet. */
__attribute__((section(".text.func_001D7560")))
void func_001D7560(Poker *self) {
    char *o = (char *)self;
    char *g;
    long fl;

    switch (self->phase) {
    case 0:
        func_001DD770(o, 0);
        SetBlendField1D4_1DDB10(o, 1);
        self->phase = self->phase + 1;
        /* fallthrough */
    case 1:
        if (D_00747A2C & 0x200) {
            if (*(long *)((char *)&D_00747A2C - 0x3EC) & PAD_HELP_TOGGLE) {
                fl = (unsigned int)self->flags;
                if (((fl >> 1) & 1) == 1) {
                    self->flags = self->flags & ~POKER_F_HELP;
                } else {
                    self->flags = self->flags | POKER_F_HELP;
                }
            }
        }
        fl = (unsigned int)self->flags;
        if (((fl >> 1) & 1) == 1) {
            NoOp_1DCE60(o);
            break;
        }
        g = (char *)&D_007474A0;
        if (*(long *)(g + 0x1B0) & PAD_QUIT) {
            func_001DD770(o, 1);
            SetBlendField1D4_1DDB10(o, 0);
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, SE_CANCEL, -1, -1, 0, 0);
            /* the store pair is written in both arms: one shared store pair if-converts to movn */
            if (self->bet != 0) {
                self->phase = 0;
                self->state = POKER_STATE_DEAL;
            } else {
                self->phase = 0;
                self->state = POKER_STATE_QUIT;
            }
        } else if (*(long *)(g + 0x1B0) & PAD_BACK) {
            func_001DD770(o, 1);
            SetBlendField1D4_1DDB10(o, 0);
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, SE_CANCEL, -1, -1, 0, 0);
            self->phase = 0;
            self->state = POKER_STATE_BACK;
        } else if (*(long *)(g + 0x1A0) & PAD_BET_UP) {
            if (self->bet < self->betMax && cCoreSave_getGold(&D_00569B70) >= POKER_BET_STEP) {
                cCoreSave_subGold(&D_00569B70, POKER_BET_STEP);
                self->bet = self->bet + POKER_BET_STEP;
                CustomIDWork_SetNumber_1DD218(o, self->bet);
                func_001DD910(o, 1);
                func_001DD5A0(o, 0);
                if (self->bet >= self->betMax) {
                    func_001DD770(o, 2);
                    SetBlendField1D4_1DDB10(o, 0);
                    func_001DD840(o, 2);
                    self->phase = 0;
                    self->state = POKER_STATE_DEAL;
                }
                self->flags = self->flags & ~POKER_F_BET_CHANGED;
            }
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, SE_BET_UP, -1, -1, 0, 0);
        } else if (*(long *)(g + 0x1A0) & PAD_BET_DOWN) {
            if (self->bet > 0) {
                cCoreSave_addGold(&D_00569B70, POKER_BET_STEP, 0);
                self->bet = self->bet - POKER_BET_STEP;
                CustomIDWork_SetNumber_1DD218(o, self->bet);
                if (self->bet == 0) {
                    func_001DD910(o, 2);
                    func_001DD5A0(o, 1);
                }
            } else {
                func_001DD770(o, 1);
                SetBlendField1D4_1DDB10(o, 0);
                self->phase = 0;
                self->state = POKER_STATE_QUIT;
            }
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, SE_BET_DOWN, -1, -1, 0, 0);
        }
        break;
    }
    /* the payout of each hand, bet times its multiplier, or the multiplier with no bet */
    SetCustomIDNumberIndexed_1DD648(o, 0, self->bet ? self->bet * 0x32 : 0x32);
    SetCustomIDNumberIndexed_1DD648(o, 1, self->bet ? self->bet * 0x14 : 0x14);
    SetCustomIDNumberIndexed_1DD648(o, 2, self->bet ? self->bet * 0xF : 0xF);
    SetCustomIDNumberIndexed_1DD648(o, 3, self->bet ? self->bet * 0xA : 0xA);
    SetCustomIDNumberIndexed_1DD648(o, 4, self->bet ? self->bet * 8 : 8);
    SetCustomIDNumberIndexed_1DD648(o, 5, self->bet ? self->bet * 8 : 8);
    SetCustomIDNumberIndexed_1DD648(o, 6, self->bet ? self->bet * 3 : 3);
    SetCustomIDNumberIndexed_1DD648(o, 7, self->bet ? self->bet * 2 : 2);
}

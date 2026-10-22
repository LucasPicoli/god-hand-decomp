/* sn-2.95.3-136 */
#include "godhand/cIDBase.h"
#include "godhand/gameWork.h"
#include "godhand/cSnd.h"

#define MENU_TRG_TO_1    0x0008000004000000L
#define MENU_TRG_TO_0    0x0004000008000000L
#define MENU_TRG_BACK_0  0x0001000001000000L
#define MENU_TRG_TO_M1   0x0002000002000000L
#define MENU_TRG_OK      0x10000000L
#define MENU_TRG_CANCEL  0x20200000L

#define SE_MENU_DECIDE 0x15E
#define SE_MENU_MOVE   0x15F
#define SE_MENU_CANCEL 0x161

extern cSnd D_005FEE00;
extern int cSnd_SeCall_2CB8A0(cSnd *self, int slot, short key1, short idA, short idB, int a5, int a6);

/* A menu panel built on cIDBase: it fades in, lets the pad pick an answer (-1, 0 or 1)
 * and fades out. */
typedef struct cIDMenuPanel {
    cIDBaseObj base;                    /* 0x00 */
    char unk48[0x5A - 0x48];
    signed char state;                  /* 0x5A 0 fade in, 1 shown, 2 fade out */
    char unk5B[0x60 - 0x5B];
    int result;                         /* 0x60 7 once an answer is decided, -1 when the panel has faded out */
    char unk64[0x91 - 0x64];
    signed char choice;                 /* 0x91 -1, 0 or 1 */
} cIDMenuPanel;

/* Moves the menu's three-way selection (-1, 0, 1) with the pad and handles decide and cancel while the panel is shown. */
__attribute__((section(".text.func_001682C8")))
void func_001682C8(cIDMenuPanel *self)
{
    if (self->state != 1) {
        return;
    }
    if ((D_007474A0.trg & MENU_TRG_TO_1) && self->choice != -1) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, SE_MENU_MOVE, -1, -1, 0, 0);
        self->choice = 1;
    } else if ((D_007474A0.trg & MENU_TRG_TO_0) && self->choice != -1) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, SE_MENU_MOVE, -1, -1, 0, 0);
        self->choice = 0;
    } else if ((D_007474A0.trg & MENU_TRG_BACK_0) && self->choice == -1) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, SE_MENU_MOVE, -1, -1, 0, 0);
        self->choice = 0;
    } else if (D_007474A0.trg & MENU_TRG_TO_M1) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, SE_MENU_MOVE, -1, -1, 0, 0);
        self->choice = -1;
    } else if (D_007474A0.trg & MENU_TRG_OK) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, SE_MENU_DECIDE, -1, -1, 0, 0);
        switch (self->choice) {
        case -1:
            self->state = 2;
            break;
        case 0:
        case 1:
            self->result = 7;
            break;
        }
    } else if (D_007474A0.trg & MENU_TRG_CANCEL) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, SE_MENU_CANCEL, -1, -1, 0, 0);
        self->state = 2;
    }
}

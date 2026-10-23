/* sn-2.95.3-136 */
#include "godhand/cIDMenuPanel.h"
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

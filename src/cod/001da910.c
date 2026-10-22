/* sn-2.95.3-136: two-choice panel step: open the panel, toggle the choice on left/right
 * and confirm on the decide button. */
#include "godhand/Poker.h"
#include "godhand/gameWork.h"
extern char D_005FEE00[];
extern void cSnd_SetBgmState(void *a0, int a1);
extern int cSnd_SeCall_2CB8A0(void *a0, int a1, short a2, short a3, short a4, int a5, int a6);
extern void PanelObj_setCursorMode(void *self, unsigned char mode);
extern void PanelObj_setArrowMode(void *self, unsigned char mode);
extern void func_001DF048(void *self, int a1);
extern void func_001DF0F0(void *self, int a1);

__attribute__((section(".text.func_001DA910")))
void func_001DA910(Poker *self)
{
    switch (self->phase) {
    case 0:
        cSnd_SetBgmState(D_005FEE00, 3);
        self->cursorOn = 1;
        self->choice = 0;
        PanelObj_setCursorMode(POKER_UI(self), 1);
        func_001DF048(POKER_UI(self), 1);
        PanelObj_setArrowMode(POKER_UI(self), 0);
        func_001DF0F0(POKER_UI(self), 0);
        self->phase += 1;
        break;
    case 1:
        if (D_007474A0.rep & 0xCC0000C000000L) {
            if (self->choice == 0) {
                self->choice = 1;
                self->cursorOn = 0;
                PanelObj_setCursorMode(POKER_UI(self), 0);
                func_001DF048(POKER_UI(self), 0);
                PanelObj_setArrowMode(POKER_UI(self), 1);
                func_001DF0F0(POKER_UI(self), 1);
            } else {
                self->cursorOn = 1;
                self->choice = 0;
                PanelObj_setCursorMode(POKER_UI(self), 1);
                func_001DF048(POKER_UI(self), 1);
                PanelObj_setArrowMode(POKER_UI(self), 0);
                func_001DF0F0(POKER_UI(self), 0);
            }
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
        } else if (D_007474A0.trg & 0x10000000) {
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15E, -1, -1, 0, 0);
            func_001DF048(POKER_UI(self), 0);
            func_001DF0F0(POKER_UI(self), 0);
            self->phase += 1;
        }
        break;
    case 2:
        self->phase = 0;
        self->state = 0xF;
        break;
    }
}

/* sn-2.95.3-136: func_001643F8, menu screen input: move the cursor and act on the decide button. */
#include "godhand/gameWork.h"
#include "godhand/cSnd.h"
#include "godhand/cSubScr.h"

#define PAD_UP          0x1000001000000L
#define PAD_DOWN        0x2000002000000L
#define PAD_DECIDE      0x10000000
#define SE_CURSOR       0x15F
#define SE_DECIDE       0x15E
#define GAMEWORK_FLAG_BIT6  6
#define ROOM_TITLE      0x21

extern cSnd D_005FEE00;
extern unsigned short D_00583ED4;
extern int cSnd_SeCall_2CB8A0(cSnd *self, int slot, short key1, short idA, short idB, int a5, int a6);
extern void func_001645E0(char *self);

/* Move the cursor over the four entries with up and down, wrapping (the first
 * entry is skipped while flag bit 6 is set), and act on the decide button. */
__attribute__((section(".text.func_001643F8")))
void func_001643F8(MenuScreen *self)
{
    unsigned long f;

    if (D_007474A0.rep & PAD_UP) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, SE_CURSOR, -1, -1, 0, 0);
        self->cursor--;
    }
    if (D_007474A0.rep & PAD_DOWN) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, SE_CURSOR, -1, -1, 0, 0);
        self->cursor++;
    }
    f = D_007474A0.flags;
    if ((f >> GAMEWORK_FLAG_BIT6 & 1) == 1) {
        self->cursor = self->cursor < 1 ? 3 : self->cursor < 4 ? self->cursor : 1;
    } else {
        self->cursor = self->cursor < 0 ? 3 : self->cursor < 4 ? self->cursor : 0;
    }
    if (D_007474A0.trg & PAD_DECIDE) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, SE_DECIDE, -1, -1, 0, 0);
        self->next = -1;
        switch (self->cursor) {
        case 0:
            self->result = 0xFFFF;
            self->next = 0xC;
            break;
        case 1:
            if (D_007474A0.room == ROOM_TITLE) {
                func_001645E0((char *)self);
                return;
            }
            self->result = D_00583ED4;
            break;
        case 3:
            self->choice = 0;
            goto clear;
        case 2:
            self->choice = 1;
        /* cases 2 and 3 share this store; storing it in each case doesn't match */
        clear:
            self->result = 0;
            break;
        }
    }
}

/* sn-2.95.3-136 */
#include "godhand/cSubScr.h"
#include "godhand/gameWork.h"
#include "godhand/cSnd.h"

#define MENU_KEY_NEXT  0x0008000004000000L  /* cursor down (pad and stick) */
#define MENU_KEY_PREV  0x0004000008000000L  /* cursor up (pad and stick) */
#define MENU_KEY_OK    0x10000000L
#define MENU_KEY_BACK  0x20000000L
#define MENU_KEY_CLOSE 0x200000L

#define MENU_SE_MOVE   0x15F
#define MENU_SE_OK     0x15E
#define MENU_SE_BACK   0x161

/* The menu panel object; 001680d8.c reads the same fields through raw offsets. */
typedef struct MenuPanel {
    char unk00[0x5A];
    signed char state;                  /* 0x5A */
    char unk5B[0x60 - 0x5B];
    int timer;                          /* 0x60 */
    char unk64[0x1B4 - 0x64];
    signed char cursor;                 /* 0x1B4 */
    char unk1B5[0x1D0 - 0x1B5];
    short unk1D0;                       /* 0x1D0 */
    short unk1D2;                       /* 0x1D2 */
    unsigned char toggle;               /* 0x1D4 */
} MenuPanel;

extern cSnd D_005FEE00;
extern int cSnd_SeCall_2CB8A0(cSnd *self, int slot, short key1, short idA, short idB, int a5, int a6);
extern void func_0016BC78(void *a0);
extern void Obj0000_Set_Short_202(unsigned char *a0);
extern void Obj0000_Set_Short_204(unsigned char *a0);


/* Input step of the menu panel: moves the cursor through its 4 (or 2) rows,
 * opens the picked row, and runs the on/off toggle page. */
__attribute__((section(".text.func_0016AE38")))
void func_0016AE38(MenuPanel *self)
{
    switch (self->state) {
    case 0:
        break;
    case 1:
        if ((D_007474A0.trg & MENU_KEY_NEXT) && !(D_007474A0.trg & MENU_KEY_OK)) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
            self->cursor++;
        }
        if ((D_007474A0.trg & MENU_KEY_PREV) && !(D_007474A0.trg & MENU_KEY_OK)) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
            self->cursor--;
        }
        switch (D_003BD930->mode) {
        case 0:
            self->cursor = self->cursor < 0 ? 3 : self->cursor < 4 ? self->cursor : 0;
            break;
        case 1:
            self->cursor = self->cursor < 0 ? 1 : self->cursor < 2 ? self->cursor : 0;
            break;
        }
        if (D_007474A0.trg & MENU_KEY_OK) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_OK, -1, -1, 0, 0);
            if ((D_003BD930->mode == 0 && self->cursor != 3) || (D_003BD930->mode == 1 && self->cursor == 0)) {
                self->unk1D2 = 0;
                self->state = 2;
                self->unk1D0 = 0;
            } else {
                self->state = 7;
            }
        }
        if (D_007474A0.trg & MENU_KEY_BACK) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
            self->state = 7;
        }
        break;
    case 3:
        func_0016BC78(self);
        break;
    case 4:
        Obj0000_Set_Short_202((unsigned char *)self);
        break;
    case 5:
        Obj0000_Set_Short_204((unsigned char *)self);
        break;
    case 7:
        if (D_007474A0.rep & MENU_KEY_NEXT) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
            self->toggle ^= 1;
        }
        if (D_007474A0.rep & MENU_KEY_PREV) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
            self->toggle ^= 1;
        }
        if (D_007474A0.trg & MENU_KEY_OK) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_OK, -1, -1, 0, 0);
            self->state = 0;
            self->timer = 10;
        }
        break;
    }
    if (D_007474A0.trg & MENU_KEY_CLOSE) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
        self->state = 7;
    }
}

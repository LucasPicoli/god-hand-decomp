/* sn-2.95.3-136 */
#include "godhand/cE3.h"

extern cE3World D_007474A0;
extern cE3Sys D_00747A2C;
extern char D_0042C7A0[];
extern char D_0042C7B8[];
extern void printf_2E0D60(int a, int b, int c, int d, int e, int f, char *format, ...);

/* Shows the E3 time limit (cursor minutes, 0 = unlimited) and moves it with the pad, clamped to 0..CE3_MENU_LAST. */
__attribute__((section(".text.cE3_menu")))
void cE3_menu(cE3 *self)
{
    cE3Sys *sys = &D_00747A2C;

    if ((sys->flags & CE3_SYS_MENU_ON) == 0) {
        return;
    }
    /* The game work D_007474A0 is D_00747A2C - 0x58C: retail forms it that way. */
    if (((cE3World *)((char *)sys - 0x58C))->menuReady == 0) {
        return;
    }
    if (self->cursor > 0) {
        printf_2E0D60(10, 16, 50, 50, 0, 0, D_0042C7A0, self->cursor);
    } else {
        printf_2E0D60(10, 16, 50, 50, 0, 0, D_0042C7B8);
    }
    if (D_007474A0.edge & CE3_PAD_DOWN) {
        self->cursor++;
    }
    if (D_007474A0.edge & CE3_PAD_UP) {
        self->cursor--;
    }
    self->cursor = self->cursor < 0 ? 0
                 : self->cursor > CE3_MENU_LAST ? CE3_MENU_LAST
                 : self->cursor;
}

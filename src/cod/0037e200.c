/* sn-2.95.3-136: func_0037E200, sound debug menu: move the cursor over the five pages and open the picked one. */

#include "godhand/menuCtl.h"

extern char D_0045C1B8[];
extern char D_0045C1C8[];
extern char *D_003F2888[];
extern void func_002E0DE8(int, int, int, char *, ...);

__attribute__((section(".text.func_0037E200")))
int func_0037E200(MenuCtl *m, MenuPad *pad)
{
    signed char i;

    if (pad->press & MENUPAD_CANCEL) {
        return 0;
    }
    if (pad->trg & MENUPAD_TRG_UP) {
        m->sel = m->sel ? m->sel - 1 : 4;
    }
    if (pad->trg & MENUPAD_TRG_DOWN) {
        if (m->sel < 4) {
            m->sel++;
        } else {
            m->sel = 0;
        }
    }
    if (pad->press & MENUPAD_DECIDE) {
        m->slotNo = 0;
        m->row = 0;
        m->next = m->sel + 1;
        return 1;
    }
    func_002E0DE8(0x15, 3, 0xD, D_0045C1B8);
    for (i = 0; i < 5; i++) {
        func_002E0DE8(0x14, (short)(i + 5), (i == m->sel) ? 0xE : 8, D_0045C1C8, D_003F2888[i]);
    }
    return 1;
}

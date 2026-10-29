/* sn-2.95.3-136 */
#include "godhand/gameWork.h"
#include "godhand/cSnd.h"
#include "godhand/cCoreSave.h"
#include "godhand/seqNode.h"
#include "godhand/cIDMenuPanel.h"
#include "godhand/menuKey.h"

#define OPTION_ROWS      6
#define PAD_WORK_VIBRATION 0x4B8               /* D_005E8140 byte: pad vibration on */

/* The options panel. head.state: 0 = pick a row, 2 = leaving. */
typedef struct OptionPanel {
    cIDPanelHead head;                  /* 0x00 */
    char unk64[0x110 - 0x64];
    signed char row;                    /* 0x110 */
} OptionPanel;

extern cSnd D_005FEE00;
extern unsigned char D_005E8140[];
extern int cSnd_SeCall_2CB8A0(cSnd *self, int slot, short key1, short idA, short idB, int a5, int a6);
extern void SdeSystemOutModeSet(int a0);
extern void func_00167EB0(void *self);

/* Input step of the options panel: moves through the six rows and changes
 * the picked setting (a save flag, the sound output mode, pad vibration). */
__attribute__((section(".text.func_00167908")))
void func_00167908(OptionPanel *self)
{
    switch (self->head.state) {
    case 0:
        switch (self->row) {
        case 0:
            if (D_007474A0.trg & MENU_KEY_OK) {
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_OK, -1, -1, 0, 0);
                self->head.state = 1;
            }
            break;
        case 1:
            if (D_007474A0.rep & MENU_KEY_LEFTRIGHT) {
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
                if (cCoreSave_getStateBit0(&D_00569B70))
                    cCoreSave_clearStateBit0(&D_00569B70);
                else
                    cCoreSave_setStateBit0(&D_00569B70);
            }
            break;
        case 2:
            if (D_007474A0.rep & MENU_KEY_LEFT) {
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
                switch (SdeSystemOutModeGet()) {
                case 1:
                    SdeSystemOutModeSet(0);
                    break;
                case 0:
                    SdeSystemOutModeSet(2);
                    break;
                case 2:
                    SdeSystemOutModeSet(1);
                    break;
                }
            }
            if (D_007474A0.rep & MENU_KEY_RIGHT) {
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
                switch (SdeSystemOutModeGet()) {
                case 1:
                    SdeSystemOutModeSet(2);
                    break;
                case 0:
                    SdeSystemOutModeSet(1);
                    break;
                case 2:
                    SdeSystemOutModeSet(0);
                    break;
                }
            }
            break;
        case 3:
            if (D_007474A0.rep & MENU_KEY_LEFTRIGHT) {
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
                if (D_005E8140[PAD_WORK_VIBRATION])
                    D_005E8140[PAD_WORK_VIBRATION] = 0;
                else
                    D_005E8140[PAD_WORK_VIBRATION] = 1;
            }
            break;
        case 4:
            if (D_007474A0.trg & MENU_KEY_OK) {
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_OK, -1, -1, 0, 0);
                func_00167EB0(self);
            }
            break;
        case 5:
            if (D_007474A0.trg & MENU_KEY_OK) {
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_OK, -1, -1, 0, 0);
                self->head.result = 10;
            }
            break;
        }
        if ((D_007474A0.rep & MENU_KEY_UP) && !(D_007474A0.trg & MENU_KEY_OK)) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
            self->row--;
        } else if ((D_007474A0.rep & MENU_KEY_DOWN) && !(D_007474A0.trg & MENU_KEY_OK)) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
            self->row++;
        }
        self->row = self->row < 0 ? OPTION_ROWS - 1 : self->row < OPTION_ROWS ? self->row : 0;
        if ((D_007474A0.trg & (MENU_KEY_OK | MENU_KEY_BACK)) == MENU_KEY_BACK) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
            self->head.result = 10;
        }
        if ((D_007474A0.trg & (MENU_KEY_OK | MENU_KEY_CLOSE)) == MENU_KEY_CLOSE) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
            self->head.result = -1;
        }
        break;
    case 1:
        break;
    case 2:
        if (D_007474A0.trg & (MENU_KEY_OK | MENU_KEY_BACK)) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
            self->head.state = 3;
        } else if (D_007474A0.trg & MENU_KEY_CLOSE) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
            self->head.result = -1;
        }
        break;
    }
}

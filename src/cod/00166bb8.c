/* sn-2.95.3-136 */
#include "godhand/gameWork.h"
#include "godhand/cSnd.h"
#include "godhand/cCoreSave.h"
#include "godhand/seqNode.h"
#include "godhand/cIDBase.h"

#define MENU_KEY_LEFT    0x0001000001000000L  /* (pad and stick) */
#define MENU_KEY_RIGHT   0x0002000002000000L
#define MENU_KEY_UP      0x0004000008000000L
#define MENU_KEY_DOWN    0x0008000004000000L
#define MENU_KEY_UPDOWN  0x000C00000C000000L
#define MENU_KEY_OK      0x10000000L
#define MENU_KEY_BACK    0x20000000L
#define MENU_KEY_CLOSE   0x200000L

#define MENU_SE_MOVE     0x15F
#define MENU_SE_OK       0x15E
#define MENU_SE_BACK     0x161

#define OPTION_ROWS      8
#define PAD_WORK_VIBRATION 0x4B8               /* D_005E8140 byte: pad vibration on */

#define OPTION_MSG_ASK   0x2008               /* message id of the yes/no question */

/* The pause options panel; 001680d8.c reads the shared panel fields through raw offsets. */
typedef struct PauseOptionPanel {
    char unk00[0x5A];
    signed char state;                  /* 0x5A 0 = pick a row, 2 = leaving, 4 = yes/no */
    char unk5B[0x60 - 0x5B];
    int timer;                          /* 0x60 */
    char unk64[0xC8 - 0x64];
    cIDBaseEnt *ask;                    /* 0xC8 the question's display entry */
    char unkCC[0x130 - 0xCC];
    signed char row;                    /* 0x130 */
    signed char answer;                 /* 0x131 0 = yes, 1 = no */
} PauseOptionPanel;

extern cSnd D_005FEE00;
extern unsigned char D_005E8140[];
extern int cSnd_SeCall_2CB8A0(cSnd *self, int slot, short key1, short idA, short idB, int a5, int a6);
extern void SetGlobalToggle_375700(int a0);
extern void func_001672F0(void *self);

/* Input step of the pause options panel: moves through the eight rows,
 * changes the picked setting (a save flag, the sound output mode, pad
 * vibration) and runs the yes/no question. */
__attribute__((section(".text.func_00166BB8")))
void func_00166BB8(PauseOptionPanel *self)
{
    switch (self->state) {
    case 0:
        switch (self->row) {
        case 0:
            if (D_007474A0.trg & MENU_KEY_OK) {
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_OK, -1, -1, 0, 0);
                self->state = 1;
            }
            break;
        case 1:
            if (D_007474A0.rep & MENU_KEY_UPDOWN) {
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
                if (cCoreSave_getStateBit0(&D_00569B70))
                    cCoreSave_clearStateBit0(&D_00569B70);
                else
                    cCoreSave_setStateBit0(&D_00569B70);
            }
            break;
        case 2:
            if (D_007474A0.rep & MENU_KEY_UP) {
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
                switch (Obj0000_Get_D_0076A7A4_3756F0()) {
                case 1:
                    SetGlobalToggle_375700(0);
                    break;
                case 0:
                    SetGlobalToggle_375700(2);
                    break;
                case 2:
                    SetGlobalToggle_375700(1);
                    break;
                }
            }
            if (D_007474A0.rep & MENU_KEY_DOWN) {
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
                switch (Obj0000_Get_D_0076A7A4_3756F0()) {
                case 1:
                    SetGlobalToggle_375700(2);
                    break;
                case 0:
                    SetGlobalToggle_375700(1);
                    break;
                case 2:
                    SetGlobalToggle_375700(0);
                    break;
                }
            }
            break;
        case 3:
            if (D_007474A0.rep & MENU_KEY_UPDOWN) {
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
                self->timer = 13;
            }
            break;
        case 5:
            if (D_007474A0.trg & MENU_KEY_OK) {
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_OK, -1, -1, 0, 0);
                self->ask->msg = OPTION_MSG_ASK;
                self->answer = 1;
                self->state = 4;
            }
            break;
        case 6:
            if (D_007474A0.trg & MENU_KEY_OK) {
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_OK, -1, -1, 0, 0);
                func_001672F0(self);
            }
            break;
        case 7:
            if (D_007474A0.trg & MENU_KEY_OK) {
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_OK, -1, -1, 0, 0);
                self->timer = 10;
            }
            break;
        }
        if ((D_007474A0.rep & MENU_KEY_LEFT) && !(D_007474A0.trg & MENU_KEY_OK)) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
            self->row--;
        } else if ((D_007474A0.rep & MENU_KEY_RIGHT) && !(D_007474A0.trg & MENU_KEY_OK)) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
            self->row++;
        }
        self->row = self->row < 0 ? OPTION_ROWS - 1 : self->row < OPTION_ROWS ? self->row : 0;
        if ((D_007474A0.trg & (MENU_KEY_OK | MENU_KEY_BACK)) == MENU_KEY_BACK) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
            self->timer = 10;
        }
        if ((D_007474A0.trg & (MENU_KEY_OK | MENU_KEY_CLOSE)) == MENU_KEY_CLOSE) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
            self->timer = -1;
        }
        break;
    case 1:
        break;
    case 2:
        if (D_007474A0.trg & (MENU_KEY_OK | MENU_KEY_BACK)) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
            self->state = 3;
        } else if (D_007474A0.trg & MENU_KEY_CLOSE) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
            self->timer = -1;
        }
        break;
    case 3:
        break;
    case 4:
        if (D_007474A0.trg & MENU_KEY_OK) {
            switch (self->answer) {
            case 0:
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_OK, -1, -1, 0, 0);
                self->timer = 11;
                break;
            case 1:
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
                self->state = 0;
                break;
            }
        } else if (D_007474A0.trg & MENU_KEY_BACK) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
            self->state = 0;
        }
        if (D_007474A0.rep & MENU_KEY_UPDOWN) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
            self->answer ^= 1;
        }
        break;
    }
}

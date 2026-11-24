/* sn-2.95.3-136 matched TU. */
#include "godhand/cSubScrOption.h"
#include "godhand/cCoreSave.h"
#include "godhand/classFADE.h"
#include "godhand/padWork.h"
#include "godhand/seqNode.h"
#include "godhand/cIDBase.h"

#define OPTION_MSG_ROW      0x2000      /* message of row n is this + n */
#define OPTION_MSG_ASK      0x2008      /* message of the yes/no question */

/* Each frame of the options panel: show the entries for the row under the
 * cursor and the current settings, run the fade to and from the second
 * display, set the messages and move both displays. */
__attribute__((section(".text.func_00166780")))
void func_00166780(cSubScrOption *self)
{
    func_00167328(self);
    self->ent[self->row]->flags &= ~IDENT_FLAG_NO_DRAW;
    if (cCoreSave_getStateBit0(&D_00569B70)) {
        self->ent[9]->flags &= ~IDENT_FLAG_NO_DRAW;
    } else {
        self->ent[8]->flags &= ~IDENT_FLAG_NO_DRAW;
    }
    switch (SdeSystemOutModeGet()) {
    case 1:
        self->ent[10]->flags &= ~IDENT_FLAG_NO_DRAW;
        break;
    case 0:
        self->ent[11]->flags &= ~IDENT_FLAG_NO_DRAW;
        break;
    case 2:
        self->ent[12]->flags &= ~IDENT_FLAG_NO_DRAW;
        break;
    }
    if (D_005E8140[PAD_WORK_VIBRATION]) {
        self->ent[13]->flags &= ~IDENT_FLAG_NO_DRAW;
    } else {
        self->ent[14]->flags &= ~IDENT_FLAG_NO_DRAW;
    }
    self->ent[15]->flags &= ~IDENT_FLAG_NO_DRAW;
    self->ent[15]->posY = D_0041FB70[self->row];

    switch (self->obj.state) {
    case 0:
    case 2:
        break;
    case 1:
        switch (D_003BD9E8) {
        case 0:
            classFADE_start(&D_00747470, 0, 10, 0, 0, 0xFF000000, 15);
            D_003BD9E8++;
            break;
        case 1:
            if (D_00747470.state >> FADE_STATE_DONE_BIT & 1) {
                D_003BD9E8 = 2;
            }
            break;
        case 2:
            classFADE_start(&D_00747470, 0, 8, 0, 0xFF000000, 0, 15);
            D_003BD9E8++;
            break;
        case 3:
            if (D_00747470.state != 0) {
                self->obj.state = 2;
                D_003BD9E8 = 0;
            }
            break;
        }
        break;
    case 3:
        switch (D_003BD9E8) {
        case 0:
            classFADE_start(&D_00747470, 0, 10, 0, 0, 0xFF000000, 15);
            D_003BD9E8++;
            break;
        case 1:
            if (D_00747470.state >> FADE_STATE_DONE_BIT & 1) {
                D_003BD9E8 = 2;
            }
            break;
        case 2:
            classFADE_start(&D_00747470, 0, 8, 0, 0xFF000000, 0, 15);
            D_003BD9E8++;
            break;
        case 3:
            if (D_00747470.state != 0) {
                self->obj.state = 0;
                D_003BD9E8 = 0;
            }
            break;
        }
        break;
    case 4:
        self->ent[15]->flags |= IDENT_FLAG_NO_DRAW;
        self->ent[18]->flags &= ~IDENT_FLAG_NO_DRAW;
        switch (self->answer) {
        case 0:
            self->ent[22]->flags &= ~IDENT_FLAG_NO_DRAW;
            break;
        case 1:
            self->ent[23]->flags &= ~IDENT_FLAG_NO_DRAW;
            break;
        }
        break;
    }

    self->ent[16]->flags &= ~IDENT_FLAG_NO_DRAW;
    self->ent[17]->flags &= ~IDENT_FLAG_NO_DRAW;
    self->ent[19]->flags &= ~IDENT_FLAG_NO_DRAW;
    self->ent[20]->flags &= ~IDENT_FLAG_NO_DRAW;
    self->ent[21]->flags &= ~IDENT_FLAG_NO_DRAW;
    if (self->obj.state != 4) {
        self->ent[16]->msg = self->row + OPTION_MSG_ROW;
        self->ent[17]->msg = self->row + OPTION_MSG_ROW;
    } else {
        self->ent[16]->msg = OPTION_MSG_ASK;
        self->ent[17]->msg = OPTION_MSG_ASK;
    }
    self->ent[18]->msg = 0x300D;
    self->ent[19]->msg = 0x300D;
    self->ent[20]->msg = 0x300E;
    self->ent[21]->msg = 0x300E;
    cIDBase_move(&self->sub);
    cIDBase_move(&self->obj.base);
}

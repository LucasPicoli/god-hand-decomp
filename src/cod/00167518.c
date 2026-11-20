/* sn-2.95.3-136 matched TU. */
#include "godhand/cSubScrOption.h"
#include "godhand/cCoreSave.h"
#include "godhand/classFADE.h"
#include "godhand/padWork.h"
#include "godhand/seqNode.h"
#include "godhand/cIDBase.h"

/* Each frame of the options variant: show the entries for the row under the
 * cursor and the current settings, run the fade to and from the second
 * display, set the row's message and move both displays. */
__attribute__((section(".text.func_00167518")))
void func_00167518(cSubScrOptionT *self)
{
    SetFlagOnChildren_167EE8(self);
    self->ent[self->row]->flags &= ~IDENT_FLAG_NO_DRAW;
    if (cCoreSave_getStateBit0(&D_00569B70)) {
        self->ent[7]->flags &= ~IDENT_FLAG_NO_DRAW;
    } else {
        self->ent[6]->flags &= ~IDENT_FLAG_NO_DRAW;
    }
    switch (SdeSystemOutModeGet()) {
    case 0:
        self->ent[8]->flags &= ~IDENT_FLAG_NO_DRAW;
        break;
    case 1:
        self->ent[9]->flags &= ~IDENT_FLAG_NO_DRAW;
        break;
    case 2:
        self->ent[10]->flags &= ~IDENT_FLAG_NO_DRAW;
        break;
    }
    if (D_005E8140[PAD_WORK_VIBRATION]) {
        self->ent[11]->flags &= ~IDENT_FLAG_NO_DRAW;
    } else {
        self->ent[12]->flags &= ~IDENT_FLAG_NO_DRAW;
    }
    self->ent[13]->flags &= ~IDENT_FLAG_NO_DRAW;
    self->ent[13]->posX = self->ent[self->row]->posX - 11.0f;
    self->ent[13]->posY = self->ent[self->row]->posY + 13.0f;

    switch (self->obj.state) {
    case 0:
    case 2:
        break;
    case 1:
        switch (D_003BD9E9) {
        case 0:
            classFADE_start(&D_00747470, 0, 10, 0, 0, 0xFF000000, 15);
            D_003BD9E9++;
            break;
        case 1:
            if (D_00747470.state >> 2 & 1) {
                D_003BD9E9 = 2;
            }
            break;
        case 2:
            classFADE_start(&D_00747470, 0, 8, 0, 0xFF000000, 0, 15);
            D_003BD9E9++;
            break;
        case 3:
            if (D_00747470.state != 0) {
                self->obj.state = 2;
                D_003BD9E9 = 0;
            }
            break;
        }
        break;
    case 3:
        switch (D_003BD9E9) {
        case 0:
            classFADE_start(&D_00747470, 0, 10, 0, 0, 0xFF000000, 15);
            D_003BD9E9++;
            break;
        case 1:
            if (D_00747470.state >> 2 & 1) {
                D_003BD9E9 = 2;
            }
            break;
        case 2:
            classFADE_start(&D_00747470, 0, 8, 0, 0xFF000000, 0, 15);
            D_003BD9E9++;
            break;
        case 3:
            if (D_00747470.state != 0) {
                self->obj.state = 0;
                D_003BD9E9 = 0;
            }
            break;
        }
        break;
    }

    self->ent[14]->flags &= ~IDENT_FLAG_NO_DRAW;
    self->ent[15]->flags &= ~IDENT_FLAG_NO_DRAW;
    switch (self->row) {
    case 0:
        self->ent[14]->msg = 0x2000;
        self->ent[15]->msg = 0x2000;
        break;
    case 1:
        self->ent[14]->msg = 0x2001;
        self->ent[15]->msg = 0x2001;
        break;
    case 2:
        self->ent[14]->msg = 0x2002;
        self->ent[15]->msg = 0x2002;
        break;
    case 3:
        self->ent[14]->msg = 0x2003;
        self->ent[15]->msg = 0x2003;
        break;
    case 4:
        self->ent[14]->msg = 0x2006;
        self->ent[15]->msg = 0x2006;
        break;
    case 5:
        self->ent[14]->msg = 0x2007;
        self->ent[15]->msg = 0x2007;
        break;
    }
    cIDBase_move(&self->sub);
    cIDBase_move(&self->obj.base);
}

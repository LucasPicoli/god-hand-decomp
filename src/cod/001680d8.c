/* sn-2.95.3-136: func_001680D8, menu panel fade in/out plus the left/right arrow highlight. */
#include "godhand/cIDMenuPanel.h"
extern char *D_003BD930;
extern void cIDBase_move(void *p);

/* The marks' flags and x are written through their addresses: as cIDBaseEnt fields (an
 * unsigned word and a float) gcc orders the stores around the D_003BD930 load differently. */
#define ENT_FLAGS(e)  (*(int *)((char *)(e) + 0x2C))      /* cIDBaseEnt.flags */
#define ENT_POSX(e)   (*(float *)((char *)(e) + 0x38))    /* cIDBaseEnt.posX */

__attribute__((section(".text.func_001680D8")))
void func_001680D8(cIDMenuPanel *self)
{
    switch (self->head.state) {
    case 0:
        self->alpha += 0x10;
        if (self->alpha > 0x80) {
            self->head.state = 1;
            self->alpha = 0x80;
        }
        break;
    case 1:
        self->alpha = 0x80;
        break;
    case 2: {
        int v;

        if (self->reopen == 1) {
            self->alpha = 0x80;
            self->head.result = 0xA;
            self->head.state = 0;
        }
        v = self->alpha - 0x10;
        if (v < 0) {
            self->alpha = 0;
            self->head.result = -1;
            self->head.state = 0;
        } else {
            self->alpha = v;
        }
        break;
    }
    }
    self->frame->colorBase.c[3] = self->alpha;
    switch (self->choice) {
    case -1:
        ENT_FLAGS(self->backMark) &= ~IDENT_FLAG_NO_DRAW;
        ENT_FLAGS(self->cursor) |= IDENT_FLAG_NO_DRAW;
        D_003BD930[0xEDD] = 0;
        break;
    case 0:
        ENT_FLAGS(self->backMark) |= IDENT_FLAG_NO_DRAW;
        ENT_FLAGS(self->cursor) &= ~IDENT_FLAG_NO_DRAW;
        ENT_POSX(self->cursor) = -184.0f;
        D_003BD930[0xEDD] = 0;
        break;
    case 1:
        ENT_FLAGS(self->backMark) |= IDENT_FLAG_NO_DRAW;
        ENT_FLAGS(self->cursor) &= ~IDENT_FLAG_NO_DRAW;
        ENT_POSX(self->cursor) = 44.0f;
        D_003BD930[0xEDD] = 1;
        break;
    }
    cIDBase_move(self);
}

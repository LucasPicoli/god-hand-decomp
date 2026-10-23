/* sn-2.95.3-136: func_001680D8, menu panel fade in/out plus the left/right arrow highlight. */
#include "godhand/cIDBase.h"
extern char *D_003BD930;
extern void cIDBase_move(void *p);

/* A menu panel built on cIDBase: it fades in, lets the pad pick an answer (-1, 0 or 1)
 * and fades out. */
typedef struct cIDMenuPanel {
    cIDBaseObj base;                    /* 0x00 */
    char unk48[0x5A - 0x48];
    signed char state;                  /* 0x5A 0 fade in, 1 shown, 2 fade out */
    char unk5B[0x60 - 0x5B];
    int result;                         /* 0x60 7 once an answer is decided, -1 when the panel has faded out */
    unsigned char reopen;               /* 0x64 1 sends a fading panel back to fade in */
    char unk65[0x80 - 0x65];
    cIDBaseEnt *frame;                  /* 0x80 its alpha follows the fade */
    cIDBaseEnt *backMark;               /* 0x84 shown while the answer is -1 */
    cIDBaseEnt *cursor;                 /* 0x88 shown on answer 0 or 1 */
    char unk8C[0x90 - 0x8C];
    unsigned char alpha;                /* 0x90 */
    signed char choice;                 /* 0x91 -1, 0 or 1 */
} cIDMenuPanel;

/* The marks' flags and x are written through their addresses: as cIDBaseEnt fields (an
 * unsigned word and a float) gcc orders the stores around the D_003BD930 load differently. */
#define ENT_FLAGS(e)  (*(int *)((char *)(e) + 0x2C))      /* cIDBaseEnt.flags */
#define ENT_POSX(e)   (*(float *)((char *)(e) + 0x38))    /* cIDBaseEnt.posX */

__attribute__((section(".text.func_001680D8")))
void func_001680D8(cIDMenuPanel *self)
{
    switch (self->state) {
    case 0:
        self->alpha += 0x10;
        if (self->alpha > 0x80) {
            self->state = 1;
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
            self->result = 0xA;
            self->state = 0;
        }
        v = self->alpha - 0x10;
        if (v < 0) {
            self->alpha = 0;
            self->result = -1;
            self->state = 0;
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

/* sn-2.95.3-136 */
#include "godhand/idSet.h"

extern void cIDBase_move(cIDBaseObj *self);

extern unsigned char D_003BD6E0;    /* swing direction of element 10: 1 swings up, 0 swings down */

/* Bit 0 of the active byte is clear. */
static __inline__ int IdSet_isStopped(IdSet *self)
{
    return (self->active & 1) == 0;
}

/* Elements 7 and 8 show the message when one is set, and are hidden otherwise. */
static __inline__ void IdSet_showMsg(IdSet *self)
{
    if (self->msg != -1) {
        self->work[7]->flags &= ~IDENT_FLAG_NO_DRAW;
        self->work[7]->msg = self->msg;
        self->work[8]->flags &= ~IDENT_FLAG_NO_DRAW;
        self->work[8]->msg = self->msg;
    } else {
        self->work[7]->flags |= IDENT_FLAG_NO_DRAW;
        self->work[8]->flags |= IDENT_FLAG_NO_DRAW;
    }
}

/* Id set update: hide every element group, then show the group of the current step and animate it. */
__attribute__((section(".text.func_0013BD40")))
void func_0013BD40(IdSet *self)
{
    unsigned short i;

    if (IdSet_isStopped(self))
        return;
    for (i = 1; i < 5; i++)
        self->work[i]->flags |= IDENT_FLAG_NO_DRAW;
    self->work[11]->flags |= IDENT_FLAG_NO_DRAW;
    self->work[10]->flags |= IDENT_FLAG_NO_DRAW;
    self->work[6]->flags |= IDENT_FLAG_NO_DRAW;
    self->work[5]->flags |= IDENT_FLAG_NO_DRAW;
    self->work[9]->flags |= IDENT_FLAG_CHILD;
    self->work[12]->flags |= IDENT_FLAG_NO_DRAW;
    self->work[0]->posX = self->x;
    self->work[0]->posY = self->y;
    IdSet_showMsg(self);
    switch (self->step) {
    case 0:
    case 1:
    case 2:
    case 3:
        self->work[6]->flags &= ~IDENT_FLAG_NO_DRAW;
        self->work[5]->flags &= ~IDENT_FLAG_NO_DRAW;
        if (self->step < 4)
            self->work[self->step + 1]->flags &= ~IDENT_FLAG_NO_DRAW;
        break;
    case 4:
        self->work[9]->flags &= ~IDENT_FLAG_CHILD;
        self->work[10]->flags &= ~IDENT_FLAG_NO_DRAW;
        if (D_003BD6E0 == 1) {
            self->work[10]->rotSpeed += 0.52359903f;
            self->work[10]->posX += 5.0f;
            if (0.52359867f < self->work[10]->rotSpeed) {
                self->work[10]->rotSpeed = 0.52359867f;
                self->work[10]->posX = 5.0f;
                D_003BD6E0 = 0;
            }
        } else {
            self->work[10]->rotSpeed -= 0.52359903f;
            self->work[10]->posX -= 5.0f;
            if (self->work[10]->rotSpeed < -0.52359867f) {
                self->work[10]->rotSpeed = -0.52359867f;
                self->work[10]->posX = -5.0f;
                D_003BD6E0 = 1;
            }
        }
        IdSet_showMsg(self);
        break;
    case 5:
        self->work[11]->flags &= ~IDENT_FLAG_NO_DRAW;
        self->work[11]->posY += 4.0f;
        if (self->work[11]->src->posY + 10.0f < self->work[11]->posY)
            self->work[11]->posY = self->work[11]->src->posY;
        break;
    case 6:
        self->work[12]->flags &= ~IDENT_FLAG_NO_DRAW;
        self->work[12]->posX -= 6.0f;
        if (self->work[12]->posX < self->work[12]->src->posX - 20.0f)
            self->work[12]->posX = self->work[12]->src->posX;
        break;
    }
    cIDBase_move(&self->base);
}

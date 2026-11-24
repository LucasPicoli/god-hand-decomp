/* sn-2.95.3-136 matched TU. */
#include "godhand/cCockScroll.h"
#include "godhand/cMessDrawFontCode.h"

/* cCockScroll's banner step. Slide entry 0 down, grow entry 1, show the
 * queued message for 90 frames, shrink entry 1 and move entry 0 out, then
 * pop both queues and start again. */
__attribute__((section(".text.func_00146A18")))
void func_00146A18(cCockScroll *self)
{
    unsigned short i;
    unsigned int j;
    float low;

    if (self->state[0] != COCKSCROLL_STEP_WAIT && self->state[0] != COCKSCROLL_STEP_POP) {
        if (self->kindQueue[0] == 0) {
            for (i = 0; i < COCKSCROLL_WORK_NUM; i++)
                self->work[i] = cIDBase_getIDWork(&self->base, i);
        } else {
            for (i = 0; i < COCKSCROLL_WORK_NUM; i++)
                self->work[i] = cIDBase_getIDWork(&self->part2, i);
        }
    }
    low = 0.0f;
    if (self->flags & COCKSCROLL_FLAG_LOW)
        low = 50.0f;
    self->flags &= ~COCKSCROLL_FLAG_LOW;
    switch (self->state[0]) {
    case COCKSCROLL_STEP_WAIT:
        if (self->count != 0)
            self->state[0]++;
        break;
    case COCKSCROLL_STEP_DROP:
        /* spins at 3 pi times the share of the drop already done */
        self->work[0]->posY += 10.0f;
        self->work[0]->rotSpeed = (1.0f - (self->work[0]->src->posY - self->work[0]->posY)
                                   / (self->work[0]->src->posY - COCKSCROLL_TOP)) * 9.424776f;
        if (self->work[0]->src->posY + low < self->work[0]->posY) {
            self->work[0]->rotSpeed = 0.0f;
            self->work[0]->posY = self->work[0]->src->posY + low;
            self->state[0]++;
        }
        break;
    case COCKSCROLL_STEP_GROW:
        self->work[1]->sclX += 0.3f;
        self->work[1]->flags &= ~IDENT_FLAG_NO_DRAW;
        if (self->work[1]->sclX > 1.3f) {
            self->work[1]->sclX = 1.3f;
            self->timer = COCKSCROLL_SHOW_TIME;
            self->state[0]++;
        }
        break;
    case COCKSCROLL_STEP_SHOW:
        /* the short at 0xBEE is ScriptState.half (0012cae0.c), which
         * GetField_BEE_2B1290 also reads; raw because cMessDrawFontCode.h
         * declares D_003C23A4 as int and ScriptState is local to 0012cae0.c */
        *(unsigned short *)(D_003C23A4 + 0xBEE) = self->msgQueue[0];
        self->work[2]->msg = 0x30F0;
        self->work[2]->flags &= ~IDENT_FLAG_NO_DRAW;
        if (--self->timer < 0) {
            self->work[2]->flags |= IDENT_FLAG_NO_DRAW;
            self->state[0]++;
        }
        break;
    case COCKSCROLL_STEP_SHRINK:
        self->work[1]->sclX -= 0.3f;
        if (self->work[1]->sclX < 0.0f) {
            self->work[1]->flags |= IDENT_FLAG_NO_DRAW;
            self->work[1]->sclX = 0.0f;
            self->state[0]++;
        }
        break;
    case COCKSCROLL_STEP_LEAVE:
        /* tests x but resets y: retail uses the one -50 (COCKSCROLL_TOP) as the
         * x exit bound and as entry 0's start y for the next message */
        self->work[0]->posX -= 10.0f;
        if (self->work[0]->posX < COCKSCROLL_TOP) {
            self->work[0]->posY = COCKSCROLL_TOP;
            self->state[0]++;
        }
        break;
    case COCKSCROLL_STEP_POP:
        for (j = 0; j < self->count - 1; j++) {
            self->msgQueue[j] = self->msgQueue[j + 1];
            self->kindQueue[j] = self->kindQueue[j + 1];
        }
        self->msgQueue[self->count - 1] = 0;
        self->kindQueue[self->count - 1] = 0;
        self->count--;
        cCockScroll_reset(self);
        self->state[0] = COCKSCROLL_STEP_WAIT;
        break;
    }
    if (self->state[0] != COCKSCROLL_STEP_WAIT && self->state[0] != COCKSCROLL_STEP_POP) {
        if (self->kindQueue[0] == 0) {
            self->work[3]->msg = 0x30F1;
            cIDBase_move(&self->base);
        } else {
            self->work[3]->msg = 0x30C5;
            cIDBase_move(&self->part2);
        }
    }
}

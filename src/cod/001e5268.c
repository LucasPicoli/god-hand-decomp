/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"
#include "godhand/Slot2.h"

extern void func_001E8E48(void *a, void *b);
extern int cSnd_SeCall(void *a0, int a1, short a2, int a3, int a4, int a5);
extern unsigned char D_005FEE00[];

/* sn-2.95.3-136 matched TU. */





static inline unsigned char tick(int *p)
{
    if (*p != 0) {
        *p = *p - 1;
        return 0;
    }
    return 1;
}

/* Slot2 start-up screen: set the board, start the reels one after another,
 * then return to the title state once all three have settled. */
__attribute__((section(".text.func_001E5268")))
void func_001E5268(Slot2 *self)
{
    unsigned char buf[16] __attribute__((aligned(16)));
    Slot2Reel *reel;

    switch (self->step) {
    case 0:
        {
            Slot2Panel *p = &self->panel;
            p->phase = 0;
            p->step = 0;
            p->state = 2;
        }
        self->step = self->step + 1;
        /* fall through */
    case 1:
        {
            long done = self->panel.doneFlag;
            if ((done & 1) == 0) return;
        }
        VU0_SQC2_VF0(buf, 0);
        reel = &self->reel[0];
        func_001E8E48(reel, buf);
        self->seId[0] = cSnd_SeCall(&D_005FEE00, 2, 1, (int)buf, 0, 0);
        {
            long done = self->reel[0].doneFlag;
            if ((done & 1) == 0) goto skip118;
        }
        reel->step = 0;
        reel->state = 2;
        reel->phase = 0;
    skip118:
        self->timer = 5;
        self->step = self->step + 1;
        return;
    case 2:
        if (tick(&self->timer) == 0) return;
        {
            Slot2Reel *r = &self->reel[1];
            long done = self->reel[1].doneFlag;
            if ((done & 1) == 0) goto skip200;
            r->step = 0;
            r->state = 2;
            r->phase = 0;
        }
    skip200:
        self->timer = 5;
        self->step = self->step + 1;
        return;
    case 3:
        if (tick(&self->timer) == 0) return;
        {
            Slot2Reel *r = &self->reel[2];
            long done = self->reel[2].doneFlag;
            if ((done & 1) == 0) goto skip2E8;
            r->step = 0;
            r->state = 2;
            r->phase = 0;
        }
    skip2E8:
        self->step = self->step + 1;
        return;
    case 4:
        {
            long done = self->reel[0].doneFlag;
            if (((done >> 1) & 1) == 0) return;
        }
        {
            long done = self->reel[1].doneFlag;
            if (((done >> 1) & 1) == 0) return;
        }
        {
            long done = self->reel[2].doneFlag;
            if (((done >> 1) & 1) == 0) return;
        }
        self->step = 0;
        self->state = 2;
        self->phase = 0;
        return;
    }
}

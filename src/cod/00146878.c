#include "godhand/cCockScroll.h"

extern void cIDBase_restartAnim(void *);

__attribute__((section(".text.func_00146878")))
void func_00146878(cCockScroll *self)
{
    cCockScroll_reset(self);
    self->count = 0;
    cIDBase_restartAnim(self);
    self->base.playing = 1;
}

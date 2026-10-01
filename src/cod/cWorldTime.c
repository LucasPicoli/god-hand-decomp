/* TU: cWorldTime - recovered C++ class. */
#include "godhand/cWorldTime.h"

extern void func_002D9D50(cWorldTime *self, unsigned int ticks, unsigned int *h, unsigned int *m, unsigned int *s);
/* Split the stage tick counter into hours, minutes and seconds. */
__attribute__((section(".text.cWorldTime_getStageHMS")))
void cWorldTime_getStageHMS(cWorldTime *self, unsigned int *h, unsigned int *m, unsigned int *s)
{
    func_002D9D50(self, self->stageTime, h, m, s);
}

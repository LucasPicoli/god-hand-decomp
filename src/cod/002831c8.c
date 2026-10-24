/* sn-2.95.3-136 */
#include "godhand/cGameObj.h"

static inline void cGameObj_setState(cGameObj *self, unsigned char phase, unsigned char step, unsigned char arg)
{
    self->stepArg = arg;
    self->phase = phase;
    self->step = step;
    self->mode = 0;
}

/* Starts phase 3 at the step for `kind`: 0, 2, 4 or 6 for kinds 0 to 3. */
__attribute__((section(".text.func_002831C8")))
void func_002831C8(cGameObj *self, unsigned int kind, unsigned char arg)
{
    switch (kind) {
    default:
    case 0:
        cGameObj_setState(self, 3, 0, arg);
        break;
    case 1:
        cGameObj_setState(self, 3, 2, arg);
        break;
    case 2:
        cGameObj_setState(self, 3, 4, arg);
        break;
    case 3:
        cGameObj_setState(self, 3, 6, arg);
        break;
    }
}

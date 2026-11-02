#include "godhand/cEm00.h"
#include "godhand/motion.h"

/* func_00282080 — +0x2F6 phase machine (record fields 0x7C/0x80, mode 5) with the
 * func_002A8578 t0 = flag@0x15B0 ? 2 : 0, plus the moveMotion-done reset of the
 * 0x2F4..0x2F7 phase block.  sn-2.95.3-136. */
extern int moveMotion(void *a0);
/* Phase machine on the step byte, 2 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_00282080"))) void func_00282080(cEm00 *self)
{
    int res;
    int t0 = 0;
    unsigned long two = 2;
    if (*(unsigned char *)((char *)self + 0x15B0))
        t0 = two;
    switch (self->step) {
        case 0:
            res = EM_RES(self);
            func_002A8578(self, EM_RES_REC(res, 0x7C), EM_RES_REC(res, 0x80), 5, 0.0f, t0, 0);
            self->step = self->step + 1;
        case 1:
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0;
                self->step = 0;
                self->stepArg = 0;
            }
            break;
    }
}

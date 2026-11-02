#include "godhand/cEm00.h"
#include "godhand/motion.h"

/* sn-2.95.3-136 matched TU. */

extern int moveMotion(void *a0);

/* sn-2.95.3-136 matched TU. */




/* Phase machine on the step byte, 8 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_002827C8"))) void func_002827C8(cEm00 *self)
{
    int res;
    int t0 = 0;
    unsigned long two = 2;
    if (*(unsigned char *)((char *)self + 0x15B0))
        t0 = two;
    switch (self->step) {
        case 0:
            switch (self->stepArg) {
                default:
                case 0:
                    res = self->resource;
                    func_002A8578(self, EM_RES_REC(res, 0xC0), EM_RES_REC(res, 0xC4), 2, 0.0f, t0,
                                  0);
                    break;
                case 1:
                    res = self->resource;
                    func_002A8578(self, EM_RES_REC(res, 0xB8), EM_RES_REC(res, 0xBC), 2, 0.0f, t0,
                                  0);
                    break;
                case 2:
                    res = self->resource;
                    func_002A8578(self, EM_RES_REC(res, 0xC8), EM_RES_REC(res, 0xCC), 2, 0.0f, t0,
                                  0);
                    break;
                case 3:
                    res = self->resource;
                    func_002A8578(self, EM_RES_REC(res, 0xD0), EM_RES_REC(res, 0xD4), 2, 0.0f, t0,
                                  0);
                    break;
                case 4:
                    res = self->resource;
                    func_002A8578(self, EM_RES_REC(res, 0xD8), EM_RES_REC(res, 0xDC), 2, 0.0f, t0,
                                  0);
                    break;
                case 5:
                    res = self->resource;
                    func_002A8578(self, EM_RES_REC(res, 0xD0), EM_RES_REC(res, 0xD4), 2, 0.0f, t0,
                                  0);
                    break;
            }
            self->step++;
            /* fallthrough */
        case 1:
            moveMotion(self);
            break;
    }
}

#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern int GetSeqSEBase(void *a0);
extern int D_005FEE00[];

/* sn-2.95.3-136 matched TU. */








/* Phase machine on the step byte, 8 case labels. Calls func_002A8578, cSnd_SeCall_2CBA48,
 * GetSeqSEBase, moveMotion. */
__attribute__((section(".text.func_002804F8"))) void func_002804F8(cEm00 *self)
{
    unsigned long t0 = 0;
    switch (self->step) {
        case 0:
            switch (self->stepArg) {
                default:
                case 0: {
                    int v = self->resource;
                    func_002A8578(self, EM_RES_REC(v, 0xA8), EM_RES_REC(v, 0xAC), 0.0f, 2, t0, 0);
                    break;
                }
                case 1: {
                    int v = self->resource;
                    func_002A8578(self, EM_RES_REC(v, 0xA0), EM_RES_REC(v, 0xA4), 0.0f, 2, t0, 0);
                    break;
                }
                case 2: {
                    int v = self->resource;
                    func_002A8578(self, EM_RES_REC(v, 0xB0), EM_RES_REC(v, 0xB4), 0.0f, 2, t0, 0);
                    break;
                }
                case 3: {
                    int v = self->resource;
                    func_002A8578(self, EM_RES_REC(v, 0xB8), EM_RES_REC(v, 0xBC), 0.0f, 2, t0, 0);
                    break;
                }
                case 4: {
                    int v = self->resource;
                    func_002A8578(self, EM_RES_REC(v, 0xC0), EM_RES_REC(v, 0xC4), 0.0f, 2, t0, 0);
                    break;
                }
                case 5: {
                    int v = self->resource;
                    func_002A8578(self, EM_RES_REC(v, 0xC8), EM_RES_REC(v, 0xCC), 0.0f, 2, t0, 0);
                    break;
                }
            }
            cSnd_SeCall_2CBA48(D_005FEE00, 1, (short)GetSeqSEBase(self), self, 0, 0, 0, 0);
            self->step++;
        case 1:
            moveMotion(self);
            break;
    }
}

/* sn-2.95.3-136: option cursor (0xBC) driven by the pad repeat bits, confirm/cancel SEs. */
#include "godhand/cSnd.h"
#include "godhand/gameWork.h"
#include "godhand/globals.h"
extern int func_00161B30(char *self);

__attribute__((section(".text.func_00161990")))
void func_00161990(char *self)
{
    if (D_007474A0.rep & 0x1000001000000L) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
        self[0xBC]--;
    } else if (D_007474A0.rep & 0x2000002000000L) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
        self[0xBC]++;
    }
    if (D_00747A28 & 0x400000) {
        self[0xBC] = *(signed char *)(self + 0xBC) < 0 ? 3
                   : *(signed char *)(self + 0xBC) < 4 ? *(unsigned char *)(self + 0xBC) : 0;
    } else {
        self[0xBC] = *(signed char *)(self + 0xBC) < 0 ? 0
                   : *(signed char *)(self + 0xBC) > 0 ? 0 : *(unsigned char *)(self + 0xBC);
    }
    if (D_007474A0.trg & 0x10000000) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x15E, -1, -1, 0, 0);
        *(int *)(self + 0x60) = 0xE;
    } else if (D_007474A0.trg & 0x20000000) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x161, -1, -1, 0, 0);
        func_00161B30(self);
    }
}

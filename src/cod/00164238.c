#include "godhand/cSnd.h"
#include "godhand/gameWork.h"
extern void func_001645E0(char *self);

__attribute__((section(".text.func_00164238")))
void func_00164238(char *self)
{
    if (*(signed char *)(self + 0x5B) != 2 || *(signed char *)(self + 0x5C) != 2) {
        return;
    }
    if (D_007474A0.rep & 0x1000001000000L) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
        *(short *)(self + 0x130) = *(unsigned short *)(self + 0x130) - 1;
    }
    if (D_007474A0.rep & 0x2000002000000L) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
        *(short *)(self + 0x130) = *(unsigned short *)(self + 0x130) + 1;
    }
    *(short *)(self + 0x130) = *(short *)(self + 0x130) < 0 ? 3
                             : *(short *)(self + 0x130) < 4 ? *(unsigned short *)(self + 0x130) : 0;
    if (D_007474A0.trg & 0x10000000) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x15E, -1, -1, 0, 0);
        *(int *)(self + 0x60) = -1;
        switch (*(short *)(self + 0x130)) {
        case 0:
            *(unsigned short *)(self + 0x134) = 0xFFFF;
            *(int *)(self + 0x60) = 0xC;
            break;
        case 1:
            func_001645E0(self);
            return;
        case 2:
            *(short *)(self + 0x136) = 1;
        clear:
            *(short *)(self + 0x134) = 0;
            break;
        case 3:
            *(short *)(self + 0x136) = 0;
            goto clear;
        }
    }
}

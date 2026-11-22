/* sn-2.95.3-136: menu slot status message for a slot kind (0x380048). */
#include "godhand/globals.h"
extern void func_002E0DE8(int a0, int a1, int a2, const char *fmt, ...);

__attribute__((section(".text.func_00380048")))
void func_00380048(unsigned char *self, char *pad, unsigned char kind)
{
    unsigned char *st;

    if (kind == 8) {
        st = self + self[5] * 0x48 + 0x49;
    } else {
        st = self + 0x319;
        if (kind != 9) {
            st = kind == 0xA ? self + 0x371 : self + 0x471;
        }
    }
    if (*(int *)(pad + 0x34) & 0x40) {
        self[2] = 1;
        *st = 0;
        return;
    }
    if (*st == 2) {
        func_002E0DE8(3, 0x14, 0xA, D_003F28B0[kind - 8]);
    } else {
        func_002E0DE8(3, 0x14, 0xA, D_003F28A0[*st - 1]);
    }
    func_002E0DE8(3, 0x15, 0xA, D_0045C328);
}

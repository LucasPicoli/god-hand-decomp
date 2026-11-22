/* cygnus-2.96, CRI ADX: stereo decode dispatch on the D_003EC660 mode flag. */
#include "godhand/globals.h"
extern void ADX_DecodeSte4AsSte(int a0, int a1, int a2, int a3, int a4, int a5,
                                short k0, short k1, int a8, short d0, short d1);
extern void func_003420E0(int a0, int a1, int a2, int a3, int a4, int a5,
                          short k0, short k1, int a8, short d0, short d1);

__attribute__((section(".text.func_003427F0")))
void func_003427F0(int a0, int a1, int a2, int a3, int a4, int a5,
                   short k0, short k1, int a8, short d0, short d1)
{
    if (D_003EC660 == 0) {
        ADX_DecodeSte4AsSte(a0, a1, a2, a3, a4, a5, k0, k1, a8, d0, d1);
        return;
    }
    func_003420E0(a0, a1, a2, a3, a4, a5, k0, k1, a8, d0, d1);
}

#include "godhand/globals.h"
extern void func_0035FEE8(void);
extern void func_0036CAA8(void);
extern void func_0035FE78(void);
extern void func_00360CC8(void);

__attribute__((section(".text.func_0035F900")))
void func_0035F900(void)
{
    if (D_003EE330 > 0) {
        func_0035FEE8();
        func_0036CAA8();
        func_0035FE78();
        func_00360CC8();
        D_003EE330 -= 1;
    }
}

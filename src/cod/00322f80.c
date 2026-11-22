#include "godhand/globals.h"
extern int func_00324500(int h);
extern int OpenStreamHandle(int h);
extern void func_00322F18(void);

__attribute__((section(".text.func_00322F80")))
void func_00322F80(void)
{
    if (D_003EB838 != 0 && D_003EB83C >= 0) {
        if (func_00324500(D_003EB838) != 1) {
            OpenStreamHandle(D_003EB838);
        }
        D_003EB840 = 1;
        func_00322F18();
    }
}

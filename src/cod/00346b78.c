#include "godhand/globals.h"
extern void MWSFSVM_Error(void *);
extern int SFD_SetCond(int, int, int);

__attribute__((section(".text.func_00346B78")))
void func_00346B78(int condition)
{
    if ((unsigned int)(condition + 1) >= 3)
        MWSFSVM_Error(D_00458848);
    else
        SFD_SetCond(0, 0x3D, condition);
}

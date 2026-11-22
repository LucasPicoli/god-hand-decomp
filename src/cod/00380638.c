#include "godhand/globals.h"
extern void func_002E0DE8(int a0, int a1, int a2, const char *fmt, ...);

__attribute__((section(".text.func_00380638")))
void func_00380638(char *object)
{
    int difference = *(int *)(object + 0xC) - *(int *)(object + 8);
    func_002E0DE8(3, (short)(difference + 7), 0xC, &D_0045C3E0);
}

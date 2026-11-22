#include "godhand/globals.h"
extern int *D_003FA62C;
extern int func_003AE188(int, int, ...);
extern void func_003A7B48(void) __attribute__((noreturn));

__attribute__((section(".text.func_003A7B58")))
void func_003A7B58(int a0, int a1, int a2)
{
    func_003AE188(
        *(int *)((char *)D_003FA62C + 0xC), (int)D_0045F5C0, a2, a0, a1);
    func_003A7B48();
}

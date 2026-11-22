#include "godhand/globals.h"
extern int Forward349308_349238(void);
extern void func_00348A08(int, void *, int, void *);
extern int func_00349250(int a0);
extern int func_00348AC8(void *, int, void *);
extern int func_003492A0(int a0);
extern int func_00348A70(void *, int, void *);
extern void func_00348B20(void);

__attribute__((section(".text.func_00345490")))
void func_00345490(void)
{
    func_00348A08(2, Forward349308_349238, 0, &D_00457B90);
    func_00348AC8(func_00349250, 0, &D_00457BA8);
    func_00348A70(func_003492A0, 0, &D_00457BC0);
    func_00348B20();
}

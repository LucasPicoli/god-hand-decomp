/* cygnus-2.96 */
#include "godhand/adxm.h"
#include "godhand/globals.h"

extern void *func_003A52F0(void *, int, int);
extern void Obj33F8_Tramp_0033B658_FC70(void);
extern void Obj33F8_Tramp_0033B670_FC88(void);

__attribute__((section(".text.func_0032F288")))
void func_0032F288(void)
{
    Obj33F8_Tramp_0033B658_FC70();
    if (--D_003D1E68 == 0)
        func_003A52F0(D_003D1E70, 0, sizeof(D_003D1E70));
    Obj33F8_Tramp_0033B670_FC88();
}

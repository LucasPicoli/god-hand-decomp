/* SN ProDG ee-gcc 2.95.3: func_0030CAA0, end-of-frame: sync, flush the cache (interrupt-safe variant on flag)
 * and swap the GS double buffer. */
#include "godhand/gameWork.h"
#include "godhand/globals.h"
extern void func_0030B870(int a0);
extern void iFlushCache(int op);
extern void FlushCache(int op);
extern int sceGsSwapDBuff(void *db, int field);
extern void func_0030CB30(void);

__attribute__((section(".text.func_0030CAA0")))
void func_0030CAA0(void)
{
    if (D_00747A24 & 0x10000000)
        func_0030B870(1);
    else
        func_0030B870(0);
    if (D_00747A24 & 0x20000000)
        iFlushCache(0);
    else
        FlushCache(0);
    sceGsSwapDBuff(D_007476C0, D_007476C0[-4]);
    func_0030CB30();
}

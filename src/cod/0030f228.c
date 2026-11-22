#include "godhand/globals.h"
extern void MoveEmitter(void);
extern void MoveEsp(void);
extern int D_00747A78;

__attribute__((section(".text.MoveEffect")))
void MoveEffect(void)
{
    D_00752D00 = *(volatile int *)0x10000800;
    D_003C3BB8 = 0;
    if (!(D_00747A78 & 0x10000000)) {
        MoveEmitter();
        MoveEsp();
        D_00741DC0 = 1.0f;
    }
    D_00752D00 -= *(volatile int *)0x10000800;
}

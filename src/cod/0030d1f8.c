/* sn-2.95.3-136: EE timer 0 interrupt and the VRAM clear at 0x30D1F8. */

typedef unsigned int u_int;
#define T0_COUNT (*(volatile u_int *)0x10000000)
#define T0_MODE  (*(volatile u_int *)0x10000010)
#define T0_COMP  (*(volatile u_int *)0x10000020)
#define INTC_TIM0 9

extern int AddIntcHandler(int cause, int (*handler)(int), int next);
extern int IntrCtl_enableVblankStart(int cause);
extern int func_003B0740(int cause);

__attribute__((section(".text.func_0030D1F8")))
void func_0030D1F8(void)
{
    T0_COUNT = 0;
    T0_COMP = 0x2589;
    T0_MODE |= 0x1C2;
    AddIntcHandler(INTC_TIM0, IntrCtl_enableVblankStart, 0);
    func_003B0740(INTC_TIM0);
}

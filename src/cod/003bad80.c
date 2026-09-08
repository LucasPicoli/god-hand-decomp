/* ee-2.9-991111 matched TU. */

typedef unsigned int u_int;
typedef int u_long128 __attribute__((mode(TI)));

extern void func_003BAD08(int a);
extern volatile u_long128 D_003FC810[];
extern u_long128 D_003FC860[];

#define IPU_CMD  (*(volatile u_int *)0x10002000)
#define IPU_CTRL (*(volatile u_int *)0x10002010)
#define IPU_FIFO (*(volatile u_long128 *)0x10007010)

__attribute__((section(".text.func_003BAD80")))
void func_003BAD80(void)
{
    func_003BAD08(1);
    IPU_CTRL = 0x40000000;
    while (*(volatile int *)0x10002010 < 0) {
        ;
    }
    IPU_CMD = 0;
    while (*(volatile int *)0x10002010 < 0) {
        ;
    }
    IPU_FIFO = D_003FC810[0];
    IPU_FIFO = D_003FC810[1];
    IPU_FIFO = D_003FC810[2];
    IPU_FIFO = D_003FC810[3];
    IPU_FIFO = D_003FC810[4];
    IPU_FIFO = D_003FC810[4];
    IPU_FIFO = D_003FC810[4];
    IPU_FIFO = D_003FC810[4];
    IPU_CMD = 0x50000000;
    while (*(volatile int *)0x10002010 < 0) {
        ;
    }
    IPU_CMD = 0x58000000;
    while (*(volatile int *)0x10002010 < 0) {
        ;
    }
    IPU_FIFO = D_003FC860[0];
    IPU_FIFO = D_003FC860[1];
    IPU_CMD = 0x60000000;
    while (*(volatile int *)0x10002010 < 0) {
        ;
    }
    IPU_CMD = 0x90000000;
    while (*(volatile int *)0x10002010 < 0) {
        ;
    }
    IPU_CTRL = 0x40000000;
    while (*(volatile int *)0x10002010 < 0) {
        ;
    }
    IPU_CMD = 0;
    while (*(volatile int *)0x10002010 < 0) {
        ;
    }
}

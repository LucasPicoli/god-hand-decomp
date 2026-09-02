/* ee-2.9-991111 matched TU. */

extern void func_003B1F28(char *fmt);
extern char D_0045DD40[];

typedef unsigned int  u_int;
typedef unsigned long u_long;




__attribute__((section(".text.func_00395758")))
int func_00395758(void *lp, void *srcaddr)
{
    u_int i;

    i = 0;
    while (*(volatile u_int *)0x1000A000 & 0x100) {
        if (i++ > 0x1000000) {
            func_003B1F28(D_0045DD40);
            return -1;
        }
    }
    *(volatile u_int *)0x1000A020 = 6;
    if (((u_int)lp & 0x70000000) == 0x70000000) {
        *(volatile u_int *)0x1000A010 = ((u_int)lp & 0xFFFFFFF) | 0x80000000;
    } else {
        *(volatile u_int *)0x1000A010 = (u_int)lp & 0xFFFFFFF;
    }
    *(volatile u_int *)0x1000A000 = 0x101;
    while (*(volatile u_int *)0x1000A000 & 0x100) {
        if (i++ > 0x1000000) {
            func_003B1F28(D_0045DD40);
            return -1;
        }
    }
    *(volatile u_int *)0x1000A020 = (int)(*(u_long *)((char *)lp + 0x50) & 0x7FFF);
    if (((u_int)srcaddr & 0x70000000) == 0x70000000) {
        *(volatile u_int *)0x1000A010 = ((u_int)srcaddr & 0xFFFFFFF) | 0x80000000;
    } else {
        *(volatile u_int *)0x1000A010 = (u_int)srcaddr & 0xFFFFFFF;
    }
    *(volatile u_int *)0x1000A000 = 0x101;
    return 0;
}

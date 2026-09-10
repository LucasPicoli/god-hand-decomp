/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

typedef unsigned long u_long;

#define D2_CHCR (*(volatile unsigned int *)0x1000A000)
#define D2_MADR (*(volatile unsigned int *)0x1000A010)
#define D2_QWC  (*(volatile unsigned int *)0x1000A020)

extern void func_003B1F28(const char *fmt);
extern char D_0045DF98[];

__attribute__((section(".text.sceGsPutDrawEnv")))
int sceGsPutDrawEnv(u_long *dg)
{
    int i;

    i = 0;
    while (D2_CHCR & 0x100) {
        if ((unsigned int)i++ > 0x1000000) {
            func_003B1F28(D_0045DF98);
            return -1;
        }
    }
    D2_QWC = (int)(*dg & 0x7FFF) + 1;
    if (((unsigned int)dg & 0x70000000) == 0x70000000)
        D2_MADR = ((unsigned int)dg & 0x0FFFFFFF) | 0x80000000;
    else
        D2_MADR = (unsigned int)dg & 0x0FFFFFFF;
    D2_CHCR = 0x101;
    return 0;
}

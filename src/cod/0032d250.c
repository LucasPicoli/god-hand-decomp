#include "godhand/globals.h"
extern void func_0032D720(char *p);
extern void *func_003A52F0(void *d, int c, unsigned int n);
extern void func_0033B938(int a0, int a1);
extern void func_0032F288(void);
extern void func_00324AC8(void);
extern void func_0033B790(void *p);
extern char D_003D1488[];

__attribute__((section(".text.func_0032D250")))
void func_0032D250(void)
{
    int i;
    char *p;

    if (--D_003D1474 == 0) {
        for (i = 0; i < 4; i++) {
            p = D_003D1488 + i * 0x278;
            if (*p == 1) {
                func_0032D720(p);
            }
        }
        func_003A52F0(D_003D1488, 0, 0x9E0);
        func_0033B938(2, 0);
        func_0033B938(5, D_003D1478);
        func_0032F288();
        func_00324AC8();
        for (i = 0; i < 4; i++) {
            p = D_003D1488 + i * 0x278;
            if (*p != 0) {
                func_0033B790(D_004529A0);
                func_0032D720(p);
            }
        }
    }
}

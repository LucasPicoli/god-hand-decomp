#include "godhand/globals.h"
extern void func_00329AC8(void);
extern void Obj3260_Tramp_00337D20_D2A0(void);
extern void func_0033F4C8(void);
extern void func_00327A00(void);
extern void func_00335E60(void);
extern void Forward33B658_33E678(void);
extern void Forward33B670_33E690(void);
extern void func_0033B938(int a0, int a1);
extern void func_0033BEC0(void);
extern void func_00326520(void);
extern void func_0033F0F0(void);
extern void func_00338B10(void);
extern void func_00339520(void);
extern void func_0033A110(void);
extern void func_0033E648(void);
extern void func_0033B790(void *p);
extern void func_003298C0(char *p);
extern char D_003C7420[];

__attribute__((section(".text.func_00324AC8")))
void func_00324AC8(void)
{
    int i;
    char *p;

    if (--D_003C7400 == 0) {
        D_003D84AC = 0;
        func_00329AC8();
        Obj3260_Tramp_00337D20_D2A0();
        func_0033F4C8();
        func_00327A00();
        func_00335E60();
        Forward33B658_33E678();
        func_0033B938(2, 1);
        func_0033B938(4, D_003C7414);
        func_0033B938(5, D_003C7408);
        func_0033BEC0();
        func_00326520();
        func_0033F0F0();
        func_00338B10();
        func_00339520();
        func_0033A110();
        Forward33B670_33E690();
        func_0033E648();
        D_003D84AC = 1;
        for (i = 0; i < 16; i++) {
            p = D_003C7420 + i * 0xC8;
            if (*p != 0) {
                func_0033B790(D_00451B48);
                func_003298C0(p);
            }
        }
    }
}

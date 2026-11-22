#include "godhand/globals.h"
extern char *GetD003EC7E0_3452B0(void);
extern int Forward3443E0_3443C8(void *p);
extern void func_00349738(int a0, int a1);
extern int Forward33BBD8_348C78(void);
extern void func_00348B50(void);
extern int Forward33B938_348A50(void);
extern int MWSFSVM_DeleteIdleFunc(void);
extern int Forward33B938_348AA8(void);
extern int Forward35F900_346BF8(void);
extern void func_00335E60(void);
extern int func_00345828(void);
extern void func_00324AC8(void);
extern int func_00349A38(void);
extern void func_0033A110(void);
extern void func_00338B10(void);
extern void func_00339520(void);
extern int Forward346450_3462C0(void);
extern int Forward33BEC0_3489F0(void);

__attribute__((section(".text.func_00345610")))
void func_00345610(void)
{
    char *w = GetD003EC7E0_3452B0();
    int i;
    int n;
    int *p;

    if (--D_003EC7D8 == 0) {
        n = 0;
        for (i = 0; i < 8; i++) {
            p = (int *)(w + 0x6C + i * 0x304);
            if (*p == 1) {
                n++;
                Forward3443E0_3443C8(p);
            }
        }
        if (n == 0) {
            func_00349738(0, 1);
            Forward33BBD8_348C78();
            func_00349738(0, 0);
        }
        func_00348B50();
        Forward33B938_348A50();
        MWSFSVM_DeleteIdleFunc();
        Forward33B938_348AA8();
        Forward35F900_346BF8();
        func_00335E60();
        func_00345828();
        func_00324AC8();
        func_00349A38();
        func_0033A110();
        func_00338B10();
        func_00339520();
        Forward346450_3462C0();
        Forward33BEC0_3489F0();
    }
}

#include "godhand/globals.h"
extern char *GetD003EC7E0_3452B0(void);
extern int Forward33BF18_348BC8(void *p);
extern int func_00349820(void);
extern void func_00347F20(void *p);
extern void MWSFSVR_SetMwsfdSvrFlg(int a0);

__attribute__((section(".text.func_00349840")))
void func_00349840(void)
{
    char *w;
    int r;
    char *p;
    int i;

    if (D_003EC7DC == 1) {
        w = GetD003EC7E0_3452B0();
        r = Forward33BF18_348BC8(w + 0x58);
        if (r == 1) {
            if (func_00349820() != r) {
                for (p = w + 0x6C, i = 7; i >= 0; i--) {
                    if (p != 0) {
                        func_00347F20(p);
                    }
                    p += 0x304;
                }
            }
            MWSFSVR_SetMwsfdSvrFlg(0);
        }
    }
}

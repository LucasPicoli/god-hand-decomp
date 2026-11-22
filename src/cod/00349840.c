#include "godhand/globals.h"
extern char *GetD003EC7E0_3452B0(void);
extern int Forward33BF18_348BC8(void *p);
extern int MWSFD_GetProhibitServer(void);
extern void mwPlyExecInfiniteLoopHandle(void *p);
extern void MWSFSVR_SetMwsfdSvrFlg(int a0);

__attribute__((section(".text.mwPlyExecInfiniteLoopServer")))
void mwPlyExecInfiniteLoopServer(void)
{
    char *w;
    int r;
    char *p;
    int i;

    if (D_003EC7DC == 1) {
        w = GetD003EC7E0_3452B0();
        r = Forward33BF18_348BC8(w + 0x58);
        if (r == 1) {
            if (MWSFD_GetProhibitServer() != r) {
                for (p = w + 0x6C, i = 7; i >= 0; i--) {
                    if (p != 0) {
                        mwPlyExecInfiniteLoopHandle(p);
                    }
                    p += 0x304;
                }
            }
            MWSFSVR_SetMwsfdSvrFlg(0);
        }
    }
}

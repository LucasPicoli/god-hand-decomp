#include "godhand/globals.h"
extern void aixp_Destroy(char *p);
extern void *func_003A52F0(void *d, int c, unsigned int n);
extern void SVM_DelCbSvr(int a0, int a1);
extern void func_0032F288(void);
extern void ADXT_Finish(void);
extern void SVM_CallErr1(void *p);
extern char D_003D1488[];

__attribute__((section(".text.AIXP_Finish")))
void AIXP_Finish(void)
{
    int i;
    char *p;

    if (--D_003D1474 == 0) {
        for (i = 0; i < 4; i++) {
            p = D_003D1488 + i * 0x278;
            if (*p == 1) {
                aixp_Destroy(p);
            }
        }
        func_003A52F0(D_003D1488, 0, 0x9E0);
        SVM_DelCbSvr(2, 0);
        SVM_DelCbSvr(5, D_003D1478);
        func_0032F288();
        ADXT_Finish();
        for (i = 0; i < 4; i++) {
            p = D_003D1488 + i * 0x278;
            if (*p != 0) {
                SVM_CallErr1(D_004529A0);
                aixp_Destroy(p);
            }
        }
    }
}

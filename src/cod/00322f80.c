#include "godhand/globals.h"
extern int func_00324500(int h);
extern int OpenStreamHandle(int h);
extern void adxf_CloseLdptnwHn(void);

__attribute__((section(".text.adxf_StopPtLd")))
void adxf_StopPtLd(void)
{
    if (D_003EB838 != 0 && D_003EB83C >= 0) {
        if (func_00324500(D_003EB838) != 1) {
            OpenStreamHandle(D_003EB838);
        }
        D_003EB840 = 1;
        adxf_CloseLdptnwHn();
    }
}

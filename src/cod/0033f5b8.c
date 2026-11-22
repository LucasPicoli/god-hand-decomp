#include "godhand/globals.h"
extern void Forward33B658_33E678(void);
extern void Forward33B670_33E690(void);
extern void CdSrd_finishRead(void);
extern void func_00328C30(void);
extern void ADXSTM_ExecServer(void);
extern void ADXF_ExecServer(void);
extern void func_00328C70(void);

__attribute__((section(".text.adxt_ExecFsSvr")))
void adxt_ExecFsSvr(void)
{
    Forward33B658_33E678();
    if (D_003EB844 != 0) {
        Forward33B670_33E690();
        return;
    }
    D_003EB844 = 1;
    Forward33B670_33E690();
    D_003EB844 = 2;
    CdSrd_finishRead();
    D_003EB844 = 3;
    func_00328C30();
    D_003EB844 = 4;
    ADXSTM_ExecServer();
    D_003EB844 = 5;
    ADXF_ExecServer();
    D_003EB844 = 6;
    ADXSTM_ExecServer();
    D_003EB844 = 7;
    func_00328C30();
    D_003EB844 = 8;
    CdSrd_finishRead();
    D_003EB844 = 9;
    func_00328C70();
    D_003EB844 = 0;
}

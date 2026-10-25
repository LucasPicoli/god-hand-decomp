extern void Forward33B658_33E678(void);
extern void Forward33B670_33E690(void);
extern void CdSrd_finishRead(void);
extern void func_00328C30(void);
extern void func_00328B88(void);
extern void func_003241D0(void);
extern void func_00328C70(void);
extern int D_003EB844;

__attribute__((section(".text.func_0033F5B8")))
void func_0033F5B8(void)
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
    func_00328B88();
    D_003EB844 = 5;
    func_003241D0();
    D_003EB844 = 6;
    func_00328B88();
    D_003EB844 = 7;
    func_00328C30();
    D_003EB844 = 8;
    CdSrd_finishRead();
    D_003EB844 = 9;
    func_00328C70();
    D_003EB844 = 0;
}

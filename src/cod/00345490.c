#include "godhand/globals.h"
extern int Forward349308_349238(void);
extern void MWSFSVM_EntryIdVfunc(int, void *, int, void *);
extern int MWSFSVR_MainThrdProc(int a0);
extern int MWSFSVM_EntryMainFunc(void *, int, void *);
extern int func_003492A0(int a0);
extern int MWSFSVM_EntryIdleFunc(void *, int, void *);
extern void func_00348B20(void);

__attribute__((section(".text.mwsflib_SetSvrFunc")))
void mwsflib_SetSvrFunc(void)
{
    MWSFSVM_EntryIdVfunc(2, Forward349308_349238, 0, &D_00457B90);
    MWSFSVM_EntryMainFunc(MWSFSVR_MainThrdProc, 0, &D_00457BA8);
    MWSFSVM_EntryIdleFunc(func_003492A0, 0, &D_00457BC0);
    func_00348B20();
}

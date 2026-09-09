/* cygnus-2.96 matched TU. */

extern void Obj0000_PreDec_D_003FC50C_3B9D80(void);
extern void func_00324AC8(void);
extern void func_00324950(void);
extern void Obj0000_PostInc_D_003FC50C_3B9D68(void);
extern void func_00366C50(void *dst, int val, int n);
extern int D_00760D90[];
extern void func_0032B300(void *hn, int sw);
extern void Obj35C0_SetField_4_C538(int a0, int sw);
extern int GuardedCall_00329FD0_329F98(void *hn);

__attribute__((section(".text.SFADXT_Finish")))
int SFADXT_Finish(void)
{
    Obj0000_PreDec_D_003FC50C_3B9D80();
    func_00324AC8();
    return 0;
}

__attribute__((section(".text.SFADXT_Init")))
int SFADXT_Init(void)
{
    func_00324950();
    Obj0000_PostInc_D_003FC50C_3B9D68();
    func_00366C50(D_00760D90, 0, 7);
    return 0;
}

__attribute__((section(".text.sfadxt_WtPause")))
void sfadxt_WtPause(void *hn, int a1, int sw)
{
    func_0032B300(hn, sw);
    Obj35C0_SetField_4_C538(a1, sw);
}

__attribute__((section(".text.sfadxt_IsEndDecinfo")))
int sfadxt_IsEndDecinfo(void *hn)
{
    if ((unsigned int)GuardedCall_00329FD0_329F98(hn) < 2) return 0;
    return 1;
}

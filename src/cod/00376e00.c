extern void func_0037BE98(void);
extern void ClearPendingFlagEvents_376E38(void);
extern void SndReq_runQueued(void);
extern void func_003774A8(void);

__attribute__((section(".text.func_00376E00")))
void func_00376E00(void)
{
    ClearPendingFlagEvents_376E38();
    SndReq_runQueued();
    func_003774A8();
    func_0037BE98();
}

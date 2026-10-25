extern void ClearEventFlagsPending_375FA0(void);
extern void ClearPendingEntries_376008(void);
extern void SndSlot_updateAll(void);
extern void func_0037BE98(void);

__attribute__((section(".text.func_00375F68")))
void func_00375F68(void)
{
    ClearEventFlagsPending_375FA0();
    ClearPendingEntries_376008();
    SndSlot_updateAll();
    func_0037BE98();
}

extern void SdeVoiceExecute(void);
extern void ClearPendingFlagEvents_376E38(void);
extern void SndReq_runQueued(void);
extern void SdeStrControl(void);

__attribute__((section(".text.func_00376E00")))
void func_00376E00(void)
{
    ClearPendingFlagEvents_376E38();
    SndReq_runQueued();
    SdeStrControl();
    SdeVoiceExecute();
}

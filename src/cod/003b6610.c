/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

extern void supplement_crt0(void);
extern void InitSystemCallTableAddress(void);
extern void InitAlarm(void);
extern void InitTimer(int a0);
extern void StartTimerSystemTime(void);
extern void InitThread(void);
extern void InitExecPS2(void);
extern void InitTLBFunctions(void);
extern void sceSifInitRebootNotify(void);

__attribute__((section(".text._InitSys")))
void _InitSys(void)
{
    supplement_crt0();
    InitSystemCallTableAddress();
    InitAlarm();
    InitTimer(2);
    StartTimerSystemTime();
    InitThread();
    InitExecPS2();
    InitTLBFunctions();
    sceSifInitRebootNotify();
}

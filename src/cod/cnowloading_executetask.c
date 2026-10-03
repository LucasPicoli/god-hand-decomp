/* cNowLoading_executeTask — start the now-loading task once: if not already
 * running (D_003C2554), mark it and register cNowLoading_taskBody with the task
 * manager (slot D_00752C00, priority -1).  sn-2.95.3-136. */

extern unsigned char D_003C2554;
extern char D_00752C00;
extern void cNowLoading_taskBody(void);
extern void cTaskManager_execute(void *, void *, int);

__attribute__((section(".text.cNowLoading_executeTask")))
void cNowLoading_executeTask(void) {
    if (D_003C2554)
        return;
    D_003C2554 = 1;
    cTaskManager_execute(&D_00752C00, (void *)&cNowLoading_taskBody, -1);
}

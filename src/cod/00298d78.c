/* sn-2.95.3-136 */

extern unsigned char D_003C0548[3];
extern int D_00586AF0;
extern void EventBgm_startByStageCount(void);
extern void func_00297C80(void *slot, void (*cb)(void));

/* Records which of the three event-61 humans are alive and queues the stage BGM pick. */
__attribute__((section(".text.SetEv61HumanAlive")))
void SetEv61HumanAlive(unsigned char a, unsigned char b, unsigned char c)
{
    D_003C0548[0] = a;
    D_003C0548[1] = b;
    D_003C0548[2] = c;
    func_00297C80(&D_00586AF0, EventBgm_startByStageCount);
}

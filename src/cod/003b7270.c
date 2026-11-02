/* ee-2.9-991111 matched TU. */

void *DIntr(void);
void *iAllocTimerCounter(void);
void EIntr(void);

__attribute__((section(".text.func_003B7270")))
void *func_003B7270(void) {
    int a = (int)DIntr();
    void *b = iAllocTimerCounter();
    if (a != 0) {
        EIntr();
    }
    return b;
}

/* ee-2.9-991111 matched TU. */

void *func_003B63A0(void);
void *iAllocTimerCounter(void);
void func_003B63F0(void);

__attribute__((section(".text.func_003B7270")))
void *func_003B7270(void) {
    int a = (int)func_003B63A0();
    void *b = iAllocTimerCounter();
    if (a != 0) {
        func_003B63F0();
    }
    return b;
}

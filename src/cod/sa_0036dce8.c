/* cygnus-2.96 matched TU. */
/* cygnus-2.96 */
/* Busy-wait: (0x3f + 1) / 32 rounds of five nops. */
__attribute__((section(".text.func_0036DCE8")))
void func_0036DCE8(void)
{
    int remaining = 0x3f;

    do {
        remaining -= 32;
        __asm__ volatile("nop");
        __asm__ volatile("nop");
        __asm__ volatile("nop");
        __asm__ volatile("nop");
        __asm__ volatile("nop");
    } while (remaining >= 0);
}

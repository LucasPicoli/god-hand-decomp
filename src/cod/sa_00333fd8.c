/* cygnus-2.96 matched TU. */
/* cygnus-2.96 */
/* Busy-wait: 0x2000 / 32 rounds of five nops. */
__attribute__((section(".text.func_00333FD8")))
void func_00333FD8(void)
{
    int remaining = 0x1fff;

    do {
        remaining -= 32;
        __asm__ volatile("nop");
        __asm__ volatile("nop");
        __asm__ volatile("nop");
        __asm__ volatile("nop");
        __asm__ volatile("nop");
    } while (remaining >= 0);
}

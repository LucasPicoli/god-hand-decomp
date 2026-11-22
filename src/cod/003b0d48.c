/* Byte-identical to RE4 PS2 (SLUS-21134) 0x0029D980 — newlib.
 * Spins on EE I/O register 0x1000F130 (bit 0x8000) then writes a0 as a byte to
 * 0x1000F180. Compiled with ee-2.9-991111: cygnus-2.96 fills the poll-loop
 * branch delay slot, newlib leaves the short-loop nops. */

__attribute__((section(".text.kputchar")))
void *kputchar(int a0) {
    while (*(volatile int *)0x1000F130 & 0x8000) {
    }
    *(volatile char *)0x1000F180 = (char)a0;
    return (void *)a0;
}

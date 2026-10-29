/* SN ProDG ee-gcc 2.95.3 matched TU. */

__attribute__((section(".text.pl00_setJump")))
void pl00_setJump(void *a0, float f12) {
    *(float*)((char*)a0+0x670) = f12;
    *(unsigned char*)((char*)a0+0x2F5) = 0x33;
    *(unsigned char*)((char*)a0+0x2F4) = 0;
    *(unsigned char*)((char*)a0+0x2F6) = 0;
    *(unsigned char*)((char*)a0+0x2F7) = 0;
}

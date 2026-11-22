/* RE4 PS2 byte-identical (SLUS-21134 @ 0x00199280). Stores a1 and a1/1536. */
__attribute__((section(".text.ADXB_SetAc3DecSmpl")))
void ADXB_SetAc3DecSmpl(int a0, int a1) {
    *(int *)(a0 + 0xC4) = a1;
    *(int *)(a0 + 0xC8) = a1 / 1536;
}

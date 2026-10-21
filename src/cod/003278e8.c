struct ADX_BASIC;
extern int ADXB_GetAinfLen(struct ADX_BASIC *self);
extern short ADXB_GetDefPan(struct ADX_BASIC *self, int ch);

/* AINF pan offset of one channel while the stream prepares or plays; -128 otherwise or without AINF. */
__attribute__((section(".text.func_003278E8")))
int func_003278E8(char *a0, int idx) {
    if (ADXB_GetAinfLen(*(struct ADX_BASIC **)(a0 + 4)) <= 0) {
        return -0x80;
    }
    if ((unsigned int)(*(unsigned char*)(a0 + 1) - 2) < 2) {
        return ADXB_GetDefPan(*(struct ADX_BASIC **)(a0 + 4), idx);
    }
    return -0x80;
}

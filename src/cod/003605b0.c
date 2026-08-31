/* cygnus-2.96 matched TU. */

extern int GetD003EE804_360720(void);

__attribute__((section(".text.func_003605B0")))
void func_003605B0(char *a0, int *src, int *dst) {
    float s = *(float *)(a0 + 0x40);
    int i;

    if (GetD003EE804_360720() == 1) {
        i = 0;
        do {
            dst[i] = (src[i] & 0x7FFFFF80) << 1;
            i++;
        } while (i < 0x100);
    } else {
        i = 0;
        do {
            int x;
            if (src[i] == 0) src[i] = 1;
            x = src[i];
            dst[i] = (unsigned int)(16777215.0f / (s * (float)(unsigned int)x / 2147483520.0f));
            i++;
        } while (i < 0x100);
    }
}

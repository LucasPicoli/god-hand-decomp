/* sn-2.95.3-136 matched TU. */

extern void func_001852E8(void *a0, int a1);

__attribute__((section(".text.func_00184A40")))
void func_00184A40(void *a0) {
    char *s0 = (char *)a0;
    float f1 = (float)*(short *)(s0 + 0x61E) / (float)*(short *)(s0 + 0x62C);
    switch (*(unsigned char *)(s0 + 0x655)) {
    case 0:
        if (f1 <= 0.75f) { func_001852E8(s0, 1); *(unsigned char *)(s0 + 0x655) += 1; }
        break;
    case 1:
        if (f1 <= 0.5f) { func_001852E8(s0, 2); *(unsigned char *)(s0 + 0x655) += 1; }
        break;
    case 2:
        if (f1 <= 0.25f) { func_001852E8(s0, 3); *(unsigned char *)(s0 + 0x655) += 1; }
        break;
    case 3:
        if (f1 <= 0.0f) { func_001852E8(s0, 4); *(unsigned char *)(s0 + 0x655) += 1; }
        break;
    case 4:
        *(unsigned char *)(s0 + 0x65C) = 1;
        break;
    }
}

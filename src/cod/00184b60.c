/* sn-2.95.3-136 matched TU. */

extern void func_001855A8(void *a0, int a1);
extern void func_00185690(void *a0, int a1);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_00184B60")))
void func_00184B60(void *a0) {
    char *s0 = (char *)a0;
    float f1 = (float)*(short *)(s0 + 0x620) / (float)*(short *)(s0 + 0x62E);
    switch (*(unsigned char *)(s0 + 0x656)) {
    case 0:
        if (f1 <= 0.95f) { func_001855A8(s0, 1); *(unsigned char *)(s0 + 0x656) += 1; }
        break;
    case 1:
        if (f1 <= 0.9f) { func_001855A8(s0, 4); *(unsigned char *)(s0 + 0x656) += 1; }
        break;
    case 2:
        if (f1 <= 0.75f) { func_00185690(s0, 1); *(unsigned char *)(s0 + 0x656) += 1; }
        break;
    case 3:
        if (f1 <= 0.5f) { func_00185690(s0, 2); *(unsigned char *)(s0 + 0x656) += 1; }
        break;
    case 4:
        if (f1 <= 0.25f) { func_00185690(s0, 3); *(unsigned char *)(s0 + 0x656) += 1; }
        break;
    case 5:
        if (f1 <= 0.0f) { func_00185690(s0, 4); *(unsigned char *)(s0 + 0x656) += 1; }
        break;
    case 6:
        *(unsigned char *)(s0 + 0x65D) = 1;
        break;
    }
}

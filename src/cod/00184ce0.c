/* sn-2.95.3-136 matched TU. */

extern void func_00185910(void *a0, int a1);
extern void func_00185A20(void *a0, int a1);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_00184CE0")))
void func_00184CE0(void *a0) {
    char *s0 = (char *)a0;
    float f1 = (float)*(short *)(s0 + 0x622) / (float)*(short *)(s0 + 0x630);
    switch (*(unsigned char *)(s0 + 0x657)) {
    case 0:
        if (f1 <= 0.95f) { func_00185910(s0, 1); *(unsigned char *)(s0 + 0x657) += 1; }
        break;
    case 1:
        if (f1 <= 0.9f) { func_00185910(s0, 4); *(unsigned char *)(s0 + 0x657) += 1; }
        break;
    case 2:
        if (f1 <= 0.75f) { func_00185A20(s0, 1); *(unsigned char *)(s0 + 0x657) += 1; }
        break;
    case 3:
        if (f1 <= 0.5f) { func_00185A20(s0, 2); *(unsigned char *)(s0 + 0x657) += 1; }
        break;
    case 4:
        if (f1 <= 0.25f) { func_00185A20(s0, 3); *(unsigned char *)(s0 + 0x657) += 1; }
        break;
    case 5:
        if (f1 <= 0.0f) { func_00185A20(s0, 4); *(unsigned char *)(s0 + 0x657) += 1; }
        break;
    case 6:
        *(unsigned char *)(s0 + 0x65E) = 1;
        break;
    }
}

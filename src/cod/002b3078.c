/* sn-2.95.3-136 matched TU. */

extern void func_002B3158(void *a0);
extern void func_002B3230(void *a0);

__attribute__((section(".text.func_002B3078")))
void func_002B3078(char *a0) {
    char *s0 = a0;
    switch (*(unsigned char *)(s0 + 0xD)) {
    case 0:
        func_002B3158(s0);
        switch (*(unsigned char *)(s0 + 0xA4)) {
        case 3:
            *(char *)(s0 + 0xD) = 1;
            break;
        case 0:
        case 2:
        case 4:
        case 5:
            *(char *)(s0 + 0xD) = 2;
            break;
        case 1:
        default:
            break;
        }
        /* fallthrough */
    case 1:
        if (func_002B3190(s0) == 0) {
            break;
        }
        *(char *)(s0 + 0xD) = *(unsigned char *)(s0 + 0xD) + 1;
        /* fallthrough */
    case 2:
        if (func_002B31F8(s0) == 0) {
            break;
        }
        func_002B3230(s0);
        *(char *)(s0 + 0xF) = 0;
        *(char *)(s0 + 0xD) = 0;
        *(char *)(s0 + 0xE) = 0;
        *(char *)(s0 + 0xC) = 2;
        break;
    default:
        break;
    }
}

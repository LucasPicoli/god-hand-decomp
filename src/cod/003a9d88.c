/* sn-2.95.3-136 matched TU. */

extern void func_003A9E58(int a0, void *a1, void *a2, int a3);
extern void func_003AB188(int a0, void *a1, void *a2, int a3);

__attribute__((section(".text.func_003A9D88")))
void func_003A9D88(char *a0, char *a1, int a2) {
    char *p = a1;
    if (*a1 != 0) {
        do {
            if (*p == 0x25) {
                if (p[1] != 0) {
                    p++;
                    while (*p < 0x41 && p[1] != 0) {
                        p++;
                    }
                    switch ((char)((unsigned char)*p - 0x45)) {
                    case 0:
                    case 2:
                    case 7:
                    case 32:
                    case 33:
                    case 34:
                        func_003A9E58(*(int *)(a0 + 0x54), a0, a1, a2);
                        return;
                    default:
                        break;
                    }
                }
            }
            p++;
        } while (*p != 0);
    }
    func_003AB188(*(int *)(a0 + 0x54), a0, a1, a2);
}

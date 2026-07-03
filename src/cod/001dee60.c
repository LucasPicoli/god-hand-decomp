/* sn-2.95.3-136 matched TU. */

extern void CustomIDWork_SetDisp(void *a0, int a1);

__attribute__((section(".text.func_001DEE60")))
void func_001DEE60(char *a0, int a1, int a2) {
    int i;
    if (a2) {
        if (a1 == 0x11) {
            for (i = 0; i < 0x11; i++) {
                if (i != 0) {
                    CustomIDWork_SetDisp(a0 + 0x60 + i * 0x7C, 1);
                }
            }
        } else if (a1 != 0) {
            CustomIDWork_SetDisp(a1 * 0x7C + 0x60 + a0, 1);
        }
    } else {
        if (a1 == 0x11) {
            for (i = 0; i < 0x11; i++) {
                if (i != 0) {
                    CustomIDWork_SetDisp(a0 + 0x60 + i * 0x7C, 0);
                }
            }
        } else if (a1 != 0) {
            CustomIDWork_SetDisp(a1 * 0x7C + 0x60 + a0, 0);
        }
    }
}

/* sn-2.95.3-136 matched TU. */

extern void func_002BE550(void *a0);
extern char D_005E8640[];

__attribute__((section(".text.func_002BE8E8")))
void func_002BE8E8(void *a0, int a1) {
    char *p;
    int i;

    if (a1 == 0xFFFF && a0 != 0) {
        p = D_005E8640;
        for (i = 2; i != -1; i--) {
            func_002BE550(p);
            p += 8;
        }
    }
}

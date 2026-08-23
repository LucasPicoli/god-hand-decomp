/* cygnus-2.96 matched TU. */

extern int D_003E0710;
extern int D_003E0708;

__attribute__((section(".text.func_003387C8")))
void func_003387C8(char *a0, int idx, int val) {
    int r;
    if (D_003E0710 == 1 && D_003E0708 <= 0) return;
    r = (val < -15) ? -15 : val;
    r = (r > 15) ? 15 : r;
    *(int *)(a0 + idx * 4 + 0x40) = r;
}

/* cygnus-2.96 matched TU. */

extern int D_003E0710;
extern int D_003E0708;
extern int D_003E0738;
extern int D_003E0748[];
extern int DTX_CallUrpc(int a0, int a1, int a2, void *a3, int t0);

__attribute__((section(".text.func_00337C88")))
void func_00337C88(void) {
    int buf[4];
    if (D_003E0710 == 1) {
        if (D_003E0708 <= 0) {
            return;
        }
    }
    if (D_003E0738 != 0) {
        DTX_CallUrpc(0xF, 0, 0, buf, 2);
        D_003E0748[0] = buf[0];
        D_003E0748[1] = buf[1];
        D_003E0738 = 0;
    }
}

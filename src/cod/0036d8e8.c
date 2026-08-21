/* cygnus-2.96 matched TU. */

extern char D_003F2048;
extern void func_0036D938();

__attribute__((section(".text.M2VERR_SetCode")))
void *M2VERR_SetCode(char *a0, void *a1) {
    if (a0 == 0) {
        func_0036D938(&D_003F2048);
    } else {
        func_0036D938(a0 + 0x4);
    }
    return a1;
}

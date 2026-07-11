/* cygnus-2.96 matched TU. */

extern struct cb_0033b790 D_007588B0;
extern char D_003E9990[];
extern char D_003EADC0[];
extern char D_00456930[];
extern void (*D_003EADB8)(void *arg, char *p);
extern void *D_003EADBC;
extern int strncat(char *dst, int src, int n);
extern char D_00460900[];
extern void func_003B9DE0(void *a0);

struct cb_0033b790 { void (*fn)(void *arg, void *p); void *arg; };




__attribute__((section(".text.func_0033B790")))
void func_0033B790(int a0) {
    if (a0 == 0) {
        D_007588B0.fn(D_007588B0.arg, 0);
        return;
    }
    func_003A5DA0(D_003E9990, a0, 0x7F);
    if (D_007588B0.fn != 0)
        D_007588B0.fn(D_007588B0.arg, D_003E9990);
}

__attribute__((section(".text.func_0033F1A8")))
int func_0033F1A8(int a0, int a1) {
    if (a0 == 0 || a1 == 0)
        return func_0033B6E8(D_00456930);
    func_003A5DA0(D_003EADC0, a0, 0xFF);
    strncat(D_003EADC0, a1, 0xFF);
    if (D_003EADB8 != 0)
        D_003EADB8(D_003EADBC, D_003EADC0);
    return func_0033B6E8(D_003EADC0);
}

__attribute__((section(".text.func_003BA058")))
void func_003BA058(int a0) {
    if (a0 == 0) {
        func_003B9DE0(D_00460900);
        return;
    }
    *(int*)((char*)a0 + 4) = 0;
}

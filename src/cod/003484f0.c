/* cygnus-2.96 matched TU. */

extern int Forward33BBD8_348C78();
extern void func_00348498(void *a0);
extern void func_003483F8(int a0, int a1);
extern void func_003482C8(int a0);

__attribute__((section(".text.func_003484F0")))
int func_003484F0(void *a0) {
    void *obj;
    void *arg;
    int (*f)(void *);
    int ret = 0;
    if (func_00348968(a0) != 1) return 0;
    obj = *(void **)((char *)a0 + 0x8);
    arg = *(void **)((char *)a0 + 0x1C);
    if (obj != 0) {
        f = *(int (**)(void *))((char *)obj + 0x1C);
        if (f != 0) {
            ret = f(arg);
        }
    }
    return ret;
}

__attribute__((section(".text.func_00348870")))
void func_00348870(int *a0) {
    int arg;
    int s3v;
    int *s2v;
    int *obj;
    void (*method)(void *);
    if (func_00348968(a0) != 1) return;
    arg = a0[7];
    s3v = a0[1];
    s2v = (int *)a0[5];
    if (arg == 0) return;
    Forward33BBD8_348C78();
    func_00348498(a0);
    a0[0] = 0;
    func_003483F8(s3v, arg);
    obj = (int *)s2v[0];
    method = *(void (**)(void *))((char *)obj + 0xC);
    method(s2v);
    a0[7] = 0;
    func_003482C8(s3v);
}

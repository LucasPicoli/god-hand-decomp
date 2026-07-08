/* cygnus-2.96 matched TU. */

extern void func_0033C4E8(int x);
extern void func_0033C290(int x);
extern void Forward33B658_3403C8(void);
extern void func_00340700(int a0);
extern void Forward33B670_3403E0(void);
extern void func_00335CD8(int a0);
extern void func_00335530(void *a0);
extern void func_00335CE0(void);

__attribute__((section(".text.func_00326800")))
void func_00326800(void *obj) {
    func_0033C4E8(*(int *)((char *)obj + 4));
    func_0033C290(*(int *)((char *)obj + 4));
}

__attribute__((section(".text.func_003406D0")))
void func_003406D0(int a0) {
    Forward33B658_3403C8();
    func_00340700(a0);
    Forward33B670_3403E0();
}

__attribute__((section(".text.func_00335500")))
void func_00335500(void *a0) {
    func_00335CD8((int)a0);
    func_00335530(a0);
    func_00335CE0();
}

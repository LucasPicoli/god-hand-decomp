/* cygnus-2.96 matched TU. */

extern void func_00348D58(void *);
extern void func_003490B0(void *);
extern void func_003491D0(void *);
extern void func_003466F0(void *);

__attribute__((section(".text.func_00349158")))
int func_00349158(void *p)
{
    switch (*(int *)((char *)p + 4)) {
    case 1:
        func_00348D58(p);
        break;
    case 2:
        func_003490B0(p);
        break;
    case 0:
    case 3:
    case 4:
        break;
    }
    func_003491D0(p);
    func_003466F0(p);
    return 0;
}

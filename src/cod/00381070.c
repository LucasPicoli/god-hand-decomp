/* sn-2.95.3-136 matched TU. */

extern void func_003810F8();
extern void func_00381150();
extern void func_003812B0();
extern void func_003813C8();

__attribute__((section(".text.func_00381070")))
void func_00381070(unsigned char *arg)
{
    int pad;

    switch (arg[4]) {
    case 0:
        func_003810F8(arg);
        break;
    case 1:
        func_00381150(arg);
        break;
    case 2:
    case 3:
        func_003812B0(arg, pad, (unsigned char)(arg[4] - 2));
        break;
    case 4:
        func_003813C8(arg);
        break;
    }
}

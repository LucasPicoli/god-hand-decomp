/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_001FD908")))
int func_001FD908(char *arg)
{
    int a, b, c;

    switch (arg[0x48]) {
    case 0:
        c = arg[0x49];
        a = 1;
        b = 2;
    tail:
        return (c == 1) ? a : b;
    case 1:
        c = arg[0x49];
        a = 3;
        b = 4;
        goto tail;
    case 2:
        c = arg[0x49];
        a = 5;
        b = 6;
        goto tail;
    case 3:
        c = arg[0x49];
        a = 7;
        b = 8;
        goto tail;
    case 4:
    default:
        return 0;
    }
}

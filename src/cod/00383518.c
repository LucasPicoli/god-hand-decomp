/* sn-2.95.3-136 matched TU. */

extern void func_00383690(unsigned char *);
extern void func_00383878(unsigned char *);
extern void func_00383B60(unsigned char *, int, int);
extern void func_00383E40(unsigned char *);

__attribute__((section(".text.func_00383518")))
void func_00383518(unsigned char *arg, int arg1)
{
    switch (arg[4]) {
    case 0:
        func_00383690(arg);
        break;
    case 1:
        func_00383878(arg);
        break;
    case 2:
    case 3:
        func_00383B60(arg, arg1, (unsigned char)(arg[4] - 2));
        break;
    case 4:
        func_00383E40(arg);
        break;
    }
}

/* cygnus-2.96 matched TU. */

extern int GuardedCall_00329FD0_329F98();
extern void func_00326800(int);

__attribute__((section(".text.func_0032CF30")))
void func_0032CF30(char *arg) {
    if (*(int *)(arg + 8) == 0) {
        return;
    }
    if (GuardedCall_00329FD0_329F98() == 0) {
        return;
    }
    switch (arg[2]) {
    case 0:
    case 1:
        if (func_00328098(*(int *)(arg + 8)) == 3) {
            func_00326800(*(int *)(arg + 4));
        }
        break;
    case 2:
        func_00326800(*(int *)(arg + 4));
        break;
    case 3:
    case 4:
    default:
        break;
    }
}

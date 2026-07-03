/* cygnus-2.96 matched TU. */

extern int GuardedCall_00329FD0_329F98();

__attribute__((section(".text.func_00342A88")))
int func_00342A88(void) {
    switch (GuardedCall_00329FD0_329F98()) {
    case 0:
        return 0;
    case 1:
    case 2:
        return 1;
    case 3:
    case 4:
        return 2;
    case 5:
        return 3;
    case 6:
        break;
    }
    return 4;
}

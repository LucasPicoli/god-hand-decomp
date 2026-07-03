/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_002B8A30")))
int func_002B8A30(int a0, unsigned int a1) {
    switch (a1) {
    case 0:
    case 1:
    case 3:
    case 5:
    case 7:
        return 1;
    case 2:
    case 4:
    case 6:
    case 8:
        return 0;
    default:
        return 0;
    }
}

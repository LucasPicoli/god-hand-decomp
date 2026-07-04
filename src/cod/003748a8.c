/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_003748A8")))
int func_003748A8(int *arg) {
    int x;

    x = *arg;
    if (x == 0) {
        return 0;
    }
    switch (func_0032DC58(x)) {
    case 0:
        return 0;
    case 1:
        return 2;
    case 2:
        return 3;
    case 3:
        return 5;
    case 4:
    default:
        return 6;
    }
}

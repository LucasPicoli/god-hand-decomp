/* cygnus-2.96 matched TU. */

__attribute__((section(".text.func_00344F68")))
int func_00344F68(int a0) {
    int buf[4];

    if (func_0035E868(a0, 0xE0, buf) != 1) {
        return 0x11;
    }
    switch (buf[0]) {
    case 1:
        return 0x21;
    case 3:
        return 0x51;
    case 6:
        return 0x61;
    case 0:
    case 8:
        break;
    }
    return 0x11;
}

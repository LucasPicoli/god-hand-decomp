/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_00309C30")))
int func_00309C30(unsigned int a0, int a1) {
    switch (a0) {
    case 0:
    case 1:
    case 2:
    case 0xA:
    case 0x1B:
    case 0x24:
    case 0x2C:
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x3A:
        return (a1 + 0x3F) / 0x40;
    case 0x13:
    case 0x14:
        a1 = (a1 + 0x3F) / 0x40;
        return a1 + (a1 & 1);
    default:
        return 0;
    }
}

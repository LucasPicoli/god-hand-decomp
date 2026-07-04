/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_00309CA0")))
int func_00309CA0(int mode, int a, int b)
{
    switch (mode) {
    case 0x00: case 0x01: case 0x1B: case 0x24: case 0x2C: case 0x30: case 0x31:
        return (a * b) / 64;
    case 0x02: case 0x0A: case 0x32: case 0x3A:
        return (a * b) / 128;
    case 0x13:
        return (a * b) / 256;
    case 0x14:
        return (a * b) / 512;
    default:
        return 0;
    }
}

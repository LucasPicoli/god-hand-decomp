/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_D_00747A94_2DB6B0();
extern int pl00_CkSubScreen(int);
extern int pl00_ckAtkActBtnEnable(int);

__attribute__((section(".text.func_001F7050")))
int func_001F7050(int *arg)
{
    switch (arg[7]) {
    case 0x00: case 0x01: case 0x02: case 0x06: case 0x08: case 0x09:
    case 0x0A: case 0x0B: case 0x0E: case 0x15: case 0x17: case 0x18:
    case 0x19: case 0x1C: case 0x1D: case 0x1E: case 0x1F: case 0x20:
    case 0x22: case 0x23: case 0x24: case 0x27: case 0x28: case 0x29:
    case 0x2A: case 0x2B: case 0x2C: case 0x2D: case 0x2E: case 0x2F:
        return pl00_CkSubScreen(Obj0000_Get_D_00747A94_2DB6B0());
    case 0x03: case 0x04: case 0x05: case 0x07: case 0x0C: case 0x0D:
    case 0x0F: case 0x10: case 0x11: case 0x12: case 0x16: case 0x1A:
    case 0x21: case 0x26:
        return pl00_ckAtkActBtnEnable(Obj0000_Get_D_00747A94_2DB6B0());
    case 0x13: case 0x14: case 0x1B: case 0x25: case 0x32:
        return 1;
    default:
        return 0;
    }
}

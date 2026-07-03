/* sn-2.95.3-136 matched TU. */

extern int D_00747A2C;
extern int D_00747A04;
extern int D_005E8140;
extern int classPAD_WORK_Pad_act_set(int *, int, int);

__attribute__((section(".text.func_0012C348")))
void func_0012C348(int a0, unsigned int a1) {
    if (D_00747A2C & 0x8000000) {
        return;
    }
    switch (a1) {
    case 0:
    default:
        classPAD_WORK_Pad_act_set(&D_005E8140, 0x3FF0000, 0x40000 << D_00747A04);
        break;
    case 1:
        classPAD_WORK_Pad_act_set(&D_005E8140, 0x3FF0000, 0x60000 << D_00747A04);
        break;
    case 2:
        classPAD_WORK_Pad_act_set(&D_005E8140, 0x3FF0000, 0xA0000 << D_00747A04);
        break;
    case 3:
        classPAD_WORK_Pad_act_set(&D_005E8140, 0x3FF0000, 0xE0000 << D_00747A04);
        break;
    case 4:
        classPAD_WORK_Pad_act_set(&D_005E8140, 0x3280000, 0x20000 << D_00747A04);
        break;
    }
}

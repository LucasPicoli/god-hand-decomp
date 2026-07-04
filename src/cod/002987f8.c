/* sn-2.95.3-136 matched TU. */

extern void displayScrollLayer(int, int);
extern int Obj0000_Get_Field_BC0_Via_Ptr_1FC740(int *);
extern int D_00569B70;

__attribute__((section(".text.func_002987F8")))
void func_002987F8(int idx, float val) {
    if (val == 0.0f) {
        switch (idx) {
        case 0:
        case 0xE:
        case 0x17:
            displayScrollLayer(0x1E, 0);
            displayScrollLayer(0x1F, 0);
            break;
        case 0xD:
        case 0x16:
            if (Obj0000_Get_Field_BC0_Via_Ptr_1FC740(&D_00569B70) != 0) {
                displayScrollLayer(0x1E, 0);
                displayScrollLayer(0x1F, 1);
            } else {
                displayScrollLayer(0x1E, 1);
                displayScrollLayer(0x1F, 0);
            }
            break;
        default:
            break;
        }
    }
}

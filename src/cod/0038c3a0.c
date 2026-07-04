/* ee-2.9-991111 matched TU. */

extern void _IO_switch_to_main_get_area(int *fp);
extern void UpdateGlobalPtrWithParam_3A7CC0(int p);

__attribute__((section(".text.func_0038C3A0")))
void func_0038C3A0(int *fp) {
    if (fp[0] & 0x100) {
        _IO_switch_to_main_get_area(fp);
    }
    UpdateGlobalPtrWithParam_3A7CC0(fp[9]);
    fp[9] = 0;
    fp[11] = 0;
    fp[10] = 0;
}

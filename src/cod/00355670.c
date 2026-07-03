/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_00355670")))
void func_00355670(int *a0) {
    if (a0 != 0) {
        switch (*a0) {
        case 4:
            *a0 = 3;
            break;
        default:
            *a0 = 0;
            break;
        }
        *(int*)((char*)a0 + 0x58) = -1;
    }
}

/* sn-2.95.3-136 matched TU. */

extern int D_00569B70;
extern int cCoreSave_getGameLevel(void *save);

__attribute__((section(".text.func_001B8670")))
void func_001B8670(char *p) {
    switch (cCoreSave_getGameLevel(&D_00569B70)) {
    case 1:
    default:
        *(float *)(p + 0x604) = 600.0f;
        break;
    case 2:
        *(float *)(p + 0x604) = 500.0f;
        break;
    case 3:
        *(float *)(p + 0x604) = 400.0f;
        break;
    case 4:
        *(float *)(p + 0x604) = 400.0f;
        break;
    case 5:
        *(float *)(p + 0x604) = 300.0f;
        break;
    }
}

/* sn-2.95.3-136 matched TU. */

extern int D_00569B70;
extern int D_005864F0;
extern int cCoreSave_getGameLevel(int *);

__attribute__((section(".text.func_0026EE40")))
void func_0026EE40(char *a0, int a1, int a2) {
    int lv;

    lv = cCoreSave_getGameLevel(&D_00569B70);
    switch (lv) {
    case 1:
    case 2:
    default:
        a1 = a1 / 2;
        break;
    case 3:
    case 4:
        a1 = a1 / 4;
        break;
    case 5:
        a1 = 0;
        break;
    }
    if (a1 < 0) {
        a1 = 0;
    }
    *(int *)(a0 + 0x16DC) = a1;
    lv = cCoreSave_getGameLevel(&D_00569B70);
    switch (lv) {
    case 1:
    case 2:
    default:
        a2 = a2 / 2;
        break;
    case 3:
    case 4:
        a2 = a2 / 4;
        break;
    case 5:
        a2 = 0;
        break;
    }
    if (a2 > 0) {
        func_00292018(&D_005864F0, a2);
    }
}

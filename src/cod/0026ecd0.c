/* sn-2.95.3-136 matched TU. */

extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern int Obj0000_Get_Field_424_1595F0(void *a0);
extern int cCoreSave_getGameLevel(void *a0);
extern void func_0026EE40(void *a0, int a1, int a2);
extern unsigned short D_00747A50;
extern int D_00569B70;
extern char D_005FEE00[];

/* func_0026ECD0 — two jump tables.  sn-2.95.3-136. */









__attribute__((section(".text.func_0026ECD0")))
void func_0026ECD0(void *a0, int a1) {
    char *s1 = (char *)a0;
    char *p;
    int t;
    int v;
    int n;

    switch (*(int *)(s1 + 0x564)) {
    default:
        t = 0xC8;
        break;
    case 0x250:
    case 0x251:
    case 0x252:
    case 0x256:
    case 0x260:
    case 0x264:
    case 0x265:
    case 0x26A:
    case 0x27E:
        t = 0x96;
        break;
    }
    v = *(int *)(s1 + 0x564);
    if (v == 0x256) {
        if (D_00747A50 == 0x406) return;
    }
    if (t >= *(int *)(s1 + 0x16E8) && a1 == 0) return;
    if (v < 0x224) {
        if (v >= 0x220) goto lvl;
    }
    p = D_005FEE00;
    cSnd_SeCall_2CBA48(p, 0, 0xF7, s1, 0, 0, 0, 0);
    cSnd_SeCall_2CBA48(p, 1, (short)(Obj0000_Get_Field_424_1595F0(s1) + 0x14), s1, 0, 0, 0, 0);
lvl:
    switch (cCoreSave_getGameLevel(&D_00569B70)) {
    case 1:
    default:
        *(int *)(s1 + 0x16EC) = 0x96;
        break;
    case 2:
        *(int *)(s1 + 0x16EC) = 0x96;
        break;
    case 3:
        *(int *)(s1 + 0x16EC) = 0x12C;
        break;
    case 4:
        *(int *)(s1 + 0x16EC) = 0x12C;
        break;
    case 5:
        *(int *)(s1 + 0x16EC) = 0x12C;
        break;
    }
    *(int *)(s1 + 0x16E8) = 0;
    func_0026EE40(s1, 0, 0);
}

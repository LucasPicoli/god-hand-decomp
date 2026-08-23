/* sn-2.95.3-136 matched TU. */

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern int Obj0000_Get_Field_5FC_NE_Zero_12C748(void *a0);
extern int Forward30F348_31CFE0(void);
extern int cCoreSave_getGameLevel(void *a0);
extern void func_00274238(void *a0, int a1);
extern unsigned char D_005CB010;
extern int D_00569B70;

__attribute__((section(".text.func_0020D140")))
int func_0020D140(void *a0)
{
    char *s0 = (char *)a0;
    unsigned short v1;
    int lim;
    int c;
    int ok;
    int t;
    int n;
    int q;
    short w;

    if (Obj0000_Get_Field_5FC_NE_Zero_12C748(Obj0000_Get_D_00747A94_2DB6B0()) != 0)
        return 0;
    if (0.0f < *(float *)(s0 + 0x1740)) return 0;
    v1 = *(unsigned short *)(s0 + 0x3AC);
    if ((v1 & 8) != 0) goto ret0;
    if ((v1 & 0x20) != 0) goto ret0;
    if ((v1 & 4) != 0) goto ret0;
    n = *(short *)(*(int *)(s0 + 0x698) + 0x46);
    switch (n) {
    case 1: case 2: case 3: case 4:
    case 7: case 8:
    case 12:
    case 14:
    case 17: case 18: case 19:
    case 21: case 22: case 23: case 24: case 25: case 26: case 27:
    case 43:
        break;
    case 85: default:
        return 0;
    }
    t = *(unsigned char *)(s0 + 0x17BB);
    if (t == 0) goto ret0;
    if (t != 1) goto ret0;
    if (D_005CB010 != 0) return 0;
    if (func_0026F1D8(s0) != 0) return 0;
    if ((*(unsigned short *)(s0 + 0x3AC) & 0x100) != 0) return 0;
    if (*(int *)(s0 + 0x17AC) <= 0) return 0;
    switch (cCoreSave_getGameLevel(&D_00569B70)) {
    case 1: default:
        lim = (Forward30F348_31CFE0() & 3) + 5;
        break;
    case 2:
        lim = (Forward30F348_31CFE0() & 3) + 4;
        break;
    case 3: case 4:
        lim = (Forward30F348_31CFE0() & 3) + 3;
        break;
    case 5:
        lim = (Forward30F348_31CFE0() & 3) + 2;
        break;
    }
    if (*(unsigned char *)(s0 + 0x17C1) != 0) lim = lim - 2;
    c = *(unsigned char *)(s0 + 0x17BF) + 1;
    *(unsigned char *)(s0 + 0x17BF) = c;
    if ((unsigned char)c >= 0x65) *(unsigned char *)(s0 + 0x17BF) = 0x64;
    if ((unsigned int)*(unsigned char *)(s0 + 0x17BF) < (unsigned int)lim)
        return 0;
    ok = 1;
    if (1.5707964f < *(float *)(s0 + 0x760)) ok = 0;
    if ((Forward30F348_31CFE0() & 3) != 0) ok = 0;
    if (ok == 0) return 0;
    q = *(int *)(s0 + 0x17AC);
    w = *(short *)(s0 + 0x548);
    if (q >= w)
        *(short *)(s0 + 0x54A) = *(unsigned short *)(s0 + 0x548);
    else
        *(short *)(s0 + 0x54A) = q;
    func_00274238(s0, 1);
    *(short *)(s0 + 0x17C8) = 0;
    *(int *)(s0 + 0x17C4) = -1;
    *(unsigned char *)(s0 + 0x17BF) = (unsigned int)Forward30F348_31CFE0() % 3;
    return 1;
ret0:
    return 0;
}

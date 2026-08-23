/* sn-2.95.3-136 matched TU. */

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern int Forward30F348_31CFE0(void);
extern int Obj0000_Get_Field_5FC_NE_Zero_12C748(void *a0);
extern int cCoreSave_getGameLevel(void *a0);
extern unsigned char D_005CB010;
extern int D_00569B70;

__attribute__((section(".text.func_0020CAC8")))
long func_0020CAC8(void *a0, int a1)
{
    char *s0 = (char *)a0;
    int s2 = a1;
    char *s1 = (char *)Obj0000_Get_D_00747A94_2DB6B0();
    int v1;
    int ok;
    int n;
    int v;

    v = *(unsigned char *)(s0 + 0x17BC);
    if (v == 1) goto arm1;
    if (v < 2) return 0;
    if (v == 2) goto body;
    return 0;
arm1:
    if ((Forward30F348_31CFE0() & 1) != 0) return 0;
body:
    if (D_005CB010 != 0) return 0;
    if (Obj0000_Get_Field_5FC_NE_Zero_12C748(s1) != 0) return 0;
    if (func_0026F1D8(s0) != 0) return 0;
    v1 = *(unsigned short *)(s0 + 0x3AC);
    if ((v1 & 0x100) != 0) return 0;
    if (*(int *)(s0 + 0x17AC) <= 0) return 0;
    if (2.3561945f < *(float *)(s0 + 0x760)) return 0;
    if (*(float *)(s0 + 0x5A8) < 1.0f) return 0;
    if (0.0f < *(float *)(s0 + 0x1740)) return 0;
    if ((v1 & 8) != 0) return 0;
    if ((v1 & 0x20) != 0) return 0;
    if ((v1 & 4) != 0) return 0;
    n = *(short *)(*(int *)(s0 + 0x698) + 0x46);
    if (n < 0x17) return 0;
    if (n >= 0x19) {
        if (n != 0x1B) return 0;
    }
    switch (cCoreSave_getGameLevel(&D_00569B70)) {
    case 1: default:
        ok = (((unsigned int)Forward30F348_31CFE0() % 8) == 0);
        break;
    case 2:
        ok = (((unsigned int)Forward30F348_31CFE0() % 6) == 0);
        break;
    case 3: case 4:
        ok = (((unsigned int)Forward30F348_31CFE0() % 4) == 0);
        break;
    case 5:
        ok = (((unsigned int)Forward30F348_31CFE0() % 3) == 0);
        break;
    }
    if (s2 == 1) ok = 1;
    if (ok == 0) return 0;
    *(unsigned char *)(s0 + 0x2F7) = 0;
    *(unsigned char *)(s0 + 0x2F4) = 0;
    *(unsigned char *)(s0 + 0x2F6) = 0;
    *(unsigned char *)(s0 + 0x2F5) = 0x46;
    return 1;
}

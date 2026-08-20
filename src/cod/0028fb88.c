/* sn-2.95.3-136 matched TU. */

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern int Obj0000_Get_Field_5FC_NE_Zero_12C748(void *a0);
extern unsigned char D_00747A50[];
extern unsigned char D_005CB010;
extern char *D_00586A80;

/* sn-2.95.3-136 matched TU. */







__attribute__((section(".text.func_0028FB88")))
short func_0028FB88(void *a0, int a1, void *a2, void *a3, int t0)
{
    char *s1 = (char *)a0;
    char *s2 = (char *)a2;
    void *g;
    float f;
    int n;
    short r;
    int ri;

    g = Obj0000_Get_D_00747A94_2DB6B0();
    f = 1.0f;
    if (a3 != 0) {
        switch (D_00747A50[1]) {
        case 1:
            break;
        case 2:
            f *= 1.3f;
            break;
        case 3:
            f *= 1.6f;
            break;
        case 4:
            f += f;
            break;
        case 5:
            f *= 2.3f;
            break;
        case 6:
            f *= 2.6f;
            break;
        case 7:
            f *= 3.0f;
            break;
        case 8:
            f *= 3.3f;
            break;
        }
    }
    if (s2 != 0 && *(unsigned short *)(s2 + 0x2FE) == 0x100) {
        if (Obj0000_Get_Field_5FC_NE_Zero_12C748(g) != 0) {
            f *= 1.5f;
        }
        if (t0 == 0 && D_005CB010 != 0) {
            switch (*(unsigned char *)(s1 + 0x622)) {
            case 0:
            default:
                f += f;
                break;
            case 1:
                f *= 1.5f;
                break;
            }
        }
    }
    n = (int)((float)a1 * f + 0.5f);
    if (n > 0x7D00) {
        n = 0x7D00;
    }
    ri = *(unsigned short *)(s1 + 0x54A) - n;
    *(short *)(s1 + 0x54A) = ri;
    if ((ri << 16) <= 0) {
        *(short *)(s1 + 0x54A) = 0;
    }
    if (*(int *)(s1 + 0x564) == 0x21F && *(unsigned char *)(s1 + 0x615) == 0) {
        char *o = D_00586A80;
        if (o != 0) {
            int t = *(unsigned short *)(o + 0x54A) - n / 2;
            *(short *)(o + 0x54A) = t;
            if ((short)t < 2) {
                *(short *)(o + 0x54A) = 1;
            }
        }
    }
    if (*(int *)(s1 + 0x564) == 0x23B) {
        *(short *)(s1 + 0x54A) = *(unsigned short *)(s1 + 0x548);
    }
    return *(short *)(s1 + 0x54A);
}

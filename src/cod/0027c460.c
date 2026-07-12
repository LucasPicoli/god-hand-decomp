/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int moveMotion(void *a0);
extern unsigned int Forward30F348_31CFE0(void);
extern void cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int a4, int a5, int a6, int a7);
extern int D_005FEE00;

__attribute__((section(".text.func_0027C460")))
void func_0027C460(void *a0)
{
    char *s0 = (char *)a0;
    char *v0;
    float f1, f0;

    *(int *)(s0 + 0x1560) |= 3;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        v0 = *(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0xC0) + (int)v0, *(int *)(v0 + 0xC4) + (int)v0, 0.0f, 5, 0, 0);
        *(float *)(s0 + 0x600) = 15.0f;
        *(unsigned char *)(s0 + 0x2F6) += 1;
        /* fallthrough */
    case 1:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        f1 = *(float *)(s0 + 0x600);
        if (f1 > 0.0f) {
            f0 = f1 - *(float *)(s0 + 0x5A8);
            *(float *)(s0 + 0x600) = f0;
            if (f0 <= 0.0f) {
                switch (Forward30F348_31CFE0() % 5) {
                case 0:
                default: cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0xA, s0, 0, 0, 0, 0); break;
                case 1: cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0xB, s0, 0, 0, 0, 0); break;
                case 2: cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0xE, s0, 0, 0, 0, 0); break;
                case 3: cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0xF, s0, 0, 0, 0, 0); break;
                case 4: cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0x10, s0, 0, 0, 0, 0); break;
                }
            }
        }
        break;
    }
}

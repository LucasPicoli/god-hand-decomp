/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern int Obj0000_Get_Field_424_1595F0(void *a0);
extern int D_005FEE00[];

/* sn-2.95.3-136 matched TU. */







__attribute__((section(".text.func_00280770")))
void func_00280770(void *a0) {
    char *s0 = (char *)a0;
    int v0;
    unsigned long t0 = 0;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x120) + v0, *(int *)(v0 + 0x124) + v0, 0.0f, 2, t0, 0);
        cSnd_SeCall_2CBA48(D_005FEE00, 1, (short)Obj0000_Get_Field_424_1595F0(s0), s0, 0, 0, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_mm;
    case 2:
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x128) + v0, *(int *)(v0 + 0x12C) + v0, 0.0f, 2, t0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
    case 3:
    L_mm:
        moveMotion(s0);
        break;
    case 4:
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x130) + v0, *(int *)(v0 + 0x134) + v0, 0.0f, 2, t0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 5:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        break;
    }
}

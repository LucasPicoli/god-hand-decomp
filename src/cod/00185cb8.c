/* sn-2.95.3-136 matched TU. */

extern void cOmBase_setMeshDispFromLayer(void *a0, int a1, int a2);
extern void cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);
extern void func_00186038(void *a0, int a1);
extern int D_005FEE00[];

__attribute__((section(".text.func_00185CB8")))
void func_00185CB8(void *a0, int a1) {
    void *s0 = a0;
    cOmBase_setMeshDispFromLayer(s0, 0x10, 0);
    cOmBase_setMeshDispFromLayer(s0, 0x11, 0);
    cOmBase_setMeshDispFromLayer(s0, 0x12, 0);
    cOmBase_setMeshDispFromLayer(s0, 0x13, 0);
    switch (a1) {
    case 0:
        cOmBase_setMeshDispFromLayer(s0, 0x10, 1);
        break;
    case 1:
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x111, s0, 0, 0, 0, 0);
        cOmBase_setMeshDispFromLayer(s0, 0x11, 1);
        break;
    case 2:
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x111, s0, 0, 0, 0, 0);
        cOmBase_setMeshDispFromLayer(s0, 0x12, 1);
        break;
    case 3:
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x111, s0, 0, 0, 0, 0);
        cOmBase_setMeshDispFromLayer(s0, 0x13, 1);
        break;
    case 4:
        SetEffect(0x298, 0xB, s0, 0, -1, 0xFFFFFFFFU);
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x112, s0, 0, 0, 0, 0);
        cOmBase_setMeshDispFromLayer(s0, 0x13, 1);
        func_00186038(s0, 0xE);
        func_00186038(s0, 0xF);
        break;
    }
}

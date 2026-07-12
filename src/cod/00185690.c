/* sn-2.95.3-136 matched TU. */

extern void cOmBase_setMeshDispFromLayer(void *a0, int a1, int a2);
extern void cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);
extern void func_00186038(void *a0, int a1);
extern int D_005FEE00[];

__attribute__((section(".text.func_00185690")))
void func_00185690(void *a0, int a1) {
    void *s0 = a0;
    cOmBase_setMeshDispFromLayer(s0, 0x15, 0);
    cOmBase_setMeshDispFromLayer(s0, 0x16, 0);
    cOmBase_setMeshDispFromLayer(s0, 0x17, 0);
    cOmBase_setMeshDispFromLayer(s0, 0x18, 0);
    cOmBase_setMeshDispFromLayer(s0, 0x1A, 0);
    cOmBase_setMeshDispFromLayer(s0, 0x1B, 0);
    cOmBase_setMeshDispFromLayer(s0, 0x1C, 0);
    switch (a1) {
    case 0:
        cOmBase_setMeshDispFromLayer(s0, 0x15, 1);
        cOmBase_setMeshDispFromLayer(s0, 0x1A, 1);
        break;
    case 1:
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x111, s0, 0, 0, 0, 0);
        cOmBase_setMeshDispFromLayer(s0, 0x16, 1);
        cOmBase_setMeshDispFromLayer(s0, 0x1B, 1);
        break;
    case 2:
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x111, s0, 0, 0, 0, 0);
        cOmBase_setMeshDispFromLayer(s0, 0x17, 1);
        cOmBase_setMeshDispFromLayer(s0, 0x1C, 1);
        break;
    case 3:
        SetEffect(0x298, 0x9, s0, 0, -1, 0xFFFFFFFFU);
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x112, s0, 0, 0, 0, 0);
        cOmBase_setMeshDispFromLayer(s0, 0x18, 1);
        cOmBase_setMeshDispFromLayer(s0, 0x1C, 1);
        func_00186038(s0, 0x7);
        break;
    case 4:
        SetEffect(0x298, 0xA, s0, 0, -1, 0xFFFFFFFFU);
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x112, s0, 0, 0, 0, 0);
        cOmBase_setMeshDispFromLayer(s0, 0x18, 1);
        cOmBase_setMeshDispFromLayer(s0, 0x1C, 1);
        func_00186038(s0, 0x8);
        func_00186038(s0, 0x9);
        func_00186038(s0, 0xA);
        func_00186038(s0, 0xB);
        break;
    }
}

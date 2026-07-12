/* sn-2.95.3-136 matched TU. */

extern void cOmBase_setMeshDispFromLayer(int a0, int a1, int a2);
extern void cSnd_SeCall_2CBA48(void *a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern void SetEffect(int a0, int a1, int a2, int a3, int a4, unsigned int a5);
extern void func_00186038(int a0, int a1);
extern int D_005FEE00;

__attribute__((section(".text.func_001852E8")))
void func_001852E8(int arg0, unsigned int arg1)
{
    cOmBase_setMeshDispFromLayer(arg0, 1, 0);
    cOmBase_setMeshDispFromLayer(arg0, 2, 0);
    cOmBase_setMeshDispFromLayer(arg0, 3, 0);
    cOmBase_setMeshDispFromLayer(arg0, 4, 0);
    cOmBase_setMeshDispFromLayer(arg0, 6, 0);
    cOmBase_setMeshDispFromLayer(arg0, 7, 0);
    cOmBase_setMeshDispFromLayer(arg0, 8, 0);
    switch (arg1) {
    case 0:
        cOmBase_setMeshDispFromLayer(arg0, 1, 1);
        cOmBase_setMeshDispFromLayer(arg0, 6, 1);
        break;
    case 1:
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x111, arg0, 0, 0, 0, 0);
        cOmBase_setMeshDispFromLayer(arg0, 2, 1);
        cOmBase_setMeshDispFromLayer(arg0, 7, 1);
        break;
    case 2:
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x111, arg0, 0, 0, 0, 0);
        cOmBase_setMeshDispFromLayer(arg0, 3, 1);
        cOmBase_setMeshDispFromLayer(arg0, 8, 1);
        break;
    case 3:
        SetEffect(0x298, 7, arg0, 0, -1, 0xFFFFFFFF);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x112, arg0, 0, 0, 0, 0);
        cOmBase_setMeshDispFromLayer(arg0, 4, 1);
        cOmBase_setMeshDispFromLayer(arg0, 8, 1);
        func_00186038(arg0, 0);
        func_00186038(arg0, 1);
        func_00186038(arg0, 2);
        break;
    case 4:
        SetEffect(0x298, 8, arg0, 0, -1, 0xFFFFFFFF);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x112, arg0, 0, 0, 0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x114, arg0, 0, 0, 0, 0);
        cOmBase_setMeshDispFromLayer(arg0, 4, 1);
        cOmBase_setMeshDispFromLayer(arg0, 8, 1);
        func_00186038(arg0, 3);
        func_00186038(arg0, 4);
        func_00186038(arg0, 5);
        func_00186038(arg0, 6);
        break;
    }
}

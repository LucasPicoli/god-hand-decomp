/* sn-2.95.3-136 matched TU. */

extern void cOmBase_setMeshDispFromLayer(int a0, int a1, int a2);
extern void cSnd_SeCall_2CBA48(void *a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern void SetEffect(int a0, int a1, int a2, int a3, int a4, unsigned int a5);
extern void func_00186038(int a0, int a1);
extern int D_005FEE00;

__attribute__((section(".text.func_00185A20")))
void func_00185A20(int arg0, unsigned int arg1)
{
    cOmBase_setMeshDispFromLayer(arg0, 0xB, 0);
    cOmBase_setMeshDispFromLayer(arg0, 0xC, 0);
    cOmBase_setMeshDispFromLayer(arg0, 0xD, 0);
    cOmBase_setMeshDispFromLayer(arg0, 0xE, 0);
    switch (arg1) {
    case 0:
        cOmBase_setMeshDispFromLayer(arg0, 0xB, 1);
        break;
    case 1:
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x111, arg0, 0, 0, 0, 0);
        cOmBase_setMeshDispFromLayer(arg0, 0xC, 1);
        break;
    case 2:
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x111, arg0, 0, 0, 0, 0);
        cOmBase_setMeshDispFromLayer(arg0, 0xD, 1);
        break;
    case 3:
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x111, arg0, 0, 0, 0, 0);
        cOmBase_setMeshDispFromLayer(arg0, 0xE, 1);
        break;
    case 4:
        SetEffect(0x298, 0xC, arg0, 0, -1, 0xFFFFFFFF);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x112, arg0, 0, 0, 0, 0);
        cOmBase_setMeshDispFromLayer(arg0, 0xE, 1);
        func_00186038(arg0, 0xC);
        func_00186038(arg0, 0xD);
        break;
    }
}

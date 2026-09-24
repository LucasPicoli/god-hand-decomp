/* sn-2.95.3-136 matched TU. */

extern void cOmBase_setMeshDispFromLayer(int a0, int a1, int a2);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern void SetEffect(int a0, int a1, int a2, int a3, int a4, unsigned int a5);
extern int D_005FEE00;

__attribute__((section(".text.func_00185910")))
void func_00185910(int arg0, int arg1)
{
    cOmBase_setMeshDispFromLayer(arg0, 0x24, 0);
    cOmBase_setMeshDispFromLayer(arg0, 0x25, 0);
    switch (arg1) {
    case 0:
        cOmBase_setMeshDispFromLayer(arg0, 0x24, 1);
        break;
    case 1:
        cOmBase_setMeshDispFromLayer(arg0, 0x25, 1);
        break;
    case 4:
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x115, arg0, 0, 0, 0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x113, arg0, 0, 0, 0, 0);
        SetEffect(0x298, 5, arg0, 0, -1, 0xFFFFFFFF);
        break;
    }
}

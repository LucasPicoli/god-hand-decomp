/* TU: CasinoWork [casino] - recovered C++ class. */
extern int Obj0000_Get_D_00747A94_2DB6B0(void);
extern void cCoreSave_setVital(void *a0, int a1);
extern void cHeatSys_SetHeatGage(void *a0, float a1);
extern void Obj1FA6_Set_Short_1C_1FA638(void *a0, short a1);
extern void cCoreSave_clearGodItem(void *a0);
extern void cCoreSave_addGodItem(void *a0, int a1);
extern int D_00569B70;
extern int D_005CB000;

__attribute__((section(".text.CasinoWork_ResetWarmUpRoom")))
void CasinoWork_ResetWarmUpRoom(int *a0)
{
    int obj;
    int i;
    int v;

    obj = Obj0000_Get_D_00747A94_2DB6B0();
    v = a0[1];
    if (v >= *(short *)(obj + 0x548)) {
        *(short *)(obj + 0x54A) = *(unsigned short *)(obj + 0x548);
    } else {
        *(short *)(obj + 0x54A) = v;
    }
    cCoreSave_setVital(&D_00569B70, a0[1]);
    cHeatSys_SetHeatGage(&D_005CB000, *(float *)((char *)a0 + 0x8));
    Obj1FA6_Set_Short_1C_1FA638(&D_00569B70, *(short *)((char *)a0 + 0xC));
    cCoreSave_clearGodItem(&D_00569B70);
    for (i = 0; i < *(unsigned short *)((char *)a0 + 0xE); i++) {
        cCoreSave_addGodItem(&D_00569B70, 1);
    }
    *a0 = *a0 & -2;
}

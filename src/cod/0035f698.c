/* cygnus-2.96: SFX stream decoder callback setup (0x35F698). */

#include "godhand/sfxlib.h"
#include "godhand/SfdYuv.h"

extern void Obj35E8_SetField_68(SfxStm *stm, void *fn);
extern void Obj35E8_SetField_6C(SfxStm *stm, void *fn);
extern void Obj35E8_SetField_70(SfxStm *stm, void *fn);
extern void Obj35E8_SetIndirect_30_18(SfxStm *stm, void *fn);
extern void Obj35E8_SetIndirect_30_1C(SfxStm *stm, void *fn);
extern void Obj35E8_SetIndirect_30_20(SfxStm *stm, void *fn);
extern void func_0035EF78(SfxStm *stm, SfxInf *inf, int c);

extern int CFT_Ycc420mbToArgb8888mb(int a0, int a1, int *a2);
extern void func_00366840(int a0, int a1, int a2);
extern void CFT_Argb8888mbToA256V(int *p);
extern void CFT_MakeArgb8888Alp3211Tbl(int a0, int a1, int a2, int a3);
extern void func_00366110(int a0, int a1, int a2, int a3);
extern void CFT_MakeArgb8888ColAdjTbl(void *dst);

__attribute__((section(".text.func_0035F698")))
void func_0035F698(SfxStm *stm, SfxInf *inf, int c)
{
    void *fn = 0;
    void *dec;

    stm->f50 = 0;
    dec = 0;
    if (inf->kind == 1) {
        dec = (void *)CFT_Ycc420mbToArgb8888mb;
    }
    Obj35E8_SetField_68(stm, dec);
    if (inf->kind == 1) {
        fn = (void *)func_00366840;
    } else if (inf->kind == 2) {
        fn = (void *)CFT_Argb8888mbToA256V;
    }
    Obj35E8_SetField_6C(stm, fn);
    Obj35E8_SetIndirect_30_18(stm, (void *)CFT_MakeArgb8888AlpLumiTbl);
    Obj35E8_SetIndirect_30_20(stm, (void *)CFT_MakeArgb8888Alp3211Tbl);
    Obj35E8_SetIndirect_30_1C(stm, (void *)func_00366110);
    Obj35E8_SetField_70(stm, (void *)CFT_MakeArgb8888ColAdjTbl);
    func_0035EF78(stm, inf, c);
}

/* TU: ccoresave_gameinit [system] - recovered method extracted to its own TU
   (sn-2.95.3-136 cc1 ICEs on this body inside the full cCoreSave.c). */
/* cCoreSave_gameInit - reset the record for a new game. */
#include "godhand/cCoreSave.h"

extern void cCoreSave_clearGodItem(cCoreSave *);
extern void cCoreSave_setGold(cCoreSave *, int);
extern void cCoreSave_setGameLevel(cCoreSave *, int);
extern void func_001FACB0(cCoreSave *);
extern int GetField80ViaPtr_1FAC80(cCoreSave *);
extern void cCoreSave_setVital(cCoreSave *, int);
extern void func_001FB980(cCoreSave *);
extern void Obj0000_Set_Short_88_If_LT_1000(cCoreSave *, int);
extern void func_001FBD00(cCoreSave *, int);
extern void func_001FAA68(cCoreSave *, int, int);
extern void cCoreSave_setClearNum(cCoreSave *, int);
extern void ClearField46Array_1FBDD0(cCoreSave *);
extern void cCoreSave_clearKillNpcNum(cCoreSave *);
extern void cCoreSave_initAddGold(cCoreSave *);
extern void cCoreSave_initContinueNum(cCoreSave *);
extern void func_001FC090(cCoreSave *);
extern void Obj0000_Set_Bytes_AE_AF_1FC100(cCoreSave *, int);
extern void func_001F9FC0(cCoreSave *);
extern void func_001FC278(cCoreSave *);
extern void func_001FC320(cCoreSave *);
extern void Obj0000_Set_Byte_156_If_NonNull_1FAE28(cCoreSave *, int);
extern void func_001FC438(cCoreSave *);
extern void func_001FC5E8(cCoreSave *);
extern void func_001FC548(cCoreSave *);
extern void func_001FC5B8(cCoreSave *);
extern void func_001FC618(cCoreSave *);
extern int Obj0000_Get_Byte_1F_If_Ptr_NonNull_1FA678(cCoreSave *);
extern void cCoreSave_setGameLevel1_1F9AD0(cCoreSave *);
extern void func_001F9A98(cCoreSave *);
extern void cCoreSave_setGameLevel5_1F9AF0(cCoreSave *);
extern void cCoreSave_addGodItem(cCoreSave *, int);

__attribute__((section(".text.cCoreSave_gameInit")))
void cCoreSave_gameInit(cCoreSave *self)
{
    int v1;

    cCoreSave_clearGodItem(self);
    cCoreSave_setGold(self, 0);
    cCoreSave_setGameLevel(self, 1);
    func_001FACB0(self);
    cCoreSave_setVital(self, GetField80ViaPtr_1FAC80(self));
    func_001FB980(self);
    Obj0000_Set_Short_88_If_LT_1000(self, 0x80);
    func_001FBD00(self, 4);
    func_001FAA68(self, 0, 0);
    func_001FAA68(self, 1, 0);
    func_001FAA68(self, 2, 0);
    func_001FAA68(self, 3, 0);
    cCoreSave_setClearNum(self, 0);
    ClearField46Array_1FBDD0(self);
    cCoreSave_clearKillNpcNum(self);
    cCoreSave_initAddGold(self);
    cCoreSave_initContinueNum(self);
    func_001FC090(self);
    Obj0000_Set_Bytes_AE_AF_1FC100(self, 0);
    func_001F9FC0(self);
    func_001FC278(self);
    func_001FC320(self);
    Obj0000_Set_Byte_156_If_NonNull_1FAE28(self, 2);
    func_001FC438(self);
    func_001FC5E8(self);
    func_001FC548(self);
    func_001FC5B8(self);
    func_001FC618(self);
    v1 = Obj0000_Get_Byte_1F_If_Ptr_NonNull_1FA678(self);
    switch (v1) {
    case 1:
    default:
        cCoreSave_setGameLevel1_1F9AD0(self);
        break;
    case 0:
        func_001F9A98(self);
        break;
    case 2:
        cCoreSave_setGameLevel5_1F9AF0(self);
        break;
    }
    cCoreSave_addGodItem(self, 1);
    cCoreSave_addGodItem(self, 1);
    cCoreSave_addGodItem(self, 1);
}

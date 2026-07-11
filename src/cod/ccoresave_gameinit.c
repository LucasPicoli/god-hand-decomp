/* TU: ccoresave_gameinit [system] - recovered method extracted to its own TU
   (sn-2.95.3-136 cc1 ICEs on this body inside the full cCoreSave.c). */
/* cCoreSave_gameInit */
extern void cCoreSave_clearGodItem(void *);
extern void cCoreSave_setGold(void *, int);
extern void cCoreSave_setGameLevel(void *, int);
extern void func_001FACB0(void *);
extern int GetField80ViaPtr_1FAC80(void *);
extern void cCoreSave_setVital(void *, int);
extern void func_001FB980(void *);
extern void Obj0000_Set_Short_88_If_LT_1000(void *, int);
extern void func_001FBD00(void *, int);
extern void func_001FAA68(void *, int, int);
extern void cCoreSave_setClearNum(void *, int);
extern void ClearField46Array_1FBDD0(void *);
extern void cCoreSave_clearKillNpcNum(void *);
extern void cCoreSave_initAddGold(void *);
extern void cCoreSave_initContinueNum(void *);
extern void func_001FC090(void *);
extern void Obj0000_Set_Bytes_AE_AF_1FC100(void *, int);
extern void func_001F9FC0(void *);
extern void func_001FC278(void *);
extern void func_001FC320(void *);
extern void Obj0000_Set_Byte_156_If_NonNull_1FAE28(void *, int);
extern void func_001FC438(void *);
extern void func_001FC5E8(void *);
extern void func_001FC548(void *);
extern void func_001FC5B8(void *);
extern void func_001FC618(void *);
extern int Obj0000_Get_Byte_1F_If_Ptr_NonNull_1FA678(void *);
extern void cCoreSave_setGameLevel1_1F9AD0(void *);
extern void func_001F9A98(void *);
extern void cCoreSave_setGameLevel5_1F9AF0(void *);
extern void cCoreSave_addGodItem(void *, int);

__attribute__((section(".text.cCoreSave_gameInit")))
void cCoreSave_gameInit(void *a0)
{
    int v1;

    cCoreSave_clearGodItem(a0);
    cCoreSave_setGold(a0, 0);
    cCoreSave_setGameLevel(a0, 1);
    func_001FACB0(a0);
    cCoreSave_setVital(a0, GetField80ViaPtr_1FAC80(a0));
    func_001FB980(a0);
    Obj0000_Set_Short_88_If_LT_1000(a0, 0x80);
    func_001FBD00(a0, 4);
    func_001FAA68(a0, 0, 0);
    func_001FAA68(a0, 1, 0);
    func_001FAA68(a0, 2, 0);
    func_001FAA68(a0, 3, 0);
    cCoreSave_setClearNum(a0, 0);
    ClearField46Array_1FBDD0(a0);
    cCoreSave_clearKillNpcNum(a0);
    cCoreSave_initAddGold(a0);
    cCoreSave_initContinueNum(a0);
    func_001FC090(a0);
    Obj0000_Set_Bytes_AE_AF_1FC100(a0, 0);
    func_001F9FC0(a0);
    func_001FC278(a0);
    func_001FC320(a0);
    Obj0000_Set_Byte_156_If_NonNull_1FAE28(a0, 2);
    func_001FC438(a0);
    func_001FC5E8(a0);
    func_001FC548(a0);
    func_001FC5B8(a0);
    func_001FC618(a0);
    v1 = Obj0000_Get_Byte_1F_If_Ptr_NonNull_1FA678(a0);
    switch (v1) {
    case 1:
    default:
        cCoreSave_setGameLevel1_1F9AD0(a0);
        break;
    case 0:
        func_001F9A98(a0);
        break;
    case 2:
        cCoreSave_setGameLevel5_1F9AF0(a0);
        break;
    }
    cCoreSave_addGodItem(a0, 1);
    cCoreSave_addGodItem(a0, 1);
    cCoreSave_addGodItem(a0, 1);
}

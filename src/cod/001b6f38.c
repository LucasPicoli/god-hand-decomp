/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern int D_00428A20;
extern char D_005CAE50[];
extern char D_00462FC0[];
extern char D_00574380[];
extern void func_001331B8(char *a0, long a1, int a2);
extern void cCollisionSolidManage_ReleaseUnit(char *a0, char *a1);
extern void ReleaseObj(char *a0);
extern void func_001FE370(char *a0, char *a1);
extern void func_002A73C8(char *a0, char *a1);
extern void Obj0000_Swap_Field_4_In_Scaled_A1_Entry_1F7800(int a0, int a1, int *a2);
extern void UnlinkAndCoalesceNode_2A9680(int, int *);
extern void cCoreSave_initAddGold(void *);
extern int D_00747A34;

__attribute__((section(".text.SetField214PtrThenInit_1B6F38")))
void SetField214PtrThenInit_1B6F38(char *a0, char *a1) {
    *(int*)(a0 + 0x214) = (int)&D_00428A20;
    func_001331B8(D_005CAE50, *(long*)(a0 + 0x540), 0);
    cCollisionSolidManage_ReleaseUnit(D_00462FC0, a0);
    ReleaseObj(a0);
    func_001FE370(D_00574380, a0);
    func_002A73C8(a0, a1);
}

__attribute__((section(".text.ReleaseField6ECByTag564_26B1E8")))
void ReleaseField6ECByTag564_26B1E8(void *a0)
{
    int x = *(int *)((char *)a0 + 0x6EC);
    if (x != 0) {
        if (*(int *)((char *)a0 + 0x564) == 0x279) {
            cOmWeapon_SetBreak(x);
            *(int *)((char *)a0 + 0x6EC) = 0;
        } else {
            cOmWeapon_setFall(x);
            *(int *)((char *)a0 + 0x6EC) = 0;
        }
    }
}

__attribute__((section(".text.LookupSlotPopulateFieldsAndDispatch_1F7858")))
void LookupSlotPopulateFieldsAndDispatch_1F7858(int a0, int a1, int a2, int a3, int t0, int t1, int t2)
{
    int *p = func_001F7798(a0);
    if (p != 0) {
        p[7] = a2;
        p[8] = a3;
        p[0] |= 1;
        p[4] = t0;
        p[5] = t1;
        p[9] = t2;
        p[6] = a1;
        Obj0000_Swap_Field_4_In_Scaled_A1_Entry_1F7800(a0, a1, p);
    }
}

__attribute__((section(".text.__builtin_delete")))
void __builtin_delete(int *a0) {
    if (a0) {
        UnlinkAndCoalesceNode_2A9680(*(int*)((char*)a0 - 0x20), a0);
    }
}


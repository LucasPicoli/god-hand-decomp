/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cActionButton.h"

extern int D_00428A20;
extern char D_005CAE50[];
extern char D_00462FC0[];
extern char D_00574380[];
extern void func_001331B8(char *a0, long a1, int a2);
extern void cCollisionSolidManage_ReleaseUnit(char *a0, char *a1);
extern void ReleaseObj(char *a0);
extern void func_001FE370(char *a0, char *a1);
extern void func_002A73C8(char *a0, char *a1);
extern cActionButtonEnt *func_001F7798(cActionButton *self);
extern void Obj0000_Swap_Field_4_In_Scaled_A1_Entry_1F7800(cActionButton *self, int priority, cActionButtonEnt *ent);
extern void cHeap_free(int, int *);
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

/* Take a free entry and set its life, kind, flags and priority, then let
 * the manager sort it in by priority. */
__attribute__((section(".text.cActionButton_set")))
void cActionButton_set(cActionButton *self, int priority, int life, int a3, int a4, int a5, int kind)
{
    cActionButtonEnt *ent = func_001F7798(self);
    if (ent != 0) {
        ent->life = life;
        ent->unk20 = a3;
        ent->flags |= ACTBTN_ENT_USED;
        ent->unk10 = a4;
        ent->unk14 = a5;
        ent->kind = kind;
        ent->priority = priority;
        Obj0000_Swap_Field_4_In_Scaled_A1_Entry_1F7800(self, priority, ent);
    }
}

__attribute__((section(".text.__builtin_delete")))
void __builtin_delete(int *a0) {
    if (a0) {
        cHeap_free(*(int*)((char*)a0 - 0x20), a0);
    }
}


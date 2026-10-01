#include "godhand/cCoreSave.h"
#include "godhand/cOmBase.h"
extern int D_005CAFF0;
extern int D_007476B0;
extern char *D_00566E10;
extern char D_00506E10[];
extern int D_00747A78;

__attribute__((section(".text.UpdateField78_FromField90_146F70")))
void UpdateField78_FromField90_146F70(char *a0) {
    if (*(unsigned char*)(a0 + 0x90) != 0) {
        *(char*)(a0 + 0x78) = 0;
    } else {
        *(char*)(a0 + 0x78) = 1;
    }
    *(char*)(a0 + 0x90) = 0;
}

__attribute__((section(".text.SetField2F5IfField615Active_1A7A08")))
void SetField2F5IfField615Active_1A7A08(int a0) {
    if (*(unsigned char*)((char*)a0 + 0x615)) {
        *(char*)((char*)a0 + 0x2F7) = 0;
        *(char*)((char*)a0 + 0x2F6) = 0;
        *(char*)((char*)a0 + 0x2F5) = 1;
    }
}

__attribute__((section(".text.SetField_ACD0_1FE348")))
void SetField_ACD0_1FE348(int a0, int a1) {
    *(int*)(a0 + 0xACD0) = a1;
}

__attribute__((section(".text.IsFieldActive_1FE358")))
int IsFieldActive_1FE358(int a0) {
    return *(int*)(a0 + 0xACD0) != 0;
}

__attribute__((section(".text.IsStateVal6_10B5C8")))
int IsStateVal6_10B5C8(char *a0) {
    if (*(unsigned char*)((char*)a0+0x2F4) != 0) {
        return 0;
    }
    return *(unsigned char*)((char*)a0+0x2F5) == 0x6;
}

__attribute__((section(".text.IsStateVal3_10B620")))
int IsStateVal3_10B620(char *a0) {
    if (*(unsigned char*)((char*)a0+0x2F4) != 0) {
        return 0;
    }
    return *(unsigned char*)((char*)a0+0x2F5) == 0x3;
}

__attribute__((section(".text.IsStateVal17_10B648")))
int IsStateVal17_10B648(char *a0) {
    if (*(unsigned char*)((char*)a0+0x2F4) != 0) {
        return 0;
    }
    return *(unsigned char*)((char*)a0+0x2F5) == 0x11;
}

__attribute__((section(".text.IsByte2F5Eq7_WhenByte2F4Zero_10B670")))
int IsByte2F5Eq7_WhenByte2F4Zero_10B670(char *a0) {
    if (*(unsigned char*)((char*)a0+0x2F4) != 0) {
        return 0;
    }
    return *(unsigned char*)((char*)a0+0x2F5) == 0x7;
}

__attribute__((section(".text.SetFirstFreeSlot_Field_1644_1268B0")))
void SetFirstFreeSlot_Field_1644_1268B0(int a0, int a1) {
    unsigned int i = 0;
    int k = 15;
    int *p = (int *)((char *)a0 + 0x1644);
    do {
        if (*p != 0) {
            i++;
            p++;
            continue;
        }
        *p = a1;
        *(int *)((char *)a0 + 0x1658) = k;
        return;
    } while (i < 5);
}

__attribute__((section(".text.SetNodeListFlag_134608")))
void SetNodeListFlag_134608(int a0, int a1) {
    int *node = *(int **)((char *)a0 + 4);
    if (node == 0) {
        return;
    }
    do {
        int v = *(int *)((char *)node + 8);
        if (a1 == 1) {
            v = v | 1;
        } else {
            v = v & -2;
        }
        *(int *)((char *)node + 8) = v;
        node = *(int **)node;
    } while (node != 0);
}

__attribute__((section(".text.AddToActiveList_138F40")))
void AddToActiveList_138F40(int *a0) {
    int a2 = *(int *)((char *)a0 + 0x1028);
    int v1, a3;
    if (a2 == 0x10) {
        return;
    }
    v1 = *(int *)((char *)a0 + 0xFF0);
    a3 = D_005CAFF0;
    if (v1 == 0) {
        *(int *)((char *)a0 + 0x1028) = 1;
        D_005CAFF0 = (int)a0;
    } else {
        *(int *)((char *)a0 + 0x1028) = *(int *)((char *)a0 + 0x102C);
        D_005CAFF0 = v1;
    }
    *(int *)((char *)a0 + 0x102C) = a2;
    *(int *)((char *)a0 + 0xFF0) = a3;
}

__attribute__((section(".text.ClearFields_A0_250_358_13F2F8")))
void ClearFields_A0_250_358_13F2F8(int *a0) {
    char *a2 = (char *)a0 + 0x250;
    unsigned short i;
    *(int *)((char *)a0 + 0xA0) = 0;
    i = 0;
    do {
        *(int *)(a2 + (i << 2)) = 0;
        i = (unsigned short)(i + 1);
    } while (i < 5);
    *(char *)((char *)a0 + 0x358) = 0;
}

__attribute__((section(".text.PostInc_D_00566E10_0015B0F0_15B0F0")))
int PostInc_D_00566E10_0015B0F0_15B0F0(int a0) {
    char *cur = D_00566E10;
    char *newp = cur + a0;
    char *limit = D_00506E10 + (D_007476B0 & 1) * 0x60000;
    if (limit < newp) return 0;
    D_00566E10 = newp;
    return (int)cur;
}

__attribute__((section(".text.SetFlagOnChildren_167EE8")))
void SetFlagOnChildren_167EE8(int a0)
{
    int **p = (int **)((char *)a0 + 0x80);
    unsigned int i = 0;
    do {
        int *q = *p;
        i++;
        p++;
        *(int *)((char *)q + 0x2C) |= 0x08000000;
    } while (i < 16);
}

__attribute__((section(".text.GetTypeDefaultValue_16EDE0")))
int GetTypeDefaultValue_16EDE0(int a0)
{
    int v0;
    switch (*(unsigned char *)((char *)a0 + 0x64)) {
    default:
        v0 = 0xA;
        break;
    case 0:
        v0 = -1;
        *(int *)((char *)a0 + 0x60) = v0;
        break;
    case 1:
        v0 = 0xA;
        *(int *)((char *)a0 + 0x60) = v0;
        break;
    }
    return v0;
}

__attribute__((section(".text.SetActorLink_1B7118")))
int SetActorLink_1B7118(int a0, int a1) {
    int v1;
    int p;
    short off;
    int (*fp)(int);
    *(int*)((char*)a0 + 0x5E0) = a1;
    v1 = *(int*)((char*)a1 + 0x20);
    if (v1 != 0) {
        if ((unsigned int)v1 < 0x200) {
            *(int*)((char*)a0 + 0x560) = v1 + 0x300;
        } else {
            *(int*)((char*)a0 + 0x560) = v1 + 0x700;
        }
    }
    p = *(int*)((char*)a0 + 0x214);
    off = *(short*)((char*)p + 0x40);
    fp = *(int (**)(int))((char*)p + 0x44);
    fp(a0 + off);
    return 1;
}

/* Clear the hit flags unless the global freeze flag is set; returns 0 while frozen. */
__attribute__((section(".text.ClearField5B4IfFlagUnset_1B76B0")))
int ClearField5B4IfFlagUnset_1B76B0(cOmBase *self) {
    int ran = 1;
    if (D_00747A78 & 0x20000000) {
        ran = 0;
        return ran;
    }
    self->hitFlags = 0;
    return ran;
}

__attribute__((section(".text.IsSpecialAnim_1C24A0")))
int IsSpecialAnim_1C24A0(void *a0) {
    switch (*(unsigned short *)((char *)a0 + 0x2FE)) {
    case 0x3BC:
    case 0x3D9:
    case 0x3E3:
        return 1;
    }
    return 0;
}

/* True in mode 0, phase 4. */
__attribute__((section(".text.Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08")))
int Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08(cOmBase *self) {
    if (self->mode != 0) return 0;
    return (self->phase ^ 4) == 0;
}

__attribute__((section(".text.SetLinkedObjField2B_1D6D68")))
void SetLinkedObjField2B_1D6D68(char *a0, int a1) {
    if (a1 != 0) {
        *(char*)(*(int*)(a0 + 0x1D8) + 0x2B) = 3;
        *(char*)(*(int*)(a0 + 0x254) + 0x2B) = 4;
    } else {
        char *v1 = a0 + 0x1D4;
        char *a5 = a0 + 0x250;
        *(char*)(*(int*)(v1 + 0x4) + 0x2B) = *(unsigned char*)(v1 + 0x78);
        *(char*)(*(int*)(a5 + 0x4) + 0x2B) = *(unsigned char*)(a5 + 0x78);
    }
}

extern int *D_003BD6E8;
extern int D_0042C320;
extern int D_0061A990[];
extern unsigned short D_007474A0[];
extern unsigned char D_005E85F8;
extern unsigned int D_00747A34;
extern int D_00747A38;
extern int D_00747A3C;
extern int D_00747A80;
extern unsigned char D_0041D5A8[];
extern unsigned char D_0041D540[];

__attribute__((section(".text.SetFlagBitF30IfField35Active_1F6EE0")))
void SetFlagBitF30IfField35Active_1F6EE0(unsigned char *a0)
{
    if (a0[0x35] != 1) {
        return;
    }
    {
        char *p = (char *)D_003BD6E8;
        *(int *)(p + 0xF30) |= 0x10000000;
    }
}

__attribute__((section(".text.Setup_1F7AE8")))
void Setup_1F7AE8(int a0)
{
    char *p = (char *)a0;
    unsigned int mask = 0xFFFFFFFE;
    *(int *)(p + 0x0) = *(int *)(p + 0x0) & mask;
    *(int *)(p + 0xC) = 1;
    *(int *)(p + 0x1C) = 0x31;
    *(int *)(p + 0x2C) = 0x1F;
    *(int *)(p + 0x10) = 0;
    *(int *)(p + 0x14) = 0;
    *(int *)(p + 0x18) = 0;
    *(int *)(p + 0x24) = 0;
    *(int *)(p + 0x20) = 0;
    *(int *)(p + 0x28) = 0;
    *(short *)(p + 0x30) = 0;
    *(char *)(p + 0x34) = 0;
    *(char *)(p + 0x35) = 0;
    *(short *)(p + 0x32) = 0;
    *(char *)(p + 0x36) = 0;
    *(int *)(p + 0x38) = 0;
    *(int *)(p + 0x3C) = 0;
    *(int *)(p + 0x40) = 0;
}

__attribute__((section(".text.InitVtableAndClearFlags_1F7B60")))
void InitVtableAndClearFlags_1F7B60(unsigned int *a0) {
    unsigned int a1 = a0[0];
    a0[2] = (unsigned int)&D_0042C320;
    a0[0] = a1 & 0xFFFFF9FC;
}

__attribute__((section(".text.InitVtablePtrAndClearFlags_1F7C60")))
void InitVtablePtrAndClearFlags_1F7C60(unsigned int *a0) {
    unsigned int a1 = a0[0];
    a0[2] = (unsigned int)&D_0042C320;
    a0[0] = a1 & 0xFFFFF9FC;
}

__attribute__((section(".text.cCoreSave_saveWorldTime")))
/* Save the global world-time pair into the record. */
void cCoreSave_saveWorldTime(cCoreSave *self) {
    int d0, d1;
    d0 = D_0061A990[0];
    self->data->worldTime = d0;
    d1 = D_0061A990[1];
    self->data->worldTimeB = d1;
}

__attribute__((section(".text.cCoreSave_addCounter08")))
/* Count up counter08, capped at 999. */
void cCoreSave_addCounter08(cCoreSave *self) {
    cCoreSaveData *data = self->data;
    unsigned int c = data->counter08 + 1;
    data->counter08 = c;
    if (c >= 0x3E8) {
        self->data->counter08 = 0x3E7;
    }
}

__attribute__((section(".text.cCoreSave_saveStageIds")))
/* Save the current stage ids into the record. */
void cCoreSave_saveStageIds(cCoreSave *self) {
    self->data->saveStageA = D_007474A0[0x2D8];
    self->data->saveStageB = D_007474A0[0x2DB];
}

__attribute__((section(".text.cCoreSave_loadWorldActive")))
/* Copy the record's world-active flag to the global. */
void cCoreSave_loadWorldActive(cCoreSave *self) {
    if (self->data->worldActive) {
        D_005E85F8 = 1;
    } else {
        D_005E85F8 = 0;
    }
}

struct S001FA690 { char pad[0x10]; unsigned short f10; };
struct W001FA690 { struct S001FA690 *p; };
__attribute__((section(".text.cCoreSave_getGold")))
/* gold, forced to its maximum by the 0x2000000 cheat. */
int cCoreSave_getGold(cCoreSave *self) {
    cCoreSaveData *data = self->data;
    if (data == 0) {
        return 0;
    }
    if (D_00747A34 & 0x2000000) {
        data->gold = CORESAVE_GOLD_MAX;
    }
    return self->data->gold;
}

__attribute__((section(".text.cCoreSave_isGoldFull")))
/* 1 when gold sits at its maximum. */
int cCoreSave_isGoldFull(cCoreSave *self) {
    cCoreSaveData *data = self->data;
    if (data == 0) {
        return 0;
    }
    return data->gold >= CORESAVE_GOLD_MAX;
}

__attribute__((section(".text.cCoreSave_getState154")))
/* state154, forced to its maximum by the 0x8000000 cheat. */
int cCoreSave_getState154(cCoreSave *self) {
    cCoreSaveData *data = self->data;
    if (data == 0) {
        return 0;
    }
    if (D_00747A38 & 0x8000000) {
        data->state154 = 0xD;
    }
    return self->data->state154;
}

__attribute__((section(".text.cCoreSave_getState155")))
/* state155, forced to its maximum by the 0x8000000 cheat. */
int cCoreSave_getState155(cCoreSave *self) {
    cCoreSaveData *data = self->data;
    if (data == 0) {
        return 0;
    }
    if (D_00747A38 & 0x8000000) {
        data->state155 = 5;
    }
    return self->data->state155;
}

__attribute__((section(".text.cCoreSave_initItem")))
/* Free every remembered-object slot and restart the serial count. */
void cCoreSave_initItem(cCoreSave *self)
{
    unsigned int i;
    unsigned int val;
    if (self->data == 0) {
        return;
    }
    i = 0;
    val = 0xFFFF;
    for (; i < CORESAVE_ITEM_NUM; i++) {
        /* Raw form kept: the typed index builds the address in the other operand order. */
        *(unsigned short *)((char *)((i << 4) + (unsigned int)self->data) + CORESAVE_OFFSET(item[0].stage)) = val;
    }
    self->data->itemNum = 1;
}

__attribute__((section(".text.cCoreSave_getStat8A")))
/* stat8A, forced to its maximum by the 0x1000000 cheat. */
unsigned char cCoreSave_getStat8A(cCoreSave *self) {
    cCoreSaveData *data;
    cCoreSaveData *q;
    data = self->data;
    if (data == 0) {
        return 0;
    }
    if (D_00747A34 & 0x01000000) {
        data->stat8A = 6;
    }
    q = self->data;
    return q->stat8A;
}

__attribute__((section(".text.cCoreSave_clearKillEmNum")))
/* Zero the per-level kill counts of this stage. */
void cCoreSave_clearKillEmNum(cCoreSave *self) {
    unsigned int i;
    if (self->data != 0) {
        i = 0;
        do {
            self->data->killEmNum[i] = 0;
            i++;
        } while (i < CORESAVE_LEVEL_NUM);
    }
}

__attribute__((section(".text.cCoreSave_addContinueNum")))
/* Count one more continue, this stage and in total. */
void cCoreSave_addContinueNum(cCoreSave *self) {
    cCoreSaveData *data;
    cCoreSaveData *q;
    data = self->data;
    if (data) {
        data->continueNum += 1;
        q = self->data;
        q->allContinueNum += 1;
    }
}

__attribute__((section(".text.cCoreSave_ckClearStage")))
/* 1 if stage `no` (0..8) is cleared; the 0x80000 cheat clears them all. */
int cCoreSave_ckClearStage(cCoreSave *self, unsigned int no) {
    cCoreSaveData *data;
    int bit;
    data = self->data;
    no = no & 0xFFFF;
    if (data == 0) {
        return 0;
    }
    if (no >= 9) {
        return 0;
    }
    if ((D_00747A3C & 0x80000) != 0) {
        return 1;
    }
    bit = data->clearStageMask & (1 << no);
    if (bit == 0) {
        return 0;
    }
    return 1;
}

__attribute__((section(".text.cCoreSave_setReelSlot")))
/* Put god reel `no` in reel slot `slot` (0..9). */
void cCoreSave_setReelSlot(cCoreSave *self, unsigned char slot, unsigned int no) {
    cCoreSaveData *data;
    unsigned int idx;
    data = self->data;
    if (data == 0) return;
    idx = slot;
    if (idx < 0xA) {
        data->reelSlot[idx] = no;
    }
}

__attribute__((section(".text.cCoreSave_ckReelSlot")))
/* 1 if god reel `no` sits in any reel slot. */
int cCoreSave_ckReelSlot(cCoreSave *self, unsigned int no) {
    unsigned char *slots;
    unsigned int i;
    if (self->data == 0) {
        return 0;
    }
    slots = self->data->reelSlot;
    for (i = 0; i < 0xA; i = i + 1) {
        if (slots[i] == no) {
            return 1;
        }
    }
    return 0;
}

__attribute__((section(".text.cCoreSave_ckEventFlag")))
/* 1 if event flag `no` is set. */
int cCoreSave_ckEventFlag(cCoreSave *self, int no) {
    cCoreSaveData *data;
    int bit;
    data = self->data;
    if (data == 0) {
        return 0;
    }
    bit = data->eventFlags & (1 << no);
    if (bit == 0) {
        return 0;
    }
    return 1;
}

__attribute__((section(".text.IsTargetVisibleOrForced_1004C8")))
int IsTargetVisibleOrForced_1004C8(int a0) {
    if (D_00747A80 & 0x200000) {
        return 1;
    }
    return IsTargetVisible_14B470(a0) != 0;
}

__attribute__((section(".text.SetField5CAndForward_12D178")))
void SetField5CAndForward_12D178(int *a0, int a1) {
    *(int *)((char *)a0 + 0x5C) = (int)D_0041D5A8;
    if (a1 & 1) {
        __builtin_delete(a0);
    }
}

__attribute__((section(".text.SetField5CAndForwardAlt_12DC88")))
void SetField5CAndForwardAlt_12DC88(int *a0, int a1) {
    *(int *)((char *)a0 + 0x5C) = (int)D_0041D5A8;
    if (a1 & 1) {
        __builtin_delete(a0);
    }
}

__attribute__((section(".text.SetField198AndForward_12E640")))
void SetField198AndForward_12E640(int *a0, int a1) {
    *(int *)((char *)a0 + 0x198) = (int)D_0041D540;
    if (a1 & 1) {
        __builtin_delete(a0);
    }
}

__attribute__((section(".text.Forward30F348_31CFE0")))
void Forward30F348_31CFE0(void) {
    func_0030F348();
}

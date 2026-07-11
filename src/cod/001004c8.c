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

__attribute__((section(".text.ClearField5B4IfFlagUnset_1B76B0")))
int ClearField5B4IfFlagUnset_1B76B0(int a0) {
    int v0 = 1;
    if (D_00747A78 & 0x20000000) {
        v0 = 0;
        return v0;
    }
    *(int*)((char*)a0 + 0x5B4) = 0;
    return v0;
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

__attribute__((section(".text.Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08")))
int Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08(void *a0) {
    if (*(unsigned char *)((char *)a0 + 0x2F4) != 0) return 0;
    return (*(unsigned char *)((char *)a0 + 0x2F5) ^ 4) == 0;
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

__attribute__((section(".text.CopyGlobalPairToTarget_1F9C30")))
void CopyGlobalPairToTarget_1F9C30(int *a0) {
    int d0, d1;
    d0 = D_0061A990[0];
    *(int *)(*(int *)a0) = d0;
    d1 = D_0061A990[1];
    *(int *)(*(int *)a0 + 4) = d1;
}

__attribute__((section(".text.UpdateCounterClamped_1F9C58")))
void UpdateCounterClamped_1F9C58(int **a0) {
    int *v1 = a0[0];
    unsigned int c = v1[2] + 1;
    v1[2] = c;
    if (c >= 0x3E8) {
        a0[0][2] = 0x3E7;
    }
}

__attribute__((section(".text.SetFieldShorts0C0E_1F9C88")))
void SetFieldShorts0C0E_1F9C88(int **a0) {
    *(short *)((char *)*a0 + 0xC) = D_007474A0[0x2D8];
    *(short *)((char *)*a0 + 0xE) = D_007474A0[0x2DB];
}

__attribute__((section(".text.UpdateActiveFlag_1F9E00")))
void UpdateActiveFlag_1F9E00(int **a0) {
    if (a0[0][0x174 / 4]) {
        D_005E85F8 = 1;
    } else {
        D_005E85F8 = 0;
    }
}

struct S001FA690 { char pad[0x10]; unsigned short f10; };
struct W001FA690 { struct S001FA690 *p; };
struct S001FA710 { char pad[0x20]; int f20; };
__attribute__((section(".text.GetTimerValue_1FA710")))
int GetTimerValue_1FA710(struct S001FA710 **a0) {
    struct S001FA710 *p = *a0;
    if (p == 0) {
        return 0;
    }
    if (D_00747A34 & 0x2000000) {
        p->f20 = 0xF423F;
    }
    return (*a0)->f20;
}

struct S001FA8E0 { char pad[0x20]; int f20; };
__attribute__((section(".text.IsTimerExpired_1FA8E0")))
int IsTimerExpired_1FA8E0(struct S001FA8E0 **a0) {
    struct S001FA8E0 *p = *a0;
    if (p == 0) {
        return 0;
    }
    return 0xF423E < p->f20;
}

__attribute__((section(".text.GetField154Byte_1FAE60")))
int GetField154Byte_1FAE60(int **a0) {
    int *p = *a0;
    if (p == 0) {
        return 0;
    }
    if (D_00747A38 & 0x8000000) {
        *((unsigned char *)p + 0x154) = 0xD;
    }
    return *((unsigned char *)*a0 + 0x154);
}

__attribute__((section(".text.GetField155Byte_1FAEA0")))
int GetField155Byte_1FAEA0(int **a0) {
    int *p = *a0;
    if (p == 0) {
        return 0;
    }
    if (D_00747A38 & 0x8000000) {
        *((unsigned char *)p + 0x155) = 5;
    }
    return *((unsigned char *)*a0 + 0x155);
}

__attribute__((section(".text.InitSlotTable_1FAFA8")))
void InitSlotTable_1FAFA8(int **a0)
{
    unsigned int i;
    unsigned int val;
    if (*a0 == 0) {
        return;
    }
    i = 0;
    val = 0xFFFF;
    for (; i < 0x80; i++) {
        *(unsigned short *)((char *)((i << 4) + (unsigned int)*a0) + 0x28A) = val;
    }
    *(unsigned short *)((char *)*a0 + 0x288) = 1;
}

__attribute__((section(".text.GetField8AByte_1FBD60")))
unsigned char GetField8AByte_1FBD60(unsigned char **a0) {
    unsigned char *p;
    unsigned char *q;
    p = *a0;
    if (p == 0) {
        return 0;
    }
    if (D_00747A34 & 0x01000000) {
        p[0x8A] = 6;
    }
    q = *a0;
    return q[0x8A];
}

__attribute__((section(".text.ClearField46Array_1FBDD0")))
void ClearField46Array_1FBDD0(int **a0) {
    unsigned int i;
    if (*a0 != 0) {
        i = 0;
        do {
            short *p = (short *)((char *)*a0 + i * 2);
            i++;
            p[0x46] = 0;
        } while (i < 5);
    }
}

__attribute__((section(".text.AddCounterFields12AndBB8_1FBF18")))
void AddCounterFields12AndBB8_1FBF18(int **a0) {
    int *p;
    int *q;
    p = *a0;
    if (p) {
        *(unsigned short *)((char *)p + 0x12) += 1;
        q = *a0;
        *(unsigned short *)((char *)q + 0xBB8) += 1;
    }
}

__attribute__((section(".text.IsSet_Field_A4_1FBFD0")))
int IsSet_Field_A4_1FBFD0(int **a0, unsigned int a1) {
    int *p;
    int v1;
    p = a0[0];
    a1 = a1 & 0xFFFF;
    if (p == 0) {
        return 0;
    }
    if (a1 >= 9) {
        return 0;
    }
    if ((D_00747A3C & 0x80000) != 0) {
        return 1;
    }
    v1 = *(int *)((char *)p + 0xA4) & (1 << a1);
    if (v1 == 0) {
        return 0;
    }
    return 1;
}

__attribute__((section(".text.SetSlotField98_1FC170")))
void SetSlotField98_1FC170(unsigned char **a0, unsigned int a1, unsigned int a2) {
    unsigned char *p;
    unsigned int idx;
    p = *a0;
    if (p == 0) return;
    idx = a1 & 0xFF;
    if (idx < 0xA) {
        *(unsigned char *)(p + idx + 0x98) = a2;
    }
}

__attribute__((section(".text.IsValueInField_98_1FC1C8")))
int IsValueInField_98_1FC1C8(unsigned char **a0, unsigned int a1) {
    unsigned char *base;
    unsigned int i;
    if (*a0 == 0) {
        return 0;
    }
    base = *a0 + 0x98;
    for (i = 0; i < 0xA; i = i + 1) {
        if (base[i] == a1) {
            return 1;
        }
    }
    return 0;
}

__attribute__((section(".text.IsFlagBitSet_1FC360")))
int IsFlagBitSet_1FC360(int **a0, int a1) {
    int *p;
    int v1;
    p = a0[0];
    if (p == 0) {
        return 0;
    }
    v1 = *(int *)((char *)p + 0xB90) & (1 << a1);
    if (v1 == 0) {
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
        ForwardFieldNeg20_002A9680_30F5A0(a0);
    }
}

__attribute__((section(".text.SetField5CAndForwardAlt_12DC88")))
void SetField5CAndForwardAlt_12DC88(int *a0, int a1) {
    *(int *)((char *)a0 + 0x5C) = (int)D_0041D5A8;
    if (a1 & 1) {
        ForwardFieldNeg20_002A9680_30F5A0(a0);
    }
}

__attribute__((section(".text.SetField198AndForward_12E640")))
void SetField198AndForward_12E640(int *a0, int a1) {
    *(int *)((char *)a0 + 0x198) = (int)D_0041D540;
    if (a1 & 1) {
        ForwardFieldNeg20_002A9680_30F5A0(a0);
    }
}

__attribute__((section(".text.Forward30F348_31CFE0")))
void Forward30F348_31CFE0(void) {
    func_0030F348();
}

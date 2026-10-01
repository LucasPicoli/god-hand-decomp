#include "godhand/cCoreSave.h"
extern char D_003C532F;

__attribute__((section(".text.ClearWordPair_201AD0")))
void ClearWordPair_201AD0(char *a0)
{
    a0[0] = 0;
    a0[1] = 0;
}

__attribute__((section(".text.NoOp_208260")))
void NoOp_208260(void)
{
}

__attribute__((section(".text.InitStateBytes_2478B8")))
void InitStateBytes_2478B8(unsigned char *a0) {
    int v = 0x99;
    a0[0x2F4] = 0;
    a0[0x2F5] = v;
    a0[0x2F6] = 2;
    a0[0x2F7] = 0;
}

__attribute__((section(".text.StoreMotionParams_2609E0")))
void StoreMotionParams_2609E0(char *a0, int a1, int a2, int a3, int t0, short t1) {
    *(int*)((char*)a0+0x1874) = a1;
    *(int*)((char*)a0+0x1870) = a2;
    *(int*)((char*)a0+0x1878) = a3;
    *(int*)((char*)a0+0x187C) = t0;
    *(short*)((char*)a0+0x1880) = t1;
}

__attribute__((section(".text.Set_Fields_1884_1894_2609F8")))
void Set_Fields_1884_1894_2609F8(char *a0, int a1, int a2, int a3, int t0, short t1) {
    *(int*)((char*)a0+0x1888) = a1;
    *(int*)((char*)a0+0x1884) = a2;
    *(int*)((char*)a0+0x188C) = a3;
    *(int*)((char*)a0+0x1890) = t0;
    *(short*)((char*)a0+0x1894) = t1;
}

__attribute__((section(".text.ClearFields_1614D0")))
void ClearFields_1614D0(char *a0) {
    *(char *)(a0 + 0x58) = 0;
    *(char *)(a0 + 0x59) = 0;
    *(int *)(a0 + 0x50) = 0;
    *(char *)(a0 + 0x64) = 0;
    *(char *)(a0 + 0x5A) = 0;
    *(char *)(a0 + 0x5B) = 0;
    *(char *)(a0 + 0x5C) = 0;
    *(int *)(a0 + 0x60) = -1;
    *(char *)(a0 + 0x5D) = 0;
}

__attribute__((section(".text.ClearStateAndFlag_1C7E08")))
int ClearStateAndFlag_1C7E08(void *a0) {
    int v1 = *(int *)((char *)a0 + 0x5B8) & ~0x40;
    *(char *)((char *)a0 + 0x2F4) = 0;
    *(char *)((char *)a0 + 0x2F5) = 0;
    *(char *)((char *)a0 + 0x2F6) = 0;
    *(char *)((char *)a0 + 0x2F7) = 0;
    *(int *)((char *)a0 + 0x5B8) = v1;
    return 1;
}

__attribute__((section(".text.ClearObjRef_1EE9A0")))
void ClearObjRef_1EE9A0(int *a0)
{
    int v1 = *a0;
    if (v1 != 0) {
        *(char *)((char *)v1 + 0x2F4) = 2;
        *a0 = 0;
    }
    *(char *)((char *)a0 + 0x4) = 0;
    *(int *)((char *)a0 + 0x2C) = 0;
    *(int *)((char *)a0 + 0x30) = 0;
}

__attribute__((section(".text.cCoreSave_setState154")))
/* Set state154, capped at 0xD. */
void cCoreSave_setState154(cCoreSave *self, unsigned char v) {
    if (self->data) {
        self->data->state154 = v;
        if (self->data->state154 >= 0xE) {
            self->data->state154 = 0xD;
        }
    }
}

__attribute__((section(".text.cCoreSave_addState154")))
/* Add to state154, capped at 0xD. */
void cCoreSave_addState154(cCoreSave *self, unsigned char n) {
    if (self->data) {
        self->data->state154 = n + self->data->state154;
        if (self->data->state154 >= 0xE) {
            self->data->state154 = 0xD;
        }
    }
}

__attribute__((section(".text.cCoreSave_setState155")))
/* Set state155, capped at 5. */
void cCoreSave_setState155(cCoreSave *self, unsigned char v) {
    if (self->data) {
        self->data->state155 = v;
        if (self->data->state155 >= 0x6) {
            self->data->state155 = 0x5;
        }
    }
}

__attribute__((section(".text.cCoreSave_addState155")))
/* Add to state155, capped at 5. */
void cCoreSave_addState155(cCoreSave *self, unsigned char n) {
    if (self->data) {
        self->data->state155 = n + self->data->state155;
        if (self->data->state155 >= 0x6) {
            self->data->state155 = 0x5;
        }
    }
}

__attribute__((section(".text.cCoreSave_addStat8A")))
/* Add to stat8A, capped at 6. */
void cCoreSave_addStat8A(cCoreSave *self, int n) {
    cCoreSaveData *data;
    cCoreSaveData *q;
    int s;
    n = n & 0xFF;
    data = self->data;
    if (data != 0) {
        s = n + data->stat8A;
        data->stat8A = s;
        q = self->data;
        if (q->stat8A >= 7) {
            q->stat8A = 6;
        }
    }
}

__attribute__((section(".text.Forward322BD8_322AD0")))
int Forward322BD8_322AD0(int a0, int a1, int a2, int a3) {
    return func_00322BD8(a0, a1, a2, a3, ((unsigned int)&D_003C532F) & -0x40, 0x800);
}

__attribute__((section(".text.Forward322C18_322B60")))
int Forward322C18_322B60(int a0, int a1, int a2, int a3) {
    return func_00322C18(a0, a1, a2, a3, ((unsigned int)&D_003C532F) & -0x40, 0x800);
}

__attribute__((section(".text.Forward323050_323038")))
void Forward323050_323038(void) { func_00323050(); }

__attribute__((section(".text.Forward33E6A8_324880")))
void Forward33E6A8_324880(void) { NoOp_33E6A8(); }

__attribute__((section(".text.Forward33E6B0_324898")))
void Forward33E6B0_324898(void) { NoOp_33E6B0(); }

__attribute__((section(".text.Forward33D4D8_33D578")))
void Forward33D4D8_33D578(short *a0, int a1, int a2, int a3) {
    func_0033D4D8(a0, a0 + a1, a3);
}

__attribute__((section(".text.Forward33B658_33E678")))
int Forward33B658_33E678(int a0, int a1, int a2, int a3) {
    return Forward33B568_33B658(a0, a1, a2, a3);
}

__attribute__((section(".text.Forward33B670_33E690")))
int Forward33B670_33E690(int a0, int a1, int a2, int a3) {
    return Forward33B5C8_33B670(a0, a1, a2, a3);
}

__attribute__((section(".text.Forward3B0640_33F3D0")))
int Forward3B0640_33F3D0(int a0, int a1, int a2, int a3) {
    return func_003B0640(a0, a0 + a1 - 1, a2, a3);
}

__attribute__((section(".text.Forward33B658_3403C8")))
int Forward33B658_3403C8(int a0, int a1, int a2, int a3) {
    return Forward33B568_33B658(a0, a1, a2, a3);
}

__attribute__((section(".text.Forward33B670_3403E0")))
int Forward33B670_3403E0(int a0, int a1, int a2, int a3) {
    return Forward33B5C8_33B670(a0, a1, a2, a3);
}

__attribute__((section(".text.Forward3A52F0_3406B0")))
int Forward3A52F0_3406B0(int a0, int a1, int a2, int a3) {
    return func_003A52F0(a0, 0, 0x2C, a3);
}

__attribute__((section(".text.Forward33B790_340AE8")))
int Forward33B790_340AE8(int a0, int a1, int a2, int a3) {
    return func_0033B790(a0, a1, a2, a3);
}

/* writes both the StoreMotionParams_2609E0 and Set_Fields_1884_1894_2609F8 field blocks. */
__attribute__((section(".text.StoreMotionParamsBoth_2609A8")))
void StoreMotionParamsBoth_2609A8(char *a0, int a1, int a2, int a3, int t0, short t1) {
    *(int*)((char*)a0+0x1874) = a1;
    *(int*)((char*)a0+0x1870) = a2;
    *(int*)((char*)a0+0x1878) = a3;
    *(int*)((char*)a0+0x187C) = t0;
    *(short*)((char*)a0+0x1880) = t1;
    *(int*)((char*)a0+0x1888) = a1;
    *(int*)((char*)a0+0x1884) = a2;
    *(int*)((char*)a0+0x188C) = a3;
    *(int*)((char*)a0+0x1890) = t0;
    *(short*)((char*)a0+0x1894) = t1;
}

/* sn-2.95.3-136 matched TU. */
#include "godhand/cHeatSys.h"

/* Level 1 once cur reaches threshold, else 0. Stores and returns lv. */
__attribute__((section(".text.cHeatSys_GetHeatLv")))
int cHeatSys_GetHeatLv(cHeatSys *self) {
    float cur = self->cur;
    float threshold = self->threshold;
    if (cur < threshold) {
        self->lv = 0;
    } else {
        self->lv = 1;
    }
    return self->lv;
}

__attribute__((section(".text.func_0028ED78")))
void func_0028ED78(int a0) {
    if (*(int*)((char*)a0 + 0x5B4) > 0) {
        float diff = *(float*)((char*)a0 + 0x5B8) - *(float*)((char*)a0 + 0x5A8);
        *(float*)((char*)a0 + 0x5B8) = diff;
        if (diff <= 0.0f) {
            *(int*)((char*)a0 + 0x5B4) = *(int*)((char*)a0 + 0x5B4) - 0x1E;
            *(float*)((char*)a0 + 0x5B8) = 90.0f;
        }
        if (*(int*)((char*)a0 + 0x5B4) < 0) {
            *(int*)((char*)a0 + 0x5B4) = 0;
        }
    }
}

__attribute__((section(".text.func_003740C8")))
void func_003740C8(int a0, float f12, float f13) {
    if (*(int*)((char*)a0 + 0x0) != 0) {
        if (f13 == 0.0f) {
            float x = *(float*)((char*)a0 + 0x18);
            if (f12 <= x) {
                *(float*)((char*)a0 + 0x1C) = *(float*)((char*)a0 + 0x28);
            } else {
                *(float*)((char*)a0 + 0x1C) = *(float*)((char*)a0 + 0x24);
            }
        } else {
            *(float*)((char*)a0 + 0x1C) = f13;
        }
        *(float*)((char*)a0 + 0x18) = f12;
    }
}

typedef void (*fn5E8)(void *);
__attribute__((section(".text.func_002BA5E8")))
void func_002BA5E8(char *a0, float f12) {
    char *o;
    *(float*)(a0 + 0x114) = f12;
    if (*(float*)(a0 + 0x110) < f12 + f12) {
        *(float*)(a0 + 0x114) = *(float*)(a0 + 0x110) * 0.5f;
    }
    o = *(char**)(a0 + 0x100);
    (*(fn5E8*)(o + 0x54))(a0 + *(short*)(o + 0x50));
}

typedef void (*fn650)(void *);
__attribute__((section(".text.func_002BA650")))
void func_002BA650(char *a0, float f12) {
    char *o;
    *(float*)(a0 + 0x110) = f12;
    if (f12 < *(float*)(a0 + 0x114) + *(float*)(a0 + 0x114)) {
        *(float*)(a0 + 0x114) = f12 * 0.5f;
    }
    o = *(char**)(a0 + 0x100);
    (*(fn650*)(o + 0x54))(a0 + *(short*)(o + 0x50));
}

__attribute__((section(".text.func_00278570")))
void func_00278570(char *a0) {
    char *p;
    unsigned long flags;
    if (*(int*)(a0 + 0x564) == 0x232) return;
    if (*(short*)(a0 + 0x54A) <= 0) return;
    p = *(char**)(a0 + 0x670);
    if (p == 0) return;
    flags = *(unsigned int*)(p + 0x60);
    if ((flags & 1) == 0) return;
    if (0.0f < *(float*)(a0 + 0x54C)) return;
    *(char*)(a0 + 0x2F7) = 0;
    *(char*)(a0 + 0x2F4) = 0;
    *(char*)(a0 + 0x2F6) = 0;
    *(char*)(a0 + 0x2F5) = 1;
}

__attribute__((section(".text.func_00178980")))
void func_00178980(char *a0) {
    *(float*)(a0 + 0x600) += 0.0080000004f;
    if (2.0f <= *(float*)(a0 + 0x600)) *(float*)(a0 + 0x600) = 2.0f;
    *(float*)(a0 + 0x100) += *(float*)(a0 + 0x600) * *(float*)(a0 + 0x600) * 0.017453292f;
    if (1.5707964f <= *(float*)(a0 + 0x100)) *(float*)(a0 + 0x100) = 1.5707964f;
}

__attribute__((section(".text.func_001E9078")))
float func_001E9078(int *a0) {
    int p = a0[0];
    float f;
    if (p == 0) {
        return 0.0f;
    }
    f = *(float *)(p + 0x100) * 57.2957763671875f;
    if (f < 0.0f) {
        f = f + 360.0f;
    }
    f = f + 0.009999999776482582f;
    if (360.0f <= f) {
        f = f - 360.0f;
    }
    return f;
}

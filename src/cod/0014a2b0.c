#include "godhand/cModel.h"

/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern void cSndBgmNode_FadeOut(void *a0, float f12);
extern void MtxInitCoord(float *mtx, cVec *pos, cVec *rot, cVec *scale, int order);
extern void CustomIDWork_SetDisp(void *a0, int a1);
extern void InitFields_1B6E90(void *a0);
extern int D_00429C80;

__attribute__((section(".text.cSnd_DieDemoStart")))
void cSnd_DieDemoStart(void *a0)
{
    char *p = (char *)a0;
    char *s0 = *(char **)(p + 0x18);
    while (s0 != 0) {
        *(unsigned int *)(s0 + 0x98) = *(unsigned int *)(s0 + 0x98) | 0x10000;
        cSndBgmNode_FadeOut(s0, 180.0f);
        s0 = *(char **)(s0 + 0x88);
    }
    *(unsigned int *)(p + 0xB0) = *(unsigned int *)(p + 0xB0) | 0x100000;
    *(unsigned int *)(p + 0xAC) = *(unsigned int *)(p + 0xAC) | 0x100000;
}

/* Rebuild the model's matrix from its position, rotation and scale, and keep
 * a copy of the scale the matrix was built with. Skipped when the owner builds
 * the matrix itself. */
__attribute__((section(".text.cModel_calcNullPart")))
void cModel_calcNullPart(cModel *self)
{
    cVec *scale;
    float *dst;

    if ((self->objFlags & CMODEL_F_NO_CALC) != 0)
        return;

    scale = &self->scale;
    MtxInitCoord(self->mtx, self->pos, &self->rot, scale, self->rotOrder);

    dst = &self->scaleCalc.x;
    if (dst != &scale->x) {
        dst[0] = scale->x;
        dst[1] = scale->y;
        dst[2] = scale->z;
    }
}

__attribute__((section(".text.CheckSlotsShort2FEAndSetByte1864_262A10")))
int CheckSlotsShort2FEAndSetByte1864_262A10(char *a0)
{
    char *t;

    t = *(char **)(*(char **)(a0 + 0x670) + 0x34);
    if (t != 0 && *(unsigned short *)(t + 0x2FE) == 0x100) {
        *(char *)(a0 + 0x1864) = 1;
        return 1;
    }
    t = *(char **)(*(char **)(a0 + 0x678) + 0x34);
    if (t != 0 && *(unsigned short *)(t + 0x2FE) == 0x100) {
        *(char *)(a0 + 0x1864) = 1;
        return 1;
    }
    t = *(char **)(*(char **)(a0 + 0x680) + 0x34);
    if (t != 0 && *(unsigned short *)(t + 0x2FE) == 0x100) {
        *(char *)(a0 + 0x1864) = 1;
        return 1;
    }
    t = *(char **)(*(char **)(a0 + 0x688) + 0x34);
    if (t != 0 && *(unsigned short *)(t + 0x2FE) == 0x100) {
        *(char *)(a0 + 0x1864) = 1;
        return 1;
    }
    return 0;
}

__attribute__((section(".text.SetFlagOnEntries7C_1D51B8")))
void SetFlagOnEntries7C_1D51B8(char *base, int idx, int flag) {
    int i;
    if (flag != 0) {
        if (idx == 0x2D) {
            for (i = 0; i < 0x2D; i++) {
                if (i != 0) {
                    CustomIDWork_SetDisp(base + 0x60 + i * 0x7C, 1);
                }
            }
        } else if (idx != 0) {
            CustomIDWork_SetDisp(base + (idx * 0x7C + 0x60), 1);
        }
    } else {
        if (idx == 0x2D) {
            for (i = 0; i < 0x2D; i++) {
                if (i != 0) {
                    CustomIDWork_SetDisp(base + 0x60 + i * 0x7C, 0);
                }
            }
        } else if (idx != 0) {
            CustomIDWork_SetDisp(base + (idx * 0x7C + 0x60), 0);
        }
    }
}

__attribute__((section(".text.InitVtable214_429C80_1C27E8")))
void *InitVtable214_429C80_1C27E8(void *a0) {
    InitFields_1B6E90(a0);
    *(int *)((char*)a0 + 0x214) = (int)&D_00429C80;
    return a0;
}

/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern void cSndBgmNode_FadeOut(void *a0, float f12);
extern void MtxInitCoord(void *a0, int a1, void *a2, void *a3, int t0);
extern void CustomIDWork_SetDisp(void *a0, int a1);
extern void InitFields_1B6E90(void *a0);
extern int D_00429C80;

__attribute__((section(".text.OrChildField98AndSelfFieldB0AC_2CA718")))
void OrChildField98AndSelfFieldB0AC_2CA718(void *a0)
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

__attribute__((section(".text.CopyVec3From110To120_14A2B0")))
void CopyVec3From110To120_14A2B0(void *a0)
{
    char *s0 = (char *)a0;
    char *s1;
    float *dst;

    if ((*(int *)(s0 + 0x250) & 0x800) != 0)
        return;

    s1 = s0 + 0x110;
    MtxInitCoord(s0 + 0x80, *(int *)(s0 + 0xF0), s0 + 0x100, s1,
                  *(unsigned char *)(s0 + 0x140));

    dst = (float *)(s0 + 0x120);
    if ((char *)dst != s1) {
        dst[0] = *(float *)(s1 + 0x0);
        dst[1] = *(float *)(s1 + 0x4);
        dst[2] = *(float *)(s1 + 0x8);
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

/* cygnus-2.96: the SFX library stream context (sfxlib.h): stream and codec checks, the step counter
 * and the field setters. */
#include "include_asm.h"
#include "godhand/sfxlib.h"
#include "godhand/globals.h"

extern void *getElemInfPtr(int a0, int a1);
typedef struct Elem {
    char pad0[0x20];
    unsigned char codec;
} Elem;
extern int func_0035E9E8(unsigned int id);
extern int isEnableVidFtr(int a0, Elem *a1);

__attribute__((section(".text.func_0035E868")))
int func_0035E868(int a0, int a1, int *a2)
{
    void *s1;
    int s0;
    s0 = a1 & 0xFF;
    *a2 = -1;
    s1 = getElemInfPtr(a0, s0);
    if (s1 == 0) {
        return 0;
    }
    if (isEnableVidFtr(s0, s1) == 0) {
        return 0;
    }
    if (*(int *)((char *)a0 + 0xC) < 0xD2) {
        return 0;
    }
    *a2 = *(unsigned char *)((char *)s1 + 0x27);
    return 1;
}

/* func_0035E8F8 stays in the monolith: rodata D_00459C50 refers to its jump-table labels. */

__attribute__((section(".text.isEnableAudFtr")))
int isEnableAudFtr(int id, Elem *e)
{
    int nz;
    int lt;

    if (func_0035E9E8(id) != 0xC0) return 0;
    nz = (e->codec != 0);
    lt = (e->codec < 2);
    return lt && nz;
}

__attribute__((section(".text.isEnableVidFtr")))
int isEnableVidFtr(int id, Elem *e)
{
    int nz;
    int lt;

    if (func_0035E9E8(id) != 0xE0) return 0;
    nz = (e->codec != 0);
    lt = (e->codec < 2);
    return lt && nz;
}

__attribute__((section(".text.func_0035E9E8")))
int func_0035E9E8(unsigned int id)
{
    if (id - 0xC0 < 0x20) return 0xC0;
    if (id - 0xE0 < 0x10) return 0xE0;
    if (id == 0xBD) goto bd;
    if (id != 0xBF) return 0;
bd:
    return 0xBD;
}

__attribute__((section(".text.Obj35E8_StepCounter_EA60")))
void Obj35E8_StepCounter_EA60(char *a0)
{
    int v1 = *(int *)(a0 + 0xC);
    int v0 = *(int *)(a0 + 0x10);
    int a1 = *(int *)(a0 + 0x4);
    *(int *)(a0 + 0x10) = -v0;
    *(int *)(a0 + 0x4) = a1 + v0 * (v1 - 1);
}

/* func_0035EBB0 stays in the monolith: rodata D_00459CE0 refers to its jump-table labels. */

__attribute__((section(".text.Obj35E8_SetField_68")))
void Obj35E8_SetField_68(char *a0, int a1)
{
    *(int *)(a0 + 0x68) = a1;
}

__attribute__((section(".text.Obj35E8_SetField_6C")))
void Obj35E8_SetField_6C(char *a0, int a1)
{
    *(int *)(a0 + 0x6C) = a1;
}

__attribute__((section(".text.Obj35E8_SetIndirect_30_18")))
void Obj35E8_SetIndirect_30_18(char *a0, int a1)
{
    *(int *)(*(int *)(a0 + 0x30) + 0x18) = a1;
}

__attribute__((section(".text.Obj35E8_SetIndirect_30_20")))
void Obj35E8_SetIndirect_30_20(char *a0, int a1)
{
    *(int *)(*(int *)(a0 + 0x30) + 0x20) = a1;
}

__attribute__((section(".text.Obj35E8_SetIndirect_30_1C")))
void Obj35E8_SetIndirect_30_1C(char *a0, int a1)
{
    *(int *)(*(int *)(a0 + 0x30) + 0x1C) = a1;
}

__attribute__((section(".text.Obj35E8_SetField_70")))
void Obj35E8_SetField_70(char *a0, int a1)
{
    *(int *)(a0 + 0x70) = a1;
}

extern void func_0035FD98(void *a, int b, int c);
extern int func_0035F830(void *a, void *b);
extern void func_0035F1D0(void *a, void *b, int c, int d);
extern void func_0035F3C8(void *a, void *b, int c);
extern void func_003603D8(int a, int b, void *c);
extern void func_0036CBC0(int a, int b, void *c);
extern void func_0036CC08(int a, int b, void *c);
extern void func_0036CC40(int a, int b, void *c);

__attribute__((section(".text.func_0035EA30")))
void func_0035EA30(void *self, SfxCtxArg *b, int c, int d, int e, int f)
{
    b->unk44 = e;
    b->unk48 = f;
    func_0035FD98(b, c, d);
}

extern int func_0035EB60(SfxTypeView *a, SfxModeView *b);
INCLUDE_ASM("nonmatching", func_0035EB60);

__attribute__((section(".text.func_0035EB98")))
void func_0035EB98(void *a, void *b, int mode)
{
    func_0035EBB0(a, b, mode);
}

__attribute__((section(".text.func_0035EDA8")))
void func_0035EDA8(SfxCtx *a, SfxCtxArg *b)
{
    func_003603D8(a->unk24, b->unk4C, a->unk38);
}

__attribute__((section(".text.func_0035EDC8")))
void func_0035EDC8(SfxCtx *a)
{
    func_0035EDE0(a->unk38);
}

__attribute__((section(".text.func_0035EE98")))
void func_0035EE98(SfxCtx *a, SfxCtxArg *b)
{
    func_0036CBC0(a->unk30, b->unk4C, a->unk38);
}

__attribute__((section(".text.func_0035EEB8")))
void func_0035EEB8(SfxCtx *a, SfxCtxArg *b)
{
    func_0036CC08(a->unk30, b->unk4C, a->unk38);
}

__attribute__((section(".text.func_0035EED8")))
void func_0035EED8(SfxCtx *a, SfxCtxArg *b)
{
    func_0036CC40(a->unk30, b->unk4C, a->unk38);
}

__attribute__((section(".text.func_0035EEF8")))
void func_0035EEF8(SfxCtx *a)
{
    void (*fn)(void *) = a->unk70;
    void *arg = a->unk38;
    if (fn) fn(arg);
}

INCLUDE_ASM("permanent", func_0035ED08);

__attribute__((section(".text.func_0035EDE0")))
void func_0035EDE0(unsigned char *t)
{
    int i;
    for (i = 0; i < 16; i++) t[i] = 0;
    for (i = 16; i < 0xEC; i++) t[i] = (i - 16) * 0.582f;
    for (i = 0xEC; i < 0x100; i++) t[i] = 0x80;
}

__attribute__((section(".text.func_0035EA88")))
int func_0035EA88(SfxTypeView *a)
{
    switch (a->unk4) {
    case 0x11: case 0x31: case 0x41: case 0x51: case 0x61:
    case 0x71: case 0xF1: case 0x111: case 0x1001:
        return 0;
    case 0x21: case 0x101:
        return 1;
    default:
        SFXLIB_Error(0, 0, D_00459C70);
        return 0;
    }
}

__attribute__((section(".text.func_0035EF78")))
void func_0035EF78(SfxTypeView *a, SfxModeView *b, int c)
{
    int type = a->unk4;

    if (type == 0)
        a->unk4 = func_0035F830(b, D_00459ED8);
    switch (type) {
    case 0x11:
        if (b->unk90 != 1) {
            func_0035F1D0(a, b, c, 0);
            return;
        }
        /* fallthrough */
    case 0x1001:
        func_0035EB98(a, b, 0x15);
        func_0035F1D0(a, b, c, 1);
        return;
    case 0x21:
        func_0035EB98(a, b, 1);
        func_0035F3C8(a, b, c);
        return;
    case 0x31:
        func_0035EB98(a, b, 2);
        func_0035F1D0(a, b, c, 1);
        return;
    case 0x41: case 0x51: case 0x61:
        func_0035EB98(a, b, func_0035EB60(a, b));
        func_0035F1D0(a, b, c, 1);
        return;
    case 0x101:
        func_0035F1D0(a, b, c, 0);
        return;
    case 0x71: case 0xF1: case 0x111:
    default:
        SFXLIB_Error(a, b, D_00459EE0);
        return;
    }
}

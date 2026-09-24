/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 candidate. */
#include "godhand/vu0.h"

typedef struct { int w[0x14A0 / 4]; } __attribute__((aligned(16))) SaveBlob;

extern char D_00569B70[];
extern char D_0061A990[];
extern char D_005CB000[];

extern void cCoreSave_systemInit(void *s);
extern void cCoreSave_setGameDifficulty(void *s, int level);
extern void cCoreSave_gameInit(void *s);
extern void cWorldTime_gameInit(void *w);
extern void cSaveManager_setCheckPoint(void *self, int a1, int a2, int a3);
extern void cHeatSys_Initialize(void *h);

__attribute__((section(".text.func_002C0840")))
void func_002C0840(char *self)
{
    char tmp[0x14A0] __attribute__((aligned(16)));
    char *p;
    char *q;
    char *t;
    char *u;
    int i;

    t = tmp;
    VU0_SQC2_VF0(tmp, 0x190);
    p = tmp + 0x28A;
    i = 0x7F;
    do {
        p[4] = 0;
        p += 0x10;
    } while (--i != -1);
    *(int *)(t + 0xB8C) = 0;
    func_003A52F0(tmp, 0, 0x14A0);
    *(unsigned short *)(tmp + 0x10) = *(unsigned short *)(self + 0x10);
    *(char *)(tmp + 0x1F) = *(char *)(self + 0x1F);
    *(int *)(tmp + 0xB90) = *(int *)(self + 0xB90);
    *(int *)(tmp + 0x170) = *(int *)(self + 0x170);
    *(int *)(tmp + 0x174) = *(int *)(self + 0x174);
    *(int *)(tmp + 0x178) = *(int *)(self + 0x178);
    cCoreSave_systemInit(D_00569B70);
    cCoreSave_setGameDifficulty(D_00569B70, *(char *)(tmp + 0x1F));
    cCoreSave_gameInit(D_00569B70);
    cWorldTime_gameInit(D_0061A990);
    *(int *)(*(char **)D_00569B70 + 0xB8C) |= 1;
    cSaveManager_setCheckPoint(self, 0, 0, 0);
    cHeatSys_Initialize(D_005CB000);
    *(short *)(self + 0xC) = 0x100;
    *(unsigned short *)(self + 0x10) = *(unsigned short *)(tmp + 0x10);
    *(char *)(self + 0x1F) = *(char *)(tmp + 0x1F);
    *(int *)(self + 0xB90) = *(int *)(tmp + 0xB90);
    *(int *)(self + 0x170) = *(int *)(tmp + 0x170);
    *(int *)(self + 0x174) = *(int *)(tmp + 0x174);
    *(int *)(self + 0x178) = *(int *)(tmp + 0x178);
    *(SaveBlob *)*(char **)D_00569B70 = *(SaveBlob *)self;
    u = tmp;
    q = tmp + 0xA8A;
    while (u + 0x28A != q) {
        q -= 0x10;
    }
}

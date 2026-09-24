/* TU: cIDBase [id] - recovered C++ class. */
#include "godhand/vu0.h"
extern int *D_003C2384;
extern void func_002A9DF8(int a0);
extern void cIDBase_resetAnim(int a0);

__attribute__((section(".text.cIDBase_initialize")))
int cIDBase_initialize(int a0, int a1, int a2)
{
    int r;
    func_002A9DF8(a0);
    *(int*)(a0 + 0x10) = a2;
    *(char*)(a0 + 0x46) = 6;
    *(int*)(a0 + 0x14) = a1;
    r = func_002ACD78(*D_003C2384, a1, a2 + 1);
    if (r == 0)
        return 0;
    if (cIDBase_setWorkFromData(a0, r) != 0)
        cIDBase_resetAnim(a0);
    return 1;
}

__attribute__((section(".text.cIDBase_restartAnim")))
void cIDBase_restartAnim(void *a0) {
    cIDBase_resetAnim(a0);
    *(char *)((char *)a0 + 0x1C) = 1;
}
#include "include_asm.h"

extern unsigned char *D_003C23A4;
extern void func_002AA6E0(void);
extern void func_002ABDC0(void *a0, void *a1);
extern void func_002AC048(void *a0, void *a1);
extern void func_002AC1C0(void *a0, void *a1);
extern void func_002AC298(void *a0, void *a1);
extern void func_002AC378(void *a0, void *a1);
extern int cMessage_create(int a0, int a1, int a2, int a3, int t0);

__attribute__((section(".text.cIDBase")))
void *cIDBase(void *a0) {
    VU0_SQC2_VF0(a0, 0x20);
    VU0_SQC2_VF0(a0, 0x30);
    func_002A9DF8(a0);
    return a0;
}

__attribute__((section(".text.cIDBase_setDispFamily")))
void cIDBase_setDispFamily(int a0, int a1, int a2) {
    int w = cIDBase_getIDWork(a0);
    func_002AA598(a0, w, a2);
    func_002AA5F0(a0, w, a2);
}


__attribute__((section(".text.cIDBase_move")))
void cIDBase_move(void *a0)
{
    char *s1 = (char *)a0;
    int i;
    int v;
    unsigned long t;
    if (*(unsigned char *)(s1 + 0x18) != 0) return;
    if (*(int *)(s1 + 0x4) == 0) return;
    func_002AA6E0();
    if (*(unsigned char *)(s1 + 0x1C) == 0) return;
    v = *(unsigned short *)(s1 + 0x1A) + 1;
    *(short *)(s1 + 0x1A) = (short)v;
    if ((short)v >= 0x2710) *(short *)(s1 + 0x1A) = 0;
    i = 0;
    while (i < *(int *)(s1 + 0xC)) {
        char *s0 = *(char **)(s1 + 0x4) + i * 0xAC;
        if (s0 != 0) {
            func_002ABDC0(s1, s0);
            func_002AC048(s1, s0);
            func_002AC1C0(s1, s0);
            func_002AC298(s1, s0);
            func_002AC378(s1, s0);
            if (*(unsigned char *)(s0 + 0x88) == 4) {
                t = *(int *)(s0 + 0x2C);
                if (((t >> 1) & 1) == 0) {
                    if (*(unsigned short *)(s0 + 0x90) != 0xFFFF) {
                        cMessage_create((int)D_003C23A4, *(unsigned short *)(s0 + 0x90), 0, 0, 0);
                        *(int *)(s0 + 0x2C) = *(int *)(s0 + 0x2C) | 0x2;
                    }
                }
            }
        }
        i++;
    }
}

extern void *D_003C2380;
extern int D_005E7510;
extern int D_007474A0;
extern char D_0044AF20[];
extern char D_0044AF28[];
extern char D_0044AF30[];
extern void *SearchData(void *a, void *b, int c);
extern void cFont_setTextureAddr(void *a0, int a1, void *a2, void *a3);
extern void cScrSpriteDraw_drawInit(void *p);
extern void cMessDrawFont_setEnvInit(void *a0);
extern void func_002AF6A8(void *a0, int a1, int a2);
extern void func_002AAFF0(void *a0, void *a1, void *a2);
extern void func_002AB0B8(void *a0, void *a1);
extern void func_002AB2A0(void *a0, void *a1);
extern void func_002AB360(void *a0, void *a1);
extern void func_002AAEF0(void *a0, void *a1, void *a2);

__attribute__((section(".text.cIDBase_trans")))
void cIDBase_trans(void *a0)
{
    char *s2 = (char *)a0;
    int draw[0x10];
    int layer;
    int i;

    if (*(unsigned char *)(s2 + 0x19) != 0) return;
    if (*(int *)(s2 + 0x4) == 0) return;
    cScrSpriteDraw_drawInit(draw);
    *(short *)((char *)draw + 0x30) = 0;
    if (*(int *)(s2 + 0x8) != 0) {
        char *g = (char *)&D_007474A0;
        int v = *(int *)(g + 0x56C);
        if (v == 0) {
            void *t = SearchData(*(void **)(s2 + 0x8), D_0044AF20, 0);
            cFont_setTextureAddr(D_003C2380, 3, t, SearchData(*(void **)(s2 + 0x8), D_0044AF28, 0));
        } else if (v >= 0) {
            if (v < 7) {
                void *t = SearchData(*(void **)(g + 0x558), D_0044AF20, 0);
                cFont_setTextureAddr(D_003C2380, 3, t, SearchData(*(void **)(s2 + 0x8), D_0044AF28, 0));
            }
        }
        *(void **)(D_003C23A4 + 0x8) = SearchData(*(void **)(s2 + 0x8), D_0044AF30, 0);
    }
    cMessDrawFont_setEnvInit(&D_005E7510);
    func_002AF6A8(&D_005E7510, 2, 0);
    for (layer = 4; layer >= -4; layer--) {
        for (i = 0; i < *(int *)(s2 + 0xC); i++) {
            int m29 = 0x20000000;
            int one = 1;
            long m27 = 0x8000000;
            char *e = *(char **)(s2 + 0x4) + i * 0xAC;
            unsigned long t1;
            if (e == 0) continue;
            if (*(signed char *)(e + 0x2B) != layer) continue;
            t1 = *(int *)(e + 0x2C);
            if (*(int *)(e + 0x2C) & m29) continue;
            if (*(signed char *)(e + 0x29) >= 0) {
                int flag = 0;
                char *p;
                for (p = *(char **)(e + 0x20); p != 0; p = *(char **)(p + 0x20)) {
                    unsigned long w = *(int *)(p + 0x2C);
                    long b = (w >> 3) & 1;
                    if (b != 0) {
                        if (w & 0x8000000) flag = 1;
                    }
                }
                if (flag == one) continue;
            }
            if (t1 & m27) continue;
            switch (*(unsigned char *)(e + 0x88)) {
            case 1:
                func_002AAFF0(s2, draw, e);
                break;
            case 2:
                func_002AB0B8(s2, e);
                break;
            case 4:
                func_002AB2A0(s2, e);
                break;
            case 3:
                func_002AB360(s2, e);
                break;
            default:
                func_002AAEF0(s2, draw, e);
                break;
            }
        }
    }
}

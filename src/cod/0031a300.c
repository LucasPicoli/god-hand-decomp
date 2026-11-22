/* sn-2.95.3-136: double-buffered DMA packet chain setup and the VIF1 kick (0x31A300..). */

#include "godhand/gameWork.h"

typedef unsigned int u_int;

typedef struct {
    int lo;
    int hi;
} DmaRange;

typedef struct {
    char pad[0xB00];
    DmaRange slot[1];
} DmaChainObj;

__attribute__((section(".text.func_0031A300")))
void func_0031A300(DmaChainObj *self, int i, int base)
{
    self->slot[i].lo = base;
    self->slot[i].hi = base + 0x80;
}

__attribute__((section(".text.func_0031A320")))
void func_0031A320(DmaChainObj *self, int i)
{
    self->slot[i].lo = 0;
    self->slot[i].hi = 0;
}

static inline int pktIsMode1(void)
{
    return D_007474A0.mode == 1;
}

#define PKT(set, n, odd) ((set)->pkt[n][odd].data)
#define LINK(a, b) SetPackedFields10And18_14FF60((int)(a), (int *)(b))

__attribute__((section(".text.func_0031A338")))
void func_0031A338(DmaPktSet *set)
{
    int odd = D_007474A0.frame & 1;
    char *p0, *p1, *p2, *p3, *p5, *p6, *p7, *p8, *p9;

    func_0014FE78(p0 = PKT(set, 0, odd));
    func_0014FE78(p1 = PKT(set, 1, odd));
    func_0014FE78(p2 = PKT(set, 2, odd));
    func_0014FE78(p3 = PKT(set, 3, odd));
    func_0014FE78(p5 = PKT(set, 5, odd));
    func_0014FE78(p6 = PKT(set, 6, odd));
    func_0014FE78(p7 = PKT(set, 7, odd));
    func_0014FE78(p8 = PKT(set, 8, odd));
    func_0014FE78(p9 = PKT(set, 9, odd));
    if (!(D_007474A0.flags & GAMEWORK_SKIP_PKT_1_3)) {
        LINK(p0, p1);
        LINK(p1, p3);
        LINK(p3, p2);
        LINK(p2, p5);
        LINK(p5, p6);
        LINK(p6, p7);
        LINK(p7, p8);
        LINK(p8, p9);
    } else {
        LINK(p0, p5);
        LINK(p5, p6);
        LINK(p6, p7);
        LINK(p7, p8);
        LINK(p8, p9);
    }
    if (pktIsMode1()) {
        func_0014FE78(PKT(set, 10, odd));
        LINK(PKT(set, 9, odd), PKT(set, 10, odd));
    }
}

__attribute__((section(".text.func_0031A538")))
void func_0031A538(int *tbl)
{
    int odd = D_007474A0.frame & 1;

    if (D_007474A0.flags & GAMEWORK_IN_INTERRUPT) {
        iFlushCache(0);
    } else {
        FlushCache(0);
    }
    sceGsSyncPath(0, 0);
    *(volatile u_int *)0x1000E010 = 2;
    *(volatile u_int *)0x1000E020 = 2;
    *(volatile u_int *)0x10009020 = 0;
    *(volatile u_int *)0x10009030 = tbl[odd * 32];
    *(volatile u_int *)0x10009000 = 0x45;
    *(volatile u_int *)0x10009000 = 0x145;
}

/* sn-2.95.3-136: func_0017AC90, setup with a radius 1 damage-take sphere 2.28 above the first child, a 120-frame
 * timer pair, and the child's height kept at 0x608. */
#include "godhand/cOmBase.h"
#include "godhand/cOmHitVolumeSetup.h"
extern void func_0017B5E0(unsigned char *p);
extern char D_00574380[];

static inline void *GetChild(char *p)
{
    int frame[3];

    return cOmBase_childAt((cOmBase *)p, frame, 0);
}

__attribute__((section(".text.func_0017AC90")))
int func_0017AC90(char *p)
{
    int bits;

    func_001B6FB8(p);
    {
        float ofs[4];
        void *slot;

        ofs[2] = 2.28f;
        ofs[3] = 1.0f;
        ofs[0] = 0.0f;
        ofs[1] = 0.0f;
        slot = cDamageManage_CreateDamageTake(D_00574380, p, 2);
        *(void **)(p + 0x60C) = slot;
        if (slot != 0 && GetChild(p) != 0) {
            cDamageUnit_AddDamageCollSphere(*(void **)(p + 0x60C), (char *)GetChild(p) + 0x80, ofs, 1.0f);
            *(int *)*(void **)(p + 0x60C) |= 1;
        }
    }
    bits = *(int *)(p + 0x250) | 0x10000;
    *(unsigned char *)(p + 0x602) = 0;
    *(int *)(p + 0x5B8) |= 8;
    *(unsigned char *)(p + 0x600) = 0;
    *(short *)(p + 0x548) = 0x78;
    *(short *)(p + 0x54A) = 0x78;
    *(int *)(p + 0x250) = bits;
    func_0017B5E0(p);
    if (GetChild(p) != 0)
        *(float *)(p + 0x608) = *(float *)((char *)GetChild(p) + 0x100);
    return 1;
}

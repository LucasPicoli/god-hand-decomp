/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/globals.h"

extern void *cSnd_GetSeData(void *a0, int a1);
extern void func_002FBFB0(int a0);
extern void UpdateObjByIndexedOp_2FBE50(int a0);
extern void getEffTypeString(void *a0, int a1);
extern void func_003A6C58(void *a0, void *a1, void *a2, int a3, int t0);

__attribute__((section(".text.cSnd_SeCall_2CBA48")))
int cSnd_SeCall_2CBA48(cSnd *self, int slot, short key, cObj *obj, cObj *owner, cParts *part, unsigned int a6, int a7) {
    int blk = (short)slot;
    int group;
    void *r;

    if (blk == 1) {
        int *p;
        unsigned int i;
        if (owner != 0) {
            group = cSnd_getEmSeGroupOwner(self, *(int *)((char *)owner + 0x564));
            if (group <= 0)
                group = owner->createId;
        } else {
            group = cSnd_getEmSeGroupOwner(self, *(int *)((char *)obj + 0x564));
            if (group <= 0)
                group = obj->createId;
        }
        p = D_0044CE48;
        i = 0;
        do {
            void *e = cSnd_GetSeData(self, *p);
            if (*(int *)((char *)e + 0x3C) == group)
                blk = *(short *)p;
            i++;
            p++;
        } while (i < 0xC);
    }

    r = cSnd_GetSeData(self, blk);
    if (cSeData_IsAlive(r) == 0)
        return 0;
    {
        int v = cSnd_AllocVoice(self);
        if (v == 0)
            return 0;
        return cSndSeVoice_Bind(v, blk, key, obj, part, a6, a7);
    }
}

__attribute__((section(".text.func_002FBED0")))
void func_002FBED0(int a0) {
    int s0 = a0;
    if (func_002B5E50(a0)) {
        int v = *(int*)(s0 + 0x114);
        if (v) {
            if (*(int*)(v + 0x250) < 0) {
                UpdateObjByIndexedOp_2FBE50(s0);
            }
        }
    }
    func_002FBFB0(s0);
    if (((*(int**)(s0 + 0x110))[1]) & 0x800) {
        if (D_00741DB8 == 0) {
            *(int*)(s0 + 0x11C) = *(int*)(s0 + 0x11C) | 0x800000;
        } else {
            *(int*)(s0 + 0x11C) = *(int*)(s0 + 0x11C) & 0xFF7FFFFF;
        }
    }
    if (((*(int**)(s0 + 0x110))[1]) & 0x400) {
        if (D_00741DB8 != 0) {
            *(int*)(s0 + 0x11C) = *(int*)(s0 + 0x11C) | 0x800000;
        } else {
            *(int*)(s0 + 0x11C) = *(int*)(s0 + 0x11C) & 0xFF7FFFFF;
        }
    }
}

__attribute__((section(".text.func_002D9F68")))
void func_002D9F68(void *a0, int a1, ...) {
    char buf0[0x100];
    char localbuf[0x40];
    getEffTypeString(localbuf, *(short*)((char*)a0 + 0x23A));
    func_003A6C58(buf0, D_0044D3B0, localbuf, (int)((unsigned short)*(unsigned short*)((char*)a0 + 0x23C) - 1), a1);
}

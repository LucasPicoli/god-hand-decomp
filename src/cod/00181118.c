/* sn-2.95.3-136: func_00181118, enemy phase update: run the handler of the current phase entry, regenerate one guard point every 4 frames, and on a new hit take its damage from the guard (breaking it at zero) with a hit sound. */
extern int cSnd_SeCall_2CBA48(void *snd, int a1, int id, void *owner, int t0, int t1, int t2, int t3);
extern void func_00180CD8(char *self);
extern char D_005FEE00[];

#include "godhand/cOmBase.h"
#include "godhand/cModel.h"
#include "godhand/emPhaseTable.h"

extern EmPhaseTable D_003BDB18;

__attribute__((section(".text.func_00181118")))
void func_00181118(char *self)
{
    char *e;
    int ofs;
    int adjust;
    int type;
    int arg;
    void (*fp)(int);
    cVtEnt8 entry;
    cDamageTake *hit;
    int n;
    int m;
    int c;
    unsigned long t;

    ofs = *(unsigned char *)(self + 0x2F5) * 8;
    e = (char *)&D_003BDB18 + ofs;
    type = *(short *)(e + 2);
    if (type >= 0) {
        cVtEnt8 *vt = *(cVtEnt8 **)(self + *(short *)(e + 4));
        entry = vt[type - 1];
        fp = (void (*)(int))entry.pfn;
    } else {
        fp = *(void (**)(int))((char *)&D_003BDB18 + ofs + 4);
    }
    adjust = D_003BDB18.e[*(unsigned char *)(self + 0x2F5)].adjust;
    if (type >= 0)
        arg = entry.delta + adjust;
    else
        arg = adjust;
    fp((int)(self + arg));

    c = --*(signed char *)(self + 0x60A);
    if (c <= 0) {
        *(signed char *)(self + 0x60A) = 4;
        n = *(short *)(self + 0x54A) + 1;
        if (n >= *(short *)(self + 0x548))
            *(short *)(self + 0x54A) = *(short *)(self + 0x548);
        else
            *(short *)(self + 0x54A) = n;
    }
    hit = *(cDamageTake **)(self + 0x60C);
    if (hit != 0) {
        t = hit->flags;
        t &= 1;
        if (t != 0) {
        m = *(short *)(self + 0x54A);
        m -= hit->power;
        *(float *)(self + 0x54C) = 3.0f;
        if (m >= *(short *)(self + 0x548))
            *(short *)(self + 0x54A) = *(short *)(self + 0x548);
        else
            *(short *)(self + 0x54A) = m;
        if (*(short *)(self + 0x54A) <= 0) {
            *(unsigned char *)(self + 0x2F4) = 1;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        } else {
            *(short *)(self + 0x600) = 8;
            *(float *)(self + 0x604) = (*(float **)(self + 0xF0))[1];
        }
        cSnd_SeCall_2CBA48(D_005FEE00, 0, 10, self, 0, 0, 0, 0);
        }
    }
    func_00180CD8(self);
}

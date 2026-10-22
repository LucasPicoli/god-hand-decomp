/* sn-2.95.3-136: func_001AC980, breakable gimmick phase update: run the handler of the current
 * phase entry, regenerate one guard point every 5 frames, and on a new hit (when not locked)
 * take its damage from the guard, breaking it at zero, with a hit sound. */
extern int cSnd_SeCall_2CBA48(void *snd, int a1, int id, void *owner, int t0, int t1, int t2, int t3);
extern void func_001AC370(char *self);
extern void func_001B7EE0(void *self, float f);
extern char D_005FEE00[];

#include "godhand/cOmBase.h"
#include "godhand/cModel.h"
#include "godhand/emPhaseTable.h"

extern EmPhaseTable D_003BDC40;

__attribute__((section(".text.func_001AC980")))
void func_001AC980(char *self)
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
    e = (char *)&D_003BDC40 + ofs;
    type = *(short *)(e + 2);
    if (type >= 0) {
        cVtEnt8 *vt = *(cVtEnt8 **)(self + *(short *)(e + 4));
        entry = vt[type - 1];
        fp = (void (*)(int))entry.pfn;
    } else {
        fp = *(void (**)(int))((char *)&D_003BDC40 + ofs + 4);
    }
    adjust = D_003BDC40.e[*(unsigned char *)(self + 0x2F5)].adjust;
    if (type >= 0)
        arg = entry.delta + adjust;
    else
        arg = adjust;
    fp((int)(self + arg));

    c = --*(signed char *)(self + 0x621);
    if (c <= 0) {
        *(signed char *)(self + 0x621) = 5;
        n = *(short *)(self + 0x54A) + 1;
        if (n >= *(short *)(self + 0x548))
            *(short *)(self + 0x54A) = *(short *)(self + 0x548);
        else
            *(short *)(self + 0x54A) = n;
    }
    if (*(unsigned char *)(self + 0x60D) == 0) {
        hit = *(cDamageTake **)(self + 0x624);
        if (hit != 0) {
            t = hit->flags;
            t &= 1;
            if (t != 0) {
            int d = hit->power;

            m = *(short *)(self + 0x54A);
            m -= d;
            *(float *)(self + 0x54C) = 3.0f;
            if (m >= *(short *)(self + 0x548))
                *(short *)(self + 0x54A) = *(short *)(self + 0x548);
            else
                *(short *)(self + 0x54A) = m;
            *(int *)(self + 0x618) += d;
            if (*(short *)(self + 0x54A) <= 0) {
                *(unsigned char *)(self + 0x2F4) = 1;
                *(unsigned char *)(self + 0x2F5) = 0;
                *(unsigned char *)(self + 0x2F6) = 0;
                *(unsigned char *)(self + 0x2F7) = 0;
            } else {
                *(short *)(self + 0x610) = 8;
                *(float *)(self + 0x614) = (*(float **)(self + 0xF0))[1];
            }
            cSnd_SeCall_2CBA48(D_005FEE00, 0, 10, self, 0, 0, 0, 0);
            }
        }
    }
    func_001AC370(self);
    if (*(unsigned char *)(self + 0x60C) == 1)
        func_001B7EE0(self, 2.0f);
}

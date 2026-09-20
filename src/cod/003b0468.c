/* ee-2.9-991111 matched TU. */

extern int iWakeupThread(int id);
extern int iSignalSema(int id);
extern int D_003FAE48;
extern int D_0077DF90;
extern char D_0077DF98[];

#include "godhand/sync.h"


__attribute__((section(".text._sceSDC")))
void _sceSDC(unsigned int start, unsigned int end)
{
    int i;
    unsigned int t;

    for (i = 0; i < 0x1000; i += 0x40) {
        GH_SYNC();
        GH_CACHE(0x10, 0x0, i);
        GH_SYNC();
        GH_MFC0_TAGLO(t);
        t = (t & 0xFFFFF000U) + i;
        if (t >= start && t <= end) {
            GH_SYNC();
            GH_CACHE(0x14, 0x0, i);
            GH_SYNC();
        }
        GH_SYNC();
        GH_CACHE(0x10, 0x1, i);
        GH_SYNC();
        GH_MFC0_TAGLO(t);
        t = (t & 0xFFFFF000U) + i;
        if (t >= start && t <= end) {
            GH_SYNC();
            GH_CACHE(0x14, 0x1, i);
            GH_SYNC();
        }
        GH_SYNC();
    }
}

#include "godhand/sync.h"


__attribute__((section(".text._sceIDC")))
void _sceIDC(unsigned int start, unsigned int end)
{
    int i;
    unsigned int t;

    for (i = 0; i < 0x1000; i += 0x40) {
        GH_SYNC();
        GH_CACHE(0x10, 0x0, i);
        GH_SYNC();
        GH_MFC0_TAGLO(t);
        t = (t & 0xFFFFF000U) + i;
        if (t >= start && t <= end) {
            GH_SYNC();
            GH_CACHE(0x16, 0x0, i);
            GH_SYNC();
        }
        GH_SYNC();
        GH_CACHE(0x10, 0x1, i);
        GH_SYNC();
        GH_MFC0_TAGLO(t);
        t = (t & 0xFFFFF000U) + i;
        if (t >= start && t <= end) {
            GH_SYNC();
            GH_CACHE(0x16, 0x1, i);
            GH_SYNC();
        }
        GH_SYNC();
    }
}

#include "godhand/eesyscall.h"

typedef struct { unsigned char cmd; unsigned char arg; } Ent;
typedef struct { int f0; int idx; Ent ent[512]; } Ring;







__attribute__((section(".text.func_003B0A40")))
int func_003B0A40(int id)
{
    int me;
    Ring *q;
    int i;

    EE_SYSCALL_R(-0x2F, me);
    if (me != id) {
        return iWakeupThread(id);
    }
    if ((unsigned int)me >= 0x100 || D_003FAE48 == 0) {
        return -1;
    }
    q = (Ring *)D_0077DF98;
    i = q->idx & 0x1FF;
    q->idx = i + 1;
    q->ent[i].cmd = 0;
    q->ent[i].arg = me;
    iSignalSema(D_0077DF90);
    return me;
}

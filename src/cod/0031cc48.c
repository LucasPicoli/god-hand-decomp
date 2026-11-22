#include "godhand/heapArena.h"
#include "godhand/gameWork.h"
#include "godhand/globals.h"

extern int func_003A6C58(char *buf, const char *fmt, ...);
extern int cDvd_ReadAllocSized(void *dvd, void *path, void *out, void *heap, int t0, void *t1, int t2, int t3);
extern void cDvd_CheckWaitFrame(void *dvd, int frame);
extern char D_00583F20[];

__attribute__((section(".text.func_0031CC48")))
void func_0031CC48(void)
{
    char buf[0x40];
    int sp40;
    GameWork *g;
    char *dvd;
    unsigned char area;
    int req;

    g = &D_007474A0;
    /* room id: high byte the area, low byte the room in it */
    area = ((unsigned char *)&g->room)[1];
    func_003A6C58(buf, D_00450EC0, area, area, ((unsigned char *)&g->room)[0]);
    dvd = D_00583F20;
    req = cDvd_ReadAllocSized(dvd, buf, &g->pack, &D_00754220, 0, &sp40, 0, 0);
    cDvd_CheckWaitFrame(dvd, req);
    D_007558A0[0] = (int)g->pack;
    D_007558A0[1] = sp40;
}

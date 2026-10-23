/* sn-2.95.3-136: func_002F3F30, reach slot init: copy the two reach volumes to the global, scale the reach radius, validate the slot indices and latch them when in reach. */
#include "godhand/reachObj.h"

extern char D_0044F038[];
extern char D_0044F058[];
extern void func_002D9F68(ReachObj *o, char *fmt, int v);

__attribute__((section(".text.func_002F3F30")))
int func_002F3F30(ReachObj *o)
{
    CAM_VIB(1, amp) = o->vol->a[0];
    CAM_VIB(1, speed) = o->vol->a[1];
    CAM_VIB(1, decay) = o->vol->a[2];
    CAM_VIB(1, phase) = o->vol->a[3];
    CAM_VIB(0, amp) = o->vol->b[0];
    CAM_VIB(0, speed) = o->vol->b[1];
    CAM_VIB(0, decay) = o->vol->b[2];
    CAM_VIB(0, phase) = o->vol->b[3];
    o->reach = o->vol->reach * 1000.0f;
    o->idxA = o->vol->idxA;
    o->idxB = o->vol->idxB;
    if (o->idxA < -1) {
        func_002D9F68(o, D_0044F038, o->idxA);
        return 0;
    }
    if (o->idxB < -1) {
        func_002D9F68(o, D_0044F058, o->idxB);
        return 0;
    }
    if (ReachObj_isWithinReach(o)) {
        if (o->idxA != -1)
            D_005CAFF0->vib[1].count = o->idxA;
        else
            D_005CAFF0->vib[1].count = 0;
        if (o->idxB != -1)
            D_005CAFF0->vib[0].count = o->idxB;
        else
            D_005CAFF0->vib[0].count = 0;
    }
    return 1;
}

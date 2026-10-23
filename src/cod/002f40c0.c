/* sn-2.95.3-136: reach slot latch (0x2F40C0). */
#include "godhand/reachObj.h"

extern void func_002FBED0(ReachObj *o);
extern void UpdateObjByIndexedOp_2FBE50(void *o);

__attribute__((section(".text.func_002F40C0")))
void func_002F40C0(ReachObj *o)
{
    int changed;
    unsigned char old;

    func_002FBED0(o);
    changed = 0;
    if (o->idxA == -1 && ReachObj_isWithinReach(o)) {
        changed = D_005CAFF0->vib[1].count != 1;
        D_005CAFF0->vib[1].count = 2;
    }
    if (o->idxB == -1 && ReachObj_isWithinReach(o)) {
        old = D_005CAFF0->vib[0].count;
        D_005CAFF0->vib[0].count = 2;
        if (old != 1) {
            changed = 1;
        }
    }
    if (changed) {
        if (o->idxA == -1) {
            CAM_VIB(1, amp) = o->vol->a[0];
            CAM_VIB(1, speed) = o->vol->a[1];
            CAM_VIB(1, decay) = o->vol->a[2];
            CAM_VIB(1, phase) = o->vol->a[3];
        }
        if (o->idxB == -1) {
            CAM_VIB(0, amp) = o->vol->b[0];
            CAM_VIB(0, speed) = o->vol->b[1];
            CAM_VIB(0, decay) = o->vol->b[2];
            CAM_VIB(0, phase) = o->vol->b[3];
        }
    }
    if (o->idxA != -1 && o->idxB != -1) {
        UpdateObjByIndexedOp_2FBE50(o);
    }
}

/* cygnus-2.96 matched TU. */

#include "godhand/Obj3290Pool.h"
#include "godhand/sftim.h"

extern void func_00352888(int time, int rate, int drop, int ofs, SftimTc *tc);
extern void func_00352AA0(SftimTc *src, SftimTc *dst);

/* With the lock held, run every queued pool entry, then release the lock. */
__attribute__((section(".text.func_00328BB0")))
void func_00328BB0(void) {
    int i;
    int queued;
    Obj3290Ent *ent;

    if (Obj3290_Tramp_0033BF18_9058(&D_003D04C4) != 0) {
        queued = OBJ3290_STATE_QUEUED;
        ent = D_003D04D0;
        for (i = OBJ3290_POOL_NUM - 1; i >= 0; i--) {
            if (ent->state == queued)
                func_003288E0(ent);
            ent++;
        }
        D_003D04C4 = 0;
    }
}

/* Set the handle's current timecode: from a time value when given, else from the start record or a cleared one. */
__attribute__((section(".text.Sftim_setTimecode")))
void Sftim_setTimecode(SftimHn *hn, SftimInfo *info, int time, int update)
{
    SftimWork *tim = &hn->tim;
    int drop = info->drop;
    int rate = info->rate;
    int ofs = info->ofs;

    if (update != 0 && time >= 0) {
        func_00352888(time, rate, drop, ofs, &tim->tc);
        return;
    }
    if (tim->rec[1].valid == 0) {
        if (hn->f36B0 != 0)
            return;
        tim->tc.rate = rate;
        tim->tc.drop = 0;
        tim->tc.hour = 0;
        tim->tc.min = 0;
        tim->tc.sec = 0;
        tim->tc.frame = 0;
        return;
    }
    if (update != 0) {
        func_00352AA0(&tim->rec[1].tc, &tim->tc);
        tim->fld[0].fieldB = tim->tc.fieldB;
        tim->fld[ofs].fieldB = tim->tc.fieldB;
        return;
    }
    tim->tc.rate = tim->rec[1].tc.rate;
    tim->tc.drop = tim->rec[1].tc.drop;
    tim->tc.hour = tim->rec[1].tc.hour;
    tim->tc.min = tim->rec[1].tc.min;
    tim->tc.sec = tim->rec[1].tc.sec;
    tim->tc.frame = tim->rec[1].tc.frame;
}

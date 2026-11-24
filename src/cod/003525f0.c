/* cygnus-2.96: Sofdec timecode (0x3525F0..). */

#include "godhand/sftim.h"

__attribute__((section(".text.sfmpv_ReformTc")))
void sfmpv_ReformTc(SftimHn *hn, MpvPicAtr *info, long time, int update)
{
    int cond = GetArrayElemA0C_35A1C8(hn, 0x34);

    if (cond == 0) {
        if (time >= 0 || info->f30 == 0 || info->f57 != 0
            || (update != 0 && sfmpv_DetectTcErr(hn, info) != 0)) {
            SFSET_SetCond(hn, 0x34, 1);
            cond = 1;
        }
    }
    if (cond == 1) {
        Sftim_setTimecode(hn, info, time, update);
    }
}

/* Record the current timecode as the start record, once. pic is not read. */
__attribute__((section(".text.sfmpv_SetHeadTtu")))
void sfmpv_SetHeadTtu(SftimHn *hn, MpvPicAtr *pic)
{
    SftimRec *rec = &hn->tim.rec[0];

    if (rec->valid == 0) {
        SftimTc tc = hn->tim.tc;
        int time;
        int unit;

        tc.frameAdd = 0;
        SFTIM_Tc2Time(&tc, &time, &unit);
        rec->tc = tc;
        rec->time = time;
        rec->unit = unit;
        rec->valid = 1;
    }
}

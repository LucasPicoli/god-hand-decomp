/* cygnus-2.96: Sofdec timecode (0x3525F0..). */

#include "godhand/sftim.h"

int sfmpv_DetectTcErr(SftimHn *hn, SftimInfo *info);
void Sftim_setTimecode(SftimHn *hn, SftimInfo *info, int time, int update);

__attribute__((section(".text.sfmpv_ReformTc")))
void sfmpv_ReformTc(SftimHn *hn, SftimInfo *info, int time, int update)
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

__attribute__((section(".text.sfmpv_SetHeadTtu")))
void sfmpv_SetHeadTtu(SftimHn *hn)
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

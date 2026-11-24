#include "godhand/sftim.h"

__attribute__((section(".text.sfmpv_DetectTcErr")))
int sfmpv_DetectTcErr(SftimHn *hn, MpvPicAtr *info)
{
    SftimTc tc;
    int now;
    int unit;
    int start;
    int len;

    if (hn->tim.rec[1].valid == 0) {
        return 0;
    }
    tc = hn->tim.tc;
    SFTIM_Tc2Time(&tc, &now, &unit);
    SFTIM_Tc2Time(&hn->tim.rec[1].tc, &start, &unit);
    len = GetArrayElemA0C_35A1C8(hn, 0x35) * unit;
    if (now > start) {
        if (now < start + len) return 0;
        return 1;
    }
    return 1;
}


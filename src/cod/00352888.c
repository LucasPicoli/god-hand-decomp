#include "godhand/sftim.h"

int func_003526D0(SftimHn *hn, SftimInfo *info);
void Sftim_setTimecode(SftimHn *hn, SftimInfo *info, int time, int update);

__attribute__((section(".text.func_00352888")))
void func_00352888(int time, int rate, int drop, int ofs, SftimTc *tc)
{
    int fps1000 = D_00459920[rate];
    int fps = D_004596C8[rate];
    int frames = func_0036C990(time, fps1000 * 2, 90000000);
    int hour;
    int min;
    int sec;
    int frame;

    tc->rate = rate;
    tc->drop = drop;
    tc->fieldB = frames & 1;
    frames >>= 1;
    frames -= ofs;
    if (frames < 0) {
        frames = 0;
    }
    if (drop != 0 && (fps1000 == 29970 || fps1000 == 59940)) {
        SftimDf *df = (fps1000 == 29970) ? &D_004596F0 : &D_00459710;
        int inHour = frames % df->perHour;
        int tens;

        hour = frames / df->perHour;
        tens = inHour / df->perTenMin;
        frames = inHour % df->perTenMin;
        if (frames < df->firstMin) {
            min = 0;
            sec = frames / df->perSec;
            frame = frames % df->perSec;
        } else {
            frames -= df->firstMin;
            min = frames / df->perMin + 1;
            frames = frames % df->perMin;
            if (frames < df->firstSec) {
                sec = 0;
                frame = frames + df->dropped;
            } else {
                frames -= df->firstSec;
                sec = frames / df->perSec + 1;
                frame = frames % df->perSec;
            }
        }
        min += df->minPerTen * tens;
    } else {
        frame = frames % fps;
        sec = frames / fps;
        min = sec / 60;
        sec %= 60;
        hour = min / 60;
        min %= 60;
    }
    tc->hour = hour;
    tc->min = min;
    tc->sec = sec;
    tc->frame = frame;
}


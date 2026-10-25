/* cygnus-2.96 matched TU. */

#include "godhand/sftim.h"

/* Record the current timecode as the last frame's time (relative to the start record) and keep it as the longest when it is not shorter. */
__attribute__((section(".text.SftimHn_recordLastFrame")))
void SftimHn_recordLastFrame(SftimHn *hn)
{
    SftimTc tc = hn->tim.tc;
    int time;
    int unit;
    SftimRec *start = &hn->tim.rec[0];
    SftimRec *longest = &hn->tim.rec[1];
    SftimRec *last = &hn->tim.rec[3];

    SFTIM_Tc2Time(&tc, &time, &unit);
    last->tc = tc;
    last->time = time - start->time;
    last->unit = unit;
    last->valid = 1;
    if (last->time >= longest->time)
        *longest = *last;
}

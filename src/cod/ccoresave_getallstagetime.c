/* cCoreSave_getAllStageTime - split the total play time into hours, minutes
 * and seconds. Each out-pointer is optional. */
#include "godhand/cCoreSave.h"

__attribute__((section(".text.cCoreSave_getAllStageTime")))
void cCoreSave_getAllStageTime(cCoreSave *self, int *hour, int *min, int *sec) {
    cCoreSaveData *data;
    unsigned int t, h, m, s;
    data = self->data;
    if (!data)
        return;
    t = data->allStageTime;
    h = t / CORESAVE_TICKS_PER_HOUR;
    t = t - h * CORESAVE_TICKS_PER_HOUR;
    m = t / CORESAVE_TICKS_PER_MIN;
    t = t - m * CORESAVE_TICKS_PER_MIN;
    s = t / CORESAVE_TICKS_PER_SEC;
    if (hour)
        *hour = h;
    if (min)
        *min = m;
    if (sec)
        *sec = s;
}

#include "godhand/mwsfd.h"
extern int SFBUF_GetRTot(SfdHn *hn, int index);

__attribute__((section(".text.sfmpv_FixedForSeek")))
void sfmpv_FixedForSeek(SfdHn *hn)
{
    SfdSeek *seek = &hn->seek;
    SfdTimPrm *cur = &hn->cur;
    int index = seek->index;

    if (seek->hdrOfs < 0)
        seek->hdrOfs = SFBUF_GetRTot(hn, index) + 4;
    if (cur->valid < 0)
        *cur = hn->init;
}

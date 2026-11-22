/* cygnus-2.96: MPVM2V_DecodePicAtr, programs the four user data channels and the user data buffer into the M2V decoder, decodes, then copies the attributes back. */
#include "godhand/MpvHandle.h"

__attribute__((section(".text.MPVM2V_DecodePicAtr")))
int MPVM2V_DecodePicAtr(MpvHandle *hn, SjObj *sj)
{
    SfdSjCh *ch;
    int i;

    if (Obj0000_Get_D_003F1FF0_36CCA8() != 0) {
        i = 0;
        ch = hn->ch;
        do {
            func_0036CDC0(hn->dev, i, ch->sj, ch->cb, ch->arg);
            i++;
            ch++;
        } while (i < 4);
        func_0036CDE8(hn->dev, hn->usr.buf, hn->usr.size);
        if (func_0036CE38(hn->dev, sj) != 0)
            return -2;
        func_0036CE10(hn->dev, 0, &hn->usr.len);
        mpvm2v_CopyPicAtr(hn);
        return 0;
    }
    return -1;
}

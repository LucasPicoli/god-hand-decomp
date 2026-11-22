/* cygnus-2.96 matched TU. */
#include "godhand/MpvHandle.h"

/* cygnus-2.96, -freorder-blocks dropped; CRI libmwsfde m2v_frm.o M2V_SkipFrm. */

extern int func_0036BDA0(void *mpv, int a1, int a2);   /* MPV_MoveChunk */

__attribute__((section(".text.func_00369FB8")))
int func_00369FB8(MpvHandle *hn, SjObj *sj)
{
    int err;
    int r;

    if (Obj0000_Set_D_00766D44_Check_Field_188_NE_2(hn) != 0) {
        return func_00369F20(0, 0xFF03020A);
    }
    err = 0xFF030305;
    for (;;) {
        r = MPV_GoNextDelimSj(sj);
        if (r == 0) {
            break;
        }
        if (r & (MPV_DLM_PSC | MPV_DLM_GSC | MPV_DLM_SHC | MPV_DLM_SEC)) {
            err = 0;
            break;
        }
        if (func_0036BDA0(sj, 1, 4) != 4) {
            break;
        }
    }
    return func_00369F20(hn, err);
}

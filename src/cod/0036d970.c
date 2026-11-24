/* cygnus-2.96 matched TU. */
#include "godhand/MpvHandle.h"

/* cygnus-2.96, -freorder-blocks dropped; CRI libmwsfde m2v_frm.o M2V_SkipFrm. */

extern int Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2(void *hn);                         /* CheckHn */
extern int func_0036BDA0(void *mpv, int a1, int a2);   /* MPV_MoveChunk */
extern void *M2VERR_SetCode(void *hn, unsigned int code);   /* ERR_SetCode */

__attribute__((section(".text.func_0036D970")))
void *func_0036D970(void *hn, SjObj *sj)
{
    unsigned int err;
    int r;

    if (Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2(hn) != 0) {
        return M2VERR_SetCode(0, 0xFF03020A);
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
    return M2VERR_SetCode(hn, err);
}

/* cygnus-2.96 matched TU. */

/* cygnus-2.96, -freorder-blocks dropped; CRI libmwsfde m2v_frm.o M2V_SkipFrm. */

extern int Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2(void *hn);                         /* CheckHn */
extern int MPV_GoNextDelimSj(void *mpv);
extern int func_0036BDA0(void *mpv, int a1, int a2);   /* MPV_MoveChunk */
extern void *M2VERR_SetCode(void *hn, unsigned int code);   /* ERR_SetCode */

__attribute__((section(".text.func_0036D970")))
void *func_0036D970(void *hn, void *mpv)
{
    unsigned int err;
    int r;

    if (Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2(hn) != 0) {
        return M2VERR_SetCode(0, 0xFF03020A);
    }
    err = 0xFF030305;
    for (;;) {
        r = MPV_GoNextDelimSj(mpv);
        if (r == 0) {
            break;
        }
        if (r & 0xCC) {
            err = 0;
            break;
        }
        if (func_0036BDA0(mpv, 1, 4) != 4) {
            break;
        }
    }
    return M2VERR_SetCode(hn, err);
}

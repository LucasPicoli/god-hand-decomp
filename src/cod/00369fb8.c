/* cygnus-2.96 matched TU. */

/* cygnus-2.96, -freorder-blocks dropped; CRI libmwsfde m2v_frm.o M2V_SkipFrm. */

extern int Obj0000_Set_D_00766D44_Check_Field_188_NE_2(void *hn);                         /* CheckHn */
extern int MPV_GoNextDelimSj(void *mpv);
extern int func_0036BDA0(void *mpv, int a1, int a2);   /* MPV_MoveChunk */
extern void *func_00369F20(void *hn, unsigned int code);   /* ERR_SetCode */

__attribute__((section(".text.func_00369FB8")))
void *func_00369FB8(void *hn, void *mpv)
{
    unsigned int err;
    int r;

    if (Obj0000_Set_D_00766D44_Check_Field_188_NE_2(hn) != 0) {
        return func_00369F20(0, 0xFF03020A);
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
    return func_00369F20(hn, err);
}

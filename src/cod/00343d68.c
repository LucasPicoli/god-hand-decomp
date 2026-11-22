/* cygnus-2.96: MWSFCRE_ResetSfdHn, starts playback of the attached movie handle
 * with func_00345848 as its callback; reports and returns -1 on failure. */
#include "godhand/globals.h"
extern int SFD_Stop(char *mv);
extern int func_0034DE20(char *mv, int cb, int arg);
extern void func_00345848(int a0, int a1);
extern int MWSFLIB_SetErrCode(int code);
extern void MWSFSVM_Error(char *msg);
extern int mwsfcre_AttachPicUsrBuf(int ply);

__attribute__((section(".text.MWSFCRE_ResetSfdHn")))
int MWSFCRE_ResetSfdHn(char *ply)
{
    char *mv = *(char **)(ply + 0x3C);
    *(char **)(ply + 0x3C) = 0;
    if (SFD_Stop(mv) != 0) {
        MWSFSVM_Error(D_004573D8);
        return -1;
    }
    *(char **)(ply + 0x3C) = mv;
    if (func_0034DE20(mv, (int)func_00345848, (int)ply) != 0) {
        MWSFLIB_SetErrCode(-0x12F);
        MWSFSVM_Error(D_00457410);
        return -1;
    }
    mwsfcre_AttachPicUsrBuf((int)ply);
    return 0;
}

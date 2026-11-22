/* cygnus-2.96: Sofdec frame-info conversion to the SFX layout (0x347008..). */
#include "godhand/mwsfd.h"
#include "godhand/globals.h"

int func_00347080(MwsfdHn *hn);
int func_003470F0(MwsfdHn *hn);
int func_00347160(unsigned int flag);

__attribute__((section(".text.func_00347008")))
void func_00347008(MwsfdHn *hn, MwsfsfxFrm *sfx)
{
    MwsfsfxFrmInf *out = &sfx->frm;
    MwsfdFrmInf *frm;

    out->fmtA = func_00347080(hn);
    out->fmtB = func_003470F0(hn);
    frm = &hn->frm;
    out->w08 = frm->w08;
    out->w0C = frm->w0C;
    out->w10 = frm->w10;
    out->flagA = func_00347160(frm->flagA);
    out->flagB = func_00347160(frm->flagB);
}

__attribute__((section(".text.func_00347080")))
int func_00347080(MwsfdHn *hn)
{
    int ret = 3;

    switch (hn->frm.fmtA) {
    case 1:
        ret = 1;
        break;
    case 2:
        ret = 2;
        break;
    case 3:
        ret = 3;
        break;
    default:
        MWSFSVM_Error(D_004588D8);
        break;
    }
    return ret;
}

__attribute__((section(".text.func_003470F0")))
int func_003470F0(MwsfdHn *hn)
{
    int ret = 1;

    switch (hn->frm.fmtB) {
    case 2:
        ret = 2;
        break;
    case 3:
        ret = 3;
        break;
    case 1:
        break;
    default:
        MWSFSVM_Error(D_00458900);
        break;
    }
    return ret;
}

__attribute__((section(".text.func_00347160")))
int func_00347160(unsigned int flag)
{
    int ret = 1;

    switch (flag) {
    case 0:
        ret = 0;
        break;
    case 1:
        break;
    default:
        MWSFSVM_Error(D_00458928);
        break;
    }
    return ret;
}

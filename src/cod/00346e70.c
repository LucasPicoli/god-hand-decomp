/* cygnus-2.96 matched TU. */

extern void MWSFSVM_Error(char *s);
extern char D_004588B0[];

__attribute__((section(".text.mwsfsfx_CnvFrmFmtTypeToSfx")))
int mwsfsfx_CnvFrmFmtTypeToSfx(unsigned int fmt)
{
    int ret;

    switch (fmt) {
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
        MWSFSVM_Error(D_004588B0);
        ret = 3;
        break;
    }
    return ret;
}

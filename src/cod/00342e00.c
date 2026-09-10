/* cygnus-2.96 matched TU. */

extern void MWSFSVM_Error(char *s);
extern char D_00457140[];

__attribute__((section(".text.mwsfcre_ConvBufFmtFromMwsfd")))
int mwsfcre_ConvBufFmtFromMwsfd(int fmt)
{
    int ret;

    if (fmt == 1) {
        ret = 1;
    } else if (fmt == 0) {
        ret = 2;
    } else if (fmt == 2) {
        ret = 2;
    } else if (fmt == 3) {
        ret = 3;
    } else {
        MWSFSVM_Error(D_00457140);
        ret = 3;
    }
    return ret;
}

/* cygnus-2.96 matched TU. */

struct ADXT {
    char f0;
    signed char f1;
    char pad2[6];
    void *f8;
    char padC[0x54];
    short f60;
    char pad62[0x32];
    void *f94;
};




__attribute__((section(".text.func_0032CEB0")))
void func_0032CEB0(struct ADXT *adxt)
{
    if (adxt->f8 != 0) {
        if (func_00328098(adxt->f8) == 4) {
            adxt->f60 = -1;
            adxt->f1 = 6;
        }
    }
    if (adxt->f94 != 0) {
        if (func_00335AA0(adxt->f94) == 3) {
            adxt->f60 = -1;
            adxt->f1 = 6;
        }
    }
}

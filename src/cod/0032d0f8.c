/* cygnus-2.96 matched TU. */

struct SJ { char pad[0x28]; void *f28; };
struct ADXT { char pad0[8]; void *f8; char pad[0x88]; struct SJ *f94; };



__attribute__((section(".text.func_0032D0F8")))
int func_0032D0F8(struct ADXT *adxt)
{
    struct SJ *sj;
    void *x;
    if (adxt == 0) return 0;
    if (adxt->f8 == 0) {
        sj = adxt->f94;
        if (sj == 0) return 0;
        x = sj->f28;
        if (x != 0) return func_00328F30(x);
        return 0;
    }
    return func_00328F30(adxt->f8);
}

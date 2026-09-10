/* cygnus-2.96 matched TU. */

extern int sj_hexstr_to_val(char *s);
extern int D_00758400[2];
extern int D_00758500[1];
extern int DTX_CallUrpc(int cmd, void *in, int nin, void *out, int nout);

struct TAG { char *p; int val; };


__attribute__((section(".text.func_0033ADC0")))
void func_0033ADC0(char *tag, struct TAG *out)
{
    out->p = tag + 0x10;
    out->val = sj_hexstr_to_val(tag + 8);
}

__attribute__((section(".text.SJRMT_GetNumData")))
int SJRMT_GetNumData(int a, int b)
{
    D_00758400[0] = a;
    D_00758400[1] = b;
    DTX_CallUrpc(0x29, D_00758400, 2, D_00758500, 1);
    return D_00758500[0];
}

/* cygnus-2.96 matched TU. */

extern int D_00758400[3];
extern int D_00758500[1];
extern int DTX_CallUrpc(int cmd, void *in, int nin, void *out, int nout);

__attribute__((section(".text.SJUNI_CreateRmt")))
int SJUNI_CreateRmt(int a, int b, int c)
{
    D_00758400[0] = a;
    D_00758400[1] = b;
    D_00758400[2] = c;
    DTX_CallUrpc(0x22, D_00758400, 3, D_00758500, 1);
    return D_00758500[0];
}

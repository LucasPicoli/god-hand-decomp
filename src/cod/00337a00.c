extern int D_003E0710;
extern int D_003E0708;
extern int D_003E0750;
extern int D_003E0748[2];
extern int D_003E073C;
extern int D_003E0740;
extern unsigned short D_003E0764;
extern unsigned short D_003E0766;
extern char D_00455668[];
extern int NameTable_getValue(void *name, int *out);
extern int DTX_CallUrpc(int cmd, void *in, int nin, void *out, int nout);

__attribute__((section(".text.func_00337A00")))
void func_00337A00(void)
{
    int in[4];
    int out[4];
    int rate;
    int v;
    int *res;

    if (D_003E0710 != 1 || D_003E0708 > 0) {
        if (NameTable_getValue(D_00455668, &rate) == 0) {
            in[0] = rate;
        } else {
            in[0] = 0xBB80;
        }
        res = &D_003E0750;
        in[1] = D_003E0764;
        in[2] = D_003E0766;
        *res = DTX_CallUrpc(0xC, in, 3, out, 3);
        D_003E073C = 0;
        D_003E0740 = 0;
        D_003E0748[0] = out[1];
        D_003E0748[1] = out[2];
    }
}

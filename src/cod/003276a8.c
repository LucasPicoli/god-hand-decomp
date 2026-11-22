struct ADXT { signed char f0; char pad[0xAB]; };
extern struct ADXT D_003CF9F0[16];
extern void ADXSJD_ExecHndl(struct ADXT *p);

__attribute__((section(".text.func_003276A8")))
void func_003276A8(void)
{
    int i;
    for (i = 0; i < 16; i++)
        if (D_003CF9F0[i].f0 == 1) ADXSJD_ExecHndl(&D_003CF9F0[i]);
}

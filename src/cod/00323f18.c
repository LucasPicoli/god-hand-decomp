/* cygnus-2.96 matched TU. */

extern int D_003E0710;
extern int D_003E0708;
extern int D_003E0738;
extern int D_003E0748[];
extern int DTX_CallUrpc(int a0, int a1, int a2, void *a3, int t0);
extern int GetD003EE078_3463F8(void);
extern void mwrsc_WaitSprDmaEnd(void);
extern void func_00346498(int a0, int a1, void *a2);
extern void func_00346578(void *a0, int a1, int a2);
extern void MWDMA_WaitEnd(int ch);
extern int D_003EE080;
extern int D_00758C80;
extern int D_0075CC80;
extern int D_00451800;
extern int D_00451828;
extern void Forward33B658_33E678(void);
extern void func_00323A00(int *);
extern void Forward33B670_33E690(void);

/* Poll the URPC state once when not locked out: fetch the 8-byte reply into D_003E0748 and mark the poll done. */






__attribute__((section(".text.func_00337C00")))
void func_00337C00(void) {
    int buf[4];
    if (D_003E0710 == 1) {
        if (D_003E0708 <= 0) {
            return;
        }
    }
    if (D_003E0738 != 1) {
        DTX_CallUrpc(0xE, 0, 0, buf, 2);
        D_003E0748[0] = buf[0];
        D_003E0748[1] = buf[1];
        D_003E0738 = 1;
    }
}

/* When the DMA mode is 1 and not yet latched, wait for the engines, queue both 16 KB transfers and latch the mode. */









__attribute__((section(".text.func_003462D8")))
void func_003462D8(void)
{
    int s0;
    int *s1;

    s0 = GetD003EE078_3463F8();
    if (s0 == 1) {
        s1 = &D_003EE080;
        if (*s1 != s0) {
            mwrsc_WaitSprDmaEnd();
            func_00346498(0, 0x4000, &D_00758C80);
            MWDMA_WaitEnd(8);
            func_00346578(&D_0075CC80, 0x4000, 0);
            MWDMA_WaitEnd(9);
            *s1 = s0;
        }
    }
}

/* Open a stream handle: log, then return its size field (handle state 1 or 3 is already open); start the read for a fresh handle. */










__attribute__((section(".text.func_00323F18")))
int func_00323F18(int *a0) {
    func_003228C0(5, 0, a0, -1, -1);
    if (a0 == 0) {
        func_0033F130(&D_00451800);
        return -3;
    }
    {
        signed char v1 = *((signed char*)a0 + 1);
        if (v1 == 1) {
            return a0[5];
        }
        if (v1 == 3) {
            *((char*)a0 + 1) = 1;
            return a0[5];
        }
        if (a0[1] == 0) {
            func_0033F130(&D_00451828);
            return -1;
        }
        func_00328368(a0[1]);
        Forward33B658_33E678();
        a0[8] = func_00328140(a0[1]) - a0[5];
        func_00323A00(a0);
        *((char*)a0 + 1) = 1;
        Forward33B670_33E690();
        func_003228C0(5, 1, a0, -1, -1);
        return a0[5];
    }
}

/* cygnus-2.96 matched TU. */

extern int D_003E0710;
extern int D_003E0708;
extern int D_003E0748[];
extern int DTX_CallUrpc(int a0, int a1, int a2, void *a3, int t0);
extern int (*D_007588B8)(void);
extern void Forward33B568_33B658(void);
extern void Forward33B5C8_33B670(void);
extern void Tramp_003302B0_003302E0(void *a0);
extern char D_00453430;
extern char D_00453450;
extern void func_00331D40(void);
extern void func_003B1F28(char *a0, int a1);
extern void func_00331D78(void);
extern char D_00454130;

__attribute__((section(".text.PS2RNA_FinishIopSnd")))
void PS2RNA_FinishIopSnd(void) {
    int buf[4];
    if (D_003E0710 == 1) {
        if (D_003E0708 <= 0) {
            return;
        }
    }
    DTX_CallUrpc(0xD, 0, 0, buf, 2);
    D_003E0748[0] = buf[0];
    D_003E0748[1] = buf[1];
}

__attribute__((section(".text.SVM_TestAndSet")))
int SVM_TestAndSet(int *a0) {
    int r;
    int t;
    if (D_007588B8 != 0) {
        r = D_007588B8();
    } else {
        Forward33B568_33B658();
        t = *a0;
        *a0 = 1;
        r = ((t ^ 1) != 0);
        Forward33B5C8_33B670();
    }
    return r;
}

__attribute__((section(".text.func_00330CF0")))
int func_00330CF0(int *a0) {
    int s0 = 3;
    if (a0 == 0) {
        Tramp_003302B0_003302E0(&D_00453430);
        return 3;
    }
    {
        int (*fp)(int) = *(int (**)(int))((char *)(*a0) + 0x2C);
        if (fp != 0) {
            s0 = fp(*(int *)((char *)a0 + 4));
        } else {
            Tramp_003302B0_003302E0(&D_00453450);
        }
    }
    return s0;
}

__attribute__((section(".text.SRD_SceOpen")))
int SRD_SceOpen(int a0, int a1) {
    int s0;
    func_00331D40();
    s0 = func_003B4220(a0, a1);
    if (s0 < 0) {
        func_003B1F28(&D_00454130, s0);
    }
    func_00331D78();
    return s0;
}

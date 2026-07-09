/* cygnus-2.96 matched TU. */

extern void Obj33F8_Tramp_0033F130_FCB0(void *a0);
extern void func_0032EF68(void *a0, int a1);
extern int D_00452D10;
extern int Obj3260_Tramp_00338788_D3E0(int a0, int a1);
extern int D_004522B8;
extern int Obj3290_Tramp_0033BF18_9058(void *a0);
extern void func_003288E0(void *a0);
extern int D_003D04C4;
extern int MWSFSVM_Error(void *a0);
extern int D_004575C8, D_004575F8, D_00457620;

/* MATCH via cygnus-2.96 +drop-freorder. */





__attribute__((section(".text.func_0032E090")))
void func_0032E090(int *a0, int a1)
{
    if (a0 == 0) {
        Obj33F8_Tramp_0033F130_FCB0(&D_00452D10);
        return;
    }
    func_0032DC90(a0);
    a0[0x6A] = a1;
    if (*((char *)a0 + 1) == 1) {
        return;
    }
    func_0032EF68(a0, a1);
}

/* MATCH via cygnus-2.96 +drop-freorder. */





__attribute__((section(".text.func_0032AA30")))
int func_0032AA30(int *a0, int a1)
{
    int v;
    if (a0 == 0) {
        return func_0033F130(&D_004522B8);
    }
    *((short *)a0 + 0x20) = a1;
    if (*((signed char *)a0 + 0xAD) == 1) {
        v = func_00327890(a0[1]);
    } else {
        v = 0;
    }
    return Obj3260_Tramp_00338788_D3E0(a0[3], *((short *)a0 + 0x20) + v);
}

/* MATCH via cygnus-2.96 +drop-freorder. */




__attribute__((section(".text.func_00328FA0")))
void func_00328FA0(int *a0)
{
    if (a0[0x14] == 0) {
        return;
    }
    if (a0[2] != 0) {
        return;
    }
    *((char *)a0 + 0x45) = 1;
    do {
        if (Obj3290_Tramp_0033BF18_9058(&D_003D04C4) == 1) {
            func_003288E0(a0);
            D_003D04C4 = 0;
        }
    } while (*((signed char *)a0 + 0x45) != 0);
}

/* MATCH via cygnus-2.96 +drop-freorder. */



__attribute__((section(".text.func_00344278")))
int func_00344278(int *a0)
{
    int r = 1;
    if (a0[0] == 2) {
        MWSFSVM_Error(&D_004575C8);
        r = 0;
    }
    if ((unsigned int)a0[9] >= 3) {
        MWSFSVM_Error(&D_004575F8);
        r = 0;
    }
    if (a0[4] >= 0xF) {
        MWSFSVM_Error(&D_00457620);
        r = 0;
    }
    return r;
}

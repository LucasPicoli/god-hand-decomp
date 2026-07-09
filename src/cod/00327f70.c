/* cygnus-2.96 matched TU. */

extern void func_00327E18(void *a0);
extern void func_0033F590(void);
extern void func_003282D0(void *a0);
extern void Obj3290_Tramp_0033E678_9028(void);
extern int Obj3290_Tramp_0033E690_9040(void);
extern void Obj33F8_Tramp_0033B658_FC70(void);
extern int Obj33F8_Tramp_0033B670_FC88(void);

/* MATCH via cygnus-2.96. */



__attribute__((section(".text.func_00327F70")))
void func_00327F70(void *a0)
{
    func_00327E18(a0);
    do {
        func_0033F590();
    } while (*((signed char *)a0 + 0x45) != 0);
}

/* MATCH via cygnus-2.96. */




__attribute__((section(".text.func_00327FD8")))
int func_00327FD8(char *a0)
{
    char v;
    func_003282D0(a0);
    Obj3290_Tramp_0033E678_9028();
    v = a0[0x49];
    if (v == 1) {
        a0[0x46] = v;
    }
    a0[0x45] = 0;
    return Obj3290_Tramp_0033E690_9040();
}

/* MATCH via cygnus-2.96. */



__attribute__((section(".text.func_0032F470")))
int func_0032F470(int *a0)
{
    Obj33F8_Tramp_0033B658_FC70();
    a0[4] = 0;
    a0[2] = 0;
    a0[3] = 0;
    *((char *)a0 + 1) = 1;
    return Obj33F8_Tramp_0033B670_FC88();
}

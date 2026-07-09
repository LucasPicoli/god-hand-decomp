/* cygnus-2.96 matched TU. */

extern int Obj33F8_Tramp_0033F130_FCB0(void *a0);
extern void Obj33F8_Tramp_0033B658_FC70(void);
extern int Obj33F8_Tramp_0033B670_FC88(void);
extern int D_00452C98;
extern void func_00338A48(void *a0, void *a1);
extern void func_003A52F0(void *a0, int a1, int a2);
extern int D_00455910, D_00455920, D_00455940, D_00455950;
extern void func_00339458(void *a0, void *a1);
extern int D_00455A70, D_00455A80, D_00455AA0, D_00455AB0;
extern void func_0033A048(void *a0, void *a1);
extern int D_00455BC8, D_00455BD8, D_00455BF8, D_00455C08;
extern void func_0033F130(void *a0);
extern void func_00329ED8(void *a0);
extern void Forward33B658_33E678(void);
extern void func_00329B60(void *a0, void *a1);
extern void func_0032B6A0(void *a0, int a1);
extern void Forward33B670_33E690(void);
extern int D_00452038;

/* MATCH via cygnus-2.96 +drop-freorder. */





__attribute__((section(".text.func_0032DFC0")))
int func_0032DFC0(int *a0, int a1, int a2)
{
    if (a0 == 0) {
        return Obj33F8_Tramp_0033F130_FCB0(&D_00452C98);
    }
    Obj33F8_Tramp_0033B658_FC70();
    a0[0x71] = a1;
    a0[0x72] = a1 + a2;
    return Obj33F8_Tramp_0033B670_FC88();
}

/* MATCH via cygnus-2.96 +drop-freorder. */




__attribute__((section(".text.func_00338CD0")))
void func_00338CD0(int *a0)
{
    if (a0 == 0) {
        func_00338A48(&D_00455910, &D_00455920);
        return;
    }
    if (a0[1] == 0) {
        func_00338A48(&D_00455940, &D_00455950);
        return;
    }
    func_003A52F0(a0, 0, 0x24);
    a0[1] = 0;
}

/* MATCH via cygnus-2.96 +drop-freorder. */




__attribute__((section(".text.func_003396F8")))
void func_003396F8(int *a0)
{
    if (a0 == 0) {
        func_00339458(&D_00455A70, &D_00455A80);
        return;
    }
    if (a0[1] == 0) {
        func_00339458(&D_00455AA0, &D_00455AB0);
        return;
    }
    func_003A52F0(a0, 0, 0x40);
    a0[1] = 0;
}

/* MATCH via cygnus-2.96 +drop-freorder. */




__attribute__((section(".text.func_0033A300")))
void func_0033A300(char *a0)
{
    if (a0 == 0) {
        func_0033A048(&D_00455BC8, &D_00455BD8);
        return;
    }
    if (a0[4] == 0) {
        func_0033A048(&D_00455BF8, &D_00455C08);
        return;
    }
    func_003A52F0(a0, 0, 0x30);
    a0[4] = 0;
}

/* MATCH via cygnus-2.96 +drop-freorder. */








__attribute__((section(".text.func_00329D78")))
void func_00329D78(int *a0, void *a1)
{
    if (a0 == 0 || a1 == 0) {
        func_0033F130(&D_00452038);
        return;
    }
    func_00329ED8(a0);
    Forward33B658_33E678();
    *((char *)a0 + 2) = 3;
    func_00329B60(a0, a1);
    func_0032B6A0(a0, 1);
    Forward33B670_33E690();
}

/* cygnus-2.96 matched TU. */

extern void func_0033FB48(int a0);
extern int strlen(const char *a0);
extern void func_00336330(void *a0, void *a1);
extern void Forward33B658_3362E8(void);
extern void Forward33B670_336300(void);
extern int D_004551B8;

/* MATCH via cygnus-2.96 +drop-freorder. */


__attribute__((section(".text.func_0033D278")))
void func_0033D278(int *a0)
{
    if (a0[1] == 3) {
        func_0033FB48(a0[2]);
        a0[35] = 0;
        a0[1] = 0;
    }
}

/* MATCH via cygnus-2.96 +drop-freorder. */


__attribute__((section(".text.func_00333B00")))
int func_00333B00(char *a0)
{
    if (strlen(a0) != 0x11) {
        return 0;
    }
    return a0[8] == 0x2E;
}

/* MATCH via cygnus-2.96 +drop-freorder. */





__attribute__((section(".text.func_00336980")))
void func_00336980(void *a0)
{
    if (a0 == 0) {
        func_00336330(a0, &D_004551B8);
        return;
    }
    Forward33B658_3362E8();
    *((char *)a0 + 1) = 0;
    Forward33B670_336300();
}

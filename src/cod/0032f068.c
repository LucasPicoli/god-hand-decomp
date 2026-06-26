/* cygnus-2.96 matched TU. */

extern void Thunk_func_0033B658(void *sp);
extern void Thunk_func_0033B670(void *sp);
extern int D_003EE278;
extern int isEffectiveVer();
extern int Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2(int *);

__attribute__((section(".text.func_0035B500")))
void func_0035B500(char *a0) {
    char local[0x10];
    volatile int *s0;
    int s1;
    s0 = (volatile int *)(a0 + 0xD30);
    s1 = func_0036C920(D_003EE278);
    Thunk_func_0033B658(local);
    s0[0x2A8/4] = s0[0x2A8/4] + s1;
    s0[0x2CC/4] = s0[0x2CC/4] + s1;
    Thunk_func_0033B670(local);
}

__attribute__((section(".text.func_0032F068")))
void func_0032F068(int *a0, int a1) {
    int *s0;
    int *s1;
    int s2;
    int n;

    s0 = a0;
    s2 = a1;
    n = func_0032F4C8(*(int *)((char *)s0 + 4));
    if (n <= 0) return;
    s1 = s0 + 3;
    s0 = (int *)n;
    do {
        func_0032B660(*s1, s2);
        s1++;
        s0 = (int *)((int)s0 - 1);
    } while (s0 != 0);
}

__attribute__((section(".text.func_0034C748")))
void func_0034C748(char *a0, int a1, int a2, int a3) {
    char local[0x10];
    int *e;

    e = (int *)(a0 + a1 * 116 + 0x1338);
    Thunk_func_0033B658(local);
    e[0] = a2;
    e[1] = a3;
    Thunk_func_0033B670(local);
}

typedef struct {
    int dummy;
    int *pVer;
} CGObj_t_DC60;

typedef struct {
    int field0;
    unsigned char byte0;
} CVerData_t_DC60;

__attribute__((section(".text.func_0035DC60")))
int func_0035DC60(CGObj_t_DC60 *a0, int *a1)
{
    CVerData_t_DC60 *s0;
    int v0;

    *a1 = -1;
    s0 = (CVerData_t_DC60 *)((char *)a0->pVer + 0x80);
    v0 = isEffectiveVer(a0);
    if (!v0) {
        return 0;
    }
    *a1 = s0->byte0;
    return 1;
}

void M2VERR_SetCode(int, int);

__attribute__((section(".text.func_0036DB80")))
void func_0036DB80(int *a0, int *a1) {
    int *s0 = (int *)((char *)a0 + 0x160);
    if (!Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2(a0)) {
        *a1 = *(int *)((char *)s0 + 0x2D4);
        return;
    }
    M2VERR_SetCode(0, 0xFF03020D);
}

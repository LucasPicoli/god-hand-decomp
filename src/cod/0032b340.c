/* cygnus-2.96 matched TU. */

extern void func_0033F130(char *msg);
extern void Forward33B658_33E678(void);
extern void Forward33B670_33E690(void);
extern void Obj3260_Tramp_00338338_D338(int a0, int a1);
extern void func_0032A1B0(void *a0, int a1, int a2);
extern char D_00452630[];
extern int D_003D1408;
extern int D_003D1454;
extern int D_003C7418;

/* cygnus-2.96 candidate. */











__attribute__((section(".text.func_0032B340")))
void func_0032B340(void *a0, int mode)
{
    int x;
    int y;
    int saved;
    int kind;

    if (a0 == 0) {
        func_0033F130(D_00452630);
        return;
    }
    kind = *(signed char *)((char *)a0 + 1);
    if (mode == *(signed char *)((char *)a0 + 0x72)) {
        return;
    }
    Forward33B658_33E678();
    *(signed char *)((char *)a0 + 0x72) = mode;
    if ((unsigned int)(kind - 3) < 2) {
        if (mode == 1) {
            Obj3260_Tramp_00338338_D338(*(int *)((char *)a0 + 0xC), 0);
        } else {
            Obj3260_Tramp_00338338_D338(*(int *)((char *)a0 + 0xC), 1);
            *(int *)((char *)a0 + 0xA0) = D_003C7418;
        }
        saved = D_003D1408;
        D_003D1408 = 0;
        func_0032A1B0(a0, (int)&x, (int)&y);
        D_003D1408 = saved;
        *(unsigned int *)((char *)a0 + 0x9C) =
            (unsigned int)((float)x / (float)y * (float)D_003D1454);
    }
    Forward33B670_33E690();
}

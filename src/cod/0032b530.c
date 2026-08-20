/* cygnus-2.96 matched TU. */

extern int Obj3260_Tramp_003388B0_D468(int a0);
extern void func_0032AF88(void);
extern void func_0032A1B0(void *a0, int a1, int a2);
extern int D_003D1408;
extern int D_003D1454;
extern int D_003C7418;

/* cygnus-2.96 matched TU. */








__attribute__((section(".text.func_0032B530")))
int func_0032B530(void *a0)
{
    int x;
    int y;
    int saved;
    int r;

    if (*(signed char *)((char *)a0 + 0x72) == 0) {
        return 0;
    }
    r = Obj3260_Tramp_003388B0_D468(*(int *)((char *)a0 + 0xC));
    func_0032AF88();
    saved = D_003D1408;
    D_003D1408 = 0;
    func_0032A1B0(a0, (int)&x, (int)&y);
    D_003D1408 = saved;
    *(unsigned int *)((char *)a0 + 0x9C) =
        (unsigned int)((float)x / (float)y * (float)D_003D1454);
    *(int *)((char *)a0 + 0xA0) = D_003C7418;
    return r;
}

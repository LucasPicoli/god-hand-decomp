/* cygnus-2.96 matched TU. */

extern void func_00338A48(void *a0, void *a1);
extern int D_00455990;
extern int D_00455920;
extern int D_004559A0;
extern int D_00455950;

__attribute__((section(".text.func_00338E38")))
void func_00338E38(int *a0, int a1, int a2)
{
    if (a0 == 0) {
        func_00338A48(&D_00455990, &D_00455920);
        return;
    }
    if (a0[1] == 0) {
        func_00338A48(&D_004559A0, &D_00455950);
        return;
    }
    a0[7] = a1;
    a0[8] = a2;
}

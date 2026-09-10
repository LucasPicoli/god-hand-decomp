/* cygnus-2.96 matched TU. */

typedef struct S { char pad0[0x10]; int f10; int f14; } S;


extern int Obj35C0_Set_a1_0_a2_C140(void *h, int a, int b);

__attribute__((section(".text.sftrn_BuildVideo")))
int sftrn_BuildVideo(void *h, S *s)
{
    func_0035C200(h, 1, 2);
    Obj35C0_Set_a1_0_a2_C140(h, 2, 3);
    if (s->f10 != 0) {
        func_0035C200(h, 3, 4);
        Obj35C0_Set_a1_0_a2_C140(h, 4, 5);
        return func_0035C200(h, 5, 6);
    }
    return func_0035C200(h, 3, 6);
}

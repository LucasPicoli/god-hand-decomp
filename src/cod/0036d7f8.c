/* cygnus-2.96 matched TU. */

typedef struct E { void *fn; void *arg; } E;
typedef struct H { int f0; E e; } H;

extern int Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2(H *h);
extern void M2VERR_SetCode(int a, int b);

__attribute__((section(".text.M2V_SetErrFunc")))
void M2V_SetErrFunc(H *h, void *fn, void *arg)
{
    E *e;
    int ok;

    ok = Obj0000_Set_D_0076A5D8_Check_Field_0_EQ_2(h);
    e = &h->e;
    if (ok != 0) {
        M2VERR_SetCode(0, 0xFF030203);
        return;
    }
    e->fn = fn;
    e->arg = arg;
}

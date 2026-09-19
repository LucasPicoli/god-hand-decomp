/* cygnus-2.96 matched TU. */

/* cygnus-2.96 */

typedef struct Tc { int idx; int fps; } Tc;
typedef void (*TcFn)(int, Tc *, int *, int *);

extern int D_00459920[];
extern TcFn D_00459948[][2];


__attribute__((section(".text.SFTIM_Tc2Time")))
void SFTIM_Tc2Time(Tc *tc, int *sec, int *flag)
{
    TcFn fn;

    int arg;

    arg = D_00459920[tc->idx];
    fn = D_00459948[tc->idx][tc->fps];
    if (fn == 0) {
        func_0034DD70(0, 0xFF000221U);
        *sec = 0;
        *flag = 1;
        return;
    }
    fn(arg, tc, sec, flag);
}

/* cygnus-2.96: func_0032E150, returns the active decoder's buffer state for a running stream player. */
#include "godhand/criStm.h"
#include "godhand/globals.h"
extern void Obj33F8_Tramp_0033F130_FCB0(char *msg);
extern int func_0032F570(void *dec);
extern int func_0032F538(void *dec);
extern int func_0032A4A8(void *sj);

__attribute__((section(".text.func_0032E150")))
int func_0032E150(StmPly *p)
{
    int stat;

    if (p == 0) {
        Obj33F8_Tramp_0033F130_FCB0(D_00452D78);
        return -1;
    }
    stat = p->stat;
    if (stat >= 1 && stat <= 3) {
        switch (func_0032F570(p->dec)) {
        case 0:
            return func_0032F538(p->dec);
        case 1:
            return func_0032A4A8(p->sj);
        }
    }
    return 0;
}

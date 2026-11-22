#include "godhand/mwPly.h"
#include "godhand/globals.h"

extern void Obj33F8_Tramp_0033F130_FCB0(char *msg);
extern void func_0032DBA0(MwPly *);
extern void Obj33F8_Tramp_0033B658_FC70(void);
extern void Obj33F8_Tramp_0033B670_FC88(void);
extern int func_003245B0(int, int, char *, int *, int *, int *);
extern int func_003247D0(int);
extern void func_0032F4B0(int, int);

__attribute__((section(".text.func_0032DA78")))
void func_0032DA78(MwPly *o, int a1, int a2)
{
    int v[3];

    if (o == 0) {
        Obj33F8_Tramp_0033F130_FCB0(D_00452AA8);
        return;
    }
    func_0032DBA0(o);
    Obj33F8_Tramp_0033B658_FC70();
    if (func_003245B0(a1, a2, D_00755C40, &v[0], &v[1], &v[2]) == 0) {
        o->unk1D0 = func_003247D0(a1);
        o->sj = o->sjDefault;
        o->unk1D4 = v[0];
        o->unk1D8 = v[1];
        o->unk1DC = v[2];
        func_0032F4B0(o->adx, o->sj);
        o->ownSj = 1;
        o->unk1B2 = 1;
        o->stat = 1;
    }
    Obj33F8_Tramp_0033B670_FC88();
}

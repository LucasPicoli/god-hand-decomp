#include "godhand/mwsfd.h"
extern int Obj34D8_SetGlobalEE0B8_IfField48(void *obj);

__attribute__((section(".text.SFD_SetElementOutSj")))
int SFD_SetElementOutSj(SfdHn *hn, int id, void *sj, int a, int b)
{
    SfdSjTbl *tbl;
    int r;

    r = Obj34D8_SetGlobalEE0B8_IfField48(hn);
    if (r != 0) {
        return func_0034DD70(0, 0xFF000171);
    }
    if ((unsigned int)(id - 0xBC) < 0x44) {
        tbl = hn->ch.sjTbl;
        tbl->unk154 = b;
        tbl->sj[id - 0xBC] = sj;
        tbl->unk150 = a;
    }
    return r;
}

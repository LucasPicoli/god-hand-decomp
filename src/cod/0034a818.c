/* cygnus-2.96: decoder handle update: poll the stream state and error, latch and map errors to
 * 0xFF000C07..09, reset the sub-object at the end states and stop on error or completion. */
#include "godhand/sftim.h"
#include "godhand/globals.h"

typedef struct DecStm {
    int sj;                             /* 0x00 */
    char pad04[0x48 - 0x04];
    int busy;                           /* 0x48 */
} DecStm;

extern int GuardedCall_00329FD0_329F98(int a);
extern int func_0032B0B0(int sj);
extern void Obj35C0_SetField_C_C540(void *obj, int v);
extern void sfadxt_SetTermDst(char *hn, int stop);
extern int sfadxt_GetTermSrc(char *hn);
extern void ADXT_TermSupply(int sj);

__attribute__((section(".text.sfadxt_ChkTermFlg")))
void sfadxt_ChkTermFlg(char *hn, int keep)
{
    void *sub = hn + 0x1020;
    DecStm *st;
    int sj;
    int stat;
    int err;

    st = *(DecStm **)(hn + 0x2004);
    sj = st->sj;
    stat = GuardedCall_00329FD0_329F98(sj);
    err = func_0032B0B0(sj);
    if (err != 0)
        D_00760DAC = err;
    if (GetArrayElemA0C_35A1C8(hn, 0x1A) == 0)
        err = 0;
    switch (err) {
    case 0:
        break;
    case -1:
        func_0034DD70((SftimHn *)hn, 0xFF000C08);
        break;
    case -2:
        func_0034DD70((SftimHn *)hn, 0xFF000C09);
        break;
    default:
        func_0034DD70((SftimHn *)hn, 0xFF000C07);
        break;
    }
    if (stat == 4 || stat == 5)
        Obj35C0_SetField_C_C540(sub, 0);
    if (stat == 5 || err != 0)
        sfadxt_SetTermDst(hn, 1);
    if (sfadxt_GetTermSrc(hn) == 1 && keep == 0) {
        ADXT_TermSupply(sj);
        if (st->busy == 0)
            sfadxt_SetTermDst(hn, 1);
    }
}

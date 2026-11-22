#include "godhand/mwsfd.h"

extern int sfmps_RingGetRead(SfdHn *o, int *a, int *b, int c, int *d);
extern int sfmps_DecodeOneUnit(SfdHn *o, int a, int b, int *n0, int *n1, int d);
extern int sfmps_RingAddRead(SfdHn *o, int n);
extern void sfmps_UpdateFlowCnt(SfdHn *o);

__attribute__((section(".text.sfmps_DecodeSomeUnit")))
int sfmps_DecodeSomeUnit(SfdHn *o)
{
    int a, b, d, n0, n1;
    int err = 0;
    int c = o->unk0028;

    while (o->stop == 0) {
        err = sfmps_RingGetRead(o, &a, &b, c, &d);
        if (err != 0) {
            break;
        }
        err = sfmps_DecodeOneUnit(o, a, b, &n0, &n1, d);
        if (err != 0) {
            break;
        }
        o->total0 += n0;
        o->total1 += n1;
        if (n0 == 0) {
            break;
        }
        err = sfmps_RingAddRead(o, n0);
        if (err != 0) {
            break;
        }
    }
    sfmps_UpdateFlowCnt(o);
    return err;
}

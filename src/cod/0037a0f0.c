/* sn-2.95.3-136: SdeTblTestBlkNoCheck, steps idx by dir (wrapping) through the current column's list until it
 * hits an enabled entry; returns that index, or -1 if none is enabled. */
#include "godhand/sndBank.h"
typedef struct {
    char unk0[7];
    signed char col;
    char unk8[8];
    short count[3]; /* 0x10 */
} MenuColSel;


__attribute__((section(".text.SdeTblTestBlkNoCheck")))
short SdeTblTestBlkNoCheck(MenuColSel *o, short idx, short dir)
{
    short n = o->count[o->col];
    short i;

    for (i = 0; i < n; i++) {
        if (idx <= -1)
            idx = n - 1;
        if (idx >= n)
            idx = 0;
        switch (o->col) {
        case 0:
            if (D_0076DF10[idx].id != 0)
                return idx;
            break;
        case 1:
            if (D_0076E510[idx].id != 0)
                return idx;
            break;
        case 2:
            if ((&D_0076EA50[idx])->num != 0)
                return idx;
            break;
        }
        idx += dir;
    }
    return -1;
}

/* cygnus-2.96: func_0034A0F0, Sofdec ADX track step: compare the two timing positions with the track's
 * count, discard ADX data while ahead or pass the shortfall to func_0034A3E0, then add what was discarded
 * to the handle's total. */
#include "godhand/mwsfd.h"
extern int func_0034A6F8(int a0, int *a1, int *a2);
extern int func_0035A968(void *buf, int ntr);
extern void func_0035AA40(void *a0, int a1, int a2);
extern int func_0035A9C8(int a0, int a1, int *a2);
extern Sint32 sfadxt_AdjDiscard(Sint8 *buf, Sint32 size, Sint32 *pFound);
extern Sint32 ADXT_IsEndcode(Sint8 *adr, Sint32 siz, Sint32 *endsiz);
extern int func_0034A3E0(void *sf, int nch, int len);
extern void func_0034A038(void *a0, int a1, int a2, int *a3);

__attribute__((section(".text.func_0034A0F0")))
void func_0034A0F0(SfdHn *sf, void *data, int len, int *out)
{
    char *buf = (char *)sf + 0xD30;
    char *work = (char *)sf->adxt;
    int nch, ntr, flag, end, tmp;
    int pos0, pos1, d, n, rem, done;

    *out = 0;
    if (func_0034A6F8((int)sf, &nch, &ntr) != 0) {
        *(void **)(work + 0x3C) = func_0034A038;
        return;
    }
    pos0 = func_0035A968(buf, ntr);
    if (pos0 < 0)
        return;
    if (GetArrayElemA0C_35A1C8(sf, 5) == 0) {
        func_0035AA40(buf, pos0, ntr);
        *(void **)(work + 0x3C) = func_0034A038;
        return;
    }
    pos1 = func_0035A9C8((int)buf, ntr, &flag);
    if (pos1 < 0)
        return;
    func_0035AA40(buf, pos1, ntr);
    done = 0;
    d = pos1 - pos0 - *(int *)(work + 0x38);
    if (d >= 0) {
        n = (d >> 5) * nch * 18;
        end = 0;
        if (n > 0) {
            int c = len / (nch * 18) * nch * 18;
            c = (c < n) ? c : n;
            done = sfadxt_AdjDiscard(data, c, &end);
            rem = n - c;
            *(int *)(work + 0x38) += done / (nch * 18) * 32;
        }
        if ((n <= 0 || rem <= 0) && flag) {
            *(void **)(work + 0x3C) = func_0034A038;
            end = ADXT_IsEndcode(data, len, &tmp);
        }
        if (end) {
            func_0035A000(sf, 6, 0);
        }
    } else {
        int nd = -d;
        if (flag) {
            int m = nd / 32 * 32;
            if (m > 0) {
                int r = func_0034A3E0(sf, nch, m);
                *(int *)(work + 0x38) -= r;
                if (m - r > 0)
                    goto out;
            }
            *(void **)(work + 0x3C) = func_0034A038;
        }
    }
out: /* the clean forms (if/else, early return, a flag) were tried and don't match */
    *out = done;
    *(long long *)((char *)sf + 0x9C8) += done;
}


/* cygnus-2.96: Sofdec frame pool queries (0x355508..). */

#include "godhand/sftim.h"

__attribute__((section(".text.SFMPVF_GetNumFrm")))
int SFMPVF_GetNumFrm(SftimHn *hn)
{
    char guard[16];
    SfdWork *w;
    SfdFrm *frm;
    int i;
    int n;

    Thunk_func_0033B658(guard);
    w = hn->work;
    n = 0;
    frm = w->frm;
    for (i = 0; i < w->nfrm; i++, frm++) {
        if ((frm->h.state == 2 || frm->h.state == 4) && frm->f58 == -1) {
            n++;
        }
    }
    if (w->f7C == 1 && n == 0) {
        n = -1;
    }
    Thunk_func_0033B670(guard);
    return n;
}

__attribute__((section(".text.SFMPVF_AllocFrm")))
SfdFrm *SFMPVF_AllocFrm(SftimHn *hn)
{
    char guard[16];
    SfdWork *w;
    SfdFrm *frm;
    int i;
    int n;

    Thunk_func_0033B658(guard);
    w = hn->work;
    n = w->nfrm;
    frm = w->frm;
    for (i = 0; i < n; i++, frm++) {
        if (frm->h.word == 0) {
            frm->h.state = 1;
            break;
        }
    }
    if (i == n) {
        frm = 0;
    }
    Thunk_func_0033B670(guard);
    return frm;
}

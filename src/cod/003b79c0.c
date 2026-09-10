/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */
#include "godhand/gp.h"

typedef struct {
    void (*func)(void *, void *);
    void *arg;
    void *gp;
    int  pad;
} NotifyHandler;

extern NotifyHandler D_00784048[];
extern NotifyHandler *D_003FBEB8;
extern int D_003FBEBC;

__attribute__((section(".text.func_003B79C0")))
void func_003B79C0(int sys, void *arg)
{
    NotifyHandler *h;
    int n;
    void *oldgp;

    if (sys != 0) {
        h = D_00784048;
        n = 0x20;
    } else {
        h = D_003FBEB8;
        n = D_003FBEBC;
    }
    oldgp = GetGp();
    if (n > 0) {
        NotifyHandler *p = h;
        int c = n;
        do {
            if (p->func != 0) {
                SetGp(p->gp);
                p->func(arg, p->arg);
            }
            c = c - 1;
            p = p + 1;
        } while (c != 0);
    }
    SetGp(oldgp);
}

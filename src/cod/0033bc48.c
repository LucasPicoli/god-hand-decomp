/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern struct Ent D_00758620[];
extern volatile int D_003E9970[];

typedef int (*Fp)(int);
struct Ent { Fp fp; int arg; int pad; };




__attribute__((section(".text.SVM_ExecSvrFunc")))
int SVM_ExecSvrFunc(int idx) {
    volatile int *flag = &D_003E9970[idx];
    struct Ent *e = &D_00758620[idx * 6];
    int acc = 0;
    int i = 5;
    do {
        Fp fp = e->fp;
        int arg = e->arg;
        e++;
        if (fp) {
            int r;
            *flag = 1;
            r = fp(arg);
            *flag = 0;
            acc |= r;
        }
    } while (--i >= 0);
    D_003E9950[idx]++;
    return acc;
}

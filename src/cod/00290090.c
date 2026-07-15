/* sn-2.95.3-136 matched TU. */

extern void func_00290000(void *a0);

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"



__attribute__((section(".text.func_00290090")))
void *func_00290090(void *a0) {
    char *p = (char *)a0;
    char *q;
    int i;

    q = p;
    /* `!= -1`, not `>= 0`: retail materialises -1 and closes with `bne`. */
    for (i = 0x3F; i != -1; i--) {
        func_00290000(q);
        q += 0x14;
    }

    *(int *)(p + 0x500) = 0;
    *(int *)(p + 0x504) = 0;
    VU0_SQC2_VF0(p, 0x520);
    *(int *)(p + 0x508) = 0;
    *(int *)(p + 0x50C) = 0;
    return p;
}

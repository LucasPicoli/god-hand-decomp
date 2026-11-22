/* cygnus-2.96: CRI stream-joint object create, 256-entry pool of 0x40-byte objects (0x3395F8), with three init arguments. */
#include "godhand/criSj.h"
#include "godhand/globals.h"

#define SJRBF_POOL_NUM  0x100

extern SjRbf D_003E3FB8[SJRBF_POOL_NUM];
extern int Forward340AE8_339438(void);
extern void func_003397C8(SjRbf *e);

__attribute__((section(".text.func_003395F8")))
SjRbf *func_003395F8(int a, int b, int c)
{
    int i;
    SjRbf *e;
    for (i = 0; i < SJRBF_POOL_NUM; i++) if (D_003E3FB8[i].used == 0) break;
    e = 0;
    if (i != SJRBF_POOL_NUM) {
        e = &D_003E3FB8[i];
        e->used = 1;
        e->vtbl = D_003E3F80;
        e->buf = (Sint8 *)a;
        e->size = b;
        e->extra = c;
        e->uuid = D_00455A50;
        e->err = (void (*)(void *, int))Forward340AE8_339438;
        e->errObj = e;
        func_003397C8(e);
    }
    return e;
}

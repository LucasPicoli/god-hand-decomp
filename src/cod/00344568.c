/* cygnus-2.96: func_00344568, allocates a buffer for a creator handle (own pool or user malloc) and records it. */
#include "godhand/globals.h"
typedef struct {
    char pad0[0x1EC];
    int pool;          /* 0x1EC */
    char pad1F0[0x200 - 0x1F0];
    int nbuf;          /* 0x200 */
    void *buf[0x20];   /* 0x204 */
} MwsfCre;

extern void MWSFSVM_Error(char *msg);
extern void *func_00344610(MwsfCre *c, int size);
extern void *mwsfcre_UsrMalloc(int size);
extern int func_00344770(MwsfCre *c);

__attribute__((section(".text.func_00344568")))
void *func_00344568(MwsfCre *c, int size)
{
    int *pool = &c->pool;
    void *p;

    if (c->nbuf >= 0x20) {
        MWSFSVM_Error(D_00457748);
        return 0;
    }
    if (size < 0)
        return 0;
    if (*pool != 0)
        p = func_00344610(c, size);
    else
        p = mwsfcre_UsrMalloc(size);
    if (p != 0) {
        c->buf[c->nbuf] = p;
        func_00344770(c);
    }
    return p;
}

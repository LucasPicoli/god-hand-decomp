#include "godhand/globals.h"
extern void *cIDBase(void *);

static inline void initIDBase(char *obj)
{
    cIDBase(obj + 0x20);
}

__attribute__((section(".text.func_002BF820")))
void func_002BF820(int init, int priority)
{
    if (priority == 0xFFFF && init)
        initIDBase(D_005F38F0);
}

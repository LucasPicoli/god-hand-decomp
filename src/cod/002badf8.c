#include "godhand/heapArena.h"
extern int _MemoryAlloc(void *, int, void *);

__attribute__((section(".text.func_002BADF8")))
int func_002BADF8(void *unused, void *p)
{
    return _MemoryAlloc(p, 0x10, D_003C3CF0);
}

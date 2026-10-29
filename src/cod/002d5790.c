#include "godhand/heapArena.h"
extern int _MemoryAlloc(void *, int, void *);

__attribute__((section(".text.func_002D5790")))
void func_002D5790(char *self)
{
    *(void **)(self + 0x10) = (void *)_MemoryAlloc(
        (void *)*(int *)(self + 8), 0x10, &D_00754200);
}

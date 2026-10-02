#include "godhand/cSnd.h"
#include "include_asm.h"

extern int D_00747A34;
extern char D_00754C10[];
extern char D_00754220[];
extern void func_003A52F0(void *, int, int);
extern void cSndMemHeap_ResetFirstBlk(void *);
extern int cSndMemHeap_Alloc(int, int);

/* A slot is available when it is unset (-1), has no owner, or its entry is alive. */
__attribute__((section(".text.cSnd_SeIsLoaded")))
int cSnd_SeIsLoaded(cSnd *self, int slot)
{
    cSndSeEntry *e;
    if (slot == -1) return 1;
    e = cSnd_GetSeData(self, slot);
    if (e->owner == -1) return 1;
    e = cSnd_GetSeData(self, slot);
    return cSeData_IsAlive(e);
}

/* Sets up a sound heap that lives in a chunk taken from a parent heap. */
__attribute__((section(".text.cSndMemHeap_OpenSub")))
void cSndMemHeap_OpenSub(cSndMemHeap *heap, cSndMemHeap *parent, int size)
{
    int base;
    heap->self = heap;
    func_003A52F0(heap, 0, sizeof(heap->blk));
    heap->size = size;
    cSndMemHeap_ResetFirstBlk(heap);
    heap->parent = parent;
    base = cSndMemHeap_Alloc(parent, size);
    heap->base = base;
    heap->self->blk[0].top = base;
}


__attribute__((section(".text.Setup_00309028_309028")))
void Setup_00309028_309028(char *a0)
{
    func_003A52F0((int)a0, 0, 0x2E0);
    *(char *)(a0 + 0x8D) = 6;
    *(short *)(a0 + 0x8E) = 5;
    *(unsigned int *)(a0 + 0x4C) = 0x80808080u;
    *(float *)(a0 + 0x7C) = 1.0f;
    *(float *)(a0 + 0x78) = 1.0f;
    *(float *)(a0 + 0x40) = 1.0f;
    *(short *)(a0 + 0xA0) = 0;
    *(short *)(a0 + 0xA2) = 0;
    *(short *)(a0 + 0xA6) = 0;
    *(short *)(a0 + 0xA8) = 0;
    *(short *)(a0 + 0xA4) = 0;
}

__attribute__((section(".text.AllocAndInitSystem_312F00")))
void *AllocAndInitSystem_312F00(void)
{
    void *p;
    if (!(D_00747A34 & 0x10000))
    {
        p = EnsureInitThenForward_2A9538_30EE08(0x1690, 0x10, D_00754C10);
        if (p != 0)
        {
            func_003A52F0(p, 0, 0x1690);
            return func_00107E40(p);
        }
    }
    return 0;
}

__attribute__((section(".text.AllocZeroedAndInit_3130E0")))
void *AllocZeroedAndInit_3130E0(void)
{
    void *p;
    if (!(D_00747A34 & 0x100000))
    {
        p = EnsureInitThenForward_2A9538_30EE08(0x1980, 0x10, D_00754220);
        if (p != 0)
        {
            func_003A52F0(p, 0, 0x1980);
            return func_00201FA0(p);
        }
    }
    return 0;
}

/* sn-2.95.3-136 matched TU. */
#include "godhand/cOmBase.h"
#include "godhand/cSnd.h"

extern int SearchData(int a0, void *a1, int a2);
extern void cModel_setTextureExchange(void *a0, int a1, int a2, int a3);
extern int D_00428A18;
extern void func_003A52F0(void *a0, int a1, int a2);
extern void func_002CD740(void *);
extern void func_002B43B0(void *);
extern void func_002B45E8(void *);
extern char *D_003C23A4;
extern int cDamageManage_ReleaseDamageGive(void *a, void *b);
extern void Tramp_00312708_1B79B0(void *a0);
extern int D_00574380;
extern void func_003870E0(int);

/* cOmBase_setTexChange — sn-2.95.3-136 */



/* Start a texture exchange on this object's model: the new texture is looked up by texKey. */
__attribute__((section(".text.cOmBase_setTexChange")))
void cOmBase_setTexChange(cOmBase *self, int arg) {
    self->texFlags |= 0x10000000;
    cModel_setTextureExchange(self, self->texSet,
        SearchData(self->texKey, &D_00428A18, 0), arg);
}

/* func_002CD668 — sn-2.95.3-136 */


/* Sets up a sound heap that starts at an address and spans a size. Its parent is itself. */
__attribute__((section(".text.func_002CD668")))
void func_002CD668(cSndMemHeap *heap, int start, int size) {
    heap->self = heap;
    func_003A52F0(heap, 0, sizeof(heap->blk));
    heap->size = size;
    func_002CD740(heap);
    heap->parent = heap;
    heap->base = 0;
    heap->self->blk[0].top = start;
}

/* func_002B3B70 — sn-2.95.3-136 */





__attribute__((section(".text.func_002B3B70")))
int func_002B3B70(char *a0) {
    if (func_002AEF90(D_003C23A4) == 0 ||
        func_002B45F8(a0, *(int *)(a0 + 0x8C), 0x8000) == 0)
        func_002B43B0(a0);
    func_002B45E8(a0);
    *(char *)(a0 + 0xC) = 6;
    *(char *)(a0 + 0xD) = 0;
    *(char *)(a0 + 0xE) = 0;
    *(char *)(a0 + 0xF) = 0;
    return 2;
}

/* func_001C8DD8 — sn-2.95.3-136 */
struct VtEnt { short delta; short index; void *pfn; };



__attribute__((section(".text.func_001C8DD8")))
void func_001C8DD8(char *a0) {
    struct VtEnt *vt;
    if (*(int *)(a0 + 0x600) != 0) {
        if (cDamageManage_ReleaseDamageGive(&D_00574380, *(void **)(a0 + 0x600)) != 0) {
            *(int *)(a0 + 0x600) = 0;
            *(int *)(a0 + 0x604) = -1;
        }
    }
    if (*(unsigned char *)(a0 + 0x640) != 0) {
        Tramp_00312708_1B79B0(a0);
        return;
    }
    vt = *(struct VtEnt **)(a0 + 0x214);
    ((void (*)(void *))vt[20].pfn)(a0 + vt[20].delta);
}

/* func_0037A5F0 — sn-2.95.3-136 */



__attribute__((section(".text.func_0037A5F0")))
void func_0037A5F0(char *a0) {
    char *p = a0 + 0xCC;
    int r;
    if (func_00387430(0) != 0) return;
    if (*(int *)(p + 0x40) == 2 && *(signed char *)(p + 0x7) == 0x2F) return;
    r = func_00386FA0(0, p);
    *(int *)(a0 + 0xC) = r;
    if (r == 0) return;
    func_003870E0(0);
}

/* include/godhand/heapArena.h - the memory arenas the allocators carve from (set up at 0x30ECF8). */
#ifndef GODHAND_HEAPARENA_H
#define GODHAND_HEAPARENA_H

typedef struct HeapArena {
    int unk[4];
} HeapArena;                    /* 0x10 */

extern HeapArena *D_003C3CF0;   /* the default arena */
extern HeapArena D_00754200;
extern HeapArena D_00754210;
extern HeapArena D_00754220;
extern HeapArena D_00754230;
extern HeapArena D_00754240;
extern HeapArena D_00754C10;
extern HeapArena D_00754C20;

void func_002A9528(HeapArena *self);    /* constructor: clears the first two words */

extern void Arena_init(HeapArena *a, int base, int size, int a3);

#endif /* GODHAND_HEAPARENA_H */

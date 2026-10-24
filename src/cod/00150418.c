/* sn-2.95.3-136 matched TU. */
#include "godhand/heapArena.h"

extern void func_002A9790(void *list);
extern void cHeap_free(int heap, int *node);
extern int func_002A9860(int list, int cur);
extern int func_002A96C0(int size, int num, int align);
extern void *EnsureInitThenForward_2A9538_30EE08(int a0, int a1, int a2);
extern void func_002A96D8(int *p, int a, int b, int c, int d);
extern void func_002B2080(void *node);
extern void func_002B22E8(void *node, void *prev, void *next, int key, unsigned short serial);

/* A g++ 2.x method table entry: delta and function pointer. */
typedef struct VtEntA {
    short delta;                        /* 0x0 */
    short index;
    void (*pfn)(void *self, int flags); /* 0x4 */
} VtEntA;

typedef struct Child150418 {
    char unk000[0x214];
    VtEntA *vt;                         /* 0x214 */
} Child150418;

#define LIST_CHILD_SIZE  0x220
#define LIST_ALIGN       0x10

typedef struct List150418 {
    int *node;                          /* 0x00 heap node of the list body, 0 when none */
    char unk04[0x14];
    int unk18;                          /* 0x18 child count */
    int unk1C;                          /* 0x1C child count */
    int size;                           /* 0x20 bytes in node */
    int capacity;                       /* 0x24 children node holds */
} List150418;

#define DELETE_FLAG  2                  /* second argument of the deleting destructor */

/* Destroys every child of the list, then the list body and frees its node. */
__attribute__((section(".text.List_destroyChildren")))
void List_destroyChildren(List150418 *self)
{
    Child150418 *child = (Child150418 *)func_002A9860((int)self, 0);
    int *node;
    while (child != 0) {
        Child150418 *next = (Child150418 *)func_002A9860((int)self, (int)child);
        VtEntA *ent = &child->vt[1];
        ent->pfn((char *)child + ent->delta, DELETE_FLAG);
        child = next;
    }
    node = self->node;
    func_002A9790(self);
    if (node != 0) {
        cHeap_free(node[-8], node);
    }
}

/* Empty the list, then give it a fresh heap node for `num` children. */
__attribute__((section(".text.func_001504B0")))
void func_001504B0(List150418 *self, int num)
{
    int size;

    List_destroyChildren(self);
    size = func_002A96C0(LIST_CHILD_SIZE, num, LIST_ALIGN);
    func_002A96D8((int *)self, (int)EnsureInitThenForward_2A9538_30EE08(size, LIST_ALIGN, (int)D_003C3CF0),
                  LIST_CHILD_SIZE, num, LIST_ALIGN);
    self->unk18 = num;
    self->unk1C = num;
    self->capacity = num;
    self->size = size;
}

/* A queue entry; the list is kept sorted by key, highest first. */
typedef struct Entry2AEE40 {
    char unk00[2];
    short key;                          /* 0x02 */
    char unk04[4];
    struct Entry2AEE40 *next;           /* 0x08 */
} Entry2AEE40;

typedef struct Queue2AEE40 {
    char unk000[0x10];
    Entry2AEE40 *head;                  /* 0x010 first entry of the sorted list */
    Entry2AEE40 *freeList;              /* 0x014 unused entries */
    char unk018[0xBD8 - 0x18];
    unsigned short serial;              /* 0xBD8 counts inserts, wraps before 0xFFFF */
} Queue2AEE40;

/* Takes an entry off the free list and links it into the sorted list at the
 * place for `key`. Returns the entry, or 0 when the free list is empty. */
__attribute__((section(".text.Queue_insertSorted")))
Entry2AEE40 *Queue_insertSorted(Queue2AEE40 *self, short key)
{
    Entry2AEE40 *entry = self->freeList;
    Entry2AEE40 *prev;
    Entry2AEE40 *cur;
    if (entry == 0) {
        return 0;
    }
    self->freeList = func_002B2318(entry);
    func_002B2080(entry);
    prev = 0;
    cur = self->head;
    while (cur != 0 && key < cur->key) {
        prev = cur;
        cur = prev->next;
    }
    self->serial++;
    if (self->serial == 0xFFFF) {
        self->serial = 0;
    }
    func_002B22E8(entry, prev, cur, key, self->serial);
    if (prev == 0) {
        self->head = entry;
    }
    return entry;
}

/* One key of a Hermite curve: the value and two more words. */
typedef struct CurveKey {
    float value;                        /* 0x0 */
    float unk4;
    float unk8;
} CurveKey;                             /* 0xC */


extern float func_002AC5B0(void *curve, short t, int idx, CurveKey *keys);

/* Samples the curve at time t: the value between the key found for t and the
 * next one, eased by func_002AC5B0. 0 if t is before the first key. */
__attribute__((section(".text.Curve_sample")))
float Curve_sample(void *curve, short t, int unused, CurveKey *keys)
{
    int idx;
    float result;
    do { } while (0);                   /* loop note: moves the prologue saves to retail's order */
    idx = KeyRec_findSegment(curve, t);
    if (idx >= 0) {
        float ease = func_002AC5B0(curve, t, idx, keys);
        float from;
        do { from = keys[idx].value; } while (0);
        result = from + (keys[idx + 1].value - from) * ease;
    } else {
        result = 0.0f;
    }
    return result;
}

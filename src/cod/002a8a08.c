/* sn-2.95.3-136 matched TU. */

#include "godhand/cGameObj.h"

extern void func_002A8AA8(cGameObjSortEnt *first, int holeIndex, int len, long val, void *tag);
extern void func_002A9098(cGameObjSortEnt *last, long val, void *tag);
extern void func_002A9100(cGameObjSortEnt *first, cGameObjSortEnt *last, void *tag);
extern void func_002A9210(cGameObjSortEnt *first, cGameObjSortEnt *last, void *unused, void *tag);

/* STL __make_heap: sift every parent of [first, last) down with adjust-heap,
 * from the last parent up to the first. */
__attribute__((section(".text.func_002A8B90")))
void func_002A8B90(cGameObjSortEnt *first, cGameObjSortEnt *last, void *tag)
{
    int len = last - first;
    int parent;
    cGameObjSortEnt val;

    if (len < 2)
        return;
    parent = (len - 2) / 2;
    for (;;) {
        val = first[parent];
        func_002A8AA8(first, parent, len, cGameObjSortEnt_pack(&val), tag);
        if (parent == 0)
            return;
        parent--;
    }
}

/* STL __push_heap: float val up from the hole at holeIndex while its parent
 * sorts before it, but not above topIndex. */
__attribute__((section(".text.func_002A8A08")))
void func_002A8A08(cGameObjSortEnt *first, int holeIndex, int topIndex, cGameObjSortEnt val, void *tag)
{
    int parent = (holeIndex - 1) / 2;

    while (holeIndex > topIndex && cGameObjSortEnt_less(first + parent, &val)) {
        first[holeIndex] = first[parent];
        holeIndex = parent;
        parent = (holeIndex - 1) / 2;
    }
    first[holeIndex] = val;
}

/* STL __pop_heap: put the top entry into result, then re-heap [first, last)
 * with val, the old value of result, at the root. */
static __inline__ void cGameObjSortEnt_popHeap(cGameObjSortEnt *first, cGameObjSortEnt *last,
                                               cGameObjSortEnt *result, cGameObjSortEnt val, void *tag)
{
    *result = *first;
    func_002A8AA8(first, 0, last - first, cGameObjSortEnt_pack(&val), tag);
}

/* STL __sort_heap: pop the largest entry off the heap [first, last) to the
 * end until one entry is left. first is read through a pointer, which
 * keeps the separate copy of it that retail passes to the pop. */
__attribute__((section(".text.func_002A8C48")))
void func_002A8C48(cGameObjSortEnt *first, cGameObjSortEnt *last, void *tag)
{
    cGameObjSortEnt **firstRef;
    cGameObjSortEnt top;

    while (last - first > 1) {
        cGameObjSortEnt *end = last;

        last--;
        top = *(end - 1);
        firstRef = &first;
        cGameObjSortEnt_popHeap(*firstRef, end - 1, end - 1, top, tag);
    }
}

/* STL __linear_insert: put *last into the sorted run that starts at first.
 * An entry that sorts before the first one shifts the whole run up by one;
 * any other goes to the unguarded insert. */
static __inline__ void cGameObjSortEnt_linearInsert(cGameObjSortEnt *first, cGameObjSortEnt *last, void *tag)
{
    cGameObjSortEnt val = *last;

    if (cGameObjSortEnt_less(&val, first)) {
        cGameObjSortEnt *src = last;
        cGameObjSortEnt *dst = last + 1;
        int n = last - first;

        while (n > 0) {
            --dst;
            --src;
            *dst = *src;
            --n;
        }
        *first = val;
    } else {
        cGameObjSortEnt copy = val;

        func_002A9098(last, cGameObjSortEnt_pack(&copy), tag);
    }
}

/* STL __insertion_sort: insert each entry after the first into the sorted
 * prefix. first is read through a pointer, which keeps the separate copy of
 * it that retail passes to the insert. */
__attribute__((section(".text.func_002A9100")))
void func_002A9100(cGameObjSortEnt *first, cGameObjSortEnt *last, void *tag)
{
    cGameObjSortEnt *i;
    cGameObjSortEnt **firstRef;

    if (first == last)
        return;
    for (i = first + 1; i != last; ++i) {
        firstRef = &first;
        cGameObjSortEnt_linearInsert(*firstRef, i, tag);
    }
}

/* STL __final_insertion_sort: insertion-sort the first GAMEOBJ_SORT_THRESHOLD
 * entries, then run the unguarded insert over the rest. A short range gets
 * the plain insertion sort. */
__attribute__((section(".text.func_002A9288")))
void func_002A9288(cGameObjSortEnt *first, cGameObjSortEnt *last, void *tag)
{
    cGameObjSortEnt *mid;

    if (last - first > GAMEOBJ_SORT_THRESHOLD) {
        mid = first + GAMEOBJ_SORT_THRESHOLD;
        func_002A9100(first, mid, tag);
        func_002A9210(mid, last, 0, tag);
    } else {
        func_002A9100(first, last, tag);
    }
}

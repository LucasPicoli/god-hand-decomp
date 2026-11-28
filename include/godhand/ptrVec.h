/* include/godhand/ptrVec.h - the object pointer lists (sn code at 0x2DB0D0, 0x30FCC0, 0x3129D0).
 *
 * Each list is a handle holding a pointer to a growable vector of object
 * pointers. Field names are ours; offsets are exact.
 */
#ifndef GODHAND_PTRVEC_H
#define GODHAND_PTRVEC_H

typedef struct PtrVec {
    int unk00;
    void **begin;                       /* 0x04 */
    void **end;                         /* 0x08 one past the last entry */
    void **cap;                         /* 0x0C one past the storage */
} PtrVec;

typedef struct PtrVecRef {
    PtrVec *v;                          /* 0 until the list is allocated */
} PtrVecRef;

/* Entries in the list; 0 before it is allocated. */
static __inline__ unsigned int PtrVecRef_size(PtrVecRef *l)
{
    return l->v ? (unsigned int)(l->v->end - l->v->begin) : 0;
}

/* Entries the storage holds; 0 before it is allocated. */
static __inline__ unsigned int PtrVecRef_capacity(PtrVecRef *l)
{
    PtrVec *v = l->v;
    if (v) {
        void **b = v->begin;
        void **c = v->cap;
        return c - b;
    }
    return 0;
}

/* Nonzero while another entry fits without growing the storage. */
static __inline__ int PtrVecRef_hasRoom(PtrVecRef *l)
{
    return PtrVecRef_size(l) < PtrVecRef_capacity(l);
}

extern PtrVecRef D_00754C30;            /* every registered object */
extern PtrVecRef D_00754C58;            /* every other object */


#endif /* GODHAND_PTRVEC_H */

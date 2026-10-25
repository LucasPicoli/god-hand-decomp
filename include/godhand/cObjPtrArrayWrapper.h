/* include/godhand/cObjPtrArrayWrapper.h - the object-pointer array wrapper (sn code at 0x3129D0..)
 * and the g++ 2.x vector it holds. Field names are ours; offsets are exact.
 */
#ifndef GODHAND_COBJPTRARRAYWRAPPER_H
#define GODHAND_COBJPTRARRAYWRAPPER_H

/* A vector of 4-byte elements. */
typedef struct cPtrVec {
    int *unk0;                  /* 0x0 */
    int *begin;                 /* 0x4 */
    int *finish;                /* 0x8 one past the last element */
    int *capEnd;                /* 0xC */
} cPtrVec;

typedef struct cObjPtrArrayWrapperObj {
    cPtrVec *vec;               /* 0x0 null before the first allocation */
} cObjPtrArrayWrapperObj;

extern void func_00317FF0(cPtrVec *vec, int *pos, int *val);

#endif

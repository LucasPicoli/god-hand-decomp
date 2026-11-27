/* include/godhand/cObjPtrArrayWrapper.h - the object-pointer array wrapper (sn code at 0x3129D0..):
 * the methods on a PtrVecRef that never grow the storage past its capacity.
 */
#ifndef GODHAND_COBJPTRARRAYWRAPPER_H
#define GODHAND_COBJPTRARRAYWRAPPER_H

#include "godhand/ptrVec.h"

/* Append value while the list has room; the new entry, or 0 when full. */
void **cObjPtrArrayWrapper_pushBack(PtrVecRef *self, void *value);

/* Insert value before position while the list has room; the new entry, or 0 when full. */
void **cObjPtrArrayWrapper_insert(PtrVecRef *self, void **position, void *value);

/* The vector's insert with reallocation (g++ 2.x vector<T *>::insert_aux). */
extern void func_00317FF0(PtrVec *vec, void **pos, void **val);

#endif

/* include/godhand/cIDObj.h - the head the id display objects share.
 *
 * An id display object is a cIDBase display that loads its own id resource
 * by name (read once into resHandle). While it runs it keeps two GameWork
 * flag words, saved on entry and put back on exit. The derived objects add
 * their entry pointers from 0x80 on.
 *
 * The class name is ours: retail keeps none for it. Field names are ours,
 * taken from the methods that read and write them. Offsets are exact.
 */
#ifndef GODHAND_CIDOBJ_H
#define GODHAND_CIDOBJ_H

#include "godhand/cIDBase.h"

struct cVtEnt;

typedef struct cIDObj {
    cIDBaseObj base;                    /* 0x00 */
    char unk48[8];
    void *resHandle;                    /* 0x50 the loaded id resource, 0 before the load */
    int readId;                         /* 0x54 disc read job of the load */
    unsigned char busy;                 /* 0x58 nonzero: the manager waits for the object */
    unsigned char unk59;                /* 0x59 */
    signed char state;                  /* 0x5A */
    signed char step;                   /* 0x5B */
    unsigned char unk5C;                /* 0x5C */
    unsigned char unk5D;                /* 0x5D */
    char unk5E[2];
    int result;                         /* 0x60 the code the owner reads, -1 = none */
    unsigned char sel;                  /* 0x64 selection, set by the creator */
    char unk65[3];
    unsigned int flags5D8;              /* 0x68 GameWork.flags5D8 kept while it runs */
    unsigned int flags5E0;              /* 0x6C GameWork.flags5E0 kept while it runs */
    struct cVtEnt *vtable;              /* 0x70 g++ 2.x vtable */
} cIDObj;                               /* 0x74 */

typedef char cIDObj_size_check[sizeof(cIDObj) == 0x74 ? 1 : -1];

#endif

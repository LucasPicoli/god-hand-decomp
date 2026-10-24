/* include/godhand/newlibMalloc.h - newlib mallocr.c chunk types and the bin array (sn code at 0x3AC090..).
 *
 * Names are newlib's; offsets are exact.
 */
#ifndef GODHAND_NEWLIBMALLOC_H
#define GODHAND_NEWLIBMALLOC_H

typedef unsigned int INTERNAL_SIZE_T;

struct malloc_chunk {
    INTERNAL_SIZE_T prev_size;
    INTERNAL_SIZE_T size;
    struct malloc_chunk *fd;
    struct malloc_chunk *bk;
};

typedef struct malloc_chunk *mchunkptr;
typedef struct malloc_chunk *mbinptr;

extern mbinptr D_003FA9D0[];      /* __malloc_av_ */

#endif /* GODHAND_NEWLIBMALLOC_H */

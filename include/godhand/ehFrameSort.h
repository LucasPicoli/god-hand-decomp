/* include/godhand/ehFrameSort.h - the FDE sort records of libgcc frame.c (gcc 2.95.2, 0x321AD0).
 *
 * end_fde_sort splits the collected FDEs into a linear and an erratic list,
 * heap-sorts the erratic one, merges the two and returns the sorted array.
 * The record layouts are frame.c's own.
 */
#ifndef GODHAND_EHFRAMESORT_H
#define GODHAND_EHFRAMESORT_H

typedef int saddr __attribute__ ((mode (pointer)));

struct dwarf_fde {
    unsigned int length;                /* 0x00 */
    int CIE_delta;                      /* 0x04 */
    void *pc_begin;                     /* 0x08 */
    saddr pc_range;                     /* 0x0C */
};
typedef struct dwarf_fde fde;

typedef struct fde_vector {
    fde **array;                        /* 0x00 */
    unsigned int count;                 /* 0x04 */
} fde_vector;

typedef struct fde_accumulator {
    fde_vector linear;                  /* 0x00 */
    fde_vector erratic;                 /* 0x08 */
} fde_accumulator;

/* Ordering function for FDEs: functions can't overlap, so compare the start addresses. */
static __inline__ saddr fde_compare(fde *x, fde *y)
{
    return (saddr)x->pc_begin - (saddr)y->pc_begin;
}

#endif

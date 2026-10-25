/* include/godhand/ehFrameObj.h - libgcc 2.95 frame.c registry record
 * (gcc/frame.h `struct object`; list head D_00755C18).
 */
#ifndef GODHAND_EHFRAMEOBJ_H
#define GODHAND_EHFRAMEOBJ_H

struct dwarf_fde;

struct object {
    void *pc_begin;                     /* 0x00 nonzero once the sorted array was built */
    void *pc_end;                       /* 0x04 */
    struct dwarf_fde *fde_begin;        /* 0x08 key the registration was made with */
    struct dwarf_fde **fde_array;       /* 0x0C sorted array to free */
    unsigned int count;                 /* 0x10 */
    struct object *next;                /* 0x14 */
};

extern struct object *D_00755C18;       /* registered objects (frame.c `objects`) */

#endif

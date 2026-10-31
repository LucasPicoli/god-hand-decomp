/* include/godhand/ehFrameObj.h - libgcc 2.95 frame.c records: the registry
 * record (gcc/frame.h `struct object`; list head D_00755C18), the FDE and CIE
 * views and the frame state frame.c fills in.
 */
#ifndef GODHAND_EHFRAMEOBJ_H
#define GODHAND_EHFRAMEOBJ_H

/* A frame description entry (frame.c `fde`). */
typedef struct dwarf_fde {
    unsigned int length;                /* 0x00 bytes after this word */
    int CIE_delta;                      /* 0x04 back to its CIE, from this field */
    void *pc_begin;                     /* 0x08 */
    void *pc_range;                     /* 0x0C */
} DwarfFde;

/* What extract_cie_info reads out of a CIE (frame.c `cie_info`). */
typedef struct cie_info {
    char *augmentation;                 /* 0x00 */
    void *eh_ptr;                       /* 0x04 */
    int code_align;                     /* 0x08 */
    int data_align;                     /* 0x0C */
    unsigned int ra_regno;              /* 0x10 */
} CieInfo;

/* The frame state __frame_state_for hands back (gcc/frame.h `frame_state`). */
typedef struct frame_state {
    void *cfa;                          /* 0x000 */
    void *eh_ptr;                       /* 0x004 */
    char unk008[0x29A - 0x008];
    unsigned short retaddr_column;      /* 0x29A */
    char unk29C[0x2F0 - 0x29C];
} __attribute__((aligned(8))) FrameState;

/* frame.c's working copy: the state and the one remember_state saves. */
typedef struct frame_state_internal {
    FrameState s;
    struct frame_state_internal *saved_state;  /* 0x2F0 */
} FrameStateInternal;

/* The FDE that covers pc, or 0 (frame.c find_fde; assembly). */
DwarfFde *func_00321F48(void *pc);
/* Read f's CIE into c; returns its first call-frame instruction, or 0 for an
 * unknown augmentation (frame.c extract_cie_info). */
void *func_00322030(DwarfFde *f, CieInfo *c);
/* Run the call-frame instruction at insn on state; with pc, advance *pc by the
 * location ops (frame.c execute_cfa_insn; assembly). */
void *func_00322138(void *insn, FrameStateInternal *state, CieInfo *info, void **pc);
/* The frame state for the code at pc_target, into state_in; 0 when no FDE covers it. */
FrameState *__frame_state_for(void *pc_target, FrameState *state_in);
/* Read an unsigned LEB128 value into *val; returns the byte after it (frame.c decode_uleb128). */
unsigned char *func_00321938(unsigned char *p, int *val);

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

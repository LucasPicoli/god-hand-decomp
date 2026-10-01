/* include/godhand/cOm4f.h - cOm4f, a door-type map object linked to a cOmDoor2.
 *
 * cOm4f keeps its own open/close state at 0x760..0x763 and a pointer to the
 * partner door at 0x790 (set by cOm4f_connectDoor). The sync method drives
 * the partner so both stand open or both stand closed.
 * Offsets are exact; unknown spans stay unkNNN.
 */
#ifndef GODHAND_COM4F_H
#define GODHAND_COM4F_H

typedef struct cOm4f {
    char unk000[0x2F4];
    unsigned char moveCmd;      /* 0x2F4 1 opening, 2 closing */
    char unk2F5[3];
    char unk2F8[0x760 - 0x2F8];
    unsigned char active;       /* 0x760 a move is in progress */
    unsigned char open;         /* 0x761 1 when the door stands open */
    unsigned char lock;         /* 0x762 1 while locked */
    unsigned char eventMode;    /* 0x763 */
    char unk764[0x790 - 0x764];
    void *door;                 /* 0x790 partner cOmDoor2, or 0 */
} cOm4f;

#endif

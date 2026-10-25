/* include/godhand/SfdLibWork.h - the Sofdec library work area (D_003EE270).
 *
 * The area holds a vblank counter, three sub-records the init calls hand to
 * their setup functions (at 0x0, 0xC and 0x10), and the table of the
 * SFD_HN_NUM stream handles from 0x54. A free handle slot is 0. Names are
 * ours. Offsets are exact.
 */
#ifndef GODHAND_SFDLIBWORK_H
#define GODHAND_SFDLIBWORK_H

#define SFD_HN_NUM  8

typedef struct SfdLibWork {
    int vcount;                 /* 0x00 */
    char pad04[0x54 - 0x04];
    void *hn[SFD_HN_NUM];       /* 0x54 */
} SfdLibWork;

extern SfdLibWork D_003EE270;

#endif /* GODHAND_SFDLIBWORK_H */

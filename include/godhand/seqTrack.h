/* include/godhand/seqTrack.h - a sound track and the node fields its table copy fills (sn code at 0x377AC0).
 *
 * A track owns three halfword tables at 0x60, 0x68 and 0x70. The copy routine
 * walks the node pool D_0076CF20 and, for each live kind-2 node owned by the
 * track, loads one entry of each table into the node. This is the node view
 * with the fields that routine writes; seqNode.h has the other view, which
 * keeps them in unk24. Field names are ours; offsets are exact. A field nobody
 * has named yet stays as unkNNN padding.
 */
#ifndef GODHAND_SEQTRACK_H
#define GODHAND_SEQTRACK_H

#define SEQNODE_NUM      48
#define SEQNODE_KIND_LIVE 0x02      /* kind bit: the node is a running sequence */
#define SEQTRACK_PART_A   1         /* part: pairs, entries picked by index / 2 */
#define SEQTRACK_PART_B   2         /* part: one entry by index % 2 */
#define SEQNODE_SUB_A     0x9       /* sub bits set once part A is copied */
#define SEQNODE_SUB_B     0xA       /* sub bits set once part B is copied */

typedef struct SeqNodeCopy {
    unsigned short flags;               /* 0x00 nonzero while in use */
    short unk02;
    char unk04;
    unsigned char kind;                 /* 0x05 */
    unsigned short sub;                 /* 0x06 */
    char unk08[0x0C];
    int owner;                          /* 0x14 track id (same as unk14 in seqNode.h) */
    char unk18[2];
    short index;                        /* 0x1A */
    char unk1C[0x0A];
    unsigned short cfgA;                /* 0x26 */
    unsigned short cfgB;                /* 0x28 */
    char unk2A[2];
    unsigned short cfgC;                /* 0x2C */
    char unk2E[0x22];
} SeqNodeCopy;                          /* 0x50 */

typedef struct SeqTrackTbl {
    char unk00[4];
    int id;                             /* 0x04 */
    char unk08[0x58];
    unsigned short tblA[4];             /* 0x60 */
    unsigned short tblB[4];             /* 0x68 */
    unsigned short tblC[4];             /* 0x70 */
} SeqTrackTbl;

extern SeqNodeCopy D_0076CF20[SEQNODE_NUM];

#endif

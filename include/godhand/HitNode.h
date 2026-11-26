/* include/godhand/HitNode.h - one shape of a hit set.
 *
 * A hit set (src/cod/00137cb8.c) holds an array of 0x38-byte nodes from
 * HITSET_OFFSET_NODE on. HitNode_dispatchByKind picks the point test by the
 * kind bits of flags: kind 0 is a prism over a quad on the XZ plane
 * (HitNode_containsQuadPoint), kinds 2 and 4 are tested by func_002C0C28 and
 * func_002C0CB0. Names are ours; unnamed fields stay as unkNN padding.
 */
#ifndef GODHAND_HITNODE_H
#define GODHAND_HITNODE_H

#define HITNODE_ACTIVE      0x1         /* flags: the node takes part in live tests */
#define HITNODE_KIND_MASK   0x6         /* flags bits 1-2 */
#define HITNODE_KIND_QUAD   0x0         /* corner[] and the yLo..yHi band */

typedef struct HitNodeCorner {
    float x;                            /* 0x0 */
    float z;                            /* 0x4 */
} HitNodeCorner;                        /* 0x8 */

typedef struct HitNode {
    HitNodeCorner corner[4];            /* 0x00 XZ corners, in order around the quad */
    float yLo;                          /* 0x20 bottom of the height band */
    float yHi;                          /* 0x24 top of the height band */
    unsigned char unk28;
    unsigned char flags;                /* 0x29 HITNODE_* */
    char unk2A[2];
    int result;                         /* 0x2C answer when the point is inside */
    char unk30[4];
    int disabled;                       /* 0x34 nonzero: skip this shape */
} HitNode;                              /* 0x38 */

typedef char HitNodeCorner_size_check[sizeof(HitNodeCorner) == 0x8 ? 1 : -1];
typedef char HitNode_size_check[sizeof(HitNode) == 0x38 ? 1 : -1];

#endif

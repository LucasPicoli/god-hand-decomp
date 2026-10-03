/* include/godhand/cNode.h - cNode, one node of the scene graph.
 *
 * A node keeps a name, links to its parent, first child and the two
 * neighbouring siblings, a local scale, a local translation and rotation,
 * and two 4x4 matrices: the local one at 0x50 and the world one at 0xB0.
 * The constructor gives both matrices the identity and attaches the node to
 * its parent. The method table sits at the end of the known part.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field nobody has named yet stays as unkNN padding. The object
 * size is not known, so there is no size check, only the offsets below.
 */
#ifndef GODHAND_CNODE_H
#define GODHAND_CNODE_H

#include "godhand/cOmBase.h"

typedef struct cNode {
    int name;                           /* 0x00 */
    struct cNode *parent;               /* 0x04 */
    struct cNode *child;                /* 0x08 first child */
    struct cNode *prev;                 /* 0x0C previous sibling */
    struct cNode *next;                 /* 0x10 next sibling */
    unsigned char flagA;                /* 0x14 */
    unsigned char flagB;                /* 0x15 */
    unsigned char flagC;                /* 0x16 */
    char unk17[9];
    cVec scale;                         /* 0x20 local scale, 1.0 at construction */
    char unk30[0x20];                   /* 0x30 local translation and rotation, cleared at construction */
    char matLocal[0x40];                /* 0x50 local matrix */
    int unk90;                          /* 0x90 cleared at construction */
    char unk94[0xC];
    char unkA0[0x10];                   /* 0xA0 cleared at construction */
    char matWorld[0x40];                /* 0xB0 world matrix */
    void *vt;                           /* 0xF0 method table */
} cNode;

#endif

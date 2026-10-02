/* include/godhand/cModel.h - the model record every drawn object starts with.
 *
 * cModel derives from cParts, the transform node (a local matrix, a world
 * matrix, a position and a rotation). cModel adds the mesh list, the colour
 * and alpha, the draw kind and the part list built from a SCR_HEADER.
 * cObj, cObjBase and cOmBase derive from cModel and keep this layout at the
 * front of their own records, so one pointer serves all four.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field nobody has named yet stays as unkNNN padding.
 *
 * C has no inheritance, so each class record is one flat run of fields.
 * CPARTS_FIELDS and CMODEL_FIELDS hold the base-class part and a derived
 * header repeats them at the front of its own record.
 */
#ifndef GODHAND_CMODEL_H
#define GODHAND_CMODEL_H

#include "godhand/cOmBase.h"            /* cVec, cMeshNode */

/* A box as centre plus half extents. cModel keeps one around all its meshes. */
typedef struct cBoundingBox {
    float center[3];                    /* 0x00 */
    float half[3];                      /* 0x0C */
} cBoundingBox;                         /* 0x18 */

/* Bits of cParts.partFlags (0x154). */
#define CPARTS_NO_LOCAL     0x08        /* skip the local matrix build */
#define CPARTS_NO_PARENT    0x10        /* skip the multiply by the parent */

/* Bits of cModel.objFlags (0x250). */
#define CMODEL_F_NEAR       0x20        /* parts are rebuilt every frame */
#define CMODEL_F_NO_CALC    0x800       /* the owner builds the matrix itself */
#define CMODEL_F_LATE       0x2000      /* sort into the later draw layers */

/* Bits of cModelNode.dispFlags (0x380). */
#define CMODEL_NODE_HIDE    0x00000001  /* node is not drawn */
#define CMODEL_NODE_ALPHA   0x20000000  /* node blends with the model alpha */
#define CMODEL_NODE_SPECIAL 0x40000000  /* node uses the special draw path */

/* cModel.drawKind: the draw-queue kind a model is sorted into. 0xA picks the
 * kind per node from the node's flags. */
#define CMODEL_KIND_PER_NODE 0xA

/* Draw layer a node of an unforced model sorts into (see cModel_nodeLayer). */
#define CMODEL_LAYER_AUTO   0xFE        /* cModel.layerForce: pick per node */

/* What cModel points at through a node's info pointer: the mesh's header. */
typedef struct cMeshInfo {
    char unk00[8];
    long name;                          /* 0x08 up to 8 chars packed low byte first */
    char unk10[0x24];
    unsigned int flags;                 /* 0x34 */
} cMeshInfo;

/* One mesh of the model's mesh list. A node holds two draw packets, one per
 * frame parity, then its state. cOmBase.h's cMeshNode is the same record with
 * fewer fields named. */
typedef struct cModelNode {
    char packet[2][0xB0];               /* 0x000 draw packet, index = frame parity */
    char unk160[0x220];
    unsigned int dispFlags;             /* 0x380 CMODEL_NODE_* */
    char unk384[0x8];
    float uvScroll[2];                  /* 0x38C */
    char unk394[0xC];
    float color[3];                     /* 0x3A0 r, g, b */
    float alpha;                        /* 0x3AC */
    char unk3B0[0x54];
    struct cModelNode *next;            /* 0x404 */
    char unk408[0x4];
    unsigned char layer;                /* 0x40C */
    char unk40D[0x7];
    cMeshInfo *info;                    /* 0x414 */
} cModelNode;

struct cParts;

#define CPARTS_FIELDS \
    float mtxLocal[16];                 /* 0x000 */ \
    char unk040[0x40]; \
    float mtx[16];                      /* 0x080 world matrix */ \
    cVec invPos;                        /* 0x0C0 */ \
    cVec *anchor;                       /* 0x0D0 normally &mtxLocal[12] */ \
    char unk0D4[0x1C]; \
    cVec *pos;                          /* 0x0F0 normally &mtx[12] */ \
    char unk0F4[0xC]; \
    cVec rot;                           /* 0x100 euler angles */ \
    cVec scale;                         /* 0x110 */ \
    cVec scaleCalc;                     /* 0x120 */ \
    cVec rotAdd;                        /* 0x130 */ \
    unsigned char rotOrder;             /* 0x140 */ \
    char unk141[3]; \
    struct cParts *next;                /* 0x144 on a model the first part, on a part the next */ \
    struct cParts *parent;              /* 0x148 */ \
    struct cParts *link;                /* 0x14C */ \
    char unk150[0x4]; \
    unsigned int partFlags;             /* 0x154 CPARTS_* */ \
    char unk158[0xBC]; \
    void *vtable;                       /* 0x214 */ \
    char unk218[0x8];

typedef struct cParts {
    CPARTS_FIELDS
} cParts;

#define CMODEL_FIELDS \
    CPARTS_FIELDS \
    char *packet[2];                    /* 0x220 the model's own draw packet, index = frame parity */ \
    char unk228[0x18]; \
    cVec tint;                          /* 0x240 rgb, and alpha in w */ \
    int objFlags;                       /* 0x250 CMODEL_F_* */ \
    int texFlags;                       /* 0x254 */ \
    char unk258[0x4]; \
    cModelNode *meshHead;               /* 0x25C */ \
    cBoundingBox box;                   /* 0x260 around every mesh */ \
    struct cOmBase **children;          /* 0x278 */ \
    float blend;                        /* 0x27C */ \
    char unk280[0x4]; \
    int texSet;                         /* 0x284 */ \
    char unk288[0x24]; \
    short id;                           /* 0x2AC */ \
    char unk2AE[0x2]; \
    unsigned char unk2B0; \
    unsigned char meshNum;              /* 0x2B1 */ \
    char unk2B2[0x2]; \
    unsigned char partNum;              /* 0x2B4 */ \
    char unk2B5[0x1]; \
    unsigned char alphaA;               /* 0x2B6 */ \
    unsigned char alphaB;               /* 0x2B7 */ \
    char unk2B8[0x4]; \
    unsigned char alphaC;               /* 0x2BC */ \
    char unk2BD[0x1]; \
    unsigned char layerForce;           /* 0x2BE */ \
    char unk2BF[0x1]; \
    int drawKind;                       /* 0x2C0 */ \
    int drawPrio;                       /* 0x2C4 */ \
    char unk2C8[0x8]; \
    unsigned int actorGroup;            /* 0x2D0 bit for the id range, set by cObj_setId */ \
    unsigned char texSlot[0x10];        /* 0x2D4 */

typedef struct cModel {
    CMODEL_FIELDS
} cModel;                               /* 0x2E4 */

typedef char cModel_size_check[(sizeof(cModel) == 0x2E4) ? 1 : -1];

#endif

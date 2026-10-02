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

/* A box as centre plus half extents: the game's cBoundingBox class. The C
 * name stays free for its constructor, which retail also calls cBoundingBox.
 * cModel keeps one around all its meshes. */
typedef struct cBox {
    float center[3];                    /* 0x00 */
    float half[3];                      /* 0x0C */
} cBox;                                 /* 0x18 */

/* Bits of cParts.partFlags (0x154). */
#define CPARTS_NO_LOCAL     0x08        /* skip the local matrix build */
#define CPARTS_NO_PARENT    0x10        /* skip the multiply by the parent */
#define CPARTS_NO_BLEND     0x100000    /* leave the part out of the blend */

/* Bits of cModel.objFlags (0x250). */
#define CMODEL_F_SHOWN      0x02        /* skip the view test: always drawn */
#define CMODEL_F_NEAR       0x20        /* parts are rebuilt every frame */
#define CMODEL_F_NO_CALC    0x800       /* the owner builds the matrix itself */
#define CMODEL_F_HIDDEN     0x10000     /* never drawn */
#define CMODEL_F_LATE       0x2000      /* sort into the later draw layers */

/* Bits of cModel.texFlags (0x254). */
#define CMODEL_TEX_EXCHANGE 0x10000000  /* nodes take the model's texture exchange table */

/* Bits of cModelNode.dispFlags (0x380). */
#define CMODEL_NODE_HIDE    0x00000001  /* node is not drawn */
#define CMODEL_NODE_BACK    0x01000000  /* node draws in the back layer */
#define CMODEL_NODE_ALPHA   0x20000000  /* node blends with the model alpha */
#define CMODEL_NODE_SPECIAL 0x40000000  /* node uses the special draw path */
#define CMODEL_NODE_SORTED  0x00004080  /* node picks draw kind 2 on a per-node model */

/* Bits of cMeshInfo.flags (0x34). */
#define CMODEL_MESH_TAG     0x00000008  /* sets bit 29 of the node's tag word (0x410) */
#define CMODEL_MESH_HIDDEN  0x00000010  /* the node starts hidden */
#define CMODEL_MESH_TO_SPECIAL 0x00002000 /* gives the node CMODEL_NODE_SPECIAL */
#define CMODEL_MESH_TO_BIT23 0x00100000 /* sets bit 23 of the node's flags */
#define CMODEL_MESH_BACK    0x01000000  /* the mesh draws in the back layer */
#define CMODEL_MESH_SPECIAL 0x00200000  /* mesh draws in the special pass */

/* cModel.drawKind: the draw-queue kind a model is sorted into. 0xA picks the
 * kind per node from the node's flags. */
#define CMODEL_KIND_PER_NODE 0xA

/* Draw layer a node of an unforced model sorts into (see cModel_nodeLayer). */
#define CMODEL_LAYER_AUTO   0xFE        /* cModel.layerForce: pick per node */

/* A mesh descriptor from the model script: what a node's info pointer reaches. */
typedef struct cMeshInfo {
    int dataOfs;                        /* 0x00 offset of the mesh data from this record */
    char unk04[4];
    long name;                          /* 0x08 up to 8 chars packed low byte first */
    char unk10[0x24];
    unsigned int flags;                 /* 0x34 CMODEL_MESH_* */
    char unk38[0xB];
    unsigned char layer;                /* 0x43 */
    char unk44[0x14];
    unsigned char alpha;                /* 0x58 nonzero: the node blends */
} cMeshInfo;

/* What a node's data pointer reaches. */
typedef struct cMeshData {
    char unk00[8];
    unsigned short num;                 /* 0x08 the draw path switches on num >= 2 */
} cMeshData;

/* One mesh of the model's mesh list. A node holds two draw packets, one per
 * frame parity, then its state. cOmBase.h's cMeshNode is the same record with
 * fewer fields named. */
typedef struct cModelNode {
    char packet[2][0xB0];               /* 0x000 draw packet, index = frame parity */
    char unk160[0x220];
    unsigned int dispFlags;             /* 0x380 CMODEL_NODE_* */
    char unk384[0x4];
    struct cMeshData *data;             /* 0x388 */
    float uvScroll[2];                  /* 0x38C */
    char unk394[0xC];
    float color[3];                     /* 0x3A0 r, g, b */
    float alpha;                        /* 0x3AC */
    char unk3B0[0x54];
    struct cModelNode *next;            /* 0x404 */
    char unk408[0x4];
    unsigned char layer;                /* 0x40C */
    char unk40D[0x3];
    unsigned int tag;                   /* 0x410 */
    cMeshInfo *info;                    /* 0x414 */
} cModelNode;

/* One entry of a g++ 2.x vtable: the function, and the offset to add to the
 * object pointer before the call. Entry n sits at vtable + 8 * n. */
typedef struct cVtEnt {
    short delta;                        /* 0x0 */
    short index;                        /* 0x2 */
    void *pfn;                          /* 0x4 */
} cVtEnt;

/* Call virtual method number n of obj, whose record has a vtable pointer. */
#define CVCALL_THIS(obj, n)  ((char *)(obj) + (obj)->vtable[n].delta)
#define CVCALL_FN(obj, n, type) ((type)(obj)->vtable[n].pfn)

/* One part of a model as the script header lists it. */
typedef struct cPartEntry {
    float pos[3];                       /* 0x00 local position */
    short link;                         /* 0x0C part index the part follows, or -1 */
    short parent;                       /* 0x0E parent part index, or -1 for the model */
} cPartEntry;                           /* 0x10 */

/* The head of a model script: where the part table is and how many parts. */
typedef struct cScrHeader {
    char unk00[4];
    int partOfs;                        /* 0x04 offset of the part table from the header */
    unsigned short partNum;             /* 0x08 */
} cScrHeader;

/* The head of a whole model script: the mesh descriptors are found through
 * a table of offsets. */
typedef struct cModelScript {
    char unk00[8];
    unsigned short meshNum;             /* 0x08 */
    char unk0A[6];
    int meshOfs[1];                     /* 0x10 offset of each mesh descriptor from the script */
} cModelScript;

struct cParts;

#define CPARTS_FIELDS \
    float mtxLocal[16];                 /* 0x000 */ \
    float mtxBind[16];                  /* 0x040 */ \
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
    int partFlags;                      /* 0x154 CPARTS_* */ \
    char unk158[0xBC]; \
    cVtEnt *vtable;                     /* 0x214 */ \
    char unk218[0x8];

typedef struct cParts {
    CPARTS_FIELDS
} cParts;

#define CMODEL_FIELDS \
    CPARTS_FIELDS \
    char *packet[2];                    /* 0x220 the model's own draw packet, index = frame parity */ \
    char *tailPacket[2];                /* 0x228 second buffer of each packet pair */ \
    int unk230; \
    int unk234; \
    char *alloc;                        /* 0x238 the block packet, tailPacket and children live in */ \
    char unk23C[0x4]; \
    cVec tint;                          /* 0x240 rgb, and alpha in w */ \
    int objFlags;                       /* 0x250 CMODEL_F_* */ \
    int texFlags;                       /* 0x254 */ \
    int unk258; \
    cModelNode *meshHead;               /* 0x25C */ \
    cBox box;                           /* 0x260 around every mesh */ \
    struct cOmBase **children;          /* 0x278 */ \
    float blend;                        /* 0x27C */ \
    char *script;                       /* 0x280 the model script header */ \
    int texSet;                         /* 0x284 */ \
    int unk288; \
    char *extraPacket[2][2];            /* 0x28C [kind][frame parity] */ \
    char *extraPacketB[2][2];           /* 0x29C [kind][frame parity] */ \
    short id;                           /* 0x2AC */ \
    short life;                         /* 0x2AE */ \
    unsigned char fadeLen;              /* 0x2B0 */ \
    unsigned char meshNum;              /* 0x2B1 */ \
    unsigned short endTime;             /* 0x2B2 */ \
    unsigned char partNum;              /* 0x2B4 */ \
    signed char depthBias;              /* 0x2B5 */ \
    unsigned char alphaA;               /* 0x2B6 */ \
    unsigned char alphaB;               /* 0x2B7 */ \
    float fadeIn;                       /* 0x2B8 */ \
    unsigned char alphaC;               /* 0x2BC */ \
    char unk2BD; \
    unsigned char layerForce;           /* 0x2BE */ \
    char unk2BF[0x1]; \
    int drawKind;                       /* 0x2C0 */ \
    int drawPrio;                       /* 0x2C4 */ \
    void *arena;                        /* 0x2C8 where the packet block is allocated from, or 0 */ \
    char unk2CC[0x4]; \
    unsigned int actorGroup;            /* 0x2D0 bit for the id range, set by cObj_setId */ \
    unsigned char texSlot[0x10];        /* 0x2D4 */

struct cModel {
    CMODEL_FIELDS
};                                      /* 0x2E4 */

/* The constructor of a class is a function with the class's name, and C
 * keeps functions and typedefs in one namespace. A TU that defines or
 * declares that constructor defines CMODEL_NO_TYPEDEF before this include
 * and writes struct cModel. */
#ifndef CMODEL_NO_TYPEDEF
typedef struct cModel cModel;
#endif

typedef char cModel_size_check[(sizeof(struct cModel) == 0x2E4) ? 1 : -1];

/* The model's overall alpha: the tint alpha scaled by the three alpha bytes.
 * 1.0 means fully opaque, which lets a node sort with the opaque ones. */
static __inline__ float cModel_alpha(struct cModel *self) {
    return self->tint.w * (self->alphaA / 255.0f) * (self->alphaB / 255.0f) * (self->alphaC / 255.0f);
}

#endif

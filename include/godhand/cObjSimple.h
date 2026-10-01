/* include/godhand/cObjSimple.h - a simple scenery/prop object.
 *
 * cObjSimple is a game object that owns a model (cModel parts) and, for
 * some props, a cloth pendulum and breast/ring physics. Each frame its
 * Update (func_002B6930) steps the model, the pendulum and the physics.
 * The class is a very large record: only the fields the methods touch are
 * named, the rest is unkNNN padding. Names are ours (the symbol table
 * only gives method names). Offsets are exact.
 */
#ifndef GODHAND_COBJSIMPLE_H
#define GODHAND_COBJSIMPLE_H

#define COBJSIMPLE_STATE_ACTIVE  4   /* state at which the object's virtual hook runs */

typedef struct cObjSimple cObjSimple;

typedef struct cObjSimpleVec3 {
    float x, y, z;
} cObjSimpleVec3;

/* A 16-byte vector (x, y, z, w); w is 1.0 for a position. */
typedef struct cObjSimpleVec {
    float x, y, z, w;
} cObjSimpleVec __attribute__((aligned(16)));

/* A child of the prop is a base-class object: it shares the first fields of cObjSimple. */
typedef struct cObjSimple cObjSimpleChild;

/* g++ 2.x vtable entry: this-adjust and function pointer. */
typedef struct cObjSimpleVtEnt {
    short delta;
    short index;
    void (*pfn)(void *self);
} cObjSimpleVtEnt;

struct cObjSimple {
    char unk000[0x30];
    cObjSimpleVec3 localPos;        /* 0x030 */
    char unk03C[0x80 - 0x3C];
    float mtx[12];                  /* 0x080 world matrix, rows 0 to 2 */
    cObjSimpleVec3 worldPos;        /* 0x0B0 matrix row 3: world position */
    float mtxW;                     /* 0x0BC */
    char unk0C0[0xD0 - 0xC0];
    struct cObjSimpleVec *outPos;   /* 0x0D0 where a prop writes this object's shifted position */
    char unk0D4[0xE0 - 0xD4];
    cObjSimpleVec3 vecE0;           /* 0x0E0 */
    char unk0EC[0xF0 - 0xEC];
    cObjSimpleVec3 *parentPos;      /* 0x0F0 position the object copies each frame */
    char unk0F4[0x100 - 0xF4];
    cObjSimpleVec3 rot;             /* 0x100 angles (x, y, z) */
    char unk10C[0x154 - 0x10C];
    unsigned int flags154;          /* 0x154 */
    char unk158[0x214 - 0x158];
    cObjSimpleVtEnt *vtbl;          /* 0x214 secondary vtable */
    char unk218[0x240 - 0x218];
    cObjSimpleVec3 vec240;          /* 0x240 copied from the parent */
    float f24C;                     /* 0x24C copied from the parent */
    unsigned int flags250;          /* 0x250 bit 4 copied from the parent */
    unsigned int drawFlags;         /* 0x254 bit 28: a texture swap is active */
    char unk258[0x278 - 0x258];
    cObjSimpleChild **children;     /* 0x278 child object table */
    char unk27C[0x2B4 - 0x27C];
    unsigned char childNum;         /* 0x2B4 entries in children[] */
    char unk2B5[0x2F0 - 0x2B5];
    unsigned int flags;             /* 0x2F0 bit 0: reset the swing each frame */
    unsigned char state;            /* 0x2F4 */
    unsigned char stateArg[3];      /* 0x2F5 cleared with state by R0_Init */
    char unk2F8[0x2FE - 0x2F8];
    unsigned short objId;           /* 0x2FE */
    char unk300[4];
    void *model;                    /* 0x304 model data / pack */
    char unk308[0x490 - 0x308];
    cObjSimpleVec3 pos;             /* 0x490 */
    char unk49C[0x4D0 - 0x49C];
    unsigned char texChangeOn;      /* 0x4D0 */
    char unk4D1[3];
    int texChangeIdx;               /* 0x4D4 */
    unsigned char oneBodyFlag;      /* 0x4D8 */
    char unk4D9[3];
    int kageObj;                    /* 0x4DC nonzero: draw the shadow */
    unsigned char parentOn;         /* 0x4E0 nonzero: follow the parent (func_002B6FE8) */
    char unk4E1[0x1390 - 0x4E1];
    unsigned char pendulumOn;       /* 0x1390 */
    char unk1391[3];
    int pendulumId;                 /* 0x1394 */
    char unk1398[0x13A0 - 0x1398];
    char pendulumData[0x2F20 - 0x13A0]; /* 0x13A0 cloth state */
    char clothAnchor[0x2FA0 - 0x2F20];  /* 0x2F20 */
    unsigned char bustFlag;         /* 0x2FA0 */
    char unk2FA1[0x2FB0 - 0x2FA1];
    cObjSimpleVec bustVel;          /* 0x2FB0 bust velocity, kept in the child's local frame */
    float bustSwing;                /* 0x2FC0 bust swing angle rate */
    char unk2FC4[0x2FD0 - 0x2FC4];
    cObjSimpleVec bustPos;          /* 0x2FD0 this frame's anchor position */
    cObjSimpleVec bustPrevPos;      /* 0x2FE0 last frame's */
    unsigned char ringFlag;         /* 0x2FF0 */
    char unk2FF1[0x3000 - 0x2FF1];
    cObjSimpleVec ringPos[2];       /* 0x3000 two ring anchors */
    char unk3020[0x3080 - 0x3020];
    float swing[8];                 /* 0x3080 per-limb swing offset, indexed like the child table */
    float swingAccum;               /* 0x30A0 time-scaled input shared by all limbs */
    int followSel;                  /* 0x30A4 which set of children func_002B6FE8 resets (0 to 5) */
    char unk30A8[0x30B0 - 0x30A8];
    struct cObjSimple *parent;      /* 0x30B0 object (and child of it) this prop is attached to */
    int parentIdx;                  /* 0x30B4 index into parent->children[], or -1 for the parent itself */
    char unk30B8[0x30C0 - 0x30B8];
    cObjSimpleVec3 parentOfsA;      /* 0x30C0 */
    char unk30CC[4];
    cObjSimpleVec3 parentOfsB;      /* 0x30D0 */
};

/* Offset checks: a wrong pad makes one of these array sizes negative. */
#define COBJSIMPLE_OFS(f) ((int)&((cObjSimple *)0)->f)
typedef char cObjSimple_chk_parentPos[COBJSIMPLE_OFS(parentPos) == 0xF0 ? 1 : -1];
typedef char cObjSimple_chk_vtbl[COBJSIMPLE_OFS(vtbl) == 0x214 ? 1 : -1];
typedef char cObjSimple_chk_children[COBJSIMPLE_OFS(children) == 0x278 ? 1 : -1];
typedef char cObjSimple_chk_childNum[COBJSIMPLE_OFS(childNum) == 0x2B4 ? 1 : -1];
typedef char cObjSimple_chk_state[COBJSIMPLE_OFS(state) == 0x2F4 ? 1 : -1];
typedef char cObjSimple_chk_model[COBJSIMPLE_OFS(model) == 0x304 ? 1 : -1];
typedef char cObjSimple_chk_pos[COBJSIMPLE_OFS(pos) == 0x490 ? 1 : -1];
typedef char cObjSimple_chk_pendulum[COBJSIMPLE_OFS(pendulumData) == 0x13A0 ? 1 : -1];
typedef char cObjSimple_chk_bust[COBJSIMPLE_OFS(bustVel) == 0x2FB0 ? 1 : -1];
typedef char cObjSimple_chk_swing[COBJSIMPLE_OFS(swing) == 0x3080 ? 1 : -1];
typedef char cObjSimple_chk_followSel[COBJSIMPLE_OFS(followSel) == 0x30A4 ? 1 : -1];
typedef char cObjSimple_chk_parent[COBJSIMPLE_OFS(parentOfsB) == 0x30D0 ? 1 : -1];
typedef char cObjSimple_chk_rot[COBJSIMPLE_OFS(rot) == 0x100 ? 1 : -1];
typedef char cObjSimple_chk_vec240[COBJSIMPLE_OFS(vec240) == 0x240 ? 1 : -1];
typedef char cObjSimple_chk_draw[COBJSIMPLE_OFS(drawFlags) == 0x254 ? 1 : -1];
typedef char cObjSimple_chk_ring[COBJSIMPLE_OFS(ringFlag) == 0x2FF0 ? 1 : -1];
typedef char cObjSimple_chk_ringPos[COBJSIMPLE_OFS(ringPos) == 0x3000 ? 1 : -1];
typedef char cObjSimple_chk_texIdx[COBJSIMPLE_OFS(texChangeIdx) == 0x4D4 ? 1 : -1];
typedef char cObjSimple_chk_one[COBJSIMPLE_OFS(oneBodyFlag) == 0x4D8 ? 1 : -1];
typedef char cObjSimple_chk_kage[COBJSIMPLE_OFS(kageObj) == 0x4DC ? 1 : -1];
typedef char cObjSimple_chk_pendOn[COBJSIMPLE_OFS(pendulumOn) == 0x1390 ? 1 : -1];

#endif

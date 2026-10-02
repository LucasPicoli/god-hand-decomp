/* include/godhand/cOmBase.h - the base object of the cOm* family.
 *
 * cOmBase is the base class of the cOm* map objects (cOmWeapon derives from
 * it, and its collision bodies are cOmBase records too). One record is at
 * least 0x5E0 bytes; derived classes append their own state after it. The
 * record holds the model handle, the damage state, the object's position (a
 * pointer, because a held object shares its holder's position), four state
 * bytes (mode, phase, step, stepArg) and three groups of flag words.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field nobody has named yet stays as unkNNN padding.
 */
#ifndef GODHAND_COMBASE_H
#define GODHAND_COMBASE_H

/* A position or direction. w is 1.0 for a point and unused for a direction. */
typedef struct cVec {
    float x, y, z, w;
} cVec;

/* Copy x, y and z and leave w alone. Skips the copy when both point at one vector. */
static __inline__ void cVec_copy3(cVec *d, cVec *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

/* One node of the model's mesh list. A model owns a singly linked list of
 * nodes; each node carries the layer it belongs to. */
typedef struct cMeshNode {
    char unk000[0x380];
    unsigned int dispFlags;             /* 0x380 bit 0 hides, bit 13 is set per tag */
    char unk384[0x1C];
    float color[3];                     /* 0x3A0 r, g, b */
    float alpha;                        /* 0x3AC */
    char unk3B0[0x54];
    struct cMeshNode *next;             /* 0x404 */
    char unk408[4];
    unsigned char layer;                /* 0x40C */
} cMeshNode;

/* The hit record that cOmBase_checkDamage receives. */
typedef struct cDamageTake {
    char unk00[0x10];
    cVec dir;                           /* 0x10 hit direction */
    char unk20[0x14];
    char *attacker;                     /* 0x34 the object that dealt the hit */
    char unk38[0xE];
    short kind;                         /* 0x46 attack kind */
    char unk48[4];
    int power;                          /* 0x4C */
    char unk50[0x10];
    unsigned int flags;                 /* 0x60 bit 0 must be set for the hit to count */
} cDamageTake;

/* Bits of cOmBase.hitFlags (0x5B4), set by the hit classifier. */
#define COMBASE_HIT_STRONG    1
#define COMBASE_HIT_PLAYER    2
#define COMBASE_HIT_KNOCKBACK 4

/* Bits of flags0 (0x5B0). Names come from what the methods do with them. */
#define COMBASE_F0_ACTIVE     0x01      /* set once the object is running */
#define COMBASE_F0_GONE       0x02      /* removed: no drops, no hit checks */
#define COMBASE_F0_DROPPED    0x10      /* the item drop already happened */

/* Bits of flags2 (0x5B8). */
#define COMBASE_FLAG_HIDDEN   0x40      /* bit 6 */
#define COMBASE_FLAG_FALL     0x10      /* bit 4 */
#define COMBASE_OBJ_HELD      0x10      /* objFlags bit 4 */

typedef struct cOmBase {
    char unk000[0x80];
    float mtx[16];                          /* 0x080 orientation matrix */
    char unk0C0[0x10];
    cVec *anchor;                           /* 0x0D0 the vector the body is pinned to */
    char unk0D4[0x1C];
    cVec *pos;                              /* 0x0F0 the object's live position */
    char unk0F4[0xC];
    cVec posPrev;                           /* 0x100 position last frame */
    char unk110[0x38];
    struct cOmBase *owner;                  /* 0x148 set on a child body to its weapon */
    char unk14C[0x100];
    float animRate;                         /* 0x24C 1.0 normal */
    int objFlags;                           /* 0x250 bit 4 (0x10) is cleared when a held object is let go */
    int texFlags;                           /* 0x254 bit 28 is set while a texture exchange is active */
    char unk258[0x20];
    struct cOmBase **children;              /* 0x278 child body list, entry 0 is the collision body */
    char unk27C[0x8];
    int texSet;                             /* 0x284 texture set handed to cModel_setTextureExchange */
    char unk288[0x2C];
    unsigned char childNum;                 /* 0x2B4 */
    char unk2B5[0x3F];
    unsigned char mode;                     /* 0x2F4 0x2F4..0x2F7 are the four state bytes the move code writes together */
    unsigned char phase;                    /* 0x2F5 */
    unsigned char step;                     /* 0x2F6 */
    unsigned char stepArg;                  /* 0x2F7 */
    char unk2F8[0x6];
    unsigned short actorId;                 /* 0x2FE actor type id, 0x100..0x1FE is the player range */
    char unk300[0x4];
    int texKey;                             /* 0x304 key searched in the texture table */
    char unk308[0x188];
    cVec posA;                              /* 0x490 position copy used for model sync */
    char unk4A0[0x98];
    long name;                              /* 0x538 object name, up to 8 chars packed low byte first */
    long modelHandle;                       /* 0x540 */
    short hpMax;                            /* 0x548 */
    short hp;                               /* 0x54A */
    float hitFlash;                         /* 0x54C 3.0 right after a hit */
    char unk550[0x10];
    int dropItem;                           /* 0x560 item id this object drops, 0xFFFF for the default drop, 0x9C3 for none */
    int actionId;                           /* 0x564 on a fighter: the current action */
    char unk568[0x48];
    int flags0;                             /* 0x5B0 */
    int hitFlags;                           /* 0x5B4 bits COMBASE_HIT_* */
    int flags2;                             /* 0x5B8 */
    char unk5BC[0x4];
    cVec knock;                             /* 0x5C0 */
    cVec posB;                              /* 0x5D0 */
} cOmBase;

typedef char cOmBase_size_check[(sizeof(cOmBase) == 0x5E0) ? 1 : -1];

/* Child number idx of an object, or 0 when idx is out of range. Writes the
 * child count to *frame, a dead store that retail keeps at the bottom of the
 * stack frame. */
static __inline__ cOmBase *cOmBase_childAt(cOmBase *b, int *frame, int idx)
{
    int n;

    *frame = n = b->childNum;
    if (idx >= 0 && idx < n) {
        return b->children[idx];
    }
    return 0;
}

#endif

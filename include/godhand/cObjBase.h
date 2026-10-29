/* include/godhand/cObjBase.h - the actor with motion, a null-part speed and a shadow.
 *
 * cObjBase derives from cObj. It adds the playing motion, the rotation and
 * speed that the model's null part contributes each frame, and the turn
 * target some actors steer toward. cOmBase derives from cObjBase. This header
 * names the cObjBase fields and repeats the cObj record in front of them
 * (see cObj.h and cModel.h).
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field nobody has named yet stays as unkNNN padding.
 */
#ifndef GODHAND_COBJBASE_H
#define GODHAND_COBJBASE_H

#include "godhand/cObj.h"
#include "godhand/vu0.h"

/* The sequence data of a motion (the game's SEQ_DATA_HEADER_1): starts with
 * "SEQ\0"; its effect block is an {ofs, num} pair at 0x14. */
typedef struct SEQ_DATA_HEADER_1 {
    char magic[4];                      /* 0x00 "SEQ\0" */
    char unk04[0x10];
    unsigned short entryOfs;            /* 0x14 byte offset of the effect entries */
    unsigned short entryNum;            /* 0x16 */
} SEQ_DATA_HEADER_1;

/* One effect the actor starts or stops each time its sequence step runs. */
typedef struct cSeqEffect {
    unsigned char kind;                 /* 0x00 */
    unsigned char id;                   /* 0x01 */
    char unk02[2];
    int handle;                         /* 0x04 */
    unsigned char part;                 /* 0x08 part to attach to, 0xFF for none */
    unsigned char flags;                /* 0x09 SEQEFF_* */
    char unk0A[2];
} cSeqEffect;                           /* 0x0C */

#define SEQEFF_OWNED   0x01             /* the effect belongs to the actor */
#define SEQEFF_SKIP    0x04             /* skip while seqSkip is set */
#define SEQEFF_AT_POS  0x08             /* plays at the actor's position */
#define SEQEFF_KILL    0x80             /* stop the effect instead of starting it */

/* What SetEffect takes to start an effect: tint, scale and flags. Built on the
 * stack with these defaults, then adjusted per call. */
typedef struct cEffectParam {
    cVec color;                         /* 0x00 all 1.0 */
    cVec unk10;                         /* 0x10 zero */
    cVec unk20;                         /* 0x20 zero */
    cVec scale;                         /* 0x30 all 1.0 */
    float size;                         /* 0x40 */
    int unk44;                          /* 0x44 */
    int flags;                          /* 0x48 EFFECT_PARAM_* */
    signed char unk4C;                  /* 0x4C -1 */
    char unk4D;
    char unk4E;
    unsigned char unk4F;                /* 0x4F 0xFF */
    int unk50;                          /* 0x50 */
    char unk54[0xC];
    cVec unk60;                         /* 0x60 zero */
    short unk70;                        /* 0x70 */
    short unk72;                        /* 0x72 */
    char unk74;                         /* 0x74 */
    char unk75[3];
    int unk78;                          /* 0x78 */
    char unk7C[4];
} cEffectParam;                         /* 0x80 */

#define EFFECT_PARAM_LOOP 0x80          /* cEffectParam.flags: the effect repeats */

/* Zero all four components; the same store as cVec_zero in sceVu0.h, which this header
 * cannot include (0013e908.c declares sceVu0ApplyMatrix with other types). */
static __inline__ void cEffectParam_zero(cVec *v) {
    VU0_SQC2_VF0_MEM(v, 0);
}

/* The default effect parameters: white, unit scale and size, nothing set. */
static __inline__ void cEffectParam_init(cEffectParam *p)
{
    cVec_set4(&p->color, 1.0f, 1.0f, 1.0f, 1.0f);
    cEffectParam_zero(&p->unk10);
    cEffectParam_zero(&p->unk20);
    cVec_set4(&p->scale, 1.0f, 1.0f, 1.0f, 1.0f);
    p->size = 1.0f;
    p->unk4C = -1;
    p->unk4F = 0xFF;
    p->unk44 = 0;
    p->flags = 0;
    p->unk4D = 0;
    p->unk4E = 0;
    p->unk50 = 0;
    cEffectParam_zero(&p->unk60);
}

#define COBJBASE_FIELDS \
    COBJ_FIELDS \
    cVec unk310;                        /* 0x310 zero at construction */ \
    cVec unk320; \
    cVec nullSpeed;                     /* 0x330 speed of the null part, in model space */ \
    float quat[4];                      /* 0x340 orientation as a quaternion */ \
    char unk350[0x10]; \
    cVec nullRotSpeed;                  /* 0x360 rotation speed of the null part */ \
    char unk370[0x10]; \
    char unk380[0x10]; \
    char unk390[0x10]; \
    char unk3A0[0xC]; \
    unsigned short seqFlags;            /* 0x3AC Motion_seq_ctr clears it each frame, then ORs in every flag key covering the frame */ \
    unsigned short seqEffectNum;        /* 0x3AE entries in use */ \
    cSeqEffect seqEffect[8];            /* 0x3B0 */ \
    char unk410[0x10];                  /* 0x410 Motion_seq_ctr's own state */ \
    char unk420[0x8]; \
    char *motion;                       /* 0x428 the motion to play */ \
    struct SEQ_DATA_HEADER_1 *seqData;  /* 0x42C the motion's sequence data ("SEQ\0") */ \
    float motionFrame;                  /* 0x430 current frame of the motion */ \
    unsigned short motionFlags;         /* 0x434 */ \
    unsigned char seqSkip;              /* 0x436 while set, SEQEFF_SKIP entries wait */ \
    char unk437[0x1]; \
    float blendLeft;                    /* 0x438 counted down by the step; blend = blendLeft / blendLen */ \
    float blendLen;                     /* 0x43C the blend-in length */ \
    float motionRate;                   /* 0x440 */ \
    float motionStep;                   /* 0x444 frames per tick, negative for reverse play */ \
    char ik[0x4];                       /* 0x448 IK::InverseKinematics reads one float here */ \
    void *shadowData;                   /* 0x44C what KageInit was given */ \
    char *kageWork;                     /* 0x450 two shadow work areas, 0x750 bytes each */ \
    char unk454[0xC]; \
    cVec kageHit;                       /* 0x460 where the shadow ray hit the ground; zero at construction */ \
    float kageHitY;                     /* 0x470 height of that hit */ \
    int groundKind;                     /* 0x474 first halfword of the ground-ray hit; picks the footstep sound */ \
    char unk478[0x8]; \
    cVec unk480;                        /* 0x480 zero at construction */ \
    cVec posA;                          /* 0x490 */ \
    int unk4A0;                         /* 0x4A0 -1 at construction */ \
    int unk4A4; \
    int kageFlags;                      /* 0x4A8 negative: no shadow; bit 0x20000000: skip the distance test */ \
    const char *kindName;               /* 0x4AC class name, set by each constructor */ \
    int unk4B0; \
    int unk4B4; \
    float turnRate;                     /* 0x4B8 */ \
    char unk4BC[0x4]; \
    cVec turnTarget;                    /* 0x4C0 */

struct cObjBase {
    COBJBASE_FIELDS
};                                      /* 0x4D0 */

/* As in cModel.h: the constructor is the function cObjBase, so its TU defines
 * COBJBASE_NO_TYPEDEF before this include and writes struct cObjBase. */
#ifndef COBJBASE_NO_TYPEDEF
typedef struct cObjBase cObjBase;
#endif

/* Byte offset of a cObjBase field, for the few bodies that must form the
 * address by hand to match retail. */
#define COBJBASE_OFFSET(field) ((int)&((struct cObjBase *)0)->field)

#endif

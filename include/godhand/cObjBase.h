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
    char unk3A0[0x80]; \
    char unk420[0x8]; \
    char *motion;                       /* 0x428 the motion to play */ \
    char *motionEnd;                    /* 0x42C */ \
    float motionBlend;                  /* 0x430 */ \
    unsigned short motionFlags;         /* 0x434 */ \
    char unk436[0x2]; \
    float motionStart;                  /* 0x438 */ \
    char unk43C[0x4]; \
    float motionRate;                   /* 0x440 */ \
    char unk444[0x74]; \
    float turnRate;                     /* 0x4B8 */ \
    char unk4BC[0x4]; \
    cVec turnTarget;                    /* 0x4C0 */

typedef struct cObjBase {
    COBJBASE_FIELDS
} cObjBase;                             /* 0x4D0 */

#endif

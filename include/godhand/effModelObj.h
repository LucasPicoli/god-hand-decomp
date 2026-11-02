/* include/godhand/effModelObj.h - the model-owning effect object (sn code at 0x2F1B60..0x2F1D58).
 *
 * An effect object looks up its model data by number, creates a model
 * object for it (self->model), checks the effect resource it plays and,
 * when it carries a group, starts that effect on the model. func_002F1D58
 * fills in the fields from the object's record, then func_002F1B60 builds
 * the model.
 *
 * Field names are ours, from the functions that use them; offsets are exact.
 */
#ifndef GODHAND_EFFMODELOBJ_H
#define GODHAND_EFFMODELOBJ_H

#include "godhand/cGameObj.h"
#include "godhand/cModel.h"           /* cVtEnt */

#define EFFOBJ_MODEL_KIND   0x500     /* CreateObj kind of the model object */
#define EFFOBJ_MODEL_ID     0xFFFF
#define EFFOBJ_MODE_MAX     3         /* modes below this are valid */
#define EFFOBJ_MODE_T32     0x1       /* mode bit: the effect needs its T32 resource */

/* The object's data record (self->rec). */
typedef struct EffObjRec {
    char unk000[0x28C];
    short t32Kind;                      /* 0x28C resource kind of the T32 table */
} EffObjRec;

typedef struct EffModelObj {
    char unk000[0x104];
    unsigned int effFlags;              /* 0x104 copied into the effect parameter */
    char unk108[0x110 - 0x108];
    EffObjRec *rec;                     /* 0x110 */
    char unk114[0x23A - 0x114];
    short effKind;                      /* 0x23A effect kind to start */
    unsigned short effNo;               /* 0x23C effect number */
    char unk23E[0x2B0 - 0x23E];
    cGameObj *model;                    /* 0x2B0 the model object, 0 until created */
    int modelNo;                        /* 0x2B4 which model data to load */
    char unk2B8[0x2DC - 0x2B8];
    unsigned int mode;                  /* 0x2DC EFFOBJ_MODE_* */
    int t32Idx;                         /* 0x2E0 index into the T32 table */
    char unk2E4[4];
    unsigned char effGroup;             /* 0x2E8 non-zero: start an effect on the model */
    char unk2E9[0x300 - 0x2E9];
    float size;                         /* 0x300 */
} EffModelObj;

#endif

/* include/godhand/cCollisionSolid.h - cCollisionSolid, one solid collision
 * body, and cCollisionSolidManage, the manager that keeps each owner's solids.
 *
 * The base constructor (cCollisionSolid) clears the state words, zeroes two
 * vectors, points the vtable word at the base table and sets flag bit 0. The
 * sphere constructor runs it, swaps in the sphere table, stores the body
 * matrix and fills the centre and the radius. The record is at least 0x74
 * bytes; its real size is not known.
 *
 * Retail's names, from its symbol table and type info strings: the classes
 * (cCollisionSolid, cCollisionSolidSphere, cCollisionSolidCapsule,
 * cCollisionSolidBox, cCollisionSolidManage, cCollisionSolidManageUnit), the
 * base constructor cCollisionSolid and its destructor cCollisionSolid__dtor,
 * and the manager's six methods (CreateUnit, CreateSphere, SetActive,
 * SetPriority, ReleaseUnit, ChkHit). The other names are ours: the unit's
 * cCollisionSolidManageUnit_clear, __dtor, _setActive and _setPriority, the
 * three body destructors, cCollisionSolid_constructSphere and
 * cCollisionSolid_updateBounds, like the field names, which come from the
 * methods that read and write them. Offsets are exact: every body that uses
 * this header builds byte-identical to retail. A field we can't name yet
 * stays as unkNN padding.
 */
#ifndef GODHAND_CCOLLISIONSOLID_H
#define GODHAND_CCOLLISIONSOLID_H

#include "godhand/cOmBase.h"

struct cGameObj;
/* Retail's matrix type (CreateSphere__21cCollisionSolidManageP8cGameObjRC7cMatrixRC4cVecf);
 * only pointers to it are used. */
struct cMatrix;

#define CSOLID_STATE_SPHERE  1          /* state: the sphere constructor ran */
#define CSOLID_STATE_BOX     3          /* state of a box body (cCollisionSolidBox) */

#define CSOLID_FLAG_ACTIVE   0x1        /* flags: the solid takes part in hit checks */
#define CSOLID_FLAG_HIT      0x2        /* flags: set on both solids of a touching pair */

/* The g++ 2.x method table of a solid body (0x28 bytes): five 8-byte
 * entries, each a this adjustment, an index and the function. */
typedef struct cCollisionSolidVt {
    short unk00[2];
    void *(*typeInfo)(void);            /* 0x04 the class's type info function */
    short dtorDelta;                    /* 0x08 */
    short dtorIndex;
    void (*dtor)(void *self, int flags); /* 0x0C destructor; flags bit 0 frees the body */
    short unk10[2];
    void (*unk14)(void *self);          /* 0x14 */
    short updateBoundsDelta;            /* 0x18 */
    short updateBoundsIndex;
    void (*updateBounds)(void *self);   /* 0x1C cCollisionSolid_updateBounds for a sphere */
    char unk20[8];                      /* 0x20 zero in every table */
} cCollisionSolidVt;

typedef char cCollisionSolidVt_size_check[(sizeof(cCollisionSolidVt) == 0x28) ? 1 : -1];

/* Method tables, named by the type info function each one holds at 0x04:
 * cCollisionSolid (D_0041D808), cCollisionSolidSphere (D_0041D7E0,
 * __tf21cCollisionSolidSphere), cCollisionSolidCapsule (D_0041D7B8,
 * __tf22cCollisionSolidCapsule) and cCollisionSolidBox (D_0041D790,
 * __tf18cCollisionSolidBox). */
extern const cCollisionSolidVt D_0041D808;
extern const cCollisionSolidVt D_0041D7E0;
extern const cCollisionSolidVt D_0041D7B8;
extern const cCollisionSolidVt D_0041D790;

/* The C function cCollisionSolid is the constructor, so the record type has
 * its own name. */
typedef struct cCollisionSolidObj {
    struct cCollisionSolidObj *next;    /* 0x00 next solid of the unit, cleared by the base constructor */
    int state;                          /* 0x04 CSOLID_STATE_* */
    unsigned int flags;                 /* 0x08 CSOLID_FLAG_*; the constructor sets CSOLID_FLAG_ACTIVE */
    char unk0C[4];
    cVec min;                           /* 0x10 bounds, (0, 0, 0, 1) from the constructor */
    cVec max;                           /* 0x20 */
    const cCollisionSolidVt *vt;        /* 0x30 table of the body kind */
    char unk34[0xC];
    const struct cMatrix *body;         /* 0x40 the body's matrix, as CreateSphere is given it */
    char unk44[0xC];
    cVec center;                        /* 0x50 sphere centre, w zeroed */
    cVec unk60;                         /* 0x60 the centre through the body matrix */
    float radius;                       /* 0x70 sphere radius */
} cCollisionSolidObj;

typedef char cCollisionSolid_min_check[((int)&((cCollisionSolidObj *)0)->min == 0x10) ? 1 : -1];
typedef char cCollisionSolid_body_check[((int)&((cCollisionSolidObj *)0)->body == 0x40) ? 1 : -1];
typedef char cCollisionSolid_radius_check[((int)&((cCollisionSolidObj *)0)->radius == 0x70) ? 1 : -1];

/* Base constructor: no next solid, state 0, both bounds (0, 0, 0, 1), base table, CSOLID_FLAG_ACTIVE. */
cCollisionSolidObj *cCollisionSolid(cCollisionSolidObj *self);
/* Base destructor: put the base table back, free the body when flags bit 0 is set. */
void cCollisionSolid__dtor(cCollisionSolidObj *self, int flags);
/* Destructors of the sphere, the capsule and the box: put the class's table
 * back, then run the base destructor. */
void cCollisionSolidSphere__dtor(cCollisionSolidObj *self, int flags);
void cCollisionSolidCapsule__dtor(cCollisionSolidObj *self, int flags);
void cCollisionSolidBox__dtor(cCollisionSolidObj *self, int flags);
/* Sphere constructor: base constructor, sphere table, body matrix, centre, radius. */
cCollisionSolidObj *cCollisionSolid_constructSphere(cCollisionSolidObj *self, const struct cMatrix *body,
                                                    const cVec *center, float radius);

/* A box in world space, as func_00136A88 tests it (0x60 bytes). The box's
 * bounds method (func_00133BC8, updateBounds in D_0041D790) fills one at
 * 0x180: the centre through the body matrix, a copy of the whole body
 * matrix, and x, y, z from the box's 0x60. */
typedef struct cCollisionSolidBoxWorld {
    cVec center;                        /* 0x00 the box's 0x50 through the body matrix */
    cVec axis[3];                       /* 0x10 rows 0..2 of the body matrix */
    cVec pos;                           /* 0x40 row 3 of the body matrix; func_00136A88 doesn't read it */
    cVec size;                          /* 0x50 x, y and z are read */
} cCollisionSolidBoxWorld;

typedef char cCollisionSolidBoxWorld_size_check[(sizeof(cCollisionSolidBoxWorld) == 0x60) ? 1 : -1];

/* A box collision body: the solid record, the eight corners, bottom face
 * first, then the box in world space. At least 0x1E0 bytes; its real size is
 * not known. */
typedef struct cCollisionSolidBox {
    cCollisionSolidObj base;
    char unk74[0xF0 - 0x74];
    cVec corner[8];                     /* 0xF0 0..3 bottom face, 4..7 top face, in order around */
    char unk170[0x10];
    cCollisionSolidBoxWorld world;      /* 0x180 */
} cCollisionSolidBox;

typedef char cCollisionSolidBox_corner_check[((int)&((cCollisionSolidBox *)0)->corner == 0xF0) ? 1 : -1];
typedef char cCollisionSolidBox_world_check[((int)&((cCollisionSolidBox *)0)->world == 0x180) ? 1 : -1];

/* Do boxes a and b overlap? 0 when they can't touch, else *reach is the
 * centre distance below which they overlap (assembly; the parameters as its
 * callers pass them). */
int func_00136A88(const cCollisionSolidBoxWorld *a, const cCollisionSolidBoxWorld *b, float *reach);
/* The point of box closest to p, into *out (assembly; the parameters as func_00134E18 passes them). */
void func_00137670(const cVec *p, const cCollisionSolidBoxWorld *box, cVec *out);

#define CSOLID_HIT_MAX       32         /* cCollisionSolidManage.hits */

/* One owner's entry in the manager's list, with the owner's solids. Retail's
 * class name, from Q225cCollisionSolidManageUnit9ePRIORITY in CreateUnit's and
 * SetPriority's symbols. CreateUnit allocates it as 0x40 bytes and
 * func_00134430 builds it. */
typedef struct cCollisionSolidManageUnit {
    struct cGameObj *owner;             /* 0x00 */
    cCollisionSolidObj *first;          /* 0x04 its first solid */
    int priority;                       /* 0x08 cCollisionSolidManageUnit::ePRIORITY. 0: never pushed;
                                         * otherwise the higher of the two takes the whole push,
                                         * equal ones split it by share */
    float share;                        /* 0x0C how much of the push it hands a unit of the same priority */
    struct cCollisionSolidManageUnit *next; /* 0x10 */
    char unk14[0xC];
    cVec min;                           /* 0x20 bounds of all its solids, (0, 0, 0, 1) from func_00134430 */
    cVec max;                           /* 0x30 */
} cCollisionSolidManageUnit;

typedef char cCollisionSolidManageUnit_size_check[(sizeof(cCollisionSolidManageUnit) == 0x40) ? 1 : -1];

/* The solid collision manager: the list of units, one per owner, and the
 * owners the last check hit. Its constructor (func_00134650) clears first,
 * the 32 hits and hitNum; it doesn't write unitNum.
 *
 * 0x8C bytes: it holds only pointers and ints (nothing 16-byte aligned), and
 * no instruction reads or writes 0x8C or past it. Its .bss slot (D_00462FC0,
 * up to D_00463050) is 0x90, which fits either size: it only bounds the
 * record to 0x89..0x90. A 0x8C record lands there because the compilers emit
 * it as .comm sym,140,8, so the next object starts at 0x462FC0 + 0x8C rounded
 * up to 8; a 0x90 record would end at the same label. */
typedef struct cCollisionSolidManage {
    cCollisionSolidManageUnit *first;   /* 0x00 */
    int unitNum;                        /* 0x04 */
    struct cGameObj *hits[CSOLID_HIT_MAX]; /* 0x08 owners hit by the last check */
    unsigned int hitNum;                /* 0x88 */
} cCollisionSolidManage;

typedef char cCollisionSolidManage_size_check[(sizeof(cCollisionSolidManage) == 0x8C) ? 1 : -1];

/* The solid collision manager (g_CollSolidManage in the retail symbol table). */
extern cCollisionSolidManage D_00462FC0;

/* Empty the manager: no units, no live solids, no hits. */
void func_00134690(cCollisionSolidManage *self);

/* Unit constructor: owner, priority and share, no solids, no next unit, both bounds (0, 0, 0, 1). */
cCollisionSolidManageUnit *func_00134430(cCollisionSolidManageUnit *self, struct cGameObj *owner,
                                         int priority, float share);
/* Destroy every solid of the unit through its table's destructor. */
void cCollisionSolidManageUnit_clear(cCollisionSolidManageUnit *self);
/* Unit destructor: cCollisionSolidManageUnit_clear, then free the unit when flags bit 0 is set. */
void cCollisionSolidManageUnit__dtor(cCollisionSolidManageUnit *self, int flags);
/* Add a sphere around center, on the body matrix, at the end of the unit's solids. */
void func_00134520(cCollisionSolidManageUnit *self, const struct cMatrix *body, const cVec *center,
                   float radius);
/* Set CSOLID_FLAG_ACTIVE on every solid of the unit (active == 1), or clear it. */
void cCollisionSolidManageUnit_setActive(cCollisionSolidManageUnit *self, int active);
/* Set the unit's priority. */
void cCollisionSolidManageUnit_setPriority(cCollisionSolidManageUnit *self, int priority);
/* The unit of owner, or 0 (assembly). */
cCollisionSolidManageUnit *func_001346C8(cCollisionSolidManage *self, struct cGameObj *owner);
/* Give owner a unit at the end of the list, unless it has one. */
void cCollisionSolidManage_CreateUnit(cCollisionSolidManage *self, struct cGameObj *owner, int priority,
                                      float share);
/* Unlink owner's unit, destroy its solids and free it. */
void cCollisionSolidManage_ReleaseUnit(cCollisionSolidManage *self, struct cGameObj *owner);
/* Add a sphere around center, on the body matrix, to owner's unit. */
void cCollisionSolidManage_CreateSphere(cCollisionSolidManage *self, struct cGameObj *owner,
                                        const struct cMatrix *body, const cVec *center, float radius);
/* Mark every solid of owner's unit active (active == 1) or inactive. */
void cCollisionSolidManage_SetActive(cCollisionSolidManage *self, struct cGameObj *owner, int active);
/* Set the priority of owner's unit (a cCollisionSolidManageUnit::ePRIORITY). */
void cCollisionSolidManage_SetPriority(cCollisionSolidManage *self, struct cGameObj *owner, int priority);

/* Push ua's owner out of box b in the ground plane; 0 when the boxes don't touch. */
int cCollisionSolidManage_pushBoxBox(cCollisionSolidManage *self, cCollisionSolidManageUnit *ua,
                                     cCollisionSolidBox *a, cCollisionSolidManageUnit *ub,
                                     cCollisionSolidBox *b);

/* Nonzero when the bounds amin..amax and bmin..bmax overlap; self isn't read. */
int func_00135250(cCollisionSolidManage *self, float *amin, float *amax, float *bmin, float *bmax);
/* Nonzero when sphere a of unit ua touches sphere b of unit ub (assembly). */
int func_00134CB0(cCollisionSolidManage *self, cCollisionSolidManageUnit *ua, cCollisionSolidObj *a,
                  cCollisionSolidManageUnit *ub, cCollisionSolidObj *b);
/* Nonzero when sphere a of unit ua touches box b of unit ub, pushing ua's
 * owner out (ub's when swapped); swapped is 1 when the box is the solid being checked. */
int func_00134E18(cCollisionSolidManage *self, cCollisionSolidManageUnit *ua, cCollisionSolidObj *a,
                  cCollisionSolidManageUnit *ub, cCollisionSolidBox *b, int swapped);

/* Refresh the bounds of obj's unit, flag every touching pair of its active
 * solids with the active solids of the other units, list up to
 * CSOLID_HIT_MAX owners hit, and return 1 on any hit. */
int cCollisionSolidManage_ChkHit(cCollisionSolidManage *self, struct cGameObj *obj);

/* The line test between two points (assembly); the parameters as its callers pass them. */
int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
            int a7, int a8, int a9, int a10, int a11, int a12);
/* The collision record of a surface ChkCollScrWall hits (retail's name; its layout isn't known). */
struct AK_HIT_INFO;

/* Wall test of obj (its posA to pos) within radius; the hit point goes to hit
 * and the record of the wall hit to *info (assembly, typed from retail's
 * ChkCollScrWall__FR8cGameObjfP4cVecUiPP11AK_HIT_INFOUiPUi). */
int ChkCollScrWall(struct cGameObj *obj, float radius, cVec *hit, unsigned int a2, struct AK_HIT_INFO **info,
                   unsigned int a4, unsigned int *a5);
/* Floor test of obj within range of its position; the hit point goes to hit
 * (assembly; obj and hit as for ChkCollScrWall, the others as its callers pass them). */
int func_001329C0(struct cGameObj *obj, cVec *hit, int a2, void *a3, float range);

#endif

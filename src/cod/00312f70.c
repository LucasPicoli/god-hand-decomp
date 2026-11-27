/* sn-2.95.3-136 matched TU. */

#include "godhand/cObj21C0.h"
#include "godhand/vu0.h"
#include "godhand/cObj20E0.h"

extern void cGameObj(void *self);
extern int D_00747A34;
extern char D_00754C10[];
extern void *_MemoryAlloc(int size, int align, void *region);
extern void cObjBase(void *self);

/* sn-2.95.3-136, cloned from CreateObjectWithVtableA. */




extern char D_00448890[];               /* method table of this 0x21C0 class */


/* The tail vector is stored through the object base with its offset in the
 * instruction, as retail does; obj->tail as the base costs a register. */
#define COBJ21C0_TAIL_OFS   ((int)&((cObj21C0 *)0)->tail)   /* 0x2190 */

/* Allocates and zeroes a 0x21C0-byte game object, runs the cGameObj
 * constructor, sets its method table and zeroes the vectors of its 44
 * records and its tail. 0 when the allocator is locked or full. */
__attribute__((section(".text.ObjFactory_create27A")))
void *ObjFactory_create27A(void)
{
    cObj21C0 *obj;
    cObj21C0 *self;
    cObj21C0Ent *e;
    int i;

    if (D_00747A34 & COBJ21C0_NO_NEW)
        goto none;
    obj = _MemoryAlloc(COBJ21C0_SIZE, COBJ21C0_ALIGN, D_00754220);
    if (obj == 0)
        goto none;
    func_003A52F0(obj, 0, COBJ21C0_SIZE);
    self = obj;
    cGameObj(self);
    self->vt = D_00448890;
    e = self->ent;
    for (i = COBJ21C0_ENT_NUM - 1; i != -1; i--) {
        VU0_SQC2_VF0(e, 0x00);
        VU0_SQC2_VF0(e, 0x10);
        VU0_SQC2_VF0(e, 0x30);
        VU0_SQC2_VF0(e, 0x40);
        VU0_SQC2_VF0(e, 0x50);
        VU0_SQC2_VF0(e, 0x80);
        e++;
    }
    VU0_SQC2_VF0(obj, COBJ21C0_TAIL_OFS);
    return obj;
none:
    /* Dead store: it puts self's last reference after obj's, so cse keeps
     * self for the constructor and obj for the return, as retail does. The
     * early-return form without it merges the two registers. */
    self = 0;
    return 0;
}

/* sn-2.95.3-136, cloned from CreateObjectWithVtableA. */




extern char D_00447AD0[];               /* method table of this 0x21C0 class */


/* The tail vector is stored through the object base with its offset in the
 * instruction, as retail does; obj->tail as the base costs a register. */
#define COBJ21C0_TAIL_OFS   ((int)&((cObj21C0 *)0)->tail)   /* 0x2190 */

/* Allocates and zeroes a 0x21C0-byte game object, runs the cGameObj
 * constructor, sets its method table and zeroes the vectors of its 44
 * records and its tail. 0 when the allocator is locked or full. */
__attribute__((section(".text.ObjFactory_create212")))
void *ObjFactory_create212(void)
{
    cObj21C0 *obj;
    cObj21C0 *self;
    cObj21C0Ent *e;
    int i;

    if (D_00747A34 & COBJ21C0_NO_NEW)
        goto none;
    obj = _MemoryAlloc(COBJ21C0_SIZE, COBJ21C0_ALIGN, D_00754220);
    if (obj == 0)
        goto none;
    func_003A52F0(obj, 0, COBJ21C0_SIZE);
    self = obj;
    cGameObj(self);
    self->vt = D_00447AD0;
    e = self->ent;
    for (i = COBJ21C0_ENT_NUM - 1; i != -1; i--) {
        VU0_SQC2_VF0(e, 0x00);
        VU0_SQC2_VF0(e, 0x10);
        VU0_SQC2_VF0(e, 0x30);
        VU0_SQC2_VF0(e, 0x40);
        VU0_SQC2_VF0(e, 0x50);
        VU0_SQC2_VF0(e, 0x80);
        e++;
    }
    VU0_SQC2_VF0(obj, COBJ21C0_TAIL_OFS);
    return obj;
none:
    /* Dead store: it puts self's last reference after obj's, so cse keeps
     * self for the constructor and obj for the return, as retail does. The
     * early-return form without it merges the two registers. */
    self = 0;
    return 0;
}

/* sn-2.95.3-136, cloned from CreateObjectWithVtableA. */




extern char D_00447F70[];               /* method table of this 0x21C0 class */


/* The tail vector is stored through the object base with its offset in the
 * instruction, as retail does; obj->tail as the base costs a register. */
#define COBJ21C0_TAIL_OFS   ((int)&((cObj21C0 *)0)->tail)   /* 0x2190 */

/* Allocates and zeroes a 0x21C0-byte game object, runs the cGameObj
 * constructor, sets its method table and zeroes the vectors of its 44
 * records and its tail. 0 when the allocator is locked or full. */
__attribute__((section(".text.ObjFactory_create253")))
void *ObjFactory_create253(void)
{
    cObj21C0 *obj;
    cObj21C0 *self;
    cObj21C0Ent *e;
    int i;

    if (D_00747A34 & COBJ21C0_NO_NEW)
        goto none;
    obj = _MemoryAlloc(COBJ21C0_SIZE, COBJ21C0_ALIGN, D_00754220);
    if (obj == 0)
        goto none;
    func_003A52F0(obj, 0, COBJ21C0_SIZE);
    self = obj;
    cGameObj(self);
    self->vt = D_00447F70;
    e = self->ent;
    for (i = COBJ21C0_ENT_NUM - 1; i != -1; i--) {
        VU0_SQC2_VF0(e, 0x00);
        VU0_SQC2_VF0(e, 0x10);
        VU0_SQC2_VF0(e, 0x30);
        VU0_SQC2_VF0(e, 0x40);
        VU0_SQC2_VF0(e, 0x50);
        VU0_SQC2_VF0(e, 0x80);
        e++;
    }
    VU0_SQC2_VF0(obj, COBJ21C0_TAIL_OFS);
    return obj;
none:
    /* Dead store: it puts self's last reference after obj's, so cse keeps
     * self for the constructor and obj for the return, as retail does. The
     * early-return form without it merges the two registers. */
    self = 0;
    return 0;
}

/* sn-2.95.3-136, cloned from CreateObjectWithVtableA. */




extern char D_00448028[];               /* method table of this 0x21C0 class */


/* The tail vector is stored through the object base with its offset in the
 * instruction, as retail does; obj->tail as the base costs a register. */
#define COBJ21C0_TAIL_OFS   ((int)&((cObj21C0 *)0)->tail)   /* 0x2190 */

/* Allocates and zeroes a 0x21C0-byte game object, runs the cGameObj
 * constructor, sets its method table and zeroes the vectors of its 44
 * records and its tail. 0 when the allocator is locked or full. */
__attribute__((section(".text.ObjFactory_create257")))
void *ObjFactory_create257(void)
{
    cObj21C0 *obj;
    cObj21C0 *self;
    cObj21C0Ent *e;
    int i;

    if (D_00747A34 & COBJ21C0_NO_NEW)
        goto none;
    obj = _MemoryAlloc(COBJ21C0_SIZE, COBJ21C0_ALIGN, D_00754220);
    if (obj == 0)
        goto none;
    func_003A52F0(obj, 0, COBJ21C0_SIZE);
    self = obj;
    cGameObj(self);
    self->vt = D_00448028;
    e = self->ent;
    for (i = COBJ21C0_ENT_NUM - 1; i != -1; i--) {
        VU0_SQC2_VF0(e, 0x00);
        VU0_SQC2_VF0(e, 0x10);
        VU0_SQC2_VF0(e, 0x30);
        VU0_SQC2_VF0(e, 0x40);
        VU0_SQC2_VF0(e, 0x50);
        VU0_SQC2_VF0(e, 0x80);
        e++;
    }
    VU0_SQC2_VF0(obj, COBJ21C0_TAIL_OFS);
    return obj;
none:
    /* Dead store: it puts self's last reference after obj's, so cse keeps
     * self for the constructor and obj for the return, as retail does. The
     * early-return form without it merges the two registers. */
    self = 0;
    return 0;
}

/* sn-2.95.3-136, cloned from CreateObjectWithVtableA. */




extern char D_00448948[];               /* method table of this 0x21C0 class */


/* The tail vector is stored through the object base with its offset in the
 * instruction, as retail does; obj->tail as the base costs a register. */
#define COBJ21C0_TAIL_OFS   ((int)&((cObj21C0 *)0)->tail)   /* 0x2190 */

/* Allocates and zeroes a 0x21C0-byte game object, runs the cGameObj
 * constructor, sets its method table and zeroes the vectors of its 44
 * records and its tail. 0 when the allocator is locked or full. */
__attribute__((section(".text.ObjFactory_create27F")))
void *ObjFactory_create27F(void)
{
    cObj21C0 *obj;
    cObj21C0 *self;
    cObj21C0Ent *e;
    int i;

    if (D_00747A34 & COBJ21C0_NO_NEW)
        goto none;
    obj = _MemoryAlloc(COBJ21C0_SIZE, COBJ21C0_ALIGN, D_00754220);
    if (obj == 0)
        goto none;
    func_003A52F0(obj, 0, COBJ21C0_SIZE);
    self = obj;
    cGameObj(self);
    self->vt = D_00448948;
    e = self->ent;
    for (i = COBJ21C0_ENT_NUM - 1; i != -1; i--) {
        VU0_SQC2_VF0(e, 0x00);
        VU0_SQC2_VF0(e, 0x10);
        VU0_SQC2_VF0(e, 0x30);
        VU0_SQC2_VF0(e, 0x40);
        VU0_SQC2_VF0(e, 0x50);
        VU0_SQC2_VF0(e, 0x80);
        e++;
    }
    VU0_SQC2_VF0(obj, COBJ21C0_TAIL_OFS);
    return obj;
none:
    /* Dead store: it puts self's last reference after obj's, so cse keeps
     * self for the constructor and obj for the return, as retail does. The
     * early-return form without it merges the two registers. */
    self = 0;
    return 0;
}

/* sn-2.95.3-136, cloned from CreateObjectWithVtableA. */






extern char D_0041B6A0[];               /* method table of this class */




/* The tail vector is stored through the object base with its offset in the
 * instruction, as retail does. */
#define COBJ20E0_TAIL_OFS   ((int)&((cObj20E0 *)0)->tail)   /* 0x20B0 */

/* Allocates and zeroes a 0x20E0-byte object, runs the cObjBase constructor,
 * sets its method table and zeroes the vectors of its 44 records and its
 * tail. 0 when the allocator is locked or full. */
__attribute__((section(".text.ObjFactory_create101")))
void *ObjFactory_create101(void)
{
    cObj20E0 *obj;
    cObj20E0 *self;
    cObj20E0Ent *e;
    int i;

    if (D_00747A34 & COBJ20E0_NO_NEW)
        goto none;
    obj = _MemoryAlloc(COBJ20E0_SIZE, COBJ20E0_ALIGN, D_00754C10);
    if (obj == 0)
        goto none;
    func_003A52F0(obj, 0, COBJ20E0_SIZE);
    self = obj;
    cObjBase(self);
    self->vt = D_0041B6A0;
    e = self->ent;
    for (i = COBJ20E0_ENT_NUM - 1; i != -1; i--) {
        VU0_SQC2_VF0(e, 0x00);
        VU0_SQC2_VF0(e, 0x10);
        VU0_SQC2_VF0(e, 0x30);
        VU0_SQC2_VF0(e, 0x40);
        VU0_SQC2_VF0(e, 0x50);
        VU0_SQC2_VF0(e, 0x80);
        e++;
    }
    VU0_SQC2_VF0(obj, COBJ20E0_TAIL_OFS);
    return obj;
none:
    /* Dead store: it puts self's last reference after obj's, so cse keeps
     * self for the constructor and obj for the return, as retail does. The
     * early-return form without it merges the two registers. */
    self = 0;
    return 0;
}

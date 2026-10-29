/* sn-2.95.3-136 matched TU. */

#include "godhand/cOm53.h"
#include "godhand/cOmScripted.h"
#include "godhand/cObjBase.h"
#include "godhand/vu0.h"
#include "godhand/cFont.h"

extern void func_001B6FB8(cOm53 *self);
extern void cOm53_setRiseWaitTime(cOm53 *self, int frames);
extern void cOm53_setDownPos(cOm53 *self, float x);
extern int cOmBase_checkDamage(cOmScripted *self, int record);
extern void MtxInitCoord(float *mtx, cVec *pos, cVec *rot, cVec *scale, int order);
extern void sceVu0ApplyMatrix(cVec *dst, float *mtx, cVec *src);
extern void func_002A58A0(cFont *self, int a1);
extern void func_002A58D8(cFont *self, unsigned int v);

/* Offsets the cOm53 and cOmBase headers leave as padding. */
#define COM53_SCRFLAGS(self) (*(int *)((char *)(self) + 0x5A0))
#define COM53_UNK613(self)   (*(unsigned char *)((char *)(self) + 0x613))
#define COM53_RISE_WAIT      0x1C2





/* Starts the lift: base init, waits COM53_RISE_WAIT frames, sets the down position to 0. */
__attribute__((section(".text.cOm53_start")))
int cOm53_start(cOm53 *self) {
    func_001B6FB8(self);
    COM53_SCRFLAGS(self) |= 1;
    cOm53_setRiseWaitTime(self, COM53_RISE_WAIT);
    cOm53_setDownPos(self, 0.0f);
    COM53_UNK613(self) = 0;
    self->base.flags2 |= 8;
    return 1;
}

/* On a plain hit (result 1) restart the four state bytes at mode 1 and flag the object dead when its hp ran out. */
__attribute__((section(".text.cOmScripted_onHit")))
void cOmScripted_onHit(cOmScripted *self) {
    if (cOmBase_checkDamage(self, self->hitRecord) == 1) {
        if (self->base.hp <= 0) {
            self->dead = 1;
        }
        self->base.mode = 1;
        self->base.phase = 0;
        self->base.step = 0;
        self->base.stepArg = 0;
    }
}

/* Adds the null part's speed to the position after turning it by yaw (radians) around the object's own origin. */
__attribute__((section(".text.Add_nullspeedDir")))
void Add_nullspeedDir(cObjBase *self, float yaw) {
    struct {
        float mtx[16];
        cVec rot;                       /* 0x40 */
    } f;

    VU0_SQC2_VF0(&f, 0x40);
    f.rot.x = 0.0f;
    f.rot.y = yaw;
    f.rot.z = 0.0f;
    MtxInitCoord(f.mtx, self->pos, &f.rot, &self->scale, self->rotOrder);
    sceVu0ApplyMatrix(self->pos, f.mtx, &self->nullSpeed);
}

/* One g++ 2.x vtable entry: this-adjust, index, function. */
typedef struct VtEnt {
    short delta;
    short index;
    int (*pfn)(void *self, int arg);
} VtEnt;

typedef struct VtOwner {
    char unk000[0x214];
    VtEnt *vt;                          /* 0x214 */
} VtOwner;

typedef struct ObjList {
    char unk00[0x1C];
    int count;                          /* 0x1C */
} ObjList;

extern void func_002A9800(ObjList *list, VtOwner *obj);

/* Queues obj on the list: counts it, runs its virtual method in slot 1 with mode 2, then moves it to the list front. */
__attribute__((section(".text.ObjList_queueObj")))
void ObjList_queueObj(ObjList *list, VtOwner *obj) {
    if (obj != 0) {
        list->count++;
        obj->vt[1].pfn((char *)obj + obj->vt[1].delta, 2);
        func_002A9800(list, obj);
    }
}

/* An ID display holder: owns a cIDBase at offset 0 and its animation state at 0x94. */
typedef struct IdHolder {
    char unk000[0x94];
    int anim;                           /* 0x94 live animation id, 0 when none */
    char unk098[4];
    int step;                           /* 0x9C */
    int timer;                          /* 0xA0 */
    float rate;                         /* 0xA4 1.0 normal */
} IdHolder;

extern void cIDBase_release(IdHolder *self);

/* Back to idle: no animation, normal rate. */
static __inline__ void IdHolder_reset(IdHolder *self) {
    self->anim = 0;
    self->rate = 1.0f;
    self->step = 0;
    self->timer = 0;
}

/* Releases the live animation if there is one, and leaves the holder idle. */
__attribute__((section(".text.IdHolder_releaseAnim")))
void IdHolder_releaseAnim(IdHolder *self) {
    if (self->anim != 0) {
        cIDBase_release(self);
        IdHolder_reset(self);
    }
    IdHolder_reset(self);
}

/* Sets the text draw state: colour, layer, three scales; then runs the two state setters with a3 and t0. */
__attribute__((section(".text.cFont_setDrawState")))
void cFont_setDrawState(cFont *self, int colour, int layer, int a3, int t0, float scaleX, float f13, float f14) {
    self->state.colour = colour;
    self->state.layer = layer;
    self->state.scaleY = scaleX;
    self->state.scaleX = scaleX;
    self->state.unk34 = f13;
    self->state.unk38 = f14;
    func_002A58A0(self, a3);
    func_002A58D8(self, t0);
}

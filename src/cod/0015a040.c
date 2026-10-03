/* sn-2.95.3-136 matched TU. */

#include "godhand/cIDBase.h"
#include "godhand/cTaskManager.h"
#include "godhand/cTaskWork.h"
#include "godhand/cOmBase.h"

extern void Obj0000_Set_Fields_68_6C_From_D_007474A0_1615D0(void *self);
extern void cIDManager_setIDData(void *mgr, int kind, int res);
extern void cIDBase_initialize(void *self, int kind, int arg);
extern void cIDBase_resetAnim(void *self);
extern int cIDBase_setPackedMessData(void *self, int kind, int arg);
extern void *cIDBase_getIDWork(void *self, int idx);
extern char D_0041F378[];
extern void **D_003C2384;
extern cTaskManager D_00752C00;
extern void cTaskWork_sleep(cTaskWork *task, int frames);
extern float capVu0Sin(float rad);
extern float capVu0Cos(float rad);
extern void CustomIDWork_SetMoveOffsetPosXSin(void *work, int kind, int frames);
extern void CustomIDWork_ResetMoveOffsetPos(void *work);
extern void CustomIDWork_SetColorAnimSin(void *work, int from, int to, int frames);
extern void CustomIDWork_ResetColorAnim(void *work);
extern char D_00747B00[];
extern char D_0044BD60[];

/* Constructor of the 6-part display object: base setup, then (when its data table matches) the ID data, initial animation and message, and the 27 display works. */


#define IDOBJ_WORK_NUM  0x1B
#define IDOBJ_KIND      6

typedef struct IdDispObj {
    cIDBaseObj base;                    /* 0x00 */
    char unk48[8];
    int resHandle;                      /* 0x50 */
    char unk54[6];
    unsigned char b5A;                  /* 0x5A */
    unsigned char b5B;                  /* 0x5B */
    unsigned char b5C;                  /* 0x5C */
    unsigned char b5D;                  /* 0x5D */
    char unk5E[2];
    int state;                          /* 0x60 */
    char unk64[0x1C];
    void *work[IDOBJ_WORK_NUM];         /* 0x80 */
    unsigned char bEC;                  /* 0xEC */
    unsigned char bED;                  /* 0xED */
    unsigned char bEE;                  /* 0xEE */
    unsigned char bEF;                  /* 0xEF */
} IdDispObj;











__attribute__((section(".text.func_00161BD0")))
void func_00161BD0(IdDispObj *self)
{
    unsigned short i;
    Obj0000_Set_Fields_68_6C_From_D_007474A0_1615D0(self);
    if (func_00161500(self, D_0041F378) != 0) {
        cIDManager_setIDData(*D_003C2384, IDOBJ_KIND, self->resHandle);
        cIDBase_initialize(self, IDOBJ_KIND, 0);
        cIDBase_resetAnim(self);
        self->base.playing = 1;
        cIDBase_setPackedMessData(self, IDOBJ_KIND, 1);
        self->b5A = 0;
        self->state = 2;
        self->b5B = 0;
        self->b5C = 0;
        self->b5D = 0;
    }
    for (i = 0; i < IDOBJ_WORK_NUM; i++) {
        self->work[i] = cIDBase_getIDWork(self, i);
    }
    self->bEC = 0;
    self->bED = 0;
    self->bEE = 0;
    self->bEF = 0;
}

/* Visit every task record as func_002D52A0 does, but a step may ask to wait: when it leaves a frame count in the wait field, sleep the running task that long and visit the same record again. */



#define TASKMGR_NUM_OFFSET   0xC        /* an unsigned short the header leaves in unk0C */
#define TASKMGR_NUM(self)    (*(unsigned short *)((char *)(self) + TASKMGR_NUM_OFFSET))
#define TASKMGR_WAIT_OFFSET  0x34       /* an unsigned short just past the header's last field */
#define TASKMGR_WAIT(self)   (*(unsigned short *)((char *)(self) + TASKMGR_WAIT_OFFSET))


extern void func_002D57C8(cTaskWork *work);     /* run one task's step */


__attribute__((section(".text.func_002D5358")))
void func_002D5358(cTaskManager *self)
{
    unsigned int i;
    int off;
    TASKMGR_WAIT(self) = 0;
    i = 0;
    if (TASKMGR_NUM(self) != 0) {
        off = 0;
        do {
            cTaskWork *work = (cTaskWork *)(self->works + off);
            long flags = (unsigned int)self->flags;
            long need;
            long attr;
            self->curNo = i;
            need = flags & 1;
            self->cur = work;
            if (need != 0) {
                if ((work->attr & 1) == 0) goto next;
            }
            need = (flags >> 1) & 1;
            if (need != 0) {
                attr = work->attr;
                if (((attr >> 1) & 1) == 0) goto next;
            }
            TASKMGR_WAIT(self) = 0;
            func_002D57C8(work);
            if (TASKMGR_WAIT(self) != 0) {
                cTaskWork_sleep(D_00752C00.cur, TASKMGR_WAIT(self));
                off -= TASKMGR_WORK_SIZE;
                i--;
            }
        next:
            i++;
            off += TASKMGR_WORK_SIZE;
        } while (i < TASKMGR_NUM(self));
    }
    self->cur = 0;
    self->curNo = TASKMGR_NONE;
}

/* Read the five (x, y) slots; when the y values hold both a 3 and a 2, set bit 2 in each of the five slot records and return 1. */
#define SLOT_NUM     5
#define SLOT_KIND_A  3
#define SLOT_KIND_B  2
#define SLOT_F_MARK  0x4

typedef struct SlotRec {
    int unk00;
    unsigned int flags;                 /* 0x04 */
} SlotRec;

typedef struct SlotObj {
    char unk0000[0x3004];
    SlotRec *slot[SLOT_NUM];            /* 0x3004 */
} SlotObj;

extern void func_001DBFB8(SlotObj *self, unsigned short *x0, unsigned short *y0, unsigned short *x1, unsigned short *y1,
                          unsigned short *x2, unsigned short *y2, unsigned short *x3, unsigned short *y3,
                          unsigned short *x4, unsigned short *y4);

__attribute__((section(".text.func_001DC5F8")))
int func_001DC5F8(SlotObj *self)
{
    unsigned short x[8];
    unsigned short y[8];
    unsigned short n;
    int j;
    int k;
    func_001DBFB8(self, &x[0], &y[0], &x[1], &y[1], &x[2], &y[2], &x[3], &y[3], &x[4], &y[4]);
    n = 0;
    for (j = 0; j < SLOT_NUM; j++) {
        if (y[j] == SLOT_KIND_A) {
            n++;
            break;
        }
    }
    for (j = 0; j < SLOT_NUM; j++) {
        if (y[j] == SLOT_KIND_B) {
            n++;
            break;
        }
    }
    if (n == 2) {
        SlotRec **p = self->slot;
        for (k = SLOT_NUM - 1; k >= 0; k--) {
            (*p)->flags |= SLOT_F_MARK;
            p++;
        }
        return 1;
    }
    return 0;
}

/* Rotate quaternion q by angle about the unit axis: q' = (axis * sin(angle/2), cos(angle/2)) * q. */





__attribute__((section(".text.Quaternion_AddRotationAxis")))
void Quaternion_AddRotationAxis(cVec *q, cVec *axis, float angle)
{
    cVec old;
    float half = angle * 0.5f;
    float s;
    float c;

    old.x = q->x;
    old.y = q->y;
    old.z = q->z;
    old.w = q->w;
    s = capVu0Sin(half);
    c = capVu0Cos(half);
    q->x = (axis->y * old.z - axis->z * old.y + axis->x * old.w) * s + c * old.x;
    q->y = (axis->z * old.x - axis->x * old.z + axis->y * old.w) * s + c * old.y;
    q->z = (axis->x * old.y - axis->y * old.x + axis->z * old.w) * s + c * old.z;
    q->w = (axis->x * old.x + axis->y * old.y + axis->z * old.z) * -s + c * old.w;
}

/* Turn the pulsing selection mark on or off: on starts the sine move of the offset work and the sine colour fade between a grey 0x80 and a grey 0xC0 colour, off resets both. */
typedef struct MarkObj {
    char unk000[0x440];
    char moveWork[0x7C];                /* 0x440 CustomIDWork of the mark offset */
    char colorWork[0x7C];               /* 0x4BC CustomIDWork of the mark colour */
} MarkObj;






__attribute__((section(".text.func_001F53A8")))
void func_001F53A8(MarkObj *self, int on)
{
    int base;
    int peak;
    int from;
    int to;
    if (on) {
        CustomIDWork_SetMoveOffsetPosXSin(self->moveWork, 3, 0x10);
        from = (((((((base & ~0xFF) | 0x80) & ~0xFF00) | 0x8000) & ~0xFF0000) | 0x800000) & ~0xFF000000) | 0x80000000;
        to = (((((((peak & ~0xFF) | 0xC0) & ~0xFF00) | 0xC000) & ~0xFF0000) | 0xC00000) & ~0xFF000000) | 0x80000000;
        CustomIDWork_SetColorAnimSin(self->colorWork, from, to, 4);
    } else {
        CustomIDWork_ResetMoveOffsetPos(self->moveWork);
        CustomIDWork_ResetColorAnim(self->colorWork);
    }
}

/* Take a free object from the pool and set it up: base init, its embedded sub-object (table D_0044BD60 as method table, scale applied through its method 3); when the taken record is not in the free state it is handed back through the pool's method 12. Returns the object, or 0. */
#define POOLOBJ_FREE_MASK   0x201
#define POOLOBJ_FREE_VALUE  0x1
#define POOLOBJ_SUB_OFFSET  0xE0

typedef struct SubVtEnt {
    short delta;
    short index;
    void (*pfn)(void *self, float scale);
} SubVtEnt;

typedef struct SubVt {
    char unk00[0x18];
    SubVtEnt scale;                     /* 0x18 method 3 */
} SubVt;

typedef struct PoolVtEnt {
    short delta;
    short index;
    void (*pfn)(void *self, void *obj);
} PoolVtEnt;

typedef struct PoolVt {
    char unk00[0x30];
    PoolVtEnt release;                  /* 0x30 method 6 */
} PoolVt;

typedef struct Pool {
    char unk00[0x18];
    PoolVt *vt;                         /* 0x18 */
} Pool;

typedef struct PoolObj {
    unsigned int flags;                 /* 0x00 */
    char unk04[0x30];
    void *owner;                        /* 0x34 */
    char unk38[0xA8];
    int state;                          /* 0xE0 first word of the sub-object */
    char unkE4[0x1C];
    SubVt *subVt;                       /* 0x100 */
} PoolObj;

extern PoolObj *create(Pool *pool, int flag);
extern void func_002B8A70(PoolObj *obj, int arg);




__attribute__((section(".text.func_002B9DF0")))
PoolObj *func_002B9DF0(Pool *pool, int arg, int a, int b, float scale)
{
    PoolObj *obj = create(pool, 0);
    PoolObj *sub;
    if (obj == 0) {
        return 0;
    }
    if (((obj->flags & POOLOBJ_FREE_MASK) ^ POOLOBJ_FREE_VALUE) != 0) {
        pool->vt->release.pfn((char *)pool + pool->vt->release.delta, obj);
        return 0;
    }
    func_002B8A70(obj, arg);
    sub = (PoolObj *)((char *)obj + POOLOBJ_SUB_OFFSET);
    func_002BB160(sub, a, b, D_00747B00);
    sub->subVt = (SubVt *)D_0044BD60;
    obj->state = 0;
    sub->subVt->scale.pfn((char *)sub + sub->subVt->scale.delta, scale);
    obj->owner = sub;
    return obj;
}

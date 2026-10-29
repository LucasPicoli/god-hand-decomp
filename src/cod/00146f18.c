/* sn-2.95.3-136 matched TU. */

#include "godhand/cGameObj.h"
#include "godhand/vu0.h"

extern char D_00586AF0[];
extern unsigned int cEvent_getCutNo();
extern float cEvent_getCutFrame();
extern void func_001C0450(cGameObj *self);
extern int D_00423E48;
#include "godhand/objField.h"
extern unsigned short D_00747A50;
extern void ClearBytesAt74And79To7C_13C618(void *self);

/* The derived object keeps a copy of the lock-on point at 0x8D0. */
/* The height is read and written through the object, not through the vector pointer: only this
 * spelling keeps retail's loads. */
#define GAMEOBJ_LOCKON_COPY_Y(self) (*(float *)((char *)(self) + 0x8D4))
#define GAMEOBJ_LOCKON_COPY(self) ((cVec *)((char *)(self) + 0x8D0))

/* cGameObj_getRaisedLockOnPos: copy the lock-on point into the 0x8D0 vector, raise it by 4.1 and return it. */
__attribute__((section(".text.cGameObj_getRaisedLockOnPos")))
cVec *cGameObj_getRaisedLockOnPos(cGameObj *self)
{
    cVec *src = ((cVec *(*)(void *))cGameObj_vt(self)->lockOn)((char *)self + cGameObj_vt(self)->lockOnDelta);
    cVec *dst = GAMEOBJ_LOCKON_COPY(self);
    cVec_copy3(dst, src);
    GAMEOBJ_LOCKON_COPY_Y(self) = GAMEOBJ_LOCKON_COPY_Y(self) + 4.1f;
    return dst;
}

/* A counted array with an allocator type record; arrayFree releases the items. */
typedef struct ArrayType {
    int unk00[4];
    short allocOfs;                         /* 0x10 this adjustment for the allocator */
    short pad12;
    void *(*alloc)(void *self, int size);   /* 0x14 */
    int unk18[2];
    short initOfs;                          /* 0x20 this adjustment for the initialiser */
    short pad22;
    void (*init)(void *self, void *items, int size);  /* 0x24 */
} ArrayType;

typedef struct ArrayObj {
    void *items;        /* 0x00 */
    int count;          /* 0x04 */
    int elemSize;       /* 0x08 */
    int unk0C;
    int unk10;
    int unk14;
    ArrayType *type;    /* 0x18 */
} ArrayObj;

extern int arrayFree(ArrayObj *a);

/* arrayAlloc: drop the old items, allocate room for n elements and run the type's initialiser over them. */
__attribute__((section(".text.arrayAlloc")))
int arrayAlloc(ArrayObj *a, int n)
{
    void *items;
    arrayFree(a);
    items = a->type->alloc((char *)a + a->type->allocOfs, a->elemSize * n);
    a->count = n;
    a->items = items;
    if (n != 0) {
        a->type->init((char *)a + a->type->initOfs, items, a->elemSize * n);
    }
    return 1;
}

/* A cutscene command object (same record as CutCmd in src/cod/001632e8.c). */
typedef struct CutCmd {
    char unk00[0x44];
    unsigned char cutFirst;             /* 0x44 first cut */
    char unk45[7];
    unsigned char cutLast;              /* 0x4C last cut */
    char unk4D[3];
    int lastFrame;                      /* 0x50 frame at which the last cut ends */
} CutCmd;





/* CutCmd_isInRange: nonzero while the running cutscene is inside the command: not before its first cut,
 * and in its last cut only until the end frame. */
__attribute__((section(".text.CutCmd_isInRange")))
int CutCmd_isInRange(CutCmd *self)
{
    char *ev = D_00586AF0;
    float frame;
    if (cEvent_getCutNo(ev) < self->cutFirst) {
        return 0;
    }
    if (cEvent_getCutNo(ev) < self->cutLast) {
        return 1;
    }
    frame = cEvent_getCutFrame(ev);
    if ((float)self->lastFrame < frame) {
        return 0;
    }
    return 1;
}

/* The flag word of the derived object at 0x5B8. */
#define GAMEOBJ_FLAGS5B8(self) (*(int *)((char *)(self) + 0x5B8))

/* cGameObj_moveToPos: move the object to a new position (live position and posA), refresh it and mark
 * bit 0x10 of the 0x5B8 flags. */
__attribute__((section(".text.cGameObj_moveToPos")))
void cGameObj_moveToPos(cGameObj *self, cVec *pos)
{
    cVec_copy3(self->pos, pos);
    func_001C0450(self);
    cVec_copy3(&self->posA, pos);
    GAMEOBJ_FLAGS5B8(self) |= 0x10;
}

/* cEm_constructWithRecords: constructor. Runs the base constructor, sets the method table, clears two
 * vectors at 0x660 and seven 0x60-byte records from 0x680 (five vectors each, then their byte at 0x54). */
__attribute__((section(".text.cEm_constructWithRecords")))
void *cEm_constructWithRecords(char *self)
{
    char *rec;
    int i;
    func_001C7D98(self);
    *(int **)(self + 0x214) = &D_00423E48;
    VU0_SQC2_VF0(self, 0x660);
    VU0_SQC2_VF0(self, 0x670);
    rec = self + 0x680;
    for (i = 6; i != -1; i--) {
        VU0_SQC2_VF0(rec, 0x0);
        VU0_SQC2_VF0(rec, 0x10);
        VU0_SQC2_VF0(rec, 0x20);
        VU0_SQC2_VF0(rec, 0x30);
        VU0_SQC2_VF0(rec, 0x40);
        Obj0000_Set_Byte_54(rec, 0);
        rec += 0x60;
    }
    return self;
}

/* A screen element with a position pair at 0x60. */
typedef struct PosPair {
    char unk00[0x60];
    float x;            /* 0x60 */
    float y;            /* 0x64 */
} PosPair;

/* Element_resetPos: reset the element; in mode 0x20 place it at (-130, 5), otherwise at the origin. */
__attribute__((section(".text.Element_resetPos")))
void Element_resetPos(PosPair *self)
{
    ClearBytesAt74And79To7C_13C618(self);
    if (D_00747A50 == 0x20) {
        self->x = -130.0f;
        self->y = 5.0f;
    } else {
        self->x = 0.0f;
        self->y = 0.0f;
    }
}

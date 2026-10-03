/* sn-2.95.3-136 matched TU. */

#include "godhand/cEm00.h"
#include "godhand/Slot2.h"
#include "godhand/vu0.h"
#include "godhand/cOmBase.h"
#include "godhand/cModel.h"

extern char D_0044E030[];
extern char D_0044E040[];
extern unsigned int D_00747A34;
extern void *EnsureInitThenForward_2A9538_30EE08(int size, int align, void *heap);
extern int LoadEntryByValue_1FFD00(char *table, char *name, void *dest);
extern void displayScrollLayer(int id, int on);
extern void func_0013ECF0(void *p);
extern void Obj0000_Clear_Fields_94_9C_13C808(void *p);
extern void ClearFields_A0_250_358_13F2F8(void *p);
extern void ClearFields94And9C_13E7D8(void *p);
extern void ClearFields_B0_AC_147018(void *p);
extern void sceVu0ApplyMatrix(void *dst, void *mtx, void *vec);
extern char D_0042CAB8[];
extern void *cModel_getMeshPtr_14B730(void *obj, char *name);

/* Reset a hit-flash driver: drop its nine state flags, clear its fields, and (unless bit 31 of the system flags is set) fade its target's hit flash down by speed * frame rate, not below the driver's floor. */


typedef struct FlashDriver {
    char unk00[0x10];
    cVec floor;                         /* 0x10 floor.y is the lowest hit flash */
    char unk20[0x10];
    cEm00 *target;                      /* 0x30 */
    int unk34;                          /* 0x34 */
    char unk38[8];
    int unk40;                          /* 0x40 */
    short unk44;                        /* 0x44 */
    char unk46[0x1A];
    int flags;                          /* 0x60 */
} FlashDriver;

typedef struct SysFlags {
    int flags;                          /* system flags */
} SysFlags;

extern SysFlags D_00747A78;
/* The frame rate scale D_00747A14 sits 0x64 bytes below the flags; retail reaches it from the flags address. */
#define SYS_FRAME_RATE  (*(float *)((char *)&D_00747A78 - 0x64))

__attribute__((section(".text.FlashDriver_resetFlash")))
void FlashDriver_resetFlash(FlashDriver *self)
{
    cVec *floor;
    self->flags &= ~0x1;
    self->flags &= ~0x2;
    self->flags &= ~0x4;
    self->flags &= ~0x8;
    self->flags &= ~0x10;
    self->flags &= ~0x20;
    self->flags &= ~0x80;
    self->flags &= ~0x100;
    self->flags &= ~0x200;
    self->unk34 = 0;
    self->unk40 = -1;
    self->unk44 = 0;
    floor = &self->floor;
    floor->x = 0;
    floor->y = 0;
    floor->z = 0;
    if (D_00747A78.flags >= 0) {
        cEm00 *t = self->target;
        if (t != 0) {
            float lowest = floor->y;
            if (t->hitFlash != lowest) {
                t->hitFlash = t->hitFlash - t->speedRate * SYS_FRAME_RATE;
                if (self->target->hitFlash < lowest) {
                    self->target->hitFlash = lowest;
                }
            }
        }
    }
}

/* Set up the file-list buffer record: two 8s, an empty counter, a 0x1000 byte buffer, then load the entry table into that buffer (a second table when system flag 0x4000 is set). */
#define FILEBUF_SYS_ALT  0x4000         /* D_00747A34 bit 14 */

typedef struct FileBuf {
    char unk00[8];
    unsigned char kindA;                /* 0x08 */
    unsigned char kindB;                /* 0x09 */
    short count;                        /* 0x0A */
    char unk0C[8];
    void *buf;                          /* 0x14 */
} FileBuf;

extern FileBuf D_0061B280;
extern int D_00754200;                  /* heap */
extern char D_00580D40[];               /* entry table */






__attribute__((section(".text.FileBuf_init")))
void FileBuf_init(void)
{
    FileBuf *fb = &D_0061B280;
    fb->count = 0;
    fb->kindA = 8;
    fb->kindB = 8;
    fb->buf = EnsureInitThenForward_2A9538_30EE08(0x1000, 0x40, &D_00754200);
    if ((D_00747A34 & FILEBUF_SYS_ALT) == 0) {
        LoadEntryByValue_1FFD00(D_00580D40, D_0044E030, fb->buf);
    } else {
        LoadEntryByValue_1FFD00(D_00580D40, D_0044E040, fb->buf);
    }
}

#define SLOT2_OFFSET_MODE     0x48E     /* ushort: display mode, 0 to 3 */
#define SLOT2_OFFSET_LAYER_0  0x434     /* layer ids, not named in Slot2.h */
#define SLOT2_OFFSET_LAYER_1  0x438
#define SLOT2_OFFSET_LAYER_2  0x43C
#define SLOT2_OFFSET_LAYER_3  0x440
#define SLOT2_OFFSET_LAYER_4  0x444
#define SLOT2_LAYER(self, off) (*(int *)((char *)(self) + (off)))
#define SLOT2_MODE(self)       (*(unsigned short *)((char *)(self) + SLOT2_OFFSET_MODE))

/* Show the scroll layers for the mode: 0 shows none, 1 shows layer 0, 2 shows layers 0 to 2, 3 shows all five. */
__attribute__((section(".text.Slot2_showLayersForMode")))
void Slot2_showLayersForMode(Slot2 *self)
{
    switch (SLOT2_MODE(self)) {
    case 0:
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_0), 0);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_1), 0);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_2), 0);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_3), 0);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_4), 0);
        break;
    case 1:
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_0), 1);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_1), 0);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_2), 0);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_3), 0);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_4), 0);
        break;
    case 2:
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_0), 1);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_1), 1);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_2), 1);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_3), 0);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_4), 0);
        break;
    case 3:
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_0), 1);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_1), 1);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_2), 1);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_3), 1);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_4), 1);
        break;
    }
}

#define MGR_SLOT_NUM  17

/* One registered object: the manager keeps its pointer at +4. */
typedef struct MgrSlot {
    int unk0;
    void *obj;                          /* 0x4 */
    int unk8;
} MgrSlot;

/* A g++ 2.x virtual table entry. */
typedef struct VtEnt {
    short delta;
    short index;
    void (*pfn)(void *self);
} VtEnt;

/* The manager: eleven sub-records at fixed offsets, then the slot table at 0x22F0. */
typedef struct DispMgr {
    char unk0000[0x22F0];
    MgrSlot slot[MGR_SLOT_NUM];         /* 0x22F0 */
    unsigned char ready;                /* 0x23BC */
} DispMgr;


extern void func_00140BF0(DispMgr *mgr, void *sub, int kind);
extern void SetupFields10And14_13D3C0(DispMgr *mgr);






#define MGR_SUB(m, ofs)  ((char *)(m) + (ofs))
#define OBJ_VT(o)        (*(VtEnt **)((char *)(o) + 0x80))
#define VT_RESET         2              /* vtable entry called on every registered object */

/* Reset the manager: clear the slot table, set up the eleven sub-records, then call the reset method of every registered object. */
__attribute__((section(".text.DispMgr_reset")))
void DispMgr_reset(DispMgr *self)
{
    int i;
    void **po;

    func_003A52F0(MGR_SUB(self, 0x22F0), 0, MGR_SLOT_NUM * 12);
    po = &self->slot[0].obj;
    func_00140BF0(self, MGR_SUB(self, 0x6E0), 1);
    func_00140BF0(self, MGR_SUB(self, 0x460), 3);
    func_00140BF0(self, MGR_SUB(self, 0xEA0), 6);
    func_00140BF0(self, MGR_SUB(self, 0xCC0), 4);
    func_00140BF0(self, MGR_SUB(self, 0x1380), 7);
    func_00140BF0(self, MGR_SUB(self, 0x1470), 8);
    func_00140BF0(self, MGR_SUB(self, 0x1520), 14);
    func_00140BF0(self, MGR_SUB(self, 0x15C0), 9);
    func_00140BF0(self, MGR_SUB(self, 0x1CB0), 15);
    func_00140BF0(self, MGR_SUB(self, 0x1910), 16);
    func_00140BF0(self, MGR_SUB(self, 0x1AE0), 17);
    SetupFields10And14_13D3C0(self);
    func_0013ECF0(MGR_SUB(self, 0x3A0));
    Obj0000_Clear_Fields_94_9C_13C808(MGR_SUB(self, 0x1DC0));
    ClearFields_A0_250_358_13F2F8(MGR_SUB(self, 0x1E90));
    ClearFields94And9C_13E7D8(MGR_SUB(self, 0x2220));
    ClearFields_B0_AC_147018(MGR_SUB(self, 0x1A20));
    for (i = MGR_SLOT_NUM - 1; i >= 0; i--) {
        void *o = *po;
        if (o != 0) {
            OBJ_VT(o)[VT_RESET].pfn((char *)o + OBJ_VT(o)[VT_RESET].delta);
        }
        po = (void **)((char *)po + sizeof(MgrSlot));
    }
    self->ready = 0;
}

/* A box: centre and half extents. */
typedef struct HitBox {
    float center[3];                    /* 0x00 */
    float half[3];                      /* 0x0C half extent on x, y, z */
} HitBox;

/* 1 if point lies inside the box (centre moved by mtx), with each half extent widened by the margins; else 0. */
__attribute__((section(".text.HitBox_containsPoint")))
int HitBox_containsPoint(HitBox *box, void *mtx, cVec *point, float mx, float my, float mz)
{
    char frame[0x30] __attribute__((aligned(16)));
    float *c = (float *)frame;
    char *w = frame + 0x20;
    float hx;
    float hy;
    float hz;

    c[0] = box->center[0];
    c[1] = box->center[1];
    c[2] = box->center[2];
    c[3] = 1.0f;
    VU0_LQC2(4, frame, 0);
    VU0_SQC2(4, frame, 0x20);
    sceVu0ApplyMatrix(w, mtx, w);
    VU0_LQC2(4, w, 0);
    VU0_SQC2(4, frame, 0x10);
    cVec_copy3((cVec *)frame, (cVec *)(frame + 0x10));
    hy = box->half[1] + my;
    hx = box->half[0] + mx;
    hz = box->half[2] + mz;
    if (!(point->y <= c[1] + hy)) return 0;
    if (!(c[1] - hy <= point->y)) return 0;
    if (!(point->x <= c[0] + hx)) return 0;
    if (!(c[0] - hx <= point->x)) return 0;
    if (!(point->z <= c[2] + hz)) return 0;
    if (c[2] - hz <= point->z) return 1;
    return 0;
}

/* cEm00.meshHook, a field cEm00.h does not name yet. */
#define EM_MESHHOOK(self) (*(cModelNode **)((char *)(self) + 0x179C))

#define EMFLAGS_SHOW_HOOK  0x400000         /* emFlags: the hooked meshes are shown */

/* Show or hide the hooked node and the named mesh to match the enemy's show flag. */
__attribute__((section(".text.cEm00_setMeshHookDisplay")))
void cEm00_setMeshHookDisplay(cEm00 *self) {
    cModelNode *mesh;
    if (EM_MESHHOOK(self) != 0) {
        mesh = cModel_getMeshPtr_14B730(self, D_0042CAB8);
        if ((self->emFlags & EMFLAGS_SHOW_HOOK) != 0) {
            EM_MESHHOOK(self)->dispFlags &= ~CMODEL_NODE_HIDE;
            if (mesh != 0) {
                mesh->dispFlags &= ~CMODEL_NODE_HIDE;
            }
        } else {
            EM_MESHHOOK(self)->dispFlags |= CMODEL_NODE_HIDE;
            if (mesh != 0) {
                mesh->dispFlags |= CMODEL_NODE_HIDE;
            }
        }
    }
}

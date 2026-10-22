/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cEmManage.h"
#include "godhand/cOmBase.h"
#include "godhand/FileLoadRec.h"

extern void SetCustomIDDispOneOrAll_1F4778(void *self, int no, int show);
extern void *InitFields_1B6E90(void *self);
#include "godhand/objField.h"
extern void sceVu0InversMatrix(float *dst, float *src);
extern void func_001A6FB0(void *self);
extern char *Getplayer(void);
extern void func_001A70D8(void *self, cVec *pos, float radius);
extern char *FileNameFromObjId(char *out, int objId);
extern int cDvd_ReadAlloc(void *dvd, void *name, void *dst, void *arg, int a4, int a5, int a6, int a7);
extern char D_00583F20[];
extern unsigned char GetField_601_17B810(void *self);
extern int cOmBase_checkDamage(void *self, int record);
extern void cOl1b_setClose(void *self);
extern void SetField_606_17AEA0(void *self);
extern void func_0017AEB0(void *self);
extern int cOl1b_isActive(void *self);
extern void func_001B7EE0(void *self, float f12);

#define MARK_NUM        7
#define MARK_A_BASE     10              /* first entry of the left marks */
#define MARK_B_BASE     0x11            /* first entry of the right marks */

/* Hides both marks of slot `no` and, if `lit`, shows one of them: the left
 * one when `right` is 0, the right one otherwise. */
__attribute__((section(".text.Panel_showSlotMark")))
void Panel_showSlotMark(void *self, unsigned short no, int right, int lit)
{
    if (no < MARK_NUM) {
        SetCustomIDDispOneOrAll_1F4778(self, no + MARK_A_BASE, 0);
        SetCustomIDDispOneOrAll_1F4778(self, no + MARK_B_BASE, 0);
        if (lit != 0) {
            if (right != 0) {
                SetCustomIDDispOneOrAll_1F4778(self, no + MARK_B_BASE, 1);
            } else {
                SetCustomIDDispOneOrAll_1F4778(self, no + MARK_A_BASE, 1);
            }
        }
    }
}

extern char D_004272F8[];               /* the class's method table */

#define SLOT_NUM     7
#define SLOT_SIZE    0x60
#define SLOT_OFFSET  0x630

typedef struct Obj1A5100 {
    char unk000[0x214];
    void *vt;                           /* 0x214 */
} Obj1A5100;

/* Constructor: base init, method table, then clears the two vectors at 0x600
 * and the seven 0x60-byte slot records from 0x630. Returns the object. */
__attribute__((section(".text.func_001A5100")))
Obj1A5100 *func_001A5100(Obj1A5100 *self)
{
    char *p;
    int i;
    InitFields_1B6E90(self);
    self->vt = D_004272F8;
    VU0_SQC2_VF0(self, 0x600);
    VU0_SQC2_VF0(self, 0x610);
    p = (char *)self + SLOT_OFFSET;
    for (i = SLOT_NUM - 1; i != -1; i--) {
        VU0_SQC2_VF0(p, 0x00);
        VU0_SQC2_VF0(p, 0x10);
        VU0_SQC2_VF0(p, 0x20);
        VU0_SQC2_VF0(p, 0x30);
        VU0_SQC2_VF0(p, 0x40);
        Obj0000_Set_Byte_54(p, 0);
        p += SLOT_SIZE;
    }
    return self;
}

#define WATCH_RADIUS  0.5f

typedef struct Obj1A6F00 {
    char unk000[0x80];
    float mtx[16];                      /* 0x080 */
    char unk0C0[0x600 - 0xC0];
    float invMtx[16];                   /* 0x600 inverse of mtx */
} Obj1A6F00;

/* Rebuilds the inverse of the object's matrix, then feeds func_001A70D8 the
 * player's position and the position of every enemy in the room. */
__attribute__((section(".text.func_001A6F00")))
void func_001A6F00(Obj1A6F00 *self)
{
    cEmSlot *slot;
    cVec pos;
    char *player;
    sceVu0InversMatrix(self->invMtx, self->mtx);
    func_001A6FB0(self);
    player = Getplayer();
    VU0_LQC2(4, *(cVec **)(player + 0xF0), 0);
    VU0_SQC2(4, &pos, 0);
    func_001A70D8(self, &pos, WATCH_RADIUS);
    for (slot = cEmManage_getTop(&D_005864F0); slot != 0; slot = slot->next) {
        if (slot->em != 0) {
            func_001A70D8(self, *(cVec **)((char *)slot->em + 0xF0), WATCH_RADIUS);
        }
    }
}

/* Starts reading the file of object `objId`. Returns the buffer pointer, or 0
 * when the read could not start. */
__attribute__((section(".text.FileLoadRec_start")))
void *FileLoadRec_start(FileLoadRec *self, int objId, int arg)
{
    char name[0x10];
    void *ret;
    int result = func_003078E0(objId);
    self->arg = arg;
    FileNameFromObjId(name, objId);
    self->handle = cDvd_ReadAlloc(D_00583F20, name, &self->data, (void *)self->arg, 0, 0, 0, 0);
    if (self->handle != 0) {
        self->result = result;
        self->state = FILELOAD_STATE_READING;
        self->flags |= FILELOAD_FLAG_STARTED;
        self->objId = objId;
        ret = self->data;
    } else {
        ret = 0;
    }
    return ret;
}

extern char *func_001F0498(void *owner, int obj, cVec *pos, float angle);   /* create one piece */

#define MARKER_KIND  0x3ED

typedef struct Obj1F08B8 {
    char unk000[0xC64];
    char *marker[3];                    /* 0xC64 the three pieces */
} Obj1F08B8;

/* Creates three markers: one in front (z = 5), one in the middle and one
 * behind (z = -5), each at x = y = 0. */
__attribute__((section(".text.func_001F08B8")))
void func_001F08B8(Obj1F08B8 *self)
{
    cVec v;
    float zero;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 5.0f;
    v.w = 1.0f;
    zero = v.x;                       /* the angle is the x just stored, read back from the stack */
    self->marker[0] = func_001F0498(self, MARKER_KIND, &v, zero);
    v.x = zero;
    v.y = zero;
    v.z = zero;
    v.w = 1.0f;
    self->marker[1] = func_001F0498(self, MARKER_KIND, &v, zero);
    v.x = zero;
    v.y = zero;
    v.z = -5.0f;
    v.w = 1.0f;
    self->marker[2] = func_001F0498(self, MARKER_KIND, &v, zero);
}

#define OL1B_MODE_OPEN   1              /* GetField_601 value of an open door */
#define OL1B_HIT_SLOWDOWN 3.0f

typedef struct cOl1bRec {
    char unk000[0x54A];
    short vital;                        /* 0x54A hit points */
    float hitPause;                     /* 0x54C */
    char unk550[0x602 - 0x550];
    unsigned char locked;               /* 0x602 */
    char unk603[0x60C - 0x603];
    int hitRecord;                      /* 0x60C */
} cOl1bRec;

/* Per frame: an unlocked open door that was hit either counts a hit (vital
 * above 0) or closes; then it steps and, while open and idle, starts its
 * motion. */
__attribute__((section(".text.cOl1b_update")))
void cOl1b_update(cOl1bRec *self)
{
    unsigned char mode;
    if (self->locked == 0) {
        mode = GetField_601_17B810(self);
        if (mode == OL1B_MODE_OPEN) {
            if (cOmBase_checkDamage(self, self->hitRecord) == mode) {
                self->hitPause = OL1B_HIT_SLOWDOWN;
                if (self->vital <= 0) {
                    cOl1b_setClose(self);
                } else {
                    SetField_606_17AEA0(self);
                }
            }
        }
    }
    func_0017AEB0(self);
    if (GetField_601_17B810(self) == OL1B_MODE_OPEN) {
        if (cOl1b_isActive(self) == 0) {
            func_001B7EE0(self, 2.0f);
        }
    }
}

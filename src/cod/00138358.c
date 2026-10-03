/* sn-2.95.3-136 matched TU. */

#include "godhand/cPlCamera.h"
#include "godhand/cCamera.h"
#include "godhand/vu0.h"
#include "godhand/cOmBase.h"
#include "godhand/cDamageUnit.h"
#include "godhand/Poker.h"
#include "godhand/cIDBase.h"

extern cPlCameraTarget *Getplayer(void);
extern void func_00139FF8(struct cPlCamera *self);
extern void func_0013AD90(struct cPlCamera *self);
extern float capVu0Atan2(float y, float x);
extern void MtxInitRotY(float *mtx, float angle);
extern void sceVu0ApplyMatrix(cVec *out, float *mtx, cVec *in);
extern void cDamageUnit_SetDamageCollActive(cDamageUnit *unit, int active);
extern void cOmBase_setMeshDispFromLayer(void *self, int layer, int on);
extern void SetField380Bit2000ForTag_1B7300(void *self, int tag, int on);
extern int ClearField5B4IfFlagUnset_1B76B0(void *self);
extern void func_002A87E8(void *self, int arg);
extern void func_001B76D8(void *self);
extern void func_001DEDA8(void *);
extern void func_001DD180(void *);
extern char D_00567D70[];
extern void NoOp_164978(void *p);
extern void cIDBase_trans(cIDBaseObj *self);

/* Follow the player: the normal chase, or the lock-on chase in state 4. */
__attribute__((section(".text.cPlCamera_update")))
void cPlCamera_update(struct cPlCamera *self) {
    if (Getplayer()->camState != PLCAM_STATE_LOCKON) {
        func_00139FF8(self);
    } else {
        func_0013AD90(self);
    }
}

/* Angles that aim from `b` to `a`: yaw about Y from the XZ part of the
 * difference, then pitch from the difference turned by -yaw. Result in *out
 * as (pitch, yaw, 0). The atan2 arguments go through locals: with the fields
 * inline, the first argument loads first and the call setup differs. */
__attribute__((section(".text.cCamera__calcRotation")))
cVec *cCamera__calcRotation(cVec *out, struct cCamera *self, cVec *a, cVec *b) {
    struct {
        cVec d;                         /* 0x00 */
        cVec rot;                       /* 0x10 */
        float mtx[16];                  /* 0x20 */
    } f;
    cVec *rot;
    float dx, dy, dz;
    char *q;
    VU0_SQC2_VF0(&f, 0x10);
    VU0_LQC2(4, a, 0);
    VU0_LQC2(5, b, 0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, &f, 0x10);
    q = (char *)&f + 0x10;
    VU0_LQC2(4, q, 0);
    VU0_SQC2(4, &f, 0);
    VU0_SQC2_VF0(&f, 0x10);
    rot = &f.rot;
    if (f.d.x == 0.0f && f.d.z == 0.0f) {
        f.rot.y = 0.0f;
    } else {
        dx = f.d.x;
        dz = f.d.z;
        f.rot.y = capVu0Atan2(dx, dz);
    }
    MtxInitRotY(f.mtx, -f.rot.y);
    sceVu0ApplyMatrix(&f.d, f.mtx, &f.d);
    if (f.d.y == 0.0f && f.d.z == 0.0f) {
        f.rot.x = 0.0f;
    } else {
        dy = f.d.y;
        dz = f.d.z;
        f.rot.x = -capVu0Atan2(dy, dz);
    }
    f.rot.z = 0.0f;
    VU0_LQC2(4, rot, 0);
    VU0_SQC2(4, out, 0);
    return out;
}

/* Switch the object off: hit volumes inactive, both mesh layers and tag bits cleared, flag 0x10000 set. */



#define OBJ_FLAG_OFF  0x10000           /* objFlags: the object is switched off */

/* A map object with a damage unit past the base record. */
typedef struct cOmDamaged {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x24];
    cDamageUnit *damage;                /* 0x604 */
} cOmDamaged;





__attribute__((section(".text.cOmDamaged_switchOff")))
void cOmDamaged_switchOff(cOmDamaged *self) {
    if (self->damage != 0) {
        cDamageUnit_SetDamageCollActive(self->damage, 0);
    }
    cOmBase_setMeshDispFromLayer(self, 0, 0);
    cOmBase_setMeshDispFromLayer(self, 0x40, 1);
    SetField380Bit2000ForTag_1B7300(self, 0, 0);
    SetField380Bit2000ForTag_1B7300(self, 0x80, 0);
    self->base.objFlags |= OBJ_FLAG_OFF;
}

/* Mode tick: if the object is active, count the 0x610 timer down, call the handler the current mode's table entry names
 * (a method table entry, or an inline handler for a negative index), then run the post steps (the first one not for actor 0x381). */


#define MODE_NUM  4
#define ACTOR_NO_POST  0x381            /* this actor skips the first post step */

/* One mode entry: this-adjust, method index (or negative: handler is inline), table offset in the object. */
typedef struct ModeEnt {
    short delta;                        /* 0x0 added to this before the call */
    short index;                        /* 0x2 slot in the method table, negative: handler inline at +4 */
    short tblOff;                       /* 0x4 where the method table pointer sits in the object */
    short pad6;
} ModeEnt;

typedef struct { char b[0x20]; } ModeTbl;
extern ModeTbl D_00429C60;              /* the four entries */





__attribute__((section(".text.cOmBase_tickModeTableSkip381")))
void cOmBase_tickModeTableSkip381(cOmBase *self) {
    ModeEnt tbl[MODE_NUM];
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;

    if (ClearField5B4IfFlagUnset_1B76B0(self) == 0) return;
    if (*(short *)((char *)self + 0x610) != 0) {
        *(short *)((char *)self + 0x610) = *(unsigned short *)((char *)self + 0x610) - 1;
    }
    *(ModeTbl *)tbl = D_00429C60;
    i8 = self->mode * 8;
    e = (char *)tbl + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)((char *)self + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)tbl + i8 + 4);
    }
    f0 = tbl[self->mode].delta;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)((char *)self + arg));
    if (self->actorId != ACTOR_NO_POST) {
        func_002A87E8(self, 0);
    }
    func_001B76D8(self);
}

/* Close the poker table: release the display ids, then clear two words of the host record. */


#define POKER_OFFSET_DISP_ID  0x25B0

typedef struct PokerHost {
    char unk00[0x90];
    int clear90;                        /* 0x90 */
    int clear94;                        /* 0x94 */
} PokerHost;

extern PokerHost **D_003C2384;



__attribute__((section(".text.Poker_releaseIds")))
void Poker_releaseIds(Poker *self)
{
    PokerHost *host;
    func_001DEDA8((char *)self + POKER_OFFSET_DISP_ID);
    func_001DD180(self);
    host = *D_003C2384;
    host->clear94 = 0;
    host->clear90 = 0;
}

/* Draw an id-base panel: run its extra draw step when both state bytes are 1, then draw the entries. */


typedef struct cIDPanel {
    cIDBaseObj idBase;
    char unk48[0x13];
    signed char sub;                    /* 0x5B */
    char unk5C[8];
    unsigned char state;                /* 0x64 */
} cIDPanel;


extern void func_00163C58(cIDPanel *self);



__attribute__((section(".text.cIDPanel_trans")))
void cIDPanel_trans(cIDPanel *self)
{
    if (self->state == 1 && self->sub == 1)
        func_00163C58(self);
    NoOp_164978(D_00567D70);
    cIDBase_trans(&self->idBase);
}

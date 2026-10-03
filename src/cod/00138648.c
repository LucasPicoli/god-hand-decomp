/* sn-2.95.3-136 matched TU. */

#include "godhand/cCamera.h"
#include "godhand/vu0.h"
#include "godhand/ColiseumBattle.h"
#include "godhand/cOmBase.h"
#include "godhand/cDamageUnit.h"

extern void sceVu0ApplyMatrix(cVec *out, float *mtx, cVec *in);
extern void sceVu0CameraMatrix(float *out, cVec *p, cVec *zd, cVec *yd);
extern unsigned char D_005CB010;
extern ColiseumEmNode *D_005869F0;
extern void *Getplayer(void);
extern void cOmBase_setMeshDispFromLayer(cOmBase *self, int layer, int on);
extern int SetEffect(int effNo, int kind, void *obj, int a3, int a4, unsigned int a5);
extern int cSnd_SeCall_2CBA48(void *snd, int a1, int a2, void *obj, int a4, int a5, int a6, int a7);
extern char D_005FEE00[];
extern void cDamageUnit_SetDamageCollActive(cDamageUnit *unit, int active);
extern void cCollisionSolidManage_SetActive(void *mgr, void *obj, int active);
extern void KillEffect(void *obj, int effNo, int mode);
extern char D_00462FC0[];

/* Build the view matrix: take the target and the eye through the model
 * matrix, find the view direction (eye minus target) and call the camera
 * matrix builder with the camera's own up vector. */
__attribute__((section(".text.func_00138648")))
void func_00138648(struct cCamera *self) {
    struct {
        cVec p;                         /* 0x00 target in view space */
        cVec e;                         /* 0x10 eye in view space */
        cVec t;                         /* 0x20 view direction */
        cVec zd;                        /* 0x30 */
        cVec yd;                        /* 0x40 */
    } f;
    char *q;
    cVec *tp;
    f.p.x = self->target.x;
    f.p.y = self->target.y;
    f.p.z = self->target.z;
    f.p.w = 1.0f;
    sceVu0ApplyMatrix(&f.p, self->mtx[6], &f.p);
    VU0_SQC2_VF0(&f, 0x10);
    sceVu0ApplyMatrix(&f.e, self->mtx[6], &self->eye);
    q = (char *)&f + 0x30;
    tp = &self->target;
    VU0_SQC2_VF0(&f, 0x30);
    VU0_LQC2(4, &f.e, 0);
    VU0_LQC2(5, tp, 0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, &f, 0x30);
    VU0_LQC2(4, q, 0);
    VU0_SQC2(4, &f, 0x20);
    f.zd.x = f.t.x;
    f.zd.y = f.t.y;
    f.zd.z = f.t.z;
    f.yd.x = self->up.x;
    f.yd.y = self->up.y;
    f.yd.z = self->up.z;
    f.zd.w = 1.0f;
    f.yd.w = 1.0f;
    sceVu0CameraMatrix(self->mtx[5], &f.p, &f.zd, &f.yd);
}

/* Coliseum: clear the nearest-enemy slot, take the player in unless the flag byte is set, then take in every regular enemy. */


#define COLISEUM_NEAR_OFFSET  0xBC8     /* an int field the header leaves in unkBB0 */
#define COLISEUM_NEAR(self)   (*(int *)((char *)(self) + COLISEUM_NEAR_OFFSET))




extern void func_001F0360(ColiseumBattle *self, void *obj);    /* weigh one object as the nearest */

__attribute__((section(".text.func_001F03E8")))
void func_001F03E8(ColiseumBattle *self) {
    ColiseumEmNode *node;
    ColiseumEm *em;
    long ok;
    int k;
    int t;

    COLISEUM_NEAR(self) = 0;
    if (D_005CB010 == 0) {
        func_001F0360(self, Getplayer());
    }
    node = D_005869F0;
    while (node != 0) {
        em = node->em;
        if (em != 0) {
            k = em->kind;
            ok = 0; if (k >= COLISEUM_EM_KIND_FIRST) { t = (k < COLISEUM_EM_KIND_END); ok = t; }
            if (ok & 0xFF) {
                func_001F0360(self, em);
            }
        }
        node = node->next;
    }
}

/* Switch the object's display layers: hide layers 0x32 and 0x33, then by mode show layer 0x32 (mode 0) or 0x33 (mode 1), or for mode 4 start effect 0x298 on it and play sound effect 0x113. */







__attribute__((section(".text.func_00185E68")))
void func_00185E68(cOmBase *self, int mode)
{
    cOmBase_setMeshDispFromLayer(self, 0x32, 0);
    cOmBase_setMeshDispFromLayer(self, 0x33, 0);
    switch (mode) {
    case 0:
        cOmBase_setMeshDispFromLayer(self, 0x32, 1);
        break;
    case 1:
        cOmBase_setMeshDispFromLayer(self, 0x33, 1);
        break;
    case 4:
        SetEffect(0x298, 2, self, 0, -1, -1);
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x113, self, 0, 0, 0, 0);
        break;
    }
}

/* Switch the object off: stop its two damage volumes, clear the active bit of its three collision bodies, drop it from the solid manager, kill two effects, hide mesh layer 1 and go to state step 2. */



#define OMOFF_FLAG_FADE_KILL  0x80000000
#define OMOFF_STEP_OFF        2

/* A collision body as this object sees it; flags is signed so the mask below is an addiu -2. */
typedef struct cOmBodyRec {
    int unk00;
    int state;                          /* 0x04 */
    int flags;                          /* 0x08 bit 0: body active */
} cOmBodyRec;

typedef struct cOmOffBody {
    cOmBase base;
    char unk5E0[0x24];
    cDamageUnit *unit[2];               /* 0x604 damage volumes */
    cOmBodyRec *solid[3];         /* 0x60C collision bodies */
    char unk618[0x9D0 - 0x618];
    unsigned int killFlags;             /* 0x9D0 bit 31: kill with the fade-out mode */
} cOmOffBody;







__attribute__((section(".text.func_001AAC90")))
void func_001AAC90(cOmOffBody *self)
{
    if (self->unit[1] != 0)
        cDamageUnit_SetDamageCollActive(self->unit[1], 0);
    if (self->unit[0] != 0)
        cDamageUnit_SetDamageCollActive(self->unit[0], 0);
    if (self->solid[0] != 0)
        self->solid[0]->flags &= ~1;
    if (self->solid[1] != 0)
        self->solid[1]->flags &= ~1;
    if (self->solid[2] != 0)
        self->solid[2]->flags &= ~1;
    cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
    self->killFlags |= OMOFF_FLAG_FADE_KILL;
    KillEffect(self, 3, 2);
    KillEffect(self, 0xB, 2);
    cOmBase_setMeshDispFromLayer(self, 1, 0);
    self->base.stepArg = 0;
    self->base.mode = 0;
    self->base.phase = 0;
    self->base.step = OMOFF_STEP_OFF;
}

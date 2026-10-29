/* sn-2.95.3-136: enemy setup: flag every mesh, pick a random facing, then build the two damage-give volumes (a box on
 * the body at 0x600, a sphere on part 0 at 0x608), both inactive, with their hit kinds and hit vector. */
#include "godhand/cOmBase.h"
#include "godhand/cOmHitVolumeSetup.h"

#define GIVE_BOX_KIND     0x41
#define GIVE_SPHERE_KIND  0x2E
#define GIVE_POWER        0x14

/* The fields of a damage-give unit this setup writes. */
typedef struct DmgGiveView {
    char unk00[0x40];
    int unk40;                          /* 0x40 -1 at setup */
    short unk44;                        /* 0x44 0 at setup */
    short kind;                         /* 0x46 attack kind */
    char unk48[4];
    int power;                          /* 0x4C */
} DmgGiveView;

/* The enemy this sets up: two damage-give units, the volume ids they returned, a facing
 * and a timer. */
typedef struct cEmTwoGive {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x600 - 0x5E0];
    DmgGiveView *box;                   /* 0x600 damage-give unit on the body */
    int boxId;                          /* 0x604 */
    DmgGiveView *sphere;                /* 0x608 damage-give unit on part 0 */
    int sphereId;                       /* 0x60C */
    char unk610[0x620 - 0x610];
    float facing;                       /* 0x620 random, -pi..pi */
    float timer;                        /* 0x624 210 at setup */
    char unk628[4];
    int unk62C;                         /* 0x62C 0 at setup */
} cEmTwoGive;

extern cMeshNode *cModel_getMeshPtr(void *p, unsigned int i);
extern unsigned int cModel_getMeshNum(void *p);
extern float fRand1_1(void);
extern void cDamageGive_SetDmgGiveHitVec(void *slot, void *vec);
extern char D_00574380[];
extern char D_00747B00[];

__attribute__((section(".text.func_001B90D0")))
int func_001B90D0(cEmTwoGive *self)
{
    cVec v[3];
    cVec *g;
    cVec *h;
    unsigned int i;
    DmgGiveView *d;
    DmgGiveView *e;
    DmgGiveView *q;
    cOmBase *part;
    int n;

    func_001B6FB8((cOmHitVolume *)self);
    for (i = 0; i < cModel_getMeshNum(self); i++)
        cModel_getMeshPtr(self, i)->dispFlags |= 1;
    self->base.unk580 = 0;
    self->base.unk584 = 0;
    self->base.unk588 = 0;
    self->facing = fRand1_1() * 3.1415927f;
    d = cDamageManage_CreateDamageGive(D_00574380, 1, self);
    self->box = d;
    if (d != 0) {
        g = &v[1];
        h = &v[2];
        v[0].y = -0.5f;
        v[0].x = 0.0f;
        v[0].z = 0.0f;
        v[0].w = 1.0f;
        v[1].x = 0.0f;
        v[1].y = 0.0f;
        v[1].z = 0.0f;
        g->w = 1.0f;
        v[2].x = 0.5f;
        h->z = 0.5f;
        h->y = 1.0f;
        h->w = 1.0f;
        self->boxId = func_001FD9D8(d, self->base.mtx, v, g, h);
        cDamageUnit_SetDamageCollActive(self->box, 0);
        self->box->kind = GIVE_BOX_KIND;
        self->box->power = GIVE_POWER;
        cDamageGive_SetDmgGiveHitVec(self->box, D_00747B00);
        q = self->box;
        q->unk40 = -1;
        q->unk44 = 0;
    }
    e = cDamageManage_CreateDamageGive(D_00574380, 0, self);
    self->sphere = e;
    if (e != 0) {
        /* The child count lands in v[0].x first; the stores below overwrite it. */
        *(int *)&v[0] = n = self->base.childNum;
        if (n != 0)
            part = self->base.children[0];
        else
            part = 0;
        v[0].w = 1.0f;
        v[0].x = 0.0f;
        v[0].y = 0.0f;
        v[0].z = 0.0f;
        self->sphereId = cDamageUnit_AddDamageCollSphere(self->sphere, part->mtx, &v[0].x, 0.4f);
        cDamageUnit_SetDamageCollActive(self->sphere, 0);
        self->sphere->kind = GIVE_SPHERE_KIND;
        self->sphere->power = GIVE_POWER;
        cDamageGive_SetDmgGiveHitVec(self->sphere, D_00747B00);
        q = self->sphere;
        q->unk40 = -1;
        q->unk44 = 0;
    }
    self->timer = 210.0f;
    self->unk62C = 0;
    return 1;
}

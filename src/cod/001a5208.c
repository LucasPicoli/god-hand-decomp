/* sn-2.95.3-136 matched TU. */

extern unsigned short D_003F2060[];
extern void func_001B6FB8(void *);
extern int cDamageManage_CreateDamageTake(int a0, int a1, int a2);
extern int cDamageManage_CreateDamageGive(int a0, int a1, int a2);
extern int cDamageUnit_AddDamageCollSphere(int a0, int a1, int a2, float f);
extern void cDamageUnit_SetDamageCollActive(int a0, int a1);
extern void cCollisionSolidManage_CreateUnit(void *a, void *b, int c, float d);
extern void cCollisionSolidManage_CreateSphere(void *a, void *b, int c, void *d, float e);
extern void SetField380Bit2000ForTag_1B7300(void *a0, int a1, int a2);
extern void cOmBase_setMeshDispFromLayer(void *a0, int a1, int a2);
extern int D_00574380;
extern int D_00462FC0;
extern char D_00747B00[];

/* sn-2.95.3-136: a list control stepping its per-slot values from pad flags. */
typedef struct ListSub {
    char unk00[4];
    unsigned char slot;                 /* 0x04 slot being edited */
    char unk05[3];
    short val[5];                       /* 0x08 */
    short idx[5];                       /* 0x12 */
} ListSub;

typedef struct ListCtl {
    char unk00[0x370];
    ListSub sub;                        /* 0x370 */
} ListCtl;

typedef struct ListPad {
    char unk00[0x2C];
    unsigned int mode;                  /* 0x2C bit 1: fast step */
    char unk30[8];
    int flags;                          /* 0x38 */
} ListPad;

#define LIST_FAST        0x2
#define LIST_COARSE      0x40000000
#define LIST_FINE_DOWN   0x8000
#define LIST_FINE_UP     0x2000



extern void func_00383A20(ListCtl *ctl, ListSub *sub);

/* Steps the edited slot of the list control by one or ten and refreshes it. */
__attribute__((section(".text.ListCtl_stepSlot")))
void ListCtl_stepSlot(ListCtl *ctl, ListPad *pad)
{
    ListSub *sub = &ctl->sub;
    short step = 1;
    int flags;

    if (pad->mode & LIST_FAST)
        step = 10;
    flags = pad->flags;
    if (flags < 0) {
        if (ctl->sub.val[sub->slot] >= step - 0x3C0)
            ctl->sub.val[sub->slot] = ctl->sub.val[sub->slot] - step;
        else
            ctl->sub.val[sub->slot] = -0x3C0;
        goto settle;
    }
    if (flags & LIST_COARSE) {
        if (ctl->sub.val[sub->slot] <= -step)
            ctl->sub.val[sub->slot] = step + ctl->sub.val[sub->slot];
        else
            ctl->sub.val[sub->slot] = 0;
settle: /* the duplicated tail was tried and is 4 B short (cross-jumped), so one shared label stays */
        sub->idx[sub->slot] = func_003807E0(ctl, sub->val[sub->slot]);
    } else if (flags & LIST_FINE_DOWN) {
        if (ctl->sub.idx[sub->slot] >= step)
            ctl->sub.idx[sub->slot] = ctl->sub.idx[sub->slot] - step;
        else
            ctl->sub.idx[sub->slot] = 0;
        sub->val[sub->slot] = D_003F2060[sub->idx[sub->slot]];
    } else {
        if ((flags & LIST_FINE_UP) == 0)
            return;
        if (ctl->sub.idx[sub->slot] <= 0x7F - step)
            ctl->sub.idx[sub->slot] = step + ctl->sub.idx[sub->slot];
        else
            ctl->sub.idx[sub->slot] = 0x7F;
        sub->val[sub->slot] = D_003F2060[sub->idx[sub->slot]];
    }
    func_00383A20(ctl, sub);
}

/* sn-2.95.3-136: a sound message node built from a playing sound, one per voice pair. */
typedef struct SndNode {
    short kind;                         /* 0x00 */
    char unk02[2];
    int handle;                         /* 0x04 */
    int srcHandle;                      /* 0x08 */
    unsigned char prio;                 /* 0x0C */
    unsigned char mode;                 /* 0x0D */
    short ofsA;                         /* 0x0E */
    short ofsB;                         /* 0x10 */
    unsigned short srcId;               /* 0x12 */
    short voice;                        /* 0x14 */
    short unk16;                        /* 0x16 */
    unsigned short tab60;               /* 0x18 */
    unsigned short tab68;               /* 0x1A */
    unsigned short tab70;               /* 0x1C */
    short unk1E;                        /* 0x1E */
    short neg20;                        /* 0x20 */
    short neg22;                        /* 0x22 */
    short neg24;                        /* 0x24 */
    unsigned char vol;                  /* 0x26 */
    unsigned char unk27;                /* 0x27 */
    unsigned char level;                /* 0x28 */
    unsigned char unk29;                /* 0x29 */
    short unk2A;                        /* 0x2A */
    unsigned short loop;                /* 0x2C */
    short code;                         /* 0x2E */
    unsigned short var5C;               /* 0x30 */
    unsigned short var5E;               /* 0x32 */
    unsigned short tab70b;              /* 0x34 */
    short unk36;                        /* 0x36 */
    short unk38;                        /* 0x38 */
    short unk3A;                        /* 0x3A */
    short unk3C;                        /* 0x3C */
    signed char tail;                   /* 0x3E */
    char unk3F;
    unsigned char z40, z41, z42, z43;   /* 0x40 */
} SndNode;                              /* 0x44 */

typedef struct SndSrc {
    char unk00[2];
    unsigned short id;                  /* 0x02 */
    int handle;                         /* 0x04 */
    char unk08[6];
    unsigned char prio;                 /* 0x0E */
    char unk0F[3];
    unsigned short flags;               /* 0x12 */
    char unk14[4];
    int slot[0x44 / 4];                 /* 0x18 node handle per voice */
    unsigned short var5C;               /* 0x5C */
    unsigned short var5E;               /* 0x5E */
    unsigned short tab60[4];            /* 0x60 */
    unsigned short tab68[4];            /* 0x68 */
    unsigned short tab70[2];            /* 0x70 */
} SndSrc;

typedef struct SndRow {
    char unk00[7];
    unsigned char base;                 /* 0x07 */
} SndRow;




/* Queues a node for voice `voice` of the source; the node copies the source's per-voice tables. */
__attribute__((section(".text.SndMsg_buildVoiceNode")))
int SndMsg_buildVoiceNode(SndSrc *src, SndRow *row, unsigned int voice)
{
    SndNode *n;
    int code;

    src->slot[voice] = func_00377FF8();
    n = func_0037D170();
    if (n == 0)
        return -1;
    n->kind = 1;
    n->handle = src->slot[voice];
    n->srcHandle = src->handle;
    n->prio = src->prio;
    n->mode = 2;
    n->ofsA = -1;
    n->ofsB = 0;
    n->srcId = src->id;
    n->voice = voice;
    n->unk16 = 0;
    n->tab60 = src->tab60[voice >> 1];
    n->tab68 = src->tab68[voice >> 1];
    code = 0x17;
    n->tab70 = src->tab70[voice & 1];
    n->unk1E = 0;
    n->neg20 = -1;
    n->neg22 = -1;
    n->neg24 = -1;
    n->vol = row->base + voice;
    n->unk27 = 0;
    n->level = 0x7F;
    n->unk29 = 0;
    n->unk2A = 0;
    if (src->flags & 1)
        n->loop = 1;
    else
        n->loop = 0;
    n->code = code;
    n->var5C = src->var5C;
    n->var5E = src->var5E;
    n->tab70b = src->tab70[voice & 1];
    n->unk36 = 0;
    n->unk38 = 0;
    n->unk3A = 0;
    n->unk3C = 0;
    n->tail = -1;
    n->z41 = 0;
    n->z40 = 0;
    n->z43 = 0;
    n->z42 = 0;
    return 0;
}

/* sn-2.95.3-136: the mixer settings block at D_0076A790 as the voice level code reads it. */
typedef struct SndMixCfg {
    char unk00[0x14];
    int stereo;                         /* 0x14 2 selects the second pair of levels */
    char unk18[0x22];
    short lvlA;                         /* 0x3A */
    short lvlB;                         /* 0x3C */
    short lvlC;                         /* 0x3E */
    short lvlD;                         /* 0x40 */
    short lvlE;                         /* 0x42 */
} SndMixCfg;

typedef struct SndMixVoice {
    char unk00[4];
    unsigned char flags;                /* 0x04 bit 0 picks the level of the pair */
    unsigned char kind;                 /* 0x05 */
    char unk06[0x20];
    unsigned short gainL1;              /* 0x26 */
    unsigned short gainR1;              /* 0x28 */
    short gain;                         /* 0x2A */
    char unk2C[4];
    short scale;                        /* 0x30 */
    char unk32[6];
    unsigned short gainL2;              /* 0x38 */
    unsigned short gainR2;              /* 0x3A */
    short pan;                          /* 0x3C */
    short level;                        /* 0x3E result */
} SndMixVoice;

#define SNDMIX_DEN   0x7F00             /* full scale of a level product */

extern SndMixCfg D_0076A790;

/* Computes a voice's output level from the mixer settings, its gain and its pan. */
__attribute__((section(".text.SndMix_calcVoiceLevel")))
void SndMix_calcVoiceLevel(SndMixVoice *v)
{
    SndMixCfg *cfg = &D_0076A790;
    int r = 0;

    if (cfg->stereo == 2) {
        v->pan = v->gainR2;
        v->gain = v->gainR1;
    } else {
        v->pan = v->gainL2;
        v->gain = v->gainL1;
    }
    if (v->pan == 0x80)
        v->pan = 0x7FFF;
    else
        v->pan = v->pan << 8;
    switch (v->kind) {
    case 9:
        r = cfg->lvlA * v->pan / SNDMIX_DEN * v->scale / SNDMIX_DEN;
        break;
    case 1:
        r = cfg->lvlA * v->pan / SNDMIX_DEN * v->scale / SNDMIX_DEN;
        break;
    case 2:
        if (v->flags & 1)
            r = cfg->lvlB * v->gain / SNDMIX_DEN;
        else
            r = cfg->lvlC * v->gain / SNDMIX_DEN;
        break;
    case 4:
        if (v->flags & 1)
            r = cfg->lvlD * v->gain / SNDMIX_DEN;
        else
            r = cfg->lvlE * v->gain / SNDMIX_DEN;
        r = r * v->pan / SNDMIX_DEN;
        break;
    }
    v->level = r;
}

/* sn-2.95.3-136: set up a map object that gives and takes damage and collides as a sphere. */













#define OBJ_GIVE         0x620      /* give-damage unit handle */
#define OBJ_TAKE         0x624      /* take-damage unit handle */
#define OBJ_MTX_PTR      0x278      /* pointer to the first child record */
#define OBJ_MTX_FLAG     0x2B4      /* nonzero when OBJ_MTX_PTR is valid */
#define GIVE_SPHERE      2.0f
#define TAKE_SPHERE      2.5f
#define SOLID_RADIUS     0.3f
#define SOLID_SPHERE     1.9f
#define GIVE_HIT_KIND    0x55
#define GIVE_DAMAGE      100
#define HIT_SIZE         0x14

__attribute__((section(".text.cOmGiveTake_initSphere")))
int cOmGiveTake_initSphere(char *p)
{
    float buf[8] __attribute__((aligned(16)));
    float *sph;
    int n;
    int m;
    int k;
    void *solid;
    int flag;
    char *vt;

    func_001B6FB8(p);
    *(int *)(p + OBJ_GIVE) = cDamageManage_CreateDamageGive((int)&D_00574380, 2, (int)p);
    if (*(int *)(p + OBJ_GIVE) != 0) {
        flag = *(unsigned char *)(p + OBJ_MTX_FLAG);
        *(int *)buf = flag;
        if (flag)
            n = **(int **)(p + OBJ_MTX_PTR);
        else
            n = 0;
        buf[4] = 0.0f;
        buf[5] = 0.0f;
        buf[6] = 0.0f;
        sph = buf + 4;
        sph[3] = 1.0f;
        cDamageUnit_AddDamageCollSphere(*(int *)(p + OBJ_GIVE), n + 0x80, (int)sph, GIVE_SPHERE);
        *(short *)(*(int *)(p + OBJ_GIVE) + 0x46) = GIVE_HIT_KIND;
        *(int *)(*(int *)(p + OBJ_GIVE) + 0x4C) = GIVE_DAMAGE;
        cDamageUnit_SetDamageCollActive(*(int *)(p + OBJ_GIVE), 0);
    }
    *(int *)(p + OBJ_TAKE) = cDamageManage_CreateDamageTake((int)&D_00574380, (int)p, 2);
    if (*(int *)(p + OBJ_TAKE) != 0) {
        flag = *(unsigned char *)(p + OBJ_MTX_FLAG);
        *(int *)buf = flag;
        if (flag)
            m = **(int **)(p + OBJ_MTX_PTR);
        else
            m = 0;
        buf[3] = 1.0f;
        buf[0] = 0.0f;
        buf[1] = 0.0f;
        buf[2] = 0.0f;
        cDamageUnit_AddDamageCollSphere(*(int *)(p + OBJ_TAKE), m + 0x80, (int)buf, TAKE_SPHERE);
        *(int *)(*(int *)(p + OBJ_TAKE)) |= 1;
        cDamageUnit_SetDamageCollActive(*(int *)(p + OBJ_TAKE), 1);
    }
    solid = &D_00462FC0;
    *(short *)(p + 0x548) = HIT_SIZE;
    *(short *)(p + 0x54A) = HIT_SIZE;
    cCollisionSolidManage_CreateUnit(solid, p, 0, SOLID_RADIUS);
    flag = *(unsigned char *)(p + OBJ_MTX_FLAG);
    *(int *)buf = flag;
    if (flag)
        k = **(int **)(p + OBJ_MTX_PTR);
    else
        k = 0;
    buf[3] = 1.0f;
    buf[0] = 0.0f;
    buf[1] = 0.0f;
    buf[2] = 0.0f;
    cCollisionSolidManage_CreateSphere(solid, p, k + 0x80, buf, SOLID_SPHERE);
    SetField380Bit2000ForTag_1B7300(p, 0, 0);
    SetField380Bit2000ForTag_1B7300(p, 0x40, 0);
    *(int *)(p + 0x250) |= 0x10000;
    cOmBase_setMeshDispFromLayer(p, 0, 1);
    cOmBase_setMeshDispFromLayer(p, 0x40, 0);
    *(int *)(p + 0x5B8) |= 8;
    vt = *(char **)(p + 0x214);
    (*(void (**)(char *, char *))(vt + 0x74))(p + *(short *)(vt + 0x70), D_00747B00);
    vt = *(char **)(p + 0x214);
    (*(void (**)(char *, char *))(vt + 0x7C))(p + *(short *)(vt + 0x78), D_00747B00);
    return 1;
}

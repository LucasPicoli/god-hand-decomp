/* sn-2.95.3-136 matched TU. */

#include "godhand/cEm00.h"
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"
#include "godhand/CustomIDWork.h"

extern unsigned short D_00747A50;
extern void func_0026ECD0(cEm00 *self, int flag);
extern float ESLib_ESHermite(float t, float p0, float p1, float m0, float m1);
extern char D_0044E960[];
extern void cHeap_free(int heap, int *block);
extern void cIDBase_initIDWork(void *part, int idx);
extern CustomIDWork *cIDBase_getIDWork(void *part, int idx);
extern void StoreVecFromFieldB0_2B6160(void *dst, void *self);
extern float capVu0Length(void *a0);
extern char *D_005CAFF0;

#define EMFLAGS_NO_REACT   0x40000      /* emFlags: the enemy ignores the trigger */
#define EM_NO_A            0x256
#define EM_NO_B            0x218
#define ROOM_NO_A          0x406        /* D_00747A50 value that blocks enemy 0x256 */
#define ROOM_NO_B          0x1          /* D_00747A50 value that blocks enemy 0x218 */





/* Trigger the enemy's reaction when allowed: not while its slide runs, only when
 * func_0026F328 accepts, the flag does not forbid it, it is alive, and for
 * enemies 0x256 and 0x218 only outside their blocked rooms. Returns 1 when it fired. */
__attribute__((section(".text.cEm00_tryReact")))
int cEm00_tryReact(cEm00 *self)
{
    if (self->slideTime > 0.0f)
        return 0;
    if (func_0026F328(self) == 0)
        return 0;
    if (self->emFlags & EMFLAGS_NO_REACT)
        return 0;
    if (self->vital <= 0)
        return 0;
    if (self->emNo == EM_NO_A && D_00747A50 == ROOM_NO_A)
        return 0;
    if (self->emNo == EM_NO_B && D_00747A50 == ROOM_NO_B)
        return 0;
    func_0026ECD0(self, 1);
    return 1;
}

/* Hermite-interpolate each of x, y and z between two points with zero
 * tangents into *tmp, copy the vector to *ret and return ret. The struct
 * return of retail is passed as the first argument. */
__attribute__((section(".text.Hermite3_interpolate")))
cVec *Hermite3_interpolate(cVec *ret, cVec *tmp, float *p0, float *p1, float t)
{
    tmp->x = ESLib_ESHermite(t, p0[0], p1[0], 0.0f, 0.0f);
    tmp->y = ESLib_ESHermite(t, p0[1], p1[1], 0.0f, 0.0f);
    tmp->z = ESLib_ESHermite(t, p0[2], p1[2], 0.0f, 0.0f);
    VU0_LQC2(4, tmp, 0);
    VU0_SQC2(4, ret, 0);
    return ret;
}

/* An object that owns six heap blocks; each block's heap handle is stored
 * 0x20 bytes before it. */
typedef struct BlockOwner {
    char unk000[0xF0];
    void *vt;                           /* 0xF0 */
    char unkF4[0x1C8];
    int *blockBC;                       /* 0x2BC */
    int *blockC0;                       /* 0x2C0 */
    int *blockC4;                       /* 0x2C4 */
    int *blockC8;                       /* 0x2C8 */
    int *blockCC;                       /* 0x2CC */
    int *blockD0;                       /* 0x2D0 */
} BlockOwner;

#define BLOCK_HEAP(b)  ((b)[-8])        /* heap handle kept in front of the block */



extern void func_002FBE28(BlockOwner *self, int flags);

/* Destructor: reset the method table, free the six blocks, then run the base destructor. */
__attribute__((section(".text.BlockOwner_dtor")))
void BlockOwner_dtor(BlockOwner *self, int flags)
{
    self->vt = D_0044E960;
    if (self->blockCC != 0)
        cHeap_free(BLOCK_HEAP(self->blockCC), self->blockCC);
    if (self->blockD0 != 0)
        cHeap_free(BLOCK_HEAP(self->blockD0), self->blockD0);
    if (self->blockC4 != 0)
        cHeap_free(BLOCK_HEAP(self->blockC4), self->blockC4);
    if (self->blockC8 != 0)
        cHeap_free(BLOCK_HEAP(self->blockC8), self->blockC8);
    if (self->blockBC != 0)
        cHeap_free(BLOCK_HEAP(self->blockBC), self->blockBC);
    if (self->blockC0 != 0)
        cHeap_free(BLOCK_HEAP(self->blockC0), self->blockC0);
    func_002FBE28(self, flags);
}

#define IDPAIR_WORK_NUM  4
#define IDPAIR_AMP       (-50.0f)       /* sine amplitude of the first element of each part */

/* A display with two cIDBase parts, at 0 and 0xA0, and four state bytes at 0x79. */
typedef struct IdPair {
    char unk00[0x79];
    unsigned char state[4];             /* 0x79 */
    char unk7D[0x85];
    short timer;                        /* 0x102 */
} IdPair;




/* Clear the state bytes, initialise the four elements of both parts, give
 * the first element of each part its sine amplitude and set the timer to 90. */
__attribute__((section(".text.IdPair_init")))
void IdPair_init(IdPair *self)
{
    unsigned short i;
    char *part;

    i = 0;
    self->state[0] = 0;
    self->state[1] = 0;
    self->state[2] = 0;
    self->state[3] = 0;
    do {
        cIDBase_initIDWork(self, i);
        i = i + 1;
    } while (i < IDPAIR_WORK_NUM);
    cIDBase_getIDWork(self, 0)->offsAmp[0] = IDPAIR_AMP;
    i = 0;
    part = (char *)self + 0xA0;
    do {
        cIDBase_initIDWork(part, i);
        i = i + 1;
    } while (i < IDPAIR_WORK_NUM);
    cIDBase_getIDWork(part, 0)->offsAmp[0] = IDPAIR_AMP;
    self->timer = 0x5A;
}

/* A trigger object with a reach (a float at 0x2B8); 0 means it always fires. */
typedef struct ReachObj {
    char unk000[0x2B8];
    float reach;                        /* 0x2B8 */
} ReachObj;

/* True when the object has no reach or the scaled distance from its anchor to
 * the reference point at D_005CAFF0 + 0x210 is within the reach. */
__attribute__((section(".text.ReachObj_isWithinReach")))
int ReachObj_isWithinReach(ReachObj *self)
{
    float buf[8];

    StoreVecFromFieldB0_2B6160(buf, self);
    VU0_LQC2(4, D_005CAFF0 + 0x210, 0);
    VU0_SQC2(4, buf, 0x10);
    if (self->reach == 0.0f)
        return 1;
    {
        float k = 1000.0f;

        buf[0] = buf[0] - buf[4];
        buf[1] = buf[1] - buf[5];
        buf[2] = buf[2] - buf[6];
        VU0_LQC2(4, buf, 0);
        VU0_LOAD_SCALAR(5, k);
        VU0_VMULX_XYZ(4, 4, 5);
        VU0_SQC2(4, buf, 0);
    }
    if (self->reach < capVu0Length(buf))
        return 0;
    return 1;
}

#define PANEL_KEY_DEFAULT  0xD
#define PANEL_STEP_LEFT    0x11
#define PANEL_STEP_RIGHT   0x12
#define PANEL_STEP_SAME    0x13

typedef struct PanelObj {
    char unk00[4];
} PanelObj;

/* The record a competitor points to: its ranking key at 0x604 (0 = default). */
typedef struct Competitor {
    char unk000[0x604];
    int key;                            /* 0x604 */
} Competitor;

typedef struct CompetitorRef {
    Competitor *who;                    /* 0x00 */
} CompetitorRef;

/* The panel owner: the panel record at 0x25B0, the two competitors being
 * compared at 0x3004 and 0x3008 and the phase machine bytes at 0x3024. */
typedef struct PanelOwner {
    char unk0000[0x25B0];
    PanelObj panel;                     /* 0x25B0 */
    char unk25B4[0xA50];
    CompetitorRef *left;                /* 0x3004 */
    CompetitorRef *right;               /* 0x3008 */
    char unk300C[0x18];
    unsigned char step;                 /* 0x3024 */
    unsigned char sub;                  /* 0x3025 */
    char unk3026[0x1E];
    unsigned char reversed;             /* 0x3044 */
} PanelOwner;

extern void PanelObj_setCursorMode(PanelObj *self, unsigned char mode);
extern void PanelObj_setArrowMode(PanelObj *self, unsigned char mode);

/* Move to a step and restart its sub-step. Written as a helper so that every
 * arm ends in the same store pair, in retail's order (sub first). */
static __inline__ void PanelOwner_setStep(PanelOwner *self, int step)
{
    self->sub = 0;
    self->step = step;
}

/* Reset the panel cursor and arrows, compare the two competitors' keys and
 * pick the next step: 0x12 when the left key is lower, 0x11 when it is higher
 * (swapped by the reversed flag), 0x13 when they tie. */
__attribute__((section(".text.PanelOwner_pickStep")))
void PanelOwner_pickStep(PanelOwner *self)
{
    int a;
    int b;

    PanelObj_setCursorMode(&self->panel, 0);
    PanelObj_setArrowMode(&self->panel, 0);
    a = self->left->who->key;
    b = self->right->who->key;
    if (a == 0)
        a = PANEL_KEY_DEFAULT;
    if (b == 0)
        b = PANEL_KEY_DEFAULT;
    if (a < b) {
        if (self->reversed)
            PanelOwner_setStep(self, PANEL_STEP_LEFT);
        else
            PanelOwner_setStep(self, PANEL_STEP_RIGHT);
    } else if (b < a) {
        if (self->reversed)
            PanelOwner_setStep(self, PANEL_STEP_RIGHT);
        else
            PanelOwner_setStep(self, PANEL_STEP_LEFT);
    } else {
        PanelOwner_setStep(self, PANEL_STEP_SAME);
    }
}

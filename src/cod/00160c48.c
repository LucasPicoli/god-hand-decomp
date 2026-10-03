/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/cNode.h"

extern float Adjust_theta(float f12);
extern float capVu0Sin(float f12);
extern float capVu0Cos(float f12);
extern void func_002FBED0(cNode *node);
extern void StoreVecFromFieldB0_2B6160(void *dst, cNode *node);
extern void *cCamera_getScreenPos(void *out, void *cam, void *vec);
extern void *D_005CAFF0;
extern unsigned char D_0061B644;

extern char *func_001F0498(void *owner, int obj, cVec *pos, float angle);     /* create one piece */

#define RING_NUM      5
#define RING_STEP     72.0f             /* degrees between two pieces */
#define RING_RADIUS   8.0f
#define RING_OBJ      0x3ED
#define DEG_TO_RAD    0.017453292f

/* Place five pieces (object 0x3ED) evenly on a circle of radius 8 around the origin. */
__attribute__((section(".text.Ring_spawnPieces")))
void Ring_spawnPieces(void *self) {
    int i;
    for (i = 0; i < RING_NUM; i++) {
        cVec pos;
        float a = Adjust_theta((float)i * RING_STEP * DEG_TO_RAD);
        float x = capVu0Sin(a) * RING_RADIUS;
        float z = capVu0Cos(a) * RING_RADIUS;
        pos.x = x;
        pos.y = 0.0f;
        pos.z = z;
        pos.w = 1.0f;
        func_001F0498(self, RING_OBJ, &pos, 0.0f);
    }
}

/* A fading overlay: state, a colour word whose top byte is the alpha, and a tick counter. */
typedef struct FadeOverlay {
    char unk000[0xED0];
    unsigned int color;                 /* 0xED0 low 24 bits rgb, top byte alpha */
    unsigned char state;                /* 0xED4 FADE_* */
    char unkED5[3];
    int tick;                           /* 0xED8 counts up while a fade runs */
} FadeOverlay;

#define FADE_IDLE      0                /* nothing shown */
#define FADE_HOLD      1                /* fully shown */
#define FADE_IN        2                /* alpha rises with tick */
#define FADE_OUT       3                /* alpha falls with tick */
#define FADE_TICKS     4                /* length of a fade */
#define FADE_ALPHA_MAX 128.0f
#define FADE_RGB_MASK  0xFFFFFF

/* Advance the fade one tick: set the alpha from the tick count and switch state when the fade ends. */
__attribute__((section(".text.FadeOverlay_tick")))
void FadeOverlay_tick(FadeOverlay *self) {
    if (self->state == FADE_IDLE) return;
    if (self->state == FADE_HOLD) return;
    if (self->state == FADE_IN) {
        int t = self->tick;
        self->color = (self->color & FADE_RGB_MASK) | ((int)((float)t * 0.25f * FADE_ALPHA_MAX) << 24);
        if (t == FADE_TICKS) {
            self->state = FADE_IDLE;
        }
    }
    if (self->state == FADE_OUT) {
        int t = self->tick;
        self->color = (self->color & FADE_RGB_MASK) | ((int)((1.0f - (float)t * 0.25f) * FADE_ALPHA_MAX) << 24);
        if (t == FADE_TICKS) {
            self->state = FADE_HOLD;
        }
    }
    self->tick = self->tick + 1;
}

extern int D_003C1180;                  /* screen width */
extern int D_003C118C;                  /* screen height */

/* A node that keeps its last screen position. */
typedef struct cScreenNode {
    cNode base;
    char unkF4[0x2C0 - sizeof(cNode)];
    float screenX;                      /* 0x2C0 */
    float screenY;                      /* 0x2C4 */
} cScreenNode;

/* Update the node, project its world position to the screen and store it, clamped inside the screen, in the node. */
__attribute__((section(".text.cScreenNode_updateScreenPos")))
void cScreenNode_updateScreenPos(cScreenNode *self) {
    float world[4] __attribute__((aligned(16)));
    float scr[4] __attribute__((aligned(16)));

    func_002FBED0(&self->base);
    StoreVecFromFieldB0_2B6160(world, &self->base);
    cCamera_getScreenPos(scr, D_005CAFF0, world);
    D_0061B644 = 1;
    if (scr[0] <= 0.0f) {
        scr[0] = 1.0f;
    }
    if ((float)D_003C1180 <= scr[0]) {
        scr[0] = (float)(D_003C1180 - 1);
    }
    if (scr[1] <= 0.0f) {
        scr[1] = 1.0f;
    }
    if ((float)D_003C118C <= scr[1]) {
        scr[1] = (float)(D_003C118C - 1);
    }
    self->screenX = scr[0];
    self->screenY = scr[1];
}

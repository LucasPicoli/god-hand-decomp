/* sn-2.95.3-136: func_00194558, breakable object update: break when the player touches its trigger or its life runs out, play the hit sound and flash the mesh for 8 frames after a hit. */
#include "godhand/cOmBase.h"
#include "godhand/player.h"

#define BREAK_FLASH_FRAMES  8
#define BREAK_MESH_LAYER    2
#define BREAK_HIT_SE        0x8C

/* A breakable object: the volume that receives hits, the trigger the player can touch,
 * and the flash countdown. */
typedef struct cOmBreakObj {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x604 - 0x5E0];
    cDamageTake *give;                  /* 0x604 the volume cOmBase_checkDamage tests */
    void *trigger;                      /* 0x608 touch trigger, 0 when none */
    char unk60C[0xAF4 - 0x60C];
    int flash;                          /* 0xAF4 frames of hit flash left */
} cOmBreakObj;

extern unsigned char D_005CB010;
extern unsigned char D_005FEE00[];
extern int func_001FDD38(void *trigger, void *pl);
extern int cOmBase_checkDamage(cOmBase *self, cDamageTake *give);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, void *f, int g, int h);
extern void cOmBase_setMeshColorFromLayer(void *self, int layer, float r, float g, float b);

static inline void setDown(cOmBreakObj *self)
{
    self->base.flags0 |= 1;
    self->base.mode = 2;
    self->base.phase = 0;
    self->base.step = 0;
    self->base.stepArg = 0;
}

static inline void *getPart(cOmBreakObj *self, int i)
{
    int frame[3];

    return cOmBase_childAt(&self->base, frame, i);
}

__attribute__((section(".text.func_00194558")))
void func_00194558(cOmBreakObj *self)
{
    if (self->trigger != 0 && D_005CB010 != 0) {
        if (func_001FDD38(self->trigger, Getplayer()) == 1)
            setDown(self);
    }
    if (cOmBase_checkDamage(&self->base, self->give) == 1) {
        if (self->base.hp <= 0) {
            setDown(self);
        } else {
            void *part = getPart(self, 1);
            cSnd_SeCall_2CBA48(D_005FEE00, 2, BREAK_HIT_SE, self, 0, part, 0, 0);
            self->flash = BREAK_FLASH_FRAMES;
        }
    }
    if (self->flash != 0) {
        if (--self->flash != 0) {
            if (self->flash & 1)
                cOmBase_setMeshColorFromLayer(self, BREAK_MESH_LAYER, 1.0f, 1.0f, 1.0f);
            else
                cOmBase_setMeshColorFromLayer(self, BREAK_MESH_LAYER, 1.0f, 0.0f, 0.0f);
        } else {
            cOmBase_setMeshColorFromLayer(self, BREAK_MESH_LAYER, 1.0f, 1.0f, 1.0f);
        }
    }
}

/* sn-2.95.3-136: func_00194558, breakable object update: break when the player touches its trigger or its life runs out, play the hit sound and flash the mesh for 8 frames after a hit. */
#include "godhand/cOmBase.h"
#include "godhand/player.h"
extern unsigned char D_005CB010;
extern unsigned char D_005FEE00[];
extern int func_001FDD38(void *trigger, void *pl);
extern int cOmBase_checkDamage(cOmBase *self, cDamageTake *give);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, void *f, int g, int h);
extern void cOmBase_setMeshColorFromLayer(void *self, int layer, float r, float g, float b);

static inline void setDown(char *p)
{
    *(unsigned int *)(p + 0x5B0) |= 1;
    *(unsigned char *)(p + 0x2F4) = 2;
    *(unsigned char *)(p + 0x2F5) = 0;
    *(unsigned char *)(p + 0x2F6) = 0;
    *(unsigned char *)(p + 0x2F7) = 0;
}

static inline void *getPart(char *p, int i)
{
    int frame[3];

    return cOmBase_childAt((cOmBase *)p, frame, i);
}

__attribute__((section(".text.func_00194558")))
void func_00194558(char *p)
{
    if (*(void **)(p + 0x608) != 0 && D_005CB010 != 0) {
        if (func_001FDD38(*(void **)(p + 0x608), Getplayer()) == 1)
            setDown(p);
    }
    if (cOmBase_checkDamage(p, *(void **)(p + 0x604)) == 1) {
        if (*(short *)(p + 0x54A) <= 0) {
            setDown(p);
        } else {
            void *part = getPart(p, 1);
            cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x8C, p, 0, part, 0, 0);
            *(int *)(p + 0xAF4) = 8;
        }
    }
    if (*(int *)(p + 0xAF4) != 0) {
        if (--*(int *)(p + 0xAF4) != 0) {
            if (*(int *)(p + 0xAF4) & 1)
                cOmBase_setMeshColorFromLayer(p, 2, 1.0f, 1.0f, 1.0f);
            else
                cOmBase_setMeshColorFromLayer(p, 2, 1.0f, 0.0f, 0.0f);
        } else {
            cOmBase_setMeshColorFromLayer(p, 2, 1.0f, 1.0f, 1.0f);
        }
    }
}

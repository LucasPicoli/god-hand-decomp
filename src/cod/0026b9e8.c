/* sn-2.95.3-136 matched TU. */

#include "godhand/player.h"
extern void func_001D0090(void *obj, void *owner);

#define ACTION_SPAWN   0x211            /* action id that spawns the child */
#define ACTOR_CHILD    0x3B8
#define CHILD_OFFSET_Y 0.6f             /* spawn height offset below the owner position */

/* While in action 0x211, create the child object 0x3B8, put it at the owner's position lowered by 0.6, mirror that in its own position copy, link it to the owner and store it at 0x730. */
__attribute__((section(".text.Spawner_spawnChild")))
void Spawner_spawnChild(char *self)
{
    char *obj;
    float *dst;
    float *src;
    float *copy;
    char *linked;
    int *p100;

    if ((*(int *)(self + 0x564) ^ ACTION_SPAWN) != 0) {
        return;
    }
    obj = (char *)CreateObj(ACTOR_CHILD, 0xFFFF);
    if (obj == 0) {
        return;
    }
    {
        char *vt = *(char **)(obj + 0x214);
        int (*fn)(char *) = *(int (**)(char *))(vt + 0x44);
        short off = *(short *)(vt + 0x40);
        fn(obj + off);
    }
    /* the odd local chains below (copy, src as p100, linked) are what the permuter found; each one changes the bytes */
    copy = *(float **)(obj + 0xF0);
    dst = copy;
    src = *(float **)(self + 0xF0);
    if (dst != src) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
    }
    dst = *(float **)(obj + 0xF0);
    dst[1] = dst[1] - CHILD_OFFSET_Y;
    copy = (float *)(obj + 0x490);
    dst = *(float **)(obj + 0xF0);
    if (copy != dst) {
        copy[0] = dst[0];
        copy[1] = dst[1];
        copy[2] = dst[2];
    }
    src = (int *)(obj + 0x100);
    p100 = src;
    p100[0] = 0;
    p100[1] = 0;
    p100[2] = 0;
    func_001D0090(obj, self);
    *(char **)(self + 0x730) = (linked = obj);
}

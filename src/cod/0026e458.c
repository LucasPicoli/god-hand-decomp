/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cEm00.h"
#include "godhand/cEmManage.h"

extern unsigned short D_00747A50;
extern unsigned char cOmbb_ckFire(void *actor);
extern int cOmbb_ckCountdown(void *actor);
extern void cOmbb_initCountdown(void *actor);

extern void cEm00_setGoto(cEm00 *self, cVec *pos, int a2, int a3, float f);

#define ROOM_FIRE_FIGHT     0x204       /* D_00747A50 value of the room where this applies */
#define GOTO_FIRE_SPEED     300.0f
#define GOTO_FIRE_MODE      0xD
#define PHASE_GOTO_FIRE     0x13
#define EM_ACTOR_FIRE_PROP  0x3B7       /* actor id of the object at 0x6EC that sets this off */

/* The held object pointer: a cEm00 field that cEm00.h does not name yet. */
#define EM_HELD_OBJ(self)   (*(cEm00 **)((char *)(self) + 0x6EC))

/* In the fire room: find a burning-free fire actor while the enemy holds the fire prop, and send the enemy to it. Returns 1 if it set the goto up. */
__attribute__((section(".text.func_0026E458")))
int func_0026E458(cEm00 *self) {
    cVec pos __attribute__((aligned(16)));
    cEmActor *actor;
    unsigned int i;

    if (D_00747A50 != ROOM_FIRE_FIGHT) {
        return 0;
    }
    for (i = 0; i < 2; i++) {
        actor = func_002948C8(&D_005864F0, i);
        if (actor != 0) {
            if (EM_HELD_OBJ(self) != 0) {
                if ((EM_HELD_OBJ(self)->actorId ^ EM_ACTOR_FIRE_PROP) == 0) {
                    if (cOmbb_ckFire(actor) == 0) {
                        if (cOmbb_ckCountdown(actor) == 0) {
                            VU0_SQC2_VF0(&pos, 0);
                            cVec_copy3(&pos, func_001B8720(actor));
                            cEm00_setGoto(self, &pos, GOTO_FIRE_MODE, 0, GOTO_FIRE_SPEED);
                            self->unk17B1 = i;
                            self->phase = PHASE_GOTO_FIRE;
                            self->step = 0;
                            self->stepArg = 0;
                            self->mode = 0;
                            cOmbb_initCountdown(actor);
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

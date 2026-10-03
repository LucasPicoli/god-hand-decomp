#include "godhand/cSaveLoad.h"
#include "godhand/cDoor.h"

/* sn-2.95.3-136 matched TU. */

extern void KillEffect(void *a0, int a1, int a2);
extern int D_00747A84;
extern void func_002000F8(cDoor *self);

#define SYS_FLAG_DOOR_STEP  0x2000000   /* D_00747A84: the door step is running */

extern cSaveLoadGlobals D_00747A2C;
extern void cSaveManager_setCheckPoint(void *a0, int a1, int a2, int a3);

#define SYS_MODE_BELOW      8           /* the mode flag word D_00747A24 sits 8 bytes below the block */

#define SYS_MODE_NO_SAVE    0x8000000


__attribute__((section(".text.func_00305F58")))
void func_00305F58(void *a0, int a1) {
    char *p = (char *)a0;
    int m = 1 << a1;
    int f = *(int *)(p + 0x414);
    if ((f & m) != 0) {
        *(int *)(p + 0x414) = f & ~m;
        KillEffect(0, a1 + 0x2200, 2);
    }
}

/* Count the door's wait down; while the step flag is set, run the jump step. */
__attribute__((section(".text.func_001FFE10")))
void func_001FFE10(cDoor *self) {
    if (self->wait != 0) {
        self->wait = (unsigned short)self->wait - 1;
    }
    if ((D_00747A84 & SYS_FLAG_DOOR_STEP) != 0) {
        func_002000F8(self);
    }
}

/* Take a checkpoint unless card access is locked (flag word at 0x08) or the
 * mode word forbids it (bit 27 of the word 8 bytes below the block). */
__attribute__((section(".text.func_002BF8F8")))
void func_002BF8F8(char *a0) {
    cSaveLoadGlobals *p = &D_00747A2C;
    if ((p->flags & SAVELOAD_FLAG_LOCK) != 0) {
        return;
    }
    if ((*(int *)((char *)p - SYS_MODE_BELOW) & SYS_MODE_NO_SAVE) != 0) {
        return;
    }
    cSaveManager_setCheckPoint(a0, 0, 0, 0);
}

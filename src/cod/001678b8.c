/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cOmDoor.h"
#include "godhand/cSceAtManager.h"

extern void *D_003C264C;
extern char D_005FEE00[];
extern void cSaveManager_stageClear(void *self);
extern void func_002CABE0(void *bus);
extern unsigned int D_00747A78;
extern void cIDBase_trans(void *self);

extern char D_005CAE50[];           /* collision list */
extern char D_00429290[];           /* six unit vectors of the door box */

typedef struct { char b[0x60]; } cDoorBoxAxes;
typedef struct { cVec v[6]; } cDoorBoxVecs;



static __inline__ void door_vec(cVec *v, float x, float y, float z, float w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

/* Register the door's solid box with the collision list: the box centre
 * is the door size plus a margin, the half extents are half the width and
 * height, and the axes are copied from the shared table. */
__attribute__((section(".text.cOmDoor_setObjCollision")))
void cOmDoor_setObjCollision(cOmDoor *self) {
    cVec center;
    cVec half;
    cVec zero;
    float *mtx;
    cDoorBoxVecs ax;
    float sx = self->size[0];
    float sy = self->size[1];

    door_vec(&center, sx, sy, self->size[2], 1.0f);
    VU0_VADDX_XYZ_MEM(&center, 0, 0.1f);
    door_vec(&half, sx * -0.5f, sy * 0.5f, 0, 1.0f);
    door_vec(&zero, 0, 0, 0, 1.0f);
    *(cDoorBoxAxes *)&ax = *(cDoorBoxAxes *)D_00429290;
    mtx = self->base.mtx;
    self->collision = func_0012EAD8(D_005CAE50, self, mtx, &half, &zero,
                                    &center, &ax.v[0], &ax.v[1], &ax.v[2], &ax.v[3],
                                    &ax.v[4], &ax.v[5]);
}

/* Game-loop state 2 handler: clear the checkpoint, silence the effect bus, go to state 3. */





__attribute__((section(".text.GameLoop_stageClearToState3")))
void GameLoop_stageClearToState3(char *state) {
    cSaveManager_stageClear(D_003C264C);
    func_002CABE0(D_005FEE00);
    *state = 3;
}

/* cSceAtManager: drop the selected unit and its cursor while the lock bit is clear. */


#define SCEAT_LOCK_CURSOR  0x100000    /* D_00747A78 bit: cursor frozen */

/* The manager past the unit list head: the cursor state. */
typedef struct cSceAtManagerCursor {
    cSceAtManager mgr;                  /* 0x00 */
    int unk60;                          /* 0x60 */
    unsigned char hitKind;              /* 0x64 */
    char unk65[3];
    int posA;                           /* 0x68 */
    int posB;                           /* 0x6C */
    int posC;                           /* 0x70 */
} cSceAtManagerCursor;


extern void func_002C1618(cSceAtManagerCursor *self);

__attribute__((section(".text.cSceAtManager_clearCursor")))
void cSceAtManager_clearCursor(cSceAtManagerCursor *self) {
    if ((D_00747A78 & SCEAT_LOCK_CURSOR) == 0) {
        self->unk60 = 0;
        self->posA = 0;
        self->posB = 0;
        self->posC = 0;
        self->hitKind = 0;
        func_002C1618(self);
    }
}

/* Draw the object: its second display block comes first while mode is 2 or 3. */
typedef struct IdDrawObj {
    char unk00[0x5A];
    signed char mode;                   /* 0x5A */
    char unk5B[0x65];
    char sub[0x20];                     /* 0xC0 second cIDBase block */
} IdDrawObj;



__attribute__((section(".text.IdDrawObj_transDual")))
void IdDrawObj_transDual(IdDrawObj *self) {
    int mode = self->mode;
    if (mode >= 0) {
        if (mode >= 2) {
            if (mode < 4) {
                cIDBase_trans(self->sub);
            }
        }
    }
    cIDBase_trans(self);
}

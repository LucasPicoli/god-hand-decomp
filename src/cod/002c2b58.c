/* sn-2.95.3-136 */
#include "godhand/cSceAtManager.h"
#include "godhand/cArea.h"
#include "godhand/cIDManager.h"
#include "godhand/gameWork.h"
#include "godhand/cVec.h"
#include "godhand/vecInline.h"

/* One jump point of the room data's jump point table: where the jump lands
 * and its heading, the room it belongs to, and the spot its unit is placed. */
typedef struct cSceAtJumpPoint {
    short x;                            /* 0x00 landing point, cm */
    short y;                            /* 0x02 */
    short z;                            /* 0x04 */
    short heading;                      /* 0x06 degrees */
    short room;                         /* 0x08 */
    signed char idx;                    /* 0x0A */
    char unk0B;
    short unitX;                        /* 0x0C where the unit is placed, cm */
    short unitY;                        /* 0x0E */
    short unitZ;                        /* 0x10 */
    unsigned short unitHeading;         /* 0x12 degrees */
} cSceAtJumpPoint;                      /* 0x14 */

typedef struct cSceAtJumpPointTbl {
    unsigned int num;                   /* 0x00 */
    cSceAtJumpPoint ent[1];             /* 0x04 */
} cSceAtJumpPointTbl;

#define JUMP_CM_TO_M     0.01f
#define JUMP_DEG_TO_RAD  0.017453292f

/* Find the placed jump point unit whose area holds pos; give its landing
 * point (cm to m) and heading (degrees to radians) from the room's jump
 * point table. 0 if pos is in no such area or the table entry is missing
 * or belongs to another room; a unit whose entry is for another room ends
 * the search.
 * Takes -fmove-all-movables and the mtc1 hazard rule: without the flag the
 * loop keeps fewer invariants in saved registers. */
__attribute__((section(".text.cSceAtManager_findJumpPoint")))
int cSceAtManager_findJumpPoint(cSceAtManager *self, cVec *pos, cVec *point, float *heading)
{
    cVec at;
    cArea area;
    cSceAtUnit *u;

    u = cSceAtManager_getUnitList(self);
    while ((u = cSceAtManager_getNextUnit(self, u)) != 0) {
        cSceAtJumpPointTbl *tbl;
        cSceAtJumpPoint *e;

        if (u->type != SCEAT_UNIT_TYPE_MARK) {
            continue;
        }
        if (u->spawnOn != 1) {
            continue;
        }
        CVEC_COPY(at, pos);
        func_002C1D68(self, &area, u);
        if (cArea_HitCheck_1F83E8(&area, &at.x) != 1) {
            continue;
        }
        tbl = SearchData(D_007474A0.pack, D_0044C230, 0);
        if (tbl == 0) {
            return 0;
        }
        if (u->spawnIdx >= tbl->num) {
            return 0;
        }
        e = &tbl->ent[u->spawnIdx];
        if (e->room != D_007474A0.room) {
            break;
        }
        vec3_set(&point->x, (float)e->x * JUMP_CM_TO_M, (float)e->y * JUMP_CM_TO_M, (float)e->z * JUMP_CM_TO_M);
        *heading = (float)e->heading * JUMP_DEG_TO_RAD;
        return 1;
    }
    return 0;
}

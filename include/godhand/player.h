/* include/godhand/player.h - the player object, its restart point and the
 * functions the player code calls.
 *
 * The player is a pl00 (pl00.h), which derives from cGameObj (cGameObj.h);
 * its method table is cGameObjVt. Field names are ours; offsets are exact.
 */
#ifndef GODHAND_PLAYER_H
#define GODHAND_PLAYER_H

#include "godhand/cGameObj.h"
#include "godhand/pl00.h"
#include "godhand/cHeatSys.h"

/* The player's saved position, rotation and heat gauge (restart point). */
typedef struct PlayerSave {
    float pos[3];               /* 0x00 */
    float rot[3];               /* 0x0C */
    float heat;                 /* 0x18 */
    float heatMax;              /* 0x1C */
} PlayerSave;

extern PlayerSave D_00755880;
extern cHeatSys D_005CB000;     /* the player's heat gauge */

/* Whether the sub screen is up. Reads the player's base.mode and base.phase
 * (0x2F4, 0x2F5) as the sub screen's open and selection bytes, and unk15F4. */
extern int pl00_CkSubScreen(pl00 *pl);
extern int func_0012BAF0(pl00 *pl);

extern cGameObj *Getplayer(void);
extern cGameObj *CreateObj(int kind, int dataId);
extern void ReleaseObj(char *obj);
/* Start the thrown object obj for move type `type`, moving along speed. owner
 * is the thrower, kept at obj+0x62C. */
extern void cOmbe_SetSpeed(cGameObj *obj, cGameObj *owner, cVec *speed, int type);
extern void cHeatSys_UpdateHeatMax(cHeatSys *self, float max);
extern void cHeatSys_SetHeatGage(cHeatSys *self, float heat);

#endif

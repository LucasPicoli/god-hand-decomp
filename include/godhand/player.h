/* include/godhand/player.h - the player object, its restart point and the
 * method-table entries the player code calls.
 *
 * The views below sit on top of cGameObj (cGameObj.h) for words that
 * header leaves as padding. Field names are ours; offsets are exact.
 */
#ifndef GODHAND_PLAYER_H
#define GODHAND_PLAYER_H

#include "godhand/cGameObj.h"
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

/* The setPos/setRot pairs of the player's method table at 0x214. */
typedef struct cPlayerVt {
    char unk00[0x70];
    short setPosDelta;          /* 0x70 */
    short pad72;
    void (*setPos)(void *self, cVec *pos);  /* 0x74 */
    short setRotDelta;          /* 0x78 */
    short pad7A;
    void (*setRot)(void *self, cVec *rot);  /* 0x7C */
} cPlayerVt;

/* The init entry of a freshly created object's method table. */
typedef struct cObjInitVt {
    char unk00[0x40];
    short initDelta;            /* 0x40 */
    short pad42;
    void (*init)(void *self);   /* 0x44 */
} cObjInitVt;

/* The object at cGameObj + 0x68C. */
typedef struct cPlayerLink {
    char unk000[0x2F0];
    int flags;                  /* 0x2F0 bit 0: the player was moved */
} cPlayerLink;

/* cGameObj.unk000 holds a second position copy at 0x30. */
typedef struct cGameObjHead {
    char unk00[0x30];
    cVec pos;                   /* 0x30 */
} cGameObjHead;

/* Partial view of the player object: the sub screen fields. */
typedef struct PlSub {
    char pad000[0x2F4];
    unsigned char subOpen;      /* 0x2F4 */
    unsigned char subSel;       /* 0x2F5 */
    char pad2F6[0x15F4 - 0x2F6];
    int flags15F4;              /* 0x15F4 */
} PlSub;

extern int pl00_CkSubScreen(PlSub *pl);
extern int func_0012BAF0(PlSub *pl);

extern cGameObj *Getplayer(void);
extern cGameObj *CreateObj(int kind, int id);
extern void ReleaseObj(char *obj);
/* Start the thrown object obj for move type `type`, moving along speed. owner
 * is the thrower; it is not read. */
extern void cOmbe_SetSpeed(cGameObj *obj, cGameObj *owner, cVec *speed, int type);
extern void cHeatSys_UpdateHeatMax(cHeatSys *self, float max);
extern void cHeatSys_SetHeatGage(cHeatSys *self, float heat);

#endif

/* include/godhand/cDamageManage.h - cDamageManage, the pools of damage records.
 *
 * The manager holds every give record (an attack's damage) and every take
 * record (a target's hit volumes). The create calls hand out the first record
 * that is not live. When none is free they return the spare record after the
 * pools; its type is 0, so the setup on it does nothing.
 *
 * Method names are the game's own, from the script binding table in the
 * retail ELF's .data (CreateDamageGive__13cDamageManage8DMG_KINDP8cGameObj and
 * the others below).
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail.
 */
#ifndef GODHAND_CDAMAGEMANAGE_H
#define GODHAND_CDAMAGEMANAGE_H

#include "godhand/cDamageGive.h"
#include "godhand/cDamageUnit.h"

#define CDAMAGE_GIVE_MAX  160           /* cDamageManage.give */
#define CDAMAGE_TAKE_MAX  256           /* cDamageManage.take */

struct cGameObj;

typedef struct cDamageManage {
    cDamageGive give[CDAMAGE_GIVE_MAX]; /* 0x0000 */
    cDamageTake take[CDAMAGE_TAKE_MAX]; /* 0x3C00 */
    cDamageGive giveSpare;              /* 0xAC00 handed out when every give is live */
    cDamageTake takeSpare;              /* 0xAC60 handed out when every take is live */
    int hitStop;                        /* 0xACD0 frames of hit pause left */
    char unkACD4[0xC];
} cDamageManage;                        /* 0xACE0: the next symbol is D_0057F060 */

typedef char cDamageManage_size_check[(sizeof(cDamageManage) == 0xACE0) ? 1 : -1];

/* The damage manager. */
extern cDamageManage D_00574380;

/* A give record for owner, set up for kind
 * (CreateDamageGive__13cDamageManage8DMG_KINDP8cGameObj). */
cDamageGive *cDamageManage_CreateDamageGive(cDamageManage *self, int kind, struct cGameObj *owner);
/* The first give that is not live, or the spare. */
cDamageGive *func_001FE1E0(cDamageManage *self);
/* A take record for owner, set up for kind
 * (CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND). */
cDamageTake *cDamageManage_CreateDamageTake(cDamageManage *self, struct cGameObj *owner, int kind);
/* The first take that is not live, or the spare. */
cDamageTake *func_001FE310(cDamageManage *self);
/* InitEntryPool_1FE188 releases every give, InitNodePool_1FE2B8 every take;
 * InitPools_1FDFA8 runs both. */
void InitPools_1FDFA8(cDamageManage *self);
void InitEntryPool_1FE188(cDamageManage *self);
void InitNodePool_1FE2B8(cDamageManage *self);
/* Runs cDvd_releaseAll and func_001FCDB8 on give and returns 1; returns 0
 * when give is 0 (ReleaseDamageGive__13cDamageManageP11cDamageGive). */
int cDamageManage_ReleaseDamageGive(cDamageManage *self, cDamageGive *give);
/* The take side of cDamageManage_ReleaseDamageGive: cDvd_releaseAll and
 * ResetObjectFields_1FCDE8 on take, then 1; 0 when take is 0. */
int ClearAndResetFields_1FE278(cDamageManage *self, cDamageTake *take);
/* Starts a hit pause of frames frames. */
void StartHitStop_1FE348(cDamageManage *self, int frames);
/* Nonzero while a hit pause runs (CkHitStop__13cDamageManage). */
int cDamageManage_CkHitStop(cDamageManage *self);
/* The per-frame update: counts the hit pause down, or runs every live give
 * and take. */
void func_001FDFD8(cDamageManage *self);

#endif

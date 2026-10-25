/* include/godhand/espSpawn.h - the effect spawn request table (0x3066D0).
 *
 * SetEffect fills a request and func_003066D0 walks the table of spawn
 * records, 0x2F0 bytes each, for the ones that match the caller. For each
 * match it takes an emitter from the pool (func_00300458), lets
 * func_00303A30 set it up and runs the emitter's start method. A failed
 * setup returns the emitter to the pool and ends the walk with 0.
 *
 * Field names are ours, from the one function that walks the table.
 */
#ifndef GODHAND_ESPSPAWN_H
#define GODHAND_ESPSPAWN_H

#include "godhand/cModel.h"           /* cVtEnt */

#define ESP_SPAWN_STRIDE      0x2F0
#define ESP_SPAWN_NO_OWNER    -1      /* lock: no owner needed */
#define ESP_SPAWN_LOCK_OWNER  -4      /* lock: the owner must be gone */
#define ESP_OWNER_HAS_ID      0x8     /* espOwner.flags: slot carries a packed event id */

/* A spawn record. */
typedef struct espSpawn {
    char unk000[0xBE];
    signed char lock;                   /* 0x0BE */
    char unk0BF[0x128 - 0xBF];
    unsigned char kind;                 /* 0x128 emitter kind to pull from the pool */
    char unk129[0x136 - 0x129];
    unsigned char group;                /* 0x136 matches espOwner.group */
    char unk137[0x2A0 - 0x137];
    unsigned int eventId;               /* 0x2A0 packed id of the event object */
    char unk2A4[ESP_SPAWN_STRIDE - 0x2A4];
} espSpawn;
typedef char espSpawn_size_check[sizeof(espSpawn) == ESP_SPAWN_STRIDE ? 1 : -1];

/* The object that asked for the effect. */
typedef struct espOwner {
    char unk00[0x48];
    unsigned int flags;                 /* 0x48 */
    char unk4C[0x74 - 0x4C];
    unsigned char group;                /* 0x74 */
} espOwner;

/* A pooled emitter as func_003066D0 sees it: only the start method. */
typedef struct espSpawnVt {
    char unk00[0x18];
    short startDelta;                   /* 0x18 */
    short pad1A;
    int (*start)(void *self);           /* 0x1C */
} espSpawnVt;
typedef struct espPooled {
    char unk00[0xF0];
    espSpawnVt *vt;                     /* 0xF0 */
} espPooled;

#endif

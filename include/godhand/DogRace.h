/* include/godhand/DogRace.h - the dog-race casino game.
 *
 * DogRace runs five racing dogs. Each dog is a 0x40-byte DogRaceDog that
 * holds the spawned object, its stat record (copied from a table row) and
 * the rolled race values. The scene state machine and its UI sit behind
 * the dogs: a cIDWork at 0x210 and two sub-objects after it.
 *
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. Fields nobody has named stay as unkNN padding.
 */
#ifndef GODHAND_DOGRACE_H
#define GODHAND_DOGRACE_H

#define DOGRACE_DOG_NUM     5
#define DOGRACE_ODDS_BASE   0x3E8   /* payout base, 0x7D0 after the game was cleared */
#define DOGRACE_ODDS_CLEAR  0x7D0

/* A dog's stat record, one row of the 0x24-byte table entry it spawns from. */
typedef struct DogRaceStats {
    int unk00;
    int grade;                  /* 0x04 below 16 it can be bumped to 30 */
    float speed;                /* 0x08 scaled by speedRate at spawn */
    float stamina;              /* 0x0C */
    float luck;                 /* 0x10 scaled by speedRate at spawn */
    float unk14;                /* 0x14 may be rolled again at spawn */
    unsigned int burstChance;   /* 0x18 percent */
    float rateMin;              /* 0x1C bounds of the speed roll */
    float rateMax;              /* 0x20 */
} DogRaceStats;                 /* 0x24 */

typedef struct DogRaceDog {
    void *obj;                  /* 0x00 spawned object, 0 if the spawn failed */
    unsigned char no;           /* 0x04 index of the dog */
    char pad05[3];
    DogRaceStats stats;         /* 0x08 */
    int raceTime;               /* 0x2C rolled finish value */
    int unk30;
    int unk34;
    int power;                  /* 0x38 sort key, strongest first */
    float speedRate;            /* 0x3C */
} DogRaceDog;                   /* 0x40 */

typedef struct DogRace {
    char unk00[4];
    int unk04;                  /* 0x004 */
    int unk08;                  /* 0x008 */
    int unk0C;                  /* 0x00C */
    char unk10[0x44];
    int unk54;                  /* 0x054 */
    char unk58[4];
    DogRaceDog dog[DOGRACE_DOG_NUM];    /* 0x05C */
    int rank[DOGRACE_DOG_NUM];  /* 0x19C */
    char unk1B0[4];
    int unk1B4;                 /* 0x1B4 */
    int unk1B8;                 /* 0x1B8 */
    int odds;                   /* 0x1BC */
    char unk1C0[4];
    int scroll[15];             /* 0x1C4 scroll layer ids, set by DogRace_Initialize */
    char unk200[0x10];
    char idWork[0x1630];        /* 0x210 cIDWork */
    char ui1[0x350];            /* 0x1840 */
    char ui2[0xE7C];            /* 0x1B90 */
    int fileData;               /* 0x2A0C loaded data file */
} DogRace;

#endif

/* include/godhand/cCoreSave.h - the persistent player record.
 *
 * cCoreSave is the game's save-data class. It holds one pointer, to a
 * 0x14A0-byte record that cCoreSave_systemInit clears at boot (the record
 * sits at D_005686D0, the object right after it at D_00569B70). Every
 * method starts with the same guard: do nothing if the record is missing.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CCORESAVE_H
#define GODHAND_CCORESAVE_H

#define CORESAVE_GOLD_MAX      999999
#define CORESAVE_KEY_MAX       9       /* key cards, keys, casino tickets */
#define CORESAVE_CLEAR_MAX     99
#define CORESAVE_LEVEL_NUM     5       /* game levels 1..5 */
#define CORESAVE_ADD_GOLD_LOG  16
#define CORESAVE_GOD_ITEM_NUM  6
#define CORESAVE_SKILL_NUM     0x72    /* valid ids; the array holds 0x80 */
#define CORESAVE_COMBO_SETS    6
#define CORESAVE_COMBO_LEN     6
#define CORESAVE_GOD_REEL_NUM  0x1F    /* valid bits of godReel */
#define CORESAVE_ITEM_NUM      0x80    /* remembered pickups */

/* Play time is counted in frames at 30 fps. */
#define CORESAVE_TICKS_PER_SEC   30
#define CORESAVE_TICKS_PER_MIN   (60 * CORESAVE_TICKS_PER_SEC)
#define CORESAVE_TICKS_PER_HOUR  (60 * CORESAVE_TICKS_PER_MIN)

typedef struct cCoreSaveCombo {
    int id[CORESAVE_COMBO_LEN];         /* 0x00 */
    char lv[CORESAVE_COMBO_LEN];        /* 0x18 */
    char pad1E[2];
    int max;                            /* 0x20 used length of id[] */
} cCoreSaveCombo;                       /* 0x24 */

/* Where the player resumes: stored as shorts and floats, copied to a
 * stack record for SetField_1C_2009B0. */
typedef struct cCoreSaveSpawn {
    unsigned char kind;                 /* 0x00 */
    unsigned char sub;                  /* 0x01 */
    unsigned short angle;               /* 0x02 */
    float pos[4];                       /* 0x04 */
    int param;                          /* 0x14 */
} cCoreSaveSpawn;                       /* 0x18 */

/* The same point as the spawn setup takes it: a different field order. */
typedef struct cCoreSaveSpawnArg {
    float pos[4];                       /* 0x00 */
    unsigned short angle;               /* 0x10 */
    unsigned char kind;                 /* 0x12 */
    unsigned char sub;                  /* 0x13 */
    int param;                          /* 0x14 */
} cCoreSaveSpawnArg;                    /* 0x18 */

/* One dropped object remembered for the stage it fell in. A slot is free
 * when stage is 0xFFFF; serial counts up from itemNum. */
typedef struct cCoreSaveItem {
    unsigned short stage;               /* 0x00 */
    unsigned short kind;                /* 0x02 object type */
    unsigned char flag;                 /* 0x04 */
    signed char yaw;                    /* 0x05 half degrees */
    unsigned short serial;              /* 0x06 */
    short pos[3];                       /* 0x08 tenths of a unit */
    unsigned short extra;               /* 0x0E */
} cCoreSaveItem;                        /* 0x10 */

typedef struct cCoreSaveData {
    int worldTime;                      /* 0x000 */
    int worldTimeB;                     /* 0x004 */
    unsigned int counter08;             /* 0x008 capped at 999 */
    unsigned short saveStageA;          /* 0x00C */
    unsigned short saveStageB;          /* 0x00E */
    unsigned short clearNum;            /* 0x010 times the game was cleared */
    unsigned short continueNum;         /* 0x012 this stage */
    unsigned int flags;                 /* 0x014 */
    char unk18[4];
    short levelPoint;                   /* 0x01C drives the game level */
    char levelDownGrace;                /* 0x01E level drops absorbed */
    char difficulty;                    /* 0x01F 0..2 */
    int gold;                           /* 0x020 */
    int addGoldNum;                     /* 0x024 entries in addGold[] */
    int addGold[CORESAVE_ADD_GOLD_LOG]; /* 0x028 recent gold pickups */
    int keyCardNum;                     /* 0x068 */
    int keyNum;                         /* 0x06C */
    int upgradeLv[4];                   /* 0x070 (index 4 reads vitalMax) */
    int vitalMax;                       /* 0x080 */
    int vital;                          /* 0x084 */
    unsigned short counter88;           /* 0x088 set only below 1000 */
    unsigned char stat8A;               /* 0x08A clamped to 1..6 */
    char unk8B;
    short killEmNum[CORESAVE_LEVEL_NUM];      /* 0x08C this stage, per level */
    unsigned short killNpcNum;          /* 0x096 this stage */
    unsigned char reelSlot[10];         /* 0x098 god reel per slot, 0x1F = empty */
    char unkA2[2];
    unsigned int clearStageMask;        /* 0x0A4 bit n = stage n cleared */
    unsigned char godItem[CORESAVE_GOD_ITEM_NUM]; /* 0x0A8 */
    unsigned char costumeNo;            /* 0x0AE */
    unsigned char prevCostumeNo;        /* 0x0AF */
    char skill[0x80];                   /* 0x0B0 -1 = not owned */
    unsigned int godReel;               /* 0x130 bit n = god reel n unlocked */
    unsigned char stock[0x20];          /* 0x134 counts, capped at 0xFF */
    unsigned char state154;             /* 0x154 clamped to 0..0xD */
    unsigned char state155;             /* 0x155 clamped to 0..5 */
    unsigned char reelItemNum;          /* 0x156 usable godItem[] slots */
    unsigned char paper;                /* 0x157 */
    cCoreSaveSpawn spawn;               /* 0x158 last respawn point */
    int worldToggle;                    /* 0x170 */
    int worldActive;                    /* 0x174 */
    int savedToggle;                    /* 0x178 */
    int unk17C;
    char unk180[0x30];                  /* 0x180 cleared by gameInit */
    cCoreSaveCombo combo[CORESAVE_COMBO_SETS]; /* 0x1B0 */
    unsigned short itemNum;             /* 0x288 */
    cCoreSaveItem item[CORESAVE_ITEM_NUM]; /* 0x28A */
    char unkA8A[0x106];
    unsigned int eventFlags;            /* 0xB90 one bit per event */
    int casinoTicketNum;                /* 0xB94 */
    unsigned int fightingRingClear[4];  /* 0xB98 one bit per ring event */
    int bonus;                          /* 0xBA8 */
    short allKillEmNum[CORESAVE_LEVEL_NUM];   /* 0xBAC whole game */
    unsigned short allKillNpcNum;       /* 0xBB6 whole game */
    unsigned short allContinueNum;      /* 0xBB8 whole game */
    unsigned short stateBits;           /* 0xBBA bit 0 = flag */
    unsigned int allStageTime;          /* 0xBBC ticks, whole game */
    int oliviaCostumeNo;                /* 0xBC0 */
    char unkBC4[0x8DC];
} cCoreSaveData;                        /* 0x14A0 */

/* Fails to compile if the layout drifts from the 0x14A0 bytes retail clears. */
typedef char cCoreSaveData_size_check[sizeof(cCoreSaveData) == 0x14A0 ? 1 : -1];

/* Byte offset of a record field, for the few bodies that must form the
 * address by hand to match retail. */
#define CORESAVE_OFFSET(field) ((unsigned int)&((cCoreSaveData *)0)->field)

typedef struct cCoreSave {
    cCoreSaveData *data;
} cCoreSave;

#endif /* GODHAND_CCORESAVE_H */

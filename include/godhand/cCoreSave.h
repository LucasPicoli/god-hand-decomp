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

typedef struct cCoreSaveData {
    char unk00[0x10];
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
    char unk70[0x10];
    int vitalMax;                       /* 0x080 */
    int vital;                          /* 0x084 */
    char unk88[4];
    short killEmNum[CORESAVE_LEVEL_NUM];      /* 0x08C this stage, per level */
    unsigned short killNpcNum;          /* 0x096 this stage */
    char unk98[0xC];
    unsigned int clearStageMask;        /* 0x0A4 bit n = stage n cleared */
    unsigned char godItem[CORESAVE_GOD_ITEM_NUM]; /* 0x0A8 */
    unsigned char costumeNo;            /* 0x0AE */
    unsigned char prevCostumeNo;        /* 0x0AF */
    char skill[0x80];                   /* 0x0B0 -1 = not owned */
    unsigned int godReel;               /* 0x130 bit n = god reel n unlocked */
    char unk134[0x22];
    unsigned char reelItemNum;          /* 0x156 usable godItem[] slots */
    unsigned char paper;                /* 0x157 */
    char unk158[0x58];
    cCoreSaveCombo combo[CORESAVE_COMBO_SETS]; /* 0x1B0 */
    char unk288[0x90C];
    int casinoTicketNum;                /* 0xB94 */
    unsigned int fightingRingClear[4];  /* 0xB98 one bit per ring event */
    char unkBA8[4];
    short allKillEmNum[CORESAVE_LEVEL_NUM];   /* 0xBAC whole game */
    unsigned short allKillNpcNum;       /* 0xBB6 whole game */
    unsigned short allContinueNum;      /* 0xBB8 whole game */
    char unkBBA[2];
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

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
    char unkA8A[0x102];
    unsigned int unkB8C;                /* 0xB8C bit 0 set by the new-game reset */
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


/* The game's one save record object. */
extern cCoreSave D_00569B70;

/* Methods, in name order. The types are those of the matched definitions. */
void cCoreSave_addAllStageTime(cCoreSave *self, int ticks);
void cCoreSave_addCasinoTicket(cCoreSave *self, int num);
void cCoreSave_addContinueNum(cCoreSave *self);
void cCoreSave_addCounter08(cCoreSave *self);
void cCoreSave_addGameLevelPoint(cCoreSave *self, int point);
int cCoreSave_addGodItem(cCoreSave *self, unsigned char item);
void cCoreSave_addGold(cCoreSave *self, int amount, int clearLog);
void cCoreSave_addKeyCardNum(cCoreSave *self, int n);
void cCoreSave_addKeyNum(cCoreSave *self, int n);
void cCoreSave_addKillEmNum(cCoreSave *self);
void cCoreSave_addKillNpcNum(cCoreSave *self);
void cCoreSave_addReelItemNum(cCoreSave *self, unsigned char n);
void cCoreSave_addStat8A(cCoreSave *self, int n);
void cCoreSave_addState154(cCoreSave *self, unsigned char n);
void cCoreSave_addState155(cCoreSave *self, unsigned char n);
int cCoreSave_addStock(cCoreSave *self, int i, int d);
void cCoreSave_addUpgradeLv(cCoreSave *self, unsigned int kind, int n);
int cCoreSave_ckClearStage(cCoreSave *self, unsigned int no);
int cCoreSave_ckEventFlag(cCoreSave *self, int no);
int cCoreSave_ckGodReel(cCoreSave *self, int no);
int cCoreSave_ckPaper(cCoreSave *self);
int cCoreSave_ckReelSlot(cCoreSave *self, unsigned int no);
void cCoreSave_clearAllContinueNum(cCoreSave *self);
void cCoreSave_clearAllKillEmNum(cCoreSave *self);
void cCoreSave_clearAllKillNpcNum(cCoreSave *self);
void cCoreSave_clearAllStageTime(cCoreSave *self);
void cCoreSave_clearBlock180(cCoreSave *self);
void cCoreSave_clearClearStage(cCoreSave *self);
void cCoreSave_clearEventFlags(cCoreSave *self);
void cCoreSave_clearFightingRing(cCoreSave *self);
void cCoreSave_clearGodItem(cCoreSave *self);
void cCoreSave_clearKillEmNum(cCoreSave *self);
void cCoreSave_clearKillNpcNum(cCoreSave *self);
void cCoreSave_clearPaper(cCoreSave *self);
void cCoreSave_clearStateBit0(cCoreSave *self);
void cCoreSave_dropLevelPoint(cCoreSave *self);
int cCoreSave_findFreeReelSlot(cCoreSave *self);
int cCoreSave_findNextStage(cCoreSave *self);
void cCoreSave_freeItem(cCoreSave *self, unsigned short id);
void cCoreSave_gameInit(cCoreSave *self);
void cCoreSave_GameLevelUp(cCoreSave *self);
int cCoreSave_getAddGold(cCoreSave *self, int i);
int cCoreSave_getAddGoldNum(cCoreSave *self);
unsigned short cCoreSave_getAllContinueNum(cCoreSave *self);
int cCoreSave_getAllKillEmNum(cCoreSave *self, int level);
unsigned short cCoreSave_getAllKillNpcNum(cCoreSave *self);
void cCoreSave_getAllStageTime(cCoreSave *self, int *hour, int *min, int *sec);
int cCoreSave_getBlock180(cCoreSave *self);
int cCoreSave_getBonus(cCoreSave *self);
int cCoreSave_getCasinoTicketNum(cCoreSave *self);
int cCoreSave_getClearNum(cCoreSave *self);
int cCoreSave_getCombo(cCoreSave *self, unsigned int set, unsigned int slot);
int cCoreSave_getComboLv(cCoreSave *self, unsigned int set, unsigned int slot);
int cCoreSave_getComboMax(cCoreSave *self, unsigned int set);
unsigned short cCoreSave_getContinueNum(cCoreSave *self);
unsigned char cCoreSave_getCostumeNo(cCoreSave *self);
int cCoreSave_getGameDifficulty(cCoreSave *self);
int cCoreSave_getGameLevel(cCoreSave *self);
unsigned char cCoreSave_getGodItem0(cCoreSave *self);
unsigned int cCoreSave_getGodItemNum(cCoreSave *self);
int cCoreSave_getGold(cCoreSave *self);
int cCoreSave_getKeyCardNum(cCoreSave *self);
int cCoreSave_getKeyNum(cCoreSave *self);
short cCoreSave_getKillEmNum(cCoreSave *self, int level);
short cCoreSave_getKillNpcNum(cCoreSave *self);
short cCoreSave_getLevelPoint(cCoreSave *self);
float cCoreSave_getLevelProgress(cCoreSave *self);
unsigned char cCoreSave_getPrevCostumeNo(cCoreSave *self);
int cCoreSave_getReelItem(cCoreSave *self);
int cCoreSave_getReelSlot(cCoreSave *self, int slot);
int cCoreSave_getSkill(cCoreSave *self, int id);
unsigned char cCoreSave_getStat8A(cCoreSave *self);
int cCoreSave_getState154(cCoreSave *self);
int cCoreSave_getState155(cCoreSave *self);
int cCoreSave_getStateBit0(cCoreSave *self);
unsigned char cCoreSave_getStock(cCoreSave *self, int i);
int cCoreSave_getVital(cCoreSave *self);
int cCoreSave_getVitalMax(cCoreSave *self);
void cCoreSave_initAddGold(cCoreSave *self);
void cCoreSave_initCombos(cCoreSave *self);
void cCoreSave_initContinueNum(cCoreSave *self);
void cCoreSave_initEasyStart(cCoreSave *self);
void cCoreSave_initItem(cCoreSave *self);
void cCoreSave_initReelSlots(cCoreSave *self);
int cCoreSave_isGoldFull(cCoreSave *self);
void cCoreSave_loadGlobalToggle(cCoreSave *self);
void cCoreSave_loadSpawn(cCoreSave *self);
void cCoreSave_loadWorldActive(cCoreSave *self);
void cCoreSave_loadWorldToggle(cCoreSave *self);
void cCoreSave_resetCostumeNo(cCoreSave *self, unsigned char no);
void cCoreSave_saveGlobalToggle(cCoreSave *self);
void cCoreSave_saveSpawn(cCoreSave *self);
void cCoreSave_saveStageIds(cCoreSave *self);
void cCoreSave_saveWorldActive(cCoreSave *self);
void cCoreSave_saveWorldTime(cCoreSave *self);
void cCoreSave_saveWorldToggle(cCoreSave *self);
void cCoreSave_setBonus(cCoreSave *self, int v);
void cCoreSave_setCasinoTicketNum(cCoreSave *self, int num);
void cCoreSave_setClearNum(cCoreSave *self, unsigned short num);
void cCoreSave_setClearStage(cCoreSave *self, unsigned short stage);
void cCoreSave_setCombo(cCoreSave *self, unsigned int set, unsigned int slot, int id, int lv);
void cCoreSave_setComboMax(cCoreSave *self, unsigned int set, int max);
void cCoreSave_setContinueNum(cCoreSave *self, unsigned short n);
void cCoreSave_setCostumeNo(cCoreSave *self, unsigned int no);
void cCoreSave_setCounter88(cCoreSave *self, short v);
void cCoreSave_setEventFlag(cCoreSave *self, int no);
void cCoreSave_SetFightingRingClearFlag(cCoreSave *self, unsigned int bit, int set);
void cCoreSave_setGameDifficulty(cCoreSave *self, int difficulty);
void cCoreSave_setGameLevel(cCoreSave *self, int level);
void cCoreSave_setGameLevel1_1F9AD0(cCoreSave *self);
void cCoreSave_setGameLevel5_1F9AF0(cCoreSave *self);
void cCoreSave_setGodReel(cCoreSave *self, int no);
void cCoreSave_setGold(cCoreSave *self, int gold);
void cCoreSave_setKeyCardNum(cCoreSave *self, int num);
void cCoreSave_setKeyNum(cCoreSave *self, int num);
void cCoreSave_setLevelPoint(cCoreSave *self, short points);
void cCoreSave_SetOliviaCostumeNo(cCoreSave *self, int no);
void cCoreSave_setPaper(cCoreSave *self);
void cCoreSave_setReelItemNum(cCoreSave *self, unsigned char n);
void cCoreSave_setReelSlot(cCoreSave *self, unsigned char slot, unsigned int no);
void cCoreSave_setSkill(cCoreSave *self, int id, int lv);
void cCoreSave_setStat8A(cCoreSave *self, unsigned char v);
void cCoreSave_setState154(cCoreSave *self, unsigned char v);
void cCoreSave_setState155(cCoreSave *self, unsigned char v);
void cCoreSave_setStateBit0(cCoreSave *self);
void cCoreSave_setUpgradeLv(cCoreSave *self, unsigned int kind, int lv);
void cCoreSave_setVital(cCoreSave *self, int vital);
void cCoreSave_shiftGodItem(cCoreSave *self);
void cCoreSave_snapshot(cCoreSave *self, int full);
void cCoreSave_stageInit(cCoreSave *self);
void cCoreSave_subGold(cCoreSave *self, int amount);
void cCoreSave_systemInit(cCoreSave *self);
void cCoreSave_updateVitalMax(cCoreSave *self);

/* Not yet named: 1 when fightingRingClear has the given bit set. */
int func_001FC4D0(cCoreSave *self, unsigned int bit);

#endif /* GODHAND_CCORESAVE_H */

/* include/godhand/cSaveLoad.h - cSaveLoad, the save/load request record.
 *
 * A cSaveLoad is a 4-byte request: mode picks what the memory card handler
 * does next. openSave and openLoad share one shape: check the card is free
 * (func_002BF700), reset it (func_002BF170), raise the 0x40000000 bit in the
 * global flag word, then write the request bytes.
 * cSaveLoadGlobals is the game state block at D_00747A2C that both methods
 * test. Offsets are exact; unknown spans stay unkNNN.
 */
#ifndef GODHAND_CSAVELOAD_H
#define GODHAND_CSAVELOAD_H

#define SAVELOAD_MODE_LOAD   2
#define SAVELOAD_MODE_SAVE   3
#define SAVELOAD_FLAG_BUSY   0x40000000   /* a card operation is open */
#define SAVELOAD_FLAG_LOCK   0x800        /* in flags: card access locked */

typedef struct cSaveLoad {
    unsigned char mode;         /* 0x00 SAVELOAD_MODE_* */
    unsigned char phase;        /* 0x01 */
    unsigned char arg2;         /* 0x02 */
    unsigned char arg3;         /* 0x03 */
} cSaveLoad;

typedef struct cSaveLoadGlobals {
    char unk00[8];
    unsigned int flags;         /* 0x08 */
    int stage;                  /* 0x0C negative while no stage is loaded */
    char unk10[0x4C];
    unsigned int stateFlags;    /* 0x5C holds SAVELOAD_FLAG_BUSY */
} cSaveLoadGlobals;

/* The last two words of the block, which retail also reaches as its own
 * symbol D_00747A84 (= D_00747A2C + 0x58). */
typedef struct cSaveLoadTail {
    int unk58;
    unsigned int stateFlags;    /* 0x5C of the block */
} cSaveLoadTail;

#endif

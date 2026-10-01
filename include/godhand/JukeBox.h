/* include/godhand/JukeBox.h - the casino jukebox screen.
 *
 * JukeBox owns one cIDBase at 0x30 (the on-screen ID object, 0x50 bytes) and
 * the loaded data file whose handle sits at 0x80. JukeBox_Execute runs the
 * whole screen from one call; func_001F5A98 loads and sets it up, func_001F5C48
 * tears it down.
 *
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. Fields nobody has named stay as unkNN.
 */
#ifndef GODHAND_JUKEBOX_H
#define GODHAND_JUKEBOX_H

#define JUKEBOX_ID_NO       0x1E    /* ID data slot of the jukebox screen */
#define JUKEBOX_ID_OFFSET   0x30
#define JUKEBOX_BGM_NONE    (-2)

typedef struct JukeBoxObj {
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char done;         /* 0x04 set when the player leaves */
    unsigned char unk05;
    char pad06[2];
    int unk08;                  /* 0x08 starts at 10 */
    int unk0C;                  /* 0x0C starts at 1 */
    int unk10;                  /* 0x10 mirrors a bit of the save flags */
    int unk14;                  /* 0x14 mirrors D_00747A24 bit 26 */
    int unk18;                  /* 0x18 mirrors D_00747A24 bit 25 */
    int unk1C;                  /* 0x1C mirrors D_00747A24 bit 24 */
    int unk20;                  /* 0x20 */
    int bgmEvent;               /* 0x24 id of the running BGM event */
    char unk28[8];
    char idBase[0x50];          /* 0x30 cIDBase */
    int dataFile;               /* 0x80 loaded file, 0 if none */
} JukeBoxObj;

#endif

/* include/godhand/JukeBox.h - the casino jukebox screen.
 *
 * JukeBox owns one cIDBase at 0x30 (the on-screen ID object: a cIDBaseObj and
 * 8 bytes up to 0x78) and the loaded data file whose handle sits at 0x80. JukeBox_Execute runs the
 * whole screen from one call; func_001F5A98 loads and sets it up, JukeBox_Release
 * tears it down.
 *
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. Fields nobody has named stay as unkNN.
 */
#ifndef GODHAND_JUKEBOX_H
#define GODHAND_JUKEBOX_H

#include "godhand/cIDBase.h"

#define JUKEBOX_ID_NO       0x1E    /* ID data slot of the jukebox screen */
#define JUKEBOX_ID_OFFSET   0x30
#define JUKEBOX_BGM_NONE    (-2)

typedef struct JukeBoxObj {
    unsigned char type;         /* 0x00 index into the hook table D_003BF0E0 */
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
    cIDBaseObj idBase;          /* 0x30 */
    char unk78[8];
    int dataFile;               /* 0x80 loaded file, 0 if none */
} JukeBoxObj;

/* One frame: run the step hook for `type`, then move and draw the ID object. */
void Entry_runHookAndDraw(JukeBoxObj *self);

#endif

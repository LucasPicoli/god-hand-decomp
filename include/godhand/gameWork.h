/* include/godhand/gameWork.h - the game work block at D_007474A0 and the
 * render packet chain built from it.
 *
 * Most older TUs still see D_007474A0 as a plain char array; this typed view
 * is for code that names its fields. Field names are ours; offsets are exact.
 */
#ifndef GODHAND_GAMEWORK_H
#define GODHAND_GAMEWORK_H

#define GAMEWORK_PLAYER_READY   0x00010000  /* flags: the player object exists */
#define GAMEWORK_SKIP_PKT_1_3   0x02000000  /* flags: packets 1-3 left out of the chain */
#define GAMEWORK_IN_INTERRUPT   0x20000000  /* flags: flush with iFlushCache */
#define GAMEWORK_ROOM_NOPLAYER  0x20        /* room: the boot room, no player object */

/* Header of the effect data file the room loads; the offsets are from the header. */
typedef struct EffDataHdr {
    char unk00[4];
    int block1;                 /* 0x04 offset of the first system block */
    int block2;                 /* 0x08 offset of the second system block */
    char unk0C[8];
    int unk14;                  /* 0x14 offset of the first effect table */
    char unk18[4];
    int unk1C;                  /* 0x1C offset of the second effect table */
} EffDataHdr;

/* Room and pad fields use the names main gives them in cDoor.h and cE3.h. */
typedef struct GameWork {
    char pad000[0x1A0];
    long trg;                   /* 0x1A0 pad trigger bits */
    long unk1A8;                /* 0x1A8 */
    long rep;                   /* 0x1B0 pad repeat bits */
    char pad1B8[0x210 - 0x1B8];
    int frame;                  /* 0x210 bit 0 picks the packet buffer */
    char pad214[0x550 - 0x214];
    EffDataHdr *effData;        /* 0x550 effect data file */
    void *sysData;              /* 0x554 system data file */
    void *langData;             /* 0x558 language data file */
    char pad55C[0x564 - 0x55C];
    int padPort;                /* 0x564 controller port the vibration goes to */
    char pad568;
    unsigned char unk569;       /* 0x569 */
    char pad56A[2];
    int language;               /* 0x56C */
    char pad570[0x574 - 0x570];
    float timeScale;            /* 0x574 speed multiplier, 1.0 at boot */
    int mode;                   /* 0x578 1 = PAL */
    int unk57C;                 /* 0x57C */
    int unk580;                 /* 0x580 */
    int flags;                  /* 0x584 GAMEWORK_* */
    char pad588[0x594 - 0x588];
    int debugFlags;             /* 0x594 */
    int flags598;               /* 0x598 */
    int flags59C;               /* 0x59C */
    char pad5A0[0x5AC - 0x5A0];
    void *pack;                 /* 0x5AC room data pack */
    unsigned short room;        /* 0x5B0 current room id */
    char pad5B2[0x5B4 - 0x5B2];
    unsigned short nextRoom;    /* 0x5B4 room the next jump goes to (cCoreSave saveStageA) */
    unsigned short unk5B6;      /* 0x5B6 (cCoreSave saveStageB) */
    char pad5B8[0x5C0 - 0x5B8];
    float startPos[3];          /* 0x5C0 player start point */
    char pad5CC[4];
    float startAngle;           /* 0x5D0 */
    char pad5D4[0x5E4 - 0x5D4];
    int flags5E4;               /* 0x5E4 */
    char pad5E8[0x5F4 - 0x5E8];
    void *playerObj;            /* 0x5F4 */
    char pad5F8[0x600 - 0x5F8];
    unsigned char pairNum;      /* 0x600 entries used in D_007558A8 */
    char pad601[0x620 - 0x601];
} GameWork;                     /* 0x620 */

extern GameWork D_007474A0;

/* The block from GameWork 0x58C on, which code also reaches as its own symbol D_00747A2C.
 * cSaveLoad.h (cSaveLoadGlobals) and cE3.h (cE3Sys) describe parts of the same block. */
typedef struct GameSys {
    int unk00;                  /* 0x00 bit 3 skips hit checks; bit 0x08000000 stops pad vibration */
    char unk04[4];
    unsigned int flags;         /* 0x08 */
    int stage;                  /* 0x0C negative while no stage is loaded */
    char unk10[0x25 - 0x10];
    unsigned char unk25;        /* 0x25 */
    char unk26[0x4C - 0x26];
    unsigned int unk4C;         /* 0x4C bit 0x04000000 pauses pad vibration */
} GameSys;

extern GameSys D_00747A2C;
extern int D_00747A24;          /* D_007474A0.flags under its own symbol */

/* One 0x80-byte DMA packet; the chain has 11, each double-buffered. */
typedef struct DmaPkt {
    char data[0x80];
} DmaPkt;

typedef struct DmaPktSet {
    DmaPkt pkt[11][2];
} DmaPktSet;

typedef struct cTaskWorkRef {
    int unk0;
    struct cTaskWork *task;     /* 0x4 */
} cTaskWorkRef;

extern cTaskWorkRef D_00752C00;

extern void func_0014FE78(char *pkt);
extern void SetPackedFields10And18_14FF60(int pkt, int *next);
extern int func_003950F8(int mode, int timeout);   /* GS path sync */
extern void FlushCache(int op);
extern void iFlushCache(int op);
extern void cTaskWork_sleep(struct cTaskWork *task, int frames);

#endif

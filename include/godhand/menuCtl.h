/* include/godhand/menuCtl.h - menu list control and file-select menus (sn code at 0x37FD28..0x385xxx).
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_MENUCTL_H
#define GODHAND_MENUCTL_H

#define MENUPAD_DPAD     0xF0       /* press: any d-pad direction */
#define MENUPAD_NEXT     0x80       /* press: next page */
#define MENUPAD_CANCEL   0x40       /* press */
#define MENUPAD_DECIDE   0x20       /* press */
#define MENUPAD_PREV     0x10       /* press: previous page */
#define MENUPAD_TRG_UP   0x1000     /* trg: cursor up */
#define MENUPAD_TRG_DOWN 0x4000     /* trg: cursor down */

typedef struct MenuPad {
    char unk00[0x2C];
    int hold;                   /* 0x2C held buttons */
    char unk30[4];
    int press;                  /* 0x34 buttons pressed this frame, MENUPAD_* */
    unsigned int trg;           /* 0x38 */
} MenuPad;

typedef struct MenuInfo {
    int f00;                    /* 0x00 */
    int f04;                    /* 0x04 */
    int f08;                    /* 0x08 */
    int f0C;                    /* 0x0C */
    int time;                   /* 0x10 play time, written by func_0032A160 */
    int unk14;                  /* 0x14 */
    float unk18;                /* 0x18 */
    int unk1C;                  /* 0x1C */
    int unk20;                  /* 0x20 */
    int unk24;                  /* 0x24 */
    int unk28;                  /* 0x28 */
    int unk2C;                  /* 0x2C */
    int handle;                 /* 0x30 */
} MenuInfo;

/* A sound slot of a menu page: the stream it plays and its state. */
typedef struct MenuSlot {
    unsigned char kind;         /* 0x00 */
    unsigned char result;       /* 0x01 a prompt is up; any d-pad key clears it */
    char unk02[2];
    short unk04;                /* 0x04 */
    short unk06;                /* 0x06 */
    short unk08;                /* 0x08 */
    short unk0A;                /* 0x0A */
    int status;                 /* 0x0C the stream's state, -1 without a stream */
    MenuInfo info;              /* 0x10 */
    char unk44[4];
} MenuSlot;                     /* 0x48 */

/* The data page of a menu. */
typedef struct MenuPage {
    unsigned char unk00;
    unsigned char result;       /* 0x01 a prompt is up; any d-pad key clears it */
    char unk02[2];
    unsigned char slot;         /* 0x04 */
    char unk05[3];
    short level[5];             /* 0x08 */
    short index[5];             /* 0x12 */
    char unk1C[0x30 - 0x1C];
    int status;                 /* 0x30 cleared when the page is left */
    char unk34[0xFC - 0x34];
    struct FileList *list;      /* 0xFC 0 when there is no data */
} MenuPage;                     /* 0x100 */

/* The loaded file table a menu list shows. */
typedef struct MenuDir {
    int unk00;
    int count;                  /* 0x04 */
} MenuDir;

typedef struct MenuList {
    unsigned char unk00;
    unsigned char result;       /* 0x01 */
    char unk02[2];
    short unk04;                /* 0x04 */
    char unk06[2];
    short unk08;                /* 0x08 */
    short unk0A;                /* 0x0A */
    int status;                 /* 0x0C the stream's state, -1 without a stream */
    unsigned int count;         /* 0x10 */
    MenuInfo work;              /* 0x14 */
    char unk48[0x4C - 0x48];
    MenuInfo info;              /* 0x4C */
    char unk80[0x84 - 0x80];
    struct MenuDir *dir;        /* 0x84 */
} MenuList;

/* The sound settings of a menu: the picked slot and its five channel settings. */
typedef struct MenuSnd {
    unsigned char kind;         /* 0x00 */
    unsigned char result;       /* 0x01 a prompt is up; any d-pad key clears it */
    unsigned char slot;         /* 0x02 */
    char unk03;
    short level[5];             /* 0x04 */
    short index[5];             /* 0x0E */
    short panL[5];              /* 0x18 PAN_L */
    short panR[5];              /* 0x22 PAN_R */
    int status;                 /* 0x2C the stream's state */
} MenuSnd;                      /* 0x30 */

/* The stream position the sound test prints. */
typedef struct MenuSndInfo {
    int total;                  /* 0x00 TOTAL TIME, in samples */
    int rate;                   /* 0x04 sample rate ("SMPL LATE") */
    int track;                  /* 0x08 TRACK NUM */
    int phrase;                 /* 0x0C PHRASE NUM */
    int song;                   /* 0x10 SONG NUM */
    int time;                   /* 0x14 TIME, in samples */
    unsigned char mute[5];      /* 0x18 MUTE per slot */
    char unk1D[0x28 - 0x1D];
} MenuSndInfo;                  /* 0x28 */

typedef struct MenuCtl {
    unsigned char next;         /* 0x00 page to go to; 0 closes the page */
    unsigned char sel;          /* 0x01 picked entry */
    unsigned char state;        /* 0x02 */
    unsigned char detail;       /* 0x03 toggled by button 4: also read the stream's sizes */
    unsigned char row;          /* 0x04 */
    unsigned char slotNo;       /* 0x05 index into slot[] */
    unsigned char unk06;
    unsigned char cursor;       /* 0x07 */
    char unk08[0x14 - 0x08];
    char *name[13];             /* 0x014 entry names (g++ strings, length word 0x10 bytes before the text) */
    MenuSlot slot[10];          /* 0x048 */
    MenuSnd snd;                /* 0x318 */
    MenuSndInfo sndInfo;        /* 0x348 */
    MenuPage page;              /* 0x370 */
    MenuList list;              /* 0x470 */
} MenuCtl;

typedef char MenuSlot_size_check[sizeof(MenuSlot) == 0x48 ? 1 : -1];
typedef char MenuSnd_size_check[sizeof(MenuSnd) == 0x30 ? 1 : -1];
typedef char MenuSndInfo_size_check[sizeof(MenuSndInfo) == 0x28 ? 1 : -1];
typedef char MenuPage_size_check[sizeof(MenuPage) == 0x100 ? 1 : -1];

typedef struct SlotInfoA {
    char unk00[0x14];
    int info;                   /* 0x14 */
    char unk18[0x20 - 0x18];
    int handle;                 /* 0x20 */
    int buf;                    /* 0x24 freed once the handle stops */
} SlotInfoA;

typedef struct SlotInfoB {
    char unk00[0x10];
    int info;                   /* 0x10 */
    int size;                   /* 0x14 */
    float time;                 /* 0x18 */
    int stamp;                  /* 0x1C */
    char unk20[0x30 - 0x20];
    int handle;                 /* 0x30 */
    int buf;                    /* 0x34 freed once the handle stops */
} SlotInfoB;

typedef struct SlotView {
    unsigned char unk00[3];
    unsigned char flags;        /* 0x03 */
    char unk04[0x30 - 0x04];
    int stat;                   /* 0x30 */
    SlotInfoB b;                /* 0x34 */
    char unk6C[0xA4 - 0x34 - sizeof(SlotInfoB)];
    SlotInfoA a;                /* 0xA4 */
} SlotView;

typedef struct FileList {
    char unk00[8];
    int count;                  /* 0x08 */
} FileList;

typedef struct FileSelWork {
    unsigned char unk00;
    unsigned char err;          /* 0x01 */
    unsigned char unk02[2];
    unsigned char busy;         /* 0x04 */
    char unk05[0xF4 - 0x05];
    int req;                    /* 0xF4 */
    void *buf;                  /* 0xF8 */
    FileList *list;             /* 0xFC */
} FileSelWork;

typedef struct FileSel {
    unsigned char unk00[2];
    unsigned char state;        /* 0x02 */
    unsigned char unk03[3];
    unsigned char cursor;       /* 0x06 */
    char unk07[0x370 - 0x07];
    FileSelWork work;           /* 0x370 */
} FileSel;

extern int GuardedCall_00329FD0_329F98(int handle);
extern int func_00380AE8(MenuCtl *ctl, MenuInfo *info, MenuList *list);
extern void func_00380EB0(MenuCtl *ctl, MenuInfo *info, MenuList *list);
extern int func_0037FD28(FileSel *sel, FileSelWork *work);
extern void func_0037FC28(FileSel *self);
extern void func_0037FF98(MenuCtl *ctl);
extern int func_00323918(int a0, int idx);

/* One row of the option menu pages (D_003F21E8, D_003F2368, D_003F24D0). */
typedef struct MenuRowEnt {
    short unk0;
    short unk2;
    short unk4;
    short y;                            /* 0x06 */
    char unk8;
    signed char handler;                /* 0x09 index into D_003F2628 */
    char unkA[0xA];
} MenuRowEnt;

extern MenuRowEnt D_003F21E8[];
extern MenuRowEnt D_003F2368[];
extern MenuRowEnt D_003F24D0[];

/* The track set a sound option drives: its count and the player handle (0x24 bytes). */
typedef struct SndTrkSet {
    char unk00[8];
    int count;                          /* 0x08 */
    char unk0C[0x20 - 0x0C];
    void *ply;                          /* 0x20 player handle */
} SndTrkSet;

/* The voice reference of a sound option (the handle at 0x30). */
typedef struct SndVoiceRef {
    char unk00[0x30];
    void *voice;                        /* 0x30 voice handle */
} SndVoiceRef;

#endif /* GODHAND_MENUCTL_H */

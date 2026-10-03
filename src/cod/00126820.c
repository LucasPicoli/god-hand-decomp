/* sn-2.95.3-136 matched TU. */

#include "godhand/cMessage.h"
#include "godhand/cIDBase.h"
#include "godhand/vu0.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/cMessCommon.h"

extern unsigned int D_00747A78;
extern void func_002B2438(cMessageWin *win);
extern unsigned short D_003BD70C;
extern void cIDBase_resetAnim(void *id);
extern unsigned int D_007474A8;
extern cCollisionSolidObj *cCollisionSolid(cCollisionSolidObj *self);
extern void *EnsureInitThenForward_2A9538_30EE08(int size, int align, int heap);
extern int cMessCommon_getCodeSize(int code);

/* Update every open message window unless the lock bit is set; a window of kind 7 is deleted. */


#define MESS_LOCK        0x80000        /* D_00747A78 bit: windows frozen */
#define MESS_KIND_ONESHOT  7            /* window kind that goes away after its update */

/* The window past its link: the kind byte at 0x0C. */
typedef struct cMessageWinKind {
    cMessageWin base;                   /* 0x00 */
    unsigned char kind;                 /* 0x0C */
} cMessageWinKind;





__attribute__((section(".text.func_002AEFA8")))
void func_002AEFA8(cMessage *self) {
    cMessageWinKind *win;
    if (D_00747A78 & MESS_LOCK) return;
    win = (cMessageWinKind *)self->head;
    while (win) {
        func_002B2438(&win->base);
        /* xor spelling: retail tests with xori + branch, a plain == hoists the 7 into a register */
        if ((win->kind ^ MESS_KIND_ONESHOT) == 0) {
            win = (cMessageWinKind *)func_002AEF10(self, &win->base);
        } else {
            win = (cMessageWinKind *)win->base.next;
        }
    }
}

/* Reset the screen object: restart all seven display blocks and clear the cursor words. */


#define SCR_SLOT_NUM  5

/* Store through a cast pointer, not a member access. A member store cannot alias the scalar
 * global D_003BD70C, so the scheduler lifts that load above it; retail keeps the load after
 * the stores, which only the cast form reproduces. */
#define SCR_STORE(type, field, value)  (*(type *)&(field) = (value))

/* A display block sits on a 0x50 stride. */
typedef struct ScrIdSlot {
    cIDBaseObj id;                      /* 0x00 */
    char pad48[0x50 - sizeof(cIDBaseObj)];
} ScrIdSlot;

typedef struct ScrObj {
    char unk000[0x90];
    int unk90;                          /* 0x090 */
    char unk94[0x6C];
    ScrIdSlot slot[SCR_SLOT_NUM];       /* 0x100 */
    char unk290[0x18E];
    short unk41E;                       /* 0x41E */
    short unk420;                       /* 0x420 */
    char unk422[0xE];
    ScrIdSlot extraA;                   /* 0x430 */
    ScrIdSlot extraB;                   /* 0x480 */
    short unk4D0;                       /* 0x4D0 */
} ScrObj;

typedef char ScrObj_extraA_check[((int)&((ScrObj *)0)->extraA == 0x430) ? 1 : -1];
typedef char ScrObj_unk4D0_check[((int)&((ScrObj *)0)->unk4D0 == 0x4D0) ? 1 : -1];


extern void func_00144C90(ScrObj *self);


__attribute__((section(".text.func_00144C08")))
void func_00144C08(ScrObj *self) {
    unsigned short i;
    func_00144C90(self);
    for (i = 0; i < SCR_SLOT_NUM; i++) {
        cIDBase_resetAnim(&self->slot[i]);
    }
    cIDBase_resetAnim(&self->extraA);
    cIDBase_resetAnim(&self->extraB);
    SCR_STORE(short, self->unk41E, 0);
    SCR_STORE(short, self->unk420, 0);
    SCR_STORE(int, self->unk90, 0);
    SCR_STORE(short, self->unk4D0, D_003BD70C);
}

/* Enemy slot upkeep: with no key held count the cooldown down, then release the slot; a held key picks the slot kind. */
#define PAD_KEY_A     0x10      /* D_007474A8 bit: first button held */
#define PAD_KEY_B     0x80      /* D_007474A8 bit: second button held */
#define PAD_KEY_ANY   (PAD_KEY_A | PAD_KEY_B)

/* The enemy record: the slot cooldown at 0x1658. */
typedef struct EmSlotObj {
    char unk0000[0x1658];
    int cooldown;                       /* 0x1658 frames before the slot is released */
} EmSlotObj;


extern void func_001268F0(EmSlotObj *self);
extern void SetFirstFreeSlot_Field_1644_1268B0(EmSlotObj *self, int kind);

__attribute__((section(".text.func_00126820")))
void func_00126820(EmSlotObj *self) {
    unsigned int keys = D_007474A8;
    if ((keys & PAD_KEY_ANY) == 0) {
        if (self->cooldown != 0) {
            self->cooldown = self->cooldown - 1;
        } else {
            func_001268F0(self);
        }
    } else if (keys & PAD_KEY_A) {
        func_001268F0(self);
        SetFirstFreeSlot_Field_1644_1268B0(self, 2);
    } else if (keys & PAD_KEY_B) {
        SetFirstFreeSlot_Field_1644_1268B0(self, 1);
    }
}

/* Sphere constructor: run the base one, then set the sphere table, owner, state, centre and radius. */



#define CSOLID_CENTER_OFFSET  0x50      /* cCollisionSolidObj.center, for the VU0 store */
#define CSOLID_UNK60_OFFSET   0x60      /* cCollisionSolidObj.unk60 */

extern const unsigned char D_0041D7E0[];        /* sphere table */


__attribute__((section(".text.func_001339F0")))
cCollisionSolidObj *func_001339F0(cCollisionSolidObj *self, void *owner, cVec *center, float radius) {
    cVec *dst;
    cCollisionSolid(self);
    dst = &self->center;
    self->vt = D_0041D7E0;
    self->owner = owner;
    VU0_SQC2_VF0(self, CSOLID_CENTER_OFFSET);
    VU0_SQC2_VF0(self, CSOLID_UNK60_OFFSET);
    self->state = CSOLID_STATE_SPHERE;
    cVec_copy3(dst, center);
    self->radius = radius;
    return self;
}

/* Read the whole file named by D_0044C0B8 from the disc into a fresh buffer kept at 0x4C0, then wait for the read. */
#define CD_SECTOR_SHIFT  11             /* 2048 byte sectors */
#define CD_SECTOR_MASK   0x7FF
#define CD_BUF_ALIGN     0x40

/* sceCdRMode */
typedef struct CdRMode {
    unsigned char trycount;
    unsigned char spindlctrl;
    unsigned char datapattern;
    unsigned char pad;
} CdRMode;

/* sceCdlFILE */
typedef struct CdFile {
    unsigned int lsn;
    unsigned int size;
    char name[16];
    unsigned char date[8];
    char unk24[0xC];                    /* the search call may write past the 0x24 byte record */
} CdFile;

typedef struct FileLoader {
    char unk000[0x4C0];
    void *buf;                          /* 0x4C0 the file's contents */
} FileLoader;

extern char D_0044C0B8[];               /* file path */
extern int D_003C3CF0;                  /* heap the buffer comes from */
extern int func_00398B90(CdFile *file, const char *path);       /* sceCdSearchFile */
extern int sceCdRead(unsigned int lsn, unsigned int sectors, void *buf, CdRMode *mode);
extern int func_00398DA0(int mode);                             /* sceCdSync */

extern void *func_003A52F0(void *dst, int val, int n);          /* memset */

__attribute__((section(".text.func_002BE458")))
void func_002BE458(FileLoader *self) {
    CdRMode mode;
    CdFile file;
    unsigned int sectors;
    func_003A52F0(&mode, 0, sizeof(mode));
    mode.spindlctrl = 1;
    func_00398B90(&file, D_0044C0B8);
    sectors = (file.size + CD_SECTOR_MASK) >> CD_SECTOR_SHIFT;
    self->buf = EnsureInitThenForward_2A9538_30EE08(sectors << CD_SECTOR_SHIFT, CD_BUF_ALIGN, D_003C3CF0);
    sceCdRead(file.lsn, sectors, self->buf, &mode);
    func_00398DA0(0);
}

/* Message window: take one printable code at the read cursor, advance the pen and the cursor, drop two flags, redraw. */



#define MWIN_FLAG_A  0x2        /* flags bit cleared after a code is taken */
#define MWIN_FLAG_B  0x4        /* flags bit cleared after a code is taken */

/* The window past its link: kind, flags, pen, cursor. */
typedef struct MessWin {
    cMessageWin base;                   /* 0x00 */
    char unk0C[8];
    int flags;                          /* 0x14 */
    char unk18[0x18];
    unsigned char codeNum;              /* 0x30 codes taken so far */
    char unk31[0x37];
    int penA;                           /* 0x68 */
    char unk6C[0x10];
    unsigned short *nextCode;           /* 0x7C code after the one taken */
    char unk80[4];
    int penB;                           /* 0x84 */
    char unk88[4];
    unsigned short *cursor;             /* 0x8C read cursor */
    int pen;                            /* 0x90 pen position before the code */
} MessWin;



extern void func_002B43B0(MessWin *self);
extern void func_002B45E8(MessWin *self);

__attribute__((section(".text.func_002B3A38")))
int func_002B3A38(MessWin *self) {
    int pen;
    int size;
    pen = self->pen + func_002AF218(self->cursor);
    size = cMessCommon_getCodeSize(*self->cursor);
    self->penA = pen;
    self->penB = pen;
    self->nextCode = self->cursor + size;
    self->codeNum++;
    self->flags &= ~MWIN_FLAG_A;
    self->flags &= ~MWIN_FLAG_B;
    func_002B43B0(self);
    func_002B45E8(self);
    return 0;
}

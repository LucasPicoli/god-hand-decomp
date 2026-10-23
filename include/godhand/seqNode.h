/* include/godhand/seqNode.h - sequence nodes, links and stop commands (sn code at 0x37C330..).
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_SEQNODE_H
#define GODHAND_SEQNODE_H

typedef struct SeqRange {
    char unk00[0x18];
    short min;                  /* 0x18 */
    short max;                  /* 0x1A */
} SeqRange;

typedef struct SeqTimer {
    short f30;                  /* 0x30 */
    short f32;                  /* 0x32 */
    short unk34;
    short f36;                  /* 0x36 */
} SeqTimer;

typedef struct SeqNode {
    unsigned short flags;       /* 0x00 */
    short id;                   /* 0x02 */
    char unk04;
    unsigned char kind;         /* 0x05 */
    unsigned short sub;         /* 0x06 */
    struct SeqNode *parent;     /* 0x08 */
    int busy;                   /* 0x0C */
    int owner;                  /* 0x10 */
    int unk14;                  /* 0x14 */
    unsigned short unk18;       /* 0x18 */
    unsigned short unk1A;       /* 0x1A */
    unsigned short unk1C;       /* 0x1C */
    unsigned short unk1E;       /* 0x1E */
    unsigned short unk20;       /* 0x20 */
    unsigned short unk22;       /* 0x22 */
    char unk24[0x30 - 0x24];
    SeqTimer timer;             /* 0x30 */
    char unk38[0x3E - 0x38];
    unsigned short weight;      /* 0x3E high byte is the update weight */
    short unk40;                /* 0x40 */
    short angle;                /* 0x42 degrees */
    short pan;                  /* 0x44 0..0x7F, 0x40 is centre */
    char unk46[0x4A - 0x46];
    unsigned short unk4A;       /* 0x4A */
    unsigned short unk4C;       /* 0x4C */
    unsigned short unk4E;       /* 0x4E */
} SeqNode;

typedef struct SeqLink {
    unsigned short flags;       /* 0x00 */
    short id;                   /* 0x02 */
    char unk04;
    unsigned char kind;         /* 0x05 */
    char unk06[2];
    SeqNode *node;              /* 0x08 */
    unsigned int age;           /* 0x0C frames alive, saturates at 0xFFFFFFFF */
    int owner;                  /* 0x10 */
    char unk14[0x1E - 0x14];
    char unk1E;                 /* 0x1E */
    char unk1F;
} SeqLink;

/* A queued sound request (0x50 bytes, 48 of them at D_0076B9C0). */
typedef struct SeqCmd {
    unsigned short used;        /* 0x00 nonzero while queued */
    short id;                   /* 0x02 pool index */
    int owner;                  /* 0x04 */
    char unk08[4];
    unsigned char flags;        /* 0x0C SEQCMD_F_* */
    unsigned char mask;         /* 0x0D */
    short all;                  /* 0x0E -1 when cleared */
    short arg;                  /* 0x10 */
    short link;                 /* 0x12 -1 when cleared */
    char unk14[0x20 - 0x14];
    short req;                  /* 0x20 sound id; the channel allocators take the record from here */
    char unk22[4];
    signed char voice;          /* 0x26 voice kind func_0037D298 allocates */
    char unk27[0x48 - 0x27];
    unsigned short seqArg;      /* 0x48 */
    char unk4A[0x50 - 0x4A];
} SeqCmd;

#define SEQCMD_M_ALT      0x01  /* mask: take the channel from func_0037CF00 */
#define SEQCMD_M_SEQUENCE 0x08  /* mask: the request plays a sequence */

#define SEQCMD_F_STOP   0x10    /* a stop request rather than a start */
#define SEQCMD_NUM      48

extern SeqCmd D_0076B9C0[SEQCMD_NUM];
extern int func_0037C330(SeqCmd *c);
extern void func_0037BE98(void);

/* A sound voice node: its work and the method table it dispatches through. */
typedef struct SndVoiceNode {
    char unk00[0x80];
    struct cVtEnt *vt;          /* 0x80 */
} SndVoiceNode;                 /* 0x84 */

extern SndVoiceNode D_0076A600[3];

/* A sound channel (0xA0 bytes); flags is nonzero while it is in use. */
typedef struct SndCh {
    unsigned short flags;       /* 0x00 */
    char unk02[2];
    int unk04;                  /* 0x04 */
    unsigned short unk08;       /* 0x08 */
    unsigned short unk0A;       /* 0x0A */
    unsigned short unk0C;       /* 0x0C */
    unsigned char unk0E;        /* 0x0E */
    unsigned char unk0F;        /* 0x0F */
    char unk10[2];
    unsigned short unk12;       /* 0x12 */
    unsigned short kind;        /* 0x14 indexes the channel handler table */
    short unk16;                /* 0x16 */
    char unk18[0x78 - 0x18];
    int unk78[6];               /* 0x78 */
    char unk90[0x10];
} SndCh;

extern SndCh D_0076E910[];

/* Per-SPU2-core state (two cores, 0x20 bytes each). */
typedef struct SndCore {
    unsigned short used;        /* 0x00 */
    char unk02[2];
    unsigned short volL;        /* 0x04 */
    unsigned short volR;        /* 0x06 */
    unsigned short unk08;       /* 0x08 */
    unsigned short unk0A;       /* 0x0A */
    int effEnd;                 /* 0x0C end of the core's effect area in SPU2 RAM */
    int handle;                 /* 0x10 */
    short core;                 /* 0x14 */
    char unk16[0x20 - 0x16];
} SndCore;

extern SndCore D_0076A7D4[2];
extern int func_00374AE0(int id);
extern void func_00377CB8(void);

/* One voice in the output block posted to the sound driver (0x20 bytes, 64 of them). */
typedef struct SndVoiceOut {
    unsigned short flags;       /* 0x00 */
    unsigned char b2;
    unsigned char b3;
    int w4;
    int w8;
    unsigned short hC, hE, h10, h12, h14, h16, h18, h1A, h1C;
    char pad1E[2];
} SndVoiceOut;

extern SndVoiceOut D_0076A9C0[64];
#define SEQ_NUM 51

extern SeqLink D_0076C8C0[SEQ_NUM];
extern SeqNode D_0076CF20[SEQ_NUM];

extern void func_0037D148(SeqNode *n);
extern void func_0037D3B0(SeqNode *n);
extern void func_0037D820(SeqNode *n);
extern void func_0037D8B8(SeqNode *n, short arg);
extern void func_00378020(SeqTimer *t);
extern void func_0037D558(SeqNode *self);
extern void func_0037C720(SeqNode *self);
extern void func_003780F8(unsigned short angle, float *l, float *r);
extern int Obj0000_Get_D_0076A7A4_3756F0(void);   /* sound output mode: 0 mono, 1 stereo, 2 surround */

#endif /* GODHAND_SEQNODE_H */

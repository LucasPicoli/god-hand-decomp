/* include/godhand/cSnd.h - the sound manager.
 *
 * cSnd owns three things: a table of sound-effect slots, a list of voices
 * that are playing right now, and a list of BGM sequence nodes. Method names
 * are the game's own, from the symbol table in the retail ELF. Field names
 * are ours, taken from the methods that read and write them. Offsets are
 * exact: every body that uses this header builds byte-identical to retail.
 * A field nobody has named yet stays as unkNNN padding. The total size of
 * cSnd is not known, so the struct has no size check.
 *
 * Two files write here. Add fields at the right offset, and never rename or
 * move one that is already named.
 */
#ifndef GODHAND_CSND_H
#define GODHAND_CSND_H

#define CSND_SE_ENTRY_SHIFT   6      /* slot stride is 1 << 6 = 0x40 */
#define CSND_SE_STOP_NUM      8      /* handles kept by SeStop */
#define CSND_SE_RECENT_NUM    16     /* recent-call ring */
#define CSND_VOICE_NUM        0x40   /* voices in the pool */
#define CSND_BGM_NODE_NUM     0x10   /* nodes in the BGM pool */
#define CSND_SE_ENTRY_NUM     0x34   /* sound-effect slots */

/* Flags on a BGM node (cSndBgmNode.flags). */
#define CSND_BGM_FLAG_SUSPEND 0x800
#define CSND_BGM_FLAG_PAUSE   0x1000

/* One slot of the sound-effect table (cSnd.seEntry), 0x40 bytes. */
typedef struct cSndSeEntry {
    char unk00[0x10];
    int  id;                    /* 0x10 sound id the slot plays */
    char unk14[0x28];
    int  owner;                 /* 0x3C object id, -1 when free */
} cSndSeEntry;                  /* 0x40 */

/* One playing voice. The list hangs off cSnd.voiceHead. */
typedef struct cSndSeVoice {
    struct cSndSeVoice *prev;   /* 0x00 */
    struct cSndSeVoice *next;   /* 0x04 */
    short key0;                 /* 0x08 */
    short key1;                 /* 0x0A */
    unsigned int flags;         /* 0x0C bit 0: handle is live */
    int kind;                   /* 0x10 0 = global, 2 = follows an object */
    int handle;                 /* 0x14 sound-driver handle */
    unsigned int stateFlags;    /* 0x18 bit 0x10000: quiet, bit 0x10: tracks a ratio */
    unsigned int optFlags;      /* 0x1C */
    int delay;                  /* 0x20 frames left before the sound starts */
    int pri;                    /* 0x24 */
    short idA;                  /* 0x28 -1 when unused */
    short idB;                  /* 0x2A -1 when unused */
    char unk2C[0xC];
    void *obj;                  /* 0x38 object the sound follows */
    void *part;                 /* 0x3C part of that object */
    float pos[3];               /* 0x40 */
    float scale;                /* 0x4C */
} cSndSeVoice;                  /* 0x50 */

/* One call remembered by the recent-call ring. */
typedef struct cSndSeRecent {
    short a;                    /* 0x0 */
    short b;                    /* 0x2 */
    int   tick;                 /* 0x4 */
} cSndSeRecent;                 /* 8 */

/* A request to start a BGM sequence; copied into the node by the start code. */
typedef struct cSndBgmReq {
    int reqNo;                  /* 0x0 */
    int state;                  /* 0x4 */
    int param;                  /* 0x8 */
    unsigned short wordA;       /* 0xC */
    unsigned short wordB;       /* 0xE */
} cSndBgmReq;                   /* 0x10 */

/* One BGM sequence node. The sequence state sits first, then our fields. */
typedef struct cSndBgmNode {
    char unk00[0x5E];
    unsigned char started;      /* 0x5E */
    char unk5F;
    unsigned char started60;    /* 0x60 */
    unsigned char unk61;        /* 0x61 */
    char unk62[0x22];
    struct cSndBgmNode *prev;   /* 0x84 */
    struct cSndBgmNode *next;   /* 0x88 */
    int bank;                   /* 0x8C bgm bank, biased by 0x80 */
    int reqNo;                  /* 0x90 request number */
    int state;                  /* 0x94 */
    unsigned int flags;         /* 0x98 */
    int param;                  /* 0x9C */
    short wordA;                /* 0xA0 */
    short wordB;                /* 0xA2 */
    int *link;                  /* 0xA4 */
    int *entry;                 /* 0xA8 */
    int matchWt;                /* 0xAC saveWt must equal this before the node may start */
    int state2;                 /* 0xB0 2 = finished */
    int wait;                   /* 0xB4 countdown, frames */
    int data;                   /* 0xB8 bgm data record */
    int saveWt;                 /* 0xBC */
    int prevWt;                 /* 0xC0 */
    float volume;               /* 0xC4 */
    float fadeTime;             /* 0xC8 */
    char unkCC[0x10];
} cSndBgmNode;                  /* 0xDC */

/* The sound memory heap hands out chunks tracked by a doubly linked list of blocks.
   Three heaps sit in a row (D_00602F80, D_00603310, D_006036A0), 0x390 bytes apart. */
#define CSND_HEAP_BLK_NUM 0x20
typedef struct cSndMemHeap cSndMemHeap;
typedef struct cSndMemBlk {
    cSndMemHeap *owner;         /* 0x00 */
    struct cSndMemBlk *next;    /* 0x04 */
    struct cSndMemBlk *prev;    /* 0x08 */
    int freeSize;               /* 0x0C bytes still free behind this block */
    int top;                    /* 0x10 first free address */
    int base;                   /* 0x14 address of the chunk, 0 = block unused */
    int size;                   /* 0x18 chunk size */
} cSndMemBlk;                   /* 0x1C */

struct cSndMemHeap {
    cSndMemBlk blk[CSND_HEAP_BLK_NUM];  /* 0x000 block 0 is the whole heap */
    cSndMemHeap *self;          /* 0x380 non-zero while the heap is set up */
    int size;                   /* 0x384 */
    int base;                   /* 0x388 chunk taken from the parent, 0 = none */
    cSndMemHeap *parent;        /* 0x38C */
};                              /* 0x390 */

typedef struct cSnd {
    char unk00[0x18];
    cSndBgmNode *bgmHead;       /* 0x18 first BGM node */
    cSndSeVoice *voiceHead;     /* 0x1C first playing voice */
    char unk20[4];
    struct cBgmHit *hit;        /* 0x24 BGM hit table */
    char unk28[0xC];
    cSndSeVoice *voicePool;     /* 0x34 CSND_VOICE_NUM voices */
    cSndBgmNode *bgmPool;       /* 0x38 CSND_BGM_NODE_NUM nodes */
    cSndSeEntry *seEntry;       /* 0x3C sound-effect slot table */
    char unk40[4];
    int f44;                    /* 0x44 */
    int f48;                    /* 0x48 */
    char unk4C[0x20];
    float f6C;                  /* 0x6C weight BGM nodes are blended with */
    char unk70[0x2C];
    float f9C;                  /* 0x9C fade ratio, 0..1 */
    char unkA0[0xC];
    unsigned int flagsAC;       /* 0xAC */
    unsigned int flagsB0;       /* 0xB0 */
    char unkB4[0xC];
    float listenPos[4];         /* 0xC0 listener position */
    float listenMtx[16];        /* 0xD0 world to listener matrix */
    int f110;                   /* 0x110 */
    char unk114[4];
    int curBank;                /* 0x118 bank of the BGM now playing, unbiased */
    int curReq;                 /* 0x11C its request number */
    int curWt;                  /* 0x120 its stored weight */
    char unk124[4];
    int f128;                   /* 0x128 */
    char unk12C[8];
    int f134;                   /* 0x134 countdown frames */
    int f138;                   /* 0x138 */
    int bgmState;               /* 0x13C eBgmState */
    int seStop[CSND_SE_STOP_NUM];       /* 0x140 */
    cSndSeRecent recent[CSND_SE_RECENT_NUM]; /* 0x160 */
    int recentPos;              /* 0x1E0 */
    char unk1E4[0xC];
    cSndSeEntry seTable[CSND_SE_ENTRY_NUM]; /* 0x1F0 sound-effect slots */
    char bgmData[0x88];         /* 0xEF0 two cBgmData records, 0x44 bytes each */
    char unkF78[8];
    cSndSeVoice voice[CSND_VOICE_NUM];      /* 0xF80 voice pool, voicePool points here */
    cSndBgmNode node[CSND_BGM_NODE_NUM];    /* 0x2380 BGM node pool, bgmPool points here */
} cSnd;

/* Size checks: a negative array size stops the build if a layout drifts. */
typedef char cSndSeEntry_size_check[sizeof(cSndSeEntry) == 0x40 ? 1 : -1];
typedef char cSndSeVoice_size_check[sizeof(cSndSeVoice) == 0x50 ? 1 : -1];
typedef char cSndBgmNode_size_check[sizeof(cSndBgmNode) == 0xDC ? 1 : -1];
typedef char cSndMemHeap_size_check[sizeof(cSndMemHeap) == 0x390 ? 1 : -1];

#endif /* GODHAND_CSND_H */

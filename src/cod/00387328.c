/* sn-2.95.3-136: strFadeSetOne, queues a voice-parameter command: with val 0 or -1 every channel is
 * reset (mask 0xF), otherwise the channels in mask get (prm, val); returns 0, or -1 if the queue is full. */
typedef struct SndCmdCh {
    short unk0;
    short prm;      /* +2 */
    short unk4;
    short val;      /* +6 */
} SndCmdCh;

typedef struct SndCmd {
    short used;             /* 0x00 */
    short unk2;
    int unk4;               /* 0x04 */
    unsigned char type;     /* 0x08 */
    unsigned char sub;      /* 0x09 */
    short unkA;             /* 0x0A */
    short id;               /* 0x0C */
    char unkE[0x12];
    SndCmdCh ch[4];         /* 0x20 */
    int mask;               /* 0x40 */
} SndCmd;

extern SndCmd *SdeStrExeOpen(void);

__attribute__((section(".text.strFadeSetOne")))
int strFadeSetOne(short id, short prm, short val, int mask)
{
    SndCmd *c = SdeStrExeOpen();
    unsigned int i;
    int bit;

    if (c == 0)
        return -1;
    c->used = 1;
    c->type = 0x10;
    c->sub = 2;
    c->id = id;
    c->unk4 = 0;
    c->unkA = 0;
    if ((unsigned short)(val + 1) < 2) {
        for (i = 0; i < 4; i++) {
            c->ch[i].prm = 0;
            c->ch[i].val = 1;
        }
        c->mask = 0xF;
        return 0;
    }
    bit = 1;
    for (i = 0; i < 4; i++) {
        if (mask & bit) {
            c->ch[i].prm = prm;
            c->ch[i].val = val;
        }
        bit <<= 1;
    }
    c->mask = mask;
    return 0;
}

/* cygnus-2.96 matched TU. */

#include "godhand/criSj.h"

extern int D_003C7400;
extern int D_003C7408;
extern int D_003C7410;
extern int D_003C7414;
extern volatile int D_003C7418;
extern char D_003C7420[];
extern volatile int D_00755C1C;
extern char D_00451AC0[];
extern char D_00451B10[];
extern char D_00451B20[];
extern char D_00451B30[];
extern void func_0033E618(void);
extern void Forward33B658_33E678(void);
extern void func_0033A090(void);
extern void func_003394A0(void);
extern void func_00338A90(void);
extern void func_0033F0B8(void);
extern void func_0033F3F0(void);
extern void Obj3260_Tramp_00337728_D288(void);
extern void func_00335DE0(void);
extern void func_0033BE80(void);
extern void Obj3260_NoOp_D2B8(void *fn, int arg);
extern void func_00335D18(void *fn, int arg);
extern void func_003A52F0(void *dst, int val, int len);
extern void func_0032AB28(int a0);
extern void Forward33B670_33E690(void);
extern void Forward33F130_3248C0(void);
extern void Forward33F130_3248D8(void);
extern void func_00324910(void);
extern void func_00324930(void);
extern void func_003248F0(void);
extern char D_00455B58[];
extern char D_00455B68[];
extern char D_00455B78[];
extern char D_00455A80[];
extern char D_00455AB0[];
extern char D_00455B20[];
extern void func_00339458(const char *msg, const char *fn);
extern char D_00455B38[];
extern char D_00455B48[];
extern void func_0036EE90(void *hn, char *start, int skipped);

/* Reference-counted start of the stream manager: the first caller sets up the module and registers the handlers. */
__attribute__((section(".text.func_00324950")))
void func_00324950(void)
{
    int *count = &D_003C7400;
    int h;
    int c;

    c = *count;
    D_00755C1C = (int)D_00451AC0;
    if (c == 0) {
        func_0033E618();
        Forward33B658_33E678();
        func_0033A090();
        func_003394A0();
        func_00338A90();
        func_0033F0B8();
        func_003279B8();
        func_003264C8();
        func_0033F3F0();
        Obj3260_Tramp_00337728_D288();
        func_00335DE0();
        func_0033BE80();
        Obj3260_NoOp_D2B8(Forward33F130_3248C0, 0);
        func_00335D18(Forward33F130_3248D8, 0);
        func_003A52F0(D_003C7420, 0, 0xC80);
        func_0033BA10(2, 1, func_00324910, 0, D_00451B10);
        h = func_0033B810(4, func_00324930, 0, D_00451B20);
        D_003C7414 = h;
        D_003C7408 = func_0033B810(5, func_003248F0, 0, D_00451B30);
        D_003C7418 = 0;
        D_003C7410 = 0;
        func_0032AB28(0x3C);
        Forward33B670_33E690();
        c = *count;
    }
    *count = c + 1;
}

/* SJ ring buffer UngetChunk: take back the last chunk handed out from lane 0 (free) or lane 1 (data)
 * when it ends where that lane's position stands; a mismatch or any other lane reports -3. */
__attribute__((section(".text.func_00339CB8")))
void func_00339CB8(SjRbf *sj, int id, SjChunk *ck)
{
    int size;
    int len;
    Sint8 *data;
    int pos;

    if (sj == 0) {
        func_00339458(D_00455B58, D_00455A80);
        return;
    }
    if (sj->used == 0) {
        func_00339458(D_00455B68, D_00455AB0);
        return;
    }
    size = sj->size;
    if (size == 0) {
        func_00339458(D_00455B78, D_00455B20);
        return;
    }
    len = ck->len;
    if (len <= 0)
        return;
    data = ck->data;
    if (data == 0)
        return;
    if (id == 0) {
        pos = (sj->freePos + size - len) % size;
        if (pos == (data - sj->buf) % size) {
            sj->freePos = pos;
            sj->free += ck->len;
        } else if (sj->err != 0) {
            sj->err(sj->errObj, -3);
        }
        sj->freeTaken -= ck->len;
    } else if (id == 1) {
        pos = (sj->dataPos + size - len) % size;
        if (pos == (data - sj->buf) % size) {
            sj->dataPos = pos;
            sj->data += ck->len;
        } else if (sj->err != 0) {
            sj->err(sj->errObj, -3);
        }
        sj->dataTaken -= ck->len;
    } else {
        ck->len = 0;
        ck->data = 0;
        if (sj->err != 0)
            sj->err(sj->errObj, -3);
    }
}

#define MIN(a, b) ((a) < (b) ? (a) : (b))

/* SJ ring buffer PutChunk: give back a chunk that lies inside the ring buffer to lane 1 (data) or
 * lane 0 (free), mirroring bytes across the wrap area; other lanes clear the chunk and report -3. */
__attribute__((section(".text.func_00339AE8")))
void func_00339AE8(SjRbf *sj, int id, SjChunk *ck)
{
    int off;
    int end;
    int n;
    int len;
    int cnt;
    int size;
    Sint8 *data;

    if (sj == 0) {
        func_00339458(D_00455B38, D_00455A80);
        return;
    }
    if (sj->used == 0) {
        func_00339458(D_00455B48, D_00455AB0);
        return;
    }
    len = ck->len;
    cnt = len;
    if (len <= 0)
        return;
    data = ck->data;
    if (data == 0)
        return;
    if (id == 1) {
        off = data - sj->buf;
        if (off < sj->extra) {
            size = sj->size;
            n = MIN(len, sj->extra - off);
            func_003A5148(sj->buf + (size + off), data, n);
            cnt = ck->len;
            data = ck->data;
            off = data - sj->buf;
        }
        off = off + cnt;
        size = sj->size;
        end = off;
        if (size < end) {
            n = MIN(cnt, end - size);
            func_003A5148(sj->buf, sj->buf + (end - n), n);
            cnt = ck->len;
        }
        sj->data += cnt;
        sj->unk34 += ck->len;
    } else if (id == 0) {
        sj->free += len;
        sj->unk2C += ck->len;
    } else {
        ck->len = 0;
        ck->data = 0;
        if (sj->err != 0)
            sj->err(sj->errObj, -3);
    }
}

/* cygnus-2.96: MPEG start-code search over a bit stream, bit reader inlined; counts the bytes skipped. */
#define REFILL()                                    \
    nxt = *p++;                                     \
    nxt <<= 8;                                      \
    nxt |= (unsigned char)*p++;                     \
    nxt <<= 8;                                      \
    nxt |= (unsigned char)*p++;                     \
    nxt <<= 8;                                      \
    nxt |= (unsigned char)*p++

#define MPV_SCAN_MAX    0xFFFFF         /* bytes scanned before giving up */
#define MPV_START_PFX   1               /* the 24 bits 00 00 01 */



typedef struct MpvBits {
    char unk00[0x30];
    unsigned int word;                  /* 0x30 first aligned window of the stream */
    char unk34[0x2D4];
    int mode;                           /* 0x308 */
    int modeB;                          /* 0x30C */
    char unk310[0x124];
    int calls;                          /* 0x434 */
    char unk438[0x5C];
    int counter;                        /* 0x494 */
} MpvBits;

/* Searches the stream from `start` for the next start code and returns a pointer just past its prefix. */
__attribute__((section(".text.func_0036EC78")))
char *func_0036EC78(char *hn, char *start)
{
    MpvBits *d = (MpvBits *)(hn + 0x160);
    char *p;
    unsigned int acc;
    unsigned int nxt;
    unsigned int pfx;
    int bitpos;
    int cnt;

    d->calls = d->calls + 1;
    if ((d->mode != 0 && d->mode != 0x20) || d->modeB != 0) {
        d->counter = d->counter + 1;
    }

    p = (char *)((int)start & ~3);
    bitpos = ((int)start - (int)p) * 8;

    acc = *p++;
    acc <<= 8;
    acc |= (unsigned char)*p++;
    acc <<= 8;
    acc |= (unsigned char)*p++;
    acc <<= 8;
    acc |= (unsigned char)*p++;
    REFILL();

    acc <<= bitpos;
    if (bitpos != 0) {
        d->word = acc | (nxt >> (32 - bitpos));
        acc = nxt << bitpos;
    } else {
        d->word = acc;
        acc = nxt;
    }
    REFILL();

    for (cnt = 0; cnt <= MPV_SCAN_MAX; cnt++) {
        pfx = acc >> 8;
        acc <<= 8;
        if (bitpos >= 9)
            pfx |= nxt >> (0x28 - bitpos);
        if (pfx == MPV_START_PFX)
            break;
        bitpos += 8;
        if (bitpos >= 0x20) {
            bitpos -= 0x20;
            acc = nxt << bitpos;
            REFILL();
        }
    }
    func_0036EE90(hn, start, cnt + 4);
    return start + (bitpos + (p - start) * 8 - 57) / 8;
}

/* cygnus-2.96 matched TU. */

/* func_00372590 — MPEG-1 picture_header() parser, bit reader inlined.
   MATCH: cygnus-2.96 with -freorder-blocks DROPPED.
     python3 .private/scripts/score_candidate.py func_00372590 <this file> \
             --compiler cygnus-2.96 --drop-freorder-blocks
   ctx+0x160 is the decoder state; 0xD8..0xFC are the picture-header fields
   (start code / temporal_reference / picture_coding_type / vbv_delay /
    full_pel+f_code fwd,bwd / extra_bit_picture + extra_information_picture). */

#define REFILL()                                    \
    nxt = *p++;                                     \
    nxt <<= 8;                                      \
    nxt |= (unsigned char)*p++;                     \
    nxt <<= 8;                                      \
    nxt |= (unsigned char)*p++;                     \
    nxt <<= 8;                                      \
    nxt |= (unsigned char)*p++

#define GETBITS(n, off)                                             \
    if (bitpos >= 32 - (n)) {                                       \
        bitpos -= 32 - (n);                                         \
        if (bitpos != 0) {                                          \
            acc |= nxt >> ((n) - bitpos);                           \
            *(int *)(d + (off)) = acc >> (32 - (n));                \
            acc = nxt << bitpos;                                    \
        } else {                                                    \
            *(int *)(d + (off)) = acc >> (32 - (n));                \
            acc = nxt;                                              \
        }                                                           \
        REFILL();                                                   \
    } else {                                                        \
        *(int *)(d + (off)) = acc >> (32 - (n));                    \
        acc <<= (n);                                                \
        bitpos += (n);                                              \
    }

__attribute__((section(".text.func_00372590")))
char *func_00372590(char *ctx, char *start)
{
    char *d;
    char *p;
    unsigned int acc;
    unsigned int nxt;
    int bitpos;
    int state;
    int type;
    int cnt;
    int m;
    int nb;

    d = ctx + 0x160;
    *(int *)(d + 0x440) = *(int *)(d + 0x440) + 1;
    *(int *)(d + 0x420) = 3;
    state = *(int *)(d + 0x308);
    if ((state != 0 && state != 4) || *(int *)(d + 0x30C) != 0) {
        *(int *)(d + 0x494) = *(int *)(d + 0x494) + 1;
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
        *(int *)(d + 0xD8) = acc | (nxt >> (32 - bitpos));
        acc = nxt << bitpos;
    } else {
        *(int *)(d + 0xD8) = acc;
        acc = nxt;
    }
    REFILL();

    GETBITS(10, 0xDC);
    GETBITS(3, 0xE0);
    GETBITS(16, 0xE4);

    type = *(int *)(d + 0xE0);
    if ((unsigned int)(type - 1) >= 3) {
        *(int *)(d + 0x494) = *(int *)(d + 0x494) + 1;
    }
    if ((unsigned int)(type - 1) < 2) {
        *(int *)(d + 0x4A8) = 0;
        cnt = *(int *)(d + 0x4A4) + 1;
        *(int *)(d + 0x4A4) = cnt;
        *(int *)(d + 0x4AC) = cnt << 16;
    } else {
        m = *(int *)(d + 0x4A8) + 1;
        *(int *)(d + 0x4A8) = m;
        *(int *)(d + 0x4AC) = ((*(int *)(d + 0x4A4) - 1) << 16) | m;
    }

    if ((unsigned int)(type - 2) < 2) {
        GETBITS(1, 0xE8);
        GETBITS(3, 0xEC);
    }
    if (type == 3) {
        GETBITS(1, 0xF0);
        GETBITS(3, 0xF4);
    }

    for (;;) {
        GETBITS(1, 0xF8);
        if (*(int *)(d + 0xF8) == 0) {
            break;
        }
        GETBITS(8, 0xFC);
    }

    nb = bitpos + (p - start) * 8;
    *(int *)(d + 0x444 + type * 4) = *(int *)(d + 0x444 + type * 4) + 1;
    *(int *)(d + 0x308) = 0x10;
    *(int *)(d + 0x30C) = 8;
    return start + (nb - 57) / 8;
}

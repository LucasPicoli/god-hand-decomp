/* include/godhand/SjRing.h - a ring buffer filled from a stream joint (ee-2.9 code at 0x3BA5A0).
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_SJRING_H
#define GODHAND_SJRING_H

#include "godhand/criSj.h"

#define SJRING_HEADER   8       /* bytes at the start of buf the payload follows */
#define SJRING_ERR      (-1)

typedef struct SjRing {
    char unk00[8];
    char *buf;                  /* 0x08 */
    int size;                   /* 0x0C total bytes of buf */
    SjObj *sj;                  /* 0x10 source joint */
    char unk14[0x34 - 0x14];
    int want;                   /* 0x34 payload bytes still to read */
} SjRing;

extern void *func_003A5148(void *dst, const void *src, int len);
extern void func_003B9DE0(const char *msg);
extern void *func_003A52F0(void *dst, int c, int n);

#endif

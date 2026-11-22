/* include/godhand/criAix.h - CRI AIX demultiplexer (cygnus code at 0x32F580..).
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_CRIAIX_H
#define GODHAND_CRIAIX_H

#include "godhand/criSj.h"

typedef struct AixHdr {
    int f0;                     /* 0x00 */
    int f4;                     /* 0x04 */
    unsigned char f8;           /* 0x08 */
    unsigned char f9;           /* 0x09 */
    short fA;                   /* 0x0A */
    int fC;                     /* 0x0C */
} AixHdr;

typedef struct AixInfo {
    char unk00[0x0C];
    char nOut;                  /* 0x0C */
    char unk0D[0x10 - 0x0D];
} AixInfo;

typedef struct AixDmx {
    char unk00;
    char stat;                  /* 0x01 */
    char nOutMax;               /* 0x02 */
    char unk03;
    char more;                  /* 0x04 */
    char unk05[0x08 - 0x05];
    int total;                  /* 0x08 */
    char unk0C[0x1C - 0x0C];
    SjObj *sj;                  /* 0x1C */
    SjObj *out[4];              /* 0x20 */
    char unk30[0xA0 - 0x30];
    AixInfo info;               /* 0xA0 */
    char unkB0[0x1958 - 0xB0];
    int noHdr;                  /* 0x1958 */
    void (*hdrCb)(void *arg, AixInfo *info);    /* 0x195C */
    void *hdrCbArg;             /* 0x1960 */
} AixDmx;

extern int func_0032F580(unsigned char *ptr, int len, AixInfo *info);
extern void SJ_SplitChunk(SjChunk *ck, int len, SjChunk *head, SjChunk *tail);

#endif /* GODHAND_CRIAIX_H */

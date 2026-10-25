/* include/godhand/sftrnHn.h - the 0x1C0-byte Sofdec transport handle (CRI libsfd, src/cod/0035c0.c).
 *
 * The 64-bit fields are timing values in microseconds and stream positions;
 * the matched initialiser stores them with sd, so they are long long here.
 * Field names are ours, taken from that initialiser; offsets are exact. A
 * field nobody has named yet stays as unkNNN padding.
 */
#ifndef GODHAND_SFTRNHN_H
#define GODHAND_SFTRNHN_H

#define SFTRN_HN_SIZE   0x1C0
#define SFTRN_USEC_SEC  1000000     /* one second in microseconds */

typedef struct SftrnHn {
    int used;                           /* 0x000 */
    int unk04;                          /* 0x004 */
    int unk08;                          /* 0x008 */
    int one0C;                          /* 0x00C */
    int cnt10;                          /* 0x010 */
    char unk14[0xF4];
    long long pos108;                   /* 0x108 */
    long long unk110;                   /* 0x110 */
    long long unk118;                   /* 0x118 */
    long long unk120;                   /* 0x120 */
    long long unk128;                   /* 0x128 */
    long long unk130;                   /* 0x130 */
    long long id138;                    /* 0x138 */
    long long usecA;                    /* 0x140 */
    long long usec148;                  /* 0x148 */
    long long usecB;                    /* 0x150 */
    long long unk158;                   /* 0x158 */
    long long usecC;                    /* 0x160 */
    long long unk168;                   /* 0x168 */
    long long usec170;                  /* 0x170 */
    long long unk178;                   /* 0x178 */
    long long unk180;                   /* 0x180 */
    long long unk188;                   /* 0x188 */
    int unk190[10];                     /* 0x190 */
    int unk1B8;                         /* 0x1B8 */
    char unk1BC[4];
} SftrnHn;                              /* 0x1C0 */

extern void func_003A52F0(void *dst, int val, int n);
extern void func_0035C480(char *hn);
extern void func_0035CB20(void);

#endif

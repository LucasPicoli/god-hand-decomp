/* include/godhand/sfdRing.h - the two-segment view of the Sofdec stream ring (CRI libsfd, 0x350F48).
 *
 * The ring buffer is handed out as two byte runs, because the data may
 * wrap: p0/n0 is the first run and p1/n1 the part after the wrap. A delimiter
 * (an MPEG start code) may straddle the join.
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_SFDRING_H
#define GODHAND_SFDRING_H

#define SFDRING_DELIM_LEN   4       /* bytes of a start code */

/* MPV_CheckDelim results this code acts on. */
#define MPV_DELIM_SEQ       4
#define MPV_DELIM_PIC       8
#define MPV_DELIM_SKIP_A    0x40
#define MPV_DELIM_SKIP_B    0x80

/* Mask bits that allow each kind of delimiter. */
#define SFDRING_MASK_PIC    0x40
#define SFDRING_MASK_SEQ    0x48

typedef struct SfdRing {
    unsigned char *p0;                  /* 0x00 */
    int n0;                             /* 0x04 */
    unsigned char *p1;                  /* 0x08 */
    int n1;                             /* 0x0C */
    int pad10[2];
} SfdRing;

typedef struct SfdDelim {
    char b[SFDRING_DELIM_LEN];
} SfdDelim;

/* The Sofdec handle seen from the ring code: it owns the stream joint at 0x1FC8. */
typedef struct SfdRingView {
    char unk0000[0x1FC8];
    int sj;                             /* 0x1FC8 */
} SfdRingView;

#endif

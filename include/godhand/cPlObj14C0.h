/* include/godhand/cPlObj14C0.h - the 0x14C0-byte player-side object built at
 * 0x313030 (sn code), factory id 0x103.
 * Derives from cPlBase (method table at 0x214); its constructor zeroes two
 * vectors at 0x1460. Field names are ours; offsets are exact.
 */
#ifndef GODHAND_CPLOBJ14C0_H
#define GODHAND_CPLOBJ14C0_H

#define CPLOBJ14C0_SIZE     0x14C0
#define CPLOBJ14C0_ALIGN    0x10
#define CPLOBJ14C0_VEC_NUM  2           /* vectors at 0x1460 */
#define CPLOBJ14C0_NO_NEW   0x10000     /* D_00747A34 bit: this allocator is locked */

typedef struct cPlObj14C0 {
    char base[0x214];                   /* cPlBase */
    void *vt;                           /* 0x214 */
    char unk218[0x1460 - 0x218];
    float vec[CPLOBJ14C0_VEC_NUM][4];   /* 0x1460 zeroed by the constructor */
    char unk1480[0x14C0 - 0x1480];
} cPlObj14C0;

typedef char cPlObj14C0_size_check[sizeof(cPlObj14C0) == CPLOBJ14C0_SIZE ? 1 : -1];

#endif

/* include/godhand/adxbMix.h - the per-stream mixer record of an ADXB decoder object (CRI libadxe, src/cod/0033d*.c).
 *
 * Three halfwords at 0xA0 hold one channel setting each. A fresh stream has
 * them all zero; the getter then loads the defaults from D_003E9D54.. before
 * it reports them. Field names are ours, taken from the matched getter;
 * offsets are exact. A field nobody has named yet stays as unkNNN padding.
 */
#ifndef GODHAND_ADXBMIX_H
#define GODHAND_ADXBMIX_H

#define ADXB_MIX_KIND_NUM   4       /* kinds below this report zeros */
#define ADXB_MIX_SUB_ZERO   8       /* sub ids below this report zeros */
#define ADXB_MIX_SUB_NUM    0x10    /* sub ids from here on are an error */

typedef struct AdxbMix {
    char unk00[0xA0];
    unsigned short ch[3];               /* 0xA0 */
    char unkA6[0x104 - 0xA6];
} AdxbMix;                              /* 0x104 */

extern unsigned short D_003E9D54;
extern unsigned short D_003E9D56;
extern unsigned short D_003E9D58;
extern char D_004568F8[];
extern int func_003A6C58(char *buf, const char *fmt, ...);
extern void func_0033C548(char *msg, int code, unsigned short *a, unsigned short *b, unsigned short *c);

#endif

/* include/godhand/cObj21C0.h - the 0x21C0-byte game object built at 0x3132D0 (sn code).
 * Derives from cGameObj; holds an array of 44 zeroed 0xA0-byte records at 0x5B0.
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_COBJ21C0_H
#define GODHAND_COBJ21C0_H

#define COBJ21C0_SIZE       0x21C0
#define COBJ21C0_ALIGN      0x10
#define COBJ21C0_ENT_NUM    44          /* records at 0x5B0 */
#define COBJ21C0_ENT_SIZE   0xA0
#define COBJ21C0_NO_NEW     0x100000    /* D_00747A34 bit: allocator locked */

typedef struct cObj21C0Ent {
    char unk00[COBJ21C0_ENT_SIZE];
} cObj21C0Ent;

typedef struct cObj21C0 {
    char base[0x214];                   /* cGameObj */
    void *vt;                           /* 0x214 */
    char unk218[0x5B0 - 0x218];
    cObj21C0Ent ent[COBJ21C0_ENT_NUM];  /* 0x5B0 */
    char unk21B0[0x2190 - 0x5B0 - sizeof(cObj21C0Ent) * COBJ21C0_ENT_NUM];
    char tail[0x21C0 - 0x2190];         /* 0x2190 */
} cObj21C0;

typedef char cObj21C0_size_check[sizeof(cObj21C0) == COBJ21C0_SIZE ? 1 : -1];

extern int D_00747A34;
extern char D_00754220[];
extern char D_00447F70[];
extern void *EnsureInitThenForward_2A9538_30EE08(int size, int align, void *region);
extern void *func_003A52F0(void *dst, int val, int len);
extern void cGameObj(void *self);

#endif

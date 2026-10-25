/* include/godhand/Obj33C8.h - the 0x104-byte object owned by src/cod/0033c8.c.
 *
 * Offset 0x8 holds a pointer to a small 0x3C-byte record (the Obj33F8 methods
 * in src/cod/0033f8.c): a lock word at 0xC, four u16 at 0x28..0x2E and three
 * s16 at 0x34..0x38. The outer object caches copies of those u16 values at
 * 0xA6..0xB2. Field names are ours, taken from the methods that touch them.
 * Offsets are exact. A field nobody has named yet stays as unkNNN padding.
 */
#ifndef GODHAND_OBJ33C8_H
#define GODHAND_OBJ33C8_H

#define OBJ33C8_SIZE 0x104

typedef struct Obj33F8 Obj33F8;

typedef struct Obj33C8 {
    short state;                        /* 0x00 cleared on reset */
    char unk02[6];
    Obj33F8 *rec;                       /* 0x08 */
    char unk0C[0x9A];
    unsigned short trio[3];             /* 0xA6 cached rec s16 trio */
    unsigned short pairA[2];            /* 0xAC cached rec u16 pair, first array */
    unsigned short pairB[2];            /* 0xB0 cached rec u16 pair, second array */
    char unkB4[0x50];
} Obj33C8;                              /* 0x104 */

extern void Obj33F8_LoadPair_28_2C_F9D8(Obj33F8 *rec, unsigned short *a, unsigned short *b);
extern void Obj33F8_LoadU16Trio_34_FA10(Obj33F8 *rec, unsigned short *a, unsigned short *b, unsigned short *c);
extern void Obj33F8_InitIfNonNull_FA30(Obj33F8 *rec);
extern void *func_003A52F0(void *dst, int c, int n); /* memset */

#endif

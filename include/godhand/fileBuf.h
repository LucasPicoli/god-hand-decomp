/* include/godhand/fileBuf.h - D_0061B280, the debug text state (sn code at 0x2E0AE0..0x2E1414).
 *
 * FileBuf_init sets the character size to 8 by 8 and allocates the 0x1000
 * byte buffer; Moji_size_set changes the character size; func_002E0F18 draws
 * a string from the cursor and leaves the cursor after it. The formatted
 * text goes to D_0061B298, the 0x200 bytes right after the record.
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_FILEBUF_H
#define GODHAND_FILEBUF_H

#define FILEBUF_DRAWN_MAX  0x800        /* characters queued; nothing in retail resets the count */

typedef struct FileBuf {
    char unk00[8];
    unsigned char charW;                /* 0x08 character width (Moji_size_set) */
    unsigned char charH;                /* 0x09 character height */
    short count;                        /* 0x0A */
    unsigned short curX;                /* 0x0C x after the last string drawn (nothing reads it) */
    unsigned short curY;                /* 0x0E */
    unsigned short lineX;               /* 0x10 x a new line starts at (never written, so 0) */
    unsigned short drawn;               /* 0x12 characters queued */
    void *buf;                          /* 0x14 */
} FileBuf;

typedef char FileBuf_size_check[sizeof(FileBuf) == 0x18 ? 1 : -1];

extern FileBuf D_0061B280;
extern char D_0061B298[];               /* the formatted text */

/* Set the character size to w by h; 8 by 8 when either is 0. */
void Moji_size_set(int w, int h);

/* The font character for c: c itself, except the codes 1..4, which map to
 * 0x7D, 0x60, 0x7C and 0x7B. */
int func_002E12D8(signed char c);

/* Draw str from (x, y), one 8x8 font cell per character, in color (below
 * 0x10: an index into the debug colour table) at depth 0xFFFF - depth;
 * '\n' goes to the next line. An index with bit 3 set keeps
 * func_0015DB30's default TEST (alpha and depth test); any other color
 * draws with the depth test alone. */
void func_002E0F18(char *str, int x, int y, unsigned int color, int depth);

#endif /* GODHAND_FILEBUF_H */

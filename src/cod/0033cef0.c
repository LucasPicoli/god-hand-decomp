/* cygnus-2.96 matched TU. */

/* cygnus-2.96 matched TU. */

typedef signed char  Sint8;
typedef signed short Sint16;
typedef signed int   Sint32;

typedef struct {
    Sint8  pad0[152];
    Sint16 f152;
    Sint16 f154;
    Sint16 f156;
} ADXB;

__attribute__((section(".text.func_0033CEF0")))
Sint32 func_0033CEF0(ADXB *b)
{
    Sint32 mode;
    Sint32 x;

    mode = b->f152;
    if (mode == 0) {
        return 16;
    }
    if (mode == 2) {
        x = b->f156;
        if (x == 2) {
            return 4;
        }
        if (x == 1) {
            return 8;
        }
        return 16;
    }
    if (mode == 1) {
        x = b->f156;
        if (x == 2) {
            return 4;
        }
        return 16;
    }
    return 16;
}

/* cygnus-2.96 matched TU. */

typedef signed char   Sint8;
typedef signed short  Sint16;
typedef unsigned short Uint16;
typedef signed int    Sint32;

__attribute__((section(".text.func_0033E818")))
Sint32 func_0033E818(Sint8 *buf, Sint32 size, Sint16 *out)
{
    Sint32 i;
    Sint32 pos;
    Sint32 code;

    pos = 0x7FFFFFFF;
    code = 128;
    size--;
    for (i = 0; i < size; i += 2) {
        if (*(Uint16 *)(buf + i) == code) {
            if (i < pos) {
                pos = i;
            }
            break;
        }
    }
    if (pos != 0x7FFFFFFF) {
        *out = pos;
        return 0;
    }
    *out = 0;
    return -1;
}

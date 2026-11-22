/* cygnus-2.96 matched TU. */

/* cygnus-2.96 matched TU. */

typedef signed char Sint8;
typedef signed int  Sint32;

typedef struct {
    Sint8  pad0[80];
    Sint32 f80;
    Sint32 f84;
    Sint32 f88;
    Sint32 f92;
} INF;

typedef struct {
    Sint8  pad0[168];
    void  *f168;
} SFX;

extern void SFX_GetTagInf(void *p, Sint32 *a, Sint32 *b);

__attribute__((section(".text.mwsfsfx_SetSfxInfTag")))
void mwsfsfx_SetSfxInfTag(SFX *sfx, Sint32 unused, INF *inf)
{
    Sint32 a;
    Sint32 b;

    SFX_GetTagInf(sfx->f168, &a, &b);
    inf->f80 = a;
    inf->f84 = b;
    inf->f88 = 0;
    inf->f92 = 0;
}

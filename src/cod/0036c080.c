/* cygnus-2.96: buffer setup (0x36C080). */

typedef struct BufSetupObj {
    char unk000[0x30];
    char *buf;                  /* 0x30 */
    char unk034[0x40 - 0x34];
    int f40;                    /* 0x40 */
    char unk044[0x110 - 0x44];
    int f110;                   /* 0x110 */
} BufSetupObj;

extern char *D_00766D38;
extern int D_003F1ABC;

__attribute__((section(".text.mpvlib_InitObj")))
void mpvlib_InitObj(BufSetupObj *o)
{
    o->buf = D_00766D38 + 0x1100;
    o->f40 = D_003F1ABC;
    o->f110 = D_003F1ABC;
}

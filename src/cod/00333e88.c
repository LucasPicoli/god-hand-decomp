/* cygnus-2.96 matched TU. */

extern char D_004544E0[];
extern void func_003A53A8(char *, char *);
extern unsigned int strlen(const char *);

typedef signed char    Sint8;
typedef short          Sint16;
typedef unsigned short Uint16;
typedef int            Sint32;
typedef unsigned char  Uint8;

#define SWP16(x) ((((x) >> 8) & 0xFF) | (((x) << 8) & ~0xFF))

__attribute__((section(".text.func_0033F050")))
Sint32 func_0033F050(Sint8 *ibuf, Sint32 ibuflen, Sint16 *dlen)
{
    if (ibuflen < 0x10) {
        return -1;
    }
    if ((Uint16)SWP16(*(Uint16 *)ibuf) != 0x8001) {
        return -2;
    }
    *dlen = (((Uint8 *)ibuf)[3] | ((*(Uint16 *)(ibuf + 2) << 8) & ~0xFF)) + 4;
    return 0;
}

extern char D_003D9DE0[];    /* dvg_ci_root_dir */




typedef struct {
    char b[2];
} Str2;

__attribute__((section(".text.func_00333E88")))
void func_00333E88(char *dirname)
{
    char c;

    if (dirname == 0) {
        D_003D9DE0[0] = 0;
        return;
    }
    if (dirname[0] != 0x2F && dirname[0] != 0x5C) {
        *(Str2 *)D_003D9DE0 = *(Str2 *)D_004544E0;
    } else {
        D_003D9DE0[0] = 0;
    }
    func_003A53A8(D_003D9DE0, dirname);
    c = dirname[strlen(dirname) - 1];
    if (c == 0x2F || c == 0x5C) {
        D_003D9DE0[strlen(D_003D9DE0) - 1] = 0;
    }
}

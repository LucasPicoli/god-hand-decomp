/* cygnus-2.96 matched TU. */

typedef signed char Sint8;
typedef unsigned char Uint8;
typedef short Sint16;
typedef unsigned short Uint16;
typedef int Sint32;
typedef unsigned int Uint32;

#define SWAP16(x)  ((((Uint16)(x)) >> 8) | ((((Uint16)(x)) << 8) & ~0xff))
#define SWAP16B(p) (((Uint8 *)(p))[1] | ((*(Uint16 *)(p) << 8) & ~0xff))

extern Sint32 ADX_DecodeInfoExVer(Sint8 *ibuf, Sint32 hdlen, Uint8 *ver, Uint8 *rev);

__attribute__((section(".text.func_0033EA98")))
Sint32 func_0033EA98(Sint8 *ibuf, Sint32 hdlen, Sint16 *idly0, Sint16 *idly1)
{
    Uint8 ver, rev;

    if (ADX_DecodeInfoExVer(ibuf, hdlen, &ver, &rev) != 0) return -1;
    if (ver >= 4) {
        if (hdlen < 32) return -1;
        if ((Uint16)SWAP16(*(Uint16 *)(ibuf + 0)) != 0x8000) return -2;
        if ((Sint16)SWAP16B(ibuf + 2) < 28) return -1;
        idly0[0] = SWAP16(*(Uint16 *)(ibuf + 24));
        idly1[0] = SWAP16(*(Uint16 *)(ibuf + 26));
        idly0[1] = SWAP16(*(Uint16 *)(ibuf + 28));
        idly1[1] = SWAP16(*(Uint16 *)(ibuf + 30));
    } else {
        idly1[1] = 0;
        idly0[1] = 0;
        idly1[0] = 0;
        idly0[0] = 0;
    }
    return 0;
}

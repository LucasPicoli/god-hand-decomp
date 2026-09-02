/* cygnus-2.96 matched TU. */

typedef signed char Sint8;
typedef unsigned char Uint8;
typedef short Sint16;
typedef unsigned short Uint16;
typedef int Sint32;
typedef unsigned int Uint32;

#define SWAP16(x) ((((Uint16)(x)) >> 8) | ((((Uint16)(x)) << 8) & ~0xff))
#define SWAP16B(p) (((Uint8 *)(p))[1] | ((*(Uint16 *)(p) << 8) & ~0xff))

__attribute__((section(".text.ADX_DecodeInfoExVer")))
Sint32 ADX_DecodeInfoExVer(Sint8 *ibuf, Sint32 hdlen, Uint8 *ver, Uint8 *rev)
{
    if (hdlen < 20) return -1;
    if ((Uint16)SWAP16(*(Uint16 *)(ibuf + 0)) != 0x8000) return -2;
    if ((Sint16)SWAP16B(ibuf + 2) < 16) return -1;
    *ver = ibuf[18];
    *rev = ibuf[19];
    return 0;
}

typedef signed char Sint8;
typedef unsigned char Uint8;
typedef short Sint16;
typedef unsigned short Uint16;
typedef int Sint32;
typedef unsigned int Uint32;

#define GB(p, i)  ((Uint8)(p)[i])
#define GET16(p)  (GB(p, 1) | (GB(p, 0) << 8))
#define GET32(p)  ((GB(p, 0) << 24) | (GB(p, 1) << 16) | (GB(p, 2) << 8) | GB(p, 3))

__attribute__((section(".text.func_0033E8A0")))
Sint32 func_0033E8A0(Sint8 *ibuf, Sint32 hdlen, Sint16 *dlen, Sint8 *code,
                      Sint8 *bps, Sint8 *blksize, Sint8 *nch, Sint32 *sfreq,
                      Sint32 *total_nsmpl, Sint32 *nsmpl_blk)
{
    if (hdlen < 16) return -1;
    if (GET16(ibuf) != 0x8000) return -2;
    *dlen = GET16(ibuf + 2) + 4;
    *code = ibuf[4];
    *blksize = ibuf[5];
    *bps = ibuf[6];
    *nch = ibuf[7];
    *sfreq = GET32(ibuf + 8);
    *total_nsmpl = GET32(ibuf + 12);
    if (*bps == 0) {
        *nsmpl_blk = 0;
    } else {
        *nsmpl_blk = (*blksize * 8 - 16) / *bps;
    }
    return 0;
}

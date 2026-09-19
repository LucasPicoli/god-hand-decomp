/* cygnus-2.96 matched TU. */

/* cygnus-2.96, -freorder-blocks dropped. Donor adx_dcd.o ADX_DecodeInfoExADPCM2. */
typedef signed char    Sint8;
typedef short          Sint16;
typedef unsigned short Uint16;
typedef int            Sint32;
typedef unsigned char  Uint8;

#define SWP16(x) ((((x) >> 8) & 0xFF) | (((x) << 8) & ~0xFF))

__attribute__((section(".text.ADX_DecodeInfoExADPCM2")))
Sint32 ADX_DecodeInfoExADPCM2(Sint8 *ibuf, Sint32 ibuflen, Sint16 *blksize)
{
    if (ibuflen < 0x12) {
        return -1;
    }
    if ((Uint16)SWP16(*(Uint16 *)ibuf) != 0x8000) {
        return -2;
    }
    if ((Sint16)(((Uint8 *)ibuf)[3] | ((*(Uint16 *)(ibuf + 2) << 8) & ~0xFF)) < 0xE) {
        return -1;
    }
    *blksize = (Sint16)SWP16(*(Uint16 *)(ibuf + 0x10));
    return 0;
}

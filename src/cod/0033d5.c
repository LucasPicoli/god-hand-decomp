/* cygnus-2.96 matched TU — CRI libadxe, recovered from recvx-decomp (CC0). */

typedef signed short Sint16;
typedef signed int   Sint32;
extern void memcpy2(Sint16 *dst, Sint16 *src, Sint32 n);  /* memcpy2 */

__attribute__((section(".text.ADXB_CopyExtraBufSte")))
void ADXB_CopyExtraBufSte(Sint16 *obuf, Sint32 obsize, Sint32 obdist, Sint32 nxsmpl) {
    memcpy2(obuf, &obuf[obsize], nxsmpl);
    memcpy2(&obuf[obdist], &obuf[obdist + obsize], nxsmpl);
}

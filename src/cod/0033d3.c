/* cygnus-2.96 matched TU — CRI libadxe, recovered from recvx-decomp (CC0). */

typedef signed short Sint16;
typedef signed int   Sint32;
typedef struct AdxDecPara {
    Sint16 *ibuf;        /* 0x00 */
    char _pad4[0x10];
    Sint16 *pcmbuf;      /* 0x14 */
    char _pad18[0x04];
    Sint32 pcmbdist;     /* 0x1C */
    Sint32 wpos;         /* 0x20 */
} AdxDecPara;
typedef struct ADXB_t {
    char _pad0[0x08];
    void *xpd;           /* 0x08 */
    char _padC[0x3C];
    AdxDecPara dp;       /* 0x48 */
} ADXB_t;
typedef ADXB_t *ADXB;
typedef void *ADXPD;
extern void ADXPD_EntrySte(ADXPD xpd, Sint16 *ibuf, Sint32 n, Sint16 *o1, Sint16 *o2); /* ADXPD_EntrySte */
extern void ADXPD_Start(ADXPD xpd);                                                  /* ADXPD_Start  */

__attribute__((section(".text.ADXB_EvokeExpandSte")))
void ADXB_EvokeExpandSte(ADXB adxb, Sint32 nblk) {
    AdxDecPara *dp;
    ADXPD xpd;
    Sint16 *obuf_l;
    dp = &adxb->dp;
    xpd = adxb->xpd;
    obuf_l = (Sint16 *)dp->pcmbuf;
    obuf_l += dp->wpos;
    ADXPD_EntrySte(xpd, dp->ibuf, nblk * 2, obuf_l, obuf_l + dp->pcmbdist);
    ADXPD_Start(xpd);
}

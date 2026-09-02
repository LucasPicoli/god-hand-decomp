/* cygnus-2.96 matched TU. */

typedef signed char Sint8;
typedef unsigned char Uint8;
typedef short Sint16;
typedef unsigned short Uint16;
typedef int Sint32;
typedef unsigned int Uint32;

typedef void *ADXPD;
typedef void *AHXSJD;

typedef struct _adx_dec_para {
    Sint8 *ibuf;
    Sint32 niblk;
    Sint32 nch;
    Sint32 blksize;
    Sint32 blknsmpl;
    Sint8 *pcmbuf;
    Sint32 pcmbsize;
    Sint32 pcmbdist;
    Sint32 wpos;
    Sint32 nroom;
    Sint32 lp_nsmpl;
    Sint32 ndecsmpl;
} AdxDecPara;

typedef struct _adx_intbuf {
    Sint16 used;
    Sint16 hdcdflag;
    Sint32 stat;
    ADXPD xpd;
    Sint8 code;
    Sint8 bps;
    Sint8 nch;
    Sint8 blklen;
    Sint32 blknsmpl;
    Sint32 sfreq;
    Sint32 total_nsmpl;
    Sint16 cof;
    Sint16 rsv1;
    Sint32 lp_ins_nsmpl;
    Sint16 nloop;
    Sint16 lp_type;
    Sint32 lp_spos;
    Sint32 lp_sofst;
    Sint32 lp_epos;
    Sint32 lp_eofst;
    Sint32 maxnch;
    Sint16 *pcmbuf;
    Sint32 pcmbsize;
    Sint32 pcmbdist;
    AdxDecPara dp;
    Sint32 (*getwrfunc)(void *, Sint32 *, Sint32 *, Sint32 *);
    void *getwrobj;
    void (*addwrfunc)(void *, Sint32, Sint32);
    void *addwrobj;
    Sint32 total_ndecsmpl;
    Sint32 curwpos;
    Sint32 ndecsmpl;
    Sint32 ndeclen;
    Sint16 fmttype;
    Sint16 rsv2;
    Sint16 cdctype;
    Sint16 k0;
    Sint16 km;
    Sint16 ka;
    AHXSJD sjdh;
    Sint32 ahxdecsmpl;
    Sint32 ahxsvrfreq;
} ADX_BASIC, *ADXB;



__attribute__((section(".text.func_0033DFA8")))
Sint32 func_0033DFA8(ADXB adxb, Sint8 *ibuf, Sint32 ibuflen)
{
    Sint16 dlen;

    adxb->hdcdflag = 1;
    if (func_0033DD78(ibuf, ibuflen, &dlen, &adxb->code, &adxb->bps, &adxb->blklen,
                      &adxb->nch, &adxb->sfreq, &adxb->total_nsmpl, &adxb->blknsmpl,
                      &adxb->cdctype) < 0) {
        return 0;
    }
    adxb->cof = 0;
    adxb->lp_eofst = 0;
    adxb->lp_epos = 0;
    adxb->lp_sofst = 0;
    adxb->lp_spos = 0;
    adxb->lp_ins_nsmpl = 0;
    adxb->lp_type = 0;
    adxb->nloop = 0;
    adxb->dp.nch = adxb->nch;
    adxb->dp.blksize = adxb->blklen;
    adxb->fmttype = 1;
    adxb->dp.blknsmpl = adxb->blknsmpl;
    adxb->dp.pcmbuf = (Sint8 *)adxb->pcmbuf;
    adxb->dp.pcmbsize = adxb->pcmbsize;
    adxb->dp.pcmbdist = adxb->pcmbdist;
    adxb->total_ndecsmpl = 0;
    adxb->curwpos = 0;
    return dlen;
}

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
    Sint16 cdctype;
    Sint16 k0;
    Sint16 km;
    Sint16 ka;
    AHXSJD sjdh;
    Sint32 ahxdecsmpl;
    Sint32 ahxsvrfreq;
} ADX_BASIC, *ADXB;

extern Sint32 Obj33F8_GetWord_C_FA68(ADXPD xpd);

__attribute__((section(".text.func_0033E220")))
void func_0033E220(ADXB adxb)
{
    AdxDecPara *dp;
    Sint16 *pcmbuf_l;
    Sint16 *pcmbuf_r;
    Uint8 *ibuf;
    Sint32 ndata;
    Sint32 i;

    dp = &adxb->dp;
    ibuf = (Uint8 *)dp->ibuf;
    if (adxb->stat == 1) {
        if (Obj33F8_GetWord_C_FA68(adxb->xpd) == 0) {
            adxb->getwrfunc(adxb->getwrobj, &dp->wpos, &dp->nroom, &dp->lp_nsmpl);
            ndata = dp->pcmbsize - dp->wpos;
            if (dp->nroom < ndata) ndata = dp->nroom;
            if (dp->niblk < ndata) ndata = dp->niblk;
            pcmbuf_l = (Sint16 *)dp->pcmbuf + dp->wpos;
            if (adxb->nch == 2) {
                pcmbuf_r = (Sint16 *)dp->pcmbuf + (dp->pcmbdist + dp->wpos);
                for (i = 0; i < ndata; i++) {
                    pcmbuf_l[i] = (ibuf[i * 2] + 0xff80) << 8;
                    pcmbuf_r[i] = (ibuf[i * 2 + 1] + 0xff80) << 8;
                }
            } else {
                for (i = 0; i < ndata; i++) {
                    pcmbuf_l[i] = (ibuf[i] + 0xff80) << 8;
                }
            }
            adxb->stat = 2;
            adxb->ndecsmpl = ndata;
            adxb->ndeclen = ndata * adxb->nch;
        }
    }
    if (adxb->stat == 2) {
        adxb->addwrfunc(adxb->addwrobj, adxb->ndeclen, adxb->ndecsmpl);
        adxb->stat = 3;
    }
}

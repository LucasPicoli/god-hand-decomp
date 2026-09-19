/* cygnus-2.96 matched TU. */

/* cygnus-2.96 */

typedef struct HdInf {
    int valid;      /* 0x00 */
    int ver;        /* 0x04 */
    int rev;        /* 0x08 */
    int rate;       /* 0x0C */
    int pad10[4];
    int sys[7];     /* 0x20 */
    int naud;       /* 0x3C */
    int nvid;       /* 0x40 */
    int nprv;       /* 0x44 */
    int nusr;       /* 0x48 */
    int aud[4];     /* 0x4C */
    int vid[1];     /* 0x5C */
} HdInf;

extern int SFH_IsSfdHeader(void *h, int *ok);


extern void sfhds_AnlyHead(void *h, HdInf *inf);
extern void sfhds_AnlySys(void *h, int *sys);
extern int sfhds_AnlyUsedStmid(void *h, int lo, int hi);
extern void sfhds_AnlyAudio(void *h, int n, int *aud);
extern void sfhds_AnlyVideo(void *h, int n, int *vid);

__attribute__((section(".text.sfhds_DoProcessHdr")))
void sfhds_DoProcessHdr(void *h, HdInf *inf)
{
    int ok;
    int ver;
    int rev;
    int rate;
    int tv;

    if (SFH_IsSfdHeader(h, &ok) == 0) ok = 0;
    if (ok == 0) return;
    if (func_0035DB38(h, &ver, &rev) == 0) {
        ver = 0;
        rev = 0;
    }
    inf->ver = ver;
    inf->rev = rev;
    tv = ver * 100 + rev;
    if (func_0035DF78(h, &rate) == 0) rate = 0;
    if (tv < 0x6E) rate = -rate;
    inf->rate = rate;
    sfhds_AnlyHead(h, inf);
    sfhds_AnlySys(h, inf->sys);
    inf->naud = sfhds_AnlyUsedStmid(h, 0xBD, 0xBD);
    inf->nvid = sfhds_AnlyUsedStmid(h, 0xBF, 0xBF);
    inf->nprv = sfhds_AnlyUsedStmid(h, 0xC0, 0xDF);
    inf->nusr = sfhds_AnlyUsedStmid(h, 0xE0, 0xEF);
    sfhds_AnlyAudio(h, inf->nprv, inf->aud);
    sfhds_AnlyVideo(h, inf->nusr, inf->vid);
    inf->valid = 1;
}

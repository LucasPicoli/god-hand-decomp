/* cygnus-2.96 matched TU. */

/* cygnus-2.96, -freorder-blocks dropped. Donor aixsjd.o AIXSJD_GetPhMediaInf. */
typedef signed char Sint8;
typedef unsigned char Uint8;
typedef unsigned short Uint16;
typedef int Sint32;
typedef float Float32;

typedef struct { Sint8 nch; Sint32 sfreq; Sint32 pckt_nbyte; Sint32 pckt_nsmpl; } AIX_TRINF;
typedef struct { Sint32 ofst; Sint32 len; Sint32 nsmpl; Sint32 sfreq; } AIX_PHINF;
typedef struct { Uint16 phno; Uint16 nph; Uint16 lpsp; Uint16 lpep; } AIX_SNGINF;
typedef struct {
    Sint8 ver; Sint8 rev; Sint32 phalign; Float32 pkt_freq; Sint8 ntr;
    AIX_TRINF trinf[32]; Sint32 nph; AIX_PHINF phinf[32]; Sint32 nsng; AIX_SNGINF snginf[4];
} AIX_INF;
typedef struct {
    Sint8 used, stat, maxtr, pause_flag, lnksw, rsv1, rsv2, rsv3;
    Sint32 total_decode, pktno, phno, phnsmple, muxsmple;
    void *sji; void *sjo[32];
    AIX_INF aixinf;
} AIXSJD_OBJ;
typedef AIXSJD_OBJ *AIXSJD;

__attribute__((section(".text.func_0032F4F8")))
void func_0032F4F8(AIXSJD aixsjd, Sint32 phno, Sint32 *ofst, Sint32 *len)
{
    if (ofst != 0) {
        *ofst = aixsjd->aixinf.phinf[phno].ofst;
    }
    if (len != 0) {
        *len = aixsjd->aixinf.phinf[phno].len;
    }
}

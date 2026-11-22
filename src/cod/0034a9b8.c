/* cygnus-2.96 matched TU. */

/* cygnus-2.96 matched TU. */

typedef signed char Sint8;
typedef signed int  Sint32;

typedef struct {
    Sint8 *data;
    Sint32 len;
    Sint32 rsv[6];
} SJCK;

typedef struct {
    Sint8  pad0[8204];
    Sint32 f8204;
} SFD;



__attribute__((section(".text.sfadxt_RingGetRead")))
Sint32 sfadxt_RingGetRead(SFD *sfd, Sint8 **pdata, Sint32 *plen)
{
    SJCK ck;
    Sint32 r;

    r = SFBUF_RingGetRead(sfd, sfd->f8204, &ck);
    *pdata = ck.data;
    *plen = ck.len;
    return r;
}

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



__attribute__((section(".text.func_0034A9B8")))
Sint32 func_0034A9B8(SFD *sfd, Sint8 **pdata, Sint32 *plen)
{
    SJCK ck;
    Sint32 r;

    r = func_0034C2B8(sfd, sfd->f8204, &ck);
    *pdata = ck.data;
    *plen = ck.len;
    return r;
}

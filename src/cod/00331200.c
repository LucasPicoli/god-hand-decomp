/* cygnus-2.96 matched TU. */

typedef signed char Sint8;
typedef char Char8;
typedef int Sint32;
typedef unsigned int Uint32;
typedef unsigned long long Uint64;
typedef Sint32 Bool;
typedef unsigned char u_char;

typedef struct {
    u_char trycount;
    u_char spindlctrl;
    u_char datapattern;
    u_char pad;
} sceCdRMode;

typedef struct srd_obj {
    Sint8 used;
    Sint8 devtype;
    Sint8 stat;
    Char8 rsv;
    Sint32 break_flg;
    Uint32 d_lsn;
    Uint32 d_sct;
    void *d_buf;
    sceCdRMode d_mode;
    void *h_buf;
    Uint64 h_byte;
    Uint64 h_skpos;
    int h_fd;
    int err_code;
} SRD_OBJ, *SRD;

extern int Forward33B568_33B688(void);
extern int Forward33B5C8_33B6B8(void);

__attribute__((section(".text.SRD_ReqRdHst")))
Bool SRD_ReqRdHst(SRD srd, int h_fd, Sint32 h_skpos, Uint64 h_byte, void *h_buf)
{
    Bool ret;

    ret = 0;
    Forward33B568_33B688();
    if (srd->stat == 0 || srd->stat == 3 || srd->stat == 9) {
        srd->devtype = 2;
        srd->stat = 1;
        srd->h_fd = h_fd;
        srd->h_buf = h_buf;
        srd->h_byte = h_byte;
        srd->h_skpos = h_skpos;
        srd->break_flg = 0;
        ret = 1;
    }
    Forward33B5C8_33B6B8();
    return ret;
}

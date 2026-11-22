/* cygnus-2.96: mpsdec_DecOneHd, dispatches one decoded MPEG start-code unit by kind (sequence, picture or
 * user data); returns 1 for the two header kinds, 0 otherwise. */
typedef struct MpvHdrDec {
    char unk0[0x10];
    int arg10;                          /* 0x10 */
    char unk14[0x94];
    long udata;                         /* 0xA8 */
    char unkB0[8];
    unsigned char ukind;                /* 0xB8 */
    char unkB9[0x3B];
    void (*ucb)(int obj, int kind, long data);  /* 0xF4 */
    int uobj;                           /* 0xF8 */
} MpvHdrDec;

extern int MPS_CheckDelim(unsigned char *p);
extern void func_003670E8(MpvHdrDec *d, unsigned char *p, int *len);
extern void mpsdec_DecSysHd(MpvHdrDec *d, unsigned char *p, int *len);
extern void func_00367DC0(MpvHdrDec *d, unsigned char *p, int *len, int arg);

__attribute__((section(".text.mpsdec_DecOneHd")))
int mpsdec_DecOneHd(MpvHdrDec *d, unsigned char *p, int unused, int *len, int *kind)
{
    int ret;
    int k;

    *len = 0;
    k = MPS_CheckDelim(p);
    *kind = k;
    ret = 0;
    switch (k) {
    case 0x10000:
        ret = 1;
        func_003670E8(d, p, len);
        break;
    case 0x20000:
        ret = 1;
        mpsdec_DecSysHd(d, p, len);
        break;
    case 0x40000:
        func_00367DC0(d, p, len, d->arg10);
        if (d->ucb != 0)
            d->ucb(d->uobj, d->ukind, d->udata);
        break;
    }
    return ret;
}

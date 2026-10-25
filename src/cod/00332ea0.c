/* cygnus-2.96: CD file handle read request: clamp the sector count to what is left of the file, issue
 * SRD_ReqRdCd and, in blocking mode, wait for it and advance the offset. */
typedef struct CdReadHn {
    char pad00[2];
    signed char stat;                   /* 0x02 */
    char pad03[5];
    int fsize;                          /* 0x08 */
    int ofs;                            /* 0x0C */
    int rqsct;                          /* 0x10 */
    int rdsct;                          /* 0x14 */
    void *buf;                          /* 0x18 */
    void *srd;                          /* 0x1C */
    int top;                            /* 0x20 */
    char pad24[0x44 - 0x24];
    unsigned char mode[3];              /* 0x44 */
} CdReadHn;

extern char D_00454458[];
extern char D_00454470[];
extern char D_00454490[];
extern unsigned char D_003D9DD0[];
extern int D_003D9DD4;
extern void func_00332808(CdReadHn *hn, char *msg);
extern void *SRD_Create(void);
extern void func_003B0640(void *start, void *end);
extern int func_00331110(void *srd, int lsn, int nsct, void *buf, void *mode);
extern void func_00331070(void *srd);
extern int func_00398DA0(int mode);
extern void func_00331BF0(void);
extern void CdSrd_finishRead(void);
extern void func_00331458(void *srd);

#define MIN(a, b) ((a) < (b) ? (a) : (b))

__attribute__((section(".text.func_00332EA0")))
int func_00332EA0(CdReadHn *hn, int nsct, void *buf)
{
    void *srd;
    int ret;

    if (hn == 0) {
        func_00332808(hn, D_00454458);
        return 0;
    }
    if (nsct < 0) {
        func_00332808(hn, D_00454470);
        return 0;
    }
    if (buf == 0) {
        func_00332808(hn, D_00454490);
        return 0;
    }
    if (hn->stat == 2)
        return 0;
    if (nsct == 0) {
        hn->stat = 1;
        return 0;
    }
    srd = SRD_Create();
    hn->srd = srd;
    if (srd == 0)
        return 0;
    hn->mode[0] = D_003D9DD0[0];
    hn->mode[1] = D_003D9DD0[1];
    hn->mode[2] = D_003D9DD0[2];
    hn->buf = buf;
    hn->rqsct = MIN(nsct, hn->fsize - hn->ofs);
    func_003B0640(buf, (char *)buf + hn->rqsct * 2048 - 1);
    if (func_00331110(hn->srd, hn->top + hn->ofs, hn->rqsct, hn->buf, hn->mode) == 0) {
        func_00331070(hn->srd);
        return 0;
    }
    if (D_003D9DD4 == 1) {
        func_00398DA0(0);
        func_00331BF0();
        CdSrd_finishRead();
        func_00331458(hn->srd);
        func_00331070(hn->srd);
        hn->srd = 0;
        hn->rdsct = nsct;
        hn->stat = 1;
        ret = hn->rqsct;
        hn->ofs += ret;
    } else {
        hn->stat = 2;
        ret = hn->rqsct;
    }
    return ret;
}

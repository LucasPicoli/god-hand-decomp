/* cygnus-2.96: start a read request: wrap buf in a stream joint of nsct sectors, issue the read, and
 * destroy the joint again on failure. */
#include "godhand/criSj.h"
#include "godhand/globals.h"
typedef struct CdReadReq {
    char unk00;
    signed char stat;                   /* 0x01 2 = busy */
    char busy;                          /* 0x02 */
    char unk03[5];
    SjObj *sj;                       /* 0x08 */
    char unk0C[0x18];
    void *buf;                          /* 0x24 */
    int size;                           /* 0x28 */
} CdReadReq;

extern void adxf_SetCmdHstry(int id, int phase, CdReadReq *h, int nsct, void *buf);
extern int func_003395A0(int buf, int size, int mode);
extern void Forward33B658_33E678(void);
extern void Forward33B670_33E690(void);
extern void Forward3B0640_33F3D0(void *buf, int size);
extern int adxf_read_sj32(CdReadReq *h, int nsct, SjObj *sj);

__attribute__((section(".text.func_00323CF0")))
int func_00323CF0(CdReadReq *h, int nsct, void *buf)
{
    SjObj *sj;
    int size;
    int n;

    adxf_SetCmdHstry(4, 0, h, nsct, buf);
    if (h == 0) { func_0033F130(D_00451718); return -3; }
    if (nsct < 0) { func_0033F130(D_00451740); return -3; }
    if (buf == 0) { func_0033F130(D_00451770); return -3; }
    if (h->stat == 2)
        return 0;
    if (h->sj != 0) {
        func_0033F130(D_00451798);
        return -1;
    }
    size = nsct << 11;
    sj = (SjObj *)func_003395A0((int)buf, size, 0);
    if (sj == 0)
        return -2;
    Forward33B658_33E678();
    h->buf = buf;
    h->sj = sj;
    h->size = size;
    if (D_003EB708 == 1)
        Forward3B0640_33F3D0(buf, size);
    Forward33B670_33E690();
    n = adxf_read_sj32(h, nsct, h->sj);
    if (n <= 0) {
        Forward33B658_33E678();
        if (h->sj != 0) {
            h->sj->vt->destroy(h->sj);
            h->sj = 0;
        }
        Forward33B670_33E690();
    }
    h->busy = 0;
    adxf_SetCmdHstry(4, 1, h, nsct, buf);
    return n;
}

/* cygnus-2.96: func_003447A8, Sofdec header analysis: clears the header info, then (in the standby
 * state) reads the stream header and fills the info block; returns 1 on success, 0 otherwise. */
#include "godhand/mwsfd.h"
#include "godhand/globals.h"
typedef struct SfdHdrInf {
    int stat;           /* 0x00 */
    int size;           /* 0x04 */
    char unk8[0x28];
    int ftype;          /* 0x30 */
    char unk34[0x5C];
} SfdHdrInf;         /* 0x90 */

extern void *func_003A52F0(void *p, int c, int n);
extern int GetField0OrZero_346828(MwsfdHn *m);
extern void func_003448B0(MwsfdHn *m, int stat);
extern void *func_003466F8(MwsfdHn *m);
extern int func_00359080(void *buf, int *size, int *hdrsize);
extern void func_00344D50(MwsfdHn *m, int hdrsize);
extern void func_00344948(MwsfdHn *m, int hdrsize, SfdHdrInf *inf);
extern void func_003448F8(MwsfdHn *m, SfdHdrInf *inf);

__attribute__((section(".text.func_003447A8")))
int func_003447A8(MwsfdHn *m, int *size, SfdHdrInf *inf)
{
    int hdrsize;
    int stat;
    void *buf;
    int ret;

    func_003A52F0(inf, 0, sizeof(SfdHdrInf));
    inf->stat = 0;
    inf->size = -1;
    *size = -1;
    stat = GetField0OrZero_346828(m);
    if (stat != 1) {
        MWSFSVM_Error(D_004577D0);
        return 0;
    }
    func_003448B0(m, 2);
    buf = func_003466F8(m);
    if (buf == 0)
        return 0;
    ret = func_00359080(buf, size, &hdrsize);
    if (ret != stat)
        return ret;
    m->hdrSize = hdrsize;
    func_00344D50(m, hdrsize);
    func_00344948(m, hdrsize, inf);
    inf->size = *size;
    m->fileType = inf->ftype;
    func_003448F8(m, inf);
    return 1;
}

/* cygnus-2.96 matched TU. */
#include "godhand/mwsfd.h"

extern int Forward33BBD8_348C78();
extern void MWSST_Stop(MwsfdSlot *slot);
extern void MWSST_DestroyCoreHn(int a0, int a1);
extern void MWSST_Finish(int a0);

__attribute__((section(".text.MWSST_GetStat")))
int MWSST_GetStat(void *a0) {
    void *obj;
    void *arg;
    int (*f)(void *);
    int ret = 0;
    if (MWSST_IsEnable(a0) != 1) return 0;
    obj = *(void **)((char *)a0 + 0x8);
    arg = *(void **)((char *)a0 + 0x1C);
    if (obj != 0) {
        f = *(int (**)(void *))((char *)obj + 0x1C);
        if (f != 0) {
            ret = f(arg);
        }
    }
    return ret;
}

__attribute__((section(".text.MWSST_Destroy")))
void MWSST_Destroy(int *a0) {
    int arg;
    int s3v;
    int *s2v;
    int *obj;
    void (*method)(void *);
    if (MWSST_IsEnable(a0) != 1) return;
    arg = a0[7];
    s3v = a0[1];
    s2v = (int *)a0[5];
    if (arg == 0) return;
    Forward33BBD8_348C78();
    MWSST_Stop(a0);
    a0[0] = 0;
    MWSST_DestroyCoreHn(s3v, arg);
    obj = (int *)s2v[0];
    method = *(void (**)(void *))((char *)obj + 0xC);
    method(s2v);
    a0[7] = 0;
    MWSST_Finish(s3v);
}

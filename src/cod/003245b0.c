/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern void Forward33E6A8_324880(void);
extern int Forward33E6B0_324898(void);
extern void MWSST_SetIfTbl(void *a0, int a1);
extern void Forward345EE0_345EC8(int a0);

/* MATCH via cygnus-2.96. */




__attribute__((section(".text.ADXF_GetFnameRangeEx")))
int ADXF_GetFnameRangeEx(int a0, int a1, int a2, int a3, int t0, int t1)
{
    int local[4];
    int r;
    Forward33E6A8_324880();
    r = adxf_GetFnameRangeEx(a0, a1, a2, a3, t0, t1, local);
    Forward33E6B0_324898();
    return r;
}

/* MATCH via cygnus-2.96. */





__attribute__((section(".text.mwPlyAttachAdx")))
int mwPlyAttachAdx(int a0, int a1, int a2, int a3)
{
    MWSST_SetIfTbl(&D_003EC668, 0);
    Forward345EE0_345EC8(a0);
    return MWSST_Create(a0, 0, a1, a2, a3);
}

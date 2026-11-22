/* cygnus-2.96 matched TU. */

extern int D_00758400;
extern int DTX_CallUrpc(int, int *, int, int, int);
extern void Forward33B658_3389F8(void);
extern void Forward33B670_338A10(void);

__attribute__((section(".text.SJRMT_Destroy")))
void SJRMT_Destroy(int a0) {
    D_00758400 = a0;
    DTX_CallUrpc(0x23, &D_00758400, 1, 0, 0);
}

__attribute__((section(".text.DTR_Destroy")))
void DTR_Destroy(int a0) {
    Forward33B658_3389F8();
    *(char *)a0 = 0;
    Forward33B670_338A10();
}

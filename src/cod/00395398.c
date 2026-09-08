/* ee-2.9-991111 matched TU. */

typedef unsigned long u_long;

typedef struct {
    short sceGsInterMode;   /* 0x00 */
    short sceGsOutMode;     /* 0x02 */
    short sceGsFFMode;      /* 0x04 */
    short sceGsVersion;     /* 0x06 */
    int  (*sceGsVSCfunc)(int);  /* 0x08 */
    int   sceGsVSCid;       /* 0x0C */
} sceGsGParam;

extern sceGsGParam *GetD003F8560_395388(void);
extern void VSync(void);
extern long VSync2(void);

__attribute__((section(".text.sceGsSyncV")))
int sceGsSyncV(int mode)
{
    sceGsGParam *gp;

    gp = GetD003F8560_395388();
    if (gp->sceGsVSCfunc == 0) {
        u_long csr0;
        VSync();
        if (gp->sceGsInterMode != 1) {
            return 1;
        }
        csr0 = (*(volatile u_long *)0x12001000 >> 13) & 1;
        return (int)csr0;
    } else {
        long csr1;
        csr1 = (VSync2() >> 13) & 1;
        if (gp->sceGsInterMode != 1) {
            return 1;
        }
        return (int)csr1;
    }
}

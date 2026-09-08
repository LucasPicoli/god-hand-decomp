/* ee-2.9-991111 matched TU. */

typedef unsigned short u_short;
typedef unsigned long  u_long;

typedef struct {
    short sceGsInterMode;      /* 0x00 */
    short sceGsOutMode;        /* 0x02 */
    short sceGsFFMode;         /* 0x04 */
    short sceGsVersion;        /* 0x06 */
    int  (*sceGsVSCfunc)(int); /* 0x08 */
    int   sceGsVSCid;          /* 0x0C */
} sceGsGParam;

extern sceGsGParam *GetD003F8560_395388(void);
extern u_long GsPutIMR(u_long imr);
extern int RemoveIntcHandler(int cause, int id);
extern int SetGsCrt(short inter, short omode, short ffmode);


__attribute__((section(".text.sceGsResetGraph")))
void sceGsResetGraph(short mode, short inter, short omode, short ffmode)
{
    sceGsGParam *gp;
    u_short ver;

    switch (mode) {
    case 0:
        gp = GetD003F8560_395388();
        *(volatile u_long *)0x12001000 = 0x200;
        gp->sceGsInterMode = inter;
        gp->sceGsOutMode = omode;
        ver = (u_short)((*(volatile u_long *)0x12001000 >> 16) & 0xFF);
        gp->sceGsVersion = ver;
        GsPutIMR(0xFF00);
        gp->sceGsFFMode = (ffmode != 0);
        if (gp->sceGsVSCfunc != 0) {
            func_003B06D8(2);
            RemoveIntcHandler(2, gp->sceGsVSCid);
            gp->sceGsVSCfunc = 0;
            gp->sceGsVSCid = 0;
        }
        SetGsCrt(inter & 1, omode & 0xFF, ffmode & 1);
        break;
    case 1:
        *(volatile u_long *)0x12001000 = 0x100;
        break;
    case 5:
        gp = GetD003F8560_395388();
        gp->sceGsFFMode = (ffmode != 0);
        gp->sceGsInterMode = inter;
        gp->sceGsOutMode = omode;
        ver = (u_short)((*(volatile u_long *)0x12001000 >> 16) & 0xFF);
        gp->sceGsVersion = ver;
        SetGsCrt(inter & 1, omode & 0xFF, ffmode & 1);
        break;
    }
}

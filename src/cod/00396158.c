/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

#include <godhand/sync.h>

typedef unsigned int  u_int;
typedef unsigned long u_long;
typedef int u_long128 __attribute__((mode(TI)));

typedef struct {
    u_long NLOOP:15;
    u_long EOP:1;
    u_long pad16:16;
    u_long ID:14;
    u_long PRE:1;
    u_long PRIM:11;
    u_long FLG:2;
    u_long NREG:4;
    u_long REGS0:4;
    u_long REGS1:4;
    u_long REGS2:4;
    u_long REGS3:4;
    u_long REGS4:4;
    u_long REGS5:4;
    u_long REGS6:4;
    u_long REGS7:4;
    u_long REGS8:4;
    u_long REGS9:4;
    u_long REGS10:4;
    u_long REGS11:4;
    u_long REGS12:4;
    u_long REGS13:4;
    u_long REGS14:4;
    u_long REGS15:4;
} sceGifTag;

typedef struct {
    u_long FBP:9;
    u_long FBW:6;
    u_long PSM:5;
    u_long pad20:12;
    u_long DBX:11;
    u_long pad43:5;
    u_long DBY:11;
    u_long pad59:5;
} sceGsDispFb;

typedef struct {
    u_long      pmode;
    u_long      smode2;
    sceGsDispFb dispfb;
    u_long      display;
    u_long      bgcolor;
} sceGsDispEnv;

typedef struct {
    u_long FBP:9;
    u_long FBW:6;
    u_long pad15:1;
    u_long PSM:6;
    u_long pad22:10;
    u_long FBMSK:32;
} sceGsFrame;

typedef struct {
    sceGsFrame frame;
    u_long     frameaddr;
    u_long     rest[14];
} sceGsDrawEnv;

typedef struct { u_long r[12]; } sceGsClear;

typedef struct {
    sceGsDispEnv disp[2];
    sceGifTag    giftag0;
    sceGsDrawEnv draw1;
    sceGsDrawEnv draw2;
    sceGsClear   clear;
    sceGifTag    giftag1;
    sceGsDrawEnv draw1b;
    sceGsDrawEnv draw2b;
    sceGsClear   clearb;
} sceGsDBuffDc;

typedef struct {
    short sceGsInterMode;
    short sceGsOutMode;
    short sceGsFFMode;
    short sceGsVersion;
    int  (*sceGsVSCfunc)(int);
    int   sceGsVSCid;
} __attribute__((aligned(8))) sceGsGParam;

extern sceGsGParam *GetD003F8560_395388(void);
extern short sceGszbufaddr(short psm, short w, short h);
extern int sceGsSetDefDispEnv(sceGsDispEnv *disp, short psm, short w, short h,
                              short dx, short dy);

extern int sceGsSetDefDrawEnv2(sceGsDrawEnv *draw, short psm, short w, short h,
                               short ztest, short zpsm);
extern int sceGsSetDefClear(sceGsClear *cp, short ztest, short x, short y,
                            short w, short h, unsigned char r, unsigned char g,
                            unsigned char b, unsigned char a, u_int z);

__attribute__((section(".text.func_00396158")))
void func_00396158(sceGsDBuffDc *db, short psm, short w, short h,
                  short ztest, short zpsm, short clear)
{
    sceGsGParam *gp;
    short x;
    short y;
    int zbp;

    gp = GetD003F8560_395388();
    sceGsSetDefDispEnv(&db->disp[0], psm, w, h, 0, 0);
    sceGsSetDefDispEnv(&db->disp[1], psm, w, h, 0, 0);
    func_00396A70(&db->draw1, psm, w, h, ztest, zpsm);
    sceGsSetDefDrawEnv2(&db->draw2, psm, w, h, ztest, zpsm);
    func_00396A70(&db->draw1b, psm, w, h, ztest, zpsm);
    sceGsSetDefDrawEnv2(&db->draw2b, psm, w, h, ztest, zpsm);
    if (clear != 0) {
        x = 2048 - (w >> 1);
        y = 2048 - (h >> 1);
        sceGsSetDefClear(&db->clear, ztest, x, y, w, h, 0, 0, 0, 0, 0);
        sceGsSetDefClear(&db->clearb, ztest, x, y, w, h, 0, 0, 0, 0, 0);
    }
    *(u_long128 *)&db->giftag0 = 0;
    *(u_long128 *)&db->giftag1 = 0;
    db->giftag0.NLOOP = clear ? 0x16 : 0x10;
    db->giftag0.EOP   = 1;
    db->giftag0.NREG  = 1;
    db->giftag0.REGS0 = 0xE;
    db->giftag1.NLOOP = clear ? 0x16 : 0x10;
    db->giftag1.EOP   = 1;
    db->giftag1.NREG  = 1;
    db->giftag1.REGS0 = 0xE;
    zbp = sceGszbufaddr(psm, w, h);
    if (gp->sceGsInterMode == 1 && gp->sceGsFFMode == 1)
        goto adjust;
    if (gp->sceGsInterMode != 0)
        return;
adjust:
    {
        short fbp;
        int   fb;

        fb = zbp >> 1;
        fbp = fb;
        db->disp[1].dispfb.FBP = fbp;
        db->draw1.frame.FBP = fb;
        db->draw2.frame.FBP = fb;
    }
}

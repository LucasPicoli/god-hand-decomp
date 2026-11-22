/* cygnus-2.96 matched TU. */

extern int SFH_AnlyNumElemTot();
extern int SFH_AnlyNumElemAud();
extern int SFH_AnlyNumElemVid();
extern int SFH_AnlyNumElemPrv();
extern int SFH_AnlyMaxPlyLenAud();
extern int SFH_AnlyMaxPlyLenVid();
extern int SFH_AnlyMaxFrmNum();
extern int sfhds_CallN(void *h, int (*f)());
extern void SFTRN_CallTrtTrif(void *h, int a, int b, int c, int d);
extern void *Obj35C0_IsIndexedSet_1F3C_C380(void *h, int n);

typedef struct R { int f0; int f4; int f8; int fC; int f10; int f14; int f18; } R;










__attribute__((section(".text.sfhds_AnlySys")))
void sfhds_AnlySys(void *h, R *r)
{
    r->f0 = sfhds_CallN(h, SFH_AnlyNumElemTot);
    r->f4 = sfhds_CallN(h, SFH_AnlyNumElemAud);
    r->f8 = sfhds_CallN(h, SFH_AnlyNumElemVid);
    r->fC = sfhds_CallN(h, SFH_AnlyNumElemPrv);
    r->f10 = sfhds_CallN(h, SFH_AnlyMaxPlyLenAud);
    r->f14 = sfhds_CallN(h, SFH_AnlyMaxPlyLenVid);
    r->f18 = sfhds_CallN(h, SFH_AnlyMaxFrmNum);
}

__attribute__((section(".text.sfpl2_TrPause")))
void sfpl2_TrPause(void *h, int n)
{
    SFTRN_CallTrtTrif(h, 7, 8, n, 0);
    do { } while (0);
}

__attribute__((section(".text.sfply_TrStart")))
void sfply_TrStart(void *h)
{
    SFTRN_CallTrtTrif(h, 7, 6, 0, 0);
    do { } while (0);
}

__attribute__((section(".text.sfsee_IsMpsStream")))
int sfsee_IsMpsStream(void *h)
{
    return Obj35C0_IsIndexedSet_1F3C_C380(h, 1) != 0;
}

/* ee-2.9-991111 matched TU. */

extern int  sceSifCheckStatRpc(void *cd);
extern void _sceCd_Poff_Intr(void *a, void *b);
extern int SignalSema(int sema);
extern int DeleteSema(int sema);
extern int iSignalSema(int sema);
extern char D_0045E1A8[];
extern char D_0045E1B8[];
extern char D_0045E1C8[];
extern char D_0045E1D8[];
extern int CreateSema(struct SemaParam *p);

/* ee-2.9-991111 — SCE libcdvd 3.0.2, cdvd000.o :: sceCdSyncS */

extern char D_003FA1C0;      /* _sceCd_cd_scmd (sceSifClientData; pass &) */
extern int  D_003F8640[];    /* D_003F8640[4] == SCE_CD_debug */
extern char D_0045E2B0[];    /* the scePrintf format string */

extern void func_003B1F28(const char *fmt);      /* scePrintf */
extern void DelayThread(int usec);             /* DelayThread */


__attribute__((section(".text.sceCdSyncS")))
int sceCdSyncS(int mode)
{
    if (mode == 0) {
        if (D_003F8640[4] > 0)
            func_003B1F28(D_0045E2B0);
        while (sceSifCheckStatRpc(&D_003FA1C0))
            DelayThread(4000);
        return 0;
    }
    return sceSifCheckStatRpc(&D_003FA1C0);
}

/* ee-2.9-991111 — SCE libcdvd 3.0.2, cdvd000.o :: sceCdSync */

extern char D_003F9810;      /* _sceCd_cd_ncmd (sceSifClientData; pass &) */
extern int  D_003F8674;      /* _sceCd_ncmd_num */
extern int  D_003F8640[];    /* D_003F8640[4] == SCE_CD_debug */
extern char D_0045E2A0[];    /* the scePrintf format string */

extern void func_003B1F28(const char *fmt);      /* scePrintf */
extern void DelayThread(int usec);             /* DelayThread */


__attribute__((section(".text.func_00398DA0")))
int func_00398DA0(int mode)
{
    if (mode == 0) {
        if (D_003F8640[4] > 0)
            func_003B1F28(D_0045E2A0);
        while (D_003F8674 || sceSifCheckStatRpc(&D_003F9810))
            DelayThread(4000);
        return 0;
    }
    if (D_003F8674 || sceSifCheckStatRpc(&D_003F9810))
        return 1;
    return 0;
}

/* ee-2.9-991111 — SCE libcdvd 3.0.2, cdvd000.o :: PowerOffCB */

extern int D_003F8664;       /* the interrupt-lock flag */
extern int D_003F8688;       /* the power-off-callback-installed flag */


extern int  func_003B63A0(void);                       /* DIntr */
extern int  EIntr(void);                       /* EIntr */
extern int  func_003B2488(int fid, void (*fn)(void *, void *), void *data); /* sceSifAddCmdHandler */

__attribute__((section(".text.PowerOffCB")))
int PowerOffCB(void)
{
    int oldstat;

    D_003F8664 = 1;
    oldstat = func_003B63A0();
    func_003B2488(0x80000012, _sceCd_Poff_Intr, 0);
    if (oldstat)
        EIntr();
    D_003F8664 = 0;
    D_003F8688 = 1;
    return 1;
}

/* ee-2.9-991111 — SCE libcdvd 3.0.2, cdvd000.o :: cdvd_exit */

extern volatile int D_003F8654;       /* the "library is initialised" flag */
extern volatile int D_003F86A0;       /* sceCdCbfunc_num */
extern int D_003F8660;       /* the callback semaphore id */
extern int D_003F8668;       /* _sceCd_ncmd_semid */
extern int D_003F866C;       /* _sceCd_scmd_semid */
extern int D_003F8670;       /* the third semaphore id */



extern int func_003B63A0(void);          /* DIntr */
extern int EIntr(void);          /* EIntr */
extern int func_003B2500(int fid);       /* sceSifRemoveCmdHandler */

__attribute__((section(".text.cdvd_exit")))
void cdvd_exit(void)
{
    int oldstat;

    if (D_003F8654) {
        D_003F86A0 = -1;
        SignalSema(*(volatile int *)&D_003F8660);
    }
    DeleteSema(D_003F8668);
    DeleteSema(D_003F866C);
    DeleteSema(D_003F8670);
    DeleteSema(D_003F8660);
    oldstat = func_003B63A0();
    func_003B2500(0x80000012);
    if (oldstat)
        EIntr();
}

/* ee-2.9-991111 — SCE libcdvd 3.0.2, cdvd000.o :: _sceCd_cd_callback */

extern volatile int D_003F86A0;   /* sceCdCbfunc_num */
extern volatile int D_003F86A4;            /* the last callback reason */
extern volatile int D_003F8674;            /* _sceCd_ncmd_num */
extern volatile int D_003F8668;            /* _sceCd_ncmd_semid */
extern int D_003F8654;            /* the "callback thread live" flag */
extern int D_0077C3C0;            /* the user callback function pointer */
extern volatile int D_003F8660;            /* the callback semaphore id */



__attribute__((section(".text.func_003984D8")))
void func_003984D8(int *arg)
{
    D_003F86A0 = arg[0];
    D_003F86A4 = D_003F86A0;
    if (D_003F86A0 == 11) {
        D_003F86A0 = 0;
        D_003F8674 = 0;
        return;
    }
    iSignalSema(D_003F8668);
    if (D_003F8654 && D_0077C3C0)
        iSignalSema(D_003F8660);
    else
        D_003F8674 = 0;
    D_003F86A0 = 0;
}

/* ee-2.9-991111 — SCE libcdvd 3.0.2, cdvd000.o :: cmd_sem_init */

struct SemaParam {
    int    currentCount;
    int    maxCount;
    int    initCount;
    int    numWaitThreads;
    unsigned int attr;
    unsigned int option;
};

extern volatile int D_003F8668;      /* _sceCd_ncmd_semid */
extern volatile int D_003F866C;      /* _sceCd_scmd_semid */
extern volatile int D_003F8670;      /* the third semaphore id */
extern volatile int D_003F8660;      /* the fourth semaphore id */
extern volatile int D_003F8674;      /* _sceCd_ncmd_num */







__attribute__((section(".text.cmd_sem_init")))
void cmd_sem_init(void)
{
    struct SemaParam sp;

    if (D_003F8668 == -1 || D_003F866C == -1 || D_003F8670 == -1) {
        sp.option = (unsigned int)D_0045E1A8;
        sp.initCount = 1;
        sp.maxCount = 1;
        D_003F8668 = CreateSema(&sp);
        sp.option = (unsigned int)D_0045E1B8;
        D_003F866C = CreateSema(&sp);
        sp.option = (unsigned int)D_0045E1C8;
        D_003F8670 = CreateSema(&sp);
        sp.option = (unsigned int)D_0045E1D8;
        sp.initCount = 0;
        D_003F8660 = CreateSema(&sp);
        D_003F8674 = 0;
    }
}

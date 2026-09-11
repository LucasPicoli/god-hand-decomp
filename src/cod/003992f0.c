/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — SCE libcdvd 3.0.2, cdvd000.o :: sceCdDiskReady_old */

typedef unsigned int u_int;

extern char D_003F8640[];        /* D_003F8640+0x10 == SCE_CD_debug */
extern int  D_003F8680;
extern int  D_003F8690;          /* "scmd rpc not bound" flag */
extern volatile int D_003F866C;          /* _sceCd_scmd_semid */
extern int  D_0077C610[];        /* sceSifClientData */
extern int  D_0077C650[];        /* send buffer */
extern int  D_003F9840[];        /* _sceCd_scmdrdata */
extern char D_0045E330[];
extern char D_0045E348[];
extern char D_0045E368[];

extern void func_003B1F28();                    /* scePrintf */
extern int  func_003B63A0(void);                /* DIntr */
extern void EIntr(void);                /* EIntr */
extern void cmd_sem_init(void);
extern int  PollSema(int sema);
extern int  SignalSema(int sema);
extern int  sceCdSyncS(int mode);
extern void sceSifInitRpc(int mode);
extern int  func_003B2F48(void *cd, unsigned int sid, int mode);   /* sceSifBindRpc */
extern void func_003B2850(void *p, int size);   /* sceSifWriteBackDCache */


__attribute__((section(".text.sceCdDiskReady_old")))
int sceCdDiskReady_old(int mode)
{
    int i;
    int r;
    int b;

    if (*(int *)(D_003F8640 + 0x10) > 0)
        func_003B1F28(D_0045E330);
    i = func_003B63A0();
    D_003F8680 = 1;
    if (i)
        EIntr();
    cmd_sem_init();
    r = PollSema(D_003F866C);
    if (D_003F866C != r)
        return 6;
    if (sceCdSyncS(1)) {
        SignalSema(D_003F866C);
        return (mode != 8) ? 6 : -1;
    }
    do {
        sceSifInitRpc(0);
        b = D_003F8690;
    } while (0);
    if (b < 0) {
        while (1) {
            if (func_003B2F48(D_0077C610, 0x8000059A, 0) < 0) {
                if (*(int *)(D_003F8640 + 0x10) > 0)
                    func_003B1F28(D_0045E348);
                for (i = 0x100000; i != -1; i--)
                    ;
                continue;
            }
            if (D_0077C610[9] != 0)
                break;
            for (i = 0x100000; i != -1; i--)
                ;
        }
        D_003F8690 = 0;
    }
    D_0077C650[0] = mode;
    func_003B2850(D_0077C650, 4);
    if (func_003B3128(D_0077C610, 0, 0, D_0077C650, 4, D_003F9840, 4, 0, 0) < 0) {
        SignalSema(D_003F866C);
        return (mode != 8) ? 6 : -1;
    }
    if (*(int *)(D_003F8640 + 0x10) > 0)
        func_003B1F28(D_0045E368);
    r = *(int *)((u_int)D_003F9840 | 0x20000000);
    SignalSema(D_003F866C);
    return r;
}

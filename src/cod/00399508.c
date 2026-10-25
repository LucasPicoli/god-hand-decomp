/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111: sceCdDiskReady. Binds the scmd RPC client when it is not bound (retrying with a delay loop),
 * then sends the mode word and returns the reply, or 6 / -1 on failure. */

typedef unsigned int u_int;

extern char D_003F8640[];        /* D_003F8640+0x10 == SCE_CD_debug */
extern int  D_003F8680;
extern int  D_003F8690;          /* "scmd rpc not bound" flag */
extern volatile int D_003F8670;  /* _sceCd_dr_semid */
extern int  D_0077C610[];        /* sceSifClientData */
extern int  D_0077C650[];        /* send buffer */
extern int  D_003FA0C0[];        /* receive buffer */
extern char D_0045E348[];
extern char D_0045E368[];
extern char D_0045E380[];

extern void func_003B1F28();                    /* scePrintf */
extern int  func_003B63A0(void);                /* DIntr */
extern void EIntr(void);                /* EIntr */
extern void cmd_sem_init(void);
extern int  PollSema(int sema);
extern int  SignalSema(int sema);
extern void sceSifInitRpc(int mode);
extern int  sceCdDiskReady_old(int mode);            /* sceCdDiskReady_old */
extern int  func_003B2F48(void *cd, unsigned int sid, int mode);   /* sceSifBindRpc */
extern void func_003B2850(void *p, int size);   /* sceSifWriteBackDCache */


__attribute__((section(".text.func_00399508")))
int func_00399508(int mode)
{
    int i;
    int n;
    int r;
    int m;

    if (*(int *)(D_003F8640 + 0x10) > 0)
        func_003B1F28(D_0045E380);
    cmd_sem_init();
    r = PollSema(D_003F8670);
    if (D_003F8670 != r)
        return (mode != 8) ? 6 : -1;
    sceSifInitRpc(0);
    n = 0;
    if (D_003F8690 < 0) {
        D_003F8690++;   /* no-op pair: it moves the local allocation, see the record */
        D_003F8690--;
        while (1) {
            if (func_003B2F48(D_0077C610, 0x8000059C, 0) < 0) {
                if (*(int *)(D_003F8640 + 0x10) > 0)
                    func_003B1F28(D_0045E348);
                for (i = 0x100000; i != -1; i--)
                    ;
                continue;
            }
            if (D_0077C610[9] != 0)
                break;
            if (n >= 0x11) {
                SignalSema(D_003F8670);
                return sceCdDiskReady_old(mode);
            }
            m = n + 1;
            for (i = 0x100000; i != -1; i--)
                ;
            n = m;
        }
        D_003F8690 = 0;
    }
    i = func_003B63A0();
    D_003F8680 = 0;
    if (i)
        EIntr();
    D_0077C650[0] = mode;
    func_003B2850(D_0077C650, 4);
    if (func_003B3128(D_0077C610, 0, 0, D_0077C650, 4, D_003FA0C0, 4, 0, 0) < 0) {
        SignalSema(D_003F8670);
        return (mode != 8) ? 6 : -1;
    }
    if (*(int *)(D_003F8640 + 0x10) > 0)
        func_003B1F28(D_0045E368);
    r = *(int *)((u_int)D_003FA0C0 | 0x20000000);
    SignalSema(D_003F8670);
    return r;
}

/* ee-2.9-991111 matched TU. */

extern char D_0045E260[];
extern char D_0045E288[];
extern void cmd_sem_init(void);
extern int  PollSema(int sema);
extern int  SignalSema(int sema);
extern void sceSifInitRpc(int mode);
extern char D_0045E2C0[];
extern char D_0045E2E8[];

/* ee-2.9-991111 — SCE libcdvd 3.0.2, cdvd000.o :: _sceCd_ncmd_prechk */

extern volatile int D_003F8668;      /* _sceCd_ncmd_semid */
extern int  D_003F8640[];    /* D_003F8640[4] == SCE_CD_debug */
extern int  D_003F865C;      /* the pending ncmd */
extern int  D_003F867C;      /* the "ncmd rpc not bound" flag */
extern int  D_003F9810[];    /* _sceCd_cd_ncmd (sceSifClientData) */






extern void func_003B1F28();                /* scePrintf */
extern int  func_00398DA0(int mode);        /* sceCdSync */

extern int  func_003B2F48(void *cd, unsigned int sid, int mode);  /* sceSifBindRpc */

__attribute__((section(".text.func_00398BB0")))
int func_00398BB0(int cmd)
{
    int i;
    int r;

    cmd_sem_init();
    r = PollSema(D_003F8668);
    if (D_003F8668 != r) {
        if (D_003F8640[4] > 0)
            func_003B1F28(D_0045E260, cmd, D_003F865C);
        return 0;
    }
    D_003F865C = cmd;
    if (func_00398DA0(1)) {
        SignalSema(D_003F8668);
        return 0;
    }
    sceSifInitRpc(0);
    if (D_003F867C < 0) {
        while (1) {
            if (func_003B2F48(D_003F9810, 0x80000595, 0) < 0) {
                if (D_003F8640[4] > 0)
                    func_003B1F28(D_0045E288);
                for (i = 0x100000; i != -1; i--)
                    ;
                continue;
            }
            if (D_003F9810[9] != 0)
                break;
            for (i = 0x100000; i != -1; i--)
                ;
        }
        D_003F867C = 0;
    }
    return 1;
}

/* ee-2.9-991111 — SCE libcdvd 3.0.2, cdvd000.o :: _sceCd_scmd_prechk */

extern volatile int D_003F866C;      /* _sceCd_scmd_semid */
extern int  D_003F8640[];    /* D_003F8640[4] == SCE_CD_debug */
extern int  D_003F8658;      /* the pending ncmd */
extern int  D_003F8694;      /* the "ncmd rpc not bound" flag */
extern int  D_003FA1C0[];    /* _sceCd_cd_scmd (sceSifClientData) */






extern void func_003B1F28();                /* scePrintf */
extern int  sceCdSyncS(int mode);           /* sceCdSyncS */

extern int  func_003B2F48(void *cd, unsigned int sid, int mode);  /* sceSifBindRpc */

__attribute__((section(".text.func_00398EB0")))
int func_00398EB0(int cmd)
{
    int i;
    int r;

    cmd_sem_init();
    r = PollSema(D_003F866C);
    if (D_003F866C != r) {
        if (D_003F8640[4] > 0)
            func_003B1F28(D_0045E2C0, cmd, D_003F8658);
        return 0;
    }
    D_003F8658 = cmd;
    if (sceCdSyncS(1)) {
        SignalSema(D_003F866C);
        return 0;
    }
    sceSifInitRpc(0);
    if (D_003F8694 < 0) {
        while (1) {
            if (func_003B2F48(D_003FA1C0, 0x80000593, 0) < 0) {
                if (D_003F8640[4] > 0)
                    func_003B1F28(D_0045E2E8);
                for (i = 0x100000; i != -1; i--)
                    ;
                continue;
            }
            if (D_003FA1C0[9] != 0)
                break;
            for (i = 0x100000; i != -1; i--)
                ;
        }
        D_003F8694 = 0;
    }
    return 1;
}

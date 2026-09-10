/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — SCE libcdvd 3.0.2, cdvd018.o :: sceCdBreak */

typedef unsigned int u_int;

extern char D_003FA1C0;      /* _sceCd_cd_scmd (sceSifClientData; pass &) */
extern int  D_003F9840[];    /* _sceCd_scmdrdata */
extern volatile int D_003F866C;      /* _sceCd_scmd_semid */
extern volatile int D_003F86A0;      /* sceCdCbfunc_num */

extern int func_00398EB0(int cmd);   /* _sceCd_scmd_prechk */
extern int func_003B3128(void *cd, int rno, int mode, void *sbuf, int ssize,
                         void *rbuf, int rsize, void *efunc, void *epara); /* sceSifCallRpc */
extern int SignalSema(int sema);

__attribute__((section(".text.func_00399B20")))
int func_00399B20(void)
{
    int *rd;
    int r;

    if (!func_00398EB0(30))
        return 0;
    rd = D_003F9840;
    D_003F86A0 = 8;
    if (func_003B3128(&D_003FA1C0, 22, 0, 0, 0, rd, 4, 0, 0) < 0) {
        SignalSema(D_003F866C);
        D_003F86A0 = 0;
        return 0;
    }
    D_003F86A0 = 0;
    r = *(int *)((u_int)rd | 0x20000000);
    SignalSema(D_003F866C);
    return r;
}

/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — SCE libcdvd 3.0.2, cdvd036.o :: sceCdMmode */

typedef unsigned int u_int;

extern char D_003FA1C0;      /* _sceCd_cd_scmd (sceSifClientData; pass &) */
extern int  D_003F9840[];    /* _sceCd_scmdrdata */
extern int  D_003F9C80[];    /* _sceCd_scmdsdata */
extern int  D_003F866C;      /* _sceCd_scmd_semid */
extern int  D_003FA1E8;      /* rpc function number */
extern int  D_003FA1EC;      /* send size */
extern int  D_003FA1F0;      /* receive size */

extern int func_00398EB0(int cmd);   /* _sceCd_scmd_prechk */
extern void func_003B2850(void *p, int size);  /* sceSifWriteBackDCache */
extern int func_003B3128(void *cd, int rno, int mode, void *sbuf, int ssize,
                         void *rbuf, int rsize, void *efunc, void *epara); /* sceSifCallRpc */
extern int SignalSema(int sema);

__attribute__((section(".text.func_00399BD8")))
int func_00399BD8(int media)
{
    int *sd = D_003F9C80;

    int r;

    if (!func_00398EB0(0x22))
        return 0;
    D_003F9C80[0] = media;
    func_003B2850(sd, 4);

    if (func_003B3128(&D_003FA1C0, D_003FA1E8, 0, sd, D_003FA1EC,
                      D_003F9840, D_003FA1F0, 0, 0) < 0) {
        SignalSema(D_003F866C);
        return 0;
    }
    r = *(int *)((u_int)D_003F9840 | 0x20000000);
    SignalSema(D_003F866C);
    return r;
}

/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — SCE libcdvd 3.0.2, cdvd014.o :: sceCdGetDiskType2 */

typedef unsigned int u_int;

extern char D_003FA1C0;      /* _sceCd_cd_scmd (sceSifClientData; pass &) */
extern int  D_003F9840[];    /* _sceCd_scmdrdata */
extern int  D_003F866C;      /* _sceCd_scmd_semid */

extern int func_00398EB0(int cmd);   /* _sceCd_scmd_prechk */
extern int func_003B3128(void *cd, int rno, int mode, void *sbuf, int ssize,
                         void *rbuf, int rsize, void *efunc, void *epara); /* sceSifCallRpc */
extern int SignalSema(int sema);

__attribute__((section(".text.func_00399910")))
int func_00399910(void)
{
    int *rd;
    int r;

    if (!func_00398EB0(1))
        return -1;
    rd = D_003F9840;
    if (func_003B3128(&D_003FA1C0, 3, 0, 0, 0, rd, 4, 0, 0) < 0) {
        SignalSema(D_003F866C);
        return -1;
    }
    r = *(int *)((u_int)rd | 0x20000000);
    SignalSema(D_003F866C);
    return r;
}

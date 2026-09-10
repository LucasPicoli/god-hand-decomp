/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — SCE libcdvd 3.0.2, cdvd017.o :: sceCdStatus */

typedef unsigned int u_int;

extern char D_003FA1C0;      /* _sceCd_cd_scmd (sceSifClientData; pass &) */
extern int  D_003F9840[];    /* _sceCd_scmdrdata */
extern int  D_003F866C;      /* _sceCd_scmd_semid */
extern int  D_003F8640[];    /* D_003F8640[4] == SCE_CD_debug */
extern char D_0045E3C0[];    /* the scePrintf format string */

extern int func_00398EB0(int cmd);   /* _sceCd_scmd_prechk */
extern int func_003B3128(void *cd, int rno, int mode, void *sbuf, int ssize,
                         void *rbuf, int rsize, void *efunc, void *epara); /* sceSifCallRpc */
extern int SignalSema(int sema);
extern void func_003B1F28(const char *fmt);   /* scePrintf */

__attribute__((section(".text.func_00399A68")))
int func_00399A68(void)
{
    int *rd;
    int r;

    if (!func_00398EB0(2))
        return -1;
    rd = D_003F9840;
    if (func_003B3128(&D_003FA1C0, 12, 0, 0, 0, rd, 4, 0, 0) < 0) {
        SignalSema(D_003F866C);
        return -1;
    }
    r = *(int *)((u_int)rd | 0x20000000);
    SignalSema(D_003F866C);
    if (D_003F8640[4] >= 2)
        func_003B1F28(D_0045E3C0);
    return r;
}

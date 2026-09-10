/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — SCE libcdvd 3.0.2, cdvd039.o :: sceCdReadClock */

typedef unsigned int u_int;
typedef struct { char b[8]; } T8;

extern char D_003FA1C0;      /* _sceCd_cd_scmd (sceSifClientData; pass &) */
extern int  D_003F9840[];    /* _sceCd_scmdrdata */
extern int  D_003F866C;      /* _sceCd_scmd_semid */

extern int func_00398EB0(int cmd);   /* _sceCd_scmd_prechk */
extern int func_003B3128(void *cd, int rno, int mode, void *sbuf, int ssize,
                         void *rbuf, int rsize, void *efunc, void *epara); /* sceSifCallRpc */
extern int SignalSema(int sema);

__attribute__((section(".text.func_00399CB0")))
int func_00399CB0(void *rtc)
{
    int r;

    if (!func_00398EB0(15))
        return 0;
    if (func_003B3128(&D_003FA1C0, 1, 0, 0, 0, D_003F9840, 16, 0, 0) < 0) {
        SignalSema(D_003F866C);
        return 0;
    }
    *(T8 *)rtc = *(T8 *)((u_int)&D_003F9840[1] | 0x20000000);
    r = *(int *)((u_int)D_003F9840 | 0x20000000);
    SignalSema(D_003F866C);
    return r;
}

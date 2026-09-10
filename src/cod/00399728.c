/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — SCE libcdvd 3.0.2, cdvd005.o :: sceCdRead */

typedef unsigned int u_int;

struct ncmdr {
    u_int  lbn;             /* 0x00 */
    u_int  sectors;         /* 0x04 */
    void  *buf;             /* 0x08 */
    unsigned char trycount;     /* 0x0C */
    unsigned char spindlctrl;   /* 0x0D */
    unsigned char datapattern;  /* 0x0E */
    unsigned char pad;          /* 0x0F */
    void  *intr_data;       /* 0x10 */
    void  *cur_pos;         /* 0x14 */
};

struct rmode {
    unsigned char trycount;
    unsigned char spindlctrl;
    unsigned char datapattern;
    unsigned char pad;
};

extern struct ncmdr D_003F8740;   /* _sceCd_ncmdsdata */
extern volatile int D_003F8678;          /* _sceCd_ee_read_mode */
extern int   D_003F9800;          /* _sceCd_Read_cur_pos */
extern char  D_003F9740[];        /* _sceCd_rd_intr_data */
extern char  D_003F8640[];        /* D_003F8640+0x10 == SCE_CD_debug */
extern volatile int D_003F86A0;          /* sceCdCbfunc_num */
extern volatile int D_003F8674;          /* _sceCd_c_cb_sem */
extern char  D_003F9810[];        /* _sceCd_cd_ncmd */
extern volatile int D_003F8668;          /* _sceCd_ncmd_semid */
extern char  D_0045E398[];
extern char  D_0045E3B0[];
extern char  _sceCd_cd_read_intr[];

extern int  func_00398D08(void);            /* sceCdNcmdDiskReady */
extern int  func_00398BB0(int cmd);         /* _sceCd_ncmd_prechk */
extern void func_003B2850(void *p, int size);   /* sceSifWriteBackDCache */
extern void func_003B1F28();                /* scePrintf */

extern int  SignalSema(int sema);

__attribute__((section(".text.sceCdRead")))
int sceCdRead(u_int lbn, u_int sectors, void *buf, struct rmode *mode)
{
    struct ncmdr *p = &D_003F8740;
    int size;

    if (!(D_003F8678 & 1)) {
        if (func_00398D08() == 6)
            return 0;
    }
    if (!func_00398BB0(4))
        return 0;

    p->lbn = lbn;
    p->sectors = sectors;
    p->buf = buf;
    p->trycount = mode->trycount;
    p->spindlctrl = mode->spindlctrl;
    p->datapattern = mode->datapattern;
    p->intr_data = D_003F9740;
    p->cur_pos = &D_003F9800;

    switch (mode->datapattern) {
    case 1:
        size = sectors * 2328;
        break;
    case 2:
        size = sectors * 2340;
        break;
    case 0:
    default:
        size = sectors * 2048;
        break;
    }

    D_003F9800 = 0;
    if (!(D_003F8678 & 2))
        func_003B2850(buf, size);

    func_003B2850(D_003F9740, 144);
    func_003B2850(p, 24);
    func_003B2850(&D_003F9800, 4);
    if (*(int *)(D_003F8640 + 0x10) > 0)
        func_003B1F28(D_0045E398);

    D_003F86A0 = 1;
    D_003F8674 = 1;
    if (func_003B3128(D_003F9810, 1, 1, p, 0x18, 0, 0,
                      _sceCd_cd_read_intr + 8, D_003F9740) < 0) {
        D_003F86A0 = 0;
        D_003F8674 = 0;
        SignalSema(D_003F8668);
        return 0;
    }
    if (*(int *)(D_003F8640 + 0x10) > 0)
        func_003B1F28(D_0045E3B0);
    return 1;
}

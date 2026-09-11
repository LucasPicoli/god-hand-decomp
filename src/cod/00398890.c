/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — SCE libcdvd 3.0.2, cdvd000.o :: func_00398890 */

typedef struct { unsigned int lsn; unsigned int size; char name[0x1C]; } sceCdlFILE;
typedef struct { char b[0x24]; } fileblk;

struct sfdata {
    unsigned char file[0x24];   /* 0x000 */
    char          name[0x100];  /* 0x024 */
    void         *addr;         /* 0x124 */
    int           layer;        /* 0x128 */
};

extern volatile int D_003F8668;       /* _sceCd_ncmd_semid */
extern char  D_003F8640[];            /* +0x10 == SCE_CD_debug */
extern int   D_003F865C;              /* ncmd_sema_keep_cmd */
extern int   D_003F868C;              /* _sf_bind */
extern struct sfdata D_0077C440;      /* _sf_data */
extern char  D_0077C464[];            /* _sf_data.name */
extern int   D_0077C580[];            /* sfrdata */
extern int   D_0077C5C0[];            /* cdrdsf (sceSifClientData) */
extern char  D_0045E1F0[];
extern char  D_0045E210[];
extern char  D_0045E228[];
extern char  D_0045E238[];
extern char  D_0045E248[];

extern void cmd_sem_init(void);
extern int  PollSema(int sema);
extern int  SignalSema(int sema);
extern void sceSifInitRpc(int mode);
extern void func_003B1F28();          /* scePrintf */
extern int  func_00398DA0(int mode);  /* sceCdSync */
extern int  func_003B2F48(void *cd, unsigned int sid, int mode);  /* sceSifBindRpc */
extern void func_003B2850(void *p, int size);  /* sceSifWriteBackDCache */


__attribute__((section(".text.func_00398890")))
int func_00398890(sceCdlFILE *fp, const char *name, int layer)
{
    int i;
    int n;
    int r;
    int b;

    cmd_sem_init();
    r = PollSema(D_003F8668);
    if (D_003F8668 != r)
        return 0;
    D_003F865C = 1;
    if (func_00398DA0(1)) {
        SignalSema(D_003F8668);
        return 0;
    }
    do {
        sceSifInitRpc(0);
        b = D_003F868C;
    } while (0);
    if (b < 0) {
        while (1) {
            if (func_003B2F48(D_0077C5C0, 0x80000597, 0) < 0) {
                if (*(int *)(D_003F8640 + 0x10) > 0)
                    func_003B1F28(D_0045E1F0);
                for (i = 0x100000; i != -1; i--)
                    ;
                continue;
            }
            if (D_0077C5C0[9] != 0)
                break;
            for (i = 0x100000; i != -1; i--)
                ;
        }
        D_003F868C = 0;
    }
    for (n = 0; n < 0x100; n++) {
        if ((D_0077C440.name[n] = name[n]) == 0)
            break;
    }
    if (n == 0x100)
        D_0077C440.name[0xFF] = 0;
    if (*(int *)(D_003F8640 + 0x10) > 0)
        func_003B1F28(D_0045E210, D_0077C464);
    D_0077C440.layer = layer;
    D_0077C440.addr = &D_0077C440;
    func_003B2850(&D_0077C440, 0x12C);
    if (func_003B3128(D_0077C5C0, 0, 0, &D_0077C440, 0x12C, D_0077C580, 4, 0, 0) < 0) {
        SignalSema(D_003F8668);
        return 0;
    }
    *(fileblk *)fp = *(fileblk *)(((unsigned int)&D_0077C440) | 0x20000000);
    if (*(int *)(D_003F8640 + 0x10) > 0)
        func_003B1F28(D_0045E228, fp->name);
    if (*(int *)(D_003F8640 + 0x10) > 0)
        func_003B1F28(D_0045E238, fp->size);
    if (*(int *)(D_003F8640 + 0x10) > 0)
        func_003B1F28(D_0045E248, fp->lsn);
    r = *(int *)(((unsigned int)D_0077C580) | 0x20000000);
    SignalSema(D_003F8668);
    return r;
}

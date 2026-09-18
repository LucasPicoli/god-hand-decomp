/* ee-2.9-991111 matched TU. */

/* sceGsExecStoreImage - libgraph graphdev.c */

typedef unsigned char u_char;
typedef unsigned int  u_int;
typedef unsigned long u_long;
typedef int qword __attribute__((mode(TI)));

typedef struct {
    u_long SBP:14;
    u_long pad14:2;
    u_long SBW:6;
    u_long pad22:2;
    u_long SPSM:6;
    u_long pad30:2;
    u_long DBP:14;
    u_long pad46:2;
    u_long DBW:6;
    u_long pad54:2;
    u_long DPSM:6;
    u_long pad62:2;
} sceGsBitbltbuf;

typedef struct {
    u_long RRW:12;
    u_long pad12:20;
    u_long RRH:12;
    u_long pad44:20;
} sceGsTrxreg;

typedef struct {
    u_int          vifcode[4];
    u_long         giftag[2];
    sceGsBitbltbuf bitbltbuf;
    long           bitbltbufaddr;
    u_long         trxpos;
    long           trxposaddr;
    sceGsTrxreg    trxreg;
    long           trxregaddr;
    u_long         finish;
    long           finishaddr;
    u_long         trxdir;
    long           trxdiraddr;
} sceGsStoreImage;

extern void  func_003B1F28(char *fmt);
extern u_int GsGetIMR(void);
extern u_int GsPutIMR(u_int imr);
extern char  D_0045DD80[];
extern char  D_0045DDB8[];
extern char  D_0045DDE8[];
extern char  D_0045DE28[];
extern qword D_003F8570;


__attribute__((section(".text.sceGsExecStoreImage")))
int sceGsExecStoreImage(sceGsStoreImage *sp, qword *dstaddr)
{
    u_char buf[16] __attribute__((aligned(16)));
    int w, h, psm;
    int bytes;
    int n;
    qword iv;
    int mod = 0;
    int qwc = 0;
    int rem = 0;
    int extra = 0;
    int hh;
    u_int cnt = 0;
    u_int imr;
    int j;

    hh = 0;
    w = sp->trxreg.RRW;
    h = sp->trxreg.RRH;
    psm = sp->bitbltbuf.SPSM;
    switch (psm) {
    case 0:
    case 48:
        bytes = w * h * 4;
        mod = bytes & 15;
        rem = (bytes >> 4) & 7;
        qwc = (bytes >> 4) & 0xfffffff8;
        if (mod == 0) {
            hh = h;
            extra = 0;
        } else {
            hh = (h + 3) & 0x1FFC;
            n = (w * hh) >> 2;
            extra = n - qwc - rem - 1;
        }
        break;
    case 1:
    case 49:
        bytes = w * h * 3;
        mod = bytes & 15;
        rem = (bytes >> 4) & 7;
        qwc = (bytes >> 4) & 0xfffffff8;
        if (mod == 0) {
            hh = h;
            extra = 0;
        } else {
            hh = (h + 15) & 0x1FF0;
            n = (w * hh * 3) >> 4;
            extra = n - qwc - rem - 1;
        }
        break;
    case 2:
    case 10:
    case 50:
    case 58:
        bytes = w * h * 2;
        mod = bytes & 15;
        rem = (bytes >> 4) & 7;
        qwc = (bytes >> 4) & 0xfffffff8;
        if (mod == 0) {
            hh = h;
            extra = 0;
        } else {
            hh = (h + 7) & 0xfffffff8;
            n = (w * hh) >> 3;
            extra = n - qwc - rem - 1;
        }
        break;
    case 19:
    case 27:
        bytes = w * h;
        mod = bytes & 15;
        rem = (bytes >> 4) & 7;
        qwc = (bytes >> 4) & 0xfffffff8;
        if (mod == 0) {
            hh = h;
            extra = 0;
        } else {
            hh = (h + 7) & 0xfffffff8;
            n = (w * hh) >> 4;
            extra = n - qwc - rem - 1;
        }
        break;
    case 20:
    case 36:
    case 44:
        bytes = (w * h) >> 1;
        mod = bytes & 15;
        rem = (bytes >> 4) & 7;
        qwc = (bytes >> 4) & 0xfffffff8;
        if (mod == 0) {
            hh = h;
            extra = 0;
        } else {
            hh = (h + 7) & 0xfffffff8;
            n = (w * hh) >> 5;
            extra = n - qwc - rem - 1;
        }
        break;
    }

    if (mod != 0) {
        *(u_long *)((u_int)&sp->trxreg | 0x20000000) =
            (u_long)(int)sp->trxreg.RRW | ((u_long)hh << 32);
    }

    while (*(volatile u_int *)0x10009000 & 0x100) {
        if (cnt++ > 0x1000000) {
            func_003B1F28(D_0045DD80);
            return -1;
        }
    }

    imr = GsPutIMR(GsGetIMR() | 0x200);

    *(volatile u_long *)0x12001000 = 2;
    *(volatile u_int *)0x10009020 = 7;
    if (((u_int)sp & 0x70000000) == 0x70000000) {
        *(volatile u_int *)0x10009010 = ((u_int)sp & 0xFFFFFFF) | 0x80000000;
    } else {
        *(volatile u_int *)0x10009010 = (u_int)sp & 0xFFFFFFF;
    }
    *(volatile u_int *)0x10009000 = 0x101;
    while (*(volatile u_int *)0x10009000 & 0x100) {
        if (cnt++ > 0x1000000) {
            func_003B1F28(D_0045DD80);
            return -1;
        }
    }

    while ((*(volatile u_long *)0x12001000 & 2) == 0) {
        if (cnt++ > 0x1000000) {
            func_003B1F28(D_0045DDB8);
            *(volatile qword *)0x10005000 = D_003F8570;
            return -1;
        }
    }

    *(volatile u_int *)0x10003C00 = 0x800000;
    *(volatile u_long *)0x12001040 = 1;

    if (qwc != 0) {
        *(volatile u_int *)0x10009020 = qwc;
        if (((u_int)dstaddr & 0x70000000) == 0x70000000) {
            *(volatile u_int *)0x10009010 = ((u_int)dstaddr & 0xFFFFFFF) | 0x80000000;
        } else {
            *(volatile u_int *)0x10009010 = (u_int)dstaddr & 0xFFFFFFF;
        }
        *(volatile u_int *)0x10009000 = 0x100;
        while (*(volatile u_int *)0x10009000 & 0x100) {
            if (cnt++ > 0x1000000) {
                func_003B1F28(D_0045DDE8);
                *(volatile u_long *)0x12001000 = 0x100;
                *(volatile u_long *)0x12001040 = 0;
                *(volatile u_int *)0x10003000 = 1;
                *(volatile u_int *)0x10003C10 = 1;
                return -1;
            }
        }
    }

    for (j = 0; j < rem; j++) {
        while ((*(volatile u_int *)0x10003C00 & 0x1F000000) == 0) {
            if (cnt++ > 0x1000000) {
                func_003B1F28(D_0045DE28);
                *(volatile u_long *)0x12001000 = 0x100;
                *(volatile u_long *)0x12001040 = 0;
                *(volatile u_int *)0x10003000 = 1;
                *(volatile u_int *)0x10003C10 = 1;
                return -1;
            }
        }
        dstaddr[qwc + j] = *(volatile qword *)0x10005000;
    }

    if (mod != 0) {
        while ((*(volatile u_int *)0x10003C00 & 0x1F000000) == 0) {
            if (cnt++ > 0x1000000) {
                func_003B1F28(D_0045DE28);
                *(volatile u_long *)0x12001000 = 0x100;
                *(volatile u_long *)0x12001040 = 0;
                *(volatile u_int *)0x10003000 = 1;
                *(volatile u_int *)0x10003C10 = 1;
                return -1;
            }
        }
        *(qword *)buf = *(volatile qword *)0x10005000;
        for (j = 0; j < mod; j++) {
            *((u_char *)dstaddr + (qwc + rem) * 16 + j) = buf[j];
        }
        for (j = 0; j < extra; j++) {
            while ((*(volatile u_int *)0x10003C00 & 0x1F000000) == 0) {
                if (cnt++ > 0x1000000) {
                    func_003B1F28(D_0045DE28);
                    *(volatile u_long *)0x12001000 = 0x100;
                    *(volatile u_long *)0x12001040 = 0;
                    *(volatile u_int *)0x10003000 = 1;
                    *(volatile u_int *)0x10003C10 = 1;
                    return -1;
                }
            }
            *(qword *)buf = *(volatile qword *)0x10005000;
        }
    }

    *(volatile u_int *)0x10003C00 = 0;
    *(volatile u_long *)0x12001040 = 0;
    GsPutIMR(imr);
    iv = D_003F8570;
    *(volatile u_long *)0x12001000 = 2;
    *(volatile qword *)0x10005000 = iv;
    return 0;
}

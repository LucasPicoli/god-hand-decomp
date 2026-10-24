/* sn-2.95.3-136 */

typedef unsigned char u_char;
typedef unsigned int  u_int;
typedef unsigned long u_long;
typedef int qword __attribute__((mode(TI)));

/* The sceGsStoreImage packet of 003958d8.c with BITBLTBUF and TRXREG held as whole register
 * words: this copy masks SPSM, RRW and RRH out of them itself. */
typedef struct GsStoreImageWords {
    u_int          vifcode[4];
    u_long         giftag[2];
    u_long         bitbltbuf;
    long           bitbltbufaddr;
    u_long         trxpos;
    long           trxposaddr;
    u_long         trxreg;
    long           trxregaddr;
    u_long         finish;
    long           finishaddr;
    u_long         trxdir;
    long           trxdiraddr;
} GsStoreImageWords;

extern void func_003B1F28(char *fmt, ...);
extern unsigned long Tramp_GsGetIMR_3964A0(void);
extern u_long func_00396008(u_long newMask);
extern char D_00450808[];
extern char D_00450840[];
extern char D_00450870[];
extern char D_004508B0[];
extern qword D_003C3CE0;

/* The game's copy of libgraph sceGsExecStoreImage: read a GS image back through the GIF/VIF1 path into dstaddr; -1 on a timeout. */
__attribute__((section(".text.func_0030E660")))
int func_0030E660(GsStoreImageWords *sp, qword *dstaddr)
{
    u_char buf[16] __attribute__((aligned(16)));
    int w, h;
    int bytes;
    int n;
    int mod = 0;
    int qwc = 0;
    int rem = 0;
    int extra = 0;
    int hh;
    u_int cnt = 0;
    u_long imr;
    int j;

    hh = 0;
    w = sp->trxreg & 0xFFF;
    h = (sp->trxreg >> 32) & 0xFFF;
    switch ((sp->bitbltbuf >> 24) & 0x3F) {
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
            (sp->trxreg & 0xFFF) | ((u_long)hh << 32);
    }

    while (*(volatile u_int *)0x10009000 & 0x100) {
        if (cnt++ > 0x1000000) {
            func_003B1F28(D_00450808);
            return -1;
        }
    }

    imr = func_00396008((Tramp_GsGetIMR_3964A0() | 0x200) & 0x7E00);

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
            func_003B1F28(D_00450808);
            return -1;
        }
    }

    while ((*(volatile u_long *)0x12001000 & 2) == 0) {
        if (cnt++ > 0x1000000) {
            func_003B1F28(D_00450840);
            *(volatile qword *)0x10005000 = D_003C3CE0;
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
                func_003B1F28(D_00450870);
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
                func_003B1F28(D_004508B0);
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
                func_003B1F28(D_004508B0);
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
                    func_003B1F28(D_004508B0);
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
    func_00396008(imr);
    *(volatile u_long *)0x12001000 = 2;
    *(volatile qword *)0x10005000 = D_003C3CE0;
    return 0;
}

/* ee-2.9-991111: libdma sceDmaPutEnv: validate a DMA environment, pack it into D_CTRL, D_PCR,
 * D_SQWC, D_RBOR and D_RBSR, and keep a copy as the current environment. */
typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;

typedef struct {
    u_char sts;                         /* 0x00 */
    u_char std;                         /* 0x01 */
    u_char mfd;                         /* 0x02 */
    u_char rcycle;                      /* 0x03 */
    u_short express;                    /* 0x04 */
    u_short notify;                     /* 0x06 */
    u_short sqwc;                       /* 0x08 */
    u_short tqwc;                       /* 0x0A */
    void *rbadr;                        /* 0x0C */
    u_int rbmsk;                        /* 0x10 */
} sceDmaEnv;

#define D_CTRL (*(volatile u_int *)0x1000E000)
#define D_PCR  (*(volatile u_int *)0x1000E020)
#define D_SQWC (*(volatile u_int *)0x1000E030)
#define D_RBSR (*(volatile u_int *)0x1000E040)
#define D_RBOR (*(volatile u_int *)0x1000E050)

extern u_char D_0045E008[];
extern u_char D_0045E018[];
extern u_char D_0045E028[];
extern sceDmaEnv D_0077C090;

__attribute__((section(".text.sceDmaPutEnv")))
int sceDmaPutEnv(sceDmaEnv *env)
{
    u_int ctrl;
    u_int pcr;
    u_int sqwc;
    u_int rbor;
    u_int rbsr;

    ctrl = D_CTRL;
    pcr = D_PCR;
    sqwc = D_SQWC;
    rbor = D_RBOR;
    rbsr = D_RBSR;
    if (env->sts >= 10)
        return -1;
    if (env->std >= 10)
        return -2;
    if (env->mfd >= 10)
        return -3;
    if (env->rcycle >= 7)
        return -4;
    ctrl = (ctrl & ~0x30) | (D_0045E008[env->sts] << 4);
    ctrl = (ctrl & ~0xC0) | (D_0045E018[env->std] << 6);
    ctrl = (ctrl & ~0xC) | (D_0045E028[env->mfd] << 2);
    if (env->rcycle) {
        ctrl |= 2;
        ctrl = (ctrl & ~0x300) | ((env->rcycle - 1) << 8);
    } else {
        ctrl &= ~2;
    }
    pcr = (env->express << 16) | env->notify;
    sqwc = (env->tqwc << 16) | env->sqwc;
    rbor = (u_int)env->rbadr;
    rbsr = env->rbmsk;
    D_CTRL = ctrl;
    D_PCR = pcr;
    D_SQWC = sqwc;
    D_RBOR = rbor;
    D_RBSR = rbsr;
    D_0077C090 = *env;
    return 0;
}

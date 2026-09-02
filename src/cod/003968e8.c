/* ee-2.9-991111 matched TU. */

extern void *GetD003F8560_395388(void);
extern void func_003BA9F0(int);
extern void setD4_CHCR(int);

__attribute__((section(".text.sceGsPutDispEnv")))
void sceGsPutDispEnv(void *env) {
    short *g;
    g = (short *)GetD003F8560_395388();
    if (g[3] == 1) {
        *(volatile unsigned long *)0x12000000 = *(unsigned long *)((char *)env + 0x00);
        *(volatile unsigned long *)0x12000070 = *(unsigned long *)((char *)env + 0x10);
        *(volatile unsigned long *)0x12000080 = *(unsigned long *)((char *)env + 0x18);
        *(volatile unsigned long *)0x120000C0 = *(unsigned long *)((char *)env + 0x20);
    } else {
        *(volatile unsigned long *)0x12000000 = *(unsigned long *)((char *)env + 0x00);
        *(volatile unsigned long *)0x12000020 = *(unsigned long *)((char *)env + 0x08);
        *(volatile unsigned long *)0x12000090 = *(unsigned long *)((char *)env + 0x10);
        *(volatile unsigned long *)0x120000A0 = *(unsigned long *)((char *)env + 0x18);
        *(volatile unsigned long *)0x120000E0 = *(unsigned long *)((char *)env + 0x20);
    }
}

__attribute__((section(".text.sceGszbufaddr")))
short sceGszbufaddr(short a, short b, short c) {
    unsigned long *p;
    unsigned long mask = 0x0000FFFF0000FFFFUL;
    int y, z;
    p = (unsigned long *)GetD003F8560_395388();
    y = (b + 63) / 64;
    if ((a & 2) != 0)
        z = (c + 63) / 64;
    else
        z = (c + 31) / 32;
    if ((*p & mask) == 1)
        return (short)(y * z);
    return (short)(y * z * 2);
}

__attribute__((section(".text.sceIpuStopDMA")))
void sceIpuStopDMA(void *s) {
    func_003BA9F0(1);
    *(int *)((char *)s + 0x00) = *(volatile unsigned int *)0x1000B410;
    *(int *)((char *)s + 0x04) = *(volatile unsigned int *)0x1000B430;
    *(int *)((char *)s + 0x08) = *(volatile unsigned int *)0x1000B420;
    *(int *)((char *)s + 0x0C) = *(volatile unsigned int *)0x1000B400;
    while ((*(volatile unsigned int *)0x10002010 & 0xF0) != 0)
        ;
    setD4_CHCR(0);
    *(int *)((char *)s + 0x10) = *(volatile unsigned int *)0x1000B010;
    *(int *)((char *)s + 0x14) = *(volatile unsigned int *)0x1000B020;
    *(int *)((char *)s + 0x18) = *(volatile unsigned int *)0x1000B000;
    *(int *)((char *)s + 0x1C) = *(volatile unsigned int *)0x10002020;
    *(int *)((char *)s + 0x20) = *(volatile unsigned int *)0x10002010;
}

__attribute__((section(".text.sceMpegGetPicture")))
int sceMpegGetPicture(void *m, unsigned int addr, int mode) {
    char *q;
    addr = (addr & 0x0FFFFFFFU) | 0x20000000U;
    q = (char *)*(int *)((char *)m + 0x40);
    *(int *)(q + 0xC4) = 1;
    *(int *)(q + 0xEC) = addr;
    *(int *)(q + 0xF8) = mode;
    *(int *)(q + 0xF4) = 0;
    *(int *)(q + 0xF0) = 0;
    return func_0039A140(m);
}

/* sn-2.95.3-136 matched TU. */

extern void func_002B46F0(unsigned char *, int, int, int);
extern void func_002B4768(unsigned char *, unsigned char *, unsigned char *);
extern unsigned int D_00747A84;
extern int D_007474A0;
extern long D_00747640;
extern unsigned char *D_003C23A4;
extern void SetFlagEntries5And6_1D5650(void *a0, int a1);
extern void SetBlendField2CC_1D5AE8(void *a0, int a1);
extern int cSnd_SeCall_2CB8A0(void *a0, int a1, short a2, short a3, short a4, int a5, int a6);
extern char D_005FEE00[];
extern void SetFlagEntries7And8_1D5610(void *a0, int a1);
extern void SetBlendField3C4_1D5A40(void *a0, int a1);
extern void func_001D5690(void *a0, int a1);
extern void func_002998D8(int a0, int a1, long a2);
extern void func_00299908(int a0);
extern void PushEntryAtField10000_299868(char *a0, long a1, long a2);
extern unsigned char D_003BD758[];
extern char D_004A6980[];

/* sn-2.95.3-136, as=sn */








__attribute__((section(".text.func_002B3EC8")))
void func_002B3EC8(unsigned char *a0)
{
    unsigned char *s0;
    char *g;
    int old;
    int n;
    int w;
    int k;

    if (D_00747A84 & 0x8000000) {
        return;
    }
    s0 = a0;
    g = (char *)&D_00747A84 - 0x5E4;
    *(int *)(s0 + 0x14) |= 0x20;
    old = *(short *)(s0 + 0x94);
    if (*(long *)(g + 0x1A0) & 0x4000008000000L) {
        *(short *)(s0 + 0x94) = *(unsigned short *)(s0 + 0x94) - 1;
    }
    if (*(long *)(g + 0x1A0) & 0x8000004000000L) {
        *(short *)(s0 + 0x94) = *(unsigned short *)(s0 + 0x94) + 1;
    }
    n = *(short *)(s0 + 0x94);
    if (n >= 0) {
        int r = *(short *)(s0 + 0x96) - 1;
        if (r < n) {
            w = r;
        } else {
            w = n;
        }
    } else {
        w = 0;
    }
    *(short *)(s0 + 0x94) = w;
    if ((short)w != old) {
        func_002B46F0(s0, 0, 0x15F, 0);
    }
    if (D_00747640 & 0x10000000L) {
        k = *(short *)(s0 + 0x94);
        *(short *)(D_003C23A4 + 0xBEC) = k;
        func_002B46F0(s0, 0, 0x15E, 0);
        *(int *)(s0 + 0x14) = *(int *)(s0 + 0x14) & ~1;
        *(int *)(s0 + 0x14) = *(int *)(s0 + 0x14) & ~0x20;
        *(int *)(s0 + 0x14) = *(int *)(s0 + 0x14) | 0x400;
        func_002B4768(s0, s0 + 0x90, s0 + 0x8C);
        *(char *)(s0 + 0xC) = 2;
        *(char *)(s0 + 0xD) = 0;
        *(char *)(s0 + 0xE) = 0;
        *(char *)(s0 + 0xF) = 0;
    }
}

/* sn-2.95.3-136, as=sn */







__attribute__((section(".text.func_001D2A28")))
void func_001D2A28(void *a0)
{
    char *s0 = (char *)a0;

    switch (*(int *)(s0 + 0x1808)) {
    case 0:
        SetFlagEntries5And6_1D5650(s0, 1);
        SetBlendField2CC_1D5AE8(s0, 1);
        *(int *)(s0 + 0x1808) += 1;
        /* fallthrough */
    case 1: {
        char *g = (char *)&D_007474A0;
        long f = *(long *)(g + 0x1B0);

        if ((f & 0xCC0000C000000L) != 0) {
            SetFlagEntries5And6_1D5650(s0, 0);
            SetBlendField2CC_1D5AE8(s0, 0);
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
            *(int *)(s0 + 0x1808) = 0;
            *(int *)(s0 + 0x1804) = 6;
            return;
        }
        if ((f & 0x3300003000000L) != 0) {
            long q = *(unsigned int *)(s0 + 0x1800);
            if (((q >> 2) & 1) == 1) {
                SetFlagEntries5And6_1D5650(s0, 0);
                SetBlendField2CC_1D5AE8(s0, 0);
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
                *(int *)(s0 + 0x1808) = 0;
                *(int *)(s0 + 0x1804) = 8;
            }
            return;
        }
        {
            long h = *(long *)(g + 0x1A0);

            if ((h & 0x10000000L) != 0) {
                SetBlendField2CC_1D5AE8(s0, 0);
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15E, -1, -1, 0, 0);
                *(int *)(s0 + 0x1808) = 0;
                *(int *)(s0 + 0x1804) = 0xA;
            }
        }
        break;
    }
    }
}

/* sn-2.95.3-136, as=sn */








__attribute__((section(".text.func_001D2888")))
void func_001D2888(void *a0)
{
    char *s0 = (char *)a0;

    switch (*(int *)(s0 + 0x1808)) {
    case 0:
        SetFlagEntries7And8_1D5610(s0, 1);
        SetBlendField3C4_1D5A40(s0, 1);
        *(int *)(s0 + 0x1808) += 1;
        /* fallthrough */
    case 1: {
        char *g = (char *)&D_007474A0;
        long f = *(long *)(g + 0x1B0);

        if ((f & 0xCC0000C000000L) != 0) {
            SetFlagEntries7And8_1D5610(s0, 0);
            SetBlendField3C4_1D5A40(s0, 0);
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
            *(int *)(s0 + 0x1808) = 0;
            *(int *)(s0 + 0x1804) = 7;
            return;
        }
        if ((f & 0x3300003000000L) != 0) {
            long q = *(unsigned int *)(s0 + 0x1800);
            if (((q >> 2) & 1) == 1) {
                SetFlagEntries7And8_1D5610(s0, 0);
                SetBlendField3C4_1D5A40(s0, 0);
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
                *(int *)(s0 + 0x1808) = 0;
                *(int *)(s0 + 0x1804) = 8;
            }
            return;
        }
        {
            long h = *(long *)(g + 0x1A0);

            if ((h & 0x10000000L) != 0) {
                SetBlendField3C4_1D5A40(s0, 0);
                func_001D5690(s0, 2);
                *(int *)(s0 + 0x1800) = *(int *)(s0 + 0x1800) & ~4;
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15E, -1, -1, 0, 0);
                *(int *)(s0 + 0x1808) = 0;
                *(int *)(s0 + 0x1804) = 9;
            }
        }
        break;
    }
    }
}

/* sn-2.95.3-136, as=sn */







__attribute__((section(".text.func_00299A28")))
void func_00299A28(char *a0, int a1, int *pal)
{
    char *s0 = a0;
    int i;
    int k;
    int n;
    long e;

    n = 0x100;
    i = 0;
    do {
        n--;
        ((int *)D_004A6980)[i] = pal[D_003BD758[i]];
        i++;
    } while (n != 0);
    func_002998D8((int)s0, 0, 0xE);
    PushEntryAtField10000_299868(s0, 0x3F, 0xFF);
    PushEntryAtField10000_299868(s0, 0x50,
                                 ((long)a1 << 32) | ((unsigned long)0x8000 << 33));
    PushEntryAtField10000_299868(s0, 0x51, 0);
    PushEntryAtField10000_299868(s0, 0x52, ((unsigned long)0x8000 << 21) | 0x10);
    PushEntryAtField10000_299868(s0, 0x53, 0);
    func_00299908((int)s0);
    *(long *)(*(long **)(s0 + 0x10000)) = ((unsigned long)0x8000 << 44) | 0x40;
    *(long *)((char *)*(long **)(s0 + 0x10000) + 8) = 0;
    *(int *)(s0 + 0x10000) = *(int *)(s0 + 0x10000) + 0x10;
    n = 0x80;
    k = 0;
    do {
        e = ((long *)D_004A6980)[k];
        n--;
        k++;
        *(long *)(*(long **)(s0 + 0x10000)) = e;
        *(int *)(s0 + 0x10000) = *(int *)(s0 + 0x10000) + 8;
    } while (n != 0);
    func_002998D8((int)s0, 0, 0xE);
    PushEntryAtField10000_299868(s0, 0x3F, 0xFF);
    func_00299908((int)s0);
}

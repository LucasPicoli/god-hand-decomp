/* sn-2.95.3-136 matched TU. */

extern void func_002998D8(int a0, int a1, long a2);
extern void func_00299908(int a0);
extern void PushEntryAtField10000_299868(char *a0, long a1, long a2);
extern unsigned char D_003BD758[];
extern char D_004A6980[];
extern void func_001D5360(void *a0, int a1);
extern void func_001D5500(void *a0, int a1);
extern void SetBlendField6AC_1D58F0(void *a0, int a1);
extern void CustomIDWork_SetNumber_1D5760(void *a0, int a1);
extern void cCoreSave_addGold(char *a0, int a1, int a2);
extern void func_001D5430(void *a0, int a1);
extern int cSnd_SeCall_2CB8A0(void *a0, int a1, short a2, short a3, short a4, int a5, int a6);
extern char D_00569B70[];
extern char D_005FEE00[];
extern int D_007474A0;

__attribute__((section(".text.func_00299BA0")))
void func_00299BA0(char *a0, int a1, int *pal, int mode)
{
    char *s0 = a0;
    int i;
    int k;
    int n;
    long e;
    unsigned *p;
    long hi;

    n = 0x100;
    i = 0;
    do {
        n--;
        ((int *)D_004A6980)[i] = pal[D_003BD758[i]];
        i++;
    } while (n != 0);
    hi = (long)a1 << 32;
    if (mode == 0) {
        n = 0x100;
        i = 0;
        do {
            unsigned v = ((unsigned *)D_004A6980)[i];
            n--;
            ((unsigned *)D_004A6980)[i] = (v & 0xFFFFFF) | (v << 24);
            i++;
        } while (n != 0);
    }
    if (mode == 1) {
        n = 0x100;
        i = 0;
        do {
            unsigned v = ((unsigned *)D_004A6980)[i];
            n--;
            ((unsigned *)D_004A6980)[i] = (v & 0xFFFFFF) | ((v & 0xFF00) << 16);
            i++;
        } while (n != 0);
    }
    if (mode == 2) {
        n = 0x100;
        i = 0;
        do {
            unsigned v = ((unsigned *)D_004A6980)[i] & 0xFFFFFF;
            n--;
            ((unsigned *)D_004A6980)[i] = v | ((v & 0xFF0000) << 8);
            i++;
        } while (n != 0);
    }
    func_002998D8((int)s0, 0, 0xE);
    PushEntryAtField10000_299868(s0, 0x3F, 0xFF);
    PushEntryAtField10000_299868(s0, 0x50,
                                 hi | ((unsigned long)0x8000 << 33));
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

__attribute__((section(".text.func_001D1AA8")))
void func_001D1AA8(void *a0)
{
    char *s0 = (char *)a0;

    switch (*(int *)(s0 + 0x1808)) {
    case 0:
        func_001D5500(s0, 0);
        SetBlendField6AC_1D58F0(s0, 1);
        *(int *)(s0 + 0x1808) += 1;
        /* fallthrough */
    case 1: {
        char *g = (char *)&D_007474A0;
        long f = *(long *)(g + 0x1B0);

        if ((f & 0x8800004000000L) != 0) {
            if (*(int *)(s0 + 0x1814) < *(int *)(s0 + 0x1810)) {
                func_001D5500(s0, 1);
                SetBlendField6AC_1D58F0(s0, 0);
                *(int *)(s0 + 0x1808) = 0;
                *(int *)(s0 + 0x1804) = 1;
            }
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
            return;
        }
        if ((f & 0x4400008000000L) != 0) {
            if (*(int *)(s0 + 0x1814) < *(int *)(s0 + 0x1810)) {
                func_001D5500(s0, 1);
                SetBlendField6AC_1D58F0(s0, 0);
                *(int *)(s0 + 0x1808) = 0;
                *(int *)(s0 + 0x1804) = 2;
            }
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
            return;
        }
        if ((f & 0x3300003000000L) != 0) {
            func_001D5500(s0, 1);
            SetBlendField6AC_1D58F0(s0, 0);
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
            *(int *)(s0 + 0x1808) = 0;
            *(int *)(s0 + 0x1804) = 4;
            return;
        }
        {
            long h = *(long *)(g + 0x1A0);

            if ((h & 0x10000000L) != 0) {
                *(int *)(s0 + 0x1808) = 0;
                *(int *)(s0 + 0x1804) = 5;
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15E, -1, -1, 0, 0);
                return;
            }
            if ((h & 0x20000000L) != 0) {
                if (*(int *)(s0 + 0x1814) > 0) {
                    int v;

                    cCoreSave_addGold(D_00569B70, 0x64, 0);
                    v = *(int *)(s0 + 0x1814) - 0x64;
                    *(int *)(s0 + 0x1814) = v;
                    CustomIDWork_SetNumber_1D5760(s0, v);
                    func_001D5360(s0, 1);
                    func_001D5430(s0, 1);
                    if (*(int *)(s0 + 0x1814) == 0) {
                        SetBlendField6AC_1D58F0(s0, 0);
                        func_001D5500(s0, 2);
                        *(int *)(s0 + 0x1808) = 0;
                        *(int *)(s0 + 0x1804) = 1;
                    }
                }
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x161, -1, -1, 0, 0);
            }
        }
        break;
    }
    }
}

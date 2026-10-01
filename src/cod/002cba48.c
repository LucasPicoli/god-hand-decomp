/* sn-2.95.3-136 matched TU. */

extern void *GetIndexedEntry_2CC4B8(void *a0, int a1);
extern int D_0044CE48[];
extern void func_002FBFB0(int a0);
extern void UpdateObjByIndexedOp_2FBE50(int a0);
extern int D_00741DB8;
extern unsigned char D_0044D3B0[];
extern void getEffTypeString(void *a0, int a1);
extern void func_003A6C58(void *a0, void *a1, void *a2, int a3, int t0);

__attribute__((section(".text.cSnd_SeCall_2CBA48")))
int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, void *t0, int t1, int t2, int t3) {
    void *s3 = a0;
    int s4 = (short)a1;
    int sa2 = (short)a2;
    void *s5 = a3;
    void *s0t0 = t0;
    int s6 = t1, s7 = t2, fp = t3;
    int s1;
    void *r;

    if (s4 == 1) {
        int *p;
        unsigned int s2;
        if (s0t0 != 0) {
            s1 = func_002CB3A8(s3, *(int *)((char *)s0t0 + 0x564));
            if (s1 <= 0)
                s1 = *(unsigned short *)((char *)s0t0 + 0x300);
        } else {
            s1 = func_002CB3A8(s3, *(int *)((char *)s5 + 0x564));
            if (s1 <= 0)
                s1 = *(unsigned short *)((char *)s5 + 0x300);
        }
        p = D_0044CE48;
        s2 = 0;
        do {
            void *e = GetIndexedEntry_2CC4B8(s3, *p);
            if (*(int *)((char *)e + 0x3C) == s1)
                s4 = *(short *)p;
            s2++;
            p++;
        } while (s2 < 0xC);
    }

    r = GetIndexedEntry_2CC4B8(s3, s4);
    if (cSeData_IsAlive(r) == 0)
        return 0;
    {
        int v = cSnd_AllocVoice(s3);
        if (v == 0)
            return 0;
        return cSndSeVoice_Bind(v, s4, sa2, (int)s5, s6, s7, fp);
    }
}

__attribute__((section(".text.func_002FBED0")))
void func_002FBED0(int a0) {
    int s0 = a0;
    if (func_002B5E50(a0)) {
        int v = *(int*)(s0 + 0x114);
        if (v) {
            if (*(int*)(v + 0x250) < 0) {
                UpdateObjByIndexedOp_2FBE50(s0);
            }
        }
    }
    func_002FBFB0(s0);
    if (((*(int**)(s0 + 0x110))[1]) & 0x800) {
        if (D_00741DB8 == 0) {
            *(int*)(s0 + 0x11C) = *(int*)(s0 + 0x11C) | 0x800000;
        } else {
            *(int*)(s0 + 0x11C) = *(int*)(s0 + 0x11C) & 0xFF7FFFFF;
        }
    }
    if (((*(int**)(s0 + 0x110))[1]) & 0x400) {
        if (D_00741DB8 != 0) {
            *(int*)(s0 + 0x11C) = *(int*)(s0 + 0x11C) | 0x800000;
        } else {
            *(int*)(s0 + 0x11C) = *(int*)(s0 + 0x11C) & 0xFF7FFFFF;
        }
    }
}

__attribute__((section(".text.func_002D9F68")))
void func_002D9F68(void *a0, int a1, ...) {
    char buf0[0x100];
    char localbuf[0x40];
    getEffTypeString(localbuf, *(short*)((char*)a0 + 0x23A));
    func_003A6C58(buf0, D_0044D3B0, localbuf, (int)((unsigned short)*(unsigned short*)((char*)a0 + 0x23C) - 1), a1);
}

/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 candidate. */

extern void CopyVec3From110To120_14A2B0(void *o);
extern void func_00150138(void *o);
extern void func_001501D0(void *o, int a1);
extern void func_002AD2B8(void *a0, int a1, void *a2, int a3, void *t0, int t1,
                          float f12);
extern unsigned char D_004209E8[];
extern char D_004209F8[];
extern char D_00420A88[];

__attribute__((section(".text.func_001717C0")))
void func_001717C0(char *self, float *p1, float *p2)
{
    char frame[0x50];
    float *q;
    float *d;
    unsigned char *tbl;
    char *ent;
    char *base;
    int i;
    int j;
    int k;
    int m;
    int n;
    int idx;
    int cnt;
    int ok;
    float fx;
    float fy;
    float fz;

    {
        float *e = *(float **)(self + 0xF0);
        if (e != p1) {
            e[0] = p1[0];
            e[1] = p1[1];
            e[2] = p1[2];
        }
    }
    {
        float *e = (float *)(self + 0x100);
        if (e != p2) {
            *(float *)(self + 0x100) = p2[0];
            e[1] = p2[1];
            e[2] = p2[2];
        }
    }
    CopyVec3From110To120_14A2B0(self);
    tbl = D_004209E8;
    q = (float *)(frame + 0x10);
    for (j = 0; j < 7; j++) {
        for (i = 0; i < 5; i++) {
            cnt = *(unsigned char *)(self + 0x2B4);
            idx = *(unsigned char *)(i + (int)tbl) + j;
            ok = 0;
            *(int *)frame = cnt;
            if (idx >= 0) {
                ok = idx < cnt;
                cnt = 0;
            }
            if (ok & 0xFF) {
                ent = *(char **)(*(char **)(self + 0x278) + idx * 4);
            } else {
                ent = 0;
            }
            func_00150138(ent);
            func_001501D0(ent, *(int *)(self + 0x250));
            fx = *(float *)(ent + 0xB0);
            fy = *(float *)(ent + 0xB4);
            fz = *(float *)(ent + 0xB8);
            *(float *)(frame + 0x10) = fx;
            *(float *)(frame + 0x14) = fy;
            *(float *)(frame + 0x18) = fz;
            base = self + 0x1AE0;
            d = (float *)(*(char **)(base + 0x10)
                          + (*(int *)(self + 0x1AE0) * j + j + i) * 0x50);
            q[3] = 1.0f;
            if (d != q) {
                d[0] = *(float *)(frame + 0x10);
                d[1] = *(float *)(frame + 0x14);
                d[2] = *(float *)(frame + 0x18);
            }
        }
    }
    for (n = 0; n < 7; n++) {
        for (m = 0; m < 5; m++) {
        }
    }
    for (n = 0; n < 7; n++) {
        k = 0;
    lp:
        k++;
        if (k < 5) {
            goto lp;
        }
    }
    func_002AD2B8(self + 0x1AE0, 0xD4, D_004209F8, 0x23, D_00420A88, 0x6A, 5.0f);
}

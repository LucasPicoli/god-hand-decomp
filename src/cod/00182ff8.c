/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 candidate. */

extern void CopyVec3From110To120_14A2B0(void *p);
extern void func_00150138(int obj);
extern void func_001501D0(int obj, int a);
extern int func_002AD2B8(void *g, int a, void *b, int c, void *d, int e, float f);
extern unsigned char D_00422A10[];
extern char D_00422A20[];
extern char D_00422A58[];

static __inline__ void SetVec4(float *d, float x, float y, float z)
{
    d[0] = x;
    d[1] = y;
    d[2] = z;
    d[3] = 1.0f;
}

static __inline__ void CopyVec3(float *d, float *s)
{
    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
}

__attribute__((section(".text.cOl30_SetInitialPosition")))
int cOl30_SetInitialPosition(char *p, float *a1, float *a2)
{
    unsigned char frame[0x10];
    float v[4];
    float spare[3][4];
    char *g;
    int i, j, jn, k, b, obj;
    int m, n, o, on;
    int off;
    unsigned char ok;

    CopyVec3(*(float **)(p + 0xF0), a1);
    CopyVec3((float *)(p + 0x100), a2);
    CopyVec3From110To120_14A2B0(p);
    j = 0;
    do {
        k = 0;
        jn = j + 1;
        for (; k < 7; k++) {
            g = p + 0xB10;
            i = D_00422A10[k] + j;
            ok = ((*(int *)frame = b = *(unsigned char *)(p + 0x2B4)), (i >= 0 && i < b));
            if (ok) obj = *(int *)(*(int *)(p + 0x278) + i * 4); else obj = 0;
            func_00150138(obj);
            func_001501D0(obj, *(int *)(p + 0x250));
            SetVec4(v, *(float *)(obj + 0xB0), *(float *)(obj + 0xB4), *(float *)(obj + 0xB8));
            off = (*(int *)(p + 0xB10) * j + j + k) * 0x50;
            CopyVec3((float *)(*(char **)(g + 0x10) + off), v);
        }
        j = jn;
    } while (j < 2);
    for (m = 0; m < 2; m++) {
        for (n = 6; n >= 0; n--) {
        }
    }
    o = 0;
    do {
        on = o + 1;
        for (m = 0; m < 7; m++) {
            i = D_00422A10[m] + o;
        }
        o = on;
    } while (o < 2);
    return func_002AD2B8(g, 0xE, D_00422A20, 0xE, D_00422A58, 7, 5.0f);
}

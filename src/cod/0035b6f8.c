/* cygnus-2.96 matched TU. */

/* cygnus-2.96 candidate: SFTIM_IsExecTime */

extern void func_0035AB98(int a0, int *t0, int *t1);
extern void func_0035B848(int a0, int a1, int a2, int *a3);
extern void func_0035B8C0(int a0, int *out, float cur, float t);
extern int D_003EE270;

__attribute__((section(".text.func_0035B6F8")))
__attribute__((section(".text.func_0035B6F8")))
void func_0035B6F8(int a0, int a1, int a2, int *a3, int scale)
{
    int t[2];
    int *w = &D_003EE270;
    int m;
    int nt;
    int mode;
    float vt;
    float vt2;
    func_0035AB98(a0, &t[0], &t[1]);
    m = t[1];
    if (m == 1) {
        if (t[0] == -2) {
            *a3 = 1;
            return;
        }
        func_0035B848(a0, a1, a2, a3);
        return;
    }
    vt = (float)a1 * 10000.0f / (float)a2;

    nt = t[0] + m * scale / w[2];
    mode = *(int *)(a0 + 0xA48);
    vt2 = (float)nt * 10000.0f / (float)m;
    t[0] = nt;
    if (mode != 1) {
        func_0035B8C0(a0, a3, vt, vt2);
        return;
    }
    if (vt <= vt2) {
        *a3 = 1;
    } else {
        *a3 = 0;
    }
}

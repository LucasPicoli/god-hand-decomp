/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

extern void func_001B6FB8(void *a0);
extern int func_0012EAD8(void *a0, void *a1, void *a2, float *a3, float *t0,
                         float *t1, float *t2, float *t3,
                         float *s0, float *s1, float *s2, float *s3);
extern char D_005CAE50[];

typedef struct Blob {
    int w[24];
} Blob;

extern Blob D_00427758;

__attribute__((section(".text.func_001A83E0")))
int func_001A83E0(void *a0)
{
    char *s0 = (char *)a0;
    float f[40];
    float *pa;
    float *pb;
    float *pc;
    float *pd;
    int r;
    char *p80;

    func_001B6FB8(s0);
    pa = &f[0];
    pb = &f[4];
    pc = &f[8];
    pd = &f[12];
    pa[0] = 1.5f;
    pa[1] = 0.2f;
    pa[2] = 1.5f;
    pa[3] = 1.0f;
    f[4] = f[0];
    f[5] = f[1];
    f[6] = f[2];
    pb[3] = 1.0f;
    f[8] = 0.0f;
    f[9] = f[1] * 0.5f;
    f[10] = 0.0f;
    pc[3] = 1.0f;
    f[12] = 0.0f;
    f[13] = 0.0f;
    f[14] = 0.0f;
    pd[3] = 1.0f;
    *(Blob *)&f[16] = D_00427758;
    p80 = s0 + 0x80;
    r = func_0012EAD8(D_005CAE50, s0, p80, &f[8], &f[12], &f[4], &f[16], &f[20],
                      &f[24], &f[28], &f[32], &f[36]);
    *(int *)(s0 + 0x600) = r;
    return 1;
}

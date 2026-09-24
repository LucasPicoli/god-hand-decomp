/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 candidate. */

extern void *cMessage_getMessageAddr(void *a, int b);
extern void *D_003C23A4;
extern void *D_003C2380;
extern int Obj0000_Get_D_003C23A4_By_Short_A1p2_2B1270(void *obj, int id);

extern void func_002A52E8(void *d, int a);
extern void func_002A53A8(void *d, int w, float x, float y, float z);


__attribute__((section(".text.func_002B0208")))
void func_002B0208(char *obj, float *prm)
{
    unsigned int n;
    unsigned int i;
    int p;
    int d;
    int val;
    int lim;
    int r;
    unsigned short w;
    float x;
    float y;

    x = *(float *)(obj + 0x88);
    lim = *(int *)(obj + 0x6C);
    y = *(float *)(obj + 0x8C);
    val = Obj0000_Get_D_003C23A4_By_Short_A1p2_2B1270(obj, *(int *)(obj + 0x64));
    n = func_002AF348(val);
    p = 1;
    for (i = 1; i < n; i++) p *= 10;
    if ((*(int *)obj & 1) != 0) {
        y += (*(float *)(obj + 0x38) + 12.0f) * *(float *)(obj + 0x48);
    }
    while (p != 0) {
        d = val / p;
        lim += 0x1E;
        w = ((unsigned short *)cMessage_getMessageAddr(D_003C23A4, 4))[d];
        *(float *)((char *)D_003C2380 + 0x2A068) = prm[0] * *(float *)(obj + 0x3C) * *(float *)(obj + 0x44);
        *(float *)((char *)D_003C2380 + 0x2A06C) = prm[0] * *(float *)(obj + 0x40) * *(float *)(obj + 0x48);
        func_002A52E8(D_003C2380, ((int *)prm)[1]);
        func_002A53A8(D_003C2380, w, x, y, 65535.0f);
        r = func_002A4B20(D_003C2380, w);
        x += (float)r * (prm[0] * *(float *)(obj + 0x3C) * *(float *)(obj + 0x44))
             + *(float *)(obj + 0x2C) * *(float *)(obj + 0x44);
        val -= d * p;
        if (*(int *)(obj + 0x1C) < lim) break;
        p /= 10;
    }
}

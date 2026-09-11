/* cygnus-2.96 matched TU. */

typedef int (*Meth)(void *obj, int sw);

typedef struct Stm {
    int f0;
    void *f4;
    int f8;
    int fC;
} Stm;

extern int GetArrayElemA0C_35A1C8(void *hn, int id);

__attribute__((section(".text.func_00357DA0")))
int func_00357DA0(void *hn)
{
    Stm *st;
    void *obj;
    Meth *vt;
    int n;

    st = (Stm *)((char *)hn + *(int *)((char *)hn + 0x1FC8) * 116 + 0x1320);
    obj = st->f4;
    vt = *(Meth **)obj;
    n = vt[9](obj, 1);
    if (n < st->fC * 80 / 100) {
        if (n < GetArrayElemA0C_35A1C8(hn, 0x46)) return 0;
    }
    return 1;
}

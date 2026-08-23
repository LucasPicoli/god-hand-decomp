/* sn-2.95.3-136 matched TU. */

extern void cOmBase_setMeshDispFromLayer(void *a0, int a1, int a2);
extern unsigned char D_004452D8[];

__attribute__((section(".text.func_001BBF68")))
int func_001BBF68(char *p)
{
    unsigned char frame[0x10] __attribute__((aligned(16)));
    int i, k, lo, b, b2, t, o1, o2;
    unsigned char ok1, ok2;

    cOmBase_setMeshDispFromLayer(p, 0, 1);
    cOmBase_setMeshDispFromLayer(p, 0x40, 0);
    i = 1;
    if (i < *(signed char *)(p + 0x624)) {
        t = *(unsigned char *)(p + 0x2B4);
        if (t != i) {
            b = t;
            lo = 0;
            k = 1;
            do {
                ok1 = ((*(int *)frame = b), (k >= lo && i < b));
                if (ok1) o1 = *(int *)(i * 4 + *(int *)(p + 0x278)); else o1 = 0;
                *(int *)(o1 + 0x154) |= 8;
                ok2 = ((*(int *)frame = b2 = *(unsigned char *)(p + 0x2B4)), (k >= lo && i < b2));
                if (ok2) o2 = *(int *)(i * 4 + *(int *)(p + 0x278)); else o2 = 0;
                *(int *)(o2 + 0x154) |= 0x10;
                i++;
                k++;
                if (!(i < *(signed char *)(p + 0x624))) break;
                t = *(unsigned char *)(p + 0x2B4);
                b = t;
            } while (t != i);
        }
    }
    *(int *)(p + 0x5B8) |= 4;
    if (*(int *)(p + 0x600) != 0) {
        *(int *)(*(int *)(p + 0x600)) |= 1;
    }
    return 1;
}

typedef struct { char b[7]; } T7;

__attribute__((section(".text.func_0026A200")))
void func_0026A200(char *p)
{
    unsigned char frame[0x20] __attribute__((aligned(16)));
    unsigned int i;
    int lo, b, idx;
    char *q;
    unsigned char ok;
    float v;

    *(T7 *)frame = *(T7 *)D_004452D8;
    if ((*(int *)(p + 0x564) ^ 0x222) != 0) return;
    if (*(signed char *)(p + 0x1865) != 0) {
        *(unsigned char *)(p + 0x1865) = *(unsigned char *)(p + 0x1865) - 1;
    }
    i = 0;
    lo = 0;
    for (; i < 7; i++) {
        idx = frame[i];
        ok = ((*(int *)(frame + 0x10) = b = *(unsigned char *)(p + 0x2B4)),
              (idx >= lo && idx < b));
        if (ok) q = (char *) *(int *)(idx * 4 + *(int *)(p + 0x278)); else q = 0;
        if (q != 0) {
            if (*(signed char *)(p + 0x1865) != 0) {
                v = *(float *)(q + 0x110) + *(float *)(p + 0x5A8);
                *(float *)(q + 0x110) = v;
                if (*(float *)(p + 0x17D4) < v) *(float *)(q + 0x110) = *(float *)(p + 0x17D4);
            } else {
                v = *(float *)(q + 0x110) - *(float *)(p + 0x5A8) * 0.5f;
                *(float *)(q + 0x110) = v;
                if (v < 1.0f) *(float *)(q + 0x110) = 1.0f;
            }
            *(float *)(q + 0x118) = *(float *)(q + 0x110);
            *(float *)(q + 0x114) = *(float *)(q + 0x110);
        }
    }
}

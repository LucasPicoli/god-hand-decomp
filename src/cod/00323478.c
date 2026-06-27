/* cygnus-2.96 matched TU. */

extern void MWSFSVM_Error();
extern char D_00458168[];
extern signed char D_003EAEC8[];
extern signed char D_003DED70[];
extern int D_003D84BC;
extern signed char D_003D84C0[];
extern void DTX_Destroy(void *);

typedef struct {
    char pad[0x1A4];
    int f1A4;
    int pad2[1];
    int f1AC;
    int f1B0;
    int f1B4;
    int f1B8;
} S346228;





__attribute__((section(".text.func_00346228")))
void func_00346228(S346228 *this, int a1, int a2) {
    int x, y, z;
    if (func_003245B0(a1, a2, this->f1A4, &x, &y, &z) == 0) {
        this->f1B0 = x;
        this->f1B4 = y;
        this->f1B8 = z;
        this->f1AC = 1;
    } else {
        MWSFSVM_Error(D_00458168);
    }
}

__attribute__((section(".text.func_00323478")))
signed char *func_00323478(void) {
    signed char *r;
    int i;
    r = 0;
    for (i = 0; i < 16; i++) {
        if (D_003EAEC8[i * 0x44] == 0) {
            r = &D_003EAEC8[i * 0x44];
            break;
        }
    }
    return r;
}

__attribute__((section(".text.func_0034F658")))
void func_0034F658(void *a0, int *out)
{
    int *base;
    int s1v;
    int r;
    int res;

    base = (int *)((char *)a0 + 0x1F74);
    s1v = base[2];
    r = func_0034CA98(a0, base[4]);
    if (r == 1) {
        func_0034F390(a0, *(int *)(s1v + 0x3C));
        res = 1;
    } else {
        res = 0;
    }
    if (out != 0)
        *out = res;
}

__attribute__((section(".text.func_00336530")))
signed char *func_00336530(void) {
    signed char *result;
    int i;
    result = 0;
    for (i = 0; i < 0x28; i++) {
        if (D_003DED70[i * 0x38] == 0) {
            result = &D_003DED70[i * 0x38];
            break;
        }
    }
    return result;
}

__attribute__((section(".text.func_003325F8")))
void func_003325F8(void) {
    signed char *p;
    int i;
    int one;
    if (--D_003D84BC == 0) {
        one = 1;
        p = D_003D84C0;
        i = 15;
        do {
            if (*p == one) {
                DTX_Destroy(p);
            }
            i--;
            p += 0x44;
        } while (i >= 0);
    }
}

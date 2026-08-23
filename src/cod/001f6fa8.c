/* sn-2.95.3-136 matched TU. */

extern char *D_003C3BF8[];
extern char D_003C3C18[];
extern long D_00747640;
extern int D_00747A84;

__attribute__((section(".text.FileNameFromObjId")))
char *FileNameFromObjId(char *out, int id) {
    int n = id >> 8;

    out[0] = D_003C3BF8[n][0];
    out[1] = D_003C3BF8[n][1];
    out[2] = '/';
    out[3] = D_003C3BF8[n][0];
    out[4] = D_003C3BF8[n][1];
    out[5] = D_003C3C18[(id & 0xF0) >> 4];
    out[6] = D_003C3C18[id & 0xF];
    out[7] = '.';
    out[8] = 'd';
    out[9] = 'a';
    out[10] = 't';
    out[11] = 0;
    return out;
}

__attribute__((section(".text.func_001F6FA8")))
int func_001F6FA8(char *p) {
    long f;

    f = D_00747640 & 0x77F00000000L;
    if ((f & 0x800000000L) && *(int *)(p + 0x20) == 0) {
        return 1;
    }
    if ((f & 0x100000000L) && *(int *)(p + 0x20) == 1) {
        return 1;
    }
    if ((f & 0x200000000L) && *(int *)(p + 0x20) == 2) {
        return 1;
    }
    if ((f & 0x400000000L) && *(int *)(p + 0x20) == 3) {
        return 1;
    }
    return 0;
}

__attribute__((section(".text.func_002CB080")))
void func_002CB080(char *a, char *b) {
    char *n;
    int nxt;
    int old;

    D_00747A84 = D_00747A84 & ~0x800;
    *(int *)(a + 0x2C) = 0;
    if (b == 0) {
        return;
    }
    n = b + *(int *)(b + 8);
    if (*(float *)(b + 4) == 0.0f) {
        return;
    }
    if (*(float *)(b + 4) == 1.1f) {
        if (*(int *)(b + 0xC) == 0) {
            return;
        }
    }
    for (;;) {
        nxt = *(int *)n;
        *(int *)n = 0;
        old = *(int *)(a + 0x2C);
        *(int *)(a + 0x2C) = (int)n;
        *(int *)n = old;
        n[0x12] = 0;
        n[0x13] = 0;
        *(int *)(n + 0x14) = 0;
        if (nxt == 0) {
            return;
        }
        n = n + (*(unsigned char *)(n + 0xE) << 4) + 0x30;
        if (n == 0) {
            return;
        }
    }
}

__attribute__((section(".text.func_002D74B8")))
int func_002D74B8(int id) {
    long ok;
    int tmp;
    int lo;

    lo = id >= 0x100;
    ok = 0;
    if (lo) {
        tmp = id < 0x200;
        ok = tmp;
    }
    if (ok & 0xFF) {
        return 1;
    }
    lo = id >= 0x200;
    ok = 0;
    if (lo) {
        tmp = id < 0x301;
        ok = tmp;
    }
    if (ok & 0xFF) {
        return 1;
    }
    lo = id >= 0x300;
    ok = 0;
    if (lo) {
        tmp = id < 0x501;
        ok = tmp;
    }
    if (ok & 0xFF) {
        return 1;
    }
    lo = id >= 0x500;
    ok = 0;
    if (lo) {
        tmp = id < 0x601;
        ok = tmp;
    }
    if (ok & 0xFF) {
        return 1;
    }
    return (unsigned int)(id - 0xFF01) < 2;
}

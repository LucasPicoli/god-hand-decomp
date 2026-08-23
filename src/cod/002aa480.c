/* sn-2.95.3-136 matched TU. */

extern char D_005E7910[];
extern char *D_00754C58;

__attribute__((section(".text.func_002AA480")))
void func_002AA480(char *a) {
    int i;
    int j;
    int c;
    int o1;
    int o2;
    int o3;
    char *p;
    char *q;
    char *r;

    for (i = 0; i < *(int *)(a + 0xC); i++) {
        o1 = i * 0xAC;
        p = (char *)(o1 + *(int *)(a + 4));
        c = *(char *)(p + 0x29);
        if (c < 0) {
            *(int *)(p + 0x20) = 0;
            continue;
        }
        if (c == *(unsigned char *)(p + 0x28)) {
            *(int *)(p + 0x20) = 0;
            return;
        }
        for (j = 0; j < *(int *)(a + 0xC); j++) {
            if (i == j) {
                continue;
            }
            o2 = i * 0xAC;
            o3 = j * 0xAC;
            q = (char *)(o2 + *(int *)(a + 4));
            r = (char *)(o3 + *(int *)(a + 4));
            if (*(char *)(q + 0x29) == *(unsigned char *)(r + 0x28)) {
                *(int *)(q + 0x20) = (int)r;
            }
        }
    }
}

typedef struct {
    int b[0x2F];
} Blk0BC;

__attribute__((section(".text.func_002B2080")))
void func_002B2080(void *dst) {
    *(Blk0BC *)dst = *(Blk0BC *)D_005E7910;
}

__attribute__((section(".text.cScenario_setOmSuspend")))
void cScenario_setOmSuspend(void *self, int susp) {
    char **cur;
    char *o;
    long ok;
    int tmp;
    int st1;
    int st2;
    long t;

    cur = *(char ***)(D_00754C58 + 4);
    while ((unsigned int)cur < *(unsigned int *)(D_00754C58 + 8)) {
        o = *cur;
        st1 = *(unsigned short *)(o + 0x2FE);
        st2 = *(unsigned short *)(o + 0x2FE);
        ok = 0;
        if (st1 >= 0x300) {
            tmp = st2 < 0x500;
            ok = tmp;
        }
        if (ok & 0xFF) {
            if (susp == 1) {
                t = *(unsigned int *)(o + 0x5B8);
                if (((t >> 6) & 1) == 0) {
                    *(int *)(o + 0x250) = *(int *)(o + 0x250) | 0x8000;
                }
            } else {
                *(int *)(o + 0x250) = *(int *)(o + 0x250) & ~0x8000;
            }
        }
        cur++;
    }
}

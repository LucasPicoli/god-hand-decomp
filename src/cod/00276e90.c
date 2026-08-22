/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.cEm12_SetParent")))
void cEm12_SetParent(char *p, char *q, int idx)
{
    char hold[16];
    char *e1;
    char *e2;
    int cnt;
    int cnt2;
    int ok;

    if (q == 0) {
        return;
    }
    cnt = *((unsigned char *) (p + 0x2B4));
    *((int *) hold) = cnt;
    if (cnt != 0) {
        e1 = *((char **) *((char **) (p + 0x278)));
    } else {
        e1 = 0;
    }
    if (e1 == 0) {
        return;
    }
    ok = 0;
    cnt2 = *((unsigned char *) (q + 0x2B4));
    *((int *) hold) = cnt2;
    if (idx >= 0) {
        ok = idx < cnt2;
        cnt2 = 0;
    }
    if (ok & 0xFF) {
        e2 = *((char **) (*((char **) (q + 0x278)) + idx * 4));
    } else {
        e2 = 0;
    }
    if (e2 == 0) {
        return;
    }
    *((int *) (e1 + 0x148)) = (int) e2;
    *((int *) (p + 0x21B4)) = idx;
    *((int *) (p + 0x21B0)) = (int) q;
    *((int *) (p + 0x2188)) = (int) q;
    *((int *) (p + 0x2168)) = 8;
}

__attribute__((section(".text.cEm53_SetParent")))
void cEm53_SetParent(char *p, char *q, int idx)
{
    char hold[16];
    char *e1;
    char *e2;
    int cnt;
    int cnt2;
    int ok;

    if (q == 0) {
        return;
    }
    cnt = *((unsigned char *) (p + 0x2B4));
    *((int *) hold) = cnt;
    if (cnt != 0) {
        e1 = *((char **) *((char **) (p + 0x278)));
    } else {
        e1 = 0;
    }
    if (e1 == 0) {
        return;
    }
    ok = 0;
    cnt2 = *((unsigned char *) (q + 0x2B4));
    *((int *) hold) = cnt2;
    if (idx >= 0) {
        ok = idx < cnt2;
        cnt2 = 0;
    }
    if (ok & 0xFF) {
        e2 = *((char **) (*((char **) (q + 0x278)) + idx * 4));
    } else {
        e2 = 0;
    }
    if (e2 == 0) {
        return;
    }
    *((int *) (e1 + 0x148)) = (int) e2;
    *((int *) (p + 0x21B4)) = idx;
    *((int *) (p + 0x21B0)) = (int) q;
    *((int *) (p + 0x2188)) = (int) q;
    *((int *) (p + 0x2168)) = 0xB;
}

__attribute__((section(".text.cEm57_SetParent")))
void cEm57_SetParent(char *p, char *q, int idx)
{
    char hold[16];
    char *e1;
    char *e2;
    int cnt;
    int cnt2;
    int ok;

    if (q == 0) {
        return;
    }
    cnt = *((unsigned char *) (p + 0x2B4));
    *((int *) hold) = cnt;
    if (cnt != 0) {
        e1 = *((char **) *((char **) (p + 0x278)));
    } else {
        e1 = 0;
    }
    if (e1 == 0) {
        return;
    }
    ok = 0;
    cnt2 = *((unsigned char *) (q + 0x2B4));
    *((int *) hold) = cnt2;
    if (idx >= 0) {
        ok = idx < cnt2;
        cnt2 = 0;
    }
    if (ok & 0xFF) {
        e2 = *((char **) (*((char **) (q + 0x278)) + idx * 4));
    } else {
        e2 = 0;
    }
    if (e2 == 0) {
        return;
    }
    *((int *) (e1 + 0x148)) = (int) e2;
    *((int *) (p + 0x21B4)) = idx;
    *((int *) (p + 0x21B0)) = (int) q;
    *((int *) (p + 0x2188)) = (int) q;
    *((int *) (p + 0x2168)) = 0xB;
}

__attribute__((section(".text.func_00283BE8")))
void func_00283BE8(char *p, char *q, int idx)
{
    char hold[16];
    char *e1;
    char *e2;
    int cnt;
    int cnt2;
    int ok;

    if (q == 0) {
        return;
    }
    cnt = *((unsigned char *) (p + 0x2B4));
    *((int *) hold) = cnt;
    if (cnt != 0) {
        e1 = *((char **) *((char **) (p + 0x278)));
    } else {
        e1 = 0;
    }
    if (e1 == 0) {
        return;
    }
    ok = 0;
    cnt2 = *((unsigned char *) (q + 0x2B4));
    *((int *) hold) = cnt2;
    if (idx >= 0) {
        ok = idx < cnt2;
        cnt2 = 0;
    }
    if (ok & 0xFF) {
        e2 = *((char **) (*((char **) (q + 0x278)) + idx * 4));
    } else {
        e2 = 0;
    }
    if (e2 == 0) {
        return;
    }
    *((int *) (e1 + 0x148)) = (int) e2;
    *((int *) (p + 0x21B4)) = idx;
    *((int *) (p + 0x21B0)) = (int) q;
    *((int *) (p + 0x2188)) = (int) q;
    *((int *) (p + 0x2168)) = 0x4;
}

__attribute__((section(".text.func_002844C0")))
void func_002844C0(char *p, char *q, int idx)
{
    char hold[16];
    char *e1;
    char *e2;
    int cnt;
    int cnt2;
    int ok;

    if (q == 0) {
        return;
    }
    cnt = *((unsigned char *) (p + 0x2B4));
    *((int *) hold) = cnt;
    if (cnt != 0) {
        e1 = *((char **) *((char **) (p + 0x278)));
    } else {
        e1 = 0;
    }
    if (e1 == 0) {
        return;
    }
    ok = 0;
    cnt2 = *((unsigned char *) (q + 0x2B4));
    *((int *) hold) = cnt2;
    if (idx >= 0) {
        ok = idx < cnt2;
        cnt2 = 0;
    }
    if (ok & 0xFF) {
        e2 = *((char **) (*((char **) (q + 0x278)) + idx * 4));
    } else {
        e2 = 0;
    }
    if (e2 == 0) {
        return;
    }
    *((int *) (e1 + 0x148)) = (int) e2;
    *((int *) (p + 0x21B4)) = idx;
    *((int *) (p + 0x21B0)) = (int) q;
    *((int *) (p + 0x2188)) = (int) q;
    *((int *) (p + 0x2168)) = 0xC;
}

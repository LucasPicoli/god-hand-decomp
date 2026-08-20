/* sn-2.95.3-136 matched TU. */

extern float cEmManage_GetSpeedRate(void *a0);
extern void func_001F2B80(void *a0, void *a1, int a2, int a3, int t0, int t1);
extern int D_005864F0;

/* sn-2.95.3-136 matched TU. */





__attribute__((section(".text.func_001EFD70")))
void func_001EFD70(void *a0, void *a1) {
    char *s0 = (char *)a0;
    float d;
    float t;
    int mins;
    int secs;
    int hund;

    d = *(float *)(s0 + 0xB98) - cEmManage_GetSpeedRate(&D_005864F0);
    *(float *)(s0 + 0xB98) = d;
    if (d < 0.0f) {
        *(float *)(s0 + 0xB98) = 0.0f;
    }
    t = *(float *)(s0 + 0xB98);
    mins = (int)(t / 1800.0f);
    t = t - (float)(mins * 1800);
    secs = (int)(t / 30.0f);
    t = t - (float)(secs * 30);
    hund = (int)(t / 30.0f * 100.0f);
    func_001F2B80(s0 + 0x60, a1, mins, secs, hund, 1);
}

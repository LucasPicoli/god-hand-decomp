/* cygnus-2.96 matched TU. */

/* cygnus-2.96 candidate: sftim_IsGrExecTime */

extern int D_003EE278;

__attribute__((section(".text.func_0035B8C0")))
void func_0035B8C0(int p, int *out, float cur, float t)
{
    char *tim = (char *)(p + 0xD30);
    float f1 = (float)*(int *)(p + 0xAC4);
    int lim;
    int cnt;
    if (t + f1 < cur) {
        *out = 0;
        return;
    }
    if (cur <= t - f1) {
        *out = 1;
        if (*(float *)(tim + 0x2C8) == cur) {
            return;
        }
        if (*(float *)(tim + 0x2C0) == cur) {
            return;
        }
        *(float *)(tim + 0x2C0) = cur;
        *(int *)(tim + 0x2BC) = *(int *)(tim + 0x2BC) + 1;
        return;
    }
    lim = 0;
    if (D_003EE278 == 0xEA24) {
        if (*(int *)(p + 0x920) < 3) {
            lim = (*(int *)(tim + 0x2AC) == 1000);
        }
    }
    cnt = *(int *)(tim + 0x2BC);
    if (lim >= cnt) {
        *out = *(int *)(tim + 0x2C4);
    } else {
        if (t < cur) {
            *out = 0;
        } else {
            *out = 1;
        }
    }
    *(int *)(tim + 0x2BC) = 0;
    *(float *)(tim + 0x2C8) = cur;
    *(int *)(tim + 0x2C4) = *out;
}

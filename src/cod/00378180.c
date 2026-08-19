/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU.  fp_hazard_rules: "mtc1" */

__attribute__((section(".text.func_00378180")))
int func_00378180(short a, short *out)
{
    int v;
    int d = 360;

    v = (int)a;
    v = v % d;
    if (v >= 180) {
        v = d - v;
        d = 0;
    }
    *out = (short)(int)((float)v * 127.0f / 180.0f + 0.5f);
    return 0;
}

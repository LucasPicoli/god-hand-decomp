/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_002D9D50")))
void func_002D9D50(int unused, unsigned int frames, int *out_h, int *out_m, int *out_s) {
    int h = frames / 108000;
    unsigned int rem = frames - h * 108000;
    int m = rem / 1800;
    int s;
    rem = rem - m * 1800;
    s = rem / 30;
    if (out_h) {
        *out_h = h;
    }
    if (out_m) {
        *out_m = m;
    }
    if (out_s) {
        *out_s = s;
    }
}

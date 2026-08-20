/* sn-2.95.3-136 matched TU. */

extern void func_002D65D0(void *a0, float *a1);
extern void CustomIDWork_SetOffsetPosY(void *a0, int a1);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001F55C0")))
void func_001F55C0(void *a0, int a1, int a2, int a3) {
    float buf[2];
    char *s0 = (char *)a0;

    func_002D65D0(s0 + 0x30D0, &buf[0]);
    s0 += 0x31C8;
    func_002D65D0(s0, &buf[1]);
    CustomIDWork_SetOffsetPosY(s0, (int)(buf[0] / (float)a1 * (float)a3));
}

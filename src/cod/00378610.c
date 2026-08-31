/* sn-2.95.3-136 matched TU. */

extern void ResetChannelPairFields_37B5E0(void *a0);
extern void func_00378868(void *a0);
extern int D_003F21B8;

/* sn-2.95.3-136 matched TU. */








__attribute__((section(".text.func_00378610")))
void func_00378610(char *s0) {
    int v;

    if ((*(int *)(s0 + 0x34) & 0x120) != 0) {
        switch (*(char *)(s0 + 5)) {
        case 0:
            s0[7] = 0;
            break;
        case 1:
            s0[7] = 1;
            break;
        case 2:
            s0[7] = 2;
            break;
        case 3:
            ResetChannelPairFields_37B5E0(s0);
            break;
        case 5:
            if (D_003F21B8 == 0) {
                D_003F21B8 = func_0037DA28(func_0030F550(0x4F8));
                if (D_003F21B8 != 0) {
                    s0[4] = 0;
                }
            }
            return;
        }
        v = s0[7];
        if (func_0037A0F0(s0, *(short *)(s0 + (v << 1) + 0x16), 1) >= 0) {
            s0[4] = 0;
        }
        return;
    }
    if ((*(int *)(s0 + 0x38) & 0x1000) != 0) {
        *(unsigned char *)(s0 + 5) = *(unsigned char *)(s0 + 5) - 1;
    }
    if ((*(int *)(s0 + 0x38) & 0x4000) != 0) {
        *(unsigned char *)(s0 + 5) = *(unsigned char *)(s0 + 5) + 1;
    }
    if (*(char *)(s0 + 5) < 0) {
        s0[5] = 5;
    }
    if (*(char *)(s0 + 5) >= 6) {
        s0[5] = 0;
    }
    func_00378868(s0);
}

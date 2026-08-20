/* sn-2.95.3-136 matched TU. */

extern void func_00318700(void *a0, void *a1);
extern void func_0014A170(void *a0);

__attribute__((section(".text.func_00318570")))
void func_00318570(char *a0)
{
    char *s0 = a0;
    char buf[0x90];

    switch (*(unsigned char *)(s0 + 0x2F4)) {
    case 1:
        *(short *)(s0 + 0x4D8) = 0x12C;
        *(unsigned char *)(s0 + 0x2F4) = *(unsigned char *)(s0 + 0x2F4) + 1;
        *(int *)(*(char **)(s0 + 0xF0) + 0x0) = 0;
        *(int *)(*(char **)(s0 + 0xF0) + 0x4) = 0;
        *(float *)(*(char **)(s0 + 0xF0) + 0x8) = -150.0f;
        *(float *)(s0 + 0x130) = -180.0f;
        *(float *)(s0 + 0x134) = -30.0f;
        *(int *)(s0 + 0x138) = 0;
        /* fall through */
    case 2: {
        int t = *(unsigned short *)(s0 + 0x4D8) - 1;

        *(short *)(s0 + 0x4D8) = t;
        if ((short)t == -1) {
            *(unsigned char *)(s0 + 0x2F4) = 3;
            *(int *)(s0 + 0x250) |= 2;
        }
        break;
    }
    case 3:
        *(unsigned char *)(s0 + 0x2F4) = 4;
        *(int *)(s0 + 0x250) |= 2;
        break;
    case 0:
    case 4:
    default:
        break;
    }
    {
        char *q = *(char **)(s0 + 0x4D0);

        if (q == 0) {
            return;
        }
        func_00318700(s0, q);
        func_0014A170(s0);
        *(int *)(buf + 0x0) = 0x20;
        *(long *)(buf + 0x30) = 0x32001;
        *(int *)(buf + 0x50) = 0;
        *(int *)(buf + 0x54) = 0;
        *(int *)(buf + 0x58) = 0;
        *(float *)(buf + 0x5C) = 1.0f;
        *(float *)(buf + 0x60) = 128.0f;
        *(int *)(buf + 0x64) = 0;
        *(int *)(buf + 0x68) = 0;
        *(float *)(buf + 0x6C) = 1.0f;
        *(int *)(buf + 0x70) = 0;
        *(float *)(buf + 0x74) = 224.0f;
        *(int *)(buf + 0x78) = 0;
        *(float *)(buf + 0x7C) = 1.0f;
        *(int *)(buf + 0x88) = 0;
        *(float *)(buf + 0x80) = 128.0f;
        *(float *)(buf + 0x84) = 224.0f;
        *(float *)(buf + 0x8C) = 1.0f;
    }
}

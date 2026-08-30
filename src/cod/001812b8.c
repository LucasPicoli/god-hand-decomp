/* sn-2.95.3-136 matched TU. */

extern int cOmSub_move(void *a0);
extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned int t1);
extern char D_005FEE00[];

extern void cOmSub_initMove1_ang(void *a0, void *a1, int a2, int a3, void *t0,
                                 float f12, float f13, int t1);

extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int a4, int a5,
                              int a6, int a7);



__attribute__((section(".text.func_001812B8")))
void func_001812B8(void *a0)
{
    char *s1 = (char *)a0;
    unsigned char frame[0x30] __attribute__((aligned(16)));
    int b1, b2, b3;
    int i1, i2, i3;
    unsigned char ok1, ok2, ok3;
    int t;

    switch (*(unsigned char *)(s1 + 0x2F5)) {
    case 0:
        *(short *)(s1 + 0x608) = 0xA;
        *(int *)(s1 + 0x5B8) &= ~0x100;
        *(unsigned char *)(s1 + 0x770) = 1;
        *(unsigned char *)(s1 + 0x2F5) = 1;
        *(unsigned char *)(s1 + 0x2F6) = 0;
        *(unsigned char *)(s1 + 0x2F7) = 0;
        /* fallthrough */
    case 1: {
        int t1a;
        if (*(short *)(s1 + 0x608) >= 0)
            goto dec;
        {
            float *q = (float *)frame;
            *(int *)frame = 0;
            q[2] = 2.0943952f;
            q[3] = 1.0f;
            *(int *)(frame + 4) = 0;
            cOmSub_initMove1_ang(s1 + 0x610, s1, 1, 0xA, frame, q[0], q[0], 0);
        }
        i1 = 1;
        ok1 = ((*(int *)(frame + 0x10) = b1 = *(unsigned char *)(s1 + 0x2B4)), (i1 < b1));
        if (ok1) t1a = *(int *)(*(int *)(s1 + 0x278) + i1 * 4); else t1a = 0;
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0xDC, s1, 0, t1a, 0, 0);
        *(unsigned char *)(s1 + 0x2F5) = 2;
        *(unsigned char *)(s1 + 0x2F6) = 0;
        *(unsigned char *)(s1 + 0x2F7) = 0;
        goto dec;
    }
    case 2: {
        char *s0 = s1 + 0x610;
        if (cOmSub_move(s0) != 0)
            break;
        {
            float *q = (float *)frame;
            *(int *)frame = 0;
            q[2] = -0.17453292f;
            q[3] = 1.0f;
            *(int *)(frame + 4) = 0;
            cOmSub_initMove1_ang(s0, s1, 1, 2, frame, q[0], q[0], 0);
        }
        *(unsigned char *)(s1 + 0x2F7) = 0;
        *(unsigned char *)(s1 + 0x2F5) = 3;
        goto zero_2F6;
    }
    case 3: {
        char *s0 = s1 + 0x610;
        int t1b, t1c;
        if (cOmSub_move(s0) != 0)
            goto dec;
        {
            float *q = (float *)frame;
            *(int *)frame = 0;
            q[2] = -1.5707964f;
            q[3] = 1.0f;
            *(int *)(frame + 4) = 0;
            cOmSub_initMove1_ang(s0, s1, 2, 6, frame, q[0], q[0], 0);
        }
        i2 = 2;
        ok2 = ((*(int *)(frame + 0x20) = b2 = *(unsigned char *)(s1 + 0x2B4)), (i2 < b2));
        if (ok2) t1b = *(int *)(*(int *)(s1 + 0x278) + i2 * 4); else t1b = 0;
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0xDD, s1, 0, t1b, 0, 0);
        i3 = 2;
        ok3 = ((*(int *)(frame + 0x20) = b3 = *(unsigned char *)(s1 + 0x2B4)), (i3 < b3));
        if (ok3) t1c = *(int *)(*(int *)(s1 + 0x278) + i3 * 4); else t1c = 0;
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0xDE, s1, 0, t1c, 0, 0);
        SetEffect(1, 1, s1, 0, -1, 0xFFFFFFFFU);
        *(unsigned char *)(s1 + 0x2F5) = 4;
        *(unsigned char *)(s1 + 0x2F6) = 0;
        *(unsigned char *)(s1 + 0x2F7) = 0;
    dec:
        t = *(unsigned short *)(s1 + 0x608) - 1;
        *(short *)(s1 + 0x608) = t;
        break;
    }
    case 4:
        if (cOmSub_move(s1 + 0x610) != 0)
            break;
        *(unsigned char *)(s1 + 0x771) = 1;
        *(unsigned char *)(s1 + 0x2F5) = 5;
        *(unsigned char *)(s1 + 0x2F7) = 0;
        goto zero_2F6;
    case 5:
        *(unsigned char *)(s1 + 0x2F7) = 0;
        *(unsigned char *)(s1 + 0x2F4) = 2;
        *(unsigned char *)(s1 + 0x2F5) = 0;
    zero_2F6:
        *(unsigned char *)(s1 + 0x2F6) = 0;
        break;
    default:
        break;
    }
}

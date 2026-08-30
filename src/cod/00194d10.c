/* sn-2.95.3-136 matched TU. */

extern float DoubleFloatMinusHalf_31D020(void);
extern void cDamageUnit_SetDamageCollFlashActive(void *a0, int a1, short a2);
extern int cOmSub_move(void *a0);
extern void cOmSub_setReverse(void *a0, int a1);
extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned int t1);
extern void func_001B7EE0(void *a0, float f12);
extern char D_005FEE00[];

extern void cOmSub_initMove1_pos(void *a0, void *a1, int a2, int a3, void *t0,
                                 float f12, float f13);



extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int a4, int a5,
                              int a6, int a7);



__attribute__((section(".text.func_00194D10")))
void func_00194D10(void *a0)
{
    char *s0 = (char *)a0;
    unsigned char frame[0x20] __attribute__((aligned(16)));
    int b1, b2, b3, b4, b5, b6, b7;
    int i1, i2, i3, i4, i5, i6, i7;
    unsigned char ok1, ok2, ok3, ok4, ok5, ok6, ok7;

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int obj;
        i1 = 2;
        ok1 = ((*(int *)frame = b1 = *(unsigned char *)(s0 + 0x2B4)), (i1 < b1));
        if (ok1) obj = *(int *)(*(int *)(s0 + 0x278) + i1 * 4); else obj = 0;
        if (obj != 0) {
            int obj2;
            i2 = 2;
        ok2 = ((*(int *)frame = b2 = *(unsigned char *)(s0 + 0x2B4)), (i2 < b2));
            if (ok2) obj2 = *(int *)(*(int *)(s0 + 0x278) + i2 * 4); else obj2 = 0;
            *(float *)(s0 + 0xB08) = *(float *)(*(int *)(obj2 + 0xD0) + 4);
        }
        *(short *)(s0 + 0xAF0) = 0x1E;
        *(unsigned char *)(s0 + 0x2F6) = 1;
        *(unsigned char *)(s0 + 0xAF3) = 0;
        *(unsigned char *)(s0 + 0x2F7) = 0;
    }
    /* fallthrough */
    case 1: {
        int obj;
        int t;
        i3 = 2;
        ok3 = ((*(int *)frame = b3 = *(unsigned char *)(s0 + 0x2B4)), (i3 < b3));
        if (ok3) obj = *(int *)(*(int *)(s0 + 0x278) + i3 * 4); else obj = 0;
        if (obj != 0) {
            int s1;
            float d;
            i4 = 2;
        ok4 = ((*(int *)frame = b4 = *(unsigned char *)(s0 + 0x2B4)), (i4 < b4));
            if (ok4) s1 = *(int *)(*(int *)(s0 + 0x278) + i4 * 4); else s1 = 0;
            d = DoubleFloatMinusHalf_31D020() * 0.05f;
            *(float *)(*(int *)(s1 + 0xD0) + 4) = *(float *)(s0 + 0xB08) + d;
        }
        t = *(unsigned short *)(s0 + 0xAF0) - 1;
        *(short *)(s0 + 0xAF0) = t;
        if ((short)t >= 0)
            break;
        i5 = 2;
        ok5 = ((*(int *)frame = b5 = *(unsigned char *)(s0 + 0x2B4)), (i5 < b5));
        if (ok5) obj = *(int *)(*(int *)(s0 + 0x278) + i5 * 4); else obj = 0;
        *(float *)(*(int *)(obj + 0xD0) + 4) = *(float *)(s0 + 0xB08);
        cDamageUnit_SetDamageCollFlashActive(*(void **)(s0 + 0x608), 1, 7);
        {
            float *q = (float *)(frame + 0x10);
            *(int *)(frame + 0x10) = 0;
            q[1] = -2.2699999f;
            *(int *)(frame + 0x18) = 0;
            q[3] = 1.0f;
            cOmSub_initMove1_pos(s0 + 0x990, s0, 2, 7, q, 0.2f, 0.0f);
        }
        *(unsigned char *)(s0 + 0xAF3) = 1;
        *(unsigned char *)(s0 + 0x2F6) = 2;
        *(unsigned char *)(s0 + 0x2F7) = 0;
        break;
    }
    case 2: {
        int t1;
        if (cOmSub_move(s0 + 0x990) != 0)
            break;
        SetEffect(0x177, 1, s0, 0, -1, 0xFFFFFFFFU);
        i6 = 1;
        ok6 = ((*(int *)frame = b6 = *(unsigned char *)(s0 + 0x2B4)), (i6 < b6));
        if (ok6) t1 = *(int *)(*(int *)(s0 + 0x278) + i6 * 4); else t1 = 0;
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0xB6, s0, 0, t1, 0, 0);
        *(short *)(s0 + 0xAF0) = 0x3C;
        *(unsigned char *)(s0 + 0x2F6) = 3;
        *(unsigned char *)(s0 + 0x2F7) = 0;
        break;
    }
    case 3: {
        int t1;
        int t = *(unsigned short *)(s0 + 0xAF0) - 1;
        *(short *)(s0 + 0xAF0) = t;
        if ((short)t >= 0)
            break;
        {
            char *q = s0 + 0x990;
            *(float *)(q + 0x30) = 30.0f;
            cOmSub_setReverse(q, 1);
        }
        i7 = 1;
        ok7 = ((*(int *)frame = b7 = *(unsigned char *)(s0 + 0x2B4)), (i7 < b7));
        if (ok7) t1 = *(int *)(*(int *)(s0 + 0x278) + i7 * 4); else t1 = 0;
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0xB7, s0, 0, t1, 0, 0);
        *(unsigned char *)(s0 + 0x2F7) = 0;
        *(unsigned char *)(s0 + 0x2F6) = 4;
        break;
    }
    case 4:
        if (cOmSub_move(s0 + 0x990) != 0)
            break;
        *(unsigned char *)(s0 + 0xAF3) = 0;
        *(unsigned char *)(s0 + 0x2F6) = 5;
        *(unsigned char *)(s0 + 0x2F7) = 0;
        break;
    case 5:
        *(unsigned char *)(s0 + 0x2F6) = 0;
        *(unsigned char *)(s0 + 0x2F5) = *(unsigned char *)(s0 + 0xAF2);
        *(unsigned char *)(s0 + 0x2F7) = 0;
        break;
    default:
        break;
    }
    if (*(unsigned char *)(s0 + 0xAF3) == 1)
        func_001B7EE0(s0, 2.3f);
}

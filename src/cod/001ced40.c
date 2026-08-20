/* sn-2.95.3-136 matched TU. */

extern float cEmManage_GetSpeedRate(void *a0);
extern int D_005864F0;

/* sn-2.95.3-136 matched TU. */




static inline int GetLayerObj(char *a0, int *frame, int idx)
{
    int b;

    *frame = b = *(unsigned char *)(a0 + 0x2B4);
    if (idx >= 0 && idx < b) {
        return *(int *)(*(int *)(a0 + 0x278) + idx * 4);
    }
    return 0;
}

__attribute__((section(".text.func_001CED40")))
void func_001CED40(void *a0) {
    char *s0 = (char *)a0;
    unsigned char frame[0x10];
    float r;
    char *e;

    r = cEmManage_GetSpeedRate(&D_005864F0);
    e = (char *)GetLayerObj(s0, (int *)frame, 1);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        *(short *)(s0 + 0x56A) = 0;
        *(int *)(s0 + 0x24C) = 0;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        /* fallthrough */
    case 1:
        {
            float t;
            int fl;

            t = *(float *)(s0 + 0x24C);
            t += r * 0.1f;
            fl = *(int *)(s0 + 0x250) | 0x10;
            *(int *)(s0 + 0x250) = fl;
            *(float *)(s0 + 0x24C) = t;
            if (t > 1.0f) {
                *(float *)(s0 + 0x24C) = 1.0f;
                *(int *)(s0 + 0x250) = fl & 0xFFFFFFEF;
                *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
            }
        }
        break;
    case 2:
        *(float *)(s0 + 0x674) = 30.0f;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        /* fallthrough */
    case 3:
        {
            if (e != 0) {
                float *p;
                float t;

                p = *(float **)(e + 0xD0);
                *p = *p + r * 0.05f;
                t = *(float *)(s0 + 0x674);
                t -= r;
                *(float *)(s0 + 0x674) = t;
                if (!(t <= 0.0f)) {
                    break;
                }
            }
            *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        }
        break;
    case 4:
        *(float *)(s0 + 0x674) = 60.0f;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        /* fallthrough */
    case 5:
        {
            float t;

            t = *(float *)(s0 + 0x674);
            t -= r;
            *(float *)(s0 + 0x674) = t;
            if (t <= 0.0f) {
                *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
            }
        }
        break;
    case 6:
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        /* fallthrough */
    case 7:
        {
            float t;

            t = *(float *)(s0 + 0x24C);
            t -= r * 0.1f;
            *(int *)(s0 + 0x250) = *(int *)(s0 + 0x250) | 0x10;
            *(float *)(s0 + 0x24C) = t;
            if (t < 0.0f) {
                *(float *)(s0 + 0x24C) = 0.0f;
                *(unsigned char *)(s0 + 0x2F4) = 1;
                *(unsigned char *)(s0 + 0x2F5) = 0;
                *(unsigned char *)(s0 + 0x2F6) = 0;
                *(unsigned char *)(s0 + 0x2F7) = 0;
            }
        }
        break;
    }
}

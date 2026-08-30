/* sn-2.95.3-136 matched TU. */

extern void func_0031A0B8(char *a0, int a1);
extern void func_0031A088(char *a0, int a1);
extern int cSnd_SeCall(void *a0, int a1, short a2, int a3, int a4, int a5);
extern char D_005FEE00[];

/* sn-2.95.3-136 matched TU. */







__attribute__((section(".text.func_001E79E8")))
void func_001E79E8(void *a0)
{
    char *s0 = (char *)a0;
    char *s1;
    float v[4];
    float *p;
    int done;

    if (*(int *)(s0 + 0x0) == 0) {
        return;
    }
    switch (*(int *)(s0 + 0x4)) {
    case 0:
        v[3] = 1.0f;
        s1 = *(char **)(s0 + 0x0);
        *(int *)(s0 + 0x54) = 0;
        p = (float *)(s1 + 0x340);
        v[0] = 0.0f;
        v[1] = 0.0f;
        v[2] = 0.0f;
        if (p != v) {
            *(float *)(s1 + 0x340) = v[0];
            p[1] = v[1];
            p[2] = v[2];
        }
        func_0031A0B8(s1, 3);
        if (v[0] != 0.0f || v[1] != 0.0f || v[2] != 0.0f) {
            func_0031A088(s1, 3);
        }
        *(int *)(s0 + 0x4) = 1;
        *(int *)(s0 + 0x8) = 0;
        *(int *)(s0 + 0xC) = 0;
        break;
    case 1:
        break;
    case 2:
        s1 = *(char **)(s0 + 0x0);
        p = (float *)(s1 + 0x340);
        v[0] = 0.08726645f;
        v[3] = 1.0f;
        v[1] = 0.0f;
        v[2] = 0.0f;
        if (p != v) {
            *(float *)(s1 + 0x340) = v[0];
            p[1] = v[1];
            p[2] = v[2];
        }
        func_0031A0B8(s1, 3);
        if (v[0] != 0.0f || v[1] != 0.0f || v[2] != 0.0f) {
            func_0031A088(s1, 3);
        }
        *(int *)(s0 + 0x10) = 0x14;
        *(int *)(s0 + 0x4) = 3;
        *(int *)(s0 + 0x8) = 0;
        *(int *)(s0 + 0xC) = 0;
        cSnd_SeCall(D_005FEE00, 2, 0, *(int *)(*(char **)(s0 + 0x0) + 0xF0), 0, 0);
        /* fallthrough */
    case 3:
        if (*(int *)(s0 + 0x10) != 0) {
            *(int *)(s0 + 0x10) -= 1;
            done = 0;
        } else {
            done = 1;
        }
        if ((done & 0xFF) != 0) {
            s1 = *(char **)(s0 + 0x0);
            p = (float *)(s1 + 0x340);
            v[0] = 0.0f;
            v[3] = 1.0f;
            v[1] = 0.0f;
            v[2] = 0.0f;
            if (p != v) {
                *(float *)(s1 + 0x340) = v[0];
                p[1] = v[1];
                p[2] = v[2];
            }
            func_0031A0B8(s1, 3);
            if (v[0] != 0.0f || v[1] != 0.0f || v[2] != 0.0f) {
                func_0031A088(s1, 3);
            }
            *(float *)(*(char **)(s0 + 0x0) + 0x100) = 1.7453293f;
            *(int *)(s0 + 0xC) = 0;
            *(int *)(s0 + 0x8) = 0;
            *(int *)(s0 + 0x4) = 4;
            *(int *)(s0 + 0x54) = *(int *)(s0 + 0x54) | 1;
        }
        break;
    case 4:
        s1 = *(char **)(s0 + 0x0);
        p = (float *)(s1 + 0x340);
        v[0] = -0.08726645f;
        v[3] = 1.0f;
        v[1] = 0.0f;
        v[2] = 0.0f;
        if (p != v) {
            *(float *)(s1 + 0x340) = v[0];
            p[1] = v[1];
            p[2] = v[2];
        }
        func_0031A0B8(s1, 3);
        if (v[0] != 0.0f || v[1] != 0.0f || v[2] != 0.0f) {
            func_0031A088(s1, 3);
        }
        *(int *)(s0 + 0x10) = 0x14;
        *(int *)(s0 + 0x4) = 5;
        *(int *)(s0 + 0x8) = 0;
        *(int *)(s0 + 0xC) = 0;
        /* fallthrough */
    case 5:
        if (*(int *)(s0 + 0x10) != 0) {
            *(int *)(s0 + 0x10) -= 1;
            done = 0;
        } else {
            done = 1;
        }
        if ((done & 0xFF) != 0) {
            s1 = *(char **)(s0 + 0x0);
            p = (float *)(s1 + 0x340);
            v[0] = 0.0f;
            v[3] = 1.0f;
            v[1] = 0.0f;
            v[2] = 0.0f;
            if (p != v) {
                *(float *)(s1 + 0x340) = v[0];
                p[1] = v[1];
                p[2] = v[2];
            }
            func_0031A0B8(s1, 3);
            if (v[0] != 0.0f || v[1] != 0.0f || v[2] != 0.0f) {
                func_0031A088(s1, 3);
            }
            *(float *)(*(char **)(s0 + 0x0) + 0x100) = 0.0f;
            *(int *)(s0 + 0x4) = 0;
            *(int *)(s0 + 0x8) = 0;
            *(int *)(s0 + 0xC) = 0;
        }
        break;
    }
}

/* sn-2.95.3-136 matched TU. */

extern float func_003A1648(float a0);
extern float func_003A1C78(float a0);
extern float D_0061B5C0[];

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_002DA7A8")))
float func_002DA7A8(float *a0, float *a1, float a2) {
    float dz;
    float dx;
    float r;
    float v;

    dz = a1[2] - a0[2];
    dx = a1[0] - a0[0];
    if (dz != 0.0f) {
        r = func_003A1648(dx / dz);
        if (dz < 0.0f) {
            r = r - 3.14159274f;
        }
    } else if (0.0f < dx) {
        r = 1.57079637f;
    } else {
        r = -1.57079637f;
    }
    v = r - a2;
    if (3.14159274f < v) {
        v = v - 6.28318548f;
    }
    if (v < -3.14159274f) {
        v = v + 6.28318548f;
    }
    return v;
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_002E8038")))
void func_002E8038(void *a0, float a1) {
    char *s1 = (char *)a0;
    float sum;
    float t;
    unsigned int i;

    sum = 0.0f;
    for (i = 0; i < *(unsigned int *)(s1 + 0x2BC); i++) {
        t = func_003A1C78((float)(i * i) * -0.5f / a1);
        D_0061B5C0[i] = t;
        if (i == 0) {
            sum += D_0061B5C0[0];
        } else {
            sum += t + t;
        }
    }
    for (i = 0; i < *(unsigned int *)(s1 + 0x2BC); i++) {
        D_0061B5C0[i] = D_0061B5C0[i] / sum;
    }
}

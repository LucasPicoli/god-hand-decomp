/* sn-2.95.3-136 matched TU. */

extern float D_0041E880[];

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_00146190")))
void func_00146190(void *arg) {
    char *p = (char *)arg;
    float d;
    unsigned short i;
    char *base;
    char *base2;
    int k;

    switch (*(short *)(p + 0x420)) {
    case 0:
        *(short *)(p + 0x420) = *(unsigned short *)(p + 0x420) + 1;
        *(float *)(p + 0x338) = 1.0f;
        break;
    case 1:
        *(float *)(p + 0x338) = *(float *)(p + 0x338) * 0.3f;
        for (i = 0; i < 5; i++) {
            k = i * 20;
            base = p + 0x98;
            *(float *)(*(char **)(base + k) + 0x44) = *(float *)(p + 0x338);
            *(float *)(*(char **)(base + k) + 0x40) = *(float *)(p + 0x338);
        }
        if (*(float *)(p + 0x338) < 0.01f) {
            *(short *)(p + 0x420) = *(unsigned short *)(p + 0x420) + 1;
        }
        break;
    case 2:
        for (i = 0; i < 4; i++) {
            k = i * 20;
            base2 = p + 0x94;
            d = D_0041E880[i] / 3.0f;
            *(float *)(*(char **)(base2 + k) + 0x40) =
                *(float *)(*(char **)(base2 + k) + 0x40) - d;
            *(float *)(*(char **)(base2 + k) + 0x44) =
                *(float *)(*(char **)(base2 + k) + 0x44) - d;
            if (*(float *)(*(char **)(base2 + k) + 0x40) < 0.001f) {
                *(int *)(p + 0x90) &= ~0x40000000u;
                *(int *)(p + 0x90) &= ~0x20000000u;
                *(short *)(p + 0x420) = 0;
                *(short *)(p + 0x41E) = 0;
            }
        }
        break;
    }
}

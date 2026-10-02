/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern void SetPositionMulti_12CE60(char *a0, float *a1);
extern int Circle_line2(char *a0, int x, float f1, int a2, int a3);

__attribute__((section(".text.pl00_lookCliff")))
void pl00_lookCliff(char *a0, float *a1, float a2) {
    float *p = (float*)(a0 + 0x660);
    int r = 0x35;
    if (p != a1) {
        *(float*)(a0 + 0x660) = a1[0];
        p[1] = a1[1];
        p[2] = a1[2];
    }
    *(float*)(a0 + 0x670) = a2;
    *(char*)(a0 + 0x2F5) = r;
    *(char*)(a0 + 0x2F4) = 0;
    *(char*)(a0 + 0x2F6) = 0;
    *(char*)(a0 + 0x2F7) = 0;
}

__attribute__((section(".text.SetPositionMulti_12CE60")))
void SetPositionMulti_12CE60(char *a0, float *a1) {
    float *q = *(float**)(a0 + 0xF0);
    float *p;
    if (q != a1) {
        q[0] = a1[0];
        q[1] = a1[1];
        q[2] = a1[2];
    }
    p = (float*)(a0 + 0x490);
    if (p != a1) {
        *(float*)(a0 + 0x490) = a1[0];
        p[1] = a1[1];
        p[2] = a1[2];
    }
    *(float*)(a0 + 0xB0) = a1[0];
    *(float*)(a0 + 0xB4) = a1[1];
    *(float*)(a0 + 0xB8) = a1[2];
    {
        char *r = *(char**)(a0 + 0x68C);
        if (r) {
            *(int*)(r + 0x2F0) |= 1;
        }
    }
}

__attribute__((section(".text.Forward15F2A8_133B28")))
void Forward15F2A8_133B28(char *a0, int a1) {
    Circle_line2(a0 + 0x60, a1, *(float*)(a0 + 0x70), 1, 1);
}

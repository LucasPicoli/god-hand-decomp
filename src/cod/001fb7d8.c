/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_003BA550")))
void func_003BA550(void *a0) {
    char *p = *(char **)((char *)a0 + 0x8);
    unsigned int t;
    p[0] = 0x72;
    p[1] = -8;
    p[2] = 0x1F;
    p[3] = 0x4E;
    p[4] = 1;
    p[5] = *(unsigned char *)((char *)a0 + 0x38);
    t = *(int *)((char *)a0 + 0x34) * 8;
    t = t & 0xFFFF;
    p[6] = (char)t;
    p[7] = (char)(t >> 8);
}

__attribute__((section(".text.ESLib_ESHermite")))
float ESLib_ESHermite(float t, float p0, float p1, float m0, float m1)
{
    float t2 = t * t;
    float t3 = t2 * t;
    float a = t2 * 3.0f;
    float b = t3 + t3;
    float c = t3 - t2;
    float h00 = b - a;
    float h01 = -b + a;
    float h10 = (c - t2) + t;
    return (h00 * p0 + p0) + p1 * h01 + m0 * h10 + m1 * c;
}

__attribute__((section(".text.cCoreSave_setCombo")))
void cCoreSave_setCombo(int *a0, unsigned int a1, unsigned int a2, int a3, int a4)
{
    char v = (char)a4;
    unsigned int k;
    if (*a0 == 0) return;
    if (a2 >= 6) return;
    if (a1 >= 6) return;
    k = a1 * 0x24;
    *(int *)(*a0 + (a2 * 4 + k) + 0x1B0) = a3;
    *(char *)(*a0 + (a2 + k) + 0x1C8) = v;
}

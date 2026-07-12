/* sn-2.95.3-136 matched TU. */

extern void sceVu0ScaleVector(void *dst, void *src, float s);
extern void sceVu0Normalize(void *dst, void *src);
extern void sceVu0TransposeMatrix(void *dst, void *src);

__attribute__((section(".text.sceVu0NormalLightMatrix")))
void sceVu0NormalLightMatrix(void *dst, void *v1, void *v2, void *v3) {
    float tmp[4];
    float *m = (float *)dst;
    sceVu0ScaleVector(tmp, v1, -1.0f);
    sceVu0Normalize(dst, tmp);
    sceVu0ScaleVector(tmp, v2, -1.0f);
    sceVu0Normalize((char *)dst + 0x10, tmp);
    sceVu0ScaleVector(tmp, v3, -1.0f);
    sceVu0Normalize((char *)dst + 0x20, tmp);
    {
        float z = 0.0f, o = 1.0f;
        m[0xF] = o; m[0xE] = z; m[0xD] = z; m[0xC] = z;
    }
    sceVu0TransposeMatrix(dst, dst);
}

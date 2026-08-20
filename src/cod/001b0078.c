/* sn-2.95.3-136 matched TU. */

extern void cOmBase_setMeshColorFromLayer(void *a0, int a1, float r, float g, float b);

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

__attribute__((section(".text.func_001B0078")))
void func_001B0078(char *a0)
{
    unsigned char frame[0x10];
    float ratio;
    float c;
    int o1;
    int o2;

    ratio = (float)*(short *)(a0 + 0x54A) / (float)*(short *)(a0 + 0x548);
    o1 = GetLayerObj(a0, (int *)frame, 1);
    if (o1 != 0) {
        o2 = GetLayerObj(a0, (int *)frame, 1);
        *(float *)(*(int *)(o2 + 0xD0) + 4) = *(float *)(a0 + 0x60C) - ratio * 0.4f;
    }
    c = ratio * 0.5f + 0.5f;
    cOmBase_setMeshColorFromLayer(a0, 0, 1.0f, c, c);
}

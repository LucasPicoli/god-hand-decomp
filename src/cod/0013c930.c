/* SN ProDG ee-gcc 2.95.3 matched TU. */

__attribute__((section(".text.ResetBlendFields_13C930")))
void ResetBlendFields_13C930(char *a0) {
    *(float *)(a0 + 0xA4) = 1.0f;
    *(int *)(a0 + 0x94) = 0;
    *(int *)(a0 + 0x9C) = 0;
    *(int *)(a0 + 0xA0) = 0;
    *(int *)(a0 + 0xB8) = 0;
}

__attribute__((section(".text.MtxInitTransVec")))
void MtxInitTransVec(float *a0, float *a1) {
    a0[1] = 0.0f;
    a0[0] = 1.0f;
    a0[2] = 0.0f;
    a0[3] = 0.0f;
    a0[4] = 0.0f;
    a0[5] = 1.0f;
    a0[6] = 0.0f;
    a0[7] = 0.0f;
    a0[8] = 0.0f;
    a0[9] = 0.0f;
    a0[10] = 1.0f;
    a0[11] = 0.0f;
    a0[12] = a1[0];
    a0[13] = a1[1];
    a0[14] = a1[2];
    a0[15] = 1.0f;
}

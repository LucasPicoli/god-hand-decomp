/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);

/* sn-2.95.3-136 matched TU. */







__attribute__((section(".text.func_002457D0")))
void func_002457D0(void *a0)
{
    char *s0 = (char *)a0;

    *(int *)(s0 + 0x250) |= 0x10000;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        char *v0 = *(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x23D8) + (int)v0,
                      *(int *)(v0 + 0x23DC) + (int)v0, 0.0f, 3, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1:
        *(float *)(s0 + 0x54C) = 3.0f;
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) += 1;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 2: {
        char *v0 = *(char **)(s0 + 0x304);
        int flags;
        func_002A8578(s0, *(int *)(v0 + 0x23E0) + (int)v0,
                      *(int *)(v0 + 0x23E4) + (int)v0, 0.0f, 0, 0, 0);
        *(unsigned char *)(s0 + 0x17BE) = *(unsigned char *)(s0 + 0x17BE) + 1;
        flags = *(int *)(s0 + 0x16D4) & 0xFFFEFC7F;
        *(int *)(s0 + 0x16D4) = flags;
        *(unsigned char *)(s0 + 0x17BE) =
            (unsigned int)*(unsigned char *)(s0 + 0x17BE) % 3;
        switch (*(unsigned char *)(s0 + 0x17BE)) {
        case 0:
            break;
        case 1:
            *(int *)(s0 + 0x16D4) = flags | 0x80;
            if (*(int *)(s0 + 0x564) == 0x276) {
                *(int *)(s0 + 0x16D4) = flags | 0x280;
            }
            break;
        case 2:
            *(int *)(s0 + 0x16D4) = flags | 0x100;
            if (*(int *)(s0 + 0x564) == 0x276) {
                *(int *)(s0 + 0x16D4) = flags | 0x300;
            }
            break;
        }
        *(unsigned char *)(s0 + 0x1869) = 4;
        *(int *)(s0 + 0x17A8) = 0;
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 3:
        *(float *)(s0 + 0x54C) = 2.0f;
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) += 1;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 4: {
        char *v0 = *(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x2388) + (int)v0,
                      *(int *)(v0 + 0x238C) + (int)v0, 0.0f, 0, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 5:
        if (moveMotion(s0) != 0) {
            func_002705D8(s0);
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    }
}

/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

extern float cEmManage_GetSpeedRate(void *a0);
extern void SetField444SignedByFlag434_158288(void *a0, float f);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void InitRenderStruct_2A8608(void *a0, int a1, int a2, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int D_005864F0;

__attribute__((section(".text.func_001CB400")))
void func_001CB400(void *a0) {
    char *s0 = (char *)a0;
    float r = cEmManage_GetSpeedRate(&D_005864F0);
    char *p = *(char **)(s0 + 0x600);
    if (p != 0) {
        r = *(float *)(p + 0x5A8);
    }
    *(float *)(s0 + 0x5A8) = r;
    SetField444SignedByFlag434_158288(s0, r);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0xC) + v, 0, 0.0f, 0, 0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_mm;
    case 2:
        {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x10) + v, 0, 0.0f, 0, 0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_mm;
    case 4:
        {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x14) + v, 0, 0.0f, 0, 0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_rs;
    case 6:
        {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x18) + v, 0, 0.0f, 0, 0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_mm;
    case 8:
        {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x44) + v, 0, 0.0f, 0, 0, 0);
            InitRenderStruct_2A8608(s0, 0x6F, 0xC, 0, 2, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_mm;
    case 10:
        if (*(unsigned char *)(s0 + 0x2F7) != 0) {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x1C) + v, *(int *)(v + 0x20) + v, 0.0f, 0, 0, 0);
        } else {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x1C) + v, 0, 0.0f, 0, 0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_mm;
    case 12:
        if (*(unsigned char *)(s0 + 0x2F7) != 0) {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x24) + v, *(int *)(v + 0x28) + v, 0.0f, 0, 0, 0);
            InitRenderStruct_2A8608(s0, 0x6F, 0xB, 0, 2, 0);
        } else {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x24) + v, 0, 0.0f, 0, 0, 0);
            InitRenderStruct_2A8608(s0, 0x6F, 0xA, 0, 2, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_rs;
    case 14:
        if (*(unsigned char *)(s0 + 0x2F7) != 0) {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x30) + v, 0, 0.0f, 0, 0, 0);
        } else {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x34) + v, 0, 0.0f, 0, 0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_mm;
    case 16:
        {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x38) + v, 0, 0.0f, 0, 0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
    case 3:
    case 7:
    case 9:
    case 11:
    case 15:
    case 17:
    L_mm:
        moveMotion(s0);
        break;
    case 18:
        {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x3C) + v, 0, 0.0f, 0, 0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 19:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = 2;
        }
        break;
    case 20:
        {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x40) + v, 0, 0.0f, 0, 0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_rs;
    case 22:
        {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x2C) + v, 0, 0.0f, 0, 0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_rs;
    case 24:
        {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x50) + v, 0, 0.0f, 0, 0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_rs;
    case 26:
        if (*(unsigned char *)(s0 + 0x2F7) != 0) {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x48) + v, *(int *)(v + 0x4C) + v, 0.0f, 0, 0, 0);
            InitRenderStruct_2A8608(s0, 0x6F, 0xF, 0, 2, 0);
        } else {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x48) + v, 0, 0.0f, 0, 0, 0);
            InitRenderStruct_2A8608(s0, 0x6F, 0xE, 0, 2, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_rs;
    case 28:
        {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x58) + v, 0, 0.0f, 0, 0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 5:
    case 13:
    case 21:
    case 23:
    case 25:
    case 27:
    case 29:
    L_rs:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = 0;
        }
        break;
    }
}

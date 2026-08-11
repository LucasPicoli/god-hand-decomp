/* sn-2.95.3-136 matched TU. */

extern float cEmManage_GetSpeedRate(void *a0);
extern void SetField444SignedByFlag434_158288(void *a0, float f);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void InitRenderStruct_2A8608(void *a0, int a1, int a2, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int D_005864F0;

/* func_001CB030 — refresh the +0x5A8 speed-rate field from the +0x600 owner, then a
 * 16-phase +0x2F6 machine over record +0x304.  sn-2.95.3-136. */







__attribute__((section(".text.func_001CB030")))
void func_001CB030(void *a0) {
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
            *(int *)(s0 + 0x250) |= 0x40000;
            func_002A8578(s0, *(int *)(v + 0xC) + v, 0, 0.0f, 0, 0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        moveMotion(s0);
        break;
    case 2:
        if (*(unsigned char *)(s0 + 0x2F7) != 0) {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x14) + v, *(int *)(v + 0x18) + v, 0.0f, 0, 0, 0);
            InitRenderStruct_2A8608(s0, 0x58, 0x65, 0, 2, 0);
        } else {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x14) + v, 0, 0.0f, 0, 0, 0);
            InitRenderStruct_2A8608(s0, 0x58, 0x64, 0, 2, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_mm;
    case 4:
        if (*(unsigned char *)(s0 + 0x2F7) != 0) {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x1C) + v, *(int *)(v + 0x20) + v, 0.0f, 0, 0, 0);
            InitRenderStruct_2A8608(s0, 0x58, 0x63, 0, 2, 0);
        } else {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x1C) + v, 0, 0.0f, 0, 0, 0);
            InitRenderStruct_2A8608(s0, 0x58, 0x62, 0, 2, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_mm;
    case 6:
        if (*(unsigned char *)(s0 + 0x2F7) != 0) {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x24) + v, *(int *)(v + 0x28) + v, 0.0f, 0, 0, 0);
            InitRenderStruct_2A8608(s0, 0x58, 0x78, 0, 2, 0);
        } else {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x24) + v, 0, 0.0f, 0, 0, 0);
            InitRenderStruct_2A8608(s0, 0x58, 0x77, 0, 2, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_mm;
    case 8:
        if (*(unsigned char *)(s0 + 0x2F7) != 0) {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x34) + v, *(int *)(v + 0x38) + v, 0.0f, 0, 0, 0);
        } else {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x34) + v, 0, 0.0f, 0, 0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_mm;
    case 10:
        {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x3C) + v, 0, 0.0f, 0, 0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_mm;
    case 12:
        if (*(unsigned char *)(s0 + 0x2F7) != 0) {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x2C) + v, *(int *)(v + 0x30) + v, 0.0f, 0, 0, 0);
        } else {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x2C) + v, 0, 0.0f, 0, 0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_mm;
    case 14:
        if (*(unsigned char *)(s0 + 0x2F7) != 0) {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x40) + v, *(int *)(v + 0x44) + v, 0.0f, 0, 0, 0);
            InitRenderStruct_2A8608(s0, 0x58, 0x94, 0, 2, 0);
        } else {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x40) + v, 0, 0.0f, 0, 0, 0);
            InitRenderStruct_2A8608(s0, 0x58, 0x93, 0, 2, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 3:
    case 5:
    case 7:
    case 9:
    case 11:
    case 13:
    case 15:
    L_mm:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = 0;
        }
        break;
    }
}

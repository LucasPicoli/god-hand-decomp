/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002744E0(void *a0);

/* sn-2.95.3-136 matched TU. */






__attribute__((section(".text.func_00246D18")))
void func_00246D18(void *a0) {
    char *s0 = (char *)a0;
    int v0;
    int n;

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        *(char *)(s0 + 0x1864) = 0;
        n = Obj0000_Get_Byte_17C3_NZ_2_276468(s0);
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x98) + v0, *(int *)(v0 + 0x9C) + v0, 0.0f, 0xA, n & 0xFFFF, 0);
        *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) & 0xDFFFFFFF;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        moveMotion(s0);
        if ((*(int *)(s0 + 0x16D0) & 0x20000000) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        }
        break;
    case 2:
        *(char *)(s0 + 0x1864) = 0;
        n = Obj0000_Get_Byte_17C3_NZ_2_276468(s0);
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x3CC) + v0, *(int *)(v0 + 0x3D0) + v0, 0.0f, 0x6, n & 0xFFFF, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 3:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        }
        break;
    case 4:
        *(char *)(s0 + 0x1864) = 0;
        n = Obj0000_Get_Byte_17C3_NZ_2_276468(s0);
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x98) + v0, *(int *)(v0 + 0x9C) + v0, 0.0f, 0xA, n & 0xFFFF, 0);
        *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) & 0xDFFFFFFF;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 5:
        moveMotion(s0);
        if ((*(int *)(s0 + 0x16D0) & 0x20000000) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        }
        break;
    case 6:
        *(char *)(s0 + 0x1864) = 0;
        n = Obj0000_Get_Byte_17C3_NZ_2_276468(s0);
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x3E4) + v0, *(int *)(v0 + 0x3E8) + v0, 0.0f, 0x6, n & 0xFFFF, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 7:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = 4;
        }
        break;
    }

    if ((*(unsigned short *)(s0 + 0x3AC) & 3) != 0) {
        if (*(int *)(s0 + 0x5F0) != 0) {
            *(int *)(s0 + 0x5F0) = 0;
            func_002744E0(s0);
        }
    }
}

/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void func_00126770(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void moveMotion(void *a0);
extern void cModel_calcParts(void *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(void *a0);
extern void func_001CF3A8(void *a0);
extern void func_001269E0(void *a0, int a1, int a2);

__attribute__((section(".text.pl00_SubscreenMode")))
void pl00_SubscreenMode(void *a0, int a1) {
    char *s0 = (char *)a0;
    int v0;
    if (a1 != 0) {
        *(unsigned char *)(s0 + 0x2F4) = 5;
        *(unsigned char *)(s0 + 0x420) = *(unsigned char *)(s0 + 0x420) | 1;
        *(float *)(s0 + 0x54C) = 5.0f;
        *(unsigned char *)(s0 + 0x2F5) = 0;
        *(unsigned char *)(s0 + 0x2F6) = 0;
        *(unsigned char *)(s0 + 0x2F7) = 0;
    } else {
        *(unsigned char *)(s0 + 0x420) = *(unsigned char *)(s0 + 0x420) & 0xFE;
        pl00_clearMotionCam(s0, 0, 0);
        func_00126770(s0);
        v0 = *(int *)(s0 + 0x304);
        *(unsigned char *)(s0 + 0x2F4) = 0;
        *(unsigned char *)(s0 + 0x2F5) = 0;
        *(unsigned char *)(s0 + 0x2F6) = 0;
        *(unsigned char *)(s0 + 0x2F7) = 0;
        func_002A8578(s0, *(int *)(v0 + 0x28) + v0, *(int *)(v0 + 0x2C) + v0, 0.0f, 0, 0, 0);
        moveMotion(s0);
        cModel_calcParts(s0);
        IK_InverseKinematics(s0 + 0x448, s0);
        cModel_calcWorldParts(s0);
        if (*(int *)(s0 + 0x6A8) != 0) {
            func_001CF3A8(*(void **)(s0 + 0x6A8));
            cModel_calcParts(*(void **)(s0 + 0x6A8));
        }
    }
}

__attribute__((section(".text.pl00_SubscreenMotSet")))
void pl00_SubscreenMotSet(void *a0, int a1) {
    char *s0 = (char *)a0;
    func_001269E0(s0, a1, 1);
    *(unsigned char *)(s0 + 0x2F4) = 5;
    *(unsigned char *)(s0 + 0x2F6) = 2;
    *(unsigned char *)(s0 + 0x2F5) = 0;
    *(unsigned char *)(s0 + 0x2F7) = 0;
}

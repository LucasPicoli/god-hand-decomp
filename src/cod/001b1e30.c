/* sn-2.95.3-136 matched TU. */

extern float Adjust_theta(float);
extern int moveMotion(int *);
extern void cOm71_SetMotionRun(int *);
extern void AddScaledVecToField_100_14F9F0(int *, float);
extern void AddScaledXfmVecToField_F0_14F928(int *, float);
extern void func_001DBEB0(void);
extern void func_001DD340(char *a0);
extern void func_001DD218(char *a0, int a1);
extern int GetTimerValue_1FA710(int *a0);
extern void func_001DD238(char *a0, int a1);
extern void SetCustomIDNumberIndexed_1DD648(char *a0, int a1, int a2);
extern void func_001DEE60(char *a0, int a1, int a2);
extern int D_00569B70;

__attribute__((section(".text.func_001D0CE8")))
void func_001D0CE8(int *a0) {
    int *s0 = a0;
    long f = *(unsigned int *)((char *)s0 + 4);
    int p1, p2, p3, p4;
    float r;
    if (((f >> 1) & 1) == 0) {
        if (((f >> 2) & 1) == 0) return;
        p1 = s0[0];
        *(float *)(p1 + 0x104) += 0.15707963705062866f;
        p2 = s0[0];
        r = Adjust_theta(*(float *)(p2 + 0x104));
        p3 = s0[0];
        *(float *)(p3 + 0x104) = r;
        p4 = s0[0];
        if (0.0f <= *(float *)(p4 + 0x104)) {
            *(float *)(p4 + 0x104) = 0.0f;
            *(int *)((char *)s0 + 4) = (*(int *)((char *)s0 + 4) | 2) & -5;
        }
    }
}

__attribute__((section(".text.func_001D6E20")))
void func_001D6E20(int *a0) {
    int *s0 = a0;
    long f = *(unsigned int *)((char *)s0 + 4);
    int p1, p2, p3, p4;
    float r;
    if (((f >> 3) & 1) == 0) {
        if (((f >> 4) & 1) == 0) return;
        p1 = s0[0];
        *(float *)(p1 + 0x104) += 0.20943951606750488f;
        p2 = s0[0];
        r = Adjust_theta(*(float *)(p2 + 0x104));
        p3 = s0[0];
        *(float *)(p3 + 0x104) = r;
        p4 = s0[0];
        if (0.0f <= *(float *)(p4 + 0x104)) {
            *(float *)(p4 + 0x104) = 0.0f;
            *(int *)((char *)s0 + 4) = (*(int *)((char *)s0 + 4) | 8) & -0x11;
        }
    }
}

__attribute__((section(".text.func_001D0DF8")))
void func_001D0DF8(int *a0) {
    int *s0 = a0;
    long f = *(unsigned int *)((char *)s0 + 4);
    int p1, p2, p3, p4;
    float r;
    if (((f >> 1) & 1) == 0) return;
    if (((f >> 2) & 1) == 0) return;
    p1 = s0[0];
    *(float *)(p1 + 0x104) += 0.15707963705062866f;
    p2 = s0[0];
    if (3.1415927410125732f <= *(float *)(p2 + 0x104)) {
        *(float *)(p2 + 0x104) = 3.1415927410125732f;
        *(int *)((char *)s0 + 4) &= -3;
        *(int *)((char *)s0 + 4) &= -5;
    }
    p3 = s0[0];
    r = Adjust_theta(*(float *)(p3 + 0x104));
    p4 = s0[0];
    *(float *)(p4 + 0x104) = r;
}

__attribute__((section(".text.func_001D6F30")))
void func_001D6F30(int *a0) {
    int *s0 = a0;
    long f = *(unsigned int *)((char *)s0 + 4);
    int p1, p2, p3, p4;
    float r;
    if (((f >> 3) & 1) == 0) return;
    if (((f >> 4) & 1) == 0) return;
    p1 = s0[0];
    *(float *)(p1 + 0x104) += 0.20943951606750488f;
    p2 = s0[0];
    if (3.1415927410125732f <= *(float *)(p2 + 0x104)) {
        *(float *)(p2 + 0x104) = 3.1415927410125732f;
        *(int *)((char *)s0 + 4) &= -9;
        *(int *)((char *)s0 + 4) &= -0x11;
    }
    p3 = s0[0];
    r = Adjust_theta(*(float *)(p3 + 0x104));
    p4 = s0[0];
    *(float *)(p4 + 0x104) = r;
}

__attribute__((section(".text.func_001B1E30")))
void func_001B1E30(int *a0) {
    int *s0 = a0;
    long m;
    *(int *)((char *)s0 + 0x600) &= -0x101;
    if (moveMotion(s0) != 0) {
        m = *(unsigned int *)((char *)s0 + 0x600);
        if (((m >> 3) & 1) == 0) goto L88;
        *(int *)((char *)s0 + 0x600) &= -9;
        cOm71_SetMotionRun(s0);
    L88:
        *(int *)((char *)s0 + 0x600) |= 0x100;
    }
    AddScaledVecToField_100_14F9F0(s0, 1.0f);
    m = *(unsigned int *)((char *)s0 + 0x600);
    if (((m >> 7) & 1) == 0) {
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
    }
}

__attribute__((section(".text.func_001D7450")))
void func_001D7450(char *a0)
{
    long v;

    *(int *)(a0 + 0x3034) = 0;
    *(int *)(a0 + 0x3038) = 0;
    func_001DBEB0();
    func_001DD340(a0);
    func_001DD218(a0, *(int *)(a0 + 0x3034));
    func_001DD238(a0, GetTimerValue_1FA710(&D_00569B70));
    SetCustomIDNumberIndexed_1DD648(a0, 0, 0x32);
    SetCustomIDNumberIndexed_1DD648(a0, 1, 0x14);
    SetCustomIDNumberIndexed_1DD648(a0, 2, 0xF);
    SetCustomIDNumberIndexed_1DD648(a0, 3, 0xA);
    SetCustomIDNumberIndexed_1DD648(a0, 4, 8);
    SetCustomIDNumberIndexed_1DD648(a0, 5, 8);
    SetCustomIDNumberIndexed_1DD648(a0, 6, 3);
    SetCustomIDNumberIndexed_1DD648(a0, 7, 2);
    func_001DEE60(a0 + 0x25B0, 0x11, 0);

    v = *(unsigned int *)(a0 + 0x3020);
    if (((v >> 3) & 1) == 0) {
        *(a0 + 0x3025) = 0;
        *(a0 + 0x3024) = 1;
    } else {
        *(a0 + 0x3025) = 0;
        *(a0 + 0x3024) = 2;
    }
    *(int *)(a0 + 0x3020) = 0;
}

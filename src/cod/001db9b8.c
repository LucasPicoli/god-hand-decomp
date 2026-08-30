/* sn-2.95.3-136 matched TU. */

extern void cSnd_SetBgmState(void *a0, int a1);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void func_001DF358(void *a0, int a1);
extern void func_001DF198(void *a0, int a1);
extern void func_001DF278(void *a0, int a1);
extern void func_001DF428(void *a0, int a1);
extern void SetCustomIDNumberIndexed_1DD648(void *a0, int a1, int a2);
extern void func_001DD5A0(void *a0, int a1);
extern void func_001DE088(void *a0, int a1);
extern void func_001DE170(void *a0, int a1);
extern void func_001DE258(void *a0, int a1);
extern void func_001DE340(void *a0, int a1);
extern void func_001DE428(void *a0, int a1);
extern void func_001DE4F8(void *a0, int a1);
extern void func_001DE7C8(void *a0, int a1);
extern void CustomIDWork_SetNumber_1DD218(void *a0, int a1);
extern void func_001DD770(void *a0, int a1);
extern void func_001DD840(void *a0, int a1);
extern void func_001DD910(void *a0, int a1);
extern void func_001DD9E0(void *a0, int a1);
extern unsigned char D_005FEE00[];
extern float D_005681C0[];

/* sn-2.95.3-136 matched TU. */
























static inline unsigned char DecCount(int *p)
{
    if (*p == 0) {
        return 1;
    }
    *p = *p - 1;
    return 0;
}

__attribute__((section(".text.func_001DB9B8")))
void func_001DB9B8(void *a0)
{
    char *s1 = (char *)a0;

    switch (*(unsigned char *)(s1 + 0x3025)) {
    case 0:
        cSnd_SetBgmState(&D_005FEE00, 0);
        *(int *)(s1 + 0x3028) = 0x1E;
        *(unsigned char *)(s1 + 0x3025) += 1;
        break;
    case 1:
        if (DecCount((int *)(s1 + 0x3028)) == 0) {
            break;
        }
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, *(void **)(*(int *)(s1 + 0x3004)), 0, 0, 0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, *(void **)(*(int *)(s1 + 0x3008)), 0, 0, 0, 0);
        {
            unsigned char c = *(unsigned char *)(s1 + 0x3025);
            do { *(int *)(s1 + 0x302C) = 0xF; } while (0);
            *(unsigned char *)(s1 + 0x3025) = c + 1;
        }
        break;
    case 2: {
        float d;
        char *p;
        int n;
        d = -((15.0f - (float)*(int *)(s1 + 0x302C)) / 15.0f);
        *(float *)(*(int *)(**(int **)(s1 + 0x3004) + 0xF0)) = d + D_005681C0[0];
        *(float *)(*(int *)(**(int **)(s1 + 0x3008) + 0xF0)) = d + D_005681C0[4];
        n = *(int *)(s1 + 0x302C);
        if (n == 0) {
            p = s1 + 0x25B0;
            func_001DF358(p, 3);
            func_001DF198(p, 3);
            func_001DF278(p, 3);
            func_001DF428(p, 3);
            *(int *)(s1 + 0x3028) = 0x14;
            *(unsigned char *)(s1 + 0x3025) += 1;
        } else {
            *(int *)(s1 + 0x302C) = n - 1;
        }
        break;
    }
    case 3:
        if (DecCount((int *)(s1 + 0x3028)) == 0) {
            break;
        }
        *(int *)(s1 + 0x3034) = 0;
        SetCustomIDNumberIndexed_1DD648(s1, 0, 0x32);
        SetCustomIDNumberIndexed_1DD648(s1, 1, 0x14);
        SetCustomIDNumberIndexed_1DD648(s1, 2, 0xF);
        SetCustomIDNumberIndexed_1DD648(s1, 3, 0xA);
        SetCustomIDNumberIndexed_1DD648(s1, 4, 8);
        SetCustomIDNumberIndexed_1DD648(s1, 5, 8);
        SetCustomIDNumberIndexed_1DD648(s1, 6, 3);
        SetCustomIDNumberIndexed_1DD648(s1, 7, 2);
        func_001DD5A0(s1, 1);
        func_001DE088(s1, 2);
        func_001DE170(s1, 2);
        func_001DE258(s1, 2);
        func_001DE340(s1, 2);
        func_001DE428(s1, 2);
        func_001DE4F8(s1, 2);
        func_001DE7C8(s1, 2);
        *(int *)(s1 + 0x3034) = 0;
        CustomIDWork_SetNumber_1DD218(s1, 0);
        func_001DD770(s1, 2);
        func_001DD840(s1, 2);
        func_001DD910(s1, 2);
        func_001DD9E0(s1, 2);
        *(int *)(s1 + 0x3028) = 0x1E;
        *(unsigned char *)(s1 + 0x3025) += 1;
        break;
    case 4:
        if (DecCount((int *)(s1 + 0x3028)) == 0) {
            break;
        }
        *(unsigned char *)(s1 + 0x3024) = 0;
        *(unsigned char *)(s1 + 0x3025) = 0;
        break;
    }
}

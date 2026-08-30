/* sn-2.95.3-136 matched TU. */

extern void CustomIDWork_SetColorAnimNormal_2D68D8(void *a0, int a1, int a2, int a3);
extern void CustomIDWork_SetScaleAnimNormal(void *a0, int a1, float a2, float a3);
extern void CustomIDWork_SetDisp(void *a0, int a1);
extern int cSnd_SeCall(void *a0, int a1, short a2, int a3, int a4, int a5);
extern void func_001ED7E0(void *a0);
extern int D_005CAFF0;
extern char D_005FEE00[];

/* sn-2.95.3-136 */










#define COL(x) ((((((((x) & ~0x00FF0000) | 0x00800000) & ~0x0000FF00) | 0x00008000) & ~0x000000FF) | 0x00000080) & ~0xFF000000)

__attribute__((section(".text.func_001ED848")))
void func_001ED848(void *a0) {
    char *s1 = (char *)a0;
    int c0, c1, c2, c3, c4, c5, c6, c7;

    long fl;
    unsigned int *flag;

    flag = (unsigned int *)s1;
    fl = *flag;
    if ((fl & 1) == 0) {
    } else {
        switch (*(int *)(s1 + 0x348)) {
        case 0: {
            char *w0 = s1 + 0x60;
            CustomIDWork_SetColorAnimNormal_2D68D8(w0, COL(c1), COL(c0) | 0x80000000, 0x14);
            CustomIDWork_SetScaleAnimNormal(w0, 0xA, 6.0f, 1.5f);
            CustomIDWork_SetDisp(w0, 1);
            *(int *)(s1 + 0x348) += 1;
            *(int *)(s1 + 0x34C) = 0x1E;
            break;
        }
        case 1:
            if (*(int *)(s1 + 0x34C) == 0) {
                char *w1;
                CustomIDWork_SetDisp(s1 + 0x60, 0);
                w1 = s1 + 0xDC;
                CustomIDWork_SetColorAnimNormal_2D68D8(w1, COL(c2), COL(c3) | 0x80000000, 0x14);
                CustomIDWork_SetScaleAnimNormal(w1, 0xA, 6.0f, 1.5f);
                CustomIDWork_SetDisp(w1, 1);
                *(int *)(s1 + 0x348) += 1;
                *(int *)(s1 + 0x34C) = 0x1E;
            } else {
                if (*(int *)(s1 + 0x34C) == 0xF) {
                    cSnd_SeCall(D_005FEE00, 2, 0xB0, D_005CAFF0 + 0x210, 0, 0);
                }
                *(int *)(s1 + 0x34C) -= 1;
            }
            break;
        case 2:
            if (*(int *)(s1 + 0x34C) == 0) {
                char *w2;
                CustomIDWork_SetDisp(s1 + 0xDC, 0);
                w2 = s1 + 0x158;
                CustomIDWork_SetColorAnimNormal_2D68D8(w2, COL(c4), COL(c5) | 0x80000000, 0x14);
                CustomIDWork_SetScaleAnimNormal(w2, 0xA, 6.0f, 1.5f);
                CustomIDWork_SetDisp(w2, 1);
                *(int *)(s1 + 0x348) += 1;
                *(int *)(s1 + 0x34C) = 0x1E;
            } else {
                if (*(int *)(s1 + 0x34C) == 0xF) {
                    cSnd_SeCall(D_005FEE00, 2, 0xB0, D_005CAFF0 + 0x210, 0, 0);
                }
                *(int *)(s1 + 0x34C) -= 1;
            }
            break;
        case 3:
            if (*(int *)(s1 + 0x34C) == 0) {
                CustomIDWork_SetDisp(s1 + 0x158, 0);
                CustomIDWork_SetDisp(s1 + 0x1D4, 1);
                *(int *)(s1 + 0x348) += 1;
                *(int *)(s1 + 0x34C) = 0x1E;
            } else {
                if (*(int *)(s1 + 0x34C) == 0xF) {
                    cSnd_SeCall(D_005FEE00, 2, 0xB0, D_005CAFF0 + 0x210, 0, 0);
                }
                *(int *)(s1 + 0x34C) -= 1;
            }
            break;
        case 4:
            if (*(int *)(s1 + 0x34C) == 0) {
                CustomIDWork_SetColorAnimNormal_2D68D8(s1 + 0x1D4, COL(c6) | 0x80000000, COL(c7), 0xA);
                *(int *)(s1 + 0x348) += 1;
                *(int *)(s1 + 0x34C) = 0xA;
            } else {
                if (*(int *)(s1 + 0x34C) == 0x14) {
                    cSnd_SeCall(D_005FEE00, 2, 0xB1, D_005CAFF0 + 0x210, 0, 0);
                }
                *(int *)(s1 + 0x34C) -= 1;
            }
            break;
        case 5:
            if (*(int *)(s1 + 0x34C) == 0) {
                func_001ED7E0(s1);
            } else {
                *(int *)(s1 + 0x34C) -= 1;
            }
            break;
        }
    }
}

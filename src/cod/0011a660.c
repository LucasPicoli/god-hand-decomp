/* sn-2.95.3-136 matched TU. */

extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void func_002A8578(void *a0, int a1, int a2, float f12, int a3, int t0, int t1);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern int moveMotion(void *a0);
extern void func_0012C540(void *a0, int a1);
extern int D_00462FC0;

/* sn-2.95.3-136 candidate. */









__attribute__((section(".text.func_0011A660")))
void func_0011A660(void *a0)
{
    char *s0 = (char *)a0;

    Forward_001346C8_00134608_1351D8(&D_00462FC0, s0, 0);
    *(float *)(s0 + 0x54C) = 2.0f;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        int b = *(int *)(s0 + 0x304);

        *(short *)(s0 + 0x5E0) = 0;
        *(short *)(s0 + 0x5E2) = 0;
        func_002A8578(s0, *(int *)(b + 0x6F0) + b, *(int *)(b + 0x6F4) + b,
                      0.0f, 3, 0, 0);
        CallWithAndClearField698_12AC28(s0);
        func_0012B928(s0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    case 1:
        if (moveMotion(s0) == 0) {
            return;
        }
        func_0012C540(s0, 1);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        *(int *)(s0 + 0x250) = *(int *)(s0 + 0x250) | 2;
        {
            char *p = *(char **)(s0 + 0x68C);

            if (p != 0) {
                *(int *)(p + 0x250) = *(int *)(p + 0x250) | 2;
            }
        }
        break;
    case 2:
    {
        int b = *(int *)(s0 + 0x304);

        func_002A8578(s0, *(int *)(b + 0x28) + b, *(int *)(b + 0x2C) + b,
                      0.0f, 3, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    case 3:
        moveMotion(s0);
        *(int *)(s0 + 0x15F4) = *(int *)(s0 + 0x15F4) | 0x1000;
        *(int *)(s0 + 0x250) = *(int *)(s0 + 0x250) | 2;
        {
            char *p = *(char **)(s0 + 0x68C);

            if (p != 0) {
                *(int *)(p + 0x250) = *(int *)(p + 0x250) | 2;
            }
        }
        break;
    case 4:
    {
        int b = *(int *)(s0 + 0x304);

        *(short *)(s0 + 0x5E0) = 0;
        *(short *)(s0 + 0x5E2) = 0;
        func_002A8578(s0, *(int *)(b + 0x6F8) + b, *(int *)(b + 0x6FC) + b,
                      0.0f, 0, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    case 5:
        if (moveMotion(s0) == 0) {
            return;
        }
        *(unsigned char *)(s0 + 0x2F4) = 0;
        *(unsigned char *)(s0 + 0x2F5) = 0;
        *(unsigned char *)(s0 + 0x2F6) = 0;
        *(unsigned char *)(s0 + 0x2F7) = 0;
        break;
    }
}

/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern int moveMotion(void *a0);

__attribute__((section(".text.func_0027F5F0")))
void func_0027F5F0(void *a0)
{
    char *s0 = (char *)a0;
    int v0;

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        switch (*(unsigned char *)(s0 + 0x2F7)) {
        default:
        case 0:
            v0 = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0x2C) + v0, *(int *)(v0 + 0x30) + v0, 5, 0.0f, 0, 0);
            break;
        case 1:
            v0 = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0x34) + v0, *(int *)(v0 + 0x38) + v0, 5, 0.0f, 0, 0);
            break;
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        moveMotion(s0);
        break;
    }
}

__attribute__((section(".text.func_0027CE70")))
void func_0027CE70(void *a0)
{
    char *s0 = (char *)a0;
    int v0;

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        switch (*(unsigned char *)(s0 + 0x2F7)) {
        default:
        case 1:
            v0 = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0x78) + v0, *(int *)(v0 + 0x7C) + v0, 0, 0.0f, 0, 0);
            break;
        case 0:
            v0 = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0x78) + v0, *(int *)(v0 + 0x7C) + v0, 0, 0.0f, 0, 0);
            break;
        case 2:
            v0 = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0x78) + v0, *(int *)(v0 + 0x7C) + v0, 0, 0.0f, 0, 0);
            break;
        }
        *(int *)(s0 + 0x15D4) = 0;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        moveMotion(s0);
        break;
    }
}

__attribute__((section(".text.func_00282120")))
void func_00282120(void *a0)
{
    char *s0 = (char *)a0;
    int v0;

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        if (*(unsigned char *)(s0 + 0x15B0)) {
            v0 = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0x8C) + v0, *(int *)(v0 + 0x90) + v0, 5, 0.0f, 0, 0);
        } else {
            v0 = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0x84) + v0, *(int *)(v0 + 0x88) + v0, 5, 0.0f, 0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        break;
    }
}

__attribute__((section(".text.func_0027FDD8")))
void func_0027FDD8(void *a0)
{
    char *s0 = (char *)a0;
    int v0;

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        if (*(unsigned char *)(s0 + 0x2F7)) {
            v0 = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0x8C) + v0, *(int *)(v0 + 0x94) + v0, 5, 0.0f, 0, 0);
        } else {
            v0 = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0x8C) + v0, *(int *)(v0 + 0x90) + v0, 5, 0.0f, 0, 0);
        }
        *(int *)(s0 + 0x5F0) = 1;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        break;
    }
}

__attribute__((section(".text.func_00282388")))
void func_00282388(void *a0)
{
    char *s0 = (char *)a0;
    int v0;
    int t0 = 0;
    unsigned long two = 2;

    if (*(unsigned char *)(s0 + 0x15B0)) t0 = two;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        if (*(unsigned char *)(s0 + 0x2F7)) {
            v0 = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0x94) + v0, *(int *)(v0 + 0x9C) + v0, 5, 0.0f, t0, 0);
        } else {
            v0 = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0x94) + v0, *(int *)(v0 + 0x98) + v0, 5, 0.0f, t0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        break;
    }
}

__attribute__((section(".text.func_00282928")))
void func_00282928(void *a0)
{
    char *s0 = (char *)a0;
    int v0;
    int t0 = 0;
    unsigned long two = 2;

    if (*(unsigned char *)(s0 + 0x15B0)) t0 = two;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x158) + v0, *(int *)(v0 + 0x15C) + v0, 2, 0.0f, t0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        moveMotion(s0);
        break;
    case 2:
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x160) + v0, *(int *)(v0 + 0x164) + v0, 2, 0.0f, t0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 3:
        moveMotion(s0);
        break;
    }
}

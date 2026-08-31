/* cygnus-2.96 matched TU. */

extern void func_0032B660(void *a0, int a1);
extern void func_0033ACA0(void *a0, int a1, void *a2, void *a3);
extern int Obj3270_GetField_2C(void *a0);
extern void func_00326860(void *a0);
extern void func_00326830(void *a0);
extern void func_00327370(void *a0);
extern int Obj3260_GetByte_1_D778(void *a0);
extern void func_003267C0(void *a0, int a1);
extern int Obj3270_GetVia4_Obj33C8_18_77E8(void *a0);
extern void Obj3270_SetField_3C(void *a0, int a1);
extern void Obj3270_SetField_44(void *a0, int a1);
extern void Obj3270_SetField_40(void *a0, int a1);

__attribute__((section(".text.func_0032C310")))
void func_0032C310(void *a0)
{
    char *s4 = (char *)a0;
    int b0[4];
    int b10[4];
    int b20[4];
    int b30[4];
    short h40;
    short h42;
    void *s2;
    char *s1;
    int s0;
    int s3;
    int v1;
    int s6;

    s2 = *(void **)(s4 + 0x4);
    s1 = *(char **)(s4 + 0x14);
    if (*(char *)(s4 + 0x98) == 0) {
        return;
    }
    h42 = 0;
    {
        int vt1 = *(int *)s1;
        void (*f1)() = *(void (**)())(vt1 + 0x18);
        f1(s1, 1, 0x7FFFFFFF, b0);
    }
    {
        int vt2 = *(int *)s1;
        void (*f2)() = *(void (**)())(vt2 + 0x18);
        f2(s1, 1, 0x7FFFFFFF, b20);
    }
    if (func_0033F050(b0[0], b0[1], &h40) != 0) {
        func_0032B660(s4, 0);
        {
            int vt3 = *(int *)s1;
            int (*f3)() = *(int (**)())(vt3 + 0x1C);
            f3(s1, 1, b20);
        }
        {
            int vt4 = *(int *)s1;
            int (*f4)() = *(int (**)())(vt4 + 0x1C);
            f4(s1, 1, b0);
        }
        return;
    }
    s0 = h40;
    s3 = func_0033E818(b0[0] + s0, b0[1] - s0, &h40);
    v1 = -1;
    if (s3 != 0) {
        v1 = func_0033E818(b20[0], b20[1], &h42);
    }
    s0 = s0 + h40;
    s6 = h42;
    if (s3 != 0) {
        if (v1 == 0) goto blockC;
        {
            int vt5 = *(int *)s1;
            int (*f5)() = *(int (**)())(vt5 + 0x1C);
            f5(s1, 1, b20);
        }
        {
            int vt6 = *(int *)s1;
            int (*f6)() = *(int (**)())(vt6 + 0x1C);
            f6(s1, 1, b0);
        }
        func_0032B660(s4, 0);
        return;
    }
    {
        int vt7 = *(int *)s1;
        int (*f7)() = *(int (**)())(vt7 + 0x1C);
        f7(s1, 1, b20);
    }
    func_0033ACA0(b0, s0, b0, b10);
    {
        int vt8 = *(int *)s1;
        int (*f8)() = *(int (**)())(vt8 + 0x20);
        f8(s1, 0, b0);
    }
    {
        int vt9 = *(int *)s1;
        int (*f9)() = *(int (**)())(vt9 + 0x1C);
        f9(s1, 1, b10);
    }
    goto blockD;
blockC:
    {
        int vt10 = *(int *)s1;
        int (*f10)() = *(int (**)())(vt10 + 0x20);
        f10(s1, 0, b0);
    }
    func_0033ACA0(b20, s6, b20, b30);
    {
        int vt11 = *(int *)s1;
        int (*f11)() = *(int (**)())(vt11 + 0x20);
        f11(s1, 0, b20);
    }
    {
        int vt12 = *(int *)s1;
        int (*f12)() = *(int (**)())(vt12 + 0x1C);
        f12(s1, 1, b30);
    }
blockD:
    *(int *)(s4 + 0xA4) += Obj3270_GetField_2C(s2);
    func_00326860(s2);
    func_00326830(s2);
    func_00327370(s2);
    if (Obj3260_GetByte_1_D778(s2) != 2) {
        func_0032B660(s4, 0);
        return;
    }
    func_003267C0(s2, *(int *)(s4 + 0x48));
    Obj3270_SetField_3C(s2, Obj3270_GetVia4_Obj33C8_18_77E8(s2));
    Obj3270_SetField_44(s2, 0);
    Obj3270_SetField_40(s2, 0);
}

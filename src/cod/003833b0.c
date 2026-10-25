extern void func_00381DC0(void *, void *, void *);
extern void func_00380F10(void *, void *, void *);
extern void func_00381D38(void *, void *, void *);
extern void func_00380E88(void *, void *, void *);
extern int MenuCtl_pollStreamAndRefresh(void *, void *, void *);

__attribute__((section(".text.func_003833B0")))
void func_003833B0(void *a0, unsigned char *a1)
{
    int result;
    if (((a1[3] ^ 1) & 1) != 0) {
        result = MenuCtl_pollStreamAndRefresh(a0, a1 + 0x34, a1);
        if (result)
            a1[1] = (unsigned char)result;
    }
}

__attribute__((section(".text.func_003833F8")))
void func_003833F8(void *a0, unsigned char *a1)
{
    if (a1[3] & 1)
        func_00381DC0(a0, a1 + 0xA4, a1);
    else
        func_00380F10(a0, a1 + 0x34, a1);
}

__attribute__((section(".text.func_00383438")))
void func_00383438(void *a0, unsigned char *a1)
{
    if (a1[3] & 1)
        func_00381D38(a0, a1 + 0xA4, a1);
    else
        func_00380E88(a0, a1 + 0x34, a1);
}

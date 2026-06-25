/* sn-2.95.3-136 matched TU. */

extern int PTR_DAT_003fa62c;
extern int write(int, char *, int);
extern int D_0077DB88;
extern void SetField_0_4_8_31EEA8(void *a, void *b, void *c);
extern int D_00785FB8;
extern int D_00427740;
extern int D_007859B8;
extern void func_0031EEC8(void *a, void *b);
extern int D_00785528;
extern int D_00460D00;
extern int D_0041D5D0;
extern int D_0041D5E8;

__attribute__((section(".text.func_003A7AE8")))
void func_003A7AE8(void *a0, void *a1, void *a2)
{
    char buf[0x60];
    char *p;
    *(void **)(buf + 0x0) = a0;
    *(int *)(buf + 0x8) = 0x7FFFFFFF;
    *(short *)(buf + 0xC) = 0x208;
    *(void **)(buf + 0x10) = a0;
    *(int *)(buf + 0x14) = 0x7FFFFFFF;
    *(int *)(buf + 0x54) = PTR_DAT_003fa62c;
    func_003A9D88(buf, a1, a2);
    p = *(char **)buf;
    *p = 0;
}

__attribute__((section(".text.func_003AE128")))
int func_003AE128(int *errp, int fd, char *buf, int n) {
    int ret;
    D_0077DB88 = 0;
    ret = write(fd, buf, n);
    if (ret == -1) {
        int e;
        e = D_0077DB88;
        if (e != 0) {
            *errp = e;
        }
    }
    return ret;
}

__attribute__((section(".text.func_003AE008")))
int func_003AE008(int *errp, int fd, char *buf, int n) {
    int ret;
    D_0077DB88 = 0;
    ret = func_003B0390(fd, buf, n);
    if (ret == -1) {
        int e;
        e = D_0077DB88;
        if (e != 0) {
            *errp = e;
        }
    }
    return ret;
}

__attribute__((section(".text.func_001A82F8")))
void *func_001A82F8(void)
{
    if (D_00785FB8 == 0) {
        func_001BD528();
        SetField_0_4_8_31EEA8(&D_00785FB8, &D_00427740, &D_007859B8);
    }
    return &D_00785FB8;
}

__attribute__((section(".text.func_00133810")))
void *func_00133810(void)
{
    if (D_00785528 == 0) {
        if (D_00460D00 == 0) {
            func_0031EEC8(&D_00460D00, &D_0041D5D0);
        }
        SetField_0_4_8_31EEA8(&D_00785528, &D_0041D5E8, &D_00460D00);
    }
    return &D_00785528;
}

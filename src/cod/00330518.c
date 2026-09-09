/* cygnus-2.96 matched TU. */

extern int strlen(const char *s);
extern char *getDevice(char *name);
extern char D_00755E84[];

struct H_zp {
    int f0, f4;
    long long f8;
    int f10, f14, f18, f1C;
    char *f20;
    int f24;
};

__attribute__((section(".text.htci_zero_padding")))
void htci_zero_padding(struct H_zp *hn)
{
    long long tot = ((long long)hn->f1C + hn->f24) << 11;
    if ((unsigned long long)hn->f8 < (unsigned long long)tot) {
        int rest = (int)(tot - hn->f8);
        func_003A52F0(hn->f20 + (hn->f24 << 11) - rest, 0, rest);
    }
}

__attribute__((section(".text.toUpperStr")))
void toUpperStr(unsigned char *str)
{
    unsigned int len = strlen((const char *)str);
    unsigned int i;

    for (i = 0; i < len + 1; i++) {
        int c = str[i];
        if (c >= 'a' && c <= 'z') {
            str[i] = c - 0x20;
        }
    }
}

__attribute__((section(".text.isNeedDevName")))
int isNeedDevName(char *name)
{
    char *dev;
    int (*fn)(int, int, int, int);

    dev = getDevice(name);
    if (dev == 0) return 0;
    fn = *(int (**)(int, int, int, int))(dev + 0x60);
    if (fn != 0) {
        return fn(0, 100, 0, 0);
    }
    return 0;
}

__attribute__((section(".text.isExistDev")))
int isExistDev(const char *name, int len)
{
    char *p = D_00755E84;
    int i;
    for (i = 0; i < 32; i++) {
        if (func_003A5BD8(name, p, len) == 0) return 1;
        p += 16;
    }
    return 0;
}

__attribute__((section(".text.func_003334C8")))
int func_003334C8(char *s1, char *s2)
{
    int len1, len2, i;

    len1 = strlen(s1);
    len2 = strlen(s2);
    if (len1 != len2) return -1;
    for (i = 0; i < len1; i++) {
        if (func_00333470(s1[i], s2[i]) != 0) return -1;
    }
    return 0;
}

__attribute__((section(".text.func_00334EF0")))
int func_00334EF0(char *s1, char *s2)
{
    int len1, len2, i;

    len1 = strlen(s1);
    len2 = strlen(s2);
    if (len1 != len2) return -1;
    for (i = 0; i < len1; i++) {
        if (func_00334E98(s1[i], s2[i]) != 0) return -1;
    }
    return 0;
}

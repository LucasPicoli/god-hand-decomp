/* cygnus-2.96 matched TU. */

extern const char D_00454458[];
extern const char D_00454960[];
extern long long Forward334310_334B20(void *hn);
extern struct E_htci D_003D9FE0[13];
extern struct E_cvfs D_003D9150[40];

__attribute__((section(".text.func_00333130")))
int func_00333130(signed char *hn)
{
    if (hn == 0) {
        func_00332808(hn, D_00454458);
        return 0;
    }
    return hn[2];
}

__attribute__((section(".text.func_00334A90")))
int func_00334A90(signed char *hn)
{
    if (hn == 0) {
        func_00334008(hn, D_00454960);
        return 0;
    }
    return hn[2];
}

__attribute__((section(".text.func_003347D0")))
int func_003347D0(int *hn)
{
    if (hn == 0) {
        func_00334008(hn, D_00454960);
        return 0;
    }
    return hn[7];
}

__attribute__((section(".text.func_00334BA8")))
int func_00334BA8(void *hn)
{
    return (int)(Forward334310_334B20(hn) & 0xFFFFFFFFLL);
}

struct E_htci { char used; char pad[47]; };


__attribute__((section(".text.func_003344C8")))
struct E_htci *func_003344C8(void)
{
    struct E_htci *ret = 0;
    int i;
    for (i = 0; i < 13; i++) {
        if (D_003D9FE0[i].used == 0) ret = &D_003D9FE0[i];
    }
    return ret;
}

struct E_cvfs { char used; char pad[71]; };


__attribute__((section(".text.func_00332BA8")))
struct E_cvfs *func_00332BA8(void)
{
    struct E_cvfs *ret = 0;
    int i;
    for (i = 0; i < 40; i++) {
        if (D_003D9150[i].used == 0) ret = &D_003D9150[i];
    }
    return ret;
}

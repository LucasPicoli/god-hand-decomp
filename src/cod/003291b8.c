extern int func_00333CE0(int a, int b, int c, int d);

__attribute__((section(".text.ADXPS2_LoadFcacheDvd")))
int ADXPS2_LoadFcacheDvd(int *p)
{
    int ret = 0;
    if (p != 0) ret = func_00333CE0(p[0], p[2], p[3], p[1]);
    else func_00333CE0((int)p, 0, 0, 0);
    return ret;
}

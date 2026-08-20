/* cygnus-2.96 matched TU. */

extern void func_0033F130(char *msg);
extern char D_00452438[];

/* cygnus-2.96 matched TU. */







__attribute__((section(".text.func_0032AE50")))
float func_0032AE50(void *a0)
{
    float r = 0.0f;
    void *obj;
    int *vt;
    int num;
    int cnt;
    int total;

    if (a0 == 0) {
        func_0033F130(D_00452438);
        return -1.0f;
    }
    if (func_00329FD0(a0) >= 2) {
        obj = *(void **)((char *)a0 + 0x14);
        if (obj != 0) {
            vt = *(int **)obj;
            num = (*(int (**)(void *, int))((char *)vt + 0x24))(obj, 1);
            cnt = func_0032A5F0(a0);
            total = func_0032A568(a0);
            r = (float)((num / (cnt * 18)) * 32) / (float)total;
        }
    }
    return r;
}

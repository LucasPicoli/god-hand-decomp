/* cygnus-2.96 matched TU. */

extern int Obj35C0_GetIndexed_1F34_C368(void *hn, int id);
extern int GetArrayElemA0C_35A1C8(void *hn, int id);

__attribute__((section(".text.func_00357FC8")))
int func_00357FC8(void *hn)
{
    int *p;
    int a6;
    int a7;
    unsigned int cond;
    int r;

    p = (int *)((char *)hn + 0xA0C);
    if (p[6] == 0 && p[5] == 0) return 1;
    a6 = Obj35C0_GetIndexed_1F34_C368(hn, 6);
    a7 = Obj35C0_GetIndexed_1F34_C368(hn, 7);
    cond = GetArrayElemA0C_35A1C8(hn, 0x19);
    r = 0;
    switch (cond) {
    case 0:
        r = a7 & a6;
        break;
    case 1:
        r = a7;
        break;
    case 2:
        r = a6;
        break;
    case 3:
        r = a7 | a6;
        break;
    }
    return r;
}

/* sn-2.95.3-136 matched TU. */

extern void func_001B6FB8(void *a0);
extern unsigned char D_004209E8[];
extern int cOl30_SetInitialPosition(char *a0, int a1, char *a2);
extern unsigned char D_00422A10[];

__attribute__((section(".text.func_00171140")))
int func_00171140(char *p)
{
    unsigned char frame[0x10];
    int i, j, jn, k, b, obj, lo;
    unsigned char ok;

    func_001B6FB8(p);
    func_001717C0(p, *(int *)(p + 0xF0), p + 0x100);
    lo = 0;
    j = 0;
    do {
        jn = j + 1;
        i = D_004209E8[j];
        for (k = 0; k <= 5; k++) {
            ok = ((*(int *)frame = b = *(unsigned char *)(p + 0x2B4)), (i >= lo && i < b));
            if (ok) obj = *(int *)(*(int *)(p + 0x278) + i * 4); else obj = 0;
            *(int *)(obj + 0x154) |= 0x18;
            i++;
        }
        j = jn;
    } while (j < 5);
    return 1;
}

__attribute__((section(".text.func_00182958")))
int func_00182958(char *p)
{
    unsigned char frame[0x10];
    int i, j, jn, k, b, obj, lo;
    unsigned char ok;

    func_001B6FB8(p);
    cOl30_SetInitialPosition(p, *(int *)(p + 0xF0), p + 0x100);
    lo = 0;
    j = 0;
    do {
        jn = j + 1;
        i = D_00422A10[j];
        for (k = 0; k <= 0; k++) {
            ok = ((*(int *)frame = b = *(unsigned char *)(p + 0x2B4)), (i >= lo && i < b));
            if (ok) obj = *(int *)(*(int *)(p + 0x278) + i * 4); else obj = 0;
            *(int *)(obj + 0x154) |= 0x18;
            i++;
        }
        j = jn;
    } while (j < 7);
    return 1;
}

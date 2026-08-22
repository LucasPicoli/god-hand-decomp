/* sn-2.95.3-136 matched TU. */

extern void func_0017C028(void *a0, int a1, void *a2);
extern unsigned char D_00421AD0[];
extern void func_001A9210(void *a0, int a1, void *a2);
extern unsigned char D_00427948[];

/* sn-2.95.3-136 */





__attribute__((section(".text.func_0017B940")))
int func_0017B940(char *p)
{
    unsigned char frame[0x10] __attribute__((aligned(16)));
    int i, j;
    int idx, b, obj;
    int lo, q, r, n;
    unsigned char ok;
    int tbl;

    func_001B6FB8(p);
    func_0017C028(p, *(int *)(p + 0xF0), p + 0x100);
    tbl = (int)D_00421AD0;
    lo = 0;
    do { } while (0);
    i = 0;
    while (i < 3) {
        j = 1;
        n = i + 1;
        q = i / 2;
        r = i - q * 2;
        for (; j < 5; j++) {
            if (r == 0) {
                idx = *(unsigned char *)(q + tbl) + j - 1;
                ok = ((*(int *)frame = b = *(unsigned char *)(p + 0x2B4)), (idx >= lo && idx < b));
                if (ok) obj = *(int *)(*(int *)(p + 0x278) + idx * 4); else obj = 0;
                *(int *)(obj + 0x154) |= 0x18;
            }
        }
        i = n;
    }
    return 1;
}

/* sn-2.95.3-136 */





__attribute__((section(".text.func_001A8980")))
int func_001A8980(char *p)
{
    unsigned char frame[0x10] __attribute__((aligned(16)));
    int i, j;
    int idx, b, obj;
    int lo, q, r, n;
    unsigned char ok;
    int tbl;

    func_001B6FB8(p);
    func_001A9210(p, *(int *)(p + 0xF0), p + 0x100);
    tbl = (int)D_00427948;
    lo = 0;
    do { } while (0);
    i = 0;
    while (i < 3) {
        j = 1;
        n = i + 1;
        q = i / 2;
        r = i - q * 2;
        for (; j < 5; j++) {
            if (r == 0) {
                idx = *(unsigned char *)(q + tbl) + j - 1;
                ok = ((*(int *)frame = b = *(unsigned char *)(p + 0x2B4)), (idx >= lo && idx < b));
                if (ok) obj = *(int *)(*(int *)(p + 0x278) + idx * 4); else obj = 0;
                *(int *)(obj + 0x154) |= 0x18;
            }
        }
        i = n;
    }
    *(int *)(p + 0x5A0) |= 0x10;
    return 1;
}

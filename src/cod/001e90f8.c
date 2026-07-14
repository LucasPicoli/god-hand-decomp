/* sn-2.95.3-136 matched TU. */

extern void func_003A52F0(void *a0, int a1, int a2);
extern void ClearFields00And30_1EE768(void *a0);
extern void func_001ECA80(void *a0);
extern void func_001ED548(void *a0);
extern void func_001EDE38(void *a0);

__attribute__((section(".text.func_001E90F8")))
void *func_001E90F8(void *a0) {
    char *p = (char *)a0;
    int i;
    int j;
    char *q;
    int *r;
    int *s;

    func_003A52F0(p, 0, 0x54);
    *(int *)(p + 0x54) = 0;

    q = p + 0x5C;
    for (j = 4; j != -1; j--) {
        ClearFields00And30_1EE768(q);
        q += 0x40;
    }

    func_001ECA80(p + 0x210);
    func_001ED548(p + 0x1840);
    func_001EDE38(p + 0x1B90);

    *(int *)(p + 0x200) = 0;
    *(unsigned short *)(p + 0x1B0) = 0xFFFF;

    r = (int *)(p + 0x19C);
    s = (int *)(p + 0x1EC);

    for (i = 9; i >= 0; i--) {
        ((int *)(p + 0x1C4))[i] = 0;
    }
    for (i = 4; i >= 0; i--) {
        r[i] = 0;
    }
    for (i = 4; i >= 0; i--) {
        s[i] = 0;
    }

    return p;
}

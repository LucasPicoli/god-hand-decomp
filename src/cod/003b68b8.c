/* ee-2.9-991111 matched TU. */

extern int D_003FBE50[];
extern int D_003FB6E8;
extern int D_003FBE28;
extern void func_003B6850(int, int);
extern void func_003B6860(int, void *, int);
extern void FlushCache(int);
extern int D_003FC240[];
extern int D_003FBEC0;
extern int D_003FC238;
extern void func_003B7B30(int, int);

__attribute__((section(".text.func_003B68B8")))
void func_003B68B8(void) {
    unsigned int i;
    int *p;
    if ((*(volatile int *)0x10001810 & 0x100) != 0)
        return;
    func_003B6850(D_003FBE50[0], D_003FBE50[1]);
    func_003B6860(0x80076000, &D_003FB6E8, 0x740);
    func_003B6860(0x82000, &D_003FBE28, 0x28);
    FlushCache(0);
    FlushCache(2);
    func_003B6850(D_003FBE50[2], D_003FBE50[3]);
    p = &D_003FBE50[4];
    i = 2;
    do {
        int r = func_003B68A8(*p);
        func_003B6850(*p, r);
        p += 2;
        i++;
    } while (i < 8);
}

__attribute__((section(".text.func_003B7B40")))
void func_003B7B40(void) {
    unsigned int i;
    func_003B7B30(D_003FC240[0], D_003FC240[1]);
    func_003B7AD8(0x80075000, (int)&D_003FBEC0, 0x330);
    FlushCache(0);
    FlushCache(2);
    func_003B7B30(D_003FC240[2], D_003FC240[3]);
    func_003B7B30(D_003FC240[4], D_003FC240[5]);
    for (i = 3; i < 8; i++) {
        int r = func_003B7B20(D_003FC240[i * 2]);
        func_003B7B30(D_003FC240[i * 2], r);
    }
    D_003FC238 = func_003B7B20(3);
}

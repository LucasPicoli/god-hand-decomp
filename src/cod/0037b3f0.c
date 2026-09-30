/* sn-2.95.3-136 matched TU. */

extern void func_002E0DE8();
extern char D_0045BD90[], D_0045BDA0[], D_0045BDA8[], D_0045BDC0[], D_0045BDC8[], D_0045BDD0[], D_0045BDD8[], D_0045BDE0[];
extern char D_0045CCB0[], D_0045CCD0[], D_0045CCE0[], D_0045CCF0[], D_0045CD10[], D_0045CD28[];

__attribute__((section(".text.func_0037B3F0")))
void func_0037B3F0(void)
{
    int st;
    func_002E0DE8(3, 4, 8, D_0045BD90);
    st = func_00387430(0);
    if (st == 0) {
        func_002E0DE8(0xC, 4, 0xF, D_0045BDA0);
        return;
    }
    if (st & 1) func_002E0DE8(0xC, 4, 0xD, D_0045BDA8);
    if (st & 2) func_002E0DE8(0xC, 4, 8, D_0045BDC0);
    if (st & 4) func_002E0DE8(0xF, 4, 8, D_0045BDC8);
    if (st & 8) func_002E0DE8(0x12, 4, 0xC, D_0045BDD0);
    if (st & 0x10) func_002E0DE8(0x15, 4, 0xD, D_0045BDD8);
    if (st & 0x20) func_002E0DE8(0x18, 4, 0xA, D_0045BDE0);
}

typedef struct { char pad[8]; short a[5]; short b[5]; short c[5]; short d[5]; } S;

__attribute__((section(".text.func_003849F8")))
void func_003849F8(int a0, S *p, unsigned char idx)
{
    if (idx == 0) {
        func_002E0DE8(3, 0x15, 8, D_0045CCB0, p->a[0], p->b[0]);
        func_002E0DE8(3, 0x16, 8, D_0045CCD0, p->c[0]);
        func_002E0DE8(3, 0x17, 8, D_0045CCE0, p->d[0]);
    } else {
        int n = idx - 1;
        func_002E0DE8(3, 0x15, 8, D_0045CCF0, n, p->a[idx], p->b[idx]);
        func_002E0DE8(3, 0x16, 8, D_0045CD10, n, p->c[idx]);
        func_002E0DE8(3, 0x17, 8, D_0045CD28, n, p->d[idx]);
    }
}

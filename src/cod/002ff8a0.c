/* sn-2.95.3-136 matched TU. */

extern int D_00754C80;
extern void func_002FA620(int, int, int);
extern void func_0031A650(int *, int, int, int, int);

/* sn-2.95.3-136 matched TU. */





__attribute__((section(".text.func_002FF8A0")))
void func_002FF8A0(char *o, int b, int p2, int p3, int p4) {
    int a;
    int c;
    int d;

    a = 2;
    if ((*(int *)(o + 0x11C) & 0x1000000) == 0) {
        int k = *(unsigned char *)(o + 0x101) + 2;
        c = *(unsigned char *)(o + 0x101);
        a = 4;
        switch ((signed char)k) {
        case 0:
            b = 0xC;
            break;
        case 1:
            b = 0xB;
            break;
        case 2:
            b = 0xA;
            break;
        case 3:
            b = 9;
            break;
        case 4:
            b = 8;
            break;
        case 5:
            a = 6;
            b = 7;
            break;
        case 6:
            a = 6;
            b = 3;
            break;
        }
    } else {
        if (b >= 0x3FC) {
            b = 0x3FC;
        }
        if (b < 0) {
            b = 0;
        }
        c = *(unsigned char *)(o + 0x101);
    }
    d = *(int *)(o + 0x11C);
    if (d & 0x2000) {
        if (d & 0x4000) {
            a = 3;
            b = 1;
        } else {
            a = 3;
            b = 2;
        }
    } else if (d & 0x4000) {
        a = 3;
        b = 5;
    }
    if ((signed char)c >= 3) {
        if ((signed char)c == 3) {
            a = 6;
            b = 7;
        } else if ((signed char)c == 4) {
            a = 6;
            b = 3;
        }
    }
    if (p4 == 2) {
        func_002FA620(a, b, 0x3C00);
    }
    func_0031A650(&D_00754C80, a, b, p2, p3);
    if (p4 == 1) {
        func_002FA620(a, b, 0x3C00);
    }
}

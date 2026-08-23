/* sn-2.95.3-136 matched TU. */

extern void func_0031A650(void *a0, int a1, int a2, int a3, int t0);
extern unsigned char D_00754C80[];

/* sn-2.95.3-136 candidate. */




__attribute__((section(".text.func_002FF748")))
void func_002FF748(void *a0, int a1, int a2, int a3)
{
    char *o = (char *)a0;
    int mode = 2;

    if ((*(int *)(o + 0x11C) & 0x1000000) == 0) {
        mode = 4;
        switch ((signed char)(*(unsigned char *)(o + 0x101) + 2)) {
        case 0:
            a1 = 0xC;
            break;
        case 1:
            a1 = 0xB;
            break;
        case 2:
            a1 = 0xA;
            break;
        case 3:
            a1 = 9;
            break;
        case 4:
            a1 = 8;
            break;
        case 5:
            mode = 6;
            a1 = 7;
            break;
        case 6:
            mode = 6;
            a1 = 3;
            break;
        }
    } else {
        if (a1 >= 0x3FC) {
            a1 = 0x3FC;
        }
        if (a1 < 0) {
            a1 = 0;
        }
    }
    {
        int flags = *(int *)(o + 0x11C);

        if ((flags & 0x2000) != 0) {
            if ((flags & 0x4000) != 0) {
                mode = 3;
                a1 = 1;
            } else {
                mode = 3;
                a1 = 2;
            }
        } else if ((flags & 0x4000) != 0) {
            mode = 3;
            a1 = 5;
        }
    }
    {
        int c = (signed char)*(unsigned char *)(o + 0x101);

        if (c >= 3) {
            if (c == 3) {
                mode = 6;
                a1 = 7;
            } else if (c == 4) {
                mode = 6;
                a1 = 3;
            }
        }
    }
    func_0031A650(&D_00754C80, mode, a1, a2, a3);
}

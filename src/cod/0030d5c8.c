/* sn-2.95.3-136 matched TU. */

extern void func_002CA798(void *a0);
extern int cDvd_ReadAlloc(void *a0, void *a1, void *a2, void *a3, int t0, int t1, int t2, int t3);
extern void func_00201108(void *a0, int a1);
extern void FileNameFromObjId(char *buf, int id);
extern int EnsureInitThenForward_2A9538_30EE08(void *, int, void *);
extern int cCoreSave_getCostumeNo(void *a0);
extern void func_0030D8E0(int a0);
extern void cTaskWork_exit(int a0);
extern int D_00747A24;
extern char D_005FEE00[];
extern int D_003C3BC8[];
extern char D_00583F20[];
extern char D_00754200[];
extern int *D_003C3CC4;
extern char D_00752C38[];
extern char D_00752C00[];
extern char D_00569B70[];

/* sn-2.95.3-136 matched TU. */




















__attribute__((section(".text.func_0030D5C8")))
void func_0030D5C8(void) {
    char buf[16];
    int h;
    int v;
    int i;
    int *p;

    {
        int a = D_00747A24;
        a |= 0x4000;
        D_00747A24 = a;
        if ((a & 0x40000) == 0) {
            func_002CA798(D_005FEE00);
        }
    }
    {
        int b = D_00747A24;
        D_00747A24 = b & 0xFFFBFFFF;
        h = 0;
        if ((b & 0x2000) == 0) {
        h = cDvd_ReadAlloc(D_00583F20, (void *)D_003C3BC8[1],
                           (char *)&D_00747A24 - 0x34, D_00754200, 0, 0, 0, 0);
        func_00201108(D_00583F20, h);
        func_00201108(D_00583F20, h);
        h = cDvd_ReadAlloc(D_00583F20, (void *)D_003C3BC8[10],
                           (char *)&D_00747A24 + 0x20, D_00754200, h, 0, 0, 0);
        }
    }
    {
        int c = D_00747A24;
        c |= 0x2000;
        D_00747A24 = c;
        if ((c & 0x400) == 0) {
        p = D_003C3CC4;
        i = 0;
        if (p[0] != 0xFFFF) {
            do {
                func_00201108(D_00583F20, h);
                i++;
                FileNameFromObjId(buf, p[0]);
                h = cDvd_ReadAlloc(D_00583F20, buf, D_00752C38 + (p[1] << 2),
                                   D_00754200, h, 0, 0, 0);
                p = D_003C3CC4 + i * 2;
            } while (p[0] != 0xFFFF);
        }
        func_00201108(D_00583F20, h);
        }
    }
    if ((D_00747A24 & 0x10000) == 0) {
        *(int *)D_00752C38 = EnsureInitThenForward_2A9538_30EE08((void *)0x1E6800, 0x40, D_00754200);
        *(int *)(D_00752C38 + 4) = EnsureInitThenForward_2A9538_30EE08((void *)0x19800, 0x40, D_00754200);
        switch (cCoreSave_getCostumeNo(D_00569B70)) {
        case 0:
        default:
            func_0030D8E0(0x100);
            break;
        case 1:
            func_0030D8E0(0x102);
            break;
        case 2:
            func_0030D8E0(0x105);
            break;
        case 3:
            func_0030D8E0(0x10F);
            break;
        case 4:
            func_0030D8E0(0x107);
            break;
        case 5:
            func_0030D8E0(0x110);
            break;
        case 6:
            func_0030D8E0(0x10E);
            break;
        case 7:
            func_0030D8E0(0x111);
            break;
        }
    }
    v = D_00747A24;
    v |= 0x10400;
    v &= ~0x4000;
    D_00747A24 = v;
    {
        int *r = (int *)D_00752C00;
        cTaskWork_exit(r[1]);
    }
}

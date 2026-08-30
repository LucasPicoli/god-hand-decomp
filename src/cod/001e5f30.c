/* sn-2.95.3-136 matched TU. */

extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);
extern void cCoreSave_addCasinoTicket(void *a0, int a1);
extern void cSnd_BgmEventStart(void *a0, int a1, int a2, int a3);
extern int Obj0000_Get_Field_B94_Via_Ptr0_1FC3D0(void *a0);
extern void func_001E6ED8(void *a0, int a1, int a2);
extern void func_001E6D48(void *a0, int a1, int a2);
extern void func_001E7908(void *a0, int a1, int a2);
extern char D_003BD6E8[];
extern char D_00569B70[];
extern char D_005FEE00[];
extern char D_007474A0[];

/* sn-2.95.3-136 matched TU. */













__attribute__((section(".text.func_001E5F30")))
void func_001E5F30(void *a0) {
    char *s1 = (char *)a0;

    switch (*(int *)(s1 + 0xC)) {
    case 0:
        *(int *)(s1 + 0x10) = 0x78;
        *(int *)(s1 + 0xC) = *(int *)(s1 + 0xC) + 1;
        break;
    case 1:
        SetEffect(1, 2, 0, 0, -1, 0xFFFFFFFFU);
        func_001E6ED8(s1, 1, 1);
        func_001E6D48(s1, 1, 1);
        cSnd_BgmEventStart(D_005FEE00, 0x32, 0, 0);
        *(int *)(s1 + 0xC) = *(int *)(s1 + 0xC) + 1;
        break;
    case 2:
        {
            int done;
            int t = *(int *)(s1 + 0x10);
            if (t != 0) {
                *(int *)(s1 + 0x10) = t - 1;
                done = 0;
            } else {
                done = 1;
            }
            if ((unsigned char)done == 0) break;
        }
        {
            char *p = *(char **)D_00569B70;
            int f = *(int *)(p + 0x14);
            if ((f & 0x8000000) == 0) {
                char *g = D_007474A0;
                *(int *)(p + 0x14) = f | 0x8000000;
                if (*(int *)(g + 0x56C) == 0 ||
                    *(unsigned short *)(g + 0x5B0) == 5) {
                    func_001E7908(s1 + 0x400, 0x1001, 1);
                } else if (*(unsigned short *)(g + 0x5B0) == 6) {
                    func_001E7908(s1 + 0x400, 0x1001, 1);
                }
                *(int *)(s1 + 0xC) = *(int *)(s1 + 0xC) + 1;
            } else {
                *(int *)(s1 + 0xC) = 4;
            }
        }
        cCoreSave_addCasinoTicket(D_00569B70, 1);
        *(int *)(*(char **)D_003BD6E8 + 0x1A10) =
            (short)Obj0000_Get_Field_B94_Via_Ptr0_1FC3D0(D_00569B70);
        func_001E6ED8(s1, 0, 0);
        func_001E6D48(s1, 0, 0);
        break;
    case 3: {
        char *g = D_007474A0;
        if ((*(long *)(g + 0x1A0) & 0xF00000000L) != 0) {
            *(int *)(s1 + 0x10) = 0x1E;
            if (*(int *)(g + 0x56C) == 0 ||
                *(unsigned short *)(g + 0x5B0) == 5) {
                func_001E7908(s1 + 0x400, 0x1001, 0);
            } else if (*(unsigned short *)(g + 0x5B0) == 6) {
                func_001E7908(s1 + 0x400, 0x1001, 0);
            }
            *(int *)(s1 + 0xC) = *(int *)(s1 + 0xC) + 1;
        }
        break;
    }
    case 4:
        if (Obj0000_Get_Field_B94_Via_Ptr0_1FC3D0(D_00569B70) >= 9) {
            {
                int done;
                int t = *(int *)(s1 + 0x10);
                if (t != 0) {
                    *(int *)(s1 + 0x10) = t - 1;
                    done = 0;
                } else {
                    done = 1;
                }
                if ((unsigned char)done == 0) break;
            }
            {
            char *g = D_007474A0;
            if (*(int *)(g + 0x56C) == 0 ||
                *(unsigned short *)(g + 0x5B0) == 5) {
                func_001E7908(s1 + 0x400, 0x1002, 1);
            } else if (*(unsigned short *)(g + 0x5B0) == 6) {
                func_001E7908(s1 + 0x400, 0x1003, 1);
            }
            }
            *(int *)(s1 + 0xC) = *(int *)(s1 + 0xC) + 1;
        } else {
            *(int *)(s1 + 0xC) = 6;
        }
        break;
    case 5: {
        char *g = D_007474A0;
        if ((*(long *)(g + 0x1A0) & 0xF00000000L) != 0) {
            if (*(int *)(g + 0x56C) == 0 ||
                *(unsigned short *)(g + 0x5B0) == 5) {
                func_001E7908(s1 + 0x400, 0x1002, 0);
            } else if (*(unsigned short *)(g + 0x5B0) == 6) {
                func_001E7908(s1 + 0x400, 0x1003, 0);
            }
            *(int *)(s1 + 0xC) = *(int *)(s1 + 0xC) + 1;
        }
        break;
    }
    case 6:
        *(int *)(s1 + 0x4) = 0;
        *(int *)(s1 + 0x8) = 0;
        *(int *)(s1 + 0xC) = 0;
        break;
    }
}

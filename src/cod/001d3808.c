/* sn-2.95.3-136 matched TU. */

extern void CustomIDWork_SetNumber_1D5760(void *a0, int a1);
extern void cSnd_BgmEventStart(void *a0, int a1, int a2, int a3);
extern void func_001D49E0(void *a0, int a1);
extern void func_001D4AA8(void *a0, int a1);
extern void func_001D6460(void *a0, int a1);
extern void func_001D6A30(void *a0, int a1);
extern void func_001D6A50(void *a0, int a1);
extern void func_001D6A70(void *a0, int a1);
extern char D_005FEE00[];
extern long D_00747640;

/* sn-2.95.3-136 matched TU. */
















__attribute__((section(".text.func_001D3808")))
void func_001D3808(void *a0) {
    char *s0 = (char *)a0;

    switch (*(int *)(s0 + 0x1808)) {
    case 0:
        *(int *)(s0 + 0x180C) = 0x14;
        *(int *)(s0 + 0x1808) = *(int *)(s0 + 0x1808) + 1;
        break;
    case 1:
        if (*(int *)(s0 + 0x180C) == 0) {
            CustomIDWork_SetNumber_1D5760(s0, 0);
            func_001D6A70(s0, 1);
            *(int *)(s0 + 0x180C) = 0x1E;
            *(int *)(s0 + 0x1808) = *(int *)(s0 + 0x1808) + 1;
        } else {
            *(int *)(s0 + 0x180C) = *(int *)(s0 + 0x180C) - 1;
        }
        break;
    case 2:
        if (*(int *)(s0 + 0x180C) == 0) {
            cSnd_BgmEventStart(D_005FEE00, 0x28, 0, 0);
            func_001D6A50(s0, func_001D4720(s0));
            func_001D49E0(s0, func_001D4720(s0) >= 0x16 ? 2 : 1);
            {
                int c = func_001D4720(s0) < 0x16;
                if ((c ^ 1) == 0) {
                    func_001D6A30(s0, func_001D47E8(s0));
                    if (func_001D49B0(s0) != 0) {
                        func_001D4AA8(s0, 4);
                    } else if (func_001D4918(s0) != 0) {
                        func_001D4AA8(s0, 3);
                    } else {
                        func_001D4AA8(s0, 1);
                    }
                }
            }
            func_001D6460(s0, 4);
            *(int *)(s0 + 0x180C) = 0x1E;
            *(int *)(s0 + 0x1808) = *(int *)(s0 + 0x1808) + 1;
        } else {
            *(int *)(s0 + 0x180C) = *(int *)(s0 + 0x180C) - 1;
        }
        break;
    case 3:
        if (*(int *)(s0 + 0x180C) == 0) {
            *(int *)(s0 + 0x180C) = 0x12C;
            *(int *)(s0 + 0x1808) = *(int *)(s0 + 0x1808) + 1;
        } else {
            *(int *)(s0 + 0x180C) = *(int *)(s0 + 0x180C) - 1;
        }
        break;
    case 4:
        if ((D_00747640 & 0x30000000) != 0 || *(int *)(s0 + 0x180C) == 0) {
            func_001D49E0(s0, 0);
            func_001D4AA8(s0, 0);
            func_001D6460(s0, 3);
            *(int *)(s0 + 0x180C) = 0x1E;
            *(int *)(s0 + 0x1808) = *(int *)(s0 + 0x1808) + 1;
        } else {
            *(int *)(s0 + 0x180C) = *(int *)(s0 + 0x180C) - 1;
        }
        break;
    case 5:
        if (*(int *)(s0 + 0x180C) == 0) {
            func_001D6A70(s0, 2);
            *(int *)(s0 + 0x180C) = 0x14;
            *(int *)(s0 + 0x1808) = *(int *)(s0 + 0x1808) + 1;
        } else {
            *(int *)(s0 + 0x180C) = *(int *)(s0 + 0x180C) - 1;
        }
        break;
    case 6:
        if (*(int *)(s0 + 0x180C) == 0) {
            *(int *)(s0 + 0x1808) = *(int *)(s0 + 0x1808) + 1;
        } else {
            *(int *)(s0 + 0x180C) = *(int *)(s0 + 0x180C) - 1;
        }
        break;
    case 7:
        *(int *)(s0 + 0x1804) = 0x13;
        *(int *)(s0 + 0x1808) = 0;
        break;
    }
}

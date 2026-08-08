/* sn-2.95.3-136 matched TU. */

extern void CustomIDWork_SetNumber_1D5760(void *a0, int a1);
extern void SetLinkedObjField2B_1D6D68(void *a0, int a1);
extern void cCoreSave_addGold(void *a0, int a1, int a2);
extern void cSnd_BgmEventStart(void *a0, int a1, int a2, int a3);
extern void func_001D49E0(void *a0, int a1);
extern void func_001D4AA8(void *a0, int a1);
extern void func_001D6700(void *a0, int a1);
extern void func_001D6A70(void *a0, int a1);
extern void func_001D6D20(void *a0, int a1);
extern char D_00569B70[];
extern char D_005FEE00[];
extern long D_00747640;

/* sn-2.95.3-136 matched TU. */














__attribute__((section(".text.func_001D3CE8")))
void func_001D3CE8(void *a0) {
    char *s0 = (char *)a0;

    switch (*(int *)(s0 + 0x1808)) {
    case 0:
        *(int *)(s0 + 0x180C) = 0x14;
        *(int *)(s0 + 0x1808) = *(int *)(s0 + 0x1808) + 1;
        *(int *)(s0 + 0x1818) = (int)((float)*(int *)(s0 + 0x1814) * 4.0f);
        break;
    case 1:
        if (*(int *)(s0 + 0x180C) == 0) {
            CustomIDWork_SetNumber_1D5760(s0, *(int *)(s0 + 0x1818));
            func_001D6D20(s0, 1);
            SetLinkedObjField2B_1D6D68(s0, 1);
            func_001D6A70(s0, 1);
            *(int *)(s0 + 0x180C) = 0x1E;
            *(int *)(s0 + 0x1808) = *(int *)(s0 + 0x1808) + 1;
        } else {
            *(int *)(s0 + 0x180C) = *(int *)(s0 + 0x180C) - 1;
        }
        break;
    case 2:
        if (*(int *)(s0 + 0x180C) == 0) {
            cSnd_BgmEventStart(D_005FEE00, 0x29, 0, 0);
            func_001D6700(s0, 4);
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
            *(int *)(s0 + 0x180C) = *(int *)(s0 + 0x1818) / 10;
            *(int *)(s0 + 0x1808) = *(int *)(s0 + 0x1808) + 1;
        } else {
            *(int *)(s0 + 0x180C) = *(int *)(s0 + 0x180C) - 1;
        }
        break;
    case 5:
        if ((D_00747640 & 0x30000000) != 0 || *(int *)(s0 + 0x180C) == 0) {
            *(int *)(s0 + 0x1818) = 0;
            CustomIDWork_SetNumber_1D5760(s0, 0);
            cCoreSave_addGold(D_00569B70, *(int *)(s0 + 0x180C) * 10, 0);
            *(int *)(s0 + 0x180C) = 0x1E;
            *(int *)(s0 + 0x1808) = *(int *)(s0 + 0x1808) + 1;
        } else {
            int v0 = *(int *)(s0 + 0x1818);
            if (v0 != 0) {
                *(int *)(s0 + 0x1818) = v0 - 10;
                CustomIDWork_SetNumber_1D5760(s0, v0 - 10);
            }
            cCoreSave_addGold(D_00569B70, 10, 0);
            *(int *)(s0 + 0x180C) = *(int *)(s0 + 0x180C) - 1;
        }
        break;
    case 6:
        {
            int t = *(int *)(s0 + 0x180C);
            if (t != 0) {
                t = t - 1;
                *(int *)(s0 + 0x180C) = t;
                if (t != 0) break;
            }
        }
        func_001D49E0(s0, 0);
        func_001D4AA8(s0, 0);
        func_001D6700(s0, 3);
        *(int *)(s0 + 0x180C) = 0x1E;
        *(int *)(s0 + 0x1808) = *(int *)(s0 + 0x1808) + 1;
        break;
    case 7:
        if (*(int *)(s0 + 0x180C) == 0) {
            func_001D6A70(s0, 2);
            *(int *)(s0 + 0x180C) = 0x1E;
            *(int *)(s0 + 0x1808) = *(int *)(s0 + 0x1808) + 1;
        } else {
            *(int *)(s0 + 0x180C) = *(int *)(s0 + 0x180C) - 1;
        }
        break;
    case 8:
        if (*(int *)(s0 + 0x180C) == 0) {
            *(int *)(s0 + 0x1808) = *(int *)(s0 + 0x1808) + 1;
        } else {
            *(int *)(s0 + 0x180C) = *(int *)(s0 + 0x180C) - 1;
        }
        break;
    case 9:
        *(int *)(s0 + 0x1804) = 0x13;
        *(int *)(s0 + 0x1808) = 0;
        break;
    }
}

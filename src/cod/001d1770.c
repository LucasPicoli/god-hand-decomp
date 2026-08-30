/* sn-2.95.3-136 matched TU. */

extern void func_001D5430(void *a0, int a1);
extern void SetBlendField4BC_1D5848(void *a0, int a1);
extern void func_001D5360(void *a0, int a1);
extern void func_001D5500(void *a0, int a1);
extern void CustomIDWork_SetNumber_1D5760(void *a0, int a1);
extern int GetTimerValue_1FA710(char *a0);
extern void cCoreSave_addGold(char *a0, int a1, int a2);
extern void cCoreSave_subGold(char *a0, int a1);
extern int cSnd_SeCall_2CB8A0(void *a0, int a1, short a2, short a3, short a4, int a5, int a6);
extern char D_00569B70[];
extern char D_005FEE00[];
extern int D_007474A0;

/* sn-2.95.3-136 matched TU. */














__attribute__((section(".text.func_001D1770")))
void func_001D1770(void *a0)
{
    char *s0 = (char *)a0;

    switch (*(int *)(s0 + 0x1808)) {
    case 0:
        func_001D5430(s0, 0);
        SetBlendField4BC_1D5848(s0, 1);
        *(int *)(s0 + 0x1808) += 1;
        /* fallthrough */
    case 1: {
        char *g = (char *)&D_007474A0;
        long f = *(long *)(g + 0x1B0);

        if ((f & 0x8800004000000L) != 0) {
            func_001D5430(s0, 1);
            SetBlendField4BC_1D5848(s0, 0);
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
            if (*(int *)(s0 + 0x1814) != 0) {
                *(int *)(s0 + 0x1808) = 0;
                *(int *)(s0 + 0x1804) = 3;
            } else {
                *(int *)(s0 + 0x1808) = 0;
                *(int *)(s0 + 0x1804) = 1;
            }
            return;
        }
        if ((f & 0x4400008000000L) != 0) {
            func_001D5430(s0, 1);
            SetBlendField4BC_1D5848(s0, 0);
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
            *(int *)(s0 + 0x1808) = 0;
            *(int *)(s0 + 0x1804) = 1;
            return;
        }
        if ((f & 0x3300003000000L) != 0) {
            func_001D5430(s0, 1);
            SetBlendField4BC_1D5848(s0, 0);
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
            *(int *)(s0 + 0x1808) = 0;
            *(int *)(s0 + 0x1804) = 4;
            return;
        }
        {
            long h = *(long *)(g + 0x1A0);

            if ((h & 0x10000000L) != 0) {
                while (*(int *)(s0 + 0x1814) < *(int *)(s0 + 0x1810) &&
                       GetTimerValue_1FA710(D_00569B70) >= 0x64) {
                    cCoreSave_subGold(D_00569B70, 0x64);
                    *(int *)(s0 + 0x1814) += 0x64;
                    *(int *)(s0 + 0x1800) |= 8;
                }
                if (*(int *)(s0 + 0x1814) != 0) {
                    CustomIDWork_SetNumber_1D5760(s0, *(int *)(s0 + 0x1814));
                    func_001D5430(s0, 2);
                    SetBlendField4BC_1D5848(s0, 0);
                    func_001D5360(s0, 2);
                    *(int *)(s0 + 0x1808) = 0;
                    *(int *)(s0 + 0x1804) = 3;
                }
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15E, -1, -1, 0, 0);
                return;
            }
            if ((h & 0x20000000L) != 0) {
                if (*(int *)(s0 + 0x1814) > 0) {
                    int v;

                    cCoreSave_addGold(D_00569B70, 0x64, 0);
                    v = *(int *)(s0 + 0x1814) - 0x64;
                    *(int *)(s0 + 0x1814) = v;
                    CustomIDWork_SetNumber_1D5760(s0, v);
                    if (*(int *)(s0 + 0x1814) == 0)
                        func_001D5500(s0, 2);
                } else {
                    func_001D5430(s0, 1);
                    SetBlendField4BC_1D5848(s0, 0);
                    *(int *)(s0 + 0x1808) = 0;
                    *(int *)(s0 + 0x1804) = 4;
                }
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x161, -1, -1, 0, 0);
            }
        }
        break;
    }
    }
}

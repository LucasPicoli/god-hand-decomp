/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern int *D_003C2384;
extern void CustomIDWork_SetDisp(char *p, int v);

__attribute__((section(".text.Forward30A2B0_2DA9B8")))
int Forward30A2B0_2DA9B8(char *a0)
{
	return sceVu0ApplyMatrix(*(int *)(a0 + 0xF0), (int)(a0 + 0x80), (int)(a0 + 0x330));
}

__attribute__((section(".text.cIDBase_release")))
int cIDBase_release(int *a0)
{
    int a1;
    a1 = a0[1];
    if (a1) {
        func_002ACF30(*D_003C2384, a1, a0[5], a0[4]);
        a0[0] = 0;
        a0[1] = 0;
        a0[2] = 0;
        return 1;
    }
    return 0;
}

__attribute__((section(".text.SetCustomIDDispOneOrAll_1EE1C0")))
void SetCustomIDDispOneOrAll_1EE1C0(char *a0, int a1, int a2)
{
    int i;
    if (a2) {
        if (a1 == 0x1D) {
            for (i = 0; i < 0x1D; i++) {
                if (i != 0)
                    CustomIDWork_SetDisp(a0 + 0x60 + i * 0x7C, 1);
            }
        } else if (a1 != 0) {
            CustomIDWork_SetDisp(a0 + (a1 * 0x7C + 0x60), 1);
        }
    } else {
        if (a1 == 0x1D) {
            for (i = 0; i < 0x1D; i++) {
                if (i != 0)
                    CustomIDWork_SetDisp(a0 + 0x60 + i * 0x7C, 0);
            }
        } else if (a1 != 0) {
            CustomIDWork_SetDisp(a0 + (a1 * 0x7C + 0x60), 0);
        }
    }
}

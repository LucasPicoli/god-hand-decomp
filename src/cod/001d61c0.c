/* sn-2.95.3-136 matched TU. */

extern void CustomIDWork_SetOffsetPosY(void *a0, int a1);
extern void CustomIDWork_SetMoveOffsetPosY(void *a0, int a1, int a2, int a3);
extern void SetFlagOnEntries7C_1D51B8(void *a0, int a1, int a2);

/* sn-2.95.3-136 matched TU. */





__attribute__((section(".text.func_001D61C0")))
void func_001D61C0(void *a0, int a1) {
    char *s0 = (char *)a0;
    switch (a1 & 0xFFFF) {
    default:
    case 0:
        CustomIDWork_SetOffsetPosY(s0 + 0x820, 0x46);
        SetFlagOnEntries7C_1D51B8(s0, 0x10, 0);
        SetFlagOnEntries7C_1D51B8(s0, 0x11, 0);
        SetFlagOnEntries7C_1D51B8(s0, 0x12, 0);
        break;
    case 1:
        CustomIDWork_SetOffsetPosY(s0 + 0x820, 0);
        break;
    case 2:
        CustomIDWork_SetMoveOffsetPosY(s0 + 0x820, 0x46, 0, 0xA);
        SetFlagOnEntries7C_1D51B8(s0, 0x10, 0);
        SetFlagOnEntries7C_1D51B8(s0, 0x11, 1);
        SetFlagOnEntries7C_1D51B8(s0, 0x12, 1);
        break;
    case 3:
        CustomIDWork_SetMoveOffsetPosY(s0 + 0x820, 0, 0x46, 0xA);
        break;
    case 4:
        CustomIDWork_SetMoveOffsetPosY(s0 + 0x820, 0x46, 0, 0xA);
        SetFlagOnEntries7C_1D51B8(s0, 0x10, 0);
        SetFlagOnEntries7C_1D51B8(s0, 0x11, 0);
        SetFlagOnEntries7C_1D51B8(s0, 0x12, 1);
        break;
    }
}

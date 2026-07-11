/* sn-2.95.3-136 matched TU. */

extern void CustomIDWork_SetOffsetPosX(void *a0, int a1);
extern void CustomIDWork_SetMoveOffsetPosX(void *a0, int a1, int a2, int a3);
extern void CustomIDWork_SetColorAnimNormal_2D68D8(void *a0, int a1, int a2, int a3);
extern void SetFlagOnEntries7C_1D51B8(void *a0, int a1, int a2);

/* sn-2.95.3-136 matched TU. */






__attribute__((section(".text.func_001D6700")))
void func_001D6700(void *a0, int a1, int a2, int a3) {
    char *s0 = (char *)a0;
    switch (a1 & 0xFFFF) {
    default:
    case 0:
        CustomIDWork_SetOffsetPosX(s0 + 0xB84, -0x1C2);
        SetFlagOnEntries7C_1D51B8(s0, 0x17, 0);
        break;
    case 1:
        CustomIDWork_SetOffsetPosX(s0 + 0xB84, 0);
        SetFlagOnEntries7C_1D51B8(s0, 0x17, 1);
        break;
    case 2:
        CustomIDWork_SetMoveOffsetPosX(s0 + 0xB84, -0x1C2, 0, 0x14);
        SetFlagOnEntries7C_1D51B8(s0, 0x17, 1);
        break;
    case 3:
        CustomIDWork_SetMoveOffsetPosX(s0 + 0xB84, 0, 0x1C2, 0x14);
        SetFlagOnEntries7C_1D51B8(s0, 0x17, 1);
        break;
    case 4: {
        char *p = s0 + 0xB84;
        CustomIDWork_SetColorAnimNormal_2D68D8(p,
            (((((((a3 & ~0x00FF0000) | 0x00800000) & ~0x0000FF00) | 0x00008000) & ~0x000000FF) | 0x00000080) & ~0xFF000000),
            (((((((a2 & ~0x00FF0000) | 0x00800000) & ~0x0000FF00) | 0x00008000) & ~0x000000FF) | 0x00000080) & ~0xFF000000) | 0x80000000,
            8);
        CustomIDWork_SetOffsetPosX(p, 0);
        SetFlagOnEntries7C_1D51B8(s0, 0x17, 1);
        break;
    }
    }
}

/* sn-2.95.3-136 matched TU. */

extern int D_005FEE00;
extern int cSnd_GetBgmData(int a0, int a1);
extern void func_002CC628(void *a0);
extern void func_002CC5C0(void *a0);

/* sn-2.95.3-136 matched TU. */









__attribute__((section(".text.func_002CC728")))
int func_002CC728(char *a0, int a1, char *a2, int a3)
{
    int sel;

    *(int *)(a0 + 0x8C) = a1 + 0x80;
    *(int *)(a0 + 0xB8) = cSnd_GetBgmData((int)&D_005FEE00, a1);
    *(int *)(a0 + 0x90) = *(int *)(a2 + 0);
    sel = *(int *)(a2 + 4);
    *(int *)(a0 + 0x94) = sel;
    *(int *)(a0 + 0x9C) = *(int *)(a2 + 8);
    *(int *)(a0 + 0x98) = a3;

    switch (sel) {
    default:
        break;
    case 3:
        *(int *)(a0 + 0xAC) = *(unsigned short *)(a2 + 0xC);
        *(int *)(a0 + 0xA4) = func_002D0578(&D_005FEE00, *(unsigned short *)(a2 + 0xE));
        break;
    case 2:
        *(int *)(a0 + 0xA8) = func_002D0598(&D_005FEE00, *(unsigned short *)(a2 + 0xC));
        *(int *)(a0 + 0xA4) = func_002D0578(&D_005FEE00, *(unsigned short *)(a2 + 0xE));
        break;
    case 1:
    case 4:
    case 5:
        *(unsigned short *)(a0 + 0xA0) = *(unsigned short *)(a2 + 0xC);
        *(unsigned short *)(a0 + 0xA2) = *(unsigned short *)(a2 + 0xE);
        break;
    case 0:
        *(int *)(a0 + 0x94) = 0;
        return 0;
    }
    func_002CC628(a0);
    func_002CC5C0(a0);
    return 1;
}

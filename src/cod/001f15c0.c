/* sn-2.95.3-136 matched TU. */

extern void ColiseumBattle_DefeatAllEnemies(void *a0);

extern void cEmSetParam_setEm(void *a0, int a1);
extern void cEmWrap_StartAction(void *a0);
extern char D_00586AB0[];

__attribute__((section(".text.func_001F15C0")))
void func_001F15C0(void *a0) {
    char *s0 = (char *)a0;
    char buf[0x10];
    int st;

    st = *(int *)(s0 + 0xB94);
    switch (st) {
    case 0:
        ColiseumBattle_DefeatAllEnemies(s0);
        *(int *)(s0 + 0xBA0) = 0;
        *(int *)(s0 + 0xB94) = *(int *)(s0 + 0xB94) + 1;
        break;
    case 1:
        if (*(int *)(s0 + 0xBA0) < 0x258 && ColiseumBattle_CountLiveEnemies(s0) != 0) goto bail;
        buf[0] = st;
        cEmSetParam_setEm(D_00586AB0, 1);
        cEmWrap_StartAction(buf);
        *(int *)(s0 + 0xBA0) = 0;
        *(int *)(s0 + 0xB8C) = *(int *)(s0 + 0xB8C) + 1;
        *(int *)(s0 + 0xB94) = *(int *)(s0 + 0xB94) + 1;
        break;
    case 2:
        if (*(int *)(s0 + 0xBA0) < 0x258 && ColiseumBattle_CountLiveEnemies(s0) != 0) goto bail;
        buf[0] = st;
        cEmSetParam_setEm(D_00586AB0, 2);
        cEmWrap_StartAction(buf);
        *(int *)(s0 + 0xBA0) = 0;
        *(int *)(s0 + 0xB8C) = *(int *)(s0 + 0xB8C) + 1;
        *(int *)(s0 + 0xB94) = *(int *)(s0 + 0xB94) + 1;
        break;
    }
    return;
bail:
    *(int *)(s0 + 0xBA0) = *(int *)(s0 + 0xBA0) + 1;
}

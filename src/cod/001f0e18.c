/* sn-2.95.3-136 matched TU. */

extern void func_001EF978(void *a0);
extern void cEmSetParam_setEm(void *a0, int a1);
extern void cEmWrap_StartAction(void *a0);
extern char D_00586AB0[];

/* sn-2.95.3-136 matched TU. */







__attribute__((section(".text.func_001F0E18")))
void func_001F0E18(void *a0) {
    char *s0 = (char *)a0;
    char buf[0x10];

    switch (*(int *)(s0 + 0xB94)) {
    case 0:
        func_001EF978(s0);
        *(int *)(s0 + 0xBA0) = 0;
        *(int *)(s0 + 0xB94) = *(int *)(s0 + 0xB94) + 1;
        break;
    case 1:
        if (*(int *)(s0 + 0xBA0) < 0x258 && func_001EF8B8(s0) != 0) goto bail;
        buf[0] = 1;
        cEmSetParam_setEm(D_00586AB0, 1);
        cEmWrap_StartAction(buf);
        *(int *)(s0 + 0xBA0) = 0;
        *(int *)(s0 + 0xB8C) = *(int *)(s0 + 0xB8C) + 1;
        *(int *)(s0 + 0xB94) = *(int *)(s0 + 0xB94) + 1;
        break;
    case 2:
        if (*(int *)(s0 + 0xBA0) < 0x258 && func_001EF8B8(s0) != 0) goto bail;
        buf[0] = 2;
        cEmSetParam_setEm(D_00586AB0, 2);
        cEmWrap_StartAction(buf);
        *(int *)(s0 + 0xBA0) = 0;
        *(int *)(s0 + 0xB8C) = *(int *)(s0 + 0xB8C) + 1;
        *(int *)(s0 + 0xB94) = *(int *)(s0 + 0xB94) + 1;
        break;
    case 3:
        if (*(int *)(s0 + 0xBA0) < 0x258 && func_001EF8B8(s0) != 0) goto bail;
        buf[0] = 3;
        cEmSetParam_setEm(D_00586AB0, 3);
        cEmWrap_StartAction(buf);
        *(int *)(s0 + 0xBA0) = 0;
        *(int *)(s0 + 0xB8C) = *(int *)(s0 + 0xB8C) + 1;
        *(int *)(s0 + 0xB94) = *(int *)(s0 + 0xB94) + 1;
        break;
    case 4:
        if (*(int *)(s0 + 0xBA0) < 0x258 && func_001EF8B8(s0) != 0) goto bail;
        buf[0] = 4;
        cEmSetParam_setEm(D_00586AB0, 4);
        cEmWrap_StartAction(buf);
        *(int *)(s0 + 0xBA0) = 0;
        *(int *)(s0 + 0xB8C) = *(int *)(s0 + 0xB8C) + 1;
        *(int *)(s0 + 0xB94) = *(int *)(s0 + 0xB94) + 1;
        break;
    case 5:
        if (*(int *)(s0 + 0xBA0) < 0x258 && func_001EF8B8(s0) != 0) goto bail;
        buf[0] = 5;
        cEmSetParam_setEm(D_00586AB0, 5);
        cEmWrap_StartAction(buf);
        *(int *)(s0 + 0xBA0) = 0;
        *(int *)(s0 + 0xB8C) = *(int *)(s0 + 0xB8C) + 1;
        *(int *)(s0 + 0xB94) = *(int *)(s0 + 0xB94) + 1;
        break;
    case 6:
        if (*(int *)(s0 + 0xBA0) < 0x258 && func_001EF8B8(s0) != 0) goto bail;
        buf[0] = 6;
        cEmSetParam_setEm(D_00586AB0, 6);
        cEmWrap_StartAction(buf);
        *(int *)(s0 + 0xBA0) = 0;
        *(int *)(s0 + 0xB8C) = *(int *)(s0 + 0xB8C) + 1;
        *(int *)(s0 + 0xB94) = *(int *)(s0 + 0xB94) + 1;
        break;
    case 7:
        if (*(int *)(s0 + 0xBA0) < 0x258 && func_001EF8B8(s0) != 0) goto bail;
        buf[0] = 7;
        cEmSetParam_setEm(D_00586AB0, 7);
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

/* sn-2.95.3-136 matched TU. */

extern void CustomIDWork_SetOffsetPosX(void *a0, int a1);
extern void CustomIDWork_SetMoveOffsetPosX(void *a0, int a1, int a2, int a3);
extern void SetFlagOnEntries7C_1D51B8(void *a0, int a1, int a2);
extern void SetCustomIDDispOneOrAll_1DD258(void *a0, int a1, int a2);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001D5C38")))
void func_001D5C38(char *p, unsigned short mode)
{
    int m = mode;
    if (m == 1) {
        goto c1;
    }
    if (m < 2) {
        goto def;
    }
    if (m == 2) {
        goto c2;
    }
    if (m == 3) {
        goto c3;
    }
def:
    CustomIDWork_SetOffsetPosX(p + 0x5B4, -0x140);
    SetFlagOnEntries7C_1D51B8(p, 0xB, 0);
    SetFlagOnEntries7C_1D51B8(p, 0xC, 0);
    SetFlagOnEntries7C_1D51B8(p, 0x23, 0);
    return;
c1:
    CustomIDWork_SetOffsetPosX(p + 0x5B4, 0);
    SetFlagOnEntries7C_1D51B8(p, 0xB, 0);
    SetFlagOnEntries7C_1D51B8(p, 0xC, 1);
    SetFlagOnEntries7C_1D51B8(p, 0x23, 0);
    return;
c2:
    CustomIDWork_SetMoveOffsetPosX(p + 0x5B4, -0x140, 0, 0xA);
    SetFlagOnEntries7C_1D51B8(p, 0xB, 0);
    SetFlagOnEntries7C_1D51B8(p, 0xC, 1);
    SetFlagOnEntries7C_1D51B8(p, 0x23, 0);
    return;
c3:
    CustomIDWork_SetMoveOffsetPosX(p + 0x5B4, 0, -0x140, 0xA);
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001D5D20")))
void func_001D5D20(char *p, unsigned short mode)
{
    int m = mode;
    if (m == 1) {
        goto c1;
    }
    if (m < 2) {
        goto def;
    }
    if (m == 2) {
        goto c2;
    }
    if (m == 3) {
        goto c3;
    }
def:
    CustomIDWork_SetOffsetPosX(p + 0x4BC, -0x140);
    SetFlagOnEntries7C_1D51B8(p, 0x9, 0);
    SetFlagOnEntries7C_1D51B8(p, 0xA, 0);
    SetFlagOnEntries7C_1D51B8(p, 0x24, 0);
    return;
c1:
    CustomIDWork_SetOffsetPosX(p + 0x4BC, 0);
    SetFlagOnEntries7C_1D51B8(p, 0x9, 0);
    SetFlagOnEntries7C_1D51B8(p, 0xA, 1);
    SetFlagOnEntries7C_1D51B8(p, 0x24, 0);
    return;
c2:
    CustomIDWork_SetMoveOffsetPosX(p + 0x4BC, -0x140, 0, 0xA);
    SetFlagOnEntries7C_1D51B8(p, 0x9, 0);
    SetFlagOnEntries7C_1D51B8(p, 0xA, 1);
    SetFlagOnEntries7C_1D51B8(p, 0x24, 0);
    return;
c3:
    CustomIDWork_SetMoveOffsetPosX(p + 0x4BC, 0, -0x140, 0xA);
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001DE088")))
void func_001DE088(char *p, unsigned char mode)
{
    int m = mode;
    if (m == 1) {
        goto c1;
    }
    if (m < 2) {
        goto def;
    }
    if (m == 2) {
        goto c2;
    }
    if (m == 3) {
        goto c3;
    }
def:
    CustomIDWork_SetOffsetPosX(p + 0x1D4, 0xFA);
    SetCustomIDDispOneOrAll_1DD258(p, 0x3, 0);
    SetCustomIDDispOneOrAll_1DD258(p, 0x4, 0);
    SetCustomIDDispOneOrAll_1DD258(p, 0x5, 0);
    return;
c1:
    CustomIDWork_SetOffsetPosX(p + 0x1D4, 0);
    SetCustomIDDispOneOrAll_1DD258(p, 0x3, 0);
    SetCustomIDDispOneOrAll_1DD258(p, 0x4, 1);
    SetCustomIDDispOneOrAll_1DD258(p, 0x5, 0);
    return;
c2:
    CustomIDWork_SetMoveOffsetPosX(p + 0x1D4, 0xFA, 0, 0xA);
    SetCustomIDDispOneOrAll_1DD258(p, 0x3, 0);
    SetCustomIDDispOneOrAll_1DD258(p, 0x4, 1);
    SetCustomIDDispOneOrAll_1DD258(p, 0x5, 0);
    return;
c3:
    CustomIDWork_SetMoveOffsetPosX(p + 0x1D4, 0, 0xFA, 0xA);
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001DE170")))
void func_001DE170(char *p, unsigned char mode)
{
    int m = mode;
    if (m == 1) {
        goto c1;
    }
    if (m < 2) {
        goto def;
    }
    if (m == 2) {
        goto c2;
    }
    if (m == 3) {
        goto c3;
    }
def:
    CustomIDWork_SetOffsetPosX(p + 0x348, 0xFA);
    SetCustomIDDispOneOrAll_1DD258(p, 0x6, 0);
    SetCustomIDDispOneOrAll_1DD258(p, 0x7, 0);
    SetCustomIDDispOneOrAll_1DD258(p, 0x8, 0);
    return;
c1:
    CustomIDWork_SetOffsetPosX(p + 0x348, 0);
    SetCustomIDDispOneOrAll_1DD258(p, 0x6, 0);
    SetCustomIDDispOneOrAll_1DD258(p, 0x7, 1);
    SetCustomIDDispOneOrAll_1DD258(p, 0x8, 0);
    return;
c2:
    CustomIDWork_SetMoveOffsetPosX(p + 0x348, 0xFA, 0, 0xA);
    SetCustomIDDispOneOrAll_1DD258(p, 0x6, 0);
    SetCustomIDDispOneOrAll_1DD258(p, 0x7, 1);
    SetCustomIDDispOneOrAll_1DD258(p, 0x8, 0);
    return;
c3:
    CustomIDWork_SetMoveOffsetPosX(p + 0x348, 0, 0xFA, 0xA);
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001DE258")))
void func_001DE258(char *p, unsigned char mode)
{
    int m = mode;
    if (m == 1) {
        goto c1;
    }
    if (m < 2) {
        goto def;
    }
    if (m == 2) {
        goto c2;
    }
    if (m == 3) {
        goto c3;
    }
def:
    CustomIDWork_SetOffsetPosX(p + 0x4BC, 0xFA);
    SetCustomIDDispOneOrAll_1DD258(p, 0x9, 0);
    SetCustomIDDispOneOrAll_1DD258(p, 0xA, 0);
    SetCustomIDDispOneOrAll_1DD258(p, 0xB, 0);
    return;
c1:
    CustomIDWork_SetOffsetPosX(p + 0x4BC, 0);
    SetCustomIDDispOneOrAll_1DD258(p, 0x9, 0);
    SetCustomIDDispOneOrAll_1DD258(p, 0xA, 1);
    SetCustomIDDispOneOrAll_1DD258(p, 0xB, 0);
    return;
c2:
    CustomIDWork_SetMoveOffsetPosX(p + 0x4BC, 0xFA, 0, 0xA);
    SetCustomIDDispOneOrAll_1DD258(p, 0x9, 0);
    SetCustomIDDispOneOrAll_1DD258(p, 0xA, 1);
    SetCustomIDDispOneOrAll_1DD258(p, 0xB, 0);
    return;
c3:
    CustomIDWork_SetMoveOffsetPosX(p + 0x4BC, 0, 0xFA, 0xA);
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001DE340")))
void func_001DE340(char *p, unsigned char mode)
{
    int m = mode;
    if (m == 1) {
        goto c1;
    }
    if (m < 2) {
        goto def;
    }
    if (m == 2) {
        goto c2;
    }
    if (m == 3) {
        goto c3;
    }
def:
    CustomIDWork_SetOffsetPosX(p + 0x630, 0xFA);
    SetCustomIDDispOneOrAll_1DD258(p, 0xC, 0);
    SetCustomIDDispOneOrAll_1DD258(p, 0xD, 0);
    SetCustomIDDispOneOrAll_1DD258(p, 0xE, 0);
    return;
c1:
    CustomIDWork_SetOffsetPosX(p + 0x630, 0);
    SetCustomIDDispOneOrAll_1DD258(p, 0xC, 0);
    SetCustomIDDispOneOrAll_1DD258(p, 0xD, 1);
    SetCustomIDDispOneOrAll_1DD258(p, 0xE, 0);
    return;
c2:
    CustomIDWork_SetMoveOffsetPosX(p + 0x630, 0xFA, 0, 0xA);
    SetCustomIDDispOneOrAll_1DD258(p, 0xC, 0);
    SetCustomIDDispOneOrAll_1DD258(p, 0xD, 1);
    SetCustomIDDispOneOrAll_1DD258(p, 0xE, 0);
    return;
c3:
    CustomIDWork_SetMoveOffsetPosX(p + 0x630, 0, 0xFA, 0xA);
}

/* sn-2.95.3-136 matched TU. */

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void func_001D0408(void *a0);
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern int cCoreSave_getGameLevel(void *a0);
extern int Forward30F348_31CFE0(void);
extern int getItemNumInRoom(void);
extern int func_00273960(void *a0, float f12);
extern float Turn_dest(void *a0, float f12, float f13, void *a1);
extern char D_00569B70[];
extern unsigned char D_005CB010;
extern char D_005864F0[];

/* sn-2.95.3-136 matched TU. */




















__attribute__((section(".text.func_002705D8")))
void func_002705D8(void *a0)
{
    char *s0 = (char *)a0;
    void *s1;

    s1 = Obj0000_Get_D_00747A94_2DB6B0();
    if (*(void **)(s0 + 0x738) != 0) {
        func_001D0408(*(void **)(s0 + 0x738));
        *(int *)(s0 + 0x738) = 0;
    }
    {
        int w = *(int *)(s0 + 0x564);

        if (w == 0x279) {
            ReleaseField6ECByTag564_26B1E8(s0);
            w = *(int *)(s0 + 0x564);
        }
        if (w == 0x26A) {
            if (*(int *)(s0 + 0x16D0) & 0x1000000) {
                *(unsigned char *)(s0 + 0x2F4) = 0;
                *(unsigned char *)(s0 + 0x2F5) = 0xA5;
                *(unsigned char *)(s0 + 0x2F6) = 0;
                *(unsigned char *)(s0 + 0x2F7) = 0;
                return;
            }
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0xA1;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
            return;
        }
        if (0.0f < *(float *)(s0 + 0x16C0) && (w ^ 0x26A) != 0) {
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0x13;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
            return;
        }
    }
    if (func_00274150(s0) != 0 || 0.0f < *(float *)(s0 + 0x1734)) {
        *(unsigned char *)(s0 + 0x2F4) = 0;
        *(unsigned char *)(s0 + 0x2F5) = 0x89;
        *(unsigned char *)(s0 + 0x2F6) = 0;
        *(unsigned char *)(s0 + 0x2F7) = 0;
        return;
    }
    if (func_00274F50(s0) != 0) {
        return;
    }
    if (func_00274E98(s0) != 0) {
        return;
    }
    if (*(unsigned char *)(s0 + 0x1864) != 0) {
        if (cCoreSave_getGameLevel(D_00569B70) >= 3) {
            if (Forward30F348_31CFE0() & 1) {
                *(unsigned char *)(s0 + 0x1864) = 0;
            }
        }
        if (*(int *)(s0 + 0x16EC) != 0) {
            *(unsigned char *)(s0 + 0x1864) = 0;
        }
        if (1.5707964f < *(float *)(s0 + 0x760)) {
            *(unsigned char *)(s0 + 0x1864) = 0;
        }
    }
    {
        int w2 = *(int *)(s0 + 0x564);

        switch (w2) {
        case 0x220:
        case 0x221:
        case 0x222:
            if (*(unsigned char *)(s0 + 0x1864) != 0) {
                *(unsigned char *)(s0 + 0x1864) = 0;
                *(unsigned char *)(s0 + 0x2F4) = 0;
                *(unsigned char *)(s0 + 0x2F5) = 0x6B;
                *(unsigned char *)(s0 + 0x2F6) = 0;
                *(unsigned char *)(s0 + 0x2F7) = 0;
                return;
            }
            if (*(float *)(s0 + 0x618) < 9.0f) {
                if (D_005CB010 != 0 || *(float *)(s0 + 0x5A8) < 1.0f) {
                    *(unsigned char *)(s0 + 0x2F4) = 0;
                    *(unsigned char *)(s0 + 0x2F5) = 0x6B;
                    *(unsigned char *)(s0 + 0x2F6) = 0;
                    *(unsigned char *)(s0 + 0x2F7) = 0;
                    return;
                }
                if (cCoreSave_getGameLevel(D_00569B70) >= 3) {
                    *(unsigned char *)(s0 + 0x2F4) = 0;
                    *(unsigned char *)(s0 + 0x2F5) = 0x12;
                    *(unsigned char *)(s0 + 0x2F6) = 0;
                    *(unsigned char *)(s0 + 0x2F7) = 1;
                    return;
                }
            }
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
            return;
        case 0x211:
            if (*(int *)(s0 + 0x16D4) & 0x20) {
                *(unsigned char *)(s0 + 0x2F4) = 0;
                *(unsigned char *)(s0 + 0x2F5) = 0x7F;
                *(unsigned char *)(s0 + 0x2F6) = 0;
                *(unsigned char *)(s0 + 0x2F7) = 0;
                return;
            }
            if (func_00260650(s0) < 2 && (unsigned int)getItemNumInRoom() < 0xA) {
                *(unsigned char *)(s0 + 0x2F4) = 0;
                *(unsigned char *)(s0 + 0x2F5) = 0x84;
                *(unsigned char *)(s0 + 0x2F6) = 0;
                *(unsigned char *)(s0 + 0x2F7) = 0;
                return;
            }
            break;
        case 0x265:
            if (*(int *)(s0 + 0x16D4) & 0x20000000) {
                if (func_0012C4F0(s1) != 0) {
                    if (func_00262AA8(s0) != 0) {
                        return;
                    }
                }
                if (*(unsigned char *)(s0 + 0x1864) != 0) {
                    *(unsigned char *)(s0 + 0x1864) = 0;
                    *(unsigned char *)(s0 + 0x2F4) = 0;
                    *(unsigned char *)(s0 + 0x2F5) = 0x6C;
                    *(unsigned char *)(s0 + 0x2F6) = 0;
                    *(unsigned char *)(s0 + 0x2F7) = 0;
                    return;
                }
                if (*(float *)(s0 + 0x618) < 12.25f) {
                    *(unsigned char *)(s0 + 0x2F4) = 0;
                    *(unsigned char *)(s0 + 0x2F5) = 0x9E;
                    *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x800000;
                    *(unsigned char *)(s0 + 0x2F6) = 0;
                    *(unsigned char *)(s0 + 0x2F7) = 0;
                    return;
                }
                *(unsigned char *)(s0 + 0x2F4) = 0;
                *(unsigned char *)(s0 + 0x2F5) = 0x9C;
                *(unsigned char *)(s0 + 0x2F6) = 0;
                *(unsigned char *)(s0 + 0x2F7) = 0;
                return;
            }
            break;
        case 0x21F:
            if (9.0f < *(float *)(s0 + 0x618)) {
                if (*(float *)(s0 + 0x16E4) <= 0.0f) {
                    if ((unsigned int)func_002919C0(D_005864F0, *(unsigned short *)(s0 + 0x2FE), 0x21F) < 2) {
                        *(unsigned char *)(s0 + 0x2F4) = 0;
                        *(unsigned char *)(s0 + 0x2F5) = 0x8B;
                        *(unsigned char *)(s0 + 0x2F6) = 0;
                        *(unsigned char *)(s0 + 0x2F7) = 0;
                        return;
                    }
                }
            }
            break;
        }
    }
    if (*(unsigned char *)(s0 + 0x1864) != 0) {
        int w3;

        *(unsigned char *)(s0 + 0x1864) = 0;
        w3 = *(int *)(s0 + 0x564);
        w3 -= 0x205;
        switch (w3) {
        default:
            if (func_0012C4F0(s1) == 0) {
                *(unsigned char *)(s0 + 0x2F4) = 0;
                *(unsigned char *)(s0 + 0x2F5) = 0x6C;
                *(unsigned char *)(s0 + 0x2F6) = 0;
                *(unsigned char *)(s0 + 0x2F7) = 0;
                return;
            }
            break;
        case 3:
        case 6:
        case 107:
        case 108:
        case 109:
        case 110:
        case 111:
            if (*(float *)(s0 + 0x618) < 9.0f &&
                ((Forward30F348_31CFE0() & 1) != 0 || func_0012C4F0(s1) != 0)) {
                if (func_00273960(s0, 6.0f) != 0) {
                    return;
                }
            }
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0x6C;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
            return;
        case 0:
        case 1:
        case 2:
        case 4:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 31:
        case 32:
        case 39:
        case 40:
        case 41:
        case 42:
        case 67:
        case 68:
        case 71:
        case 72:
        case 73:
        case 77:
        case 85:
            if (func_0012C4F0(s1) != 0) {
                break;
            }
            if (*(float *)(s0 + 0x618) < 9.0f && (Forward30F348_31CFE0() & 1) != 0) {
                *(unsigned char *)(s0 + 0x2F4) = 0;
                *(unsigned char *)(s0 + 0x2F5) = 0xA;
                *(unsigned char *)(s0 + 0x2F6) = 0;
                *(unsigned char *)(s0 + 0x2F7) = 1;
                return;
            }
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0x6C;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
            return;
        case 27:
        case 28:
        case 29:
            if (func_0012C4F0(s1) != 0) {
                break;
            }
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0x12;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 1;
            return;
        case 81:
        case 121:
            if (func_0012C4F0(s1) != 0) {
                *(unsigned char *)(s0 + 0x2F4) = 0;
                *(unsigned char *)(s0 + 0x2F5) = 0x4B;
                *(unsigned char *)(s0 + 0x2F6) = 0;
                *(unsigned char *)(s0 + 0x2F7) = 0;
                break;
            }
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0x6C;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
            return;
        case 30:
            if (func_0012C4F0(s1) == 0 && *(float *)(s0 + 0x618) < 9.0f &&
                (Forward30F348_31CFE0() & 1) != 0) {
                *(unsigned char *)(s0 + 0x2F4) = 0;
                *(unsigned char *)(s0 + 0x2F5) = 0xA;
                *(unsigned char *)(s0 + 0x2F6) = 0;
                *(unsigned char *)(s0 + 0x2F7) = 1;
                return;
            }
            break;
        case 116:
            if (*(float *)(s0 + 0x618) < 25.0f && (Forward30F348_31CFE0() & 1) != 0) {
                *(unsigned char *)(s0 + 0x2F4) = 0;
                *(unsigned char *)(s0 + 0x2F5) = 9;
                *(unsigned char *)(s0 + 0x2F6) = 0;
                *(unsigned char *)(s0 + 0x2F7) = 2;
                return;
            }
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0x6C;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
            return;
        }
    }
    *(unsigned char *)(s0 + 0x1864) = 0;
    if (1.5707964f < Turn_dest(*(void **)(s0 + 0xF0), *(float *)(s0 + 0x104),
                               3.1415927f, s0 + 0x16A0)) {
        *(unsigned char *)(s0 + 0x2F4) = 0;
        *(unsigned char *)(s0 + 0x2F5) = 8;
        *(int *)(s0 + 0x16D4) = *(int *)(s0 + 0x16D4) | 1;
        *(unsigned char *)(s0 + 0x2F6) = 0;
        *(unsigned char *)(s0 + 0x2F7) = 0;
        return;
    }
    *(unsigned char *)(s0 + 0x2F4) = 0;
    *(unsigned char *)(s0 + 0x2F5) = 0;
    *(unsigned char *)(s0 + 0x2F6) = 0;
    *(unsigned char *)(s0 + 0x2F7) = 0;
}

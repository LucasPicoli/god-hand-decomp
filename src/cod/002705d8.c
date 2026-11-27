/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cCamera.h"
#include "godhand/cGameObj.h"

extern void *Getplayer(void);
extern void func_001D0408(void *a0);
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern int irand(void);
extern int getItemNumInRoom(void);
extern char D_005864F0[];

/* sn-2.95.3-136 matched TU. */




















__attribute__((section(".text.func_002705D8")))
void func_002705D8(void *a0)
{
    cGameObj *s0 = a0;
    void *s1;

    s1 = Getplayer();
    if (*(void **)((char *)s0 + 0x738) != 0) {
        func_001D0408(*(void **)((char *)s0 + 0x738));
        *(int *)((char *)s0 + 0x738) = 0;
    }
    {
        int w = s0->emNo;

        if (w == 0x279) {
            ReleaseField6ECByTag564_26B1E8(s0);
            w = s0->emNo;
        }
        if (w == 0x26A) {
            if (*(int *)((char *)s0 + 0x16D0) & 0x1000000) {
                s0->mode = 0;
                s0->phase = 0xA5;
                s0->step = 0;
                s0->stepArg = 0;
                return;
            }
            s0->mode = 0;
            s0->phase = 0xA1;
            s0->step = 0;
            s0->stepArg = 0;
            return;
        }
        if (0.0f < *(float *)((char *)s0 + 0x16C0) && (w ^ 0x26A) != 0) {
            s0->mode = 0;
            s0->phase = 0x13;
            s0->step = 0;
            s0->stepArg = 0;
            return;
        }
    }
    if (func_00274150(s0) != 0 || 0.0f < *(float *)((char *)s0 + 0x1734)) {
        s0->mode = 0;
        s0->phase = 0x89;
        s0->step = 0;
        s0->stepArg = 0;
        return;
    }
    if (func_00274F50(s0) != 0) {
        return;
    }
    if (cEm00_startHitUnitAim(s0) != 0) {
        return;
    }
    if (*(unsigned char *)((char *)s0 + 0x1864) != 0) {
        if (cCoreSave_getGameLevel(&D_00569B70) >= 3) {
            if (irand() & 1) {
                *(unsigned char *)((char *)s0 + 0x1864) = 0;
            }
        }
        if (*(int *)((char *)s0 + 0x16EC) != 0) {
            *(unsigned char *)((char *)s0 + 0x1864) = 0;
        }
        if (1.5707964f < *(float *)((char *)s0 + 0x760)) {
            *(unsigned char *)((char *)s0 + 0x1864) = 0;
        }
    }
    {
        int w2 = s0->emNo;

        switch (w2) {
        case 0x220:
        case 0x221:
        case 0x222:
            if (*(unsigned char *)((char *)s0 + 0x1864) != 0) {
                *(unsigned char *)((char *)s0 + 0x1864) = 0;
                s0->mode = 0;
                s0->phase = 0x6B;
                s0->step = 0;
                s0->stepArg = 0;
                return;
            }
            if (*(float *)((char *)s0 + 0x618) < 9.0f) {
                if (D_005CB010 != 0 || s0->speedRate < 1.0f) {
                    s0->mode = 0;
                    s0->phase = 0x6B;
                    s0->step = 0;
                    s0->stepArg = 0;
                    return;
                }
                if (cCoreSave_getGameLevel(&D_00569B70) >= 3) {
                    s0->mode = 0;
                    s0->phase = 0x12;
                    s0->step = 0;
                    s0->stepArg = 1;
                    return;
                }
            }
            s0->mode = 0;
            s0->phase = 0;
            s0->step = 0;
            s0->stepArg = 0;
            return;
        case 0x211:
            if (*(int *)((char *)s0 + 0x16D4) & 0x20) {
                s0->mode = 0;
                s0->phase = 0x7F;
                s0->step = 0;
                s0->stepArg = 0;
                return;
            }
            if (cOmBase_countGroupsInAction211(s0) < 2 && (unsigned int)getItemNumInRoom() < 0xA) {
                s0->mode = 0;
                s0->phase = 0x84;
                s0->step = 0;
                s0->stepArg = 0;
                return;
            }
            break;
        case 0x265:
            if (*(int *)((char *)s0 + 0x16D4) & 0x20000000) {
                if (func_0012C4F0(s1) != 0) {
                    if (func_00262AA8(a0) != 0) {
                        return;
                    }
                }
                if (*(unsigned char *)((char *)s0 + 0x1864) != 0) {
                    *(unsigned char *)((char *)s0 + 0x1864) = 0;
                    s0->mode = 0;
                    s0->phase = 0x6C;
                    s0->step = 0;
                    s0->stepArg = 0;
                    return;
                }
                if (*(float *)((char *)s0 + 0x618) < 12.25f) {
                    s0->mode = 0;
                    s0->phase = 0x9E;
                    *(int *)((char *)s0 + 0x16D0) = *(int *)((char *)s0 + 0x16D0) | 0x800000;
                    s0->step = 0;
                    s0->stepArg = 0;
                    return;
                }
                s0->mode = 0;
                s0->phase = 0x9C;
                s0->step = 0;
                s0->stepArg = 0;
                return;
            }
            break;
        case 0x21F:
            if (9.0f < *(float *)((char *)s0 + 0x618)) {
                if (*(float *)((char *)s0 + 0x16E4) <= 0.0f) {
                    if ((unsigned int)func_002919C0(D_005864F0, s0->actorId, 0x21F) < 2) {
                        s0->mode = 0;
                        s0->phase = 0x8B;
                        s0->step = 0;
                        s0->stepArg = 0;
                        return;
                    }
                }
            }
            break;
        }
    }
    if (*(unsigned char *)((char *)s0 + 0x1864) != 0) {
        int w3;

        *(unsigned char *)((char *)s0 + 0x1864) = 0;
        w3 = s0->emNo;
        w3 -= 0x205;
        switch (w3) {
        default:
            if (func_0012C4F0(s1) == 0) {
                s0->mode = 0;
                s0->phase = 0x6C;
                s0->step = 0;
                s0->stepArg = 0;
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
            if (*(float *)((char *)s0 + 0x618) < 9.0f &&
                ((irand() & 1) != 0 || func_0012C4F0(s1) != 0)) {
                if (func_00273960(a0, 6.0f) != 0) {
                    return;
                }
            }
            s0->mode = 0;
            s0->phase = 0x6C;
            s0->step = 0;
            s0->stepArg = 0;
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
            if (*(float *)((char *)s0 + 0x618) < 9.0f && (irand() & 1) != 0) {
                s0->mode = 0;
                s0->phase = 0xA;
                s0->step = 0;
                s0->stepArg = 1;
                return;
            }
            s0->mode = 0;
            s0->phase = 0x6C;
            s0->step = 0;
            s0->stepArg = 0;
            return;
        case 27:
        case 28:
        case 29:
            if (func_0012C4F0(s1) != 0) {
                break;
            }
            s0->mode = 0;
            s0->phase = 0x12;
            s0->step = 0;
            s0->stepArg = 1;
            return;
        case 81:
        case 121:
            if (func_0012C4F0(s1) != 0) {
                s0->mode = 0;
                s0->phase = 0x4B;
                s0->step = 0;
                s0->stepArg = 0;
                break;
            }
            s0->mode = 0;
            s0->phase = 0x6C;
            s0->step = 0;
            s0->stepArg = 0;
            return;
        case 30:
            if (func_0012C4F0(s1) == 0 && *(float *)((char *)s0 + 0x618) < 9.0f &&
                (irand() & 1) != 0) {
                s0->mode = 0;
                s0->phase = 0xA;
                s0->step = 0;
                s0->stepArg = 1;
                return;
            }
            break;
        case 116:
            if (*(float *)((char *)s0 + 0x618) < 25.0f && (irand() & 1) != 0) {
                s0->mode = 0;
                s0->phase = 9;
                s0->step = 0;
                s0->stepArg = 2;
                return;
            }
            s0->mode = 0;
            s0->phase = 0x6C;
            s0->step = 0;
            s0->stepArg = 0;
            return;
        }
    }
    *(unsigned char *)((char *)s0 + 0x1864) = 0;
    if (1.5707964f < Turn_dest(*(void **)((char *)s0 + 0xF0), s0->rot.y,
                               (float *)((char *)s0 + 0x16A0), 3.1415927f)) {
        s0->mode = 0;
        s0->phase = 8;
        *(int *)((char *)s0 + 0x16D4) = *(int *)((char *)s0 + 0x16D4) | 1;
        s0->step = 0;
        s0->stepArg = 0;
        return;
    }
    s0->mode = 0;
    s0->phase = 0;
    s0->step = 0;
    s0->stepArg = 0;
}

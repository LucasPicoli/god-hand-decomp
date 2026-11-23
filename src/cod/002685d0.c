/* sn-2.95.3-136 matched TU. */

extern int cEmManage_DarkWorldCk(void *a0);
extern void KillEffect(void *a0, int a1, int a2);
extern unsigned char D_005864F0[];

/* sn-2.95.3-136 candidate. */






#include "godhand/vu0.h"
#include "godhand/cObjBase.h"


__attribute__((section(".text.func_002685D0")))
void func_002685D0(void *a0)
{
    char *s0 = (char *)a0;
    cEffectParam s;
    int s1;

    s.color.x = 1.0f;
    s.color.y = 1.0f;
    s.color.z = 1.0f;
    s.color.w = 1.0f;
    VU0_SQC2_VF0(&s, 0x10);
    VU0_SQC2_VF0(&s, 0x20);
    {
        float *q = &s.scale.x;

        s.scale.x = 1.0f;
        q[1] = 1.0f;
        q[2] = 1.0f;
        q[3] = 1.0f;
    }
    s.size = 1.0f;
    s.unk4C = -1;
    s.unk4F = 0xFF;
    s.unk44 = 0;
    s.flags = 0;
    s.unk4D = 0;
    s.unk4E = 0;
    s.unk50 = 0;
    VU0_SQC2_VF0(&s, 0x60);
    s.unk70 = 0;
    s.size = *(float *)(s0 + 0x114);
    s.unk72 = 0;
    s.unk74 = 0;
    s.unk78 = 0;
    s1 = 0;
    if (*(int *)(s0 + 0x564) < 0x216) {
        s1 = (*(int *)(s0 + 0x564) >= 0x214);
    }
    if (cEmManage_DarkWorldCk(&D_005864F0) != 0 || s1 != 0) {
        if ((*(int *)(s0 + 0x16D0) & 0x100) == 0) {
            *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x100;
            switch (*(int *)(s0 + 0x564)) {
            case 0x200: default:
                SetEffect(0x58, 0xB, a0, &s, 4, EFFECT_FOLLOW_OWNER);
                break;
            case 0x205: case 0x206: case 0x207: case 0x224: case 0x241:
                SetEffect(0x58, 0xD, a0, &s, 4, EFFECT_FOLLOW_OWNER);
                break;
            case 0x20F: case 0x210: case 0x226:
                SetEffect(0x58, 0xE, a0, &s, 4, EFFECT_FOLLOW_OWNER);
                break;
            case 0x20A: case 0x20C: case 0x20D: case 0x245: case 0x247: case 0x24F:
                SetEffect(0x58, 0xC, a0, &s, 4, EFFECT_FOLLOW_OWNER);
                break;
            case 0x21A: case 0x21B: case 0x21D: case 0x21E: case 0x225: case 0x22C:
            case 0x22D: case 0x22E: case 0x22F: case 0x248: case 0x249: case 0x24C:
            case 0x24D: case 0x24E: case 0x25A:
                SetEffect(0x58, 0x6D, a0, &s, 4, EFFECT_FOLLOW_OWNER);
                break;
            case 0x208: case 0x209: case 0x20B: case 0x20E: case 0x211: case 0x213:
            case 0x214: case 0x215: case 0x217: case 0x21C: case 0x21F: case 0x220:
            case 0x221: case 0x222: case 0x223: case 0x23B: case 0x250: case 0x251:
            case 0x252: case 0x256: case 0x260: case 0x264: case 0x265: case 0x26A:
            case 0x270: case 0x271: case 0x272: case 0x273: case 0x274: case 0x275:
            case 0x276: case 0x278: case 0x279: case 0x27E:
                break;
            }
        }
    } else {
        if ((*(int *)(s0 + 0x16D0) & 0x100) != 0) {
            *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) & 0xFFFFFEFF;
            KillEffect(s0, 4, 2);
        }
    }
}

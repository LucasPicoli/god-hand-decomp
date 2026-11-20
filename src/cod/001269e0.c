/* sn-2.95.3-136 matched TU. */
#include "godhand/pl00.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/gameWork.h"
#include "godhand/cScrSpriteDraw.h"

/* Picks a motion's two records from the pack (offsets from its start): motA is
 * the record every style shares, motB the variant for styles 0-2 (norm),
 * style 3 (alt) or any other style (other). */
#define PL00_PICK_MOTION(rec, norm, alt, other)                 \
    switch (style) {                                            \
    default:                                                    \
        motA = EM_RES_REC(EM_RES(&self->base), rec);            \
        motB = EM_RES_REC(EM_RES(&self->base), other);          \
        break;                                                  \
    case 0:                                                     \
    case 1:                                                     \
    case 2:                                                     \
        motA = EM_RES_REC(EM_RES(&self->base), rec);            \
        motB = EM_RES_REC(EM_RES(&self->base), norm);           \
        break;                                                  \
    case 3:                                                     \
        motA = EM_RES_REC(EM_RES(&self->base), rec);            \
        motB = EM_RES_REC(EM_RES(&self->base), alt);            \
        break;                                                  \
    }

/* Start player motion `motion`: set the two blend records, pick the motion's
 * records for the current style (style 1 when `now` is set) and start them
 * with func_002A8578, mode 7 (5 in style 3, 0 when `now` is set). */
__attribute__((section(".text.func_001269E0")))
void func_001269E0(pl00 *self, int motion, int now)
{
    float start;
    float blend;
    int style;
    int motA;
    int motB;

    start = 0.0f;
    style = self->unk5F2;
    if (now != 0) {
        style = 1;
    }
    blend = 7.0f;
    if (style == 3) {
        blend = 5.0f;
    }
    self->unk1684 = 0;
    switch (motion) {
    case 0:
    case 1:
    case 2:
    default:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 7, 0, 0x64);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 7, 0, 0x64);
        PL00_PICK_MOTION(0xE0, 0xE8, 0xEC, 0xE4);
        break;
    case 0x5E:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 7, 0, 0x64);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 7, 0, 0x64);
        PL00_PICK_MOTION(0xE0, 0x984, 0x988, 0x984);
        break;
    case 0x3:
    case 0x66:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 7, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 2, 0, 0xA);
        PL00_PICK_MOTION(0x860, 0x868, 0x86C, 0x864);
        break;
    case 0x4:
    case 0x5:
    case 0x6:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 7, 0, 0x64);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 7, 0, 0x64);
        PL00_PICK_MOTION(0x84, 0x8C, 0x90, 0x88);
        break;
    case 0x5F:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 7, 0, 0x64);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 7, 0, 0x64);
        PL00_PICK_MOTION(0x84, 0x95C, 0x960, 0x95C);
        break;
    case 0x7:
    case 0x8:
    case 0x9:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 2, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 2, 0, 0xA);
        PL00_PICK_MOTION(0x94, 0x9C, 0xA0, 0x98);
        break;
    case 0x56:
    case 0x57:
    case 0x58:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 7, 0, 0x64);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 7, 0, 0x64);
        start = 1.0f;
        PL00_PICK_MOTION(0x840, 0x848, 0x84C, 0x844);
        break;
    case 0x59:
    case 0x5A:
    case 0x5B:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 7, 0, 0x64);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 7, 0, 0x64);
        PL00_PICK_MOTION(0x850, 0x858, 0x85C, 0x854);
        break;
    case 0xA:
    case 0xB:
    case 0xC:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 7, 0, 0x64);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 7, 0, 0x64);
        PL00_PICK_MOTION(0xF0, 0xF8, 0xFC, 0xF4);
        break;
    case 0x60:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 7, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 7, 0, 0xA);
        PL00_PICK_MOTION(0xF0, 0x98C, 0x990, 0x98C);
        break;
    case 0xD:
    case 0xE:
    case 0xF:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 7, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 7, 0, 0xA);
        start = 1.0f;
        PL00_PICK_MOTION(0x3F0, 0x3F8, 0x3FC, 0x3F4);
        break;
    case 0x61:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 7, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 7, 0, 0xA);
        start = 1.0f;
        PL00_PICK_MOTION(0x3F0, 0x994, 0x998, 0x994);
        break;
    case 0x10:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 7, 0, 0x64);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 7, 0, 0x64);
        PL00_PICK_MOTION(0x1D0, 0x1D8, 0x1DC, 0x1D4);
        break;
    case 0x62:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 0x2D, 0, 0x64);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 0x2D, 0, 0x64);
        PL00_PICK_MOTION(0x1D0, 0x96C, 0x970, 0x96C);
        break;
    case 0x11:
    case 0x12:
    case 0x13:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 7, 0, 0x64);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 7, 0, 0x64);
        PL00_PICK_MOTION(0x17C, 0x184, 0x188, 0x180);
        break;
    case 0x14:
    case 0x15:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 7, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 7, 0, 0xA);
        PL00_PICK_MOTION(0x45C, 0x464, 0x468, 0x460);
        break;
    case 0x16:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 1, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 1, 0, 0xA);
        PL00_PICK_MOTION(0x45C, 0x974, 0x978, 0x974);
        break;
    case 0x17:
    case 0x18:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 7, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 7, 0, 0xA);
        PL00_PICK_MOTION(0x46C, 0x474, 0x478, 0x470);
        break;
    case 0x19:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 0x2D, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 0x2D, 0, 0xA);
        PL00_PICK_MOTION(0x46C, 0x99C, 0x9A0, 0x99C);
        break;
    case 0x1A:
    case 0x1B:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 3, 0x15, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 3, 0x15, 0, 0xA);
        PL00_PICK_MOTION(0x130, 0x138, 0x13C, 0x134);
        break;
    case 0x1C:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 3, 0x17, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 3, 0x17, 0, 0xA);
        PL00_PICK_MOTION(0x130, 0x9A4, 0x9A8, 0x9A4);
        break;
    case 0x1D:
    case 0x1E:
    case 0x1F:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 1, 0x12, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 1, 0x12, 0, 0xA);
        start = 5.0f;
        PL00_PICK_MOTION(0x110, 0x118, 0x11C, 0x114);
        break;
    case 0x30:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 1, 0x11, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 1, 0x11, 0, 0xA);
        PL00_PICK_MOTION(0x554, 0x55C, 0x560, 0x558);
        break;
    case 0x20:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 1, 0x11, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 1, 0x11, 0, 0xA);
        start = 5.0f;
        PL00_PICK_MOTION(0x430, 0x438, 0x43C, 0x434);
        break;
    case 0x2F:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 2, 0x17, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 2, 0x17, 0, 0xA);
        start = 3.0f;
        PL00_PICK_MOTION(0x544, 0x54C, 0x550, 0x548);
        self->unk1618 = 0x14;
        break;
    case 0x22:
    case 0x6C:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 7, 0, 0x64);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 7, 0, 0x64);
        PL00_PICK_MOTION(0x2C8, 0x2D0, 0x2D4, 0x2CC);
        break;
    case 0x21:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 0x2D, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 0x2D, 0, 0xA);
        PL00_PICK_MOTION(0x3E0, 0x3E8, 0x3EC, 0x3E4);
        break;
    case 0x25:
    case 0x64:
    case 0x65:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 7, 0x19, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 7, 0x19, 0, 0xA);
        PL00_PICK_MOTION(0x2F8, 0x300, 0x304, 0x2FC);
        break;
    case 0x24:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0xB, 0xA, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0xB, 0xA, 0, 0xA);
        start = 3.0f;
        self->unk1603 = 0xA;
        PL00_PICK_MOTION(0x2E8, 0x2F0, 0x2F4, 0x2EC);
        break;
    case 0x37:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0xB, 0xA, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0xB, 0xA, 0, 0xA);
        start = 2.0f;
        self->unk1603 = 0xA;
        PL00_PICK_MOTION(0x5A4, 0x5AC, 0x5B0, 0x5A8);
        self->unk1618 = 0x1C;
        break;
    case 0x32:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0xB, 0xA, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0xB, 0xA, 0, 0xA);
        PL00_PICK_MOTION(0x534, 0x53C, 0x540, 0x538);
        break;
    case 0x26:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 6, 1, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 6, 1, 0, 0xA);
        switch (style) {
        default:
            start = 5.0f;
            motA = EM_RES_REC(EM_RES(&self->base), 0x120);
            motB = EM_RES_REC(EM_RES(&self->base), 0x124);
            break;
        case 0:
        case 1:
        case 2:
            start = 5.0f;
            motA = EM_RES_REC(EM_RES(&self->base), 0x120);
            motB = EM_RES_REC(EM_RES(&self->base), 0x128);
            break;
        case 3:
            start = 5.0f;
            motA = EM_RES_REC(EM_RES(&self->base), 0x120);
            motB = EM_RES_REC(EM_RES(&self->base), 0x12C);
            break;
        }
        break;
    case 0x31:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 6, 0x2D, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 6, 0x2D, 0, 0xA);
        start = 2.0f;
        PL00_PICK_MOTION(0x524, 0x52C, 0x530, 0x528);
        break;
    case 0x35:
        start = 3.0f;
        if (D_007474A0.language == 0) {
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 6, 0x2D, 0, 0xA);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 6, 0x2D, 0, 0xA);
        } else {
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 6, 1, 0, 0xA);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 6, 1, 0, 0xA);
        }
        PL00_PICK_MOTION(0x584, 0x58C, 0x590, 0x588);
        break;
    case 0x3D:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 6, 1, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 6, 1, 0, 0xA);
        start = 2.0f;
        PL00_PICK_MOTION(0x62C, 0x634, 0x638, 0x630);
        break;
    case 0x39:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0xC, 0xA, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0xC, 0xA, 0, 0xA);
        start = 3.0f;
        PL00_PICK_MOTION(0x5C4, 0x5CC, 0x5D0, 0x5C8);
        break;
    case 0x36:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 6, 1, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 6, 1, 0, 0xA);
        PL00_PICK_MOTION(0x594, 0x59C, 0x5A0, 0x598);
        break;
    case 0x34:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 6, 0xF, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 6, 0xF, 0, 0xA);
        PL00_PICK_MOTION(0x574, 0x57C, 0x580, 0x578);
        break;
    case 0x27:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 4, 0x2D, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 4, 0x2D, 0, 0xA);
        PL00_PICK_MOTION(0xA4, 0xAC, 0xB0, 0xA8);
        break;
    case 0x68:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 4, 1, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 4, 1, 0, 0xA);
        PL00_PICK_MOTION(0xA4, 0xAC, 0xB0, 0xA8);
        break;
    case 0x69:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 4, 0xD, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 4, 0xD, 0, 0xA);
        PL00_PICK_MOTION(0xA4, 0x964, 0x968, 0x964);
        break;
    case 0x3B:
    case 0x67:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 4, 0xC, 0, 0x123);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 4, 0xC, 0, 0x123);
        PL00_PICK_MOTION(0x5E4, 0x5EC, 0x5F0, 0x5E8);
        break;
    case 0x3C:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 4, 0xD, 0, 0x123);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 4, 0xD, 0, 0x123);
        PL00_PICK_MOTION(0x5F4, 0x5FC, 0x600, 0x5F8);
        break;
    case 0x44:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 4, 0x1D, 0, 0x123);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 4, 0x1D, 0, 0x123);
        PL00_PICK_MOTION(0x6CC, 0x6D4, 0x6D8, 0x6D0);
        break;
    case 0x3A:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 7, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 2, 0, 0xA);
        PL00_PICK_MOTION(0x5D4, 0x5DC, 0x5E0, 0x5D8);
        break;
    case 0x23:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0xA, 0x2D, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 4, 1, 0, 0xA);
        start = 7.0f;
        PL00_PICK_MOTION(0x2D8, 0x2DC, 0x2DC, 0x2DC);
        break;
    case 0x3E:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0xA, 8, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0xA, 8, 0, 0xA);
        PL00_PICK_MOTION(0x63C, 0x644, 0x648, 0x640);
        break;
    case 0x33:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0xC, 0xA, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 4, 1, 0, 0xA);
        switch (style) {
        default:
            motA = EM_RES_REC(EM_RES(&self->base), 0x564);
            motB = EM_RES_REC(EM_RES(&self->base), 0x568);
            break;
        case 0:
        case 1:
        case 2:
            motA = EM_RES_REC(EM_RES(&self->base), 0x564);
            motB = EM_RES_REC(EM_RES(&self->base), 0x56C);
            break;
        case 3:
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0xC, 8, 0, 0xA);
            motA = EM_RES_REC(EM_RES(&self->base), 0x564);
            motB = EM_RES_REC(EM_RES(&self->base), 0x570);
            break;
        }
        break;
    case 0x3F:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 7, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 2, 0, 0xA);
        PL00_PICK_MOTION(0x64C, 0x654, 0x658, 0x650);
        break;
    case 0x40:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 7, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 2, 0, 0xA);
        PL00_PICK_MOTION(0x65C, 0x664, 0x668, 0x660);
        break;
    case 0x41:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 7, 0, 0x64);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 2, 0, 0xA);
        PL00_PICK_MOTION(0x66C, 0x674, 0x678, 0x670);
        break;
    case 0x42:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 7, 0, 0x64);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 2, 0, 0xA);
        PL00_PICK_MOTION(0x67C, 0x684, 0x688, 0x680);
        break;
    case 0x43:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 7, 0, 0x64);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 2, 0, 0xA);
        PL00_PICK_MOTION(0x68C, 0x694, 0x698, 0x690);
        break;
    case 0x28:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 7, 0x19, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 7, 0x19, 0, 0xA);
        PL00_PICK_MOTION(0x324, 0x32C, 0x330, 0x328);
        break;
    case 0x38:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 7, 0x19, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 7, 0x19, 0, 0xA);
        PL00_PICK_MOTION(0x5B4, 0x5BC, 0x5C0, 0x5B8);
        break;
    case 0x29:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 7, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 7, 0, 0xA);
        PL00_PICK_MOTION(0x334, 0x33C, 0x340, 0x338);
        break;
    case 0x45:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 0x2D, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 0x2D, 0, 0xA);
        start = 4.0f;
        PL00_PICK_MOTION(0x700, 0x708, 0x70C, 0x704);
        break;
    case 0x2C:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 7, 7, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 7, 8, 0, 0xA);
        switch (style) {
        default:
            motB = motA = EM_RES_REC(EM_RES(&self->base), 0x420);
            break;
        case 0:
        case 1:
        case 2:
            motA = EM_RES_REC(EM_RES(&self->base), 0x420);
            motB = EM_RES_REC(EM_RES(&self->base), 0x428);
            break;
        case 3:
            motA = EM_RES_REC(EM_RES(&self->base), 0x420);
            motB = EM_RES_REC(EM_RES(&self->base), 0x42C);
            break;
        }
        break;
    case 0x2B:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 7, 7, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 7, 7, 0, 0xA);
        PL00_PICK_MOTION(0x410, 0x418, 0x41C, 0x414);
        break;
    case 0x2A:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 7, 7, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 7, 7, 0, 0xA);
        PL00_PICK_MOTION(0x400, 0x408, 0x40C, 0x404);
        break;
    case 0x2D:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 7, 1, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 7, 1, 0, 0xA);
        PL00_PICK_MOTION(0x440, 0x448, 0x44C, 0x444);
        self->base.hitFlash = 5.0f;
        break;
    case 0x2E:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 2, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 2, 0, 0xA);
        blend = 5.0f;
        PL00_PICK_MOTION(0x47C, 0x484, 0x488, 0x480);
        break;
    case 0x63:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 0xE, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 0xE, 0, 0xA);
        blend = 5.0f;
        PL00_PICK_MOTION(0x47C, 0x48C, 0x490, 0x48C);
        break;
    case 0x46:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 5, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 5, 0, 0xA);
        PL00_PICK_MOTION(0x710, 0x718, 0x71C, 0x714);
        self->unk1618 = 0x17;
        break;
    case 0x47:
    case 0x6D:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 5, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 5, 0, 0xA);
        PL00_PICK_MOTION(0x720, 0x728, 0x72C, 0x724);
        break;
    case 0x4C:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 0x2D, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 0x2D, 0, 0xA);
        PL00_PICK_MOTION(0x770, 0x778, 0x77C, 0x774);
        break;
    case 0x4D:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 7, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 7, 0, 0xA);
        PL00_PICK_MOTION(0x780, 0x788, 0x78C, 0x784);
        self->unk1618 = 0xE;
        break;
    case 0x4E:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0xA, 0xA, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0xA, 0xA, 0, 0xA);
        PL00_PICK_MOTION(0x790, 0x798, 0x79C, 0x794);
        break;
    case 0x48:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 3, 0x16, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 3, 0x16, 0, 0xA);
        PL00_PICK_MOTION(0x730, 0x738, 0x73C, 0x734);
        self->unk1618 = 0x37;
        break;
    case 0x49:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 6, 6, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 6, 6, 0, 0xA);
        PL00_PICK_MOTION(0x740, 0x748, 0x74C, 0x744);
        break;
    case 0x4A:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 6, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 6, 0, 0xA);
        PL00_PICK_MOTION(0x750, 0x758, 0x75C, 0x754);
        self->unk1618 = 0x32;
        break;
    case 0x4B:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 3, 0x13, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 3, 0x13, 0, 0xA);
        PL00_PICK_MOTION(0x760, 0x768, 0x76C, 0x764);
        break;
    case 0x4F:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 5, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 5, 0, 0xA);
        PL00_PICK_MOTION(0x7A0, 0x7A8, 0x7AC, 0x7A4);
        break;
    case 0x50:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 8, 0x13, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 8, 0x13, 0, 0xA);
        PL00_PICK_MOTION(0x7B0, 0x7B8, 0x7BC, 0x7B4);
        break;
    case 0x51:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 5, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 5, 0, 0xA);
        PL00_PICK_MOTION(0x7C0, 0x7C8, 0x7CC, 0x7C4);
        self->unk1618 = 0xB;
        break;
    case 0x52:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 5, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 5, 0, 0xA);
        PL00_PICK_MOTION(0x7D0, 0x7D8, 0x7DC, 0x7D4);
        self->unk1618 = 0x10;
        break;
    case 0x53:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 3, 0x12, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0xA, 0xA, 0, 0xA);
        PL00_PICK_MOTION(0x7E0, 0x7E8, 0x7EC, 0x7E4);
        self->unk1618 = 0x1C;
        break;
    case 0x54:
    case 0x6A:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 0x2D, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 0x2D, 0, 0xA);
        start = 4.0f;
        PL00_PICK_MOTION(0x93C, 0x944, 0x948, 0x940);
        break;
    case 0x6B:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 0x2D, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 0x2D, 0, 0xA);
        start = 4.0f;
        PL00_PICK_MOTION(0x93C, 0x97C, 0x980, 0x97C);
        break;
    case 0x55:
    case 0x6E:
    case 0x6F:
    case 0x70:
    case 0x71:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0xA, 8, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0xA, 8, 0, 0xA);
        PL00_PICK_MOTION(0xB4, 0xBC, 0xC0, 0xB8);
        break;
    case 0x5C:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 3, 0, 0x64);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 3, 0, 0x64);
        PL00_PICK_MOTION(0x880, 0x888, 0x88C, 0x884);
        break;
    case 0x5D:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 0, 4, 0, 0x64);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 0, 4, 0, 0x64);
        PL00_PICK_MOTION(0x890, 0x898, 0x89C, 0x894);
        break;
    }
    if (motA != 0 && motB != 0) {
        if (now != 0) {
            blend = 0.0f;
        }
        func_002A8578(self, motA, motB, func_0031ED08(blend), start, 0x40, 0);
    }
}

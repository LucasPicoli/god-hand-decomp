/* sn-2.95.3-136 */
#include "godhand/menuCtl.h"

extern void func_002E0DE8(int x, int y, int color, const char *fmt, ...);
extern int func_003A6C58(char *buf, const char *fmt, ...);
extern int func_0032B0B0(int handle);
extern void func_00380720(void *self, int a, int b, int *hh, int *mm, int *ss, int *cc);

extern char D_0045C4D0[];
extern char D_0045C4F8[];
extern char D_0045C510[];
extern char D_0045C520[];
extern char D_0045C538[];
extern char D_0045C548[];
extern char D_0045C558[];
extern char D_0045C560[];
extern char D_0045C568[];
extern char D_0045C588[];
extern char D_0045C5A8[];
extern char D_0045C5C8[];
extern char D_0045C5E8[];
extern char D_0045C600[];
extern char D_0045C620[];
extern char D_0045C630[];
extern char D_0045C640[];
extern char D_0045C650[];
extern char D_0045C660[];
extern char D_0045C670[];
extern char D_0045C680[];
extern char D_0045C698[];
extern char D_0045C6A8[];
extern char D_0045C6B8[];
extern char D_0045C6C8[];
extern char *D_003F2820[];
extern char *D_003F2840[];
extern char *D_003F2848[];

/* The g++ string's text, terminated, or "" when it is empty. */
static __inline__ char *StrText(char **s)
{
    int len = ((int *)*s)[-4];

    if (len == 0)
        return D_0045C4D0;
    (*s)[len] = 0;
    return *s;
}

/* Print the sound test page for the current entry. */
__attribute__((section(".text.func_00381478")))
void func_00381478(MenuCtl *self)
{
    char buf[0x100];
    int hh;
    int mm;
    int ss;
    int cc;
    MenuSlot *item = &self->slot[self->slotNo];
    MenuInfo *info;
    int color;
    int num;

    func_002E0DE8(0x11, 3, 0xD, D_0045C4F8);
    info = &item->info;
    func_002E0DE8(3, 5, 8, D_0045C510, self->slotNo, StrText(&self->name[self->slotNo]));
    switch (item->status) {
    case -1:
        if (item->result != 0) {
            func_002E0DE8(0xF, 0x16, 0xE, D_003F2848[item->result - 1]);
            func_002E0DE8(0x13, 0x17, 8, D_0045C520);
        }
        /* fall through */
    case 0:
    case 5:
        color = 0xF;
        break;
    case 6:
        color = 0xA;
        num = func_0032B0B0(info->handle);
        func_002E0DE8(0x14, 7, 0xD, D_0045C538, num);
        break;
    default:
        color = 0xD;
        break;
    }
    func_002E0DE8(3, 7, 8, D_0045C548);
    if (item->status >= 0)
        func_002E0DE8(0xC, 7, color, D_0045C558, D_003F2820[item->status]);
    else
        func_002E0DE8(0xC, 7, color, D_0045C560);
    func_002E0DE8(0x14, 7, 0xE, D_003F2840[item->kind]);
    func_00380720(self, info->f04, info->f00, &hh, &mm, &ss, &cc);
    func_002E0DE8(3, 9, 8, D_0045C568, hh, mm, ss, cc);
    func_00380720(self, info->f04, info->time, &hh, &mm, &ss, &cc);
    func_002E0DE8(3, 0xA, 8, D_0045C588, hh, mm, ss, cc);
    func_00380720(self, info->f04, info->unk14, &hh, &mm, &ss, &cc);
    func_002E0DE8(3, 0xB, 8, D_0045C5A8, hh, mm, ss, cc);
    func_002E0DE8(3, 0xD, 0xD, D_0045C5C8);
    func_002E0DE8(3, 0xF, 8, D_0045C5E8, self->slotNo, 0xA);
    func_002E0DE8(3, 0x10, 8, D_0045C600, item->unk04, item->unk06);
    func_002E0DE8(3, 0x11, 8, D_0045C620, item->unk08);
    func_002E0DE8(3, 0x12, 8, D_0045C630, item->unk0A);
    func_002E0DE8(3, 0x13, 8, D_0045C640, info->unk20);
    func_002E0DE8(0x20, 7, 8, D_0045C650, info->f04);
    func_002E0DE8(0x20, 8, 8, D_0045C660, info->f08);
    func_002E0DE8(0x20, 9, 8, D_0045C670, info->f0C);
    func_003A6C58(buf, D_0045C680, info->unk18);
    func_002E0DE8(0x20, 0xA, 8, D_0045C558, buf);
    func_002E0DE8(0x20, 0xB, 8, D_0045C698, info->unk1C);
    if (self->detail) {
        func_002E0DE8(0x20, 0xC, 8, D_0045C6A8, info->unk24);
        func_002E0DE8(0x20, 0xD, 8, D_0045C6B8, info->unk28);
        func_002E0DE8(0x20, 0xE, 8, D_0045C6C8, info->unk2C);
    }
}

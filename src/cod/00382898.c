/* sn-2.95.3-136 */

#include "godhand/menuCtl.h"

extern void func_002E0DE8(int x, int y, int color, const char *fmt, ...);
extern void func_00380720(void *self, int a, int b, int *hh, int *mm, int *ss, int *cc);

extern char D_0045C800[];
extern char D_0045C808[];
extern char D_0045C820[];
extern char D_0045C830[];
extern char D_0045C850[];
extern char D_0045C870[];
extern char D_0045C888[];
extern char D_0045C898[];
extern char D_0045C8A0[];
extern char D_0045C8A8[];
extern char D_0045C8C8[];
extern char D_0045C8E8[];
extern char D_0045C8F8[];
extern char D_0045C908[];
extern char D_0045C918[];
extern char D_0045C928[];
extern char D_0045C948[];
extern char D_0045C960[];
extern char D_0045C970[];
extern char D_0045C980[];
extern char D_0045C990[];
extern char D_0045C9B0[];
extern char D_0045C9C0[];
extern char D_0045C9D0[];
extern char *D_003F2840[];
extern char *D_003F2858[];
extern char *D_003F2870[];

/* The g++ string's text, terminated, or "" when it is empty. */
static __inline__ char *StrText(char **s)
{
    int len = ((int *)*s)[-4];

    if (len == 0)
        return D_0045C800;
    (*s)[len] = 0;
    return *s;
}

/* Print the stream sound test page. */
__attribute__((section(".text.func_00382898")))
void func_00382898(MenuCtl *self)
{
    int hh;
    int mm;
    int ss;
    int cc;
    MenuSnd *snd = &self->snd;
    MenuSndInfo *info = &self->sndInfo;
    int color;

    func_002E0DE8(0x11, 3, 0xD, D_0045C808);
    func_002E0DE8(3, 5, 8, D_0045C820, StrText(&self->name[10]));
    switch (snd->status) {
    case -1:
        if (snd->result != 0) {
            if (snd->result == 1)
                func_002E0DE8(0xF, 0x16, 0xE, D_0045C830);
            else
                func_002E0DE8(0xF, 0x16, 0xE, D_0045C850);
            func_002E0DE8(0x13, 0x17, 8, D_0045C870);
        }
        /* fall through */
    case 0:
    case 3:
        color = 0xF;
        break;
    case 4:
        color = 0xA;
        break;
    default:
        color = 0xD;
        break;
    }
    func_002E0DE8(3, 7, 8, D_0045C888);
    if (snd->status >= 0)
        func_002E0DE8(0xC, 7, color, D_0045C898, D_003F2858[snd->status]);
    else
        func_002E0DE8(0xC, 7, color, D_0045C8A0);
    func_002E0DE8(0x14, 7, 0xE, D_003F2840[snd->kind]);
    func_00380720(self, info->rate, info->total, &hh, &mm, &ss, &cc);
    func_002E0DE8(3, 9, 8, D_0045C8A8, hh, mm, ss, cc);
    func_00380720(self, info->rate, info->time, &hh, &mm, &ss, &cc);
    func_002E0DE8(3, 0xA, 8, D_0045C8C8, hh, mm, ss, cc);
    func_002E0DE8(0x20, 7, 8, D_0045C8E8, info->rate);
    func_002E0DE8(0x20, 8, 8, D_0045C8F8, info->track);
    func_002E0DE8(0x20, 9, 8, D_0045C908, info->phrase);
    func_002E0DE8(0x20, 0xA, 8, D_0045C918, info->song);
    func_002E0DE8(3, 0xD, 0xD, D_0045C928);
    if (snd->slot == 0) {
        func_002E0DE8(3, 0xF, 8, D_0045C948, snd->level[snd->slot], snd->index[snd->slot]);
        func_002E0DE8(3, 0x10, 8, D_0045C960, snd->panL[snd->slot]);
        func_002E0DE8(3, 0x11, 8, D_0045C970, snd->panR[snd->slot]);
        func_002E0DE8(3, 0x12, 8, D_0045C980, D_003F2870[info->mute[snd->slot]]);
    } else {
        func_002E0DE8(3, 0xF, 8, D_0045C990, snd->slot - 1, snd->level[snd->slot], snd->index[snd->slot]);
        func_002E0DE8(3, 0x10, 8, D_0045C9B0, snd->slot - 1, snd->panL[snd->slot]);
        func_002E0DE8(3, 0x11, 8, D_0045C9C0, snd->slot - 1, snd->panR[snd->slot]);
        func_002E0DE8(3, 0x12, 8, D_0045C9D0, snd->slot - 1, D_003F2870[info->mute[snd->slot]]);
    }
}

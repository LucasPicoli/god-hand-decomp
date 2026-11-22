/* cygnus-2.96: func_0032A900, clamp the pan to -15..15 into +0x46 and forward it to the voice at +0xC
 * (-0x80 while D_003C7410 mutes). */
#include "godhand/globals.h"
typedef struct {
    char pad00[0x0C];
    int voice;
    char pad10[0x46 - 0x10];
    short pan;
} PanCtl;

extern void func_0033F130(int msg);
extern void Obj3260_Tramp_00338818_D410(int voice, int pan);

__attribute__((section(".text.func_0032A900")))
void func_0032A900(PanCtl *s, int pan)
{
    if (s == 0) {
        func_0033F130((int)D_00452258);
        return;
    }
    if (pan < -15)
        s->pan = -15;
    else if (pan > 15)
        s->pan = 15;
    else
        s->pan = pan;
    if (D_003C7410 == 0)
        Obj3260_Tramp_00338818_D410(s->voice, s->pan);
    else
        Obj3260_Tramp_00338818_D410(s->voice, -0x80);
}

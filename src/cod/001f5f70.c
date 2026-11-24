/* sn-2.95.3-136: func_001F5F70, per-frame update of a menu screen: runs the current state's handler,
 * jumps to state 2 on pad bit 0x20000000, then keeps the screen's BGM event playing once its delay runs out. */
#include "godhand/cSnd.h"

typedef struct MenuScreen {
    unsigned char unk0;
    unsigned char state;    /* 0x01 */
    unsigned char sub;      /* 0x02 */
    unsigned char step;     /* 0x03 */
    unsigned char unk4;
    unsigned char bgmFirst; /* 0x05 */
    char unk6[2];
    int delay;              /* 0x08 */
    char unkC[0x18];
    int bgm;                /* 0x24 */
} MenuScreen;

typedef struct MenuStateFn {
    short delta;
    short pad;
    void (*fn)(void *self);
} MenuStateFn;

extern MenuStateFn D_003BF0F8[];
extern unsigned long D_00747640;
extern void func_001F6680(MenuScreen *s);
extern void func_001F6758(MenuScreen *s);
extern void CustomID_toggleBit29(MenuScreen *s);
extern void cSnd_BgmEventStart(void *snd, int ev, int a, int b);
extern int cSnd_BgmEvIsPlaying(void *snd, int ev);

__attribute__((section(".text.func_001F5F70")))
void func_001F5F70(MenuScreen *s)
{
    D_003BF0F8[s->state].fn((char *)s + D_003BF0F8[s->state].delta);
    if (D_00747640 & 0x20000000) {
        s->sub = 0;
        s->state = 2;
        s->step = 0;
    }
    func_001F6680(s);
    func_001F6758(s);
    CustomID_toggleBit29(s);
    if (--s->delay < 0) {
        if (s->bgmFirst != 0) {
            if (s->bgm != -2) {
                s->bgmFirst = 0;
                cSnd_BgmEventStart(&D_005FEE00, s->bgm, 0, 0);
            }
        } else if (s->bgm != -2 && cSnd_BgmEvIsPlaying(&D_005FEE00, s->bgm) == 0) {
            cSnd_BgmEventStart(&D_005FEE00, s->bgm, 0, 0);
        }
    }
}

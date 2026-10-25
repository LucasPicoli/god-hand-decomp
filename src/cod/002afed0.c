#include "godhand/cMessDrawFontCode.h"

extern unsigned short *cMessage_getRubyAddr(int mess, unsigned short id);
extern unsigned short *func_002AFC48(cMessDrawFont *self, float x, float y, unsigned short *msg,
                                     unsigned short *cur, unsigned short *ruby, float *scale, int left);
extern float cMessDrawFont_measureCode(cMessDrawFont *self, unsigned short *text, float *scale);
extern int cScriptCmd_getTicks(unsigned short *text);

__attribute__((section(".text.func_002AFED0")))
void func_002AFED0(cMessDrawFont *self, unsigned short id, float x, float y, float *scale, int n)
{
    unsigned short *p;
    unsigned short *msg;
    unsigned short *ruby;
    int count = 0;
    float w;

    p = cMessage_getMessageAddr(D_003C23A4, id);
    msg = p;
    ruby = cMessage_getRubyAddr(D_003C23A4, id);
    while (count <= n) {
        if (*p >> 15) {
            if ((*p & 0xFF00) == 0x8000) {
                break;
            }
        } else {
            ruby = func_002AFC48(self, x, y, msg, p, ruby, scale, n - count);
        }
        w = cMessDrawFont_measureCode(self, p, scale);
        if (w != 0.0f) {
            x += w + self->unk2C[0] * self->zoomX;
        }
        count += cScriptCmd_getTicks(p);
        p += cMessCommon_getCodeSize(*p);
    }
}

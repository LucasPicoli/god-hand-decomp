/* cygnus-2.96: mpvm2v_CopyPicAtr, reads the picture attributes and counters back from the M2V decoder into the handle. */
#include "godhand/MpvHandle.h"

__attribute__((section(".text.mpvm2v_CopyPicAtr")))
void mpvm2v_CopyPicAtr(MpvHandle *hn)
{
    MpvPicAtr atr;
    int a, b, c, x, d, e;

    func_0036CE68(hn->dev, &atr);
    func_0036CE90(hn->dev, &a);
    func_0036CEB8(hn->dev, &b, &c, &x);
    func_0036CEE0(hn->dev, &d, &e);
    hn->picAtr = atr;
    hn->bitRate = a;
    hn->blocks = b / 2048;
    hn->c = c;
    hn->d = d;
    hn->e = e;
}

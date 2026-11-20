/* Moji_size_set — sets the debug text character width and height to the
 * byte args, or 8/8 if either is zero. sn-2.95.3-136. Source store order
 * width, height yields retail's height-first / width-in-delay-slot via scheduler rotation. */
#include "godhand/fileBuf.h"

__attribute__((section(".text.Moji_size_set")))
void Moji_size_set(int w, int h) {
    w &= 0xFF;
    if (w != 0) {
        h &= 0xFF;
        if (h != 0) {
            D_0061B280.kindA = w;
            D_0061B280.kindB = h;
            return;
        }
    }
    D_0061B280.kindA = 8;
    D_0061B280.kindB = 8;
}

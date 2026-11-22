/* cygnus-2.96 matched TU. */
#include "godhand/CriServer.h"
#include "godhand/globals.h"

extern void func_003B9DE0(char *msg);

/* Set the server frequency in Hz and derive the server calls per block. */
__attribute__((section(".text.CriServer_setFreq")))
void CriServer_setFreq(CriServer *self, int freq) {
    if (self == 0) {
        func_003B9DE0(D_00460B48);
        return;
    }
    if (freq <= 0) {
        func_003B9DE0(D_00460B70);
        return;
    }
    self->callsPerBlock = CRISVR_SAMPLE_RATE / (freq * CRISVR_BLOCK_SIZE) + 1;
}

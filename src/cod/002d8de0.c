#include "godhand/cWorldLight.h"
/* cWorldLight_Gaibu_set_off — writes a flag (0x1E) and clears a counter in a
 * far sub-block (a0+0x10000 base). Compiled with sn-2.95.3-136. */

/* Switches the external light off: restarts its 30 frame countdown and clears the flags. */
__attribute__((section(".text.cWorldLight_Gaibu_set_off")))
void cWorldLight_Gaibu_set_off(cWorldLight *self)
{
    self->gaibuFrames = 0x1E;
    self->flags = 0;
}

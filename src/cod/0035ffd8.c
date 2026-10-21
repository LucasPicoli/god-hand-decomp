/* cygnus-2.96 matched TU. */
#include "godhand/sfxlib.h"

/* Record the input chunk, then find its header and frame tags. */
__attribute__((section(".text.SFXZ_SetTagInf")))
void SFXZ_SetTagInf(SfxZmvTagState *state, Sint8 *data, Sint32 len)
{
    SjTagRec *input;

    input = &state->input;
    input->set = SJ_TAG_SET;
    input->ck.data = data;
    input->ck.len = len;
    sfxzmv_SetTagGrp(state);
}

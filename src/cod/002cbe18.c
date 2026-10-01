/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"

extern void cSndSeVoice_Detach(void *a0, void *a1);

/* sn-2.95.3-136 matched TU. */



/* Detaches every voice from an object. */
__attribute__((section(".text.cSnd_SeDetachObj")))
void cSnd_SeDetachObj(cSnd *self, void *obj) {
    cSndSeVoice *v = self->voiceHead;
    while (v) {
        cSndSeVoice_Detach(v, obj);
        v = v->next;
    }
}

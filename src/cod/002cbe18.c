/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"

extern void func_002CE488(void *a0, void *a1);

/* sn-2.95.3-136 matched TU. */



/* Detaches every voice from an object. */
__attribute__((section(".text.func_002CBE18")))
void func_002CBE18(cSnd *self, void *obj) {
    cSndSeVoice *v = self->voiceHead;
    while (v) {
        func_002CE488(v, obj);
        v = v->next;
    }
}

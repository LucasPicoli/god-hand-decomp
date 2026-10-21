/* cygnus-2.96 matched TU. */
#include "godhand/CriServer.h"

extern void func_003B9DE0(char *msg);
extern char D_00460B20[];   /* "E03032403 : NULL pointer is passed." */

/* Set the server callback and the context it is called with; every pointer must be non-NULL. */
__attribute__((section(".text.CriServer_setCallback")))
void CriServer_setCallback(CriServer *self, void *callback, void *context) {
    if (self == 0 || callback == 0 || context == 0) {
        func_003B9DE0(D_00460B20);
        return;
    }
    self->callback = callback;
    self->context = context;
}

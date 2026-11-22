/* cygnus-2.96 matched TU. */
#include "godhand/CriServer.h"

/* Replace the server callback and keep the context it already has. */
__attribute__((section(".text.AC3LINK_SetInSj")))
void AC3LINK_SetInSj(CriServer *self, void *callback)
{
    void *context;
    CriServer_getCallback(self, 0, &context);
    CriServer_setCallback(self, callback, context);
}

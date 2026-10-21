/* cygnus-2.96 matched TU. */
#include "godhand/CriServer.h"

/* Replace the server callback and keep the context it already has. */
__attribute__((section(".text.func_003B9CE8")))
void func_003B9CE8(CriServer *self, void *callback)
{
    void *context;
    CriServer_getCallback(self, 0, &context);
    CriServer_setCallback(self, callback, context);
}

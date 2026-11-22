/* cygnus-2.96 */
#include "godhand/CriServer.h"
#include "godhand/globals.h"

extern void func_003B9DE0(void *);

__attribute__((section(".text.func_003BA830")))
void func_003BA830(char *self, int *out_a, int *out_b)
{
    if (self == 0) {
        func_003B9DE0(D_00460AD0);
        return;
    }
    if (out_a != 0)
        *out_a = *(int *)(self + 0x1C);
    if (out_b != 0)
        *out_b = *(int *)(self + 0x20);
}

/* Read the server callback and its context; either out pointer may be NULL. */
__attribute__((section(".text.CriServer_getCallback")))
void CriServer_getCallback(CriServer *self, void **callback, void **context)
{
    if (self == 0) {
        func_003B9DE0(D_00460AF8);
        return;
    }
    if (callback != 0)
        *callback = self->callback;
    if (context != 0)
        *context = self->context;
}

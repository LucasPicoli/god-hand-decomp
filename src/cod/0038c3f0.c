/* ee-2.9-991111 matched TU. */

#include "godhand/libio.h"

/* libio genops.c :: __overflow -- return _IO_OVERFLOW (f, ch); */
__attribute__((section(".text.func_0038C3F0")))
int func_0038C3F0(struct _IO_FILE *f, int ch) {
    return (*f->vtable->__overflow.pfn)(f, ch);
}

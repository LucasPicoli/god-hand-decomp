/* ee-2.9-991111 matched TU. */

#include "godhand/libio.h"
/* libio genops.c :: _IO_sgetn -- return _IO_XSGETN (fp, data, n); */
__attribute__((section(".text._IO_sgetn")))
int _IO_sgetn(struct _IO_FILE *fp, void *data, int n) {
    return (*fp->vtable->__xsgetn.pfn)(fp, data, n);
}

/* ee-2.9-991111 matched TU. */

#include "godhand/libio.h"
/* libio genops.c :: _IO_default_uflow */
__attribute__((section(".text._IO_default_uflow")))
int _IO_default_uflow(struct _IO_FILE *fp) {
    int ch = (*fp->vtable->__underflow.pfn)(fp);
    if (ch == -1)
        return -1;
    return *(unsigned char *) fp->_IO_read_ptr++;
}

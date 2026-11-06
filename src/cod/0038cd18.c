/* ee-2.9-991111 matched TU. */

#include "godhand/libio.h"
/* libio genops.c :: _IO_sputbackc */
__attribute__((section(".text._IO_sputbackc")))
int _IO_sputbackc(struct _IO_FILE *fp, int c) {
    int result;

    if (fp->_IO_read_ptr > fp->_IO_read_base
        && (unsigned char) fp->_IO_read_ptr[-1] == (unsigned char) c) {
        fp->_IO_read_ptr--;
        result = (unsigned char) c;
    } else
        result = (*fp->vtable->__pbackfail.pfn)(fp, c);

    if (result != -1)
        fp->_flags &= ~0x10;

    return result;
}

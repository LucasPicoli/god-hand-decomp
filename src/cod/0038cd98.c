/* ee-2.9-991111 matched TU. */

#include "godhand/libio.h"
/* libio genops.c :: _IO_sungetc */
__attribute__((section(".text._IO_sungetc")))
int _IO_sungetc(struct _IO_FILE *fp) {
    int result;

    if (fp->_IO_read_ptr > fp->_IO_read_base) {
        fp->_IO_read_ptr--;
        result = (unsigned char) *fp->_IO_read_ptr;
    } else
        result = (*fp->vtable->__pbackfail.pfn)(fp, -1);

    if (result != -1)
        fp->_flags &= ~0x10;

    return result;
}

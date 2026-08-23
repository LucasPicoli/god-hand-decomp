/* sn-2.95.3-136 matched TU. */

extern struct _IO_FILE *D_003F50F8;

struct _IO_FILE {
    int _flags;
    char pad[0x30];
    struct _IO_FILE *_chain;
};



__attribute__((section(".text._IO_link_in")))
void _IO_link_in(struct _IO_FILE *fp) {
    struct _IO_FILE *old;

    if ((fp->_flags & 0x80) == 0) {
        old = D_003F50F8;
        D_003F50F8 = fp;
        fp->_chain = old;
        fp->_flags |= 0x80;
    }
}

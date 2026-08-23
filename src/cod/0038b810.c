/* ee-2.9-991111 matched TU. */

__attribute__((section(".text._IO_adjust_column")))
int _IO_adjust_column(unsigned int start, char *line, int count) {
    char *ptr = line + count;
    while (ptr > line) {
        if (*--ptr == '\n') {
            return line + count - ptr - 1;
        }
    }
    return start + count;
}

__attribute__((section(".text.cur_ptr__7filebuf")))
char *cur_ptr__7filebuf(int *p) {
    int base;
    int end;
    if ((p[0] & 0x100) != 0) {
        base = p[9];
    } else {
        base = p[3];
    }
    if ((p[0] & 0x100) != 0) {
        end = p[11];
    } else {
        end = p[2];
    }
    if (base != end) {
        if ((p[0] & 0x100) != 0) {
            return (char *)p[9];
        }
        return (char *)p[1];
    }
    return (char *)p[5];
}

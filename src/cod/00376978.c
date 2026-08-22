/* ee-2.9-991111 matched TU. */

extern char D_0076F050[];
extern char D_0076E590[];
extern char D_0076B9C0[];
extern char D_0076CF20[];

__attribute__((section(".text.func_00376978")))
char *func_00376978(void) {
    char *p = D_0076F050;
    int i = 0;

    do {
        if (*(unsigned short *)p == 0) {
            return p;
        }
        i++;
        p += 0x40;
    } while (i < 0x60);
    return 0;
}

__attribute__((section(".text.func_00377998")))
char *func_00377998(void) {
    char *p = D_0076E590;
    char *end = D_0076E590 + 0x380;

    for (;;) {
        if (*(unsigned short *)p == 0) {
            return p;
        }
        p += 0x70;
        if (!((int)p < (int)end)) {
            return 0;
        }
    }
}

__attribute__((section(".text.func_0037D170")))
char *func_0037D170(void) {
    char *p = D_0076B9C0;
    char *end = D_0076B9C0 + 0xF00;

    for (;;) {
        if (*(unsigned short *)p == 0) {
            return p;
        }
        p += 0x50;
        if (!((int)p < (int)end)) {
            return 0;
        }
    }
}

__attribute__((section(".text.func_0037D2D8")))
char *func_0037D2D8(void) {
    char *p = D_0076CF20;
    char *end = D_0076CF20 + 0xFF0;

    for (;;) {
        if (*(unsigned short *)p == 0) {
            return p;
        }
        p += 0x50;
        if (!((int)p < (int)end)) {
            return 0;
        }
    }
}

__attribute__((section(".text.func_003970C8")))
void func_003970C8(char *p, int n) {
    int i;

    for (i = n - 1; i != -1; i--) {
        *p = 0;
        p++;
    }
}

struct _IO_marker;

struct _IO_FILE {
    int _flags;
    char *p04;
    char *p08;
    char *p0c;
    char *p10;
    char *p14;
    char *p18;
    char *p1c;
    char *p20;
    char *p24;
    char *p28;
    char *p2c;
    struct _IO_marker *_markers;
};

struct _IO_marker {
    struct _IO_marker *_next;
    struct _IO_FILE *_sbuf;
    int _pos;
};

__attribute__((section(".text._IO_remove_marker")))
void _IO_remove_marker(struct _IO_marker *marker) {
    struct _IO_marker **ptr = &marker->_sbuf->_markers;

    for (; ; ptr = &(*ptr)->_next) {
        if (*ptr == 0) {
            break;
        } else if (*ptr == marker) {
            *ptr = marker->_next;
            return;
        }
    }
}

/* ee-2.9-991111 */
__attribute__((section(".text.is_reading__7filebuf")))
int is_reading__7filebuf(char *p)
{
    int a = (*(int *)p & 0x100) ? *(int *)(p + 0x24) : *(int *)(p + 0xC);
    int b = (*(int *)p & 0x100) ? *(int *)(p + 0x2C) : *(int *)(p + 0x8);

    return (a ^ b) != 0;
}

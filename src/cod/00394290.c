/* sn-2.95.3-136 matched TU. */

extern int patch(int, int, int);
extern int strlen(const char *);
extern int __svfscanf(void *, const char *, void *);
extern int func_003A6CD8();
extern void *PTR_DAT_003fa62c;
extern void *PTR_DAT_003f852c;

struct E { int f0; unsigned int f4; int f8; };
__attribute__((section(".text.func_00394290")))
int func_00394290(struct E *e, int count, int key, int base) {
    unsigned int i; unsigned int f4;
    i = count - 1;
    if (count != 0) {
        do {
            f4 = e->f4;
            if ((f4 >> 8) == (unsigned)key) {
                if (patch(e->f0, f4 & 0xFF, base + e->f8) == 0) return 0;
            }
            e++; i--;
        } while (i != 0xFFFFFFFFu);
    }
    return 1;
}

typedef void *va_list;
#define va_start(ap, last) (ap = (void *)((char *)__builtin_next_arg(last) - 0x30))
#define va_end(ap)

struct __sFILE {
    unsigned char *_p;
    int _r;
    int _w;
    short _flags;
    short _file;
    struct { unsigned char *_base; int _size; } _bf;
    int _lbfsize;
    void *_cookie;
    void *_read;
    void *_write;
    void *_seek;
    void *_close;
    struct { unsigned char *_base; int _size; } _ub;
    unsigned char *_up;
    int _ur;
    unsigned char _ubuf[3];
    unsigned char _nbuf[1];
    struct { unsigned char *_base; int _size; } _lb;
    int _blksize;
    int _offset;
    void *_data;
};






__attribute__((section(".text.func_003A6CE0")))
int func_003A6CE0(const char *str, const char *fmt, ...) {
    int ret;
    va_list ap;
    struct __sFILE f;
    f._flags = 4;
    f._bf._base = f._p = (unsigned char *)str;
    f._bf._size = f._r = strlen(str);
    f._read = (void *)func_003A6CD8;
    f._ub._base = 0;
    f._lb._base = 0;
    f._data = PTR_DAT_003fa62c;
    va_start(ap, fmt);
    ret = __svfscanf(&f, fmt, ap);
    va_end(ap);
    return ret;
}

struct Elem {
    int field_0;
    int field_4;
    unsigned short field_8;
    unsigned char field_A;
    unsigned char field_B;
};

struct Node {
    char pad[0xC];
    struct Elem *field_C;
    int field_10;
    char pad2[0x30 - 0x14];
    struct Node *field_30;
};





__attribute__((section(".text.func_003945C0")))
int func_003945C0(struct Elem *a0) {
    struct Node *node;
    struct Elem *elem;
    int cnt;
    node = (struct Node *)PTR_DAT_003f852c;
    if (node != 0) {
        do {
            cnt = node->field_10;
            elem = node->field_C;
            if (cnt != 0) {
                do {
                    if (elem->field_B != 0 && elem->field_8 == a0->field_8 &&
                        func_003A5678(elem->field_0, a0->field_0) == 0) {
                        return 1;
                    }
                    elem++;
                } while (--cnt != 0);
            }
            node = node->field_30;
        } while (node != 0);
    }
    return func_003943D0(a0);
}

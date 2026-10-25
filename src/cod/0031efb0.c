/* ee-2.9-991111 matched TU. */

/* ee-gcc 2.9-991111: __class_type_info_dcast, general dynamic_cast step (gcc 2.95.2 tinfo.cc
 * __class_type_info::dcast). Matches this type, else walks the base list, forwarding to each
 * base's virtual dcast through its g++ 2.x vtable entry, and rejects a target reached at two
 * different addresses unless the sub-object test picks one. */
typedef unsigned int USItype;

typedef struct {
    short delta;
    short index;
    void *(*fn)(char *self, void *desired, int is_public, void *objptr, void *sub, void *subptr);
} VtEntry;

typedef struct {
    char *base;                         /* 0x00 base type_info */
    USItype offset : 29;                /* 0x04 */
    USItype is_virtual : 1;
    USItype access : 2;                 /* 1 public, 2 protected, 3 private */
} BaseInfo;

typedef struct {
    int unk00;
    char *vtbl;                         /* 0x04 */
    BaseInfo *base_list;                /* 0x08 */
    unsigned int n_bases;               /* 0x0C */
} ClassTypeInfo;

#define BASE_PUBLIC 1

extern int type_info___eq(void *a, void *b);

#define DCAST(obj, desired, pub, ptr, sub, subptr) \
    ((VtEntry *)((obj)->vtbl + 0x10))->fn((char *)(obj) + ((VtEntry *)((obj)->vtbl + 0x10))->delta, \
                                          desired, pub, ptr, sub, subptr)

__attribute__((section(".text.__class_type_info_dcast")))
void *__class_type_info_dcast(ClassTypeInfo *self, void *desired, int is_public, void *objptr,
                              void *sub, void *subptr)
{
    void *match_found;
    void *p;
    void *os;
    void *ns;
    unsigned int i;
    ClassTypeInfo *b;
    ClassTypeInfo *d;

    if (type_info___eq(self, desired))
        return objptr;
    match_found = 0;
    for (i = 0; i < self->n_bases; i++) {
        BaseInfo *bi;

        if (is_public && self->base_list[i].access != BASE_PUBLIC)
            continue;
        /* offset first: integer arithmetic keeps retail's addu operand order (pointer arithmetic swaps it) */
        bi = (BaseInfo *)(i * 8 + (unsigned int)self->base_list);
        p = (char *)objptr + bi->offset;
        if (bi->is_virtual)
            p = *(void **)p;
        b = (ClassTypeInfo *)bi->base;
        p = DCAST(b, desired, is_public, p, sub, subptr);
        if (p) {
            if (match_found == 0) {
                match_found = p;
            } else if (match_found != p) {
                if (sub) {
                    d = (ClassTypeInfo *)desired;
                    os = DCAST(d, sub, 1, match_found, 0, 0);
                    ns = DCAST(d, sub, 1, p, 0, 0);
                    if (os == ns) {
                    } else if (os == subptr) {
                        continue;
                    } else if (ns == subptr) {
                        match_found = p;
                        continue;
                    }
                }
                return 0;
            }
        }
    }
    return match_found;
}

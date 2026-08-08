/* sn-2.95.3-136 matched TU. */

typedef unsigned int size_t;

typedef struct Obj {
    struct Obj *free_list_link;
} Obj;

extern void *func_003A7C70(size_t);   /* malloc */
extern void *func_0031D6E8(size_t);   /* _S_oom_malloc */
extern void *D_003C4030[16];          /* _S_free_list */
extern char *D_003C4074;              /* _S_start_free */
extern char *D_003C4078;              /* _S_end_free */
extern size_t D_003C407C;             /* _S_heap_size */

__attribute__((section(".text.func_0031D778")))
char *func_0031D778(size_t size, int *nobjs)
{
    char *result;
    size_t total_bytes;
    size_t bytes_left;

    total_bytes = size * *nobjs;
    bytes_left = D_003C4078 - D_003C4074;

    if (bytes_left >= total_bytes) {
        result = D_003C4074;
        D_003C4074 += total_bytes;
        return result;
    } else if (bytes_left >= size) {
        *nobjs = (int)(bytes_left / size);
        total_bytes = size * *nobjs;
        result = D_003C4074;
        D_003C4074 += total_bytes;
        return result;
    } else {
        size_t bytes_to_get = 2 * total_bytes + (((D_003C407C >> 4) + 7) & ~7);
        if (bytes_left > 0) {
            void **my_free_list;
            size_t idx;
            idx = (bytes_left + 7) / 8;
            idx = idx - 1;
            my_free_list = D_003C4030 + idx;
            *(char **)D_003C4074 = (char *)*my_free_list;
            *my_free_list = D_003C4074;
        }
        D_003C4074 = (char *)func_003A7C70(bytes_to_get);
        if (0 == D_003C4074) {
            size_t i;
            void **my_free_list;
            Obj *p;
            size_t idx;
            void *r;
            for (i = size; i <= 128; i += 8) {
                idx = (i + 7) / 8;
                idx = idx - 1;
                my_free_list = D_003C4030 + idx;
                p = (Obj *)*my_free_list;
                if (0 != p) {
                    *my_free_list = p->free_list_link;
                    D_003C4074 = (char *)p;
                    D_003C4078 = D_003C4074 + i;
                    return func_0031D778(size, nobjs);
                }
            }
            D_003C4078 = 0;
            r = func_003A7C70(bytes_to_get);
            if (0 == r)
                r = func_0031D6E8(bytes_to_get);
            D_003C4074 = (char *)r;
        }
        D_003C407C += bytes_to_get;
        D_003C4078 = D_003C4074 + bytes_to_get;
        return func_0031D778(size, nobjs);
    }
}

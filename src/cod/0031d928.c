/* sn-2.95.3-136 matched TU. */

typedef unsigned int size_t;

typedef struct Obj {
    struct Obj *free_list_link;
} Obj;

extern char *func_0031D778(size_t n, int *nobjs);   /* _S_chunk_alloc */
extern void *D_003C4030[16];                        /* _S_free_list */

__attribute__((section(".text.func_0031D928")))
void *func_0031D928(size_t n)
{
    int nobjs = 20;
    char *chunk = func_0031D778(n, &nobjs);
    void **my_free_list;
    Obj *result;
    Obj *current_obj;
    Obj *next_obj;
    size_t idx;
    int i;

    if (1 == nobjs)
        return chunk;
    idx = (n + 7) / 8;
    idx = idx - 1;
    my_free_list = D_003C4030 + idx;

    result = (Obj *)chunk;
    *my_free_list = next_obj = (Obj *)(chunk + n);
    for (i = 1; ; i++) {
        current_obj = next_obj;
        next_obj = (Obj *)((char *)next_obj + n);
        if (nobjs - 1 == i) {
            current_obj->free_list_link = 0;
            break;
        } else {
            current_obj->free_list_link = next_obj;
        }
    }
    return result;
}

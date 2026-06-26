/* sn-2.95.3-136 matched TU. */

extern int D_0077DB88;

typedef struct {
    void *items;
    int f04;
    int f08;
    int f0C;
    int f10;
    int f14;
    void *type;
} ArrayObj;

typedef struct {
    int f00;
    int f04;
    int f08;
    int f0C;
    int f10;
    int f14;
    short offset;
    short f1A;
    void (*free_fn)(void *, void *);
} ArrayType;

__attribute__((section(".text.arrayFree")))
int arrayFree(ArrayObj *a0) {
    ArrayObj *s0;
    void *items;
    ArrayType *t;
    short off;
    void (*fn)(void *, void *);

    s0 = a0;
    items = s0->items;
    if (items == 0) return 0;
    t = (ArrayType *)s0->type;
    off = t->offset;
    fn = t->free_fn;
    fn((char *)s0 + off, items);
    s0->items = 0;
    return 1;
}

int func_003B0450(int, int);

__attribute__((section(".text.func_003ADFA8")))
int func_003ADFA8(int *out, int a1, int a2) {
    int result;
    D_0077DB88 = 0;
    result = func_003B0450(a1, a2);
    if (result == -1) {
        if (D_0077DB88 != 0) {
            *out = D_0077DB88;
        }
    }
    return result;
}

void *sbrk(int);

__attribute__((section(".text.func_003AE0C8")))
void *func_003AE0C8(void **out, int size) {
    void *result;
    D_0077DB88 = 0;
    result = sbrk(size);
    if (result == (void *)-1) {
        if (D_0077DB88 != 0) {
            *out = (void *)D_0077DB88;
        }
    }
    return result;
}

/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_00155D60")))
unsigned char *func_00155D60(unsigned char *base, long val, int idx) {
    unsigned char *p;
    int i;

    for (i = base[0x385] - 1; i != 0; i--) {
        ;
    }
    p = base + idx * 0xB0;
    *(long *)(p + 0x30) = val;
    return p;
}

__attribute__((section(".text.func_002C3000")))
void func_002C3000(void *unused, unsigned int *arr, int count) {
    int i;

    arr[0] = 0xFFFFFFFF;
    for (i = 0; i < count - 1; i++) {
        arr[i + 1] = ((unsigned int)&arr[i]) & 0x7FFFFFFF;
    }
}

typedef struct Sub {
    unsigned char pad0[0x10];
    int f10;
} Sub;

typedef struct Node {
    unsigned char pad0[0x24];
    struct Node *next;
    Sub *sub;
} Node;

typedef struct Owner {
    unsigned char pad0[0x3C];
    Node *head;
    unsigned char pad1[0x8];
    unsigned char flag;
} Owner;



__attribute__((section(".text.func_001FD988")))
void func_001FD988(Owner *o, unsigned char f) {
    Node *p;
    int r;

    o->flag = f;
    r = func_001FD908(o);
    for (p = o->head; p != 0; p = p->next) {
        p->sub->f10 = r;
    }
}

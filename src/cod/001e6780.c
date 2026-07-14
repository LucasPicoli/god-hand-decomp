/* sn-2.95.3-136 matched TU. */

extern char D_005686D0[];
extern char D_00580D20[];
extern char D_0057F060[];
extern void SetFields_4_And_8_1FE6B8(void *dst, void *src, int count);

__attribute__((section(".text.Slot2_SetSlotLayer")))
void Slot2_SetSlotLayer(void *self, int *src) {
    int *dst;
    int i;

    dst = (int *)((char *)self + 0x3A0);
    for (i = 11; i >= 0; i--) {
        *dst++ = *src++;
    }
}

typedef struct Link {
    int unk0;
    struct Link *prev;
    int unk8;
    int flags;
} Link;

typedef struct Pool {
    int unk0;
    Link list[16];
} Pool;

__attribute__((section(".text.func_001F77D0")))
void func_001F77D0(Pool *pool) {
    Link *p;
    Link *q;
    int i;

    p = &pool->list[14];
    for (i = 15; i > 0; i--) {
        p[1].prev = p;
        p[1].flags = 0;
        p--;
    }
    q = pool->list;
    q->prev = 0;
    q->flags = 0;
}

typedef struct Node {
    char pad0[0x88];
    struct Node *next;
    char pad8C[0xC];
    int flags;
    char pad9C[0x28];
    float value;
} Node;

typedef struct Owner {
    char pad0[0x18];
    Node *head;
} Owner;

__attribute__((section(".text.func_002D0820")))
void func_002D0820(Owner *owner, float value) {
    Node *n;

    for (n = owner->head; n != 0; n = n->next) {
        n->value = value;
        n->flags |= 4;
    }
}

__attribute__((section(".text.func_002AF348")))
int func_002AF348(int value) {
    int digits;
    int limit;

    digits = 1;
    limit = 10;
    while (value >= limit) {
        limit = limit * 10;
        digits++;
    }
    return digits;
}

#include "godhand/vu0.h"



__attribute__((section(".text.func_001FC758")))
void func_001FC758(int enable, int id) {
    char *base;
    char *p;
    int i;

    if (id != 0xFFFF) {
        return;
    }
    if (enable == 0) {
        return;
    }

    base = D_005686D0;
    VU0_SQC2_VF0(base, 0x190);

    p = base + 0x28A;
    i = 128;
    while (i--) {
        p[4] = 0;
        p += 0x10;
    }

    *(int *)(base + 0xB8C) = 0;
}

__attribute__((section(".text.func_001FF780")))
void func_001FF780(int enable, int id) {
    int i;

    if (id != 0xFFFF) {
        return;
    }
    if (enable == 0) {
        return;
    }

    i = 80;
    while (i--) {
        ;
    }

    SetFields_4_And_8_1FE6B8(D_00580D20, D_0057F060, 0x50);
}

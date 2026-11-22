/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEmManage.h"

extern char D_0076A880[];

__attribute__((section(".text.strrev")))
char *strrev(char *s) {
    int i;
    int j;
    char c;

    for (j = 0; s[j] != '\0'; j++) {
        ;
    }
    j--;
    i = 0;
    while (i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        i++;
        j--;
    }
    return s;
}

__attribute__((section(".text.SdeRpcClientInit")))
void SdeRpcClientInit(void) {
    char *base;
    int status;
    int done;
    int i;

    base = D_0076A880;
    do {
        status = sceSifBindRpc(base + 0xDC, 0x19720317, 0);
        if (status < 0) {
            for (;;) {
                ;
            }
        }
        done = *(int *)(base + 0x100);

        i = 10000;
        while (i--) {
            ;
        }
    } while (done == 0);
}

__attribute__((section(".text.cCoreSave_clearGodItem")))
void cCoreSave_clearGodItem(cCoreSave *self) {
    int i;

    for (i = 0; i < CORESAVE_GOD_ITEM_NUM; i++) {
        self->data->godItem[i] = 0;
    }
}

/* Counts the listed slots of one kind. */
__attribute__((section(".text.cEmManage_countKind")))
int cEmManage_countKind(cEmManage *self, int kind) {
    cEmSlot *slot;
    int n = 0;

    for (slot = self->list.top; slot != 0; slot = slot->next) {
        if (slot->kind == kind) {
            n++;
        }
    }
    return n;
}

__attribute__((section(".text.memcpyalpha")))
void memcpyalpha(unsigned char *dst, unsigned char *src, unsigned int n) {
    while (n--) {
        *dst++ = *src++;
    }
}

typedef struct Node {
    char pad0[0x10];
    struct Node *next;
} Node;

typedef struct Owner {
    char pad0[0x8];
    Node *head;
} Owner;

__attribute__((section(".text.func_002B5E58")))
int func_002B5E58(Owner *this) {
    Node *p;
    int n;

    n = 0;
    p = this->head;
    if (p != 0) {
        n = 1;
        for (p = p->next; p != 0; p = p->next) {
            n++;
        }
    }
    return n;
}

/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.HideModelMgr_ClearHiddenModelList")))
void HideModelMgr_ClearHiddenModelList(int *list) {
    int i;

    for (i = 31; i >= 0; i--) {
        list[i] = 0;
    }
}

typedef struct Thing {
    unsigned char pad0[0xEE8];
    int arr[9];
    unsigned char pad1[0x9];
    unsigned char flag;
} Thing;

__attribute__((section(".text.func_0015FEE0")))
void func_0015FEE0(Thing *t) {
    int v = -1;
    int i;

    for (i = 8; i >= 0; i--) {
        t->arr[i] = v;
    }
    t->flag = 0;
}

typedef struct Node {
    unsigned char pad0[0x8];
    struct Node *next;
    unsigned char pad1[0x20];
    unsigned char key;
} Node;

typedef struct Obj {
    unsigned char pad0[0x10];
    Node *head;
} Obj;

__attribute__((section(".text.func_002AEDC0")))
int func_002AEDC0(Obj *o, unsigned char key) {
    Node *n;
    int count;

    count = 0;
    for (n = o->head; n != 0; n = n->next) {
        if (n->key == key) {
            count++;
        }
    }
    return count;
}

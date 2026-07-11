/* cygnus-2.96 matched TU. */

typedef struct Node_002b22e8 {
    unsigned short id;
    short val;
    void *prev;
    void *next;
} Node_002b22e8;

__attribute__((section(".text.func_002B22E8")))
void func_002B22E8(Node_002b22e8 *a0, Node_002b22e8 *a1, Node_002b22e8 *a2, short a3, unsigned short a4) {
    if (a1 != 0) a1->next = a0;
    if (a2 != 0) a2->prev = a0;
    a0->prev = a1;
    a0->next = a2;
    a0->val = a3;
    a0->id = a4;
}

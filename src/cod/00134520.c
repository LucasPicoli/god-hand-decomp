/* sn-2.95.3-136 matched TU. */

extern void *func_001339F0(void *mem, int a, int b, float f);
extern int D_00460D18;

typedef struct Node {
    struct Node *next;
    struct Node *child;
} Node;

__attribute__((section(".text.func_00134520")))
void func_00134520(Node *n, int a, int b, float f) {
    Node *p;
    Node *q;

    if (n->next != 0) {
        if (n->child != 0) {
            q = n->child;
            while (q->next != 0) {
                q = q->next;
            }
            p = (Node *)func_001339F0(func_0030F550(0x80), a, b, f);
            q->next = p;
        } else {
            p = (Node *)func_001339F0(func_0030F550(0x80), a, b, f);
            n->child = p;
        }
        if (p != 0) {
            D_00460D18 = D_00460D18 + 1;
        }
    }
}

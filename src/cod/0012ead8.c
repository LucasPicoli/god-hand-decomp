/* sn-2.95.3-136 matched TU. */

extern char D_005686D0[];
extern char *D_00569B70;
extern void InitSlotTable_1FAFA8(void *self);
extern void func_001FC138(void *self);
extern void cCoreSave_setGameDifficulty(void *self, int level);

/* sn-2.95.3-136 candidate. */

typedef struct Node {
    struct Node *next;
} Node;




__attribute__((section(".text.func_0012EAD8")))
Node *func_0012EAD8(char *self, void *obj, int a2, int a3, int a4, int a5,
                    int a6, int a7, int a8, int a9, int a10, int a11)
{
    Node *q;
    Node *p;

    if (obj != 0) {
        if (*(Node **)(self + 0x190) != 0) {
            q = *(Node **)(self + 0x190);
            while (q->next != 0) {
                q = q->next;
            }
            p = func_0012D970(func_0030F550(0x190), obj, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
            q->next = p;
            if (p != 0) {
                *(int *)(self + 0x194) = *(int *)(self + 0x194) + 1;
                return q->next;
            }
        } else {
            p = func_0012D970(func_0030F550(0x190), obj, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
            *(Node **)(self + 0x190) = p;
            if (p != 0) {
                *(int *)(self + 0x194) = *(int *)(self + 0x194) + 1;
                return p;
            }
        }
    }
    return 0;
}

/* sn-2.95.3-136 candidate. */








__attribute__((section(".text.cCoreSave_systemInit")))
void cCoreSave_systemInit(char **self)
{
    unsigned int i;

    func_003A52F0(D_005686D0, 0, 0x14A0);
    D_00569B70 = D_005686D0;
    InitSlotTable_1FAFA8(self);
    for (i = 0; i < 0x80; i++) {
        (*self + i)[0xB0] = -1;
    }
    func_001FC138(self);
    cCoreSave_setGameDifficulty(self, 1);
}

/* TU: cEmManage [enemy] - recovered C++ class. */
extern float D_00747A14;

__attribute__((section(".text.cEmManage_GetSpeedRate")))
float cEmManage_GetSpeedRate(void *a0) {
    return *(float*)((char*)a0 + 0x548) * D_00747A14;
}
extern int func_00290958(void *a0);
extern int GetActiveEntry_1FE9B8(void *a0, int a1);
extern void cDataManager_loadWait(void *a0, int a1, void *a2, int a3);
extern void func_001FEAA0(void *a0, int a1, int a2, int a3);
extern char *CreateObj(int a0, int a1);
extern void func_00290048(void *node, void *obj, int kind);
extern int func_00290988(void *a0, int a1);
extern void cEmManage_ReleaseEm(void *a0, void *a1);
extern char D_005864E0[];
extern char D_00754220[];

typedef struct Node { struct Node *prev; struct Node *next; } Node;
typedef struct List { Node *head; Node *tail; } List;

__attribute__((section(".text.cEmManage_EntryEm")))
char *cEmManage_EntryEm(char *this, int *ep, int kind, void *a3)
{
    int slot;
    char *obj;
    Node *node;
    List *list;
    char *vt;

    if (ep == 0)
        goto ng;
    if (kind < -1)
        return 0;
    slot = func_00290958(this);
    if (slot == -1)
        goto ng;
    if (GetActiveEntry_1FE9B8(D_005864E0, ep[0]) == 0)
        cDataManager_loadWait(D_005864E0, ep[0], D_00754220, 1);
    func_001FEAA0(D_005864E0, ep[0], ep[10], ep[11]);
    obj = CreateObj(ep[0], 0xFFFF);
    if (obj == 0)
        return 0;
    node = (Node *)(this + slot * 0x14);
    func_00290048(node, obj, kind);
    if (node != 0) {
        list = (List *)(this + 0x500);
        if (list->tail == 0) {
            list->head = node;
            node->prev = 0;
            list->head->next = 0;
            list->tail = node;
        } else {
            list->tail->next = node;
            node->prev = list->tail;
            list->tail = node;
            node->next = 0;
        }
    }
    *(int *)(this + 0x508) += 1;
    if (func_00290988(this, kind) == 1)
        *(int *)(this + 0x50C) += 1;
    *(short *)(obj + 0x640) = *((unsigned char *)ep + 0x31);
    vt = *(char **)(obj + 0x214);
    if ((*(int (**)(char *, int *, void *))(vt + 0x9C))(obj + *(short *)(vt + 0x98), ep, a3) != 0)
        return obj;
    cEmManage_ReleaseEm(this, obj);
ng:
    return 0;
}

/* sn-2.95.3-136 matched TU. */

extern void cEmManage_ReleaseEm(void *a0, int a1);
extern void ReleaseObj(void *a0);
extern void *D_00754C58;

__attribute__((section(".text.cEmManage_ReleaseEmAll")))
void cEmManage_ReleaseEmAll(void *a0) {
    char *this = (char *)a0;
    char *node;
    char *p;
    char *obj;
    node = *(char **)(this + 0x500);
    while (node != 0) {
        char *next = *(char **)(node + 0x4);
        cEmManage_ReleaseEm(this, *(int *)(node + 0x8));
        node = next;
    }
    p = *(char **)((char *)D_00754C58 + 0x4);
    while (p != *(char **)((char *)D_00754C58 + 0x8)) {
        obj = *(char **)p;
        if (*(unsigned short *)(obj + 0x2FE) == 0x364) ReleaseObj(obj);
        p += 4;
    }
}

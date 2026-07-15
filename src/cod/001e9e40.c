/* sn-2.95.3-136 matched TU. */

extern void ClearObjRef_1EE9A0(void *a0);
extern void func_001EDF60(void *a0);
extern void func_001ED660(void *a0);
extern void func_001ECBD0(void *a0);
extern void UnlinkAndCoalesceNode_2A9680(void *a0, void *a1);
extern void func_001EB9F8(void *a0);
extern void **D_003C2384;

__attribute__((section(".text.func_001E9E40")))
void func_001E9E40(void *a0) {
    char *p = (char *)a0;
    char *q;
    int i;
    void *base;
    void *node;

    q = p + 0x5C;
    /* closes with bgez -> i >= 0 */
    for (i = 4; i >= 0; i--) {
        ClearObjRef_1EE9A0(q);
        q += 0x40;
    }

    func_001EDF60(p + 0x1B90);
    func_001ED660(p + 0x1840);
    func_001ECBD0(p + 0x210);

    base = *D_003C2384;
    ((int *)base)[0x29] = 0;
    ((int *)base)[0x28] = 0;

    node = *(void **)(p + 0x2A0C);
    if (node != 0) {
        UnlinkAndCoalesceNode_2A9680(*(void **)((char *)node - 0x20), node);
    }
    func_001EB9F8(p);
}

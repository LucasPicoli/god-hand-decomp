/* sn-2.95.3-136 matched TU. */

extern int D_007476B0;
extern void func_0014D0E8(void *this);
extern void *cModel_getMeshPtr(void *this, int idx);
extern void func_00153B00(void *this, void *mesh);
extern void func_00155BE8(void *this, unsigned int flag, int bit);
extern void func_0014B4D0(void *this, void *node);
extern void ForwardAttackByMode_14B5D8(void *this, void *node);
extern void func_00155AE8(void *a, int b, int c);
extern void func_0014B810(void *this, void *node, int a2);
extern void func_0014C6B8(void *this, int a1);

/* cModel_Tag_set_scr — sn-2.95.3-136, --call-loop-pad.
   The first mesh walk `do { func_00153B00(this, mesh); mesh = mesh->0x404; }
   while (mesh)` is a TWO-arg call-loop: the closing bnel carries `a1 = mesh`
   in its delay slot, so the injected pad is not absorbed. That loop is the
   padded one (delta 4). The big node loop below is long -> not padded. */













__attribute__((section(".text.cModel_Tag_set_scr")))
void cModel_Tag_set_scr(void *this, int arg1, int arg2) {
    char *base = (char *)this;
    int bit = D_007476B0 & 1;
    char *mesh;
    char *node;
    char *prev;
    int last;
    int r;

    func_0014D0E8(this);

    mesh = (char *)cModel_getMeshPtr(this, 0);
    if (mesh != 0) {
        do {
            func_00153B00(this, mesh);
            mesh = *(char **)(mesh + 0x404);
        } while (mesh != 0);
    }

    func_00155BE8(this, 0x80000000, bit);

    prev = 0;
    last = 0;
    node = (char *)cModel_getMeshPtr(this, 0);
    if (node != 0) {
        do {
            if ((*(int *)(node + 0x380) & 1) == 0) {
                int flags = *(int *)(base + 0x250);
                if ((flags & 0x400) != 0 ||
                    arg2 == ((*(volatile int *)(*(char **)(node + 0x414) + 0x34) & 0x01000000) > 0)) {
                    int flags2;
                    if ((flags & 0x80) == 0) {
                        func_0014B4D0(this, node);
                    }
                    flags2 = *(int *)(base + 0x250);
                    if ((flags2 & 0x00400000) != 0) {
                        ForwardAttackByMode_14B5D8(this, node);
                    }
                    r = func_0014BEF8(this, node);
                    func_00155AE8(node, r | 0x80000000, bit);
                    if (last != r && prev != 0) {
                        func_00155AE8(prev, last, bit);
                    }
                    prev = node;
                    last = r;
                    func_0014B810(this, node, (short)arg1);
                }
            }
            node = *(char **)(node + 0x404);
        } while (node != 0);
    }

    if (prev != 0) {
        func_00155AE8(prev, last, bit);
    }
    func_0014C6B8(this, (short)arg1);
}

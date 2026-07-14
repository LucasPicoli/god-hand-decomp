/* sn-2.95.3-136 matched TU. */

extern void func_003A52F0(void *dst, int val, int len);
extern void UnlinkAndCoalesceNode_2A9680(void *list, int node);
extern char D_00754220[];

__attribute__((section(".text.func_002D73E0")))
void func_002D73E0(void *obj) {
    char *base = (char *)obj;
    char *q;
    int *r;
    int i;
    int node;

    func_003A52F0(base + 0x80, 0, 0x7000);

    for (i = 255; i >= 0; i--) {
        *(short *)(base + 0x80 + i * 0x70) = 0xFF;
    }

    *(int *)(base + 0x78) = 0;

    r = (int *)(base + 0x16100);
    q = base + 0x10000;
    for (i = 0; i < 8; i++) {
        node = *(int *)(q + 0x5D74);
        if (node != 0) {
            UnlinkAndCoalesceNode_2A9680(D_00754220, node);
            *(int *)(q + 0x5D74) = 0;
        }
        *r = 0;
        q += 0x80;
        r++;
    }

    *(int *)(base + 0x16130) = 0;
    *(int *)(base + 0x16120) = 0;
}

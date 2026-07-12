/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_001FD9D8")))
int func_001FD9D8(int a0, int a1, int a2, int a3, int a4) {
    int desc;
    int node;
    int *head;
    int *last;
    int result;
    int (*fn)(int);

    if (*(char *)(a0 + 0x49) == 0) {
        return -1;
    }
    desc = *(int *)(a0 + 0x50);
    fn = *(int (**)(int))(desc + 0x14);
    node = fn(a0 + *(short *)(desc + 0x10));
    if (node == 0) {
        return -1;
    }
    if (func_001FD908(a0) == 0) {
        return -1;
    }
    result = func_001FC988(node, func_001FD908(a0), a1, a2, a3, a4, a0);
    if (result == -1) {
        return -1;
    }
    head = *(int **)(a0 + 0x3C);
    if (head != 0) {
        last = head;
        if (*(int **)((char *)last + 0x24) != 0) {
            do {
                last = *(int **)((char *)last + 0x24);
            } while (*(int **)((char *)last + 0x24) != 0);
        }
        *(int **)((char *)last + 0x24) = (int *)node;
        *(int *)(node + 0x20) = (int)last;
    } else {
        *(int **)(a0 + 0x3C) = (int *)node;
    }
    return result;
}
